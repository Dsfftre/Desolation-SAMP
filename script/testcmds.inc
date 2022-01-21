/*#if defined _inc_testcmds
	#undef _inc_testcmds
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

YCMD:trainingfloor(playerid, params[], help)
 {
	SetPlayerPos(playerid, 948.5112, 2224.7825, 1014.5812);
	return 1;
}
YCMD:play(playerid, params[], help)
 {
	//Audio_Play(playerid, 22);
	return 1;
 }

YCMD:sewers(playerid, params[], help) {
	SetPlayerPos(playerid, 1942.2697, 1307.9337, 605.2542);
	return 1;
}


YCMD:floor4(playerid, params[], help) {
	SetPlayerPos(playerid, 2013.0966, 2221.6104, 1026.1846);
	return 1;
}

YCMD:floor3(playerid, params[], help) {
	SetPlayerPos(playerid, 1600.0323, 1773.7811, 1034.6913);
	return 1;
}

YCMD:floor2b(playerid, params[], help) {
	SetPlayerPos(playerid, 949.2772, 2014.6150, 1014.0919);
	return 1;
}

YCMD:floor2(playerid, params[], help) {
	SetPlayerPos(playerid, 923.2028, 2005.4574, 1015.4441);
	return 1;
}

YCMD:floor1(playerid, params[], help) {
	SetPlayerPos(playerid, -1624.4282, 552.2929, 1001.2941);
	return 1;
}
/*
YCMD:buffalo(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(402, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:rcbaron(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(464, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:rcraider(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(465, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:rcgoblin(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(501, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:beagle(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(511, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:seasparrow(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(447, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:hunter(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(425, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:hydra(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(520, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:rhino(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(432, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}

YCMD:roadtrain(playerid, params[], help) {
	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new vehid = CreateVehicle(515, pos[0], pos[1], pos[2]+2.0, 0.0, random(64), random(64), 0, 1);
	PutPlayerInVehicle(playerid, vehid, 0);
	SetVehicleHealth(vehid, 12000.0);
	return 1;
}*/

YCMD:swat(playerid, params[], help) {
	SetPlayerHealth(playerid, 150.0);
	SetPlayerArmour(playerid, 100.0);
	GivePlayerWeapon(playerid, 31, 350);
	GivePlayerWeapon(playerid, 24, 100);
	GivePlayerWeapon(playerid, 4, 1);
	GivePlayerWeapon(playerid, 16, 5);
	return 1;
}

YCMD:sona(playerid, params[], help) {
	GivePlayerWeapon(playerid, 8, 1);
	return 1;
}

YCMD:paparazzi(playerid, params[], help) {
	GivePlayerWeapon(playerid, 43, 500);
	return 1;
}

YCMD:boom(playerid, params[], help) {
	new Float:boompos[3];
	GetPlayerPos(playerid, boompos[0], boompos[1], boompos[2]);
	CreateExplosion(boompos[0], boompos[1], boompos[2], 7, 10.0);
	StunPlayer(playerid);
	return 1;
}
/*
YCMD:stun(playerid, params[], help) {
	StunPlayer(playerid);
	return 1;
}

*/

/*hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) {
	new string[256];
	format(string, sizeof string, "OnPlayerGiveDamage(playerid %d, damagedid %d, Float:amount %f, weaponid %d, bodypart %d)", playerid, damagedid, amount, weaponid, bodypart);
	SendClientMessageToAll(-1, string);
	return Y_HOOKS_CONTINUE_RETURN_1;
}*/

/*hook OnVehicleDamageStatusUpd(vehicleid, playerid) {
	new string[256];
	format(string, sizeof string, "OnVehicleDamageStatusUpdate(vehicleid %d, playerid %d)", vehicleid, playerid);
	SendClientMessageToAll(-1, string);
	return Y_HOOKS_CONTINUE_RETURN_1;
}*/

/*hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) {
	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
	new string[256];
	format(string, sizeof string, "OnPlayerWeaponShot(playerid, weaponid %d, hittype %d, hitid %d, X %f, fY %f, fZ %f)", playerid, weaponid, hittype, hitid, fX, fY, fZ);
	SendClientMessageToAll(-1, string);
	if(adminlevel[playerid] != 1)
		CreateDynamicObject(2114,fX, fY, fZ, 0.0, 0.0, 0.0);
	return Y_HOOKS_CONTINUE_RETURN_1;
}*/