YCMD:addzombie(playerid, params[], help) {
	if(adminlevel[playerid] < 5) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	if(GetPlayerInterior(playerid) + GetPlayerVirtualWorld(playerid) > 0) return SCM(playerid, HEX_RED, "Error: You cannot spawn zombies in interiors. Your virtualworld and interior id must be 0.");

	new Float:p_pos[3];
	GetPlayerPos(playerid, p_pos[0], p_pos[1], p_pos[2]);

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `npc_zombies` (`posx`, `posy`, `posz`, `created_playerId`) VALUES ('%f', '%f', '%f', '%d')",  p_pos[0], p_pos[1], p_pos[2], CharacterSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");	

	new string[256];
	format(string, sizeof string, "[LOG]: %s[%d] has spawned a new zombie. (It will spawn after the server restarts.)", PlayerName(playerid), playerid);
	SendAdminMessage(HEX_YELLOW, string, true);
	//AdminLog(string);
	return 1;
}