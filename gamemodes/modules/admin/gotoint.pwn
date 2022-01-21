YCMD:gotoint(playerid, params[], help) {
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;

	if(sscanf(params, "d", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /gotoint [entrance id]");

	foreach(new i:Entrances) {
		if(IntInfo[i][sqlid] == targetid) {
			SetPlayerPos(playerid, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz]);
			SetPlayerFacingAngle(playerid, IntInfo[i][outf]);
			SetPlayerInterior(playerid, IntInfo[i][outint]);
			SetPlayerVirtualWorld(playerid, IntInfo[i][outvw]);
			return 1;
		}
	}
	SCM(playerid, HEX_RED, "Error: Invalid (non-existent) interior sql id.");
	return 1;
}