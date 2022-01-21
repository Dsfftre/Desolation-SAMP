YCMD:kick(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
	new pID, str[256], reason[128];
	if(sscanf(params, "rS(Not specified)[128]", pID,reason)) return SCM(playerid, HEX_FADE2, "/kick [id]");
	if(pID == INVALID_PLAYER_ID) {
		unformat(params, "i", pID);
		if(!IsPlayerConnected(pID) || IsPlayerNPC(pID))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(adminlevel[pID] != 0 && adminlevel[playerid] < 5)
	{
		SCM(playerid, HEX_RED, "You can't kick admins.");
	}
	else
	{
		if(adminlevel[playerid] != -1)
			format(str, sizeof(str), "Admin %s has kicked  %s | Reason: %s", PlayerName(playerid), PlayerName(pID), reason);
		else
			format(str, sizeof(str), "%s has been kicked | Reason: %s", PlayerName(pID), reason);
		//SendAdminMessage(HEX_RED, str, true);
		SendClientMessageToAll(COLOR_RED, str);
		KickPlayer(pID);
	}
	return 1;
}