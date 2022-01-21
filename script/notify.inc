/*#if defined _inc_useitem
	#undef _inc_useitem
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>


SendNotifications(playerid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `notifications` WHERE accountid = '%d' AND state = '1'", AccountSQL[playerid]);
	inline LoadNotifications() {
		if(!cache_num_rows()) {
			@return 0;
		}
		
		SCM(playerid, HEX_RED, "You have the following notifications:");
		new i = -1;
		new string[256];
		for(;++i<cache_num_rows();) {
			cache_get_value(i, "admwarn", string, 256);
			SCM(playerid, HEX_FADE2, string);
		}

		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `notifications` set `state` = 0 WHERE accountid = %d", AccountSQL[playerid]);
        mysql_tquery(g_SQL, sql, "", "");
		
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadNotifications, sql);
	return 1;
}


hook OnPlayerSpawn(playerid) {
	if(Bit_Get(loggedin, playerid) && Bit_Get(character, playerid))
		SendNotifications(playerid);

	new pemail[128];
	format(pemail, sizeof pemail, "%s", GetSQLEmail(playerid));
	if(!strcmp(pemail, "empty", false, 128))
		SCM(playerid, HEX_YELLOW, "You do not have an email connected to your account. You can add it with the /email command.");

	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:notify(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);

	new aID, reason[256];
	if(sscanf(params, "iS(Not specified)[256]", aID, reason)) return SCM(playerid, HEX_FADE2, "/notify [accountid] [reason] (Hint: Use /whois character_name to figure out someone's ACCOUNT ID.)");

	if(strlen(reason) < 3)  return SCM(playerid, HEX_FADE2, "/notify [accountid] [reason]");

	AddNotification(aID, reason);
	
	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has added a notification to account[%d]: %s", AdminNames[adminlevel[playerid]], PlayerName(playerid), aID, reason);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

YCMD:reportwarn(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);

	new aID;
	if(sscanf(params, "i", aID)) return SCM(playerid, HEX_FADE2, "/reportwarn [accountid]");

	AddReportWarn(aID);
	
	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has added a notification (/reportwarn) to account[%d]: Your are officially notified to check your pending reports on the forum!", AdminNames[adminlevel[playerid]], PlayerName(playerid), aID);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

AddNotification(aID, reason[]) {
	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `notifications` (`accountid`, `admwarn`) VALUES ('%d', '%e')", aID, reason);
	mysql_tquery(g_SQL, sql, "", "");	
	return 1;
}

AddReportWarn(aID) {
	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `notifications` (`accountid`) VALUES ('%d')", aID);
	mysql_tquery(g_SQL, sql, "", "");	
	return 1;
}