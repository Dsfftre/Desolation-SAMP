YCMD:listitems(playerid, params[], help) {
	if(adminlevel[playerid] < 4) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	mysql_format(g_SQL, sql, sizeof sql, "SELECT id, name FROM `itemlist`");

	inline LoadItemNames() {
		if(!cache_num_rows()) {
			SCM(playerid, HEX_RED, "Error: Failed to reach item database.");
			@return 0;
		}
		
		new i = -1;
		new iid, iname[64], string[1024], tmpstring[128];
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", iid);
			cache_get_value(i, "name", iname, 64);
			format(tmpstring, sizeof tmpstring, "%s:[%d] ", iname, iid);
			strcat(string, tmpstring);
			tmpstring = "";
			if(i%8==0 && i > 0) {
				SCM(playerid, HEX_FADE2, string);
				string = "";
			}
		}
		if(strlen(string) > 3)
			SCM(playerid, HEX_FADE2, string);

		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadItemNames, sql);

	return 1;
}