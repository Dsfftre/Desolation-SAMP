YCMD:gotocar(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;

	if(sscanf(params, "d", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /gotocar [vehicle id]");
	if(!IsValidVehicle(targetid)) return SCM(playerid, HEX_RED, "Error: Invalid vehicle.");

	new Float:tmpPos[3];
	GetVehiclePos(targetid, tmpPos[0], tmpPos[1], tmpPos[2]);
	SetPlayerPos(playerid, tmpPos[0]+RandomFloat(10.0)-5.0, tmpPos[1]+RandomFloat(10.0)-5.0, tmpPos[2]);

	return 1;
}