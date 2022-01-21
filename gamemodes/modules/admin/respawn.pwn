YCMD:respawn(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	new targetid;
	if(Group_GetPlayer(g_Admin, playerid))
	{
		if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /respawn [id]");
		if(targetid == INVALID_PLAYER_ID) {
			unformat(params, "i", targetid);
			if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}

		if(IsPlayerInAnyVehicle(targetid))
		RemovePlayerFromVehicle(targetid);	

		mysql_format(g_SQL, sql, sizeof sql, "SELECT `spawnInteriors` FROM `player` WHERE id = '%d' AND state = 1 LIMIT 1", CharacterSQL[targetid]);
		inline LoadRespawnInfo() {
			if(!cache_num_rows()) {
				SetPlayerPos(targetid, 1797.6653, -1869.5405, 13.5742);
				SetPlayerFacingAngle(targetid, 0.0);
				SetPlayerInterior(targetid, 0);
				SetPlayerVirtualWorld(targetid, 0);
				ChangeMaskVW(targetid);
				@return 1;
			}
			
			new spawninginti;
			cache_get_value_int(0, "spawnInteriors", spawninginti);
			new bool:spawnedatinti = false;
			foreach(new i:Entrances) {
				if(IntInfo[i][sqlid] == spawninginti) {
					SetPlayerVirtualWorld(targetid, IntInfo[i][outvw]);
					SetPlayerInterior(targetid, IntInfo[i][outint]);
					SetPlayerPos(targetid, IntInfo[i][outx],IntInfo[i][outy],IntInfo[i][outz]);
					SetPlayerFacingAngle(targetid, IntInfo[i][outf]);
					ChangeMaskVW(targetid);
					spawnedatinti = true;
					break;
				}
			}

			if(!spawnedatinti) {
				SetPlayerPos(targetid, 1797.6653, -1869.5405, 13.5742);
				SetPlayerFacingAngle(targetid, 0.0);
				SetPlayerInterior(targetid, 0);
				SetPlayerVirtualWorld(targetid, 0);
				ChangeMaskVW(targetid);
				@return 1;
			}

			@return 1;
		}
		MySQL_TQueryInline(g_SQL, using inline LoadRespawnInfo, sql);

		new string[256];
		format(string, sizeof string, "%s %s has respawned %s[%i].", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid);
		SendAdminMessage(HEX_YELLOW, string, true);		
	}
	return 1;
}