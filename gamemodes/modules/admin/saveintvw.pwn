YCMD:saveintvw(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid, targetvw;
	if(sscanf(params, "ii",targetid, targetvw)) return SCM(playerid, HEX_FADE2, "Usage: /saveintvw [sqlid] [virtualwrold] (Saves the entrance's inside virtualworld! Unless it's a special mapping the virtualworld needs to be equal to the sqlid!)");
	
	foreach(new i:Entrances) {
		if(IntInfo[i][sqlid] == targetid) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `intvw` = '%d' WHERE id = '%d' LIMIT 1", targetvw, targetid);
			mysql_tquery(g_SQL, sql, "", "");
			SFM(playerid, HEX_FADE2, "Datebase interior virtualworld update query submitted. Resetting interior virtualworld to %d!", targetvw);

			IntInfo[i][intvw] = targetvw;

			new string[256];
			format(string, sizeof string, "[LOG]: %s %s has set entrance %d's inside virtualworld to %d.", AdminNames[adminlevel[playerid]], PlayerName(playerid), targetid, targetvw);
			SendAdminMessage(HEX_YELLOW, string, true);

			return 1;
		}
	}

	SCM(playerid, HEX_RED, "Error: Invalid entrance sqlid!");

	return 1;
}