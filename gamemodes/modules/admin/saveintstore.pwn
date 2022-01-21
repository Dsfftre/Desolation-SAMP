YCMD:saveintstore(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid, targets;
	if(sscanf(params, "ii",targetid, targets)) return SCM(playerid, HEX_FADE2, "Usage: /saveintstore [sqlid] [storeId] (Changes pickup or checkpoint. 0: safehouse, -1: looting place, above 0: actual stores)");
	
	foreach(new i:Entrances) {
		if(IntInfo[i][sqlid] == targetid) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `storeId` = '%d' WHERE id = '%d' LIMIT 1", targets, targetid);
			mysql_tquery(g_SQL, sql, "", "");

			IntInfo[i][storeId] = targets;

			if(IsValidDynamicCP(IntInfo[i][checkpoint_out]))
				DestroyDynamicCP(IntInfo[i][checkpoint_out]);
			else if(IsValidDynamicPickup(IntInfo[i][pickup_out]))
				DestroyDynamicPickup(IntInfo[i][pickup_out]);

			IntInfo[i][checkpoint_out] = 0;
			IntInfo[i][pickup_out] = 0;


			if(IntInfo[i][storeId] == 0)
				IntInfo[i][checkpoint_out] = CreateDynamicCP(IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], CHECKPOINT_SIZE, IntInfo[i][outvw], IntInfo[i][outint], -1, CHECKPOINT_RANGE);
			else if(IntInfo[i][storeId] == -1)
				IntInfo[i][pickup_out] = CreateDynamicPickup(LOOTSTORE_PICKUP, 2, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], IntInfo[i][outvw], IntInfo[i][outint], -1);
			else
				IntInfo[i][pickup_out] = CreateDynamicPickup(STORE_PICKUP, 2, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], IntInfo[i][outvw], IntInfo[i][outint], -1);

			new string[256];
			format(string, sizeof string, "[LOG]: %s %s has set entrance %d's storeId to %d.", AdminNames[adminlevel[playerid]], PlayerName(playerid), targetid, targets);
			SendAdminMessage(HEX_YELLOW, string, true);

			return 1;
		}
	}

	SCM(playerid, HEX_RED, "Error: Invalid entrance sqlid!");

	return 1;
}