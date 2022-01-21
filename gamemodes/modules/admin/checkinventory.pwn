YCMD:checkinventory(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;

	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /checkinventory [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	mysql_format(g_SQL, sql, sizeof sql, "SELECT pi.*, il.name FROM `player_items` AS pi INNER JOIN `itemlist` AS il ON il.id = pi.itemId WHERE pi.state = 1 AND pi.playerId = %d LIMIT %d", CharacterSQL[targetid], MAX_INVENTORY_SLOTS);
	inline LoadInventoryData() {
		if(!cache_num_rows()) {
			SFM(playerid, HEX_FADE2, "%s's inventory is empty.", PlayerName(targetid));
			@return 1;
		}

		SFM(playerid,HEX_LORANGE,"%s's items:", PlayerName(targetid));
		new string[2048];
		new tmp_return[32];
		new tmp_string[128], tmp_amount, i = -1;
		for(;++i<cache_num_rows();) {
			tmp_return = "ERROR";
			cache_get_value_int(i, "amount", tmp_amount);
			cache_get_value(i, "name", tmp_return, 32);
			
			if(tmp_amount > 1)
				format(tmp_string,sizeof(tmp_string),"[%i. %s (%i) ] ",i+1, tmp_return,tmp_amount);
			else
				format(tmp_string,sizeof(tmp_string),"[%i. %s ] ",i+1, tmp_return);
			strcat(string,tmp_string);
			if(i%5==0 && i != 0) {
				SCM(playerid,HEX_WHITE,string);
				string = "";
			}
		}
		if(!IsPlayerConnected(playerid)) @return 1;
		if(strlen(string)>0)
			SCM(playerid, HEX_WHITE, string);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadInventoryData, sql);

	return 1;
}