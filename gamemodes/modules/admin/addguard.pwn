YCMD:addguard(playerid, params[], help) {
	if(adminlevel[playerid] < 5) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	if(GetPlayerInterior(playerid) + GetPlayerVirtualWorld(playerid) > 0) return SCM(playerid, HEX_RED, "Error: You cannot spawn guards in interiors. Your virtualworld and interior id must be 0.");

	new Float:p_pos[4];
	GetPlayerPos(playerid, p_pos[0], p_pos[1], p_pos[2]);
	GetPlayerFacingAngle(playerid, p_pos[3]);

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `npc_guards` (`posx`, `posy`, `posz`, `posf`, `created_playerId`) VALUES ('%f', '%f', '%f', '%f', '%d')",  p_pos[0], p_pos[1], p_pos[2], p_pos[3], CharacterSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");	

	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has spawned a new guard. (It will spawn after the server restarts.)", AdminNames[adminlevel[playerid]], PlayerName(playerid), playerid);
	SendAdminMessage(HEX_YELLOW, string, true);
	//AdminLog(string);
	return 1;
}