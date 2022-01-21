/*#if defined _inc_vehicles
	#undef _inc_vehicles
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>
new Text:Coche[MAX_PLAYERS];
new Engine[MAX_VEHICLES];
new Fuel[MAX_VEHICLES];



hook OnGameModeInit() {
	ManualVehicleEngineAndLights();
	SpawnVehicles();

    for(new i; i<MAX_PLAYERS; i++)
    {
        Coche[i] = TextDrawCreate(492.000000,120.000000,"Engine");
		TextDrawUseBox(Coche[i], 1);
		TextDrawBoxColor(Coche[i], 0x00000000);
		TextDrawTextSize(Coche[i], 633.000000, 5.000000);
		TextDrawAlignment(Coche[i], 0);
		//TextDrawBackgroundColor(Coche[i], 0x00000000);
		TextDrawFont(Coche[i], 1);
		TextDrawLetterSize(Coche[i], 0.499999, 1.300000);
		TextDrawColor(Coche[i], 0xffffffff);
		TextDrawSetProportional(Coche[i], 1);
		TextDrawSetShadow(Coche[i], 1);
		TextDrawSetOutline(Coche[i], 1);

    }
    for(new c = 0; c<MAX_VEHICLES; c++)
	{
		Fuel[c] = 60+random(40);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}
/*hook OnVehicleDeath(vehicleid, killerid) {
	//SetVehicleToRespawn(vehicleid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}*/

hook OnVehicleSpawn(vehicleid) {
	new vehicle = FindVehicle(vehicleid);
	if(vehicle == INVALID_VEHICLE_ID) return Y_HOOKS_CONTINUE_RETURN_1;
	SetVehicleHealth(vehicleid,  VehicleInfo[vehicle][vhealth]);
	VehicleInfo[vehicle][engine] = 0;
	SetVehicleParamsEx(VehicleInfo[vehicle][vid], 0, 0, 0, VehicleInfo[vehicle][locked], 0, 0, 0);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate) {
	if(newstate == PLAYER_STATE_DRIVER) 
	{
		if(IsZombie(playerid))
		{
			RemovePlayerFromVehicle(playerid);
			return Y_HOOKS_CONTINUE_RETURN_1;
		}
		if(Bit_Get(tutorial, playerid))
		{
			SCM(playerid, HEX_FADE2, "Hint: Press Y or type /engine to start vehicles. You can turn on the lights if you press 2 (or +) by default.");
		}
		new vehicle = FindPlayerVehicle(playerid);
		//if(vehicle != INVALID_VEHICLE_ID) return Y_HOOKS_CONTINUE_RETURN_1;//Swap this with the line below in a live mode ((DEBUG))
		if(vehicle == INVALID_VEHICLE_ID && !Group_GetPlayer(g_AdminDuty, playerid)) {
			RemovePlayerFromVehicle(playerid);
			SCM(playerid, HEX_FADE2, "This vehicle is currently disabled.");
			return Y_HOOKS_CONTINUE_RETURN_1;
		}
		if(IsArmedVehicle(VehicleInfo[vehicle][vid]) && VehicleInfo[vehicle][locked]) 
		{
			//printf("DEBUG vehicle %d, locked %d, vid %d", vehicle, VehicleInfo[vehicle][locked], VehicleInfo[vehicle][vid]);
			RemovePlayerFromVehicle(playerid);
			new sendText[256];
			format(sendText, sizeof sendText, "AdmWarn: %s[%d] has entered a locked armed vehicle[%d]. (Script calls RemovePlayerFromVehicle now.)", PlayerName(playerid), playerid, VehicleInfo[vehicle][vid]);
			SendAdminMessage(HEX_LRED, sendText, true);
			print(sendText);
			return Y_HOOKS_CONTINUE_RETURN_1;
		}
		if(IsAnAirVehicle(GetPlayerVehicleID(playerid)))
		{
			if(Pilot[playerid] == 0)
			{
				SCM(playerid, HEX_FADE2, "[Desolation] You don't know how to fly aircraft!");
				RemovePlayerFromVehicle(playerid);
				return Y_HOOKS_CONTINUE_RETURN_1;
			}
		}
		if(Bit_Get(togshud, playerid))
			TextDrawShowForPlayer(playerid, Coche[playerid]);
	}
	
	if(newstate == PLAYER_STATE_ONFOOT)
	{
		TextDrawHideForPlayer(playerid, Coche[playerid]);
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}

/*YCMD:fuel(playerid, params[], help) {
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new vehicle = GetPlayerVehicleID(playerid);
		if(Fuel[vehicle] < 100)
		{
			if(IsPlayerInRangeOfPoint(playerid,15.0, 655.7314, -564.7745, 16.3359))
			{
				Fuel[vehicle] = 100;
				SCM(playerid, HEX_FADE2, "[Desolation] You refilled your vehicle!");//
			}
			else return SCM(playerid, HEX_RED, "You must be at an operating gas station.");
		}
		else return SCM(playerid, HEX_RED, "This vehicle's tank is full.");

	}
	return 1;
}*/


YCMD:createcar(playerid, params[], help) {
	if(adminlevel[playerid] < 5) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new vmodel,
		color[2];
	if(sscanf(params,"k<vehicle>dd", vmodel, color[0], color[1])) return SCM(playerid, HEX_FADE2, "Usage: /createcar [model] [color] [color](Note these vehicles are public by default.)");
	if(vmodel < 400 || vmodel > 611) return SCM(playerid, HEX_RED, "Error: Valid vehicle IDs range from 400 to 611.");
	new Float:ppos[4];
	GetPlayerPos(playerid, ppos[0], ppos[1], ppos[2]);
	GetPlayerFacingAngle(playerid, ppos[3]);
	new carid = CreateVehicle(vmodel, ppos[0], ppos[1], ppos[2], ppos[3]+1.0, color[0], color[1], -1, 0);
	PutPlayerInVehicle(playerid, carid, 0);
	return 1;
}

YCMD:savecar(playerid, params[], help) {
	if(adminlevel[playerid] < 5) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You need to be in a vehicle to add it to the sql table.");
	new vmodel = GetVehicleModel(GetPlayerVehicleID(playerid));
	new Float:ppos[4];
	GetVehiclePos(GetPlayerVehicleID(playerid), ppos[0], ppos[1], ppos[2]);
	GetVehicleZAngle(GetPlayerVehicleID(playerid), ppos[3]);
	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `vehicle` (`model`, `posx`, `posy`, `posz`, `posf`) VALUES ('%d', '%f', '%f', '%f', '%f')", vmodel, ppos[0], ppos[1], ppos[2], ppos[3]);
	mysql_tquery(g_SQL, sql, "", "");
	return 1;
}

SpawnVehicles() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `vehicle` WHERE state > 0 LIMIT %d", MAX_VEHICLES);
	inline LoadVehicleData() {
		if(!cache_num_rows()) {
			print("Error: Vehicles table is empty.");
			@return 1;
		}
		new i = -1;
		new v_engine, lights, alarm, doors, bonnet, boot, objective;
		for(;++i<cache_num_rows();) 
		{
			cache_get_value_int(i, "id", VehicleInfo[i][sqlid]);
			cache_get_value_float(i, "posx", VehicleInfo[i][vpos][0]);
			cache_get_value_float(i, "posy", VehicleInfo[i][vpos][1]);
			cache_get_value_float(i, "posz", VehicleInfo[i][vpos][2]);
			cache_get_value_float(i, "posf", VehicleInfo[i][vpos][3]);
			cache_get_value_int(i, "model", VehicleInfo[i][model]);
			cache_get_value_float(i, "vhealth", VehicleInfo[i][vhealth]);
			cache_get_value_int(i, "access", VehicleInfo[i][access]);
			cache_get_value_int(i, "locked", VehicleInfo[i][locked]);
			cache_get_value_int(i, "factionId", VehicleInfo[i][factionId]);
			cache_get_value_int(i, "playerId", VehicleInfo[i][playersId]);
			cache_get_value_int(i, "color1", VehicleInfo[i][vcolor][0]);
			cache_get_value_int(i, "color2", VehicleInfo[i][vcolor][1]);
			cache_get_value_int(i, "interior", VehicleInfo[i][interior]);
			cache_get_value_int(i, "virtualworld", VehicleInfo[i][v_virtualworld]);
			cache_get_value_int(i, "siren", VehicleInfo[i][siren]);
			cache_get_value(i, "plates", VehicleInfo[i][plates], 32);
			VehicleInfo[i][vid] = CreateVehicle(VehicleInfo[i][model], VehicleInfo[i][vpos][0], VehicleInfo[i][vpos][1], VehicleInfo[i][vpos][2], VehicleInfo[i][vpos][3], VehicleInfo[i][vcolor][0], VehicleInfo[i][vcolor][1], 3600, VehicleInfo[i][siren]);
			GetVehicleParamsEx(VehicleInfo[i][vid], v_engine, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(VehicleInfo[i][vid], v_engine, lights, alarm, VehicleInfo[i][locked], bonnet, boot, objective);
			SetVehicleHealth(VehicleInfo[i][vid], VehicleInfo[i][vhealth]);
			SetVehicleNumberPlate(VehicleInfo[i][vid], VehicleInfo[i][plates]);
			Iter_Add(Cars, VehicleInfo[i][vid]);
		}
		printf("%d vehicles have been created.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadVehicleData, sql);
	return 1;
}
YCMD:engine(playerid, params[], help) {
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");
	if(Group_GetPlayer(g_AdminDuty, playerid) && IsPlayerInAnyVehicle(playerid)) 
	{
		new v_engine, lights, alarm, doors, bonnet, boot, objective;
		GetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, lights, alarm, doors, bonnet, boot, objective);
		if(v_engine == 1) 
		{
			SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, lights, alarm, doors, bonnet, boot, objective);
		}
		else 
		{
			SetVehicleParamsEx(GetPlayerVehicleID(playerid), 1, lights, alarm, doors, bonnet, boot, objective);
		}
		return 1;
	}

	if(GetPlayerVehicleSeat(playerid) != 0) return SCM(playerid, HEX_RED, "Error: You need to be in the driver's seat.");
	new vehicle = FindPlayerVehicle(playerid);
	if(vehicle == INVALID_VEHICLE_ID) return SCM(playerid, HEX_FADE2, "This vehicle is currently disabled.");
	if(!IsVehicleAccess(playerid, vehicle)) return SCM(playerid, HEX_FADE2, "You don't have access to this vehicle.");

	new v_engine, lights, alarm, doors, bonnet, boot, objective;
	GetVehicleParamsEx(VehicleInfo[vehicle][vid], v_engine, lights, alarm, doors, bonnet, boot, objective);
	new string[128];
	new coche = GetPlayerVehicleID(playerid);
	if(v_engine == 1) 
	{
		VehicleInfo[vehicle][engine] = 0;
		SetVehicleParamsEx(VehicleInfo[vehicle][vid], 0, lights, alarm, doors, bonnet, boot, objective);
		format(string, sizeof string, "%s turns off the engine.");
		PlayerAction(playerid, string);
		Engine[coche] = 0;
	}
	else 
	{
		VehicleInfo[vehicle][engine] = 1;
		SetVehicleParamsEx(VehicleInfo[vehicle][vid], 1, lights, alarm, doors, bonnet, boot, objective);
		format(string, sizeof string, "%s turns on the engine.");
		PlayerAction(playerid, string);
		Engine[coche] = 1;
	}
	return 1;
}

FindPlayerVehicle(playerid) {
	if(!IsPlayerInAnyVehicle(playerid)) return INVALID_VEHICLE_ID;
	new check = GetPlayerVehicleID(playerid);
	new i = -1;
	for(;++i<MAX_VEHICLES;) 
	{
		if(check == VehicleInfo[i][vid])
			return i;
	}
	return INVALID_VEHICLE_ID;
}

FindVehicle(vehicleid) {
	if(!IsValidVehicle(vehicleid)) return INVALID_VEHICLE_ID;
	new i = -1;
	for(;++i<MAX_VEHICLES;) {
		if(vehicleid == VehicleInfo[i][vid])
			return i;
	}
	return INVALID_VEHICLE_ID;
}

IsVehicleAccess(playerid, vehicle) {
	if(Group_GetPlayer(g_AdminDuty, playerid)) return 1;
	if(VehicleInfo[vehicle][access] == 0) return 1;
	if(VehicleInfo[vehicle][access] == GetPVarInt(playerid, "accesskey")) return 1;
	if(faction[playerid] == VehicleInfo[vehicle][factionId] && VehicleInfo[vehicle][factionId] > 0) return 1;
	if(CharacterSQL[playerid] == VehicleInfo[vehicle][playersId]) return 1;
	//if(VehicleInfo[vehicle][playersId] == 0 && VehicleInfo[vehicle][factionId] == 0) return 1;
	return 0;
}

IsArmedVehicle(vehicleid) {
	switch(GetVehicleModel(vehicleid)) {
		case 425: return 1;
		case 432: return 1;
		case 447: return 1;
		case 464: return 1;
		case 476: return 1;
		case 520: return 1;
	}
	return 0;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(newkeys & KEY_SUBMISSION) 
	{
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) 
		{
			new v_engine, lights, alarm, doors, bonnet, boot, objective;
			GetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, lights, alarm, doors, bonnet, boot, objective);
			if(lights == 1) 
			{
				SetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, 0, alarm, doors, bonnet, boot, objective);
			}
			else 
			{
				SetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, 1, alarm, doors, bonnet, boot, objective);
			}
		}
	}
	else if(newkeys & KEY_YES && IsPlayerInAnyVehicle(playerid)) 
	{
		if(Group_GetPlayer(g_AdminDuty, playerid)) 
		{
			new v_engine, lights, alarm, doors, bonnet, boot, objective;
			GetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, lights, alarm, doors, bonnet, boot, objective);
			if(v_engine == 1) 
			{
				SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, lights, alarm, doors, bonnet, boot, objective);
			}
			else 
			{
				SetVehicleParamsEx(GetPlayerVehicleID(playerid), 1, lights, alarm, doors, bonnet, boot, objective);
			}
			return Y_HOOKS_CONTINUE_RETURN_1;
		}
		if(!IsHuman(playerid)) { SCM(playerid, HEX_RED, "Error: Zombies cannot do that."); return Y_HOOKS_CONTINUE_RETURN_1; }
		if(GetPlayerVehicleSeat(playerid) != 0) { SCM(playerid, HEX_FADE2, "You need to be in the driver's seat."); return Y_HOOKS_CONTINUE_RETURN_1; }
		new vehicle = FindPlayerVehicle(playerid);
		if(vehicle == INVALID_VEHICLE_ID) { SCM(playerid, HEX_FADE2, "This vehicle is currently disabled."); return Y_HOOKS_CONTINUE_RETURN_1; }
		if(!IsVehicleAccess(playerid, vehicle)) { SCM(playerid, HEX_FADE2, "You don't have access to this vehicle."); return Y_HOOKS_CONTINUE_RETURN_1; }

		new v_engine, lights, alarm, doors, bonnet, boot, objective;
		GetVehicleParamsEx(VehicleInfo[vehicle][vid], v_engine, lights, alarm, doors, bonnet, boot, objective);
		new string[258];
		new coche = GetPlayerVehicleID(playerid);
		if(v_engine == 1) 
		{
			VehicleInfo[vehicle][engine] = 0;
			SetVehicleParamsEx(VehicleInfo[vehicle][vid], 0, lights, alarm, doors, bonnet, boot, objective);
			format(string, sizeof string, "turns off the engine.");
			PlayerAction(playerid, string);
			Engine[coche] = 0;
		}
		else if(Fuel[coche] == 0)
		{
			format(string, sizeof string, "%s turns the vehicle key around but the car doesnt respond");
			PlayerAction(playerid, string);
		}
		else
		{
			VehicleInfo[vehicle][engine] = 1;
			SetVehicleParamsEx(VehicleInfo[vehicle][vid], 1, lights, alarm, doors, bonnet, boot, objective);
			format(string, sizeof string, "turns on the engine.");
			PlayerAction(playerid, string);
			Engine[coche] = 1;
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

stock IsAnAirVehicle(vehicleid)
{
    new airmodel = GetVehicleModel(vehicleid);
    switch(airmodel)
    {
        case 592: return 1;
        case 577: return 1;
        case 511: return 1;
        case 512: return 1;
        case 593: return 1;
        case 520: return 1;
        case 553: return 1;
        case 476: return 1;
        case 519: return 1;
        case 460: return 1;
        case 513: return 1;
        case 548: return 1;
        case 425: return 1;
        case 417: return 1;
        case 487: return 1;
        case 488: return 1;
        case 497: return 1;
        case 563: return 1;
        case 447: return 1;
        case 469: return 1;
    }
    return 0;
}
ptask FuelLoss[60000](playerid)
{
	if(IsPlayerNPC(playerid)) return 0;
	new coche = GetPlayerVehicleID(playerid);
	if(coche == INVALID_VEHICLE_ID) return 0;
	new v_engine, lights, alarm, doors, bonnet, boot, objective;
	GetVehicleParamsEx(coche, v_engine, lights, alarm, doors, bonnet, boot, objective);
	if(v_engine != 1) return 0;

    new amount = random(3);
	
    if(coche != 0 && Engine[coche] == 1 && Fuel[coche] > 0) 
	{
		Fuel[coche] = (amount > Fuel[coche]) ? 0 : Fuel[coche] - amount;
    }
	else if(Fuel[coche] == 0) //need to find a new way to add this as once it hits 0 it will count to 60 again and then turn the engine off.
	{
		if(Engine[coche] == 1)
		{
			new string[256];
			format(string, sizeof string, "%s engine sputters out and dies");
	        PlayerAction(playerid, string);
	        SetVehicleParamsEx(coche, 0, 0, 0, 0, 0, 0, 0);
	        Engine[coche] = 0;
		}
	}
	return 1;
}

ptask VehicleTextdraw[1000](playerid)
{
	if(IsPlayerInAnyVehicle(playerid) && !IsPlayerNPC(playerid))
	{
		if(Bit_Get(togshud, playerid))
		{
			new coche = GetPlayerVehicleID(playerid);
			new string[256];
			if(Engine[coche] == 0)
			{
				format(string, sizeof(string), "~r~Engine off.~n~~y~Fuel:~w~%d.", Fuel[coche]);
				TextDrawSetString(Coche[playerid], string);
			}
			else if(Engine[coche] == 1)
			{
				format(string, sizeof(string), "~g~Engine on.~n~~y~Fuel:~w~%d.", Fuel[coche]);
				TextDrawSetString(Coche[playerid], string);
			}
			TextDrawShowForPlayer(playerid, Coche[playerid]);
		}
		else
		{
			TextDrawHideForPlayer(playerid, Coche[playerid]);
		}
	}
}


/*task VehicleTextdraw[1000]()
{
	foreach(new i:Player)
	{
		if(IsPlayerNPC(i)) return 0;
		if(IsPlayerInAnyVehicle(i))
		{
		    new coche = GetPlayerVehicleID(i);
		    new string[256];
		    if(Engine[coche] == 0)
		    {
				format(string, sizeof(string), "~r~Engine off.\n\n~y~Fuel:~w~%d.", Fuel[coche]);
				TextDrawSetString(Coche[i], string);
			}
			else if(Engine[coche] == 1)
			{
				format(string, sizeof(string), "~g~Engine on.\n\n~y~Fuel:~w~%d.", Fuel[coche]);
				TextDrawSetString(Coche[i], string);
			}
			TextDrawShowForPlayer(i, Coche[i]);
		}
	}
	return 1;
}*/

YCMD:trunk(playerid, params[], help) {
	new v_engine, lights, alarm, doors, bonnet, boot, objective;
	if(IsPlayerInAnyVehicle(playerid)) {
		if(GetPlayerVehicleSeat(playerid) != 0) return SCM(playerid, HEX_RED, "Error: You must be sitting in the drivers seat.");

		GetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, lights, alarm, doors, bonnet, boot, objective);
		if(boot == 1) boot = 0;
		else boot = 1;
		SetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, lights, alarm, doors, bonnet, boot, objective);
		

	}
	else {
		new Float:c_vpos[3];
		new i = -1;
		for(;++i<MAX_VEHICLES;) {
			if(!IsValidVehicle(i)) continue;
			GetVehiclePos(i, c_vpos[0], c_vpos[1], c_vpos[2]);
			if(IsPlayerInRangeOfPoint(playerid, CHECK_RANGE*3, c_vpos[0], c_vpos[1], c_vpos[2])) {
				GetVehicleParamsEx(i, v_engine, lights, alarm, doors, bonnet, boot, objective);
				if(boot == 1) boot = 0;
				else boot = 1;
				SetVehicleParamsEx(i, v_engine, lights, alarm, doors, bonnet, boot, objective);
				return 1;
			}

		}

	}
	SCM(playerid, HEX_RED, "Error: No vehicle found in range.");
	return 1;
}

YCMD:hood(playerid, params[], help) {
	new v_engine, lights, alarm, doors, bonnet, boot, objective;
	if(IsPlayerInAnyVehicle(playerid)) {
		if(GetPlayerVehicleSeat(playerid) != 0) return SCM(playerid, HEX_RED, "Error: You must be sitting in the drivers seat.");

		GetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, lights, alarm, doors, bonnet, boot, objective);
		if(bonnet == 1) bonnet = 0;
		else bonnet = 1;
		SetVehicleParamsEx(GetPlayerVehicleID(playerid), v_engine, lights, alarm, doors, bonnet, boot, objective);
		

	}
	else {
		new Float:c_vpos[3];
		new i = -1;
		for(;++i<MAX_VEHICLES;) {
			if(!IsValidVehicle(i)) continue;
			GetVehiclePos(i, c_vpos[0], c_vpos[1], c_vpos[2]);
			if(IsPlayerInRangeOfPoint(playerid, CHECK_RANGE*3, c_vpos[0], c_vpos[1], c_vpos[2])) {
				GetVehicleParamsEx(i, v_engine, lights, alarm, doors, bonnet, boot, objective);
				if(bonnet == 1) bonnet = 0;
				else bonnet = 1;
				SetVehicleParamsEx(i, v_engine, lights, alarm, doors, bonnet, boot, objective);
				return 1;
			}

		}

	}
	SCM(playerid, HEX_RED, "Error: No vehicle found in range.");
	return 1;
}

IsVehicleOccupied(carid) {

	foreach(new i:Player) {

		if(GetPlayerVehicleID(i) == carid)
			return true;

	}

	return false;
}

