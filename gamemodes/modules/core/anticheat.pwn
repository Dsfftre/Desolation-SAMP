//ANTI SILENT AIMBOT: 0
//ANTI VEHICLE REPAIR HACK: 1
//ANTI SCREEN FLICKERING: 2
//ANTI CAR TROLLER: 3
//ANTI SURFING INVISIBLE: 4
//ANTI AIRBREAK: 5
//ANTI SEAT ID CRASHER: 6
//ANTI SPEED HACK (On Foot/Driver): 7
//ANTI TROLL ANIMATION: 8
//ANTI ANIMATION INVISIBLE: 9
//ANTI FLY HACK (On Foot): 10
//ANTI RAGE SHOT: 11
//ANTI TRAILER CRASHER: 12
//ANTI WEAPON HACK: 13

#include <YSI_Coding\y_hooks>

forward OnPlayerChangedToTrailer(playerid, vehicleid, trailerid);

new OldSpeed[MAX_PLAYERS];
new Float:LastPosition[MAX_PLAYERS][3];
new OldTrailer[MAX_PLAYERS];

public OnPlayerConnect(playerid)
{
    SetPVarInt(playerid, "LegalSpeed", 0);
	#if defined HAC_OnPlayerConnect
	    return HAC_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

public OnPlayerSpawn(playerid)
{
	SetTimerEx("AntiCheatControl", 200, true, "i", playerid);
	SetPVarInt(playerid, "CarID", -1);
	#if defined HAC_OnPlayerSpawn
	    return HAC_OnPlayerSpawn(playerid);
	#else
		return 1;
	#endif
}

forward AntiCheatControl(playerid);
public AntiCheatControl(playerid)
{
	OldSpeed[playerid] = PlayerSpeed(playerid);
	GetPlayerPos(playerid, LastPosition[playerid][0], LastPosition[playerid][1], LastPosition[playerid][2]);
	if (GetPlayerVehicleID(playerid) > -1 && GetVehicleTrailer(GetPlayerVehicleID(playerid)) > -1)
	{
	    OldTrailer[playerid] = GetVehicleTrailer(GetPlayerVehicleID(playerid));
	}
	else
	{
		OldTrailer[playerid] = -1;
	}
	return 1;
}

public OnPlayerChangedToTrailer(playerid, vehicleid, trailerid)
{
    if (OldTrailer[playerid] != -1 && OldTrailer[playerid] != trailerid)
    {
        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 12);
    }
	return 1;
}

public OnVehicleDamageStatusUpdate(vehicleid, playerid)
{
    SetPVarInt(playerid, "LegalSpeed", 1);
    SetTimerEx("ResetLegalSpeed", 500, false, "i", playerid);
    #if defined HAC_OnVehicleDamageStatusUpdate
	    return HAC_OnVehicleDamageStatusUpdate(vehicleid, playerid);
	#else
		return 1;
	#endif
}

forward ResetLegalSpeed(playerid);
public ResetLegalSpeed(playerid)
{
    SetPVarInt(playerid, "LegalSpeed", 0);
    return 1;
}

stock PlayerSpeed(playerid)
{
    new Float:ST[4];
    if(IsPlayerInAnyVehicle(playerid))
    GetVehicleVelocity(GetPlayerVehicleID(playerid),ST[0],ST[1],ST[2]);
    else GetPlayerVelocity(playerid,ST[0],ST[1],ST[2]);
    ST[3] = floatsqroot(floatpower(floatabs(ST[0]), 2.0) + floatpower(floatabs(ST[1]), 2.0) + floatpower(floatabs(ST[2]), 2.0)) * 179.28625;
    return floatround(ST[3]);
}

public OnVehicleSpawn(vehicleid) {
	new Float:vHatasd;
	GetVehicleHealth(vehicleid, vHatasd);
	if (vHatasd > 950)
	{
	    SetVehicleHealth(vehicleid, 950);
	}
	#if defined HAC_OnVehicleSpawn
	    return HAC_OnVehicleSpawn(vehicleid);
	#else
		return 1;
	#endif
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    new vehicleid = GetPlayerVehicleID(playerid);
    SetPVarInt(playerid, "CarID", vehicleid);
	SetPVarInt(playerid, "LegalSpeed", 1);
	SetTimerEx("ResetLegalSpeed", 500, true, "i", playerid);
	#if defined HAC_OnPlayerStateChange
	    return HAC_OnPlayerStateChange(playerid, newstate, oldstate);
	#else
		return 1;
	#endif
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
    new Float:vHealth;
	GetVehicleHealth(vehicleid, vHealth);
	if (vHealth > 950)
	{
		SetVehicleHealth(vehicleid, 950); 
	}
	#if defined HAC_OnVehicleMod
	    return HAC_OnVehicleMod(playerid, vehicleid, componentid);
	#else
		return 1;
	#endif
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
    new Float:vHealth;
	GetVehicleHealth(vehicleid, vHealth); 
	if (vHealth > 950) 
	{
		SetVehicleHealth(vehicleid, 950); 
	}
	#if defined HAC_OnVehiclePaintjob
	    return HAC_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
	#else
		return 1;
	#endif
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	new Float:vHealth;
	GetVehicleHealth(vehicleid, vHealth);
	if (vHealth > 950) 
	{
		SetVehicleHealth(vehicleid, 950);
	}
	#if defined HAC_OnVehicleRespray
	    return HAC_OnVehicleRespray(playerid, vehicleid, color1, color2);
	#else
		return 1;
	#endif
}

public OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    if (!GetPlayerWeapon(playerid))
    {
        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 13);
    }
    if (weaponid == 0)
    {
        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 13);
    }
   	if (hittype == 1)
	{
        new Float:ox, Float:oy, Float:oz, Float:hx, Float:hy, Float:hz;
        GetPlayerLastShotVectors(playerid, ox, oy, oz, hx, hy, hz);
        new Float:hitposdistance = GetPlayerDistanceFromPoint(hitid, hx, hy, hz);
    	if (hitposdistance == 0)
	    {
	    	CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 0);
	    }
        if (hitposdistance > 3.0)
	    {
	    	CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 0);
	    }
        new Float:xyz[3];
        GetPlayerPos(hitid,xyz[0],xyz[1],xyz[2]);
        new Float:Distance = GetPlayerDistanceFromPoint(playerid,xyz[0],xyz[1],xyz[2]);
		switch(weaponid) {
			case 30: {
				if(Distance > 70) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
			case 31: {
				if(Distance > 90) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
			case 33: {
				if(Distance > 100) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
			case 34: {
				if(Distance > 200) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
			case 25: {
				if(Distance > 30) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
			case 29: {
				if(Distance > 40) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
			case 22: {
				if(Distance > 50) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
			case 23: {
				if(Distance > 50) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
			case 24: {
				if(Distance > 50) return CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 11);
			}
        }
    }
    #if defined HAC_OnPlayerWeaponShot
	    return HAC_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
    #else
		return 1;
	#endif
}

public OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z)
{
    new Float:vHealth;
	GetVehicleHealth(vehicleid, vHealth);
    if (vHealth > 950)
    {
	    SetVehicleHealth(vehicleid, 950);
	}
    #if defined HAC_OnUnoccupiedVehicleUpdate
	    return HAC_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
    #else
		return 1;
	#endif
}


hook OnPlayerSlowUpdate(playerid)
{
	new vehid = GetPlayerVehicleID(playerid);
	if (vehid > -1) 
    {
		new Float:vehealth;
		GetVehicleHealth(vehid, vehealth);
		if (vehealth > 950)
		{
            CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 1);
			SetVehicleHealth(vehid, 950);
		}
	}
	if (GetPlayerWeapon(playerid) < 0)
	{
	    CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 13);
	}
	new Float:airbreak = GetPlayerDistanceFromPoint(playerid, LastPosition[playerid][0], LastPosition[playerid][1], LastPosition[playerid][2]);
	if (GetPlayerCameraMode(playerid) == 45 || GetPlayerCameraMode(playerid) == 34)
	{
		CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 2);
	}
    if (GetPVarInt(playerid, "LegalSpeed") == 0 && GetPlayerPing(playerid) < 200 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && PlayerSpeed(playerid) >= 40 && PlayerSpeed(playerid) - OldSpeed[playerid] >= 20)
    {
        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 7);
    }
    if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && PlayerSpeed(playerid) - OldSpeed[playerid] >= 30)
    {
		CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 7);
	}
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && GetPVarInt(playerid, "CarID") != vehid)
    {
        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 3);
    }
    if(GetPlayerAnimationIndex(playerid) == 970 || GetPlayerAnimationIndex(playerid) == 966 || GetPlayerAnimationIndex(playerid) == 516)
    {
        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 8);
    }
	if(GetPlayerAnimationIndex(playerid) == 402)
	{
		CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 9);
	}
	new surfingvehicle = GetPlayerSurfingVehicleID(playerid);
    new Float:svx, Float:svy, Float:svz, Float:npx, Float:npy, Float:npz;
    GetVehiclePos(surfingvehicle, svx, svy, svz);
    GetPlayerPos(playerid, npx, npy, npz);
    new Float:surfing = (svy + svx + svz) - (npx + npy + npz);
    if((surfingvehicle != 65535) && (surfing  < -30 || surfing > 30))
    {
	   CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 4);
    }
    new SurfingObject = GetPlayerSurfingObjectID(playerid);
    new Float:XObject, Float:YObject, Float:ZObject;
    GetObjectPos(SurfingObject, XObject, YObject, ZObject);
    new Float:surfing2 = (XObject + YObject + ZObject) - (npx + npy + npz);
    if((SurfingObject != 65535) && (surfing2  < -30 || surfing2 > 30))
	{
        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 4);
	}
	new SeatID = GetPlayerVehicleSeat(playerid);
	if(GetPlayerState(playerid) == PLAYER_STATE_PASSENGER && SeatID == 0)
	{
        CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 6);
	}
    if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID && GetPlayerAnimationIndex(playerid) != 1130)
    {
        if(PlayerSpeed(playerid) >= 5 && airbreak >= 10.0 && airbreak < 50.0)
        {
            CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 5);
        }
    }
    if (GetPlayerAnimationIndex(playerid) == 44 && PlayerSpeed(playerid) >= 5)
    {
		CallLocalFunction("OnPlayerCheatDetected", "ii", playerid, 10);
	}
    if (GetVehicleTrailer(vehid) > -1)
    {
        CallLocalFunction("OnPlayerChangedToTrailer", "iii", playerid, vehid, GetVehicleTrailer(vehid));
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}

#if defined HAC_OnPlayerWeaponShot
	forward HAC_OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ);
#endif

#if defined HAC_OnPlayerConnect
	forward HAC_OnPlayerConnect(playerid);
#endif

#if defined HAC_OnPlayerSpawn
	forward HAC_OnPlayerSpawn(playerid);
#endif

#if defined HAC_OnVehicleDamageStatusUpdate
	forward HAC_OnVehicleDamageStatusUpdate(vehicleid, playerid);
#endif

#if defined HAC_OnVehicleSpawn
	forward HAC_OnVehicleSpawn(vehicleid);
#endif

#if defined HAC_OnPlayerStateChange
	forward HAC_OnPlayerStateChange(playerid, newstate, oldstate);
#endif

#if defined HAC_OnVehicleMod
	forward HAC_OnVehicleMod(playerid, vehicleid, componentid);
#endif

#if defined HAC_OnVehiclePaintjob
	forward HAC_OnVehiclePaintjob(playerid, vehicleid, paintjobid);
#endif

#if defined HAC_OnVehicleRespray
	forward HAC_OnVehicleRespray(playerid, vehicleid, color1, color2);
#endif

#if defined HAC_OnPlayerUpdate
	forward HAC_OnPlayerUpdate(playerid);
#endif

#if defined HAC_OnUnoccupiedVehicleUpdate
	forward HAC_OnUnoccupiedVehicleUpdate(vehicleid, playerid, passenger_seat, Float:new_x, Float:new_y, Float:new_z, Float:vel_x, Float:vel_y, Float:vel_z);
#endif

#define OnPlayerWeaponShot  	            HAC_OnPlayerWeaponShot
#define OnPlayerConnect     	            HAC_OnPlayerConnect
#define OnPlayerSpawn        	            HAC_OnPlayerSpawn
#define OnVehicleDamageStatusUpdate         HAC_OnVehicleDamageStatusUpdate
#define OnVehicleSpawn                      HAC_OnVehicleSpawn
#define OnPlayerStateChange  	            HAC_OnPlayerStateChange
#define OnVehicleMod                        HAC_OnVehicleMod
#define OnVehiclePaintjob              	    HAC_OnVehiclePaintjob
#define OnVehicleRespray                    HAC_OnVehicleRespray
#define OnPlayerUpdate                      HAC_OnPlayerUpdate
#define OnUnoccupiedVehicleUpdate           HAC_OnUnoccupiedVehicleUpdate
