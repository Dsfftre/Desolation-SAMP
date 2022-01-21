YCMD:freeze(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid=INVALID_PLAYER_ID;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /freeze [id] [time in seconds (optional)]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	FreezePlayer(targetid);
	new string[256];
	format(string, sizeof string, "[LOG]: %s has frozen %s", PlayerName(playerid), PlayerName(targetid));
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

stock FreezePlayer(playerid, time=0) {
	TogglePlayerControllable(playerid, false);
	if(time > 0) 
	{
		SetTimerEx("UnfreezeTimer", time*1000, false, "i", playerid);
	}
	return 1;
}