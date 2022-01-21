YCMD:saveintout(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid;
	if(sscanf(params, "i",targetid)) return SCM(playerid, HEX_FADE2, "Usage: /saveintout [sqlid] (Saves the entrance's outside points to your current location, including coordinates and interior id. Virtualworld is untouched!)");
	
	new Float:intint_ppos[4];
	GetPlayerPos(playerid, intint_ppos[0], intint_ppos[1], intint_ppos[2]);
	GetPlayerFacingAngle(playerid, intint_ppos[3]);

	foreach(new i:Entrances) {
		if(IntInfo[i][sqlid] == targetid) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `outx` = '%f', `outy` = '%f', `outz` = '%f', `outf` = '%f', `outint` = '%d' WHERE id = '%d' LIMIT 1", intint_ppos[0], intint_ppos[1], intint_ppos[2], intint_ppos[3],  GetPlayerInterior(playerid), targetid);
			mysql_tquery(g_SQL, sql, "", "");

			IntInfo[i][outx] = intint_ppos[0];
			IntInfo[i][outy] = intint_ppos[1];
			IntInfo[i][outz] = intint_ppos[2];
			IntInfo[i][outf] = intint_ppos[3];
			IntInfo[i][outint] = GetPlayerInterior(playerid);

			if(IsValidDynamicCP(IntInfo[i][checkpoint_out]))
				DestroyDynamicCP(IntInfo[i][checkpoint_out]);
			else if(IsValidDynamicPickup(IntInfo[i][pickup_out]))
				DestroyDynamicPickup(IntInfo[i][pickup_out]);

			if(IntInfo[i][storeId] == 0)
				IntInfo[i][checkpoint_out] = CreateDynamicCP(IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], CHECKPOINT_SIZE, IntInfo[i][outvw], IntInfo[i][outint], -1, CHECKPOINT_RANGE);
			else if(IntInfo[i][storeId] == -1)
				IntInfo[i][pickup_out] = CreateDynamicPickup(LOOTSTORE_PICKUP, 2, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], IntInfo[i][outvw], IntInfo[i][outint], -1);
			else
				IntInfo[i][pickup_out] = CreateDynamicPickup(STORE_PICKUP, 2, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], IntInfo[i][outvw], IntInfo[i][outint], -1);

			new string[256];
			format(string, sizeof string, "[LOG]: %s %s has changed entrance %d's outside position.", AdminNames[adminlevel[playerid]], PlayerName(playerid), targetid);
			SendAdminMessage(HEX_YELLOW, string, true);

			return 1;
		}

	}

	SCM(playerid, HEX_RED, "Error: Invalid entrance sqlid!");

	return 1;
}