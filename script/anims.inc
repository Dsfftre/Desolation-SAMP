/*#if defined _inc_anims
	#undef _inc_anims
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

new const AnimLibs[][] = {
  "AIRPORT",      "ATTRACTORS",   "BAR",          "BASEBALL",     "BD_FIRE",
  "BEACH",        "BENCHPRESS",   "BF_INJECTION", "BIKE_DBZ",     "BIKED",
  "BIKEH",        "BIKELEAP",     "BIKES",        "BIKEV",        "BLOWJOBZ",
  "BMX",          "BOMBER",       "BOX",          "BSKTBALL",     "BUDDY",
  "BUS",          "CAMERA",       "CAR",          "CAR_CHAT",     "CARRY",
  "CASINO",       "CHAINSAW",     "CHOPPA",       "CLOTHES",      "COACH",
  "COLT45",       "COP_AMBIENT",  "COP_DVBYZ",    "CRACK",        "CRIB",
  "DAM_JUMP",     "DANCING",      "DEALER",       "DILDO",        "DODGE",
  "DOZER",        "DRIVEBYS",     "FAT",          "FIGHT_B",      "FIGHT_C",
  "FIGHT_D",      "FIGHT_E",      "FINALE",       "FINALE2",      "FLAME",
  "FLOWERS",      "FOOD",         "FREEWEIGHTS",  "GANGS",        "GFUNK",
  "GHANDS",       "GHETTO_DB",    "GOGGLES",      "GRAFFITI",     "GRAVEYARD",
  "GRENADE",      "GYMNASIUM",    "HAIRCUTS",     "HEIST9",       "INT_HOUSE",
  "INT_OFFICE",   "INT_SHOP",     "JST_BUISNESS", "KART",         "KISSING",
  "KNIFE",        "LAPDAN1",      "LAPDAN2",      "LAPDAN3",      "LOWRIDER",
  "MD_CHASE",     "MD_END",       "MEDIC",        "MISC",         "MTB",
  "MUSCULAR",     "NEVADA",       "ON_LOOKERS",   "OTB",          "PARACHUTE",
  "PARK",         "PAULNMAC",     "PED",          "PLAYER_DVBYS", "PLAYIDLES",
  "POLICE",       "POOL",         "POOR",         "PYTHON",       "QUAD",
  "QUAD_DBZ",     "RAPPING",      "RIFLE",        "RIOT",         "ROB_BANK",
  "ROCKET",       "RUNNINGMAN",   "RUSTLER",      "RYDER",        "SCRATCHING",
  "SEX",          "SHAMAL",       "SHOP",         "SHOTGUN",      "SILENCED",
  "SKATE",        "SMOKING",      "SNIPER",       "SNM",          "SPRAYCAN",
  "STRIP",        "SUNBATHE",     "SWAT",         "SWEET",        "SWIM",
  "SWORD",        "TANK",         "TATTOOS",      "TEC",          "TRAIN",
  "TRUCK",        "UZI",          "VAN",          "VENDING",      "VORTEX",
  "WAYFARER",     "WEAPONS",      "WOP",          "WUZI"
};

hook OnGameModeInit() {
	Command_AddAltNamed("stopanim", "sa");
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {
	for(new i = 0; i < sizeof(AnimLibs); ++i)
		ApplyAnimation(playerid, AnimLibs[i], "null", 4.0, 0, 0, 0, 0, 0, 1);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(Bit_Get(inanim, playerid)) {
		if(!Bit_Get(dead, playerid)) {
			if(newkeys & KEY_AIM) {
				Bit_Vet(inanim, playerid);
				ClearAnimations(playerid, 1);
				if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CUFFED || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CARRY)
					SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:anims(playerid, params[], help) {
    new string[1024];
    string = "/(s)top(a)nim /seat /lay /sit /lean /lean2 /fall /flip /rollfall /injured /injured2 /crack /dead /exhausted /kiss /washhands\n/handsup /akick /lowbodypush /push /lifejump /fstance /aim /aiml /aimr /fuckyou /taichi /crossarms /lightcig\n/tapcig /carry /box /pimpslap /elbow /kneekick /slapass /dance /strip /cover /lowthrow /cop /cop2 /highthrow /sleep\n";
    strcat(string, "/airkick /gkick /gpunch /swat1 /swat2 /walk /wave /facepalm /gsign /lol /cry /funeral /koface /kostomach /drunk\n/biteanim /bittenanim\n/stunanim /robcash /robno /riflestand /rifleup");

	if(Bit_Get(tutorial, playerid))
			SCM(playerid, HEX_FADE2, "Hint: You can do frozen anims like /rifleup, then immediately aim by holding your right mouse button.");

	inline Empty(pid, dialogid, response, listitem, string:inputtext[])
    {
        #pragma unused pid, dialogid, response, listitem, inputtext
    }
    Dialog_ShowCallback(playerid, using inline Empty, DIALOG_STYLE_MSGBOX, "{FFFFFF}Animations", string, "Close");
    return 1;
}

YCMD:stopanim(playerid, params[], help) {
	
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
    if(IsPlayerConnected(playerid)) {
		Bit_Vet(inanim, playerid);
        ClearAnimations(playerid, 1);
        //SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CUFFED || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_CARRY)
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    }
    return 1;
}

YCMD:gsign(playerid, params[], help) {
    if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	new animid;
	sscanf(params, "i", animid);
	switch (animid) {
		case 1: ApplyAnimation(playerid, "GHANDS", "gsign1", 3.5, 0, 0, 0, 0, 0, 1);
		case 2: ApplyAnimation(playerid, "GHANDS", "gsign1LH", 3.5, 0, 0, 0, 0, 0, 1);
		case 3: ApplyAnimation(playerid, "GHANDS", "gsign2", 3.5, 0, 0, 0, 0, 0, 1);
		case 4: ApplyAnimation(playerid, "GHANDS", "gsign2LH", 3.5, 0, 0, 0, 0, 0, 1);
		case 5: ApplyAnimation(playerid, "GHANDS", "gsign3", 3.5, 0, 0, 0, 0, 0, 1);
		case 6: ApplyAnimation(playerid, "GHANDS", "gsign3LH", 3.5, 0, 0, 0, 0, 0, 1);
		case 7: ApplyAnimation(playerid, "GHANDS", "gsign4", 3.5, 0, 0, 0, 0, 0, 1);
		case 8: ApplyAnimation(playerid, "GHANDS", "gsign4LH", 3.5, 0, 0, 0, 0, 0, 1);
		case 9: ApplyAnimation(playerid, "GHANDS", "gsign5", 3.5, 0, 0, 0, 0, 0, 1);
		case 10: ApplyAnimation(playerid, "GHANDS", "gsign5LH", 3.5, 0, 0, 0, 0, 0, 1);
		default: SCM(playerid, HEX_FADE2, "Usage: /gsign [1-10]")	;
	}

	return 1;
}

YCMD:stunanim(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "FIGHT_E", "HIT_FIGHTKICK_B", 3.0, 0, 1, 1, 0, 0, 1);
	
	return 1;
}

YCMD:biteanim(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "BASEBALL", "BAT_HIT_2", 4.0, 0, 1, 1, 0, 0, 1);
	
	return 1;
}

YCMD:bittenanim(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "FIGHT_E", "HIT_FIGHTKICK", 4.1, 0, 1, 1, 0, 0, 1);
	
	return 1;
}

YCMD:injured2(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SWAT", "gnstwall_injurd", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:sleep(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "CRACK", "crckidle2", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:funeral(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	
	ApplyAnimation(playerid, "GRAVEYARD", "prst_loopa", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:cry(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "GRAVEYARD", "mrnF_loop", 4.0, 1, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:swat1(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	
	ApplyAnimation(playerid, "SWAT", "swt_breach_01", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:swat2(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SWAT", "swt_breach_02", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:handsup(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	SetPlayerSpecialAction(playerid, 10);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:drunk(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "WALK_DRUNK", 4.0, 1, 1, 1, 1, 1, 1);
	Bit_Let(inanim, playerid);

	return 1;
}
YCMD:crossarms(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 2.0, 0, 1, 1, 1, -1, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:cover(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "cower", 3.0, 1, 0, 0, 0, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:lol(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "RAPPING", "Laugh_01", 3.0, 0, 0, 0, 0, 0, 1);
	
	return 1;
}//VOMIT (playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);s

YCMD:wave(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "endchat_03", 2.0, 0, 0, 0, 0, 0, 1);
	
	return 1;
}

YCMD:washhands(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:slapass(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:crack(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0, 1, 0, 0, 0, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:sit(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:fuckyou(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "fucku", 4.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:taichi(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PARK", "Tai_Chi_Loop", 4.0, 1, 0, 0, 0, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:carry(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "CARRY", "crry_prtial", 2.0, 1, 1, 1, 1, 1, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:dead(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	new animid;
	sscanf(params, "i", animid);
	switch(animid) {
		case 1: ApplyAnimation(playerid, "CRACK", "crckdeth1", 4.0999, 0, 1, 1, 1, 0, 1);
		case 2: ApplyAnimation(playerid, "CRACK", "crckdeth2", 4.0999, 0, 1, 1, 1, 0, 1);
		case 3: ApplyAnimation(playerid, "CRACK", "crckdeth3", 4.0999, 0, 1, 1, 1, 0, 1);
		case 4: ApplyAnimation(playerid, "CRACK", "crckdeth4", 4.0999, 0, 1, 1, 1, 0, 1);
		case 5: ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.0999, 0, 1, 1, 1, 0, 1);
		default: { SCM(playerid, HEX_FADE2, "Usage: /dead [1-5]"); return 1; }
	}
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:seat(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "SEAT_down", 4.0999, 0, 0, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:fall(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "KO_skid_front", 4.0999, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:flip(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "KD_left", 4.0999, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:kiss(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "KISSING", "Playa_Kiss_02", 3.0, 0, 0, 0, 0, 0, 1);

	return 1;
}
YCMD:injured(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 0, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:push(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "GANGS", "shake_cara", 4.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:akick(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "POLICE", "Door_Kick", 4.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:lowbodypush(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "GANGS", "shake_carSH", 4.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:koface(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "KO_shot_face", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:kostomach(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "KO_shot_stom", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:lifejump(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "EV_dive", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:exhausted(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "IDLE_tired", 3.0, 1, 0, 0, 0, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:pimpslap(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "BIKE_elbowL", 4.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:rollfall(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "BIKE_fallR", 4.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:lightcig(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SMOKING", "M_smk_in", 3.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:tapcig(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SMOKING", "M_smk_tap", 3.0, 0, 0, 0, 0, 0, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:box(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "GYMNASIUM", "GYMshadowbox", 4.0, 1, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:lay(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SUNBATHE", "Lay_Bac_in", 3.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:cop(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SWORD", "sword_block", 4.0, 0, 1, 1, 1, 1, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:cop2(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "ped", "ARRESTgun", 4.1, 0, 1, 1, 1, 1,1);
	
	return 1;
}


YCMD:elbow(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "FIGHT_D", "FightD_3", 4.0, 0, 1, 1, 0, 0, 1);

	return 1;
}

YCMD:kneekick(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "FIGHT_D", "FightD_2", 4.0, 0, 1, 1, 0, 0, 1);

	return 1;
}

YCMD:fstance(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "FIGHT_D", "FightD_IDLE", 3.0, 1, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:gpunch(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "FIGHT_B", "FightB_G", 4.0, 0, 0, 0, 0, 0, 1);
	
	return 1;
}

YCMD:airkick(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "FIGHT_C", "FightC_M", 4.0, 0, 1, 1, 0, 0, 1);
	
	return 1;
}

YCMD:gkick(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "FIGHT_D", "FightD_G", 4.0, 0, 0, 0, 0, 0, 1);
	
	return 1;
}

YCMD:lowthrow(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "GRENADE", "WEAPON_throwu", 3.0, 0, 0, 0, 0, 0, 1);

	return 1;
}

YCMD:highthrow(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "GRENADE", "WEAPON_throw", 4.0, 0, 0, 0, 0, 0, 1);
	
	return 1;
}

YCMD:walk(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	new animid;
	sscanf(params, "i", animid);
	switch (animid) {
		case 1: ApplyAnimation(playerid, "PED", "WALK_civi", 4.0, 1, 1, 1, 1, 1, 1);
		case 2: ApplyAnimation(playerid, "PED", "WALK_gang1", 4.0, 1, 1, 1, 1, 1, 1);
		case 3: ApplyAnimation(playerid, "PED", "WALK_gang2", 4.0, 1, 1, 1, 1, 1, 1);
		case 4: ApplyAnimation(playerid, "PED", "WALK_armed", 4.0, 1, 1, 1, 1, 1, 1);
		case 5: ApplyAnimation(playerid, "PED", "WALK_fat", 4.0, 1, 1, 1, 1, 1, 1);
		case 6: ApplyAnimation(playerid, "PED", "WALK_fatold", 4.0, 1, 1, 1, 1, 1, 1);
		case 7: ApplyAnimation(playerid, "PED", "WALK_old", 4.0, 1, 1, 1, 1, 1, 1);
		case 8: ApplyAnimation(playerid, "PED", "WALK_player", 4.0, 1, 1, 1, 1, 1, 1);
		case 9: ApplyAnimation(playerid, "PED", "Player_Sneak", 4.0, 1, 1, 1, 1, 1, 1);
		case 10: ApplyAnimation(playerid, "PED", "WALK_shuffle", 4.0, 1, 1, 1, 1, 1, 1);
		case 11: ApplyAnimation(playerid, "PED", "WALK_Wuzi", 4.0, 1, 1, 1, 1, 1, 1);
		case 12: ApplyAnimation(playerid, "PED", "WOMAN_walkbusy", 4.0, 1, 1, 1, 1, 1, 1);
		case 13: ApplyAnimation(playerid, "PED", "WOMAN_walkfatold", 4.0, 1, 1, 1, 1, 1, 1);
		case 14: ApplyAnimation(playerid, "PED", "WOMAN_walknorm", 4.0, 1, 1, 1, 1, 1, 1);
		case 15: ApplyAnimation(playerid, "PED", "WOMAN_walkold", 4.0, 1, 1, 1, 1, 1, 1);
		case 16: ApplyAnimation(playerid, "PED", "WOMAN_walkpro", 4.0, 1, 1, 1, 1, 1, 1);
		case 17: ApplyAnimation(playerid, "PED", "WOMAN_walksexy", 4.0, 1, 1, 1, 1, 1, 1);
		case 18: ApplyAnimation(playerid, "PED", "WOMAN_walkshop", 4.0, 1, 1, 1, 1, 1, 1);
		default: { SCM(playerid, HEX_FADE2, "Usage: /walk [1-18]"); return 1; }
	}

	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:aim(playerid, params[], help) { //1153 aimindex
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "gang_gunstand", 3.0, 0, 0, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:facepalm(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "MISC", "plyr_shkhead", 3.0, 0, 0, 0, 0, 0, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:aiml(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "MISC", "Hiker_Pose_L", 3.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);
	
	return 1;
}

YCMD:aimr(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "MISC", "Hiker_Pose", 3.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:lean(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "GANGS", "leanIDLE", 2.0, 0, 0, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:lean2(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "MISC", "Plyrlean_loop", 2.0, 0, 1, 1, 1, 0, 1);
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:dance(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(GetPlayerAnimationIndex(playerid) == 745) return SCM(playerid, HEX_RED, "Error: Invalid /dance anim index.");

	new animid;
	sscanf(params, "i", animid);
	switch(animid) {
		case 1: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
		case 2: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
		case 3: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
		case 4: SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
		default: { SCM(playerid, HEX_FADE2, "Usage: /dance [1-4]"); return 1; }
	}
	
	if(Bit_Get(tutorial, playerid))
			SCM(playerid, HEX_FADE2, "Hint: You can do extra moves with the 'WASD' plus 'space' keys. Press 'F' to stop.");
	Bit_Let(inanim, playerid);

	return 1;
}

YCMD:strip(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	switch (params[0]) {
		case 'a', 'A': ApplyAnimation(playerid,"STRIP", "strip_A", 4.1, 1, 1, 1, 1, 1,1 );
		case 'b', 'B': ApplyAnimation(playerid,"STRIP", "strip_B", 4.1, 1, 1, 1, 1, 1,1 );
		case 'c', 'C': ApplyAnimation(playerid,"STRIP", "strip_C", 4.1, 1, 1, 1, 1, 1,1 );
		case 'd', 'D': ApplyAnimation(playerid,"STRIP", "strip_D", 4.1, 1, 1, 1, 1, 1,1 );
		case 'e', 'E': ApplyAnimation(playerid,"STRIP", "strip_E", 4.1, 1, 1, 1, 1, 1,1 );
		case 'f', 'F': ApplyAnimation(playerid,"STRIP", "strip_F", 4.1, 1, 1, 1, 1, 1,1 );
		case 'g', 'G': ApplyAnimation(playerid,"STRIP", "strip_G", 4.1, 1, 1, 1, 1, 1,1 );
		default: { SCM(playerid, HEX_FADE2, "Usage: /strip [A-G]"); return 1; }
	}

	Bit_Let(inanim, playerid);
		
	return 1;
}

YCMD:robcash(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SHOP", "SHP_Rob_GiveCash", 4.1, 0, 0, 0, 0, 0, 1);
	
	return 1;
}

YCMD:robno(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SHOP", "SHP_Rob_React", 4.1, 0, 0, 0, 0, 0, 1);
	
	return 1;
}

YCMD:comehere(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "POLICE", "COPTRAF_COME", 4.1, 0, 0, 0, 0, 0, 1);
	
	return 1;
}

YCMD:riflestand(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "PED", "IDLE_ARMED", 4.1, 0, 1, 1, 1, 0,1 );

	Bit_Let(inanim, playerid);

	return 1;
}


YCMD:rifleup(playerid, params[], help) {
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");

	ApplyAnimation(playerid, "SHOP", "SHP_Gun_Aim", 4.1, 0, 1, 1, 1, 1,1 );

	Bit_Let(inanim, playerid);
	
	return 1;
}

// TEST ANIMS FROM HERE
