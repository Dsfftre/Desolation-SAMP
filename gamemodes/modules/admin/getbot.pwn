YCMD:getbot(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;

	if(sscanf(params, "q", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /getbot [npc]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid npc id. (Using an id, not name might work.)");
	}

	SetPlayerInterior(targetid, GetPlayerInterior(playerid));
	SetPlayerVirtualWorld(targetid, GetPlayerVirtualWorld(playerid));

	new string[256];
	if(adminlevel[playerid] == -1)
		format(string, sizeof string, "[Hidden Admin] %s has summoned %s[%i].", PlayerName(playerid), PlayerName(targetid), targetid);
	else
		format(string, sizeof string, "%s %s has summoned %s[%i].", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid);
	SendAdminMessage(HEX_YELLOW, string, true);


	new Float:Pos[3];
	GetPlayerPos(playerid, Pos[0],Pos[1],Pos[2]);

	switch(random(6)) 
	{
		case 0: FCNPC_SetPosition(targetid, Pos[0]+1, Pos[1], Pos[2]);
		case 1: FCNPC_SetPosition(targetid, Pos[0]+1, Pos[1]+1, Pos[2]);
		case 2: FCNPC_SetPosition(targetid, Pos[0]-1, Pos[1], Pos[2]);
		case 3: FCNPC_SetPosition(targetid, Pos[0]-1, Pos[1]-1, Pos[2]);
		case 4: FCNPC_SetPosition(targetid, Pos[0]-1, Pos[1]+1, Pos[2]);
		case 5: FCNPC_SetPosition(targetid, Pos[0]+1, Pos[1]-1, Pos[2]);
	}

	return 1;
}