YCMD:debug(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	new targetid;
	if(Group_GetPlayer(g_Admin, playerid))
	{
		if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /debug [id]");
		if(targetid == INVALID_PLAYER_ID) {
			unformat(params, "i", targetid);
			if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}

		DebugPlayer(targetid);

		new string[256];
		format(string, sizeof string, "%s %s has debugged %s[%i].", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid);
		SendAdminMessage(HEX_YELLOW, string, true);
	}
	return 1;
}

YCMD:debugme(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");

	if(GetPVarInt(playerid, "debugged") == 1)
		return SCM(playerid, HEX_RED, "Error: You recently used the /debugme command.");

	new bool:findadmin = false;

	foreach(new i:GroupMember[g_AdminDuty]) {
		findadmin = true;
		break;
	}

	if(findadmin)
		return SCM(playerid, HEX_RED, "There are admins in-game. Use /report if you need to be debugged.");

	new string[256];
	format(string,sizeof string, "(( %s [%d] has declared themselves bugged, and teleported away with the /debugme command. ))", PlayerName(playerid,false), playerid);
	WhiteProxMSG(NAMETAG_DISTANCE*2, playerid, string);

	DebugPlayer(playerid);
	SetPVarInt(playerid, "debugged", 1);

	defer DebugFade(playerid);
	SCM(playerid, HEX_FADE2, "Hint: You can use again /debugme in 10 minutes.");

	format(string, sizeof string, "%s [%d] has debugged himself.", PlayerName(playerid), playerid);
	SendAdminMessage(HEX_YELLOW, string, true);
	
	return 1;
}

timer DebugFade[600*1000](playerid) {
	DeletePVar(playerid,  "debugged");
}

DebugPlayer(playerid) {

	new ispcar = GetPlayerVehicleID(playerid);

	if(ispcar) 
	{
		RemovePlayerFromVehicle(playerid);
		SetVehicleToRespawn(ispcar);
	}
	
	SetPlayerPos(playerid, 1797.6653, -1869.5405, 13.5742);
	SetPlayerFacingAngle(playerid, 0.0);

	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);

	ChangeMaskVW(playerid);

	return 1;
}