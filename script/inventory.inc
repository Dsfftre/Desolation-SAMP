/*#if defined _inc_inventory
	#undef _inc_inventory
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>



hook OnGameModeInit() {
	SpawnLoot();
	Command_AddAltNamed("inventory", "inv");
	Command_AddAltNamed("inventory", "items");
	Command_AddAltNamed("inventory", "bag");

	Command_AddAltNamed("repair", "fix");
	Command_AddAltNamed("fill", "fuel");
	Command_AddAltNamed("fill", "refuel");

	return Y_HOOKS_CONTINUE_RETURN_1;
}

SpawnLoot() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `loot` WHERE state > 0 LIMIT %d", MAX_LOOT);
	inline LoadInventoryData() 
	{
		if(!cache_num_rows()) 
		{
			print("Error: Loot table is empty.");
			@return 1;
		}
		new i = -1;
		for(;++i<cache_num_rows();) 
		{
			cache_get_value_int(i, "itemlistCategory", LootInfo[i][l_category]);
			cache_get_value_int(i, "id", LootInfo[i][sqlid]);
			cache_get_field_name(i, "name", LootInfo[i][Name]); 
			cache_get_value_float(i, "posx", LootInfo[i][lootpos][0]);
			cache_get_value_float(i, "posy", LootInfo[i][lootpos][1]);
			cache_get_value_float(i, "posz", LootInfo[i][lootpos][2]);
			cache_get_value_int(i, "interior", LootInfo[i][interior]);
			cache_get_value_int(i, "virtualworld", LootInfo[i][l_virtualworld]);
			CreateLoot(i, LootInfo[i][l_category]);			
		}
		printf("%d loots have been created.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadInventoryData, sql);
	return 1;
}

CreateLoot(lootid, category) {
	if(category == 3 || category == 4) 
	{
		if(!random(5))
			mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `itemlist` WHERE state > 0 AND category = %d AND rare = 1 ORDER BY RAND() LIMIT 1", category);
		else if(!random(10))
			mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `itemlist` WHERE state > 0 AND category = %d AND rare = 2 ORDER BY RAND() LIMIT 1", category);
		else
			mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `itemlist` WHERE state > 0 AND category = %d AND rare = 0 ORDER BY RAND() LIMIT 1", category);
	}
	else
		mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `itemlist` WHERE state > 0 AND category = %d AND rare = 0 ORDER BY RAND() LIMIT 1", category);
	
	inline LoadLootData() 
	{
		new	Float:o_pos[3],
			Float:o_rot[3];
		if(!cache_num_rows())
			printf("DEBUG !cache_num_rows @ Createloot lootid %d", lootid);
		
		cache_get_value_int(0, "id", LootInfo[lootid][itemlistId]);
		cache_get_value_int(0, "object", LootInfo[lootid][object]);

		if(LootInfo[lootid][itemlistId] == 0) 
		{
			printf("DEBUG ITEMLISTID == 0 @ lootid %d category %d", lootid, category);
		}

		cache_get_value_float(0, "posx", o_pos[0]);
		cache_get_value_float(0, "posy", o_pos[1]);
		cache_get_value_float(0, "posz", o_pos[2]);

		cache_get_value_float(0, "rotx", o_rot[0]);
		cache_get_value_float(0, "roty", o_rot[1]);
		cache_get_value_float(0, "rotz", o_rot[2]);

		Bit_Let(lootable, lootid);

		LootInfo[lootid][object] = CreateDynamicObject(LootInfo[lootid][object], LootInfo[lootid][lootpos][0]+o_pos[0], LootInfo[lootid][lootpos][1]+o_pos[1], LootInfo[lootid][lootpos][2]+o_pos[2], o_rot[0], o_rot[1], o_rot[2], LootInfo[lootid][l_virtualworld], LootInfo[lootid][interior]);
		//new LootStr[20];
		//format(LootStr, sizeof(LootStr), "%s", LootInfo[lootid][Name]);
		//LootInfo[lootid][LabelID] = CreateDynamic3DTextLabel(LootStr, -1, LootInfo[lootid][lootpos][0], LootInfo[lootid][lootpos][1], LootInfo[lootid][lootpos][2], 100, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, -1, 10.0);
	}
	MySQL_TQueryInline(g_SQL, using inline LoadLootData, sql);	
	return 1;
}


CountPlayerItem(playerid, itemid, bool:all = true) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_items` WHERE itemId = %d AND playerId = %d AND state = 1", itemid, CharacterSQL[playerid]);
	new Cache:result = mysql_query(g_SQL, sql);
	
	if(!cache_num_rows()) {
		return 0;
	}

	new i = -1;
	new check_amount = 0;
	new returnval = 0;
	if(all) {
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "amount", check_amount);
			returnval += check_amount;		
		}
	}
	else {
		cache_get_value_int(0, "amount", check_amount);
		returnval += check_amount;		
	}
	cache_delete(result);
	return returnval;	
}

CountStorageItem(storageid, itemid, bool:all = true) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_items` WHERE itemId = %d AND storageId = %d AND state = 2", itemid, storageid);
	new Cache:result = mysql_query(g_SQL, sql);
	
	if(!cache_num_rows()) {
		return 0;
	}

	new i = -1;
	new check_amount = 0;
	new returnval = 0;
	if(all) {
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "amount", check_amount);
			returnval += check_amount;		
		}
	}
	else {
		cache_get_value_int(0, "amount", check_amount);
		returnval += check_amount;		
	}
	cache_delete(result);
	return returnval;	
}


HasPlayerItem(playerid, itemid, amount = 0) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_items` WHERE itemId = %d AND playerId = %d AND state = 1", itemid, CharacterSQL[playerid]);
	new Cache:result = mysql_query(g_SQL, sql);
	
	new check_amount;
	if(!cache_num_rows()) {
		return 0;
	}

	new i = -1;
	for(;++i<cache_num_rows();) {
		cache_get_value_int(i, "amount", check_amount);
		if(check_amount >= amount) {
			cache_delete(result);
			return 1;	
		}
	}
	
	cache_delete(result);
	return 0;
}

GivePlayerItem(playerid, itemid, amount = 1) {
	if(HasPlayerItem(playerid, itemid, 1) && IsStackingItem(itemid)) {
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount`+%d WHERE itemId = %d AND playerId = %d AND state = 1 LIMIT 1", amount, itemid, CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
		return 1;
	}
	else if(CountPlayerItems(playerid) < MAX_INVENTORY_SLOTS) {
		mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `player_items` (`playerId`, `itemId`, `amount`, `modPlayerId`, `crePlayerId`) VALUES ( '%d', '%d', '%d', '%d', '%d')",  CharacterSQL[playerid], itemid, amount, CharacterSQL[playerid], CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
		return 1;
	}
	return 0;
}

GiveStorageItem(storagesql, itemid, amount = 1, playerid = -1) {
	if(HasStorageItem(storagesql, itemid, 1) && IsStackingItem(itemid)) {
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount`+%d WHERE itemId = %d AND storageId = %d AND state = 2 LIMIT 1", amount, itemid, storagesql);
		mysql_tquery(g_SQL, sql, "", "");
		return 1;
	}
	else if(CountStorageItems(storagesql) < MAX_STORAGE_ITEMS) {
		mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `player_items` (`storageId`, `itemId`, `amount`, `modPlayerId`, `crePlayerId`, `state`) VALUES ( '%d', '%d', '%d', '%d', '%d', '2')",  storagesql, itemid, amount, CharacterSQL[playerid], CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
		return 1;
	}
	return 0;
}

RemovePlayerItem(playerid, itemid, amount = 1) {
	if(!HasPlayerItem(playerid, itemid, 1)){
		printf("Error on RemovePlayerItem(playerid %d, itemid %d, amount %d): !HasPlayerItem", playerid, itemid, amount);
		return 0;
	}
	if(IsStackingItem(itemid)) {
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount`-%d WHERE `itemId` = %d AND `playerId` = %d AND `state` = 1 LIMIT 1", amount, itemid, CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
		mysql_format(g_SQL, sql, sizeof sql, "DELETE FROM `player_items` WHERE `playerId` = %d AND `amount` <= 0 AND `state` = 1",  CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
	}
	else {
		mysql_format(g_SQL, sql, sizeof sql, "DELETE FROM `player_items` WHERE `playerId` = %d AND `itemId` = %d AND `state` = 1 LIMIT %d",  CharacterSQL[playerid], itemid, amount);
		mysql_query(g_SQL, sql);
	}
	return 1;
}


HasStorageItem(storagesql, itemid, amount = 0) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_items` WHERE itemId = %d AND storageId = %d AND state = 2", itemid, storagesql);
	new Cache:result = mysql_query(g_SQL, sql);
	
	new check_amount;
	if(!cache_num_rows()) {
		return 0;
	}

	new i = -1;
	for(;++i<cache_num_rows();) {
		cache_get_value_int(i, "amount", check_amount);
		if(check_amount >= amount) {
			cache_delete(result);
			return 1;	
		}
	}
	
	cache_delete(result);
	return 0;
}

FlushItem(itemsql) {
	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `state` = 0 WHERE `id` = %d LIMIT 1", itemsql);
	mysql_query(g_SQL, sql);
	return 1;
}

GetItemName(itemid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT name FROM `itemlist` WHERE id = %d LIMIT 1", itemid);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnName[64]="Error";
	if(cache_num_rows()) {
		cache_get_value(0, "name", returnName, 64);
	}
	cache_delete(result);
	return returnName;
}


YCMD:inventorylist(playerid, params[], help) {
	if(!SpamPrevent(playerid)) return 1;
	if(!IsHuman(playerid)) SCM(playerid, HEX_FADE2, "Zombies cannot use their inventory!");
	mysql_format(g_SQL, sql, sizeof sql, "SELECT pi.*, il.name FROM `player_items` AS pi INNER JOIN `itemlist` AS il ON il.id = pi.itemId WHERE pi.state = 1 AND pi.playerId = %d LIMIT %d", CharacterSQL[playerid], MAX_INVENTORY_SLOTS);
	inline LoadInventoryData() {
		if(!cache_num_rows()) {
			SCM(playerid, HEX_FADE2, "Your inventory is empty.");
			@return 1;
		}

		SCM(playerid,HEX_LORANGE,"Your items:");
		new string[2048];
		new tmp_return[32];
		new tmp_string[128], tmp_amount, i = -1;
		for(;++i<cache_num_rows();) {
			tmp_return = "ERROR";
			cache_get_value_int(i, "amount", tmp_amount);
			cache_get_value(i, "name", tmp_return, 32);
			
			if(tmp_amount > 1)
				format(tmp_string,sizeof(tmp_string),"[%i. %s (%i) ] \n",i+1, tmp_return,tmp_amount);
			else
				format(tmp_string,sizeof(tmp_string),"[%i]%s\n",i+1, tmp_return);
			strcat(string,tmp_string);
			if(i%5==0 && i != 0) {
				SCM(playerid,HEX_WHITE,string);
				string = "";
			}
		}
		if(!IsPlayerConnected(playerid)) @return 1;
		if(strlen(string)>0)
		{
			SCM(playerid, HEX_WHITE, string);
			ShowPlayerDialog(playerid, 82492, DIALOG_STYLE_LIST, "Inventory", string, "Select", "Close");
		}
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadInventoryData, sql);
	return 1;
}

YCMD:inventory(playerid, params[], help) {
	if(!SpamPrevent(playerid)) return 1;

	if(Bit_Get(dead, playerid) || IsZombie(playerid)) {
		SCM(playerid, HEX_RED, "Error: You cannot do that now.");
		return Y_HOOKS_BREAK_RETURN_1;
	}

	if(!Bit_Get(openinventory, playerid))
		OpenInventory(playerid);
	else
		CloseInventory(playerid);

	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(IsPlayerNPC(playerid) || Bit_Get(dead, playerid) || Bit_Get(frozen, playerid) || !IsHuman(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
	if(newkeys &  KEY_NO && !(oldkeys & KEY_NO)) 
	{
		if(!SpamPrevent(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
		if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DUCK && !IsPlayerInAnyVehicle(playerid)) {
			LootItem(playerid);
			LootCash(playerid);
			LootDrop(playerid);
			LootBandit(playerid);
		}		
	}	
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LootDrop(playerid) {
	new i = -1;
	for(;++i<MAX_PLAYERS;) 
	{
		new j = -1;
		for(;++j<MAX_INVENTORY_SLOTS*3;) 
		{
			if(GetPlayerInterior(playerid) == dropped_interior[i][j] && GetPlayerVirtualWorld(playerid) == dropped_virtualworld[i][j]) 
			{
				if(IsPlayerInRangeOfPoint(playerid, 1.2, dropped_posx[i][j], dropped_posy[i][j], dropped_posz[i][j])) 
				{
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
					GameTextForPlayer(playerid, "~w~Looting~y~...", 1000, 4);					
					if(GivePlayerItem(playerid, dropped_itemid[i][j], dropped_amount[i][j]) == 0) 
					{
						//SCM(playerid, HEX_FADE2, "Your inventory is full.");
						defer TimedGameTextForPlayer(playerid, "~w~~r~Your inventory is full!", 2200, 4);
						defer TimedPlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
					}
					else 
					{
						new string[256];
						format(string, sizeof string, "~y~%s ~w~looted!", GetItemName(dropped_itemid[i][j]));
						defer TimedGameTextForPlayer(playerid, string, 2200, 4);
						defer TimedPlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
						dropped_itemid[i][j] = 0;
						dropped_interior[i][j] = 0;
						dropped_virtualworld[i][j] = 0;
						DestroyDynamicObject(dropped_object[i][j]);
						dropped_object[i][j] = 0;
						dropped_posx[i][j] = 0.0;
						dropped_posy[i][j] = 0.0;
						dropped_posz[i][j] = 0.0;
					}
					break;
				}

			}

		}
	}
	return 1;
}

LootItem(playerid) {
	new i = -1;
	for(;++i<MAX_LOOT;)
		if(Bit_Get(lootable, i))
			if(LootInfo[i][l_virtualworld] == GetPlayerVirtualWorld(playerid) && LootInfo[i][interior] == GetPlayerInterior(playerid))
				if(IsPlayerInRangeOfPoint(playerid, 1.2, LootInfo[i][lootpos][0], LootInfo[i][lootpos][1], LootInfo[i][lootpos][2])) {
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
					GameTextForPlayer(playerid, "~w~Looting~y~...", 1000, 4);						
					if(GivePlayerItem(playerid, LootInfo[i][itemlistId], DefaultAmount(LootInfo[i][itemlistId])) == 0) {
						//SCM(playerid, HEX_FADE2, "Your inventory is full.");
						defer TimedGameTextForPlayer(playerid, "~w~~r~Your inventory is full!", 2200, 4);
						defer TimedPlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
					}
					else {
						Bit_Vet(lootable, i);
						DestroyDynamicObject(LootInfo[i][object]);
						defer ReviveLoot(i);
						new string[256];
						format(string, sizeof string, "~y~%s ~w~looted!", GetItemName(LootInfo[i][itemlistId]));
						defer TimedGameTextForPlayer(playerid, string, 2200, 4);
						defer TimedPlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);

						if(LootInfo[i][itemlistId] > 18 && LootInfo[i][itemlistId] < 34) {
							AddMatchingAmmo(playerid, LootInfo[i][itemlistId]);
						}

					}
					break;
				}
	return 1;
}

ShowLootDialog(playerid, lootfrom, npcloot = false) {
	if(npcloot) {
		
		if(GetPVarInt(lootfrom, "npcgun") <= 1) {
			defer TimedGameTextForPlayer(playerid, "~w~~y~Empty", 2200, 3);
			defer TimedPlayerPlaySound(playerid, 1055, 0.0, 0.0, 0.0);
			return 0;
		}

		new string[256];
		format(string, sizeof string, "%s\n", DeathReason(GetPVarInt(lootfrom, "npcgun")));

		inline Dialog_loot_npc(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
			#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
			if(Open_response) {
				switch(Open_listitem) {
				case 0: {
					if(GivePlayerItem(playerid, GetItemFromWeapon(GetPVarInt(lootfrom, "npcgun")), 1) == 0) {
						//SCM(playerid, HEX_FADE2, "Your inventory is full.");
						defer TimedGameTextForPlayer(playerid, "~w~~r~Your inventory is full!", 2200, 4);
						defer TimedPlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
					}
					else {
						if( GetItemFromWeapon(GetPVarInt(lootfrom, "npcgun")) > 18 && GetItemFromWeapon(GetPVarInt(lootfrom, "npcgun")) < 34) {
							AddMatchingAmmo(playerid, GetItemFromWeapon(GetPVarInt(lootfrom, "npcgun")));
						}
						SetPVarInt(lootfrom, "npcgun", 0);
						SetPVarInt(lootfrom, "lootedby", -1);
						
					}
				}
				default:
					SetPVarInt(lootfrom, "lootedby", -1);
				}
			}
			else {				
				SetPVarInt(lootfrom, "lootedby", -1);
			}
		}	
		Dialog_ShowCallback(playerid, using inline Dialog_loot_npc, DIALOG_STYLE_LIST, "Seaching body...", string, "Loot","Close");
	}
	return 1;
}

GetItemFromWeapon(weaponid) {
	new i = -1;
	switch(weaponid) {
		case 22: i = 19;
		case 23: i = 20;
		case 24: i = 21;
		case 25: i = 22;
		case 26: i = 23;
		case 27: i = 24;
		case 28: i = 25;
		case 29: i = 26;
		case 30: i = 27;
		case 31: i = 28;
		case 32: i = 29;
		case 33: i = 30;
		case 34: i = 31;
		case 35: i = 32;
		case 36: i = 33;
		case 37: i = 34;

		default: i = weaponid;
	}
	return i;
}

LootBandit(playerid) {
	new Float:zPoz[3];
	foreach(new j:GroupMember[npc_a51]) {
		if(GetPlayerInterior(playerid) == FCNPC_GetInterior(j) && GetPlayerVirtualWorld(playerid) == FCNPC_GetVirtualWorld(j)) {
			if(FCNPC_GetHealth(j) < 1.0) {
				FCNPC_GetPosition(j, zPoz[0], zPoz[1], zPoz[2]);
				if(IsPlayerInRangeOfPoint(playerid, 1.6, zPoz[0], zPoz[1], zPoz[2])) {
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
					GameTextForPlayer(playerid, "~w~Searching~y~...", 1000, 3);
					if(GetPVarInt(j, "lootedby") == -1 && AI_GetReaction(j) == AI_MODE_HOSTILE) {
						SetPVarInt(j, "lootedby", playerid);
						ShowLootDialog(playerid, j, true);
					}
					else {
						SCM(playerid, HEX_RED, "Error: Somebody else is looting this body.");
						break;
					}
					if(GetPVarInt(j, "lootable") && AI_GetReaction(j) == AI_MODE_HOSTILE) {
						SetPVarInt(j, "lootable", 0);
						new dices = random(2) + random(2);
						if(dices == 2)
							dices += random(2);
						if(dices == 3)
							dices += random(2);
						if(dices == 4)
							dices += random(2);
						new lootcash = 0;
						new i = -1;
						for(;++i<dices;) {
							lootcash += random(21);
							if(halloween_event)
								lootcash += random(21);
						}
						GivePlayerMoney(playerid, lootcash);
						cash[playerid] += lootcash;
						if(lootcash == 0) {
							defer TimedGameTextForPlayer(playerid, "~w~~y~Empty", 2200, 3);
							defer TimedPlayerPlaySound(playerid, 1055, 0.0, 0.0, 0.0);
						}
						else {
							new lilstr[128];
							format(lilstr, sizeof lilstr, "~w~~g~$%d found", lootcash);
							defer TimedGameTextForPlayer(playerid, lilstr, 2200, 3);
							defer TimedPlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						}
						break;
					}
					else {
						defer TimedGameTextForPlayer(playerid, "~w~~y~Empty", 2200, 3);
						defer TimedPlayerPlaySound(playerid, 1055, 0.0, 0.0, 0.0);
						if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: Bandit cash was already looted.");
						break;
					}
				}
			}
		}
	}
	return 1;
}

LootCash(playerid) {
	new Float:zPoz[3];
	foreach(new j:GroupMember[npc_Zombie]) {
		if(GetPlayerInterior(playerid) == FCNPC_GetInterior(j) && GetPlayerVirtualWorld(playerid) == FCNPC_GetVirtualWorld(j)) {
			if(FCNPC_GetHealth(j) < 1.0) {
				FCNPC_GetPosition(j, zPoz[0], zPoz[1], zPoz[2]);
				if(IsPlayerInRangeOfPoint(playerid, 1.6, zPoz[0], zPoz[1], zPoz[2])) {
					ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
					GameTextForPlayer(playerid, "~w~Searching~y~...", 1000, 3);
					if(GetPVarInt(j, "lootable")) {
						SetPVarInt(j, "lootable", 0);
						new dices = random(2) + random(2);
						if(dices == 2)
							dices += random(2);
						if(dices == 3)
							dices += random(2);
						if(dices == 4)
							dices += random(2);
						new lootcash = 0;
						new i = -1;
						for(;++i<dices;) {
							lootcash += random(21);
							if(halloween_event)
								lootcash += random(21);
						}
						GivePlayerMoney(playerid, lootcash);
						cash[playerid] += lootcash;
						if(lootcash == 0) {
							defer TimedGameTextForPlayer(playerid, "~w~~y~Empty", 2200, 3);
							defer TimedPlayerPlaySound(playerid, 1055, 0.0, 0.0, 0.0);
						}
						else {
							new lilstr[128];
							format(lilstr, sizeof lilstr, "~w~~g~$%d found", lootcash);
							defer TimedGameTextForPlayer(playerid, lilstr, 2200, 3);
							defer TimedPlayerPlaySound(playerid, 1054, 0.0, 0.0, 0.0);
						}
						break;
					}
					else {
						defer TimedGameTextForPlayer(playerid, "~w~~y~Empty", 2200, 3);
						defer TimedPlayerPlaySound(playerid, 1055, 0.0, 0.0, 0.0);
						if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: Zombie was already looted.");
						break;
					}
				}
			}
		}
	}
	return 1;
}

timer ReviveLoot[random(LOOT_RESPAWNTIME)+random(LOOT_RESPAWNTIME)](lootid) {
	CreateLoot(lootid, LootInfo[lootid][l_category]);
}


GetAmmoItemFromWeaponid(weaponid) {
	switch(weaponid) {
		case 22: return 39;
		case 23: return 39;
		case 24: return 41;
		case 25: return 40;
		case 26: return 40;
		case 27: return 40;
		case 28: return 39;
		case 29: return 39;
		case 30: return 42;
		case 31: return 43;
		case 32: return 39;
		case 33: return 44;
		case 34: return 44;
		case 35: return 45;
		case 36: return 45;
		case 37: return 46;
	}
	return 0;
}

WeaponAmmo(weaponid) {

	switch(weaponid) {
		case 22: return 17;
		case 23: return 17;
		case 24: return 7;
		case 25: return 12;
		case 26: return 12;
		case 27: return 7;
		case 28: return 50;
		case 29: return 30;
		case 30: return 30;
		case 31: return 30;
		case 32: return 30;
		case 33: return 10;
		case 34: return 10;
		case 35: return 1;
		case 36: return 1;
		case 37: return 1000;
	}
	return 0;
}

WeaponItemAmmo(itemsql) {

	switch(itemsql) {
		case 19: return 17;
		case 20: return 17;
		case 21: return 7;
		case 22: return 7;
		case 23: return 12;
		case 24: return 7;
		case 25: return 50;
		case 26: return 30;
		case 27: return 30;
		case 28: return 30;
		case 29: return 30;
		case 30: return 10;
		case 31: return 10;
		case 32: return 1;
		case 33: return 1;
		case 34: return 1000;
	}
	return 0;
}

AddMatchingAmmo(playerid, itemid) {
	switch(itemid) {
		case 19: GivePlayerItem(playerid, 39, WeaponItemAmmo(19));
		case 20: GivePlayerItem(playerid, 39, WeaponItemAmmo(20));
		case 21: GivePlayerItem(playerid, 41, WeaponItemAmmo(21));
		case 22: GivePlayerItem(playerid, 40, WeaponItemAmmo(22));
		case 23: GivePlayerItem(playerid, 40, WeaponItemAmmo(23));
		case 24: GivePlayerItem(playerid, 40, WeaponItemAmmo(24));
		case 25: GivePlayerItem(playerid, 39, WeaponItemAmmo(25));
		case 26: GivePlayerItem(playerid, 39, WeaponItemAmmo(26));
		case 27: GivePlayerItem(playerid, 42, WeaponItemAmmo(27));
		case 28: GivePlayerItem(playerid, 43, WeaponItemAmmo(28));
		case 29: GivePlayerItem(playerid, 39, WeaponItemAmmo(29));
		case 30: GivePlayerItem(playerid, 44, WeaponItemAmmo(30));
		case 31: GivePlayerItem(playerid, 44, WeaponItemAmmo(31));
		case 32: GivePlayerItem(playerid, 45, WeaponItemAmmo(32));
		case 33: GivePlayerItem(playerid, 45, WeaponItemAmmo(33));
	}
	return 1;
}

DefaultAmount(itemid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT amount FROM `itemlist` WHERE id = %d LIMIT 1", itemid);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnval;
	if(cache_num_rows()) {
		cache_get_value_int(0, "amount", returnval);
	}
	cache_delete(result);
	return returnval;	
}

IsStackingItem(itemid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT stacking FROM `itemlist` WHERE id = %d LIMIT 1", itemid);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnval;
	if(cache_num_rows()) {
		cache_get_value_int(0, "stacking", returnval);
	}
	cache_delete(result);
	return returnval;
}

CountPlayerItems(playerid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT id FROM `player_items`  WHERE state = 1 AND playerId = '%d'", CharacterSQL[playerid]);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnval = cache_num_rows();
	cache_delete(result);
	return returnval;
}

CountStorageItems(storage) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT id FROM `player_items`  WHERE state = 2 AND storageId = '%d'", storage);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnval = cache_num_rows();
	cache_delete(result);
	return returnval;
}

YCMD:loot(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) {
		if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
		if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	}

	new targetid;

	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /loot [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}
	if(playerid == targetid) return SCM(playerid, HEX_RED, "Error: You cannot loot from yourself.");
	HandlePlayerLootPlayer(playerid, targetid);
	
	return 1;
}

HandlePlayerLootPlayer(playerid, targetid) {

	if(!IsPlayerConnected(playerid)) return 0;
	if(!IsPlayerConnected(targetid)) return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");

	if(!Group_GetPlayer(g_AdminDuty, playerid)) {
		if(!Bit_Get(dead, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
		if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
		if(GetPlayerInterior(playerid) != GetPlayerInterior(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
		new Float:p_dist[3];
		GetPlayerPos(targetid, p_dist[0], p_dist[1], p_dist[2]);
		if(GetPlayerDistanceFromPoint(playerid, p_dist[0], p_dist[1], p_dist[2]) > 5.0) return SCM(playerid, HEX_RED, "[Desolation]: You are too far away.");
	}
	ReloadPlayerInventory(targetid, true);
	mysql_format(g_SQL, sql, sizeof sql, "SELECT pi.*, il.name FROM `player_items` AS pi INNER JOIN `itemlist` AS il ON il.id = pi.itemId WHERE pi.state = 1 AND pi.playerId = %d LIMIT %d", CharacterSQL[targetid], MAX_INVENTORY_SLOTS);
	inline LoadInventoryData() {
		if(!cache_num_rows()) {
			SFM(playerid, HEX_FADE2, "%s's inventory is empty.", PlayerName(targetid));
			@return 1;
		}

		new string[2048];
		new tmp_return[32];
		new tmp_string[128], tmp_amount, i = -1;
		for(;++i<cache_num_rows();) {
			tmp_return = "ERROR";
			cache_get_value_int(i, "amount", tmp_amount);
			cache_get_value(i, "name", tmp_return, 32);
			
			format(tmp_string,sizeof(tmp_string),"%i. %s (%i)\n",i+1, tmp_return,tmp_amount);
			strcat(string,tmp_string);

			format(tmp_string, sizeof tmp_string, "Looting %s", PlayerName(targetid));

			inline ShowLootScreen(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
				#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
				if(Open_response) {
					if(!IsPlayerConnected(playerid)) @return 0;
					if(!IsPlayerConnected(targetid)) @return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
					format(string, sizeof string, "Are you sure you want to loot %s (%d) from %s?", GetItemName(inventory_itemid[targetid][Open_listitem]), inventory_amount[targetid][Open_listitem], PlayerName(targetid));
					inline ShowLootConfirm(Confirm_pid, Confirm_dialogid, Confirm_response, Confirm_listitem, string:Confirm_inputtext[]) {
						#pragma unused Confirm_pid, Confirm_dialogid, Confirm_response, Confirm_listitem, Confirm_inputtext
						if(Confirm_response) {
							if(!IsPlayerConnected(playerid)) @return 0;
							if(!IsPlayerConnected(targetid)) @return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
							if(!Bit_Get(dead, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");

							if(GivePlayerItem(playerid, inventory_itemid[targetid][Open_listitem], inventory_amount[targetid][Open_listitem]) == 0) {
								SCM(playerid, HEX_FADE2, "Your inventory is full.");
								PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
							}
							else {
								format(string, sizeof string, "~y~%s ~w~looted!", GetItemName(inventory_itemid[targetid][Open_listitem]));
								GameTextForPlayer(playerid, string, 2000, 3);
								format(string, sizeof string, "has looted %s from %s.", GetItemName(inventory_itemid[targetid][Open_listitem]), PlayerName(targetid, false));
								PlayerHiddenAction(playerid, string);
								PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
								RemovePlayerItem(targetid, inventory_itemid[targetid][Open_listitem], inventory_amount[targetid][Open_listitem]);
								HandlePlayerLootPlayer(playerid, targetid);
							}
							@return 1;
						}
						else {
							HandlePlayerLootPlayer(playerid, targetid);
							@return 1;
						}
					}
					Dialog_ShowCallback(playerid, using inline ShowLootConfirm, DIALOG_STYLE_MSGBOX, tmp_string, string, "Loot","Back");
				}
				@return 1;
			}	
			Dialog_ShowCallback(playerid, using inline ShowLootScreen, DIALOG_STYLE_LIST, tmp_string, string, "Loot","Close");

		}
		if(!IsPlayerConnected(playerid)) @return 1;

		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadInventoryData, sql);

	return 1;
}