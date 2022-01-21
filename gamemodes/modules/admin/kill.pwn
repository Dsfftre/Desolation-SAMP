YCMD:kill(playerid, params[], help) {
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /kill [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	SetPlayerHealth(targetid, 0.0);
	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has killed %s.",AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid));
	SendAdminMessage(HEX_YELLOW, string, true);
	return 1;
}