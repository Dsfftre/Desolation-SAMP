YCMD:fixcar(playerid, params[], help) {
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid;

	if(sscanf(params, "d", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /fixcar [vehicle id]");
	if(!IsValidVehicle(targetid)) return SCM(playerid, HEX_RED, "Error: Invalid vehicle.");
	
	RepairVehicle(targetid);
	SetVehicleHealth(targetid, 1000.0);

	return 1;
}
