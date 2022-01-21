YCMD:whois(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);

	new lookup[128];
	if(sscanf(params, "s[128]", lookup)) return SCM(playerid, HEX_FADE2, "/whois [character_name]");

	mysql_format(g_SQL, sql, sizeof sql, "SELECT ac.id AS ac_id, ac.name AS ac_name, ac.adminlevel AS ac_adminlevel, ac.state AS ac_state, ac.email AS ac_email, pi.* FROM account AS ac INNER JOIN player AS pi ON ac.id = pi.accountId WHERE pi.name = '%e' LIMIT 1", lookup);
	inline LoadWhoisData() {
		if(!cache_num_rows()) {
			SCM(playerid, HEX_FADE2, "Player not found!");
			@return 0;
		}

		SFM(playerid, HEX_ADMIN, "WHOIS lookup results on playername '%s' on '%s'", lookup, ReturnTime());

		new acc_id, acc_name[128], acc_admin, acc_state, acc_email[128];

		cache_get_value_int(0, "ac_id", acc_id);
		cache_get_value(0, "ac_name", acc_name, 128);
		cache_get_value_int(0, "ac_adminlevel", acc_admin);
		cache_get_value_int(0, "ac_state", acc_state);
		cache_get_value(0, "ac_email", acc_email, 128);
		SFM(playerid, HEX_BLUE, "Account: id:[%d] name:[%s] adminlevel:[%d] state:[%d] email:[%s]", acc_id, acc_name, acc_admin, acc_state, acc_email);

		new pl_id, pl_name[128], pl_level, pl_faction, pl_city, pl_experience, pl_factionrank[32];
		new Float:pl_hp, Float:pl_armor, Float:pl_hunger, Float:pl_thirst;
		new pl_spawninterior, pl_deaths, pl_kills, pl_zkills, pl_deadstatus;
		new pl_credate[128], pl_logindate[128];

		cache_get_value_int(0, "id", pl_id);
		cache_get_value(0, "name", pl_name, 128);
		cache_get_value_int(0, "level", pl_level);
		cache_get_value_int(0, "factionId", pl_faction);
		cache_get_value_int(0, "cityId", pl_city);
		cache_get_value_int(0, "experience", pl_experience);
		cache_get_value(0, "rank", pl_factionrank, 32);
		cache_get_value_float(0, "health", pl_hp);
		cache_get_value_float(0, "armor", pl_armor);
		cache_get_value_float(0, "hunger", pl_hunger);
		cache_get_value_float(0, "thirst", pl_thirst);
		cache_get_value_int(0, "spawnInteriors", pl_spawninterior);
		cache_get_value_int(0, "deaths", pl_deaths);
		cache_get_value_int(0, "kills", pl_kills);
		cache_get_value_int(0, "zkills", pl_zkills);
		cache_get_value_int(0, "deadstatus", pl_deadstatus);
		cache_get_value(0, "creDate", pl_credate, 128);
		cache_get_value(0, "loginDate", pl_logindate, 128);

		SFM(playerid, HEX_FADE2, "Player: id:[%d] name:[%s] level:[%d] experience:[%d]", pl_id, pl_name, pl_level, pl_experience);
		SFM(playerid, HEX_FADE2, "Player: hp:[%f] armor:[%f] hunger:[%f] thirst:[%f]", pl_hp, pl_armor, pl_hunger, pl_thirst);
		SFM(playerid, HEX_FADE2, "Player: deadstatus:[%d] deaths:[%d] kills:[%d] npckills:[%d] ", pl_deadstatus, pl_deaths, pl_kills, pl_zkills);
		SFM(playerid, HEX_FADE2, "Player: faction:[%d] factionrank:[%s] city:[%d] spawninterior:[%d]", pl_faction, pl_factionrank, pl_city, pl_spawninterior);
		SFM(playerid, HEX_FADE2, "Player: created:[%s] lastlogin:[%s]", pl_credate, pl_logindate);

		Account_bancheck(playerid, acc_id);

		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadWhoisData, sql);
	

	return 1;
}

Account_bancheck(playerid, accountsql)
{
	mysql_format(g_SQL, sql, sizeof(sql), "SELECT * FROM bans WHERE A_ID = %d LIMIT 1", accountsql);
	inline Load_Account_bancheck() {
		if(!cache_num_rows()) {
			@return 0;
		}
		else {
			new i = -1;
			for(;++i<cache_num_rows();) {
				new banid, bannedp[MAX_PLAYER_NAME], bannedip[18], bannername[MAX_PLAYER_NAME], banreason[128], bantime[64];
				cache_get_value_int(i, "id", banid);
				cache_get_value(i, "PlayerName", bannedp, MAX_PLAYER_NAME);
				cache_get_value(i, "BannedBy", bannername, MAX_PLAYER_NAME);
				cache_get_value(i, "Reason", banreason, 128);
				cache_get_value(i, "IP", bannedip, 18);
				cache_get_value(i, "Timestamp", bantime, 64);
				SFM(playerid, HEX_RED, "Ban[%d]: name(when banned):[%s] ip:[%s] bannedby:[%s] reason:[%s] timestamp:[%s]", banid, bannedp, bannedip, bannername, banreason, bantime);
			}
			
		}
	}
	MySQL_TQueryInline(g_SQL, using inline Load_Account_bancheck, sql);
	return 1;
}