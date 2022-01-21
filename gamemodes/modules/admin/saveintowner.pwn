YCMD:saveintowner(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid, targetp;
	if(sscanf(params, "ii",targetid, targetp)) return SCM(playerid, HEX_FADE2, "Usage: /saveintowner [sqlid] [playersql]");
	
	foreach(new i:Entrances) {
		if(IntInfo[i][sqlid] == targetid) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `playerId` = '%d' WHERE id = '%d' LIMIT 1", targetp, targetid);
			mysql_tquery(g_SQL, sql, "", "");

			IntInfo[i][player] = targetp;

			new string[256];
			format(string, sizeof string, "[LOG]: %s %s has set entrance %d's owner to %d (%s).", AdminNames[adminlevel[playerid]], PlayerName(playerid), targetid, targetp, GetSQLCharname(targetp));
			SendAdminMessage(HEX_YELLOW, string, true);

			return 1;
		}
	}

	SCM(playerid, HEX_RED, "Error: Invalid entrance sqlid!");

	return 1;
}