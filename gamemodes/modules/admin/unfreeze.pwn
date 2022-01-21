YCMD:unfreeze(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid=INVALID_PLAYER_ID;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /unfreeze [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	UnfreezePlayer(targetid);
	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has unfrozen %s.",AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid));
	SendAdminMessage(HEX_YELLOW, string, true);
	return 1;
}

stock UnfreezePlayer(playerid) {
	TogglePlayerControllable(playerid, true);
	return 1;
}
forward UnfreezeTimer(playerid);
public UnfreezeTimer(playerid) {
	UnfreezePlayer(playerid);
	return 1;
}