YCMD:checkstats(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid = playerid;
	if(adminlevel[playerid] != 0) 
	{
		if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /stats [id]");
		if(targetid == INVALID_PLAYER_ID)  {
			unformat(params, "i", targetid);
			if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}

	}

	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Float:healthp[2];
	GetPlayerHealth(targetid, healthp[0]);
	GetPlayerArmour(targetid, healthp[1]);
	new killstat[3];

	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player` WHERE id = %d", CharacterSQL[targetid]);
	inline LoadStats() {
		if(!cache_num_rows()) {
			@return 0;
		}		
		cache_get_value_int(0, "kills", killstat[0]);		
		cache_get_value_int(0, "zkills", killstat[1]);
		cache_get_value_int(0, "deaths", killstat[2]);
		if(targetid == playerid)
			SFM(playerid, HEX_ORANGE, ":: ________ :: Stats of %s on %02d/%02d/%d %02d:%02d:%02d :: ________ ::",PlayerName(targetid, true), Year, Month, Day, Hour, Minute, Second);
		else
			SFM(playerid, HEX_ADMIN, ":: ________ :: Stats of %s on %02d/%02d/%d %02d:%02d:%02d :: ________ ::",PlayerName(targetid, true), Year, Month, Day, Hour, Minute, Second);
		SFM(playerid, HEX_FADE2, "Account | sqlid:[%d] accountid:[%d] accountname: [%s] adminlevel:[%d]", CharacterSQL[targetid], AccountSQL[targetid], accountname[targetid], adminlevel[targetid]);
		SFM(playerid, HEX_FADE2, "Player | level:[%d] experience:[%d] cash:[%d] health:[%2.f] armor:[%2.f]", GetPlayerScore(targetid), experience[targetid], cash[targetid], healthp[0], healthp[1]);
		SFM(playerid, HEX_FADE2, "Player | player kills:[%d] zombie kills:[%d] deaths:[%d]", killstat[0], killstat[1], killstat[2]);
		SFM(playerid, HEX_FADE2, "Player | skin:[%d] zombierace:[%s] interior:[%d] virtualworld:[%d]", GetPlayerSkin(targetid), ZombieRaceName(zombierace[targetid]), GetPlayerInterior(targetid), GetPlayerVirtualWorld(targetid)); 
		if(faction[targetid] > 0)
			ShowFactionStats(playerid, targetid);
		if(city[targetid] > 0)
			ShowCityStats(playerid, targetid);
		SFM(playerid, HEX_FADE2, "Flags | zombie:[%d] infected:[%d] dead:[%d] frozen:[%d] hints:[%d] radiation:[%d]", onezero(Bit_Get(pzombie, targetid)), onezero(Bit_Get(infected, targetid)), onezero(Bit_Get(dead, targetid)), onezero(Bit_Get(frozen, targetid)), onezero(Bit_Get(tutorial, targetid)), onezero(Bit_Get(radiation, targetid)) );
		if(targetid == playerid)
			SFM(playerid, HEX_ORANGE, ":: ________ :: Stats of %s on %02d/%02d/%d %02d:%02d:%02d :: ________ ::",PlayerName(targetid, true), Year, Month, Day, Hour, Minute, Second);
		else
			SFM(playerid, HEX_ADMIN, ":: ________ :: Stats of %s on %02d/%02d/%d %02d:%02d:%02d :: ________ ::",PlayerName(targetid, true), Year, Month, Day, Hour, Minute, Second);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadStats, sql);
	return 1;
}