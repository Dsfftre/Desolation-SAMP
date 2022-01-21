YCMD:saveintint(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid;
	if(sscanf(params, "i",targetid)) return SCM(playerid, HEX_FADE2, "Usage: /saveintint [sqlid] (Saves the entrance's inside points to your current location, including coordinates and interior id. Virtualworld is untouched!)");
	
	new Float:intint_ppos[4];
	GetPlayerPos(playerid, intint_ppos[0], intint_ppos[1], intint_ppos[2]);
	GetPlayerFacingAngle(playerid, intint_ppos[3]);

	

	foreach(new i:Entrances) {
		if(IntInfo[i][sqlid] == targetid) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `intx` = '%f', `inty` = '%f', `intz` = '%f', `intf` = '%f', `intint` = '%d' WHERE id = '%d' LIMIT 1", intint_ppos[0], intint_ppos[1], intint_ppos[2], intint_ppos[3],  GetPlayerInterior(playerid), targetid);
			mysql_tquery(g_SQL, sql, "", "");

			IntInfo[i][intx] = intint_ppos[0];
			IntInfo[i][inty] = intint_ppos[1];
			IntInfo[i][intz] = intint_ppos[2];
			IntInfo[i][intf] = intint_ppos[3];
			IntInfo[i][intint] = GetPlayerInterior(playerid);

			new string[256];
			format(string, sizeof string, "[LOG]: %s %s has changed entrance %d's inside position.", AdminNames[adminlevel[playerid]], PlayerName(playerid), targetid);
			SendAdminMessage(HEX_YELLOW, string, true);

			return 1;
		}

	}

	SCM(playerid, HEX_RED, "Error: Invalid entrance sqlid!");

	return 1;
}