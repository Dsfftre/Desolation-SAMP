YCMD:gotosafe(playerid, params[], help) {
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;

	if(sscanf(params, "d", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /gotosafe [safe sqlid]");

	foreach(new i:Storages) {
		if(storageInfo[i][safe_sqlid] == targetid) {
			SetPlayerPos(playerid, storageInfo[i][safe_pos][0], storageInfo[i][safe_pos][1], storageInfo[i][safe_pos][2]);
			SetPlayerInterior(playerid, storageInfo[i][safe_interior]);
			SetPlayerVirtualWorld(playerid, storageInfo[i][safe_virtualworld]);
			SFM(playerid, HEX_FADE2, "You have teleported to safe ID %d. Owner: %s", storageInfo[i][safe_sqlid], GetSQLCharname(storageInfo[i][safe_playerid]));
			return 1;
		}
	}
	SCM(playerid, HEX_RED, "Error: Invalid (non-existent) storage sql id.");
	return 1;
}