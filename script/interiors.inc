/*#if defined _inc_interiors
	#undef _inc_interiors
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>


hook OnGameModeInit() {
	LoadEntrances();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadEntrances() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `interiors` WHERE state > 0 LIMIT %d", MAX_INTERIORS);
	inline LoadInteriorData() {
		if(!cache_num_rows()) {
			print("No interiors found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", IntInfo[i][sqlid]);
			cache_get_value(i, "name", IntInfo[i][intname]);
			cache_get_value_int(i, "playerId", IntInfo[i][player]);
			cache_get_value_int(i, "factionId", IntInfo[i][factionId]);
			cache_get_value_int(i, "cityId", IntInfo[i][cityId]);
			cache_get_value_int(i, "storeId", IntInfo[i][storeId]);

			cache_get_value_float(i, "intx", IntInfo[i][intx]);
			cache_get_value_float(i, "inty", IntInfo[i][inty]);
			cache_get_value_float(i, "intz", IntInfo[i][intz]);
			cache_get_value_float(i, "intf", IntInfo[i][intf]);
			cache_get_value_int(i, "intvw", IntInfo[i][intvw]);
			cache_get_value_int(i, "intint", IntInfo[i][intint]);

			cache_get_value_float(i, "outx", IntInfo[i][outx]);
			cache_get_value_float(i, "outy", IntInfo[i][outy]);
			cache_get_value_float(i, "outz", IntInfo[i][outz]);
			cache_get_value_float(i, "outf", IntInfo[i][outf]);
			cache_get_value_int(i, "outvw", IntInfo[i][outvw]);
			cache_get_value_int(i, "outint", IntInfo[i][outint]);

			cache_get_value_int(i, "locked", IntInfo[i][locked]);

			Iter_Add(Entrances, i);

			if(IntInfo[i][storeId] == 0) {
				IntInfo[i][checkpoint_out] = CreateDynamicCP(IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], CHECKPOINT_SIZE, IntInfo[i][outvw], IntInfo[i][outint], -1, CHECKPOINT_RANGE);
			}
			else if(IntInfo[i][storeId] == -1) {
				IntInfo[i][pickup_out] = CreateDynamicPickup(LOOTSTORE_PICKUP, 2, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], IntInfo[i][outvw], IntInfo[i][outint], -1);
			}
			else {
				IntInfo[i][pickup_out] = CreateDynamicPickup(STORE_PICKUP, 2, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], IntInfo[i][outvw], IntInfo[i][outint], -1);
				switch(IntInfo[i][storeId]) {
					case 2: CreateDynamicMapIcon(IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], 18, 0, IntInfo[i][outvw], IntInfo[i][outint], -1, 1000.0, MAPICON_GLOBAL, -1, 0);
					case 3: CreateDynamicMapIcon(IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], 22, 0, IntInfo[i][outvw], IntInfo[i][outint], -1, 1000.0, MAPICON_GLOBAL, -1, 0);
				}
			}
		}
		printf("%d interiors loaded.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadInteriorData, sql);
	return 1;
}

LoadNewEntrances() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `interiors` WHERE state = 69");
	inline LoadNewInteriorData() {
		if(!cache_num_rows()) {
			print("No interiors found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			new j = -1;
			for(;++j<MAX_INTERIORS;) {
				if(IntInfo[j][sqlid] == 0 && IntInfo[j][intx] == 0.0) {

					cache_get_value_int(i, "id", IntInfo[j][sqlid]);
					cache_get_value(i, "name", IntInfo[j][intname]);
					cache_get_value_int(i, "playerId", IntInfo[j][player]);
					cache_get_value_int(i, "factionId", IntInfo[j][factionId]);
					cache_get_value_int(i, "cityId", IntInfo[j][cityId]);
					cache_get_value_int(i, "storeId", IntInfo[j][storeId]);

					cache_get_value_float(i, "intx", IntInfo[j][intx]);
					cache_get_value_float(i, "inty", IntInfo[j][inty]);
					cache_get_value_float(i, "intz", IntInfo[j][intz]);
					cache_get_value_float(i, "intf", IntInfo[j][intf]);
					cache_get_value_int(i, "intvw", IntInfo[j][intvw]);
					cache_get_value_int(i, "intint", IntInfo[j][intint]);

					cache_get_value_float(i, "outx", IntInfo[j][outx]);
					cache_get_value_float(i, "outy", IntInfo[j][outy]);
					cache_get_value_float(i, "outz", IntInfo[j][outz]);
					cache_get_value_float(i, "outf", IntInfo[j][outf]);
					cache_get_value_int(i, "outvw", IntInfo[j][outvw]);
					cache_get_value_int(i, "outint", IntInfo[j][outint]);

					cache_get_value_int(i, "locked", IntInfo[j][locked]);

					Iter_Add(Entrances, j);

					if(IntInfo[j][storeId] == 0) {
						IntInfo[j][checkpoint_out] = CreateDynamicCP(IntInfo[j][outx], IntInfo[j][outy], IntInfo[j][outz], CHECKPOINT_SIZE, IntInfo[j][outvw], IntInfo[j][outint], -1, CHECKPOINT_RANGE);
					}
					else if(IntInfo[j][storeId] == -1) {
						IntInfo[j][pickup_out] = CreateDynamicPickup(LOOTSTORE_PICKUP, 2, IntInfo[j][outx], IntInfo[j][outy], IntInfo[j][outz], IntInfo[j][outvw], IntInfo[j][outint], -1);
					}
					else {
						IntInfo[j][pickup_out] = CreateDynamicPickup(STORE_PICKUP, 2, IntInfo[j][outx], IntInfo[j][outy], IntInfo[j][outz], IntInfo[j][outvw], IntInfo[j][outint], -1);
						switch(IntInfo[i][storeId]) {
							case 2: CreateDynamicMapIcon(IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], 18, 0, IntInfo[i][outvw], IntInfo[i][outint], -1, 1000.0, MAPICON_GLOBAL, -1, 0);
							case 3: CreateDynamicMapIcon(IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz], 22, 0, IntInfo[i][outvw], IntInfo[i][outint], -1, 1000.0, MAPICON_GLOBAL, -1, 0);
						}
					}
					break;
					
				}
			}
		}
		printf("%d new interior(s) loaded.", i);
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `state` = 1 WHERE state = 69");
		mysql_tquery(g_SQL, sql, "", "");
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadNewInteriorData, sql);
	
	return 1;
}

YCMD:createinterior(playerid, params[], help) {
	if(adminlevel[playerid] < 4) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 4 admins.");

	new intiname[64],
		Float:interiorpos[4],
		vw,
		int;

    if(sscanf(params,"s[64]", intiname)) return SCM(playerid, HEX_FADE2, "Usage: /createinterior [name] (Max 64 characters.)");

	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

    GetPlayerPos(playerid, interiorpos[0], interiorpos[1], interiorpos[2]);
    GetPlayerFacingAngle(playerid, interiorpos[3]);

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `interiors` (`name`, `outx`, `outy`, `outz`, `outf`, `outvw`, `outint`, `state`) VALUES ('%e', '%f', '%f', '%f', '%f', '%d', '%d', '69')", intiname, interiorpos[0], interiorpos[1], interiorpos[2], interiorpos[3], vw, int);
	mysql_tquery(g_SQL, sql, "", "");	

	SCM(playerid, HEX_FADE2, "Interior added to the database! Loading...");
	printf("interior created %s", intiname);

	LoadNewEntrances();
	return 1;
}

hook OnPlayerPickUpDynPickup(playerid, pickupid) {
	//new i = -1;
	//for(;++i<MAX_INTERIORS;) {
	foreach(new i:Entrances) {
		if(IntInfo[i][pickup_out] == pickupid) {
			new gametext[256];
			format(gametext, sizeof gametext, "%s~n~~p~PRESS ~k~~VEHICLE_ENTER_EXIT~ TO ENTER", IntInfo[i][intname]);
			GameTextForPlayer(playerid, gametext, 4000, 3);
			if(Group_GetPlayer(g_AdminDuty, playerid)) {
				SFM(playerid, HEX_YELLOW, "[Store info] [sqlid:%d] [name:%s] [owner:(sql%d) %s] [faction:%d] [city:%d] [store:%d] [lock:%d]", IntInfo[i][sqlid], IntInfo[i][intname], IntInfo[i][player], GetSQLCharname(IntInfo[i][player]), IntInfo[i][factionId], IntInfo[i][cityId], IntInfo[i][storeId], IntInfo[i][locked]);
			}
			return Y_HOOKS_BREAK_RETURN_1;
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid) {
	//new i = -1;
	//for(;++i<MAX_INTERIORS;) {
	foreach(new i:Entrances) {
		if(IntInfo[i][checkpoint_out] == checkpointid) {
			SFM(playerid, HEX_GREEN, "Safehouse %s %d.", IntInfo[i][intname], IntInfo[i][sqlid]);
			if(IntInfo[i][player] == 0 && IntInfo[i][cityId] == 0 && IntInfo[i][factionId] == 0) SCM(playerid, HEX_FADE2, "You are able to /claim this safehouse!");
			SCM(playerid, HEX_FADE2, "Commands: /claim, /abandon, /ddo, /ds, press F (by default) to enter.");
			if(Group_GetPlayer(g_AdminDuty, playerid)) {
				SFM(playerid, HEX_YELLOW, "[Safehouse info] [sqlid:%d] [name:%s] [owner:(sql%d) %s] [faction:%d] [city:%d] [store:%d] [lock:%d]", IntInfo[i][sqlid], IntInfo[i][intname], IntInfo[i][player], GetSQLCharname(IntInfo[i][player]), IntInfo[i][factionId], IntInfo[i][cityId], IntInfo[i][storeId], IntInfo[i][locked]);
			}
			return Y_HOOKS_BREAK_RETURN_1;
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if((newkeys & KEY_YES) && !(oldkeys & KEY_YES)) 
	{
		if(Bit_Get(frozen, playerid) && !Bit_Get(dead, playerid)) 
		{
			KillTimer(SpawnFreezeTimer[playerid]);
			SpawnFreeze(playerid);
			return Y_HOOKS_BREAK_RETURN_1;
		}
	}
	//if((newkeys & KEY_SECONDARY_ATTACK) && !(oldkeys & KEY_SECONDARY_ATTACK) && !(newkeys & KEY_AIM) && !(oldkeys & KEY_AIM)) {
	if((newkeys & KEY_SECONDARY_ATTACK) && !(oldkeys & KEY_SECONDARY_ATTACK) && GetPlayerTargetPlayer(playerid) == INVALID_PLAYER_ID) {
		if(Bit_Get(dead, playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
		foreach(new i:Entrances) {
			if(IntInfo[i][outint] == GetPlayerInterior(playerid) && IntInfo[i][outvw] == GetPlayerVirtualWorld(playerid) && IsPlayerInRangeOfPoint(playerid, CHECK_RANGE, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz])) {
				//printf("DEBUG: -- 1");
				if(IntInfo[i][locked])
					SCM(playerid, HEX_FADE2, "The door is locked.");
				else {
					if(IntInfo[i][intint] != 0 || IntInfo[i][intvw] != 0) {
						TogglePlayerControllable(playerid, false);
						Bit_Let(frozen, playerid);
						SpawnFreezeTimer[playerid] = SetTimerEx("SpawnFreeze", GetPlayerPing(playerid)*20+2000, 0, "%i", playerid);
						//printf("DEBUG: -- 2");
					}
					else {
						TogglePlayerControllable(playerid,false);
						Bit_Let(frozen, playerid);
						SpawnFreezeTimer[playerid] = SetTimerEx("SpawnFreeze", GetPlayerPing(playerid)*10+100, 0, "%i", playerid);
					}
					
					SetPlayerVirtualWorld(playerid, IntInfo[i][intvw]);
					SetPlayerInterior(playerid, IntInfo[i][intint]);
					SetPlayerPos(playerid, IntInfo[i][intx], IntInfo[i][inty], IntInfo[i][intz]);
					SetPlayerFacingAngle(playerid, IntInfo[i][intf]);
					FixSpectators(playerid);

					ChangeMaskVW(playerid);
					//printf("DEBUG: -- 3");
					if(IntInfo[i][storeId] == -1 && Bit_Get(tutorial, playerid))
						SCM(playerid, HEX_FADE2, "Hint: Crouch over an item and press N (by default) to loot it.");
					else if(IntInfo[i][storeId] == 2 && Bit_Get(tutorial, playerid))
						SCM(playerid, HEX_FADE2, "Hint: Type /shop to open the blackmarket's menu.");
					else if(IntInfo[i][storeId] == 3 && Bit_Get(tutorial, playerid))
						SCM(playerid, HEX_FADE2, "Hint: Type /shop to open the pharmacy's menu.");
					else if(IntInfo[i][storeId] == 0 && Bit_Get(tutorial, playerid) && IntInfo[i][factionId] == faction[playerid])
						SCM(playerid, HEX_FADE2, "Hint: Type /setspawn to spawn in your faction's safehouse.");
					else if(IntInfo[i][storeId] == 0 && Bit_Get(tutorial, playerid))
						SCM(playerid, HEX_FADE2, "Hint: You can get your own safehouse, request it on the forum!");
					return Y_HOOKS_BREAK_RETURN_1;
				}					
			}
			else if(IntInfo[i][intint] == GetPlayerInterior(playerid) && IntInfo[i][intvw] == GetPlayerVirtualWorld(playerid) && IsPlayerInRangeOfPoint(playerid, CHECK_RANGE, IntInfo[i][intx], IntInfo[i][inty], IntInfo[i][intz])) {
				if(IntInfo[i][locked])
					SCM(playerid, HEX_FADE2, "The door is locked.");
				else {
					
					SetPlayerVirtualWorld(playerid, IntInfo[i][outvw]);
					SetPlayerInterior(playerid, IntInfo[i][outint]);
					SetPlayerPos(playerid, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz]);
					SetPlayerFacingAngle(playerid, IntInfo[i][outf]);
					FixSpectators(playerid);
					
					ChangeMaskVW(playerid);
					if(IntInfo[i][outint] != 0 || IntInfo[i][outvw] != 0) {
						TogglePlayerControllable(playerid,false);
						Bit_Let(frozen, playerid);
						SpawnFreezeTimer[playerid] = SetTimerEx("SpawnFreeze", GetPlayerPing(playerid)*20+2000, 0, "%i", playerid);
					}
					else {
						TogglePlayerControllable(playerid,false);
						Bit_Let(frozen, playerid);
						SpawnFreezeTimer[playerid] = SetTimerEx("SpawnFreeze", GetPlayerPing(playerid)*10+100, 0, "%i", playerid);
					}
					return Y_HOOKS_BREAK_RETURN_1;
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:lock(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	

	if(!InteriorLock(playerid))
		SCM(playerid, HEX_RED, "Error: You cannot use any locks here.");
	return 1;
}


YCMD:setspawn(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	

	foreach(new i:Entrances)
		if(IntInfo[i][player] == CharacterSQL[playerid] || Group_GetPlayer(g_AdminDuty, playerid) || (IntInfo[i][factionId] == faction[playerid] &&  faction[playerid] > 0) || HasDoorKey(playerid, i))
			if(IntInfo[i][outint] == GetPlayerInterior(playerid) && IntInfo[i][outvw] == GetPlayerVirtualWorld(playerid) && IsPlayerInRangeOfPoint(playerid, CHECK_RANGE, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz])) 
			{
				new check = SetPlayerSpawnInterior(playerid, IntInfo[i][sqlid]);
				if(check) SCM(playerid, HEX_FADE2, "You will spawn here next time you use /respawnme.");
				else SCM(playerid, HEX_RED, "Error: Something went wrong.");
				return 1;
			}

	SCM(playerid, HEX_RED, "Error: You need to be outside at an interior door where you have access (via /lock).");
	return 1;
}

SetPlayerSpawnInterior(playerid, interiors_sqlid) {
	if(IsPlayerConnected(playerid) && !IsPlayerNPC(playerid)) {
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `spawnInteriors` = %d WHERE id = %d LIMIT 1", interiors_sqlid, CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
		return 1;
	}
	return 0;
}

InteriorLock(playerid) {
	if(IsPlayerInAnyVehicle(playerid)) return 0;
	foreach(new i:Entrances) {
		if(IntInfo[i][player] == CharacterSQL[playerid] || Group_GetPlayer(g_AdminDuty, playerid) || (IntInfo[i][factionId] == faction[playerid] &&  faction[playerid] > 0) || HasDoorKey(playerid, i)) {
			if(IntInfo[i][outint] == GetPlayerInterior(playerid) && IntInfo[i][outvw] == GetPlayerVirtualWorld(playerid) && IsPlayerInRangeOfPoint(playerid, CHECK_RANGE, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz])) {
				if(IntInfo[i][locked]) {
					IntInfo[i][locked] = 0;
					GameTextForPlayer(playerid, "~y~Property ~g~unlocked", 2500, 4);
				}
				else {
					IntInfo[i][locked] = 1;
					GameTextForPlayer(playerid, "~y~Property ~r~locked", 2500, 4);
				}
				mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `locked` = '%d' WHERE id = '%d' LIMIT 1", IntInfo[i][locked], IntInfo[i][sqlid]);
				mysql_tquery(g_SQL, sql, "", "");
				PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
				return 1;					
			}
			if(IntInfo[i][intint] == GetPlayerInterior(playerid) && IntInfo[i][intvw] == GetPlayerVirtualWorld(playerid) && IsPlayerInRangeOfPoint(playerid, CHECK_RANGE, IntInfo[i][intx], IntInfo[i][inty], IntInfo[i][intz])) {
				if(IntInfo[i][locked]) {
					IntInfo[i][locked] = 0;
					GameTextForPlayer(playerid, "~y~Property ~g~unlocked", 2500, 4);
				}
				else {
					IntInfo[i][locked] = 1;
					GameTextForPlayer(playerid, "~y~Property ~r~locked", 2500, 4);
				}
				mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `locked` = '%d' WHERE id = '%d' LIMIT 1", IntInfo[i][locked], IntInfo[i][sqlid]);
				mysql_tquery(g_SQL, sql, "", "");
				PlayerPlaySound(playerid, 24600, 0.0, 0.0, 0.0);
				return 1;
			}
		}
	}
	return 0;
}

HasDoorKey(playerid, entrance) {

	mysql_format(g_SQL, sql, sizeof sql, "SELECT id FROM `player_keys` WHERE playerId = %d AND interiorsId = %d AND state > 0 LIMIT 1", CharacterSQL[playerid], IntInfo[entrance][sqlid]);

	new Cache:result = mysql_query(g_SQL, sql);
	if(cache_num_rows()) {
		cache_delete(result);
		return 1;
	}
	
	return 0;
}


forward SpawnFreeze(playerid);
public SpawnFreeze(playerid) {
	if(Bit_Get(frozen, playerid) && !Bit_Get(dead, playerid)) {
		TogglePlayerControllable(playerid,true);
		Bit_Vet(frozen, playerid);
	}
	return 1;
}

YCMD:ddo(playerid, params[], help) {
	new text[256],string[256];
	if(sscanf(params, "s[256]", text)) return SCM(playerid, HEX_FADE2, "Usage: /ddo [action]");
	format(string, sizeof(string), "[Door] * %s (( %s ))",text,PlayerName(playerid,false));

	foreach(new i:Entrances) {
		if(GetPlayerInterior(playerid) == IntInfo[i][outint] && GetPlayerVirtualWorld(playerid) == IntInfo[i][outvw]) {
			if(IsPlayerInRangeOfPoint(playerid, 3.0, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz])) {
				ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, string);

				foreach(new j:Player) {
					if(GetPlayerInterior(j) == IntInfo[i][intint] && GetPlayerVirtualWorld(j) == IntInfo[i][intvw]) {
						if(IsPlayerInRangeOfPoint(j, NAMETAG_DISTANCE*3, IntInfo[i][intx], IntInfo[i][inty], IntInfo[i][intz])) {
							SCM(j, HEX_PURPLE, string);
						}
					}
				}
				return 1;
			}
		}

	}

	SCM(playerid, HEX_RED, "Error: There is no door close to you.");
	
	return 1;
}

///doorcheck, /knock, /ddo, /ds

YCMD:ds(playerid, params[], help) {
	new text[256],string[256];
	if(sscanf(params, "s[256]", text)) return SCM(playerid, HEX_FADE2, "Usage: /ds [message]");
	format(string, sizeof(string), "[Door] * %s (( %s ))",text,PlayerName(playerid,false));

	foreach(new i:Entrances) {
		if(GetPlayerInterior(playerid) == IntInfo[i][outint] && GetPlayerVirtualWorld(playerid) == IntInfo[i][outvw]) {
			if(IsPlayerInRangeOfPoint(playerid, 3.0, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz])) {
				WhiteProxMSG(NAMETAG_DISTANCE*2, playerid, string);

				foreach(new j:Player) {
					if(GetPlayerInterior(j) == IntInfo[i][intint] && GetPlayerVirtualWorld(j) == IntInfo[i][intvw]) {
						if(IsPlayerInRangeOfPoint(j, NAMETAG_DISTANCE*3, IntInfo[i][intx], IntInfo[i][inty], IntInfo[i][intz])) {
							SCM(j, HEX_WHITE, string);
						}
					}
				}
				return 1;
			}
		}

	}

	SCM(playerid, HEX_RED, "Error: There is no door close to you.");
	
	return 1;
}


YCMD:claim(playerid, params[], help) {

	foreach(new j:Entrances) {
		if(IntInfo[j][player] == CharacterSQL[playerid]) {
			return SCM(playerid, HEX_RED, "Error: You already have a safehouse. Use /abandon to drop it.");
		}
	}

	foreach(new i:Entrances) {
		if(GetPlayerInterior(playerid) == IntInfo[i][outint] && GetPlayerVirtualWorld(playerid) == IntInfo[i][outvw]) {
			if(IsPlayerInRangeOfPoint(playerid, 3.0, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz])) {

				if(IntInfo[i][storeId] != 0) return SCM(playerid, HEX_RED, "Error: This interior is not a safehouse."); 
				if(IntInfo[i][player] != 0) return SCM(playerid, HEX_RED, "Error: This interior is already claimed."); 
				if(IntInfo[i][factionId] != 0 && IntInfo[i][factionId] != faction[playerid]) return SCM(playerid, HEX_RED, "Error: You cannot claim this interior due faction restrictions."); 
				if(IntInfo[i][cityId] != 0 && IntInfo[i][cityId] != city[playerid]) return SCM(playerid, HEX_RED, "Error: You cannot claim this interior due faction restrictions."); 
				
				IntInfo[i][player] = CharacterSQL[playerid];

				mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `playerId` = '%d' WHERE id = '%d' LIMIT 1", CharacterSQL[playerid], IntInfo[i][sqlid]);
				mysql_tquery(g_SQL, sql, "", "");

				new string[256];
				format(string, sizeof string, "[LOG]: %s has claimed interior entrance %d.", PlayerName(playerid), IntInfo[i][sqlid]);
				SendAdminMessage(HEX_YELLOW, string, true);

				SCM(playerid, HEX_YELLOW, "You claimed this interior!");

				return 1;
			}
		}
	}

	SCM(playerid, HEX_RED, "Error: There is no door close to you.");
	
	return 1;
}

YCMD:abandon(playerid, params[], help) {

	foreach(new i:Entrances) {
		if(GetPlayerInterior(playerid) == IntInfo[i][outint] && GetPlayerVirtualWorld(playerid) == IntInfo[i][outvw]) {
			if(IsPlayerInRangeOfPoint(playerid, 3.0, IntInfo[i][outx], IntInfo[i][outy], IntInfo[i][outz])) {

				if(IntInfo[i][player] != CharacterSQL[playerid]) return SCM(playerid, HEX_RED, "Error: You are not the owner of this interior."); 
				
				IntInfo[i][player] = 0;

				mysql_format(g_SQL, sql, sizeof sql, "UPDATE `interiors` SET `playerId` = '%d' WHERE id = '%d' LIMIT 1", 0, IntInfo[i][sqlid]);
				mysql_tquery(g_SQL, sql, "", "");

				EmptyHouseKeys(IntInfo[i][sqlid]);

				new string[256];
				format(string, sizeof string, "[LOG]: %s has abandoned interior entrance %d.", PlayerName(playerid), IntInfo[i][sqlid]);
				SendAdminMessage(HEX_YELLOW, string, true);

				return 1;
			}
		}
	}

	SCM(playerid, HEX_RED, "Error: There is no door close to you.");
	
	return 1;
}

EmptyHouseKeys(houseid) {

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_keys` SET `state` = '0' WHERE interiorsId = '%d' LIMIT 1", houseid);
	mysql_tquery(g_SQL, sql, "", "");

	return 1;
}

YCMD:grantdoorkey(playerid, params[], help) {

	if(!SpamPrevent(playerid)) return 1;

	new houseid, targetid;

	if(sscanf(params, "rd", targetid, houseid)) return SCM(playerid, HEX_FADE2, "Usage: /grantdoorkey [id] [safehouse] (Hint: Walk to a door to see the safehouse's ID in the address.)");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "dd", targetid, houseid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(playerid == targetid) return SCM(playerid, HEX_RED, "[Desolation]: You cannot grant yourself keys.");

	new home = -1;
	foreach(new i:Entrances) {
		if(IntInfo[i][player] == CharacterSQL[playerid]) {
			if(IntInfo[i][sqlid] == houseid) {
				home = i;
				break;
			}
		}
	}

	if(home == -1) return SCM(playerid, HEX_RED, "Error: You do not own a safehouse with that ID. Walk to a door to see the safehouse's ID in the address.");

	new Float:pos[3];
	GetPlayerPos(targetid, pos[0],pos[1],pos[2]);
	if(!IsPlayerInRangeOfPoint(playerid, 6.0, pos[0],pos[1],pos[2]) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");


    mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `player_keys` (`playerId`, `interiorsId`) VALUES ('%d', '%d')", CharacterSQL[targetid], houseid);
	mysql_tquery(g_SQL, sql, "", "");

	SFM(playerid, HEX_YELLOW, "You have given %s a key to safehouse %d.", PlayerName(targetid), houseid);
	SFM(targetid, HEX_YELLOW, "You have recieved a key from %s to safehouse %d.", PlayerName(playerid), houseid);

	return 1;
}