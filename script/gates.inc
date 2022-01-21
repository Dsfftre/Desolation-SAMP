/*#if defined _inc_gates
	#undef _inc_gates
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

enum gateInfoEnum {
	gate_sqlid,
	gate_objectid,
	gate_vw,
	gate_int,
	gate_faction,
	gate_city,
	gate_lock,
	gate_autoclose,
	bool:sec_gate,
	Float:gate_distancecheck,
	Float:gate_posx,
	Float:gate_posy,
	Float:gate_posz,
	Float:gate_posfx,
	Float:gate_posfy,
	Float:gate_posfz,
	Float:gate_sec_posx,
	Float:gate_sec_posy,
	Float:gate_sec_posz,
	Float:gate_sec_posfx,
	Float:gate_sec_posfy,
	Float:gate_sec_posfz
}
new gateInfo[MAX_GATES+1][gateInfoEnum];

new Iterator:MovingGates<MAX_GATES+1>;

hook OnGameModeInit() {
	LoadGates();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadGates() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `gates` WHERE state > 0");
	inline LoadGateData() {
		if(!cache_num_rows()) {
			print("No gates found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", gateInfo[i+1][gate_sqlid]);
			cache_get_value_int(i, "objectid", gateInfo[i+1][gate_objectid]);
			cache_get_value_int(i, "virtualworld", gateInfo[i+1][gate_vw]);
			cache_get_value_int(i, "interior", gateInfo[i+1][gate_int]);
			cache_get_value_int(i, "factionId", gateInfo[i+1][gate_faction]);
			cache_get_value_int(i, "cityId", gateInfo[i+1][gate_city]);
			cache_get_value_int(i, "glock", gateInfo[i+1][gate_lock]);
			cache_get_value_int(i, "autoclose", gateInfo[i+1][gate_autoclose]);
			cache_get_value_float(i, "distancecheck", gateInfo[i+1][gate_distancecheck]);

			//first position of gate

			cache_get_value_float(i, "posx", gateInfo[i+1][gate_posx]);
			cache_get_value_float(i, "posy", gateInfo[i+1][gate_posy]);
			cache_get_value_float(i, "posz", gateInfo[i+1][gate_posz]);

			cache_get_value_float(i, "posfx", gateInfo[i+1][gate_posfx]);
			cache_get_value_float(i, "posfy", gateInfo[i+1][gate_posfy]);
			cache_get_value_float(i, "posfz", gateInfo[i+1][gate_posfz]);

			// second position (after /gates used)

			cache_get_value_float(i, "sec_posx", gateInfo[i+1][gate_sec_posx]);
			cache_get_value_float(i, "sec_posy", gateInfo[i+1][gate_sec_posy]);
			cache_get_value_float(i, "sec_posz", gateInfo[i+1][gate_sec_posz]);

			cache_get_value_float(i, "sec_posfx", gateInfo[i+1][gate_sec_posfx]);
			cache_get_value_float(i, "sec_posfy", gateInfo[i+1][gate_sec_posfy]);
			cache_get_value_float(i, "sec_posfz", gateInfo[i+1][gate_sec_posfz]);

			new bool:milkgate = false;
			if(gateInfo[i+1][gate_objectid] == 19379)
				milkgate = true;

			gateInfo[i+1][gate_objectid] = CreateDynamicObject(gateInfo[i+1][gate_objectid], gateInfo[i+1][gate_posx], gateInfo[i+1][gate_posy], gateInfo[i+1][gate_posz], gateInfo[i+1][gate_posfx], gateInfo[i+1][gate_posfy], gateInfo[i+1][gate_posfz], gateInfo[i+1][gate_vw], gateInfo[i+1][gate_int]);
			
			if(milkgate)
				SetDynamicObjectMaterial(gateInfo[i+1][gate_objectid], 0, 16640, "a51", "sw_olddrum1", 0x00000000);

			Iter_Add(MovingGates, i+1);
		}
		printf("%d gates have been created.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadGateData, sql);
	return 1;
}

YCMD:gates(playerid, params[], help) {
    if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");

	new bool:bypass = false;
	new bool:foundgate = false;

	foreach(new i:MovingGates) {
		if(IsValidDynamicObject(gateInfo[i][gate_objectid])) {
			if(GetPlayerInterior(playerid) == gateInfo[i][gate_int] && GetPlayerVirtualWorld(playerid) == gateInfo[i][gate_vw]) {
				if( (!gateInfo[i][sec_gate] && IsPlayerInRangeOfPoint(playerid, gateInfo[i][gate_distancecheck], gateInfo[i][gate_posx], gateInfo[i][gate_posy], gateInfo[i][gate_posz])) || (gateInfo[i][sec_gate] && IsPlayerInRangeOfPoint(playerid, gateInfo[i][gate_distancecheck], gateInfo[i][gate_sec_posx], gateInfo[i][gate_sec_posy], gateInfo[i][gate_sec_posz]) )) {
					if(Group_GetPlayer(g_AdminDuty, playerid)) bypass = true;
					else if(gateInfo[i][gate_lock]) bypass = true;
					else if(faction[playerid] > 0 && faction[playerid] == gateInfo[i][gate_faction]) bypass = true;
					else if(city[playerid] > 0 && city[playerid] == gateInfo[i][gate_city]) bypass = true;
					if(!bypass) return SCM(playerid, HEX_RED, "Error: You don't have a key to this gate.");
					if(gateInfo[i][sec_gate]) {
						gateInfo[i][sec_gate] = false;
						MoveDynamicObject(gateInfo[i][gate_objectid], gateInfo[i][gate_posx], gateInfo[i][gate_posy], gateInfo[i][gate_posz], 2.0, gateInfo[i][gate_posfx], gateInfo[i][gate_posfy], gateInfo[i][gate_posfz]);
					}
					else {
						gateInfo[i][sec_gate] = true;
						MoveDynamicObject(gateInfo[i][gate_objectid], gateInfo[i][gate_sec_posx], gateInfo[i][gate_sec_posy], gateInfo[i][gate_sec_posz], 2.0, gateInfo[i][gate_sec_posfx], gateInfo[i][gate_sec_posfy], gateInfo[i][gate_sec_posfz]);
					}
					if(gateInfo[i][gate_autoclose])
						defer GateAutoCloseDelay(i);
					foundgate = true;

					
				}
			}
		}
	}
	if(!foundgate)
		SCM(playerid, HEX_RED, "Error: You are not near any gates.");
	return 1;
}

timer GateAutoCloseDelay[10000](gateid)
{
    if(gateInfo[gateid][sec_gate]) {
		gateInfo[gateid][sec_gate] = false;
		MoveDynamicObject(gateInfo[gateid][gate_objectid], gateInfo[gateid][gate_posx], gateInfo[gateid][gate_posy], gateInfo[gateid][gate_posz], 2.0, gateInfo[gateid][gate_posfx], gateInfo[gateid][gate_posfy], gateInfo[gateid][gate_posfz]);
	}
	else {
		gateInfo[gateid][sec_gate] = true;
		MoveDynamicObject(gateInfo[gateid][gate_objectid], gateInfo[gateid][gate_sec_posx], gateInfo[gateid][gate_sec_posy], gateInfo[gateid][gate_sec_posz], 2.0, gateInfo[gateid][gate_sec_posfx], gateInfo[gateid][gate_sec_posfy], gateInfo[gateid][gate_sec_posfz]);
	}
}