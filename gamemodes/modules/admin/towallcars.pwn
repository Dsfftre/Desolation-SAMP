YCMD:towallcars(playerid, params[], help)  {
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new i;
	foreach(i : Cars) {
		if(!IsValidVehicle(i)) continue;
		if(!IsVehicleOccupied(i)) {
			new j = FindVehicle(i);
			SetVehicleToRespawn(i);
			RepairVehicle(i);
			SetVehicleHealth(i, VehicleInfo[j][vhealth]);
		}
	}

	new string[256];
	format(string, sizeof string, "[LOG]: %s[%d] has towed all unoccupied vehicles.", PlayerName(playerid), playerid);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}