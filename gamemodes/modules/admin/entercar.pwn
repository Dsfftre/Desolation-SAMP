YCMD:entercar(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new carid, seatid;
	if(Group_GetPlayer(g_Admin, playerid))
	{
		if(sscanf(params, "dd", carid, seatid)) return SCM(playerid, HEX_FADE2, "Usage: /entercar [vehicle id] [seat id] (0 Driver, 1 Front, 2 Back-left, 3 Back-right, 4+ for planes etc.)");
		if(!IsValidVehicle(carid)) return SCM(playerid, HEX_RED, "Error: Invalid vehicle.");
		if(seatid < 0 || seatid > 3) return SCM(playerid, HEX_RED, "Error: Invalid seat. (0 Driver, 1 Front, 2 Back-left, 3 Back-right)");

		foreach(new i : Player) {
			if(IsPlayerInVehicle(i, carid) && GetPlayerVehicleSeat(i) == seatid)
				return SCM(playerid, HEX_RED, "Error: That seat is already taken."); 
		}

		SetPlayerVirtualWorld(playerid, GetVehicleVirtualWorld(carid));
		PutPlayerInVehicle(playerid, carid, seatid);
	}
	return 1;
}