/*
 * $Id: openserSIPServerObjects.c 5901 2009-07-21 07:45:05Z bogdan_iancu $
 *
 * SNMPStats Module 
 * Copyright (C) 2006 SOMA Networks, INC.
 * Written by: Jeffrey Magder (jmagder@somanetworks.com)
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 *
 * History:
 * --------
 * 2006-11-23 initial version (jmagder)
 * 2007-02-16 Moved all OID registrations from the experimental branch to 
 *            OpenSER's IANA assigned enterprise branch. (jmagder)
 * 
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf,v 1.9 2005/01/07 09:37:18 dts12 Exp $
 *
 * This file implements all scalares defines in the OPENSER-SIP-SERVER-MIB.  For
 * a full description of the scalars, please see OPENSER-SIP-SERVER-MIB.
 *
 */

#include <string.h>

#include "../../statistics.h"
#include "../../sr_module.h"
#include "../../config.h"
#include "../usrloc/usrloc.h"

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "openserSIPServerObjects.h"

#include "snmpstats_globals.h"
#include "utilities.h"

/* Used for openserSIPRegUserLookupCounter.  (See the MIB file for details) */
unsigned int global_UserLookupCounter;


/* Initializes the openserSIPServerObjects module.  This involves: 
 *
 *  - Registering all OID's
 *  - Setting up handlers for all OID's
 *
 * This function is mostly auto-generated. */
void init_openserSIPServerObjects(void)
{
	static oid openserSIPProxyStatefulness_oid[]  =
		{ OPENSER_OID,3,1,2,1,3,1 };

	static oid openserSIPProxyRecordRoute_oid[]   =
		{ OPENSER_OID,3,1,2,1,3,3 };

	static oid openserSIPProxyAuthMethod_oid[]    =
		{ OPENSER_OID,3,1,2,1,3,4 };

	static oid openserSIPNumProxyRequireFailures_oid[]     =
		{ OPENSER_OID,3,1,2,1,4,1 };

	static oid openserSIPRegMaxContactExpiryDuration_oid[] =
		{ OPENSER_OID,3,1,2,1,5,2 };

	static oid openserSIPRegMaxUsers_oid[]              =
		{ OPENSER_OID,3,1,2,1,5,3 };

	static oid openserSIPRegCurrentUsers_oid[]          =
		{ OPENSER_OID,3,1,2,1,5,4 };

	static oid openserSIPRegDfltRegActiveInterval_oid[] =
		{ OPENSER_OID,3,1,2,1,5,5 };

	static oid openserSIPRegUserLookupCounter_oid[]     =
		{ OPENSER_OID,3,1,2,1,5,8 };

	static oid openserSIPRegAcceptedRegistrations_oid[] =
		{ OPENSER_OID,3,1,2,1,6,1 };

	static oid openserSIPRegRejectedRegistrations_oid[] =
		{ OPENSER_OID,3,1,2,1,6,2 };

	DEBUGMSGTL(("openserSIPServerObjects", "Initializing\n"));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPProxyStatefulness",
			handle_openserSIPProxyStatefulness,
			openserSIPProxyStatefulness_oid,
			OID_LENGTH(openserSIPProxyStatefulness_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPProxyRecordRoute",
			handle_openserSIPProxyRecordRoute,
			openserSIPProxyRecordRoute_oid,
			OID_LENGTH(openserSIPProxyRecordRoute_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPProxyAuthMethod",
			handle_openserSIPProxyAuthMethod,
			openserSIPProxyAuthMethod_oid,
			OID_LENGTH(openserSIPProxyAuthMethod_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPNumProxyRequireFailures",
			handle_openserSIPNumProxyRequireFailures,
			openserSIPNumProxyRequireFailures_oid,
			OID_LENGTH(openserSIPNumProxyRequireFailures_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPRegMaxContactExpiryDuration",
			handle_openserSIPRegMaxContactExpiryDuration,
			openserSIPRegMaxContactExpiryDuration_oid,
			OID_LENGTH(openserSIPRegMaxContactExpiryDuration_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPRegMaxUsers",
			handle_openserSIPRegMaxUsers,
			openserSIPRegMaxUsers_oid,
			OID_LENGTH(openserSIPRegMaxUsers_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPRegCurrentUsers",
			handle_openserSIPRegCurrentUsers,
			openserSIPRegCurrentUsers_oid,
			OID_LENGTH(openserSIPRegCurrentUsers_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPRegDfltRegActiveInterval",
			handle_openserSIPRegDfltRegActiveInterval,
			openserSIPRegDfltRegActiveInterval_oid,
			OID_LENGTH(openserSIPRegDfltRegActiveInterval_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPRegUserLookupCounter",
			handle_openserSIPRegUserLookupCounter,
			openserSIPRegUserLookupCounter_oid,
			OID_LENGTH(openserSIPRegUserLookupCounter_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPRegAcceptedRegistrations",
			handle_openserSIPRegAcceptedRegistrations,
			openserSIPRegAcceptedRegistrations_oid,
			OID_LENGTH(openserSIPRegAcceptedRegistrations_oid),
			HANDLER_CAN_RONLY));

	netsnmp_register_scalar(
		netsnmp_create_handler_registration(
			"openserSIPRegRejectedRegistrations",
			handle_openserSIPRegRejectedRegistrations,
			openserSIPRegRejectedRegistrations_oid,
			OID_LENGTH(openserSIPRegRejectedRegistrations_oid),
			HANDLER_CAN_RONLY));
}

/* The following are handlers for the scalars in the OPENSER-SIP-SERVER-MIB. */

int handle_openserSIPProxyStatefulness(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	int statefullness;

	if (module_loaded("dialog")) 
	{
		statefullness = PROXY_STATEFULNESS_CALL_STATEFUL;
	}
	else if (module_loaded("tm"))
	{
		statefullness = PROXY_STATEFULNESS_TRANSACTION_STATEFUL;
	}
	else
	{
		statefullness = PROXY_STATEFULNESS_STATELESS;
	}

	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
			(u_char *) &statefullness, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}


int handle_openserSIPProxyRecordRoute(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	/* If the rr module is loaded, then we support record route.  otherwise,
	 * we want to return 2, which is false for SNMP TruthValue. */
	int supportRecordRoute = TC_FALSE;

	if (module_loaded("rr"))
	{
		supportRecordRoute = TC_TRUE;
	}
    
	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
			(u_char *) &supportRecordRoute, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}

int handle_openserSIPProxyAuthMethod(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{

	/* The result needs to be returned as an SNMP bit field. */
	unsigned int auth_bitfield = SIP_AUTH_METHOD_NONE;
	
	if (module_loaded("tls")) {
		auth_bitfield |=  SIP_AUTH_METHOD_TLS;
		auth_bitfield &= ~SIP_AUTH_METHOD_NONE;
	}
	
	/* We can have both tls and auth loaded simultaneously.  Therefore we
	 * use an if instead of a else/else-if. */
	if (module_loaded("auth")) {
		auth_bitfield |= SIP_AUTH_METHOD_DIGEST;
		auth_bitfield &= ~SIP_AUTH_METHOD_NONE;
	}

	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_OCTET_STR,
			(u_char *) &auth_bitfield, 1);
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}

int handle_openserSIPNumProxyRequireFailures(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	int result = get_statistic("bad_msg_hdr"); 
   
	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_COUNTER,
			(u_char *) &result, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}

int handle_openserSIPRegMaxContactExpiryDuration(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	int result = get_statistic("max_expires");
    
	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_UNSIGNED,
			(u_char *) &result, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}

int handle_openserSIPRegMaxUsers(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{

	/* OpenSER doesn't currently have a parameterized maximum number of
	 * users.  So we return the maximum value an unsigned32 SNMP datatype
	 * can hold.  */
	unsigned int result = 0xffffffff; 
	
	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_UNSIGNED,
			(u_char *) &result, sizeof(unsigned int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}

int handle_openserSIPRegCurrentUsers(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	int max_users = 0;

	max_users = get_statistic("registered_users");
	
	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_GAUGE,
			(u_char *) &max_users, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}

int handle_openserSIPRegDfltRegActiveInterval(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	int result = get_statistic("default_expire");
	
	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_UNSIGNED,
			(u_char *) &result, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}


int handle_openserSIPRegUserLookupCounter(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	int result = ++global_UserLookupCounter;

	/* If we have had so many requests that we've hit our maximum index,
	 * then we reset our counter back to 1.  For this not to cause problems,
	 * it will be required that old rows belonging to the table 
	 * openserSIPRegUserLookupTable are eventually deleted. */
	if (global_UserLookupCounter > MAX_USER_LOOKUP_COUNTER) {
		global_UserLookupCounter = 1;
	}

	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_COUNTER,
			(u_char *) &result, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}

int handle_openserSIPRegAcceptedRegistrations(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	int result = get_statistic("accepted_regs");
	
	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_COUNTER,
			(u_char *) &result, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}

int handle_openserSIPRegRejectedRegistrations(netsnmp_mib_handler *handler,
	netsnmp_handler_registration *reginfo,
	netsnmp_agent_request_info   *reqinfo,
	netsnmp_request_info         *requests)
{
	int result = get_statistic("rejected_regs");
	
	if (reqinfo->mode==MODE_GET) {
		snmp_set_var_typed_value(requests->requestvb, ASN_COUNTER,
			(u_char *) &result, sizeof(int));
		return SNMP_ERR_NOERROR;
	}

	return SNMP_ERR_GENERR;
}
