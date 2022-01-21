#include <YSI_Coding\y_hooks>


hook OnGameModeInit() {
	LoadStoragePoints();

	Command_AddAltNamed("storagehelp", "safehelp");

	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadStoragePoints() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `storages` WHERE state = 1");
	inline LoadStorageData() {
		if(!cache_num_rows()) {
			print("No storage points found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", storageInfo[i][safe_sqlid]);
			//cache_get_value_int(i, "objectid", storageInfo[i][safe_object]);
			cache_get_value_int(i, "objectid", storageInfo[i][safe_object2]);
			cache_get_value_int(i, "objectid", storageInfo[i][safe_objid]);

			cache_get_value_int(i, "interior", storageInfo[i][safe_interior]);
			cache_get_value_int(i, "virtualworld", storageInfo[i][safe_virtualworld]);

			cache_get_value_float(i, "posx", storageInfo[i][safe_pos][0]);
			cache_get_value_float(i, "posy", storageInfo[i][safe_pos][1]);
			cache_get_value_float(i, "posz", storageInfo[i][safe_pos][2]);

			cache_get_value_float(i, "rotx", storageInfo[i][safe_rot][0]);
			cache_get_value_float(i, "roty", storageInfo[i][safe_rot][1]);
			cache_get_value_float(i, "rotz", storageInfo[i][safe_rot][2]);

			cache_get_value_int(i, "playerid", storageInfo[i][safe_playerid]);
			cache_get_value_int(i, "factionid", storageInfo[i][safe_factionid]);
			cache_get_value_int(i, "cityid", storageInfo[i][safe_cityid]);

			cache_get_value_int(i, "locked", storageInfo[i][safe_locked]);

			MoveStoragePoint(i);

			Iter_Add(Storages, i);
		}
		
		printf("%d storage points loaded.", CountStorages());
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadStorageData, sql);
	return 1;
}

/*MoveStoragePoint(storage) {

	if(storageInfo[storage][safe_object] == 0 || !IsValidDynamicObject(storageInfo[storage][safe_object])) {
		print("creating storage object");
		storageInfo[storage][safe_object] = CreateDynamicObject(storageInfo[storage][safe_object], storageInfo[storage][safe_pos][0], storageInfo[storage][safe_pos][1], storageInfo[storage][safe_pos][2], storageInfo[storage][safe_rot][0], storageInfo[storage][safe_rot][1], storageInfo[storage][safe_rot][2], storageInfo[storage][safe_virtualworld], storageInfo[storage][safe_interior]);
		
		//if(storageInfo[storage][safe_objid] == 19618) {
		//	
		//	storageInfo[storage][safe_object2] = CreateDynamicObject(19619, storageInfo[storage][safe_pos][0]-0.4, storageInfo[storage][safe_pos][1]-0.2, storageInfo[storage][safe_pos][2], storageInfo[storage][safe_rot][0], storageInfo[storage][safe_rot][1], storageInfo[storage][safe_rot][2], storageInfo[storage][safe_virtualworld], storageInfo[storage][safe_interior]);
		//}
	}
	else {
		print("destroying storage object");
		DestroyDynamicObject(storageInfo[storage][safe_object]);
		storageInfo[storage][safe_object] = CreateDynamicObject(storageInfo[storage][safe_objid], storageInfo[storage][safe_pos][0], storageInfo[storage][safe_pos][1], storageInfo[storage][safe_pos][2], storageInfo[storage][safe_rot][0], storageInfo[storage][safe_rot][1], storageInfo[storage][safe_rot][2], storageInfo[storage][safe_virtualworld], storageInfo[storage][safe_interior]);
		
		//if(storageInfo[storage][safe_objid] == 19618) {
		//	
		//	storageInfo[storage][safe_object2] = CreateDynamicObject(19619, storageInfo[storage][safe_pos][0]-0.4, storageInfo[storage][safe_pos][1]-0.2, storageInfo[storage][safe_pos][2], storageInfo[storage][safe_rot][0], storageInfo[storage][safe_rot][1], storageInfo[storage][safe_rot][2], storageInfo[storage][safe_virtualworld], storageInfo[storage][safe_interior]);
		//}
	}

	return 1;
}*/

MoveStoragePoint(storage) {

	if(IsValidDynamicObject(storageInfo[storage][safe_object])) {
		
		print("destroying storage object");
		DestroyDynamicObject(storageInfo[storage][safe_object]);
		storageInfo[storage][safe_object] = CreateDynamicObject(storageInfo[storage][safe_objid], storageInfo[storage][safe_pos][0], storageInfo[storage][safe_pos][1], storageInfo[storage][safe_pos][2], storageInfo[storage][safe_rot][0], storageInfo[storage][safe_rot][1], storageInfo[storage][safe_rot][2], storageInfo[storage][safe_virtualworld], storageInfo[storage][safe_interior]);

	}
	else {
		
		print("creating storage object");
		storageInfo[storage][safe_object] = CreateDynamicObject(storageInfo[storage][safe_object2], storageInfo[storage][safe_pos][0], storageInfo[storage][safe_pos][1], storageInfo[storage][safe_pos][2], storageInfo[storage][safe_rot][0], storageInfo[storage][safe_rot][1], storageInfo[storage][safe_rot][2], storageInfo[storage][safe_virtualworld], storageInfo[storage][safe_interior]);

	}

	return 1;
}

CountStorages() {
	new i = 0;
	foreach(new j:Storages) {
		++i;
	}
	return i;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(newkeys & KEY_NO && !IsPlayerInAnyVehicle(playerid)) {

        if(Bit_Get(dead, playerid) || IsZombie(playerid)) {
            SCM(playerid, HEX_RED, "Error: You cannot do that now.");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        if(!Bit_Get(openstorage, playerid))
            OpenStorage_Check(playerid);
        else
            CloseStorage(playerid);

    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}


CloseStorage(playerid) {
    Bit_Vet(openstorage, playerid);
    return 1;
}

OpenStorage_Check(playerid) {

	foreach(new i:Storages) {

		if(GetPlayerInterior(playerid) == storageInfo[i][safe_interior] && GetPlayerVirtualWorld(playerid) == storageInfo[i][safe_virtualworld]) {
			if(IsPlayerInRangeOfPoint(playerid, CHECK_RANGE, storageInfo[i][safe_pos][0], storageInfo[i][safe_pos][1], storageInfo[i][safe_pos][2])) {

				OpenStorage(playerid, i);

			}
		}
	}

    
    return 1;
}

OpenStorage(playerid, storage) { // PLAYER TAKING ITEM FROM THE SAFE

	if(!StorageAccess(playerid, storage)) return SCM(playerid, HEX_RED, "Error: You cannot access this storage.");

	Bit_Let(openstorage, playerid);
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_items` WHERE storageId = '%d' AND state = 2 LIMIT %d", storageInfo[storage][safe_sqlid], MAX_STORAGE_ITEMS);
	
	inline LoadStorageItems() {

		new itemsql[MAX_STORAGE_ITEMS];
		new itemid[MAX_STORAGE_ITEMS];
		new itemamount[MAX_STORAGE_ITEMS];
		new tmpstr[128];
		new string[2048] = "Item\tAmount\n{FFFF00}Add new item\t<\n";

		if(cache_num_rows()) {
			new i = -1;
			new itemsfound = cache_num_rows();
			for(;++i<itemsfound;) {
				cache_get_value_int(i, "id", itemsql[i]);
				cache_get_value_int(i, "itemId", itemid[i]);
				cache_get_value_int(i, "amount", itemamount[i]);
			}
			i = -1;
			for(;++i<itemsfound;) {		
				format(tmpstr, sizeof tmpstr, "{008000}%d. %s\tx%d\n", i+1, GetItemName(itemid[i]), itemamount[i]);
				strcat(string, tmpstr);
			}

		}	
		format(tmpstr, sizeof tmpstr, "Retrieve item {008000}from Storage #%d", storageInfo[storage][safe_sqlid]);
		
		inline selectStorageItem(pid, dialogid, response, listitem, string:inputtext[]) {
			#pragma unused pid, dialogid, response, listitem, inputtext
			if(response) {
				if(Bit_Get(dead, playerid) || IsZombie(playerid)) @return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
				if(listitem == 0) {
					OpenStorageTransfer(playerid, storage);					
				}
				else {
					if(HasStorageItem(storageInfo[storage][safe_sqlid], itemid[listitem-1], itemamount[listitem-1])) {
						if(GivePlayerItem(playerid, itemid[listitem-1], itemamount[listitem-1]) == 0) {
							SCM(playerid, HEX_FADE2, "Your inventory is full.");
							PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
						}
						else {
							format(string, sizeof string, "~y~%s ~w~retrieved!", GetItemName(itemid[listitem-1]));
							GameTextForPlayer(playerid, string, 2000, 3);
							PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
							FlushItem(itemsql[listitem-1]);
							OpenStorage(playerid, storage);
						}
					}
					else {
						SCM(playerid, HEX_RED, "Item not found.");
						OpenStorage(playerid, storage);
					}
				}

			}
			else {
				Bit_Vet(openstorage, playerid);
			}
		}
		Dialog_ShowCallback(playerid, using inline selectStorageItem, DIALOG_STYLE_TABLIST_HEADERS, tmpstr, string, "Select", "Close");


		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadStorageItems, sql);


	return 1;
}

OpenStorageTransfer(playerid, storage) { // PLAYER ADDING ITEM INTO THE SAFE

	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_items` WHERE playerId = '%d' AND state = 1 LIMIT %d", CharacterSQL[playerid], MAX_INVENTORY_SLOTS);
	
	inline LoadStorageItems_player() {

		new itemsql[MAX_STORAGE_ITEMS];
		new itemid[MAX_STORAGE_ITEMS];
		new itemamount[MAX_STORAGE_ITEMS];
		new tmpstr[128];
		new string[2048] = "Item\tAmount\n";

		if(cache_num_rows()) {
			new i = -1;
			new itemsfound = cache_num_rows();
			for(;++i<itemsfound;) {
				cache_get_value_int(i, "id", itemsql[i]);
				cache_get_value_int(i, "itemId", itemid[i]);
				cache_get_value_int(i, "amount", itemamount[i]);
			}
			i = -1;
			for(;++i<itemsfound;) {		
				format(tmpstr, sizeof tmpstr, "{FFFF00}%d. %s\tx%d\n", i+1, GetItemName(itemid[i]), itemamount[i]);
				strcat(string, tmpstr);
			}

		}	
		format(tmpstr, sizeof tmpstr, "Add item to {FFFF00}Storage #%d", storageInfo[storage][safe_sqlid]);
		
		inline selectStorageItem_player(pid, dialogid, response, listitem, string:inputtext[]) {
			#pragma unused pid, dialogid, response, listitem, inputtext
			if(response) {
				if(Bit_Get(dead, playerid) || IsZombie(playerid)) @return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
				if(HasPlayerItem(playerid, itemid[listitem], itemamount[listitem])) {
					if(GiveStorageItem(storageInfo[storage][safe_sqlid], itemid[listitem], itemamount[listitem], playerid) == 0) {
						SCM(playerid, HEX_FADE2, "The storage is full.");
						PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
					}
					else {
						format(string, sizeof string, "~w~%s ~y~added!", GetItemName(itemid[listitem]));
						GameTextForPlayer(playerid, string, 2000, 3);
						PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
						FlushItem(itemsql[listitem]);
						OpenStorage(playerid, storage);
					}
				}
				else {
					SCM(playerid, HEX_RED, "Item not found.");
					OpenStorage(playerid, storage);
				}
				
			}
			else {
				OpenStorage(playerid, storage);
			}
		}
		Dialog_ShowCallback(playerid, using inline selectStorageItem_player, DIALOG_STYLE_TABLIST_HEADERS, tmpstr, string, "Select", "Back");


		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadStorageItems_player, sql);


	return 1;
}

StorageAccess(playerid, storage) {

	if(Group_GetPlayer(g_AdminDuty, playerid)) return 1;
	if(!storageInfo[storage][safe_locked]) return 1;
	if(CharacterSQL[playerid] == storageInfo[storage][safe_playerid]) return 1;
	if(faction[playerid] > 0 && faction[playerid] == storageInfo[storage][safe_factionid]) return 1;
	if(city[playerid] > 0 && city[playerid] == storageInfo[storage][safe_cityid]) return 1;
	if(HasStorageKey(playerid, storageInfo[storage][safe_sqlid])) return 1;

	return 0;
}

HasStorageKey(playerid, safe) {

	mysql_format(g_SQL, sql, sizeof sql, "SELECT id FROM `player_keys` WHERE playerId = %d AND storageId = %d AND state > 0 LIMIT 1", CharacterSQL[playerid], safe);

	new Cache:result = mysql_query(g_SQL, sql);
	if(cache_num_rows()) {
		cache_delete(result);
		return 1;
	}
	
	return 0;
}

/*
YCMD:addgathering(playerid, params[], help) {
	new Float:gat_pos[3],
		ggattype,
		gglevel;

    if(sscanf(params,"dd", ggattype, gglevel)) {
		SCM(playerid, HEX_FADE2, "Usage: /addgathering [gattype] [glevel]");
		SCM(playerid, HEX_FADE2, "gattypes: 0 scavenging, 1 biological, 2 mining");
		SCM(playerid, HEX_FADE2, "glevels range from 0 to 2.");
		return 1;
	}
	if(ggattype > 2 || ggattype < 0) return SCM(playerid, HEX_RED, "Error: Invalid gattype. gattypes: 0 scavenging, 1 biological, 2 mining");
	if(gglevel > 2 || gglevel < 0) return SCM(playerid, HEX_RED, "Error: Invalid glevel. glevels range from 0 to 2, 0 being the lowest.");

    GetPlayerPos(playerid, gat_pos[0], gat_pos[1], gat_pos[2]);

	gatheringInfo[active_gathering_nodes][gpos][0] = gat_pos[0];
	gatheringInfo[active_gathering_nodes][gpos][1] = gat_pos[1];
	gatheringInfo[active_gathering_nodes][gpos][2] = gat_pos[2];

	gatheringInfo[active_gathering_nodes][gattype] = ggattype;
	gatheringInfo[active_gathering_nodes][glevel] = gglevel;
	gatheringInfo[active_gathering_nodes][interior] = GetPlayerInterior(playerid);
	gatheringInfo[active_gathering_nodes][virtualworld] = GetPlayerVirtualWorld(playerid);

	CreateGatherable(active_gathering_nodes);
	++active_gathering_nodes;

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `gathering` (`posx`, `posy`, `posz`, `type`, `level`, `interior`, `virtualworld`) VALUES ('%f', '%f', '%f', '%d', '%d', '%d', '%d')",  gat_pos[0], gat_pos[1], gat_pos[2], ggattype, gglevel, gatheringInfo[active_gathering_nodes][interior], gatheringInfo[active_gathering_nodes][virtualworld]);
	mysql_tquery(g_SQL, sql, "", "");	

	SFM(playerid, HEX_FADE2, "Gathering node %d created. (%d / %d)", active_gathering_nodes, ggattype, gglevel);
	return 1;
}*/


YCMD:storagehelp(playerid, params[], help) {

	SCM(playerid, HEX_FADE2, "Press 'N' (key_no by default) to access a safe. You can add or remove items in the dialog menu.");
	SFM(playerid, HEX_FADE2, "Commands: /mysafes /grantsafekey /removesafekeys /movesafe /createsafe (Note: A safe costs $%d.)", SAFE_COST);

	return 1;
}

YCMD:removesafekeys(playerid, params[], help) {

	if(!SpamPrevent(playerid)) return 1;

	new safeid;

	if(sscanf(params, "d", safeid)) return SCM(playerid, HEX_FADE2, "Usage: /removesafekeys [safe] (Hint: Use /mysafes to check your safe id.)");

	new storage = -1;
	foreach(new i:Storages) {
		if(storageInfo[i][safe_playerid] == CharacterSQL[playerid]) {
			if(storageInfo[i][safe_sqlid] == safeid) {
				storage = i;
				break;
			}
		}
	}

	if(storage == -1) return SCM(playerid, HEX_RED, "Error: You do not own a safe with that id. Check /mysafes or /storagehelp for more information.");

	EmptySafeKeys(safeid);

	SFM(playerid, HEX_YELLOW, "You have inactivated all spare key access to storage %d.", safeid);

	return 1;
}

YCMD:grantsafekey(playerid, params[], help) {

	if(!SpamPrevent(playerid)) return 1;

	new safeid, targetid;

	if(sscanf(params, "rd", targetid, safeid)) return SCM(playerid, HEX_FADE2, "Usage: /grantfesafekey [id] [safe] (Hint: Use /mysafes to check your safe id.)");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "dd", targetid, safeid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(playerid == targetid) return SCM(playerid, HEX_RED, "[Desolation]: You cannot grant yourself keys.");

	new storage = -1;
	foreach(new i:Storages) {
		if(storageInfo[i][safe_playerid] == CharacterSQL[playerid]) {
			if(storageInfo[i][safe_sqlid] == safeid) {
				storage = i;
				break;
			}
		}
	}

	if(storage == -1) return SCM(playerid, HEX_RED, "Error: You do not own a safe with that id. Check /mysafes or /storagehelp for more information.");

	new Float:pos[3];
	GetPlayerPos(targetid, pos[0],pos[1],pos[2]);
	if(!IsPlayerInRangeOfPoint(playerid, 6.0, pos[0],pos[1],pos[2]) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");


    mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `player_keys` (`playerId`, `storageId`) VALUES ('%d', '%d')", CharacterSQL[targetid], safeid);
	mysql_tquery(g_SQL, sql, "", "");

	SFM(playerid, HEX_YELLOW, "You have given %s a key to storage %d.", PlayerName(targetid), safeid);
	SFM(targetid, HEX_YELLOW, "You have recieved a key from %s to storage %d.", PlayerName(playerid), safeid);

	return 1;
}

enum SafeboxEnum {
	s_name[32],
	s_objid,
	s_slots,
	s_price
}

static const SafeList[][SafeboxEnum] = {
	{"Cabinet", 2007, MAX_STORAGE_ITEMS, SAFE_COST},
	{"Doorless safe", 19618, MAX_STORAGE_ITEMS, SAFE_COST},
	{"Gym locker", 11729, MAX_STORAGE_ITEMS, SAFE_COST},
	{"Huge box", 3800, MAX_STORAGE_ITEMS, SAFE_COST}
};

YCMD:createsafe(playerid, params[], help) {

	//if(GetPlayerVirtualWorld(playerid) == 0) return SCM(playerid, HEX_RED, "Error: You must be inside an interior to create a safe.");

	new string[512], tmpstring[128];
	format(string, sizeof string, "Name\tObject id\tSlots\tPrice\n");
	new i = -1;
	for(;++i<sizeof(SafeList);) {
		format(tmpstring, sizeof tmpstring, "%s\t(%d)\t%d\t$%d\n", SafeList[i][s_name], SafeList[i][s_objid], SafeList[i][s_slots], SafeList[i][s_price]);
		strcat(string, tmpstring);
	}

	inline createSafe_player(pid, dialogid, response, listitem, string:inputtext[]) {
		#pragma unused pid, dialogid, response, listitem, inputtext
		if(response) {
			SafeCreation(playerid, listitem);
		}
	}
	Dialog_ShowCallback(playerid, using inline createSafe_player, DIALOG_STYLE_TABLIST_HEADERS, "Choose your new safe", string, "Purchase", "Back");

	return 1;
}

StorageID(ssql) {
	new storage = -1;
	foreach(new i:Storages) {
		if(storageInfo[i][safe_sqlid] == ssql) {
			storage = i;
			break;
		}
	}
	return storage;
}

YCMD:movesafe(playerid, params[], help) {

	if(!SpamPrevent(playerid)) return 1;

	new safeid;

	if(sscanf(params, "d", safeid)) return SCM(playerid, HEX_FADE2, "Usage: /movesafe [safe] (Hint: Use /mysafes to check your safe id.)");

	new storage = -1;
	foreach(new i:Storages) {
		if(storageInfo[i][safe_playerid] == CharacterSQL[playerid]) {
			if(storageInfo[i][safe_sqlid] == safeid) {
				storage = i;
				break;
			}
		}
	}

	if(storage == -1) return SCM(playerid, HEX_RED, "Error: You do not own a safe with that id. Check /mysafes or /storagehelp for more information.");

	SafeMoving(playerid, safeid);

	return 1;
}

SafeMoving(playerid, safeid) {

	new string[512], tmpstring[128];
	format(string, sizeof string, "Name\tObject id\tSlots\tPrice\n");
	new i = -1;
	for(;++i<sizeof(SafeList);) {
		format(tmpstring, sizeof tmpstring, "%s\t(%d)\t%d\t$%d\n", SafeList[i][s_name], SafeList[i][s_objid], SafeList[i][s_slots], SafeList[i][s_price]);
		strcat(string, tmpstring);
	}

	inline createSafe_player(pid, dialogid, response, listitem, string:inputtext[]) {
		#pragma unused pid, dialogid, response, listitem, inputtext
		if(response) {
			SafeCreation_move(playerid, listitem, safeid);
		}
	}
	Dialog_ShowCallback(playerid, using inline createSafe_player, DIALOG_STYLE_TABLIST_HEADERS, "Choose your new safe (moving)", string, "Purchase", "Back");

	return 1;
}

SafeCreation_move(playerid, safeitem, safeid) {

	if(cash[playerid] < SafeList[safeitem][s_price] || SafeList[safeitem][s_price] < 1) return SCM(playerid, HEX_RED, "Error: You do not have enough money.");

	cash[playerid] -= SafeList[safeitem][s_price];
	GivePlayerMoney(playerid, -1*SafeList[safeitem][s_price]);

	new Float:s_pos[3];
	GetPlayerPos(playerid, s_pos[0], s_pos[1], s_pos[2]);
	new editsafe = CreateDynamicObject(SafeList[safeitem][s_objid], s_pos[0], s_pos[1], s_pos[2], 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid);
	SetPVarInt(playerid, "editsafe_move", editsafe);
	SetPVarInt(playerid, "safeitem_move", safeitem);
	SetPVarInt(playerid, "safeitemid", safeid);
	EditDynamicObject(playerid, editsafe);

	SCM(playerid, HEX_FADE2, "Remember, your safe cannot obstruct roleplay! Do not place them close to gates or in the air, and also do not use them as a ladder!");

	return 1;
}

SafeCreation(playerid, safeitem) {

	new psafes = 0;
	foreach(new i:Storages) {
		if(storageInfo[i][safe_playerid] == CharacterSQL[playerid]) {
			++psafes;
		}
		if(psafes >= MAX_PLAYER_SAFES)
			return SFM(playerid, HEX_RED, "Error: You already have %d/%d personal safes.", psafes, MAX_PLAYER_SAFES);
	}

	if(cash[playerid] < SafeList[safeitem][s_price] || SafeList[safeitem][s_price] < 1) return SCM(playerid, HEX_RED, "Error: You do not have enough money.");

	cash[playerid] -= SafeList[safeitem][s_price];
	GivePlayerMoney(playerid, -1*SafeList[safeitem][s_price]);

	new Float:s_pos[3];
	GetPlayerPos(playerid, s_pos[0], s_pos[1], s_pos[2]);
	new editsafe = CreateDynamicObject(SafeList[safeitem][s_objid], s_pos[0], s_pos[1], s_pos[2], 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid);
	SetPVarInt(playerid, "editsafe", editsafe);
	SetPVarInt(playerid, "safeitem", safeitem);
	EditDynamicObject(playerid, editsafe);

	SCM(playerid, HEX_FADE2, "Remember, your safe cannot obstruct roleplay! Do not place them close to gates or in the air, and also do not use them as a ladder!");

	return 1;
}

hook OnPlayerEditDynObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz) {
	new objid = GetPVarInt(playerid, "editsafe");
	if(objid > 0) {
		if(response == EDIT_RESPONSE_CANCEL) {
			DestroyDynamicObject(objid);
			cash[playerid] += SAFE_COST;
			GivePlayerMoney(playerid, SAFE_COST);
			DeletePVar(playerid, "editsafe");
			DeletePVar(playerid, "safeitem");
			return Y_HOOKS_BREAK_RETURN_1;
		}
		else if(response == EDIT_RESPONSE_FINAL) {

			new selsafe = GetPVarInt(playerid, "safeitem");

			mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `storages` (`objectid`, `interior`, `virtualworld`, `posx`, `posy`, `posz`, `rotx`, `roty`, `rotz`, `playerid`) VALUES ('%d', '%d', '%d', '%f', '%f', '%f', '%f', '%f', '%f', '%d')",  SafeList[selsafe][s_objid], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), x, y, z, rx, ry, rz, CharacterSQL[playerid]);
			mysql_tquery(g_SQL, sql, "", "");	

			DestroyDynamicObject(objid);
			DeletePVar(playerid, "editsafe");
			DeletePVar(playerid, "safeitem");

			LoadPlayerStoragePoint(CharacterSQL[playerid], playerid);
			return Y_HOOKS_BREAK_RETURN_1;
		}
	}
	else {
		objid = GetPVarInt(playerid, "editsafe_move");
		if(response == EDIT_RESPONSE_CANCEL) {
			DestroyDynamicObject(objid);
			cash[playerid] += SAFE_COST;
			GivePlayerMoney(playerid, SAFE_COST);
			DeletePVar(playerid, "editsafe_move");
			DeletePVar(playerid, "safeitem_move");
			return Y_HOOKS_BREAK_RETURN_1;
		}
		else if(response == EDIT_RESPONSE_FINAL) {

			new selsafe = GetPVarInt(playerid, "safeitem");

			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `storages` SET `objectid`='%d', `interior`='%d', `virtualworld`='%d', `posx`='%f', `posy`='%f', `posz`='%f', `rotx`='%f', `roty`='%f', `rotz`='%f' WHERE id = %d LIMIT 1", SafeList[selsafe][s_objid], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), x, y, z, rx, ry, rz, GetPVarInt(playerid, "safeitemid"));
			mysql_tquery(g_SQL, sql, "", "");	

			DestroyDynamicObject(objid);



			new rew = StorageID(GetPVarInt(playerid, "safeitemid"));

			storageInfo[rew][safe_objid] = SafeList[selsafe][s_objid];
			storageInfo[rew][safe_interior] = GetPlayerInterior(playerid);
			storageInfo[rew][safe_virtualworld] = GetPlayerVirtualWorld(playerid);

			storageInfo[rew][safe_pos][0] = x;
			storageInfo[rew][safe_pos][1] = y;
			storageInfo[rew][safe_pos][2] = z;

			storageInfo[rew][safe_rot][0] = rx;
			storageInfo[rew][safe_rot][1] = ry;
			storageInfo[rew][safe_rot][2] = rz;


			MoveStoragePoint(StorageID(GetPVarInt(playerid, "safeitemid")));

			DeletePVar(playerid, "editsafe_move");
			DeletePVar(playerid, "safeitem_move");
			DeletePVar(playerid, "safeitemid");
			
			return Y_HOOKS_BREAK_RETURN_1;
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}


LoadPlayerStoragePoint(playersql, playerid = -1) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `storages` WHERE state = 1 AND playerid = %d LIMIT %d", playersql, MAX_PLAYER_SAFES);
	inline LoadStorageData_player() {
		if(!cache_num_rows()) {
			printf("No storage point found in LoadPlayerStoragePoint playersql %d.", playersql);
			@return 0;
		}
		new i = Iter_Count(Storages);
		++i;
		new j = -1;
		for(;++j<cache_num_rows();) {
			new a;
			new bool:safeex = false;
			cache_get_value_int(j, "id", a);
			foreach(new k:Storages) {
				if(storageInfo[k][safe_sqlid] == a)
					safeex = true;
			}
			if(!safeex) {
				cache_get_value_int(j, "id", storageInfo[i][safe_sqlid]);
				//cache_get_value_int(j, "objectid", storageInfo[i][safe_object]);
				cache_get_value_int(j, "objectid", storageInfo[i][safe_object2]);
				cache_get_value_int(j, "objectid", storageInfo[i][safe_objid]);

				cache_get_value_int(j, "interior", storageInfo[i][safe_interior]);
				cache_get_value_int(j, "virtualworld", storageInfo[i][safe_virtualworld]);

				cache_get_value_float(j, "posx", storageInfo[i][safe_pos][0]);
				cache_get_value_float(j, "posy", storageInfo[i][safe_pos][1]);
				cache_get_value_float(j, "posz", storageInfo[i][safe_pos][2]);

				cache_get_value_float(j, "rotx", storageInfo[i][safe_rot][0]);
				cache_get_value_float(j, "roty", storageInfo[i][safe_rot][1]);
				cache_get_value_float(j, "rotz", storageInfo[i][safe_rot][2]);

				cache_get_value_int(j, "playerid", storageInfo[i][safe_playerid]);
				cache_get_value_int(j, "factionid", storageInfo[i][safe_factionid]);
				cache_get_value_int(j, "cityid", storageInfo[i][safe_cityid]);

				cache_get_value_int(j, "locked", storageInfo[i][safe_locked]);

				MoveStoragePoint(i);

				Iter_Add(Storages, i);

				printf("%d player storage has been loaded.", i);
			}
		}
		if(playerid > -1 && IsPlayerConnected(playerid))
			SFM(playerid, HEX_YELLOW, "%d personal safe(s) loaded!", j+1);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadStorageData_player, sql);
	return 1;
}

YCMD:mysafes(playerid, params[], help) {
	
	new psafes = 0, bool:smatch=false;
	
	foreach(new i:Storages) {
		if(storageInfo[i][safe_playerid] == CharacterSQL[playerid]) {
			++psafes;
			if(!smatch) {
				smatch = true;
				SCM(playerid, HEX_YELLOW, "List of your storages:");
			}
			SFM(playerid, HEX_FADE2, " - Safe SQLID %d", storageInfo[i][safe_sqlid]);
		}

	}

	if(smatch)
		SFM(playerid, HEX_YELLOW, "You  have %d/%d personal safes.", psafes, MAX_PLAYER_SAFES);
	else
		SCM(playerid, HEX_FADE2, "You do not have any safes.");

	return 1;
}

EmptySafeKeys(safeid) {

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_keys` SET `state` = '0' WHERE storageId = '%d' LIMIT 1", safeid);
	mysql_tquery(g_SQL, sql, "", "");

	return 1;
}