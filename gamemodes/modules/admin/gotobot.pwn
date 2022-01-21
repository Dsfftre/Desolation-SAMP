YCMD:gotobot(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;

	if(sscanf(params, "q", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /gotobot [npc]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid npc id. (Using an id, not name might work.)");
	}

	SetPlayerInterior(playerid, GetPlayerInterior(targetid));
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(targetid));

	new string[256];
	if(adminlevel[playerid] == -1)
		format(string, sizeof string, "[Hidden Admin] %s has teleported to %s[%i].", PlayerName(playerid), PlayerName(targetid), targetid);
	else
		format(string, sizeof string, "%s %s has teleported to %s[%i].", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid);
	SendAdminMessage(HEX_YELLOW, string, true);

	ChangeMaskVW(playerid);

	new Float:Pos[3];
	FCNPC_GetPosition(targetid, Pos[0],Pos[1],Pos[2]);

	if(GetPlayerDistanceFromPoint(playerid, Pos[0],Pos[1],Pos[2]) > 1.2)
		switch(random(6)) 
		{
			case 0: SetPlayerPos(playerid, Pos[0]+1, Pos[1], Pos[2]);
			case 1: SetPlayerPos(playerid, Pos[0]+1, Pos[1]+1, Pos[2]);
			case 2: SetPlayerPos(playerid, Pos[0]-1, Pos[1], Pos[2]);
			case 3: SetPlayerPos(playerid, Pos[0]-1, Pos[1]-1, Pos[2]);
			case 4: SetPlayerPos(playerid, Pos[0]-1, Pos[1]+1, Pos[2]);
			case 5: SetPlayerPos(playerid, Pos[0]+1, Pos[1]-1, Pos[2]);
		}

	return 1;
}