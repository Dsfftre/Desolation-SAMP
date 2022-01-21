YCMD:feed(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /feed [id]");
	if(targetid == INVALID_PLAYER_ID)  {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	hunger[targetid] = 100.0;
	thirst[targetid] = 100.0;

	RefreshBars(targetid);
	
	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has refilled %s's hunger and thirst.", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid);
	SendAdminMessage(HEX_YELLOW, string, true);
	if(playerid != targetid) {
		format(string, sizeof string, "[LOG]: %s %s has refilled your hunger and thirst.", AdminNames[adminlevel[playerid]], PlayerName(playerid));
		SCM(targetid, HEX_YELLOW, string);
	}
	return 1;
}