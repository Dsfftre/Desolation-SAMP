YCMD:addloot(playerid, params[], help) {	
	new string[256];
	if(adminlevel[playerid] < 4) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	
	new Float:pos[3],
		category,
		vw,
		int;

    if(sscanf(params,"i", category)) return SCM(playerid, HEX_FADE2, "Usage: /addloot [category] (2 consumable, 3 military, 4 police, 5 tool, 6 sex toy)");

	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `loot` (`itemlistCategory`, `posx`, `posy`, `posz`, `virtualworld`, `interior`) VALUES ('%d', '%f', '%f', '%f', '%d', '%d')", category, pos[0], pos[1], pos[2], vw, int);
	mysql_tquery(g_SQL, sql, "", "");

	format(string, sizeof string, "[LOG]: %s %s has spawned a new a new item. (It will spawn after the server restarts.)", AdminNames[adminlevel[playerid]], PlayerName(playerid), playerid);
	SendAdminMessage(HEX_YELLOW, string, true);
	//AdminLog(string);

	return 1;
}