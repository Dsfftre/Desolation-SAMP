/*#if defined _inc_useitem
	#undef _inc_useitem
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	Command_AddAltNamed("firstaid", "heal");
	Command_AddAltNamed("boxers", "boxer");
	Command_AddAltNamed("boxers", "brassknuckles");
	Command_AddAltNamed("golfclub", "golf");
	Command_AddAltNamed("nightstick", "baton");
	Command_AddAltNamed("bat", "baseball");
	Command_AddAltNamed("bat", "baseballbat");
	Command_AddAltNamed("katana", "sword");
	Command_AddAltNamed("molotov", "molotovcocktail");
	Command_AddAltNamed("infect", "virus");
	Command_AddAltNamed("antidote", "cure");
	Command_AddAltNamed("antidote", "antivirus");
	Command_AddAltNamed("silenced", "silencedpistol");
	Command_AddAltNamed("spaz", "combatshotgun");
	Command_AddAltNamed("microuzi", "uzi");
	Command_AddAltNamed("countyrifle", "rifle");
	Command_AddAltNamed("sniperrifle", "sniper");
	Command_AddAltNamed("ar15", "m4");
	Command_AddAltNamed("hsrpg", "hsrocket");

	return Y_HOOKS_CONTINUE_RETURN_1;
}

/*public OnPlayerUpdate(playerid) {
    if((GetPlayerWeapon(playerid) == 44 || GetPlayerWeapon(playerid) == 45) && !IsPlayerInAnyVehicle(playerid)) {
        new keys,ud,lr;
        GetPlayerKeys(playerid, keys, ud, lr);
        if(keys & KEY_FIRE)  {
            return 0;
        }
	}
    return 1;
}*/

/*
YCMD:boxers(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 1, 1)) return SCM(playerid, HEX_RED, "Error: You need a boxer in your inventory.");
	RemovePlayerItem(playerid, 1, 1);
	p_weapon[playerid][2] = 1;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "prepares a pair of boxers.");
	return 1;
}

YCMD:golfclub(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 2, 1)) return SCM(playerid, HEX_RED, "Error: You need a golf club in your inventory.");
	RemovePlayerItem(playerid, 2, 1);
	p_weapon[playerid][2] = 2;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "takes hold of a golf club.");
	return 1;
}

YCMD:nightstick(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 3, 1)) return SCM(playerid, HEX_RED, "Error: You need a golf club in your inventory.");
	RemovePlayerItem(playerid, 3, 1);
	p_weapon[playerid][2] = 2;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "unholsters a baton.");
	return 1;
}

YCMD:knife(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 4, 1)) return SCM(playerid, HEX_RED, "Error: You need a knife in your inventory.");
	RemovePlayerItem(playerid, 4, 1);
	p_weapon[playerid][2] = 4;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "unsheathes a knife.");
	return 1;
}

YCMD:bat(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 5, 1)) return SCM(playerid, HEX_RED, "Error: You need a baseball bat in your inventory.");
	RemovePlayerItem(playerid, 5, 1);
	p_weapon[playerid][2] = 5;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "takes hold of a baseball bat.");
	return 1;
}

YCMD:shovel(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 6, 1)) return SCM(playerid, HEX_RED, "Error: You need a shovel in your inventory.");
	RemovePlayerItem(playerid, 6, 1);
	p_weapon[playerid][2] = 6;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "takes hold of a shovel.");
	return 1;
}

YCMD:poolcue(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 7, 1)) return SCM(playerid, HEX_RED, "Error: You need a pool cue in your inventory.");
	RemovePlayerItem(playerid, 7, 1);
	p_weapon[playerid][2] = 7;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "holds a pool cue.");
	return 1;
}

YCMD:katana(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 8, 1)) return SCM(playerid, HEX_RED, "Error: You need a katana in your inventory.");
	RemovePlayerItem(playerid, 8, 1);
	p_weapon[playerid][2] = 8;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a katana.");
	return 1;
}

YCMD:chainsaw(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 9, 1)) return SCM(playerid, HEX_RED, "Error: You need a chainsaw in your inventory.");
	RemovePlayerItem(playerid, 9, 1);
	p_weapon[playerid][2] = 9;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a chainsaw.");
	return 1;
}

YCMD:purpledildo(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 10, 1)) return SCM(playerid, HEX_RED, "Error: You need a purple dildo in your inventory.");
	RemovePlayerItem(playerid, 10, 1);
	p_weapon[playerid][2] = 10;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);
	return 1;
}

YCMD:dildo(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 11, 1)) return SCM(playerid, HEX_RED, "Error: You need a dildo in your inventory.");
	RemovePlayerItem(playerid, 11, 1);
	p_weapon[playerid][2] = 11;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);
	return 1;
}

YCMD:vibrator(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 12, 1)) return SCM(playerid, HEX_RED, "Error: You need a vibrator in your inventory.");
	RemovePlayerItem(playerid, 12, 1);
	p_weapon[playerid][2] = 12;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);
	return 1;
}

YCMD:silvervibrator(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 13, 1)) return SCM(playerid, HEX_RED, "Error: You need a vibrator in your inventory.");
	RemovePlayerItem(playerid, 13, 1);
	p_weapon[playerid][2] = 13;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);
	return 1;
}

YCMD:flowers(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 14, 1)) return SCM(playerid, HEX_RED, "Error: You need flowers in your inventory.");
	RemovePlayerItem(playerid, 14, 1);
	p_weapon[playerid][2] = 14;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "holds a bouquet of flowers.");
	return 1;
}

YCMD:cane(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 15, 1)) return SCM(playerid, HEX_RED, "Error: You need a vibrator in your inventory.");
	RemovePlayerItem(playerid, 15, 1);
	p_weapon[playerid][2] = 15;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);

	PlayerAction(playerid, "holds a cane.");
	return 1;
}

YCMD:grenade(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 16, 1)) return SCM(playerid, HEX_RED, "Error: You need a grenade in your inventory.");
	RemovePlayerItem(playerid, 16, 1);

	GivePlayerWeapon(playerid, 16, 1);
	SCM(playerid, HEX_FADE2, "Your hand-held grenades will be lost upon relogging.");

	PlayerAction(playerid, "takes hold of a grenade.");
	return 1;
}

YCMD:teargas(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 17, 1)) return SCM(playerid, HEX_RED, "Error: You need a tear gas in your inventory.");
	RemovePlayerItem(playerid, 17, 1);

	GivePlayerWeapon(playerid, 17, 1);
	SCM(playerid, HEX_FADE2, "Your hand-held tear gas will be lost upon relogging.");

	PlayerAction(playerid, "prepares a teargas.");
	return 1;
}

YCMD:molotov(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 18, 1)) return SCM(playerid, HEX_RED, "Error: You need a molotov cocktail in your inventory.");
	RemovePlayerItem(playerid, 18, 1);

	GivePlayerWeapon(playerid, 18, 1);
	SCM(playerid, HEX_FADE2, "Your hand-held molotov cocktail will be lost upon relogging.");

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "lights a molotov cocktail.");
	return 1;
}

YCMD:camera(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 35, 1)) return SCM(playerid, HEX_RED, "Error: You need a camera in your inventory.");
	RemovePlayerItem(playerid, 35, 1);
	p_weapon[playerid][2] = 43;

	GivePlayerWeapon(playerid, p_weapon[playerid][2], 700);

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a camera.");
	return 1;
}

YCMD:parachute(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 38, 1)) return SCM(playerid, HEX_RED, "Error: You need a vibrator in your inventory.");
	RemovePlayerItem(playerid, 38, 1);

	GivePlayerWeapon(playerid, 46, 1);
	SCM(playerid, HEX_FADE2, "Your parachute will be lost upon relogging.");
	return 1;
}

YCMD:mediccase(playerid, params[], help) {
	SCM(playerid, HEX_FADE2, "Usage: /revive [id]");
	return 1;
}
*/

YCMD:fill(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You need to be in a vehicle.");

	new targetid = GetPlayerVehicleID(playerid);
	new addfuel = 100;

	if(!Group_GetPlayer(g_AdminDuty, playerid)) {
		if(Fuel[targetid] >= 100) return SCM(playerid, HEX_RED, "Error: The vehicle's tank is already full.");
		if(!HasPlayerItem(playerid, 46, 1)) return SCM(playerid, HEX_RED, "Error: You do not have a filled Jerrycan.");
		addfuel = CountPlayerItem(playerid, 46, false);
		new maxaddfuel = 100 - Fuel[targetid];
		if(addfuel > maxaddfuel) addfuel = maxaddfuel;
		RemovePlayerItem(playerid, 46, addfuel);
	}

	Fuel[targetid] += addfuel;
	if(Fuel[targetid] > 100) Fuel[targetid] = 100;



	new string[128];
	
	if(addfuel == 1)
		format(string, sizeof string, "pours %d litre of fuel into the tank.", addfuel);
	else
		format(string, sizeof string, "pours %d liters of fuel into the tank.", addfuel);

	PlayerHiddenAction(playerid, string);

	if(addfuel == 1)
		format(string, sizeof string, "> %s pours %d litre of fuel into the tank.", PlayerName(playerid,false), addfuel);
	else
		format(string, sizeof string, "> %s pours %d liters of fuel into the tank.", PlayerName(playerid,false), addfuel);

	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, string);

	RemovePlayerFromVehicle(playerid);
	//ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);

	format(string, sizeof string, "[LOG]: %s[%d] has filled %d gas into vehicle %d.", PlayerName(playerid), playerid, addfuel, targetid);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

YCMD:repair(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You need to be in a vehicle.");

	new targetid = GetPlayerVehicleID(playerid);
	new addfuel = 100;
	new Float:vhp;
	GetVehicleHealth(targetid, vhp);

	if(!Group_GetPlayer(g_AdminDuty, playerid)) {
		if(vhp >= 1000.0) return SCM(playerid, HEX_RED, "Error: The vehicle's health is already full.");
		if(!HasPlayerItem(playerid, 64, 1)) return SCM(playerid, HEX_RED, "Error: You do not have a toolbox.");
		RemovePlayerItem(playerid, 64, 1);
	}

	SetVehicleHealth(targetid, 1000.0);
	RepairVehicle(targetid);

	new string[128];
	format(string, sizeof string, "repairs the vehicle.", addfuel);
	PlayerHiddenAction(playerid, string);
	format(string, sizeof string, "> %s repairs the vehicle.", PlayerName(playerid,false));
	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, string);

	RemovePlayerFromVehicle(playerid);
	//ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	format(string, sizeof string, "[LOG]: %s[%d] has repaired vehicle %d.", PlayerName(playerid), playerid, targetid);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

YCMD:firstaid(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /firstaid [id]");
	if(targetid == INVALID_PLAYER_ID)  {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	new Float:health = 150.0;
	if(!Group_GetPlayer(g_AdminDuty, playerid)) {
		if(GetPlayerInterior(playerid) != GetPlayerInterior(targetid) && GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		new Float:fapos[3];
		GetPlayerPos(targetid, fapos[0], fapos[1], fapos[2]);
		if(!IsPlayerInRangeOfPoint(playerid, 2.0, fapos[0], fapos[1], fapos[2])) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		if(!HasPlayerItem(playerid, 48, 1)) return SCM(playerid, HEX_RED, "Error: You need a First Aid Kit to heal someone.");
		RemovePlayerItem(playerid, 48, 1);
		GetPlayerHealth(targetid, health);
		health += 80.0;
		if(health > 150.0) health = 150.0;
	}
	SetPlayerHealth(targetid, health);


	new string[128];
	format(string, sizeof string, "uses a First Aid Kit on %s.", PlayerName(targetid, false));
	PlayerHiddenAction(playerid, string);
	if(playerid != targetid)
		format(string, sizeof(string), "> %s used a First Aid Kit on %s.", PlayerName(playerid,false),PlayerName(targetid,false));
	else
		format(string, sizeof(string), "> %s used a First Aid Kit.", PlayerName(playerid,false),PlayerName(targetid,false));
	//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE);
	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, string);

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);

	return 1;
}

YCMD:infect(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /infect [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	if(!Group_GetPlayer(g_AdminDuty, playerid)) {
		if(GetPlayerInterior(playerid) != GetPlayerInterior(targetid) && GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		new Float:inpos[3];
		GetPlayerPos(targetid, inpos[0], inpos[1], inpos[2]);
		if(!IsPlayerInRangeOfPoint(playerid, 2.0, inpos[0], inpos[1], inpos[2])) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		if(!HasPlayerItem(playerid, 52, 1)) return SCM(playerid, HEX_RED, "Error: You need a virus sample to infect someone.");
		if(playerid != targetid && GetPlayerSpecialAction(targetid) != SPECIAL_ACTION_DUCK) return SCM(playerid, HEX_RED, "Error: Your target needs to be crouching.");
		RemovePlayerItem(playerid, 52, 1);
	}
	if(random(10))
		Bit_Let(infected, targetid);

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	new string[128];
	format(string, sizeof string, "injects a vaccine into %s.", PlayerName(targetid, false));
	PlayerAction(playerid, string);
	return 1;
}

YCMD:antidote(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /antidote [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(!Group_GetPlayer(g_AdminDuty, playerid)) {
		if(GetPlayerInterior(playerid) != GetPlayerInterior(targetid) && GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		new Float:inpos[3];
		GetPlayerPos(targetid, inpos[0], inpos[1], inpos[2]);
		if(!IsPlayerInRangeOfPoint(playerid, 2.0, inpos[0], inpos[1], inpos[2])) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "Error: You are too far away.");
		if(!HasPlayerItem(playerid, 53, 1)) return SCM(playerid, HEX_RED, "Error: You need an Antidote to cure someone.");
		if(playerid != targetid && GetPlayerSpecialAction(targetid) != SPECIAL_ACTION_DUCK) return SCM(playerid, HEX_RED, "Error: Your target needs to be crouching.");
		RemovePlayerItem(playerid, 53, 1);
	}
	if(random(10))
		Bit_Vet(infected, targetid);

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	new string[128];
	format(string, sizeof string, "injects a vaccine into %s.", PlayerName(targetid, false));
	PlayerAction(playerid, string);
	return 1;
}
/*
YCMD:pistol(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 19, 1)) return SCM(playerid, HEX_RED, "Error: You need a pistol in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /pistol [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 39, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 19, 1);
	RemovePlayerItem(playerid, 39, subammo);

	p_weapon[playerid][1] = 22;
	p_ammos[playerid][1] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][1], p_ammos[playerid][1]);

	ApplyAnimation(playerid, "PYTHON", "python_reload", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a pistol.");
	return 1;
}

YCMD:silencedpistol(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 20, 1)) return SCM(playerid, HEX_RED, "Error: You need a silenced pistol in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /silencedpistol [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 39, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 20, 1);
	RemovePlayerItem(playerid, 39, subammo);

	p_weapon[playerid][1] = 23;
	p_ammos[playerid][1] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][1], p_ammos[playerid][1]);

	ApplyAnimation(playerid, "SILENCED", "Silence_reload", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a silenced pistol.");
	return 1;
}

YCMD:deagle(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 21, 1)) return SCM(playerid, HEX_RED, "Error: You need a Desert Eagle in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /deagle [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 41, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 21, 1);
	RemovePlayerItem(playerid, 41, subammo);

	p_weapon[playerid][1] = 24;
	p_ammos[playerid][1] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][1], p_ammos[playerid][1]);

	ApplyAnimation(playerid, "PYTHON", "python_reload", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a Desert Eagle.");
	return 1;
}

YCMD:shotgun(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 22, 1)) return SCM(playerid, HEX_RED, "Error: You need a shotgun in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /shotgun [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 40, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 22, 1);
	RemovePlayerItem(playerid, 40, subammo);

	p_weapon[playerid][0] = 25;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "BUDDY", "BUDDY_RELOAD", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a shotgun.");
	return 1;
}

YCMD:sawnoff(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 23, 1)) return SCM(playerid, HEX_RED, "Error: You need a sawn-off shotgun in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /sawnoff [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 40, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 23, 1);
	RemovePlayerItem(playerid, 40, subammo);

	p_weapon[playerid][0] = 26;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "PYTHON", "python_reload", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a sawnoff shotgun.");
	return 1;
}

YCMD:combatshotgun(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 24, 1)) return SCM(playerid, HEX_RED, "Error: You need a combat shotgun in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /combatshotgun [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 40, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 24, 1);
	RemovePlayerItem(playerid, 40, subammo);

	p_weapon[playerid][0] = 27;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "BUDDY", "BUDDY_RELOAD", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a combat shotgun.");
	return 1;
}

YCMD:uzi(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 25, 1)) return SCM(playerid, HEX_RED, "Error: You need a micro uzi in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /uzi [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 39, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 25, 1);
	RemovePlayerItem(playerid, 39, subammo);

	p_weapon[playerid][0] = 28;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "UZI", "UZI_RELOAD", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a micro uzi.");
	return 1;
}

YCMD:mp5(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 26, 1)) return SCM(playerid, HEX_RED, "Error: You need a MP5 in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /mp5 [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 39, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 26, 1);
	RemovePlayerItem(playerid, 39, subammo);

	p_weapon[playerid][0] = 29;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "UZI", "UZI_RELOAD", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips an MP5.");
	return 1;
}

YCMD:ak47(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 27, 1)) return SCM(playerid, HEX_RED, "Error: You need an AK47 in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /ak47 [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 42, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 27, 1);
	RemovePlayerItem(playerid, 42, subammo);

	p_weapon[playerid][0] = 30;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "PYTHON", "python_reload", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips an AK47.");
	return 1;
}

YCMD:m4(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 28, 1)) return SCM(playerid, HEX_RED, "Error: You need an M4 in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /m4 [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 43, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 28, 1);
	RemovePlayerItem(playerid, 43, subammo);

	p_weapon[playerid][0] = 31;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "TEC", "TEC_reload", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips an M4.");
	return 1;
}

YCMD:tec9(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 29, 1)) return SCM(playerid, HEX_RED, "Error: You need a TEC9 in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /tec9 [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 39, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 29, 1);
	RemovePlayerItem(playerid, 39, subammo);

	p_weapon[playerid][0] = 32;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "TEC", "TEC_reload", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a TEC9.");
	return 1;
}

YCMD:rifle(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 30, 1)) return SCM(playerid, HEX_RED, "Error: You need a county rifle in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /rifle [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 44, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 30, 1);
	RemovePlayerItem(playerid, 44, subammo);

	p_weapon[playerid][0] = 33;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "RIFLE", "RIFLE_load", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a county rifle.");
	return 1;
}

YCMD:sniper(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 31, 1)) return SCM(playerid, HEX_RED, "Error: You need a sniper rifle in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /sniper [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 44, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 31, 1);
	RemovePlayerItem(playerid, 44, subammo);

	p_weapon[playerid][0] = 34;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	ApplyAnimation(playerid, "RIFLE", "RIFLE_load", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "equips a sniper rifle.");
	return 1;
}

YCMD:rpg(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 32, 1)) return SCM(playerid, HEX_RED, "Error: You need an RPG in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /rpg [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 45, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 32, 1);
	RemovePlayerItem(playerid, 45, subammo);

	p_weapon[playerid][0] = 35;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	PlayerAction(playerid, "equips an RPG.");
	return 1;
}

YCMD:hsrocket(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 33, 1)) return SCM(playerid, HEX_RED, "Error: You need an HS Rocket in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /hsrocket [ammo]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of ammunition.");
	if(!HasPlayerItem(playerid, 45, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much ammunition.");


	RemovePlayerItem(playerid, 33, 1);
	RemovePlayerItem(playerid, 45, subammo);

	p_weapon[playerid][0] = 36;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	PlayerAction(playerid, "equips an HS Rocket launcher.");
	return 1;
}

YCMD:flamethrower(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 34, 1)) return SCM(playerid, HEX_RED, "Error: You need a flamethrower in your inventory.");

	new subammo;
	if(sscanf(params, "d", subammo)) return SCM(playerid, HEX_FADE2, "Usage: /flamethrower [gas]");
	if(subammo < 1) return SCM(playerid, HEX_RED, "Error: Invalid amount of gas.");
	if(!HasPlayerItem(playerid, 46, subammo)) return SCM(playerid, HEX_RED, "Error: You do not have that much gas. (Jerrycan)");


	RemovePlayerItem(playerid, 34, 1);
	RemovePlayerItem(playerid, 46, subammo);

	p_weapon[playerid][0] = 37;
	p_ammos[playerid][0] = subammo;

	GivePlayerWeapon(playerid, p_weapon[playerid][0], p_ammos[playerid][0]);

	PlayerAction(playerid, "equips a flamethrower.");
	return 1;
}

YCMD:nightvision(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 36, 1)) return SCM(playerid, HEX_RED, "Error: You need a nightvision in your inventory.");

	GivePlayerWeapon(playerid, 44, 1);

	if(Bit_Get(tutorial, playerid))
		SCM(playerid, HEX_FADE2, "Hint: You can select and use nightvision from your weapons. Only you will see the attachment on your character.");

	return 1;
}

YCMD:thermalgoggles(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	if(!HasPlayerItem(playerid, 37, 1)) return SCM(playerid, HEX_RED, "Error: You need a nightvision in your inventory.");

	GivePlayerWeapon(playerid, 45, 1);

	if(Bit_Get(tutorial, playerid))
		SCM(playerid, HEX_FADE2, "Hint: You can select and use thermal goggles from your weapons. Only you will see the attachment on your character.");

	return 1;
}*/