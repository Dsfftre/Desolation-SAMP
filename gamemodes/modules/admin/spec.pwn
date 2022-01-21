YCMD:spec(playerid, params[], help) {
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid=INVALID_PLAYER_ID;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /spec [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	Bit_Let(spectating, playerid);

	TogglePlayerSpectating(playerid, true);
	SetPlayerInterior(playerid, GetPlayerInterior(targetid));
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(targetid));

	if(IsPlayerInAnyVehicle(targetid))
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(targetid), SPECTATE_MODE_NORMAL);
	else
		PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE_NORMAL);

	SetPVarInt(playerid, "spect", targetid);
	defer FixSpectatorsAgain(targetid);

	if(adminlevel[targetid] > 4) SFM(targetid, HEX_YELLOW, "[NOTE]: %s %s has started spectating you.", AdminNames[adminlevel[playerid]], PlayerName(playerid));



	return 1;
}

YCMD:specoff(playerid, params[], help) {
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	if(!Bit_Get(spectating, playerid)) return SCM(playerid, HEX_RED, "Error: You are not in spectator mode.");

	RandomHumanSpawn(playerid);
	TogglePlayerSpectating(playerid, false);
	Bit_Vet(spectating, playerid);
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);

	SetPVarInt(playerid, "spect", -1);

	if(Group_GetPlayer(g_AdminDuty, playerid))
        SetPlayerColor(playerid, COLOR_ADMIN);

	defer AdmindutyColor(playerid);

	return 1;
}

timer AdmindutyColor[1000](playerid) {
	if(Group_GetPlayer(g_AdminDuty, playerid))
        SetPlayerColor(playerid, COLOR_ADMIN);	
}

FixSpectators(playerid) {
	foreach(new i:Player) {
		if(GetPVarInt(i, "spect") == playerid) {
			SetPlayerInterior(i, GetPlayerInterior(playerid));
			SetPlayerVirtualWorld(i, GetPlayerVirtualWorld(playerid));
			if(IsPlayerInAnyVehicle(playerid))
				PlayerSpectateVehicle(i, GetPlayerVehicleID(playerid), SPECTATE_MODE_NORMAL);
			else
				PlayerSpectatePlayer(i, playerid, SPECTATE_MODE_NORMAL);
			SetPlayerInterior(i, GetPlayerInterior(playerid));
			SetPlayerVirtualWorld(i, GetPlayerVirtualWorld(playerid));			
		}
	}

	defer FixSpectatorsAgain(playerid);

	return 1;
}

timer FixSpectatorsAgain[1000](playerid) {

	foreach(new i:Player) {
		if(GetPVarInt(i, "spect") == playerid) {
			SetPlayerInterior(i, GetPlayerInterior(playerid));
			SetPlayerVirtualWorld(i, GetPlayerVirtualWorld(playerid));
			if(IsPlayerInAnyVehicle(playerid))
				PlayerSpectateVehicle(i, GetPlayerVehicleID(playerid), SPECTATE_MODE_NORMAL);
			else
				PlayerSpectatePlayer(i, playerid, SPECTATE_MODE_NORMAL);
			SetPlayerInterior(i, GetPlayerInterior(playerid));
			SetPlayerVirtualWorld(i, GetPlayerVirtualWorld(playerid));			
		}
	}

	defer FixSpectatorsAgain(playerid);

}