YCMD:zombierace(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	
	new targetid, pzrace;

    if(sscanf(params,"ud", targetid, pzrace)) return SCM(playerid, HEX_FADE2, "Usage: /zombierace [id] [race] (Hint: Wanderer[0], Jumper[1], Runner[2], Bloater[3], Screecher[4], Sniffer[5], Hulks[6], Tyrant[7])");
	
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "ii", targetid, pzrace);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(pzrace < 0 || pzrace > 7) return SCM(playerid, HEX_RED, "Error: Invalid zombie race id.");

    zombierace[targetid] = pzrace;

	new stringa[256];
	format(stringa, sizeof stringa, "[LOG]: %s %s has zombie race-changed %s[%d] to %s.", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid, ZombieRaceName(zombierace[targetid]));
	SendAdminMessage(HEX_YELLOW, stringa, true);
	SFM(targetid, HEX_YELLOW, "[LOG]: %s %s has changed your zombie race to '%s'.", AdminNames[adminlevel[playerid]], PlayerName(playerid), playerid, ZombieRaceName(zombierace[targetid]));
	return 1;
}