YCMD:checkweapons(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;	
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /checkweapons [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	new weapons[13][2];
	new string[512], string2[128];
	new bool:match = false;
	for (new i = 0; i <= 12; i++) {
		GetPlayerWeaponData(targetid, i, weapons[i][0], weapons[i][1]);
		if(weapons[i][0] > 0) {
			format(string2, sizeof string2, "%s[%d]; ", DeathReason(weapons[i][0]), weapons[i][1]);
			strcat(string, string2);
			match = true;
		}
	}
	if(match) {
		SFM(playerid, HEX_FADE2, "%s's weapons:", PlayerName(targetid));
		SCM(playerid, HEX_FADE2, string);
	}
	else
		SFM(playerid, HEX_FADE2, "%s has no weapon.", PlayerName(targetid));
	return 1;
}