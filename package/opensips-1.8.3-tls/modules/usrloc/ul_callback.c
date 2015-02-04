/*
 * $Id: ul_callback.c 5901 2009-07-21 07:45:05Z bogdan_iancu $
 *
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 * --------
 *  2004-03-16  created (bogdan)
 */

/*! \file
 *  \brief USRLOC - Callback functions
 *  \ingroup usrloc
 */


#include <stdlib.h>

#include "../../dprint.h"
#include "../../error.h"
#include "../../mem/shm_mem.h"
#include "ul_callback.h"


struct ulcb_head_list* ulcb_list = 0;



int init_ulcb_list(void)
{
	ulcb_list = (struct ulcb_head_list*)shm_malloc
		( sizeof(struct ulcb_head_list) );
	if (ulcb_list==0) {
		LM_CRIT("no more shared mem\n");
		return -1;
	}
	ulcb_list->first = 0;
	ulcb_list->reg_types = 0;
	return 1;
}


void destroy_ulcb_list(void)
{
	struct ul_callback *cbp, *cbp_tmp;

	if (!ulcb_list)
		return;

	for( cbp=ulcb_list->first; cbp ; ) {
		cbp_tmp = cbp;
		cbp = cbp->next;
		if (cbp_tmp->param) shm_free( cbp_tmp->param );
		shm_free( cbp_tmp );
	}

	shm_free(ulcb_list);
}



/*! \brief 
	register a callback function 'f' for 'types' mask of events;
*/
int register_ulcb( int types, ul_cb f, void *param )
{
	struct ul_callback *cbp;

	/* are the callback types valid?... */
	if ( types<0 || types>ULCB_MAX ) {
		LM_CRIT("invalid callback types: mask=%d\n",types);
		return E_BUG;
	}
	/* we don't register null functions */
	if (f==0) {
		LM_CRIT("null callback function\n");
		return E_BUG;
	}

	/* build a new callback structure */
	if (!(cbp=(struct ul_callback*)shm_malloc(sizeof( struct ul_callback)))) {
		LM_ERR("no more share mem\n");
		return E_OUT_OF_MEM;
	}

	/* link it into the proper place... */
	cbp->next = ulcb_list->first;
	ulcb_list->first = cbp;
	ulcb_list->reg_types |= types;
	/* ... and fill it up */
	cbp->callback = f;
	cbp->param = param;
	cbp->types = types;
	if (cbp->next)
		cbp->id = cbp->next->id+1;
	else
		cbp->id = 0;

	return 1;
}


