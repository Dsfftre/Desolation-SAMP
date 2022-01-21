YCMD:gethere(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;
	if(Group_GetPlayer(g_Admin, playerid))
	{
		if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /gethere [id]");
		if(targetid == playerid) return SCM(playerid, HEX_RED, "Error: You cannot teleport to yourself.");
		if(targetid == INVALID_PLAYER_ID) {
			unformat(params, "i", targetid);
			if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}

		new kocsi = GetPlayerVehicleID(playerid), Float:Pos[3];
		GetPlayerPos(playerid, Pos[0],Pos[1],Pos[2]);
		if(kocsi) 
		{
			SetVehiclePos(kocsi, Pos[0],Pos[1],Pos[2]);
			SetVehicleVirtualWorld(kocsi, GetPlayerVirtualWorld(targetid));
			LinkVehicleToInterior(kocsi, GetPlayerInterior(targetid));
		}
		switch(random(6)) 
		{
			case 0: SetPlayerPos(targetid, Pos[0]+1, Pos[1], Pos[2]);
			case 1: SetPlayerPos(targetid, Pos[0]+1, Pos[1]+1, Pos[2]);
			case 2: SetPlayerPos(targetid, Pos[0]-1, Pos[1], Pos[2]);
			case 3: SetPlayerPos(targetid, Pos[0]-1, Pos[1]-1, Pos[2]);
			case 4: SetPlayerPos(targetid, Pos[0]-1, Pos[1]+1, Pos[2]);
			case 5: SetPlayerPos(targetid, Pos[0]+1, Pos[1]-1, Pos[2]);
		}	
		SetPlayerInterior(targetid, GetPlayerInterior(playerid));
		SetPlayerVirtualWorld(targetid, GetPlayerVirtualWorld(playerid));
		if(kocsi) PutPlayerInVehicle(targetid, kocsi, 1);

		ChangeMaskVW(targetid);
		FixSpectators(targetid);

		new string[256];
		format(string, sizeof string, "%s %s has summoned %s[%i].", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid);
		SendAdminMessage(HEX_YELLOW, string, true);
	}
	return 1;
}