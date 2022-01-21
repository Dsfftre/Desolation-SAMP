YCMD:getcar(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;

	if(sscanf(params, "d", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /getcar [vehicle id]");
	if(!IsValidVehicle(targetid)) return SCM(playerid, HEX_RED, "Error: Invalid vehicle.");
	new Float:tmpPos[3];
	GetPlayerPos(playerid, tmpPos[0], tmpPos[1], tmpPos[2]);
	SetVehiclePos(targetid, tmpPos[0]+RandomFloat(8.0)-4.0, tmpPos[1]+RandomFloat(8.0)-4.0, tmpPos[2]);

	return 1;
}