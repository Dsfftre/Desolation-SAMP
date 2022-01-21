YCMD:givepackage(playerid, params[], help) {
	if(adminlevel[playerid] < 2 && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
    	
    new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "/givepackage [id]");
	if(targetid == INVALID_PLAYER_ID) 
	{
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}
    GivePlayerItem(targetid, 28, 1);
    GivePlayerItem(targetid, 43, 200);
    GivePlayerItem(targetid, 63, 1);
    GivePlayerItem(targetid, 48, 1);
    GivePlayerItem(targetid, 56, 1);
    GivePlayerItem(targetid, 57, 1);

    return 1;
}

