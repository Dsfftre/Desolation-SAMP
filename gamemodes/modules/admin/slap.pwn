YCMD:slap(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;

	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /slap [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	new Float:tmpPos[3];
	GetPlayerPos(targetid, tmpPos[0], tmpPos[1], tmpPos[2]);
	SetPlayerPos(targetid, tmpPos[0], tmpPos[1], tmpPos[2]+4.0);
	PlayerPlaySound(targetid, 1136, 0.0, 0.0, 0.0);

	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has slapped %s.", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid));
	SendAdminMessage(HEX_YELLOW, string, true);

	SCM(targetid, HEX_YELLOW, "An admin has slapped you.");

	return 1;
}