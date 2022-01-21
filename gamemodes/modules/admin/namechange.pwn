YCMD:namechange(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid, newname[25];
	if(sscanf(params, "rs[25]", targetid, newname)) return SCM(playerid, HEX_FADE2, "Usage: /rename [id] [Firstname_Lastname]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "is[25]", targetid, newname);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	if(strlen(newname) > 25) return SCM(playerid, HEX_RED, "Error: A player name can be maximum 25 characters.");

	new string[256];
	format(string, sizeof string, "%s %s has namechanged %s[%i] to %s.", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid, newname);
	SendAdminMessage(HEX_YELLOW, string, true);

	SetPlayerName(targetid, newname);

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `name` = '%e' WHERE id = %d LIMIT 1", newname, CharacterSQL[targetid]);
	mysql_tquery(g_SQL, sql, "", "");
	printf("%s", sql);

	if(playerid != targetid) 
	{
		format(string, sizeof string, "[Desolation]: %s %s has changed your name to %s.", AdminNames[adminlevel[playerid]], PlayerName(playerid), newname);
		SCM(targetid, HEX_YELLOW, string);
	}
	
	return 1;
}