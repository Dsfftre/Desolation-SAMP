YCMD:ban(playerid, params[], help) {
	if(adminlevel[playerid] < 2 && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);

	new pID, str[128], reason[128];
	if(sscanf(params, "iS(Not specified)[128]", pID, reason)) return SCM(playerid, HEX_FADE2, "/ban [id] [reason]");
	if(pID == INVALID_PLAYER_ID) {
		unformat(params, "i", pID);
		if(!IsPlayerConnected(pID) || IsPlayerNPC(pID))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(!IsPlayerConnected(pID)) return SCM(playerid, HEX_RED, "Error: Invalid player. Only use id!");
	if(adminlevel[pID] != 0 && adminlevel[playerid] < 6) {
		SCM(playerid, HEX_RED, "You can't ban admins.");
	}
	else
	{
		if(adminlevel[playerid] != -1)
			format(str, sizeof(str), "Admin %s has banned %s | Reason: %s", PlayerName(playerid), PlayerName(pID), reason);
		else
			format(str, sizeof(str), "%s has been banned | Reason: %s", PlayerName(pID), reason);
		//SendAdminMessage(HEX_RED, str, true);
		SendClientMessageToAll(COLOR_RED, str);
		IssueBan(pID, PlayerName(playerid), reason, false);
	}
	//AdminLog(string);
	

	return 1;
}

YCMD:unban(playerid, params[], help) {
	if(adminlevel[playerid] < 2 && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);

	new pID;
	if(sscanf(params, "i", pID)) return SCM(playerid, HEX_FADE2, "/unban [charactersql]");

	new str[256];
	format(str, sizeof(str), "AdmWrn: %s has unbanned character sql %d.", PlayerName(playerid), pID);
	SendAdminMessage(HEX_RED, str, true);
	RemoveBan(pID);

	return 1;
}

IssueBan(playerid, adminname[], reason[], bool:message = true)
{	
	new ip[18];
	GetPlayerIp(playerid, ip, 18);
    mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO bans (PlayerName, IP, C_ID, A_ID, BannedBy, Reason) VALUES('%s', '%s', %d, %d, '%s', '%e')", PlayerName(playerid), ip, CharacterSQL[playerid], AccountSQL[playerid], adminname, reason);
	mysql_tquery(g_SQL, sql, "", "");
	if(message) {
		new str[256];
		format(str, sizeof(str), "%s has been banned | Reason: %s", PlayerName(playerid), reason);
		SendClientMessageToAll(COLOR_RED, str);
	}
	KickPlayer(playerid);
	return 1;
}

RemoveBan(charsql)
{	
    mysql_format(g_SQL, sql, sizeof sql, "DELETE FROM `bans` WHERE C_ID = %d LIMIT 1", charsql);//devnote: add check
	mysql_tquery(g_SQL, sql, "", "");

	return 1;
}