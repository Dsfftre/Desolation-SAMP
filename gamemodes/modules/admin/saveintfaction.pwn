YCMD:saveintfaction(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid, targetf;
	if(sscanf(params, "ii",targetid, targetf)) return SCM(playerid, HEX_FADE2, "Usage: /saveintfaction [sqlid] [factionsql]");
	
	foreach(new i:Entrances) {
		if(IntInfo[i][sqlid] == targetid) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `factionId` = '%d' WHERE id = '%d' LIMIT 1", targetf, targetid);
			mysql_tquery(g_SQL, sql, "", "");

			IntInfo[i][factionId] = targetf;

			new string[256];
			format(string, sizeof string, "[LOG]: %s %s has set entrance %d's faction to %d (%s).", AdminNames[adminlevel[playerid]], PlayerName(playerid), targetid, targetf, GetSQLFactionname(targetf));
			SendAdminMessage(HEX_YELLOW, string, true);

			return 1;
		}
	}

	SCM(playerid, HEX_RED, "Error: Invalid entrance sqlid!");

	return 1;
}

YCMD:saveintcity(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid, targetf;
	if(sscanf(params, "ii",targetid, targetf)) return SCM(playerid, HEX_FADE2, "Usage: /saveintcity [sqlid] [citysql]");
	
	foreach(new i:Entrances) {
		if(IntInfo[i][sqlid] == targetid) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `cityId` = '%d' WHERE id = '%d' LIMIT 1", targetf, targetid);
			mysql_tquery(g_SQL, sql, "", "");

			IntInfo[i][cityId] = targetf;

			new string[256];
			format(string, sizeof string, "[LOG]: %s %s has set entrance %d's city to %d (%s).", AdminNames[adminlevel[playerid]], PlayerName(playerid), targetid, targetf, GetSQLCityname(targetf));
			SendAdminMessage(HEX_YELLOW, string, true);

			return 1;
		}
	}

	SCM(playerid, HEX_RED, "Error: Invalid entrance sqlid!");

	return 1;
}