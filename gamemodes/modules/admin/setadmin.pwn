YCMD:setadmin(playerid, params[], help) {
    if(adminlevel[playerid] < 6) return SendErrorMessage(playerid, ERROR_ADMIN);

	new targetid, targetlevel;
	if(sscanf(params, "rd", targetid, targetlevel)) return  SCM(playerid, HEX_RED, "/setadmin [playerid] [level]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "ii", targetid, targetlevel);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(targetlevel < -1 || targetlevel > 6) return SCM(playerid, HEX_RED, "Admin levels are ONLY between -1 and 6");

	adminlevel[targetid] = targetlevel;
	Group_SetPlayer(g_Admin, targetid, true);
	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET adminlevel = %d WHERE id = %d LIMIT 1", targetlevel, AccountSQL[targetid]);
	mysql_tquery(g_SQL, sql, "", "");
	printf("%s", sql);

	return 1;
}
