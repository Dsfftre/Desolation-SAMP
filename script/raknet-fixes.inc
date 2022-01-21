#define RPC_ServerJoin (137)
#define RPC_ServerQuit (138)
/*
stock ShowPlayerOnScoreBoard(playerid, toplayerid, bool:show) {
    if(!IsPlayerConnected(playerid) || !IsPlayerConnected(toplayerid)) return 0;
    
    new BitStream:bs = BS_New(), name[MAX_PLAYER_NAME];
    
    BS_WriteValue(
        bs,
        PR_UINT16, playerid,
        PR_UINT8, 1
    );

    BS_RPC(bs, toplayerid, RPC_ServerQuit);
    BS_Reset(bs);
    
    GetPlayerName(playerid, name, sizeof(name));
    
    BS_WriteValue(
        bs,
        PR_UINT16, playerid,
        PR_INT32, 0,
        PR_UINT8, !show,
        PR_UINT8, strlen(name),
        PR_STRING, name
    );
    
    BS_RPC(bs, toplayerid, RPC_ServerJoin);
    BS_Delete(bs);
    return 1;
} 
*/
//AntiVehicleSpawn
/*new VehicleDestroyed = 136;
IRPC:VehicleDestroyed(playerid, BitStream:bs)
{
    new vehicleid;

    BS_ReadUint16(bs, vehicleid);

    if (GetVehicleModel(vehicleid) < 400)
    {
        return 0;
    }

    return OnVehicleRequestDeath(vehicleid, playerid);
}
forward OnVehicleRequestDeath(vehicleid, killerid);
public OnVehicleRequestDeath(vehicleid, killerid)
{
    new Float:health;

    GetVehicleHealth(vehicleid, health);

    if (health >= 250.0)
    {
        return 0;
    }

    return 1;
}*/

//Fix surfing invisible Variant 2: rewrite and continue packet processing
//and: Anti-BulletCrasher (Anti-Crasher) to s()beit blue eclipse and s()beit red eclispe
//and: Disable GetPlayerTargetPlayer on everyone with weapon in hands
const PLAYER_SYNC = 207;
public OnIncomingPacket(playerid, packetid, BitStream:bs)
{
    if(IsPlayerNPC(playerid))
        return 1;
    if (packetid == PLAYER_SYNC)
    {
        new onFootData[PR_OnFootSync];

        BS_IgnoreBits(bs, 8); // ignore packetid (byte)
        BS_ReadOnFootSync(bs, onFootData);

        if (onFootData[PR_surfingVehicleId] != 0 &&
            onFootData[PR_surfingVehicleId] != INVALID_VEHICLE_ID
        ) {
            if ((floatabs(onFootData[PR_surfingOffsets][0]) >= 50.0) ||
                (floatabs(onFootData[PR_surfingOffsets][1]) >= 50.0) ||
                (floatabs(onFootData[PR_surfingOffsets][2]) >= 50.0)
            ) {
                onFootData[PR_surfingOffsets][0] = onFootData[PR_surfingOffsets][1] = onFootData[PR_surfingOffsets][2] = 0.0;

                BS_SetWriteOffset(bs, 8);
                BS_WriteOnFootSync(bs, onFootData); // rewrite
            } 
        }
        if(onFootData[PR_position][2] == -5.5) {
			Kick(playerid);
			return 0;
		}
        
    }

    return 1;
}

// Fix aimZ invisible Variant 2: rewrite and continue packet processing
// and: Anti - InvalidCamera (Anti-Crasher)
const AIM_SYNC = 203;
IPacket:AIM_SYNC(playerid, BitStream:bs)
{
    if(IsPlayerNPC(playerid))
        return 1;
    new aimData[PR_AimSync];
    
    BS_IgnoreBits(bs, 8); // ignore packetid (byte)
    BS_ReadAimSync(bs, aimData);

    if (aimData[PR_aimZ] != aimData[PR_aimZ]) // is NaN
    {
        aimData[PR_aimZ] = 0.0;

        BS_SetWriteOffset(bs, 8);
        BS_WriteAimSync(bs, aimData); // rewrite
    }
    if (aimData[PR_camMode] == 45 || aimData[PR_camMode] == 49)
	{
		Kick(playerid);
		return 1;
	}

    return 1;
}

// Fix "Unoccupied" crasher and "Enter" crasher
const UNOCCUPIED_SYNC = 209;
IPacket:UNOCCUPIED_SYNC(playerid, BitStream:bs)
{
    new unoccupiedData[PR_UnoccupiedSync];
 
    BS_IgnoreBits(bs, 8); // ignore packetid (byte)
    BS_ReadUnoccupiedSync(bs, unoccupiedData);
 
    if ((floatabs(unoccupiedData[PR_roll][0]) > 1.0) ||
        (floatabs(unoccupiedData[PR_roll][1]) > 1.0) ||
        (floatabs(unoccupiedData[PR_roll][2]) > 1.0) ||
        (floatabs(unoccupiedData[PR_direction][0]) > 1.0) ||
        (floatabs(unoccupiedData[PR_direction][1]) > 1.0) ||
        (floatabs(unoccupiedData[PR_direction][2]) > 1.0) ||
        (floatabs(unoccupiedData[PR_position][0]) > 20000.0) ||
        (floatabs(unoccupiedData[PR_position][1]) > 20000.0) ||
        (floatabs(unoccupiedData[PR_position][2]) > 20000.0) ||
        (floatabs(unoccupiedData[PR_angularVelocity][0]) > 1.0) ||
        (floatabs(unoccupiedData[PR_angularVelocity][1]) > 1.0) ||
        (floatabs(unoccupiedData[PR_angularVelocity][2]) > 1.0) ||
        (floatabs(unoccupiedData[PR_velocity][0]) > 100.0) ||
        (floatabs(unoccupiedData[PR_velocity][1]) > 100.0) ||
        (floatabs(unoccupiedData[PR_velocity][2]) > 100.0)
    ) {
        return 0; // ignore bad packet
    }

    if ((unoccupiedData[PR_roll][0] == unoccupiedData[PR_direction][0]) &&
        (unoccupiedData[PR_roll][1] == unoccupiedData[PR_direction][1]) &&
        (unoccupiedData[PR_roll][2] == unoccupiedData[PR_direction][2])
    ) {
        return 0; // ignore bad packet
    }    

    return 1;
}

//Anti-InvalidSeat (Anti-Crasher)
const PASSENGER_SYNC = 211;
IPacket:PASSENGER_SYNC(playerid, BitStream:bs){
	if(GetPlayerVehicleSeat(playerid) == 0){
		Kick(playerid);
		return 0;
	}
	return 1;
}
