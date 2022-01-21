YCMD:humanrace(playerid, params[], help) {
	if(adminlevel[playerid] < 6) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid, prace;
    if(sscanf(params,"ud", targetid, prace)) return SCM(playerid, HEX_FADE2, "Usage: /humanrace [id] [race] (Hint: Jumper[0], Native[1], Asurmen[2], Cimmerians[3], Type Human Tyrant[4], Ancient Atlantean[5])");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "ii", targetid, prace);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(prace < 0 || prace > 6) return SCM(playerid, HEX_RED, "Error: Invalid human race id.");

    race[targetid] = prace;

	new string[256];
	format(string, sizeof string, "[LOG]: %S %s has race-changed %s[%d] to %s.", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid, RaceName(race[targetid]));
	SendAdminMessage(HEX_YELLOW, string, true);
	SFM(targetid, HEX_YELLOW, "[LOG]: %s %s has changed your human race to '%s'.", AdminNames[adminlevel[playerid]], PlayerName(playerid), playerid, RaceName(race[targetid]));
	return 1;
}