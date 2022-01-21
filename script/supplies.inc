/*#if defined _inc_supplies
	#undef _inc_supplies
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

#define MAX_SUPPLIES 5
#define MAX_TRAILERS 8
#define SUPPLY_MAP_ICON_OIL 51 //truck
#define SUPPLY_MAP_ICON_WEAPONS 6 //gray pistol
#define SUPPLY_MAP_ICON_MEDICAL 22 //hospital

#define SUPPLY_PRICE_OIL 50
#define SUPPLY_PRICE_MEDICAL 100
#define SUPPLY_PRICE_WEAPON 300


enum supplyInfoEnum {
	sqlid,
	brand,
	Float:pos[3],
	checkpoint,
	supplies
}
new supplyInfo[MAX_SUPPLIES][supplyInfoEnum];

enum trailerInfoEnum {
	sqlid,
	Float:pos[3],
	brand,
	cargotype,
	cargoamount,
	vid
}
new trailerInfo[MAX_TRAILERS][trailerInfoEnum];

YCMD:loadsupply(playerid, params[], help) {
	new j = -1;
	new Float:spos[3];
	for(;++j<MAX_TRAILERS;) {
		GetVehiclePos(trailerInfo[j][vid], spos[0], spos[1], spos[2]);
		if(GetPlayerDistanceFromPoint(playerid, spos[0], spos[1], spos[2]) < 6.0) {
			new supplyitems[3][2];
			mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_items` WHERE state = 1 AND playerId = %d AND itemId > 48 AND itemId < 52", CharacterSQL[playerid]);
			inline LoadCarrySupplies() {
				if(!cache_num_rows()) {
					SCM(playerid, HEX_FADE2, "You don't have any supply items in your inventory.");
					@return 0;
				}
				new i = -1;
				for(;++i<cache_num_rows();) {
					cache_get_value_int(i, "itemId", supplyitems[i][0]);
					cache_get_value_int(i, "amount", supplyitems[i][1]);

					if(trailerInfo[j][cargotype] == supplyitems[i][0] || trailerInfo[j][cargotype] == 0) {
						if(trailerInfo[j][cargoamount] > 9) {
							SCM(playerid, HEX_FADE2, "The trailer is already full.");
							@return 0;
						}
						mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` set `STATE` = 0, `modPlayerId` = %d, `modDate` = CURRENT_TIMESTAMP WHERE state = 1 AND playerId = %d AND itemId = %d AND amount = %d LIMIT 1", CharacterSQL[playerid], CharacterSQL[playerid], supplyitems[i][0], supplyitems[i][1]);
						mysql_tquery(g_SQL, sql);
						trailerInfo[j][cargotype] = supplyitems[i][0];
						trailerInfo[j][cargoamount] += supplyitems[i][1];
						SCM(playerid, HEX_WHITE, "You have loaded your supplies into the trailer.");
						@return 1;
					}
				}
				SCM(playerid, HEX_FADE2, "The trailer has a different type of cargo.");
				@return 0;
			}
			MySQL_TQueryInline(g_SQL, using inline LoadCarrySupplies, sql);
			return 1;
		}
	}
	SCM(playerid, HEX_FADE2, "You need to be close to a trailer.");
	return 1;
}

/*YCMD:checksupply(playerid, params[], help) {
	if(!IsTruck(GetPlayerVehicleID(playerid))) { SCM(playerid, HEX_FADE2, "You must be in a truck attached to a trailer."); return 1; }
	if(!IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)) ) { SCM(playerid, HEX_FADE2, "You must have a trailer attached."); return 1; }

	new trailerid = GetVehicleTrailer(GetPlayerVehicleID(playerid));

	new j = -1;
	for(;++j<MAX_TRAILERS;) {
		if(trailerInfo[j][vid] == trailerid) {
			switch(trailerInfo[j][cargotype]) {
				case 0: SCM(playerid, HEX_WHITE, "The trailer is empty.");
				case 49: SFM(playerid, HEX_WHITE, "The trailer has %d barrels of oil.", trailerInfo[j][cargoamount]);
				case 50: SFM(playerid, HEX_WHITE, "The trailer has %d medical supply boxes.", trailerInfo[j][cargoamount]);
				case 51: SFM(playerid, HEX_WHITE, "The trailer has %d weapon supply boxes.", trailerInfo[j][cargoamount]);
			}
			return 1;
		}
	}

	SCM(playerid, HEX_FADE2, "There was an error fetching the trailer's cargo.");
	return 1;
}
*/

hook OnPlayerEnterDynamicCP(playerid, checkpointid) {
	new i = -1;
	for(;++i<MAX_SUPPLIES;) {
		if(checkpointid == supplyInfo[i][checkpoint]) {
			switch(supplyInfo[i][brand]) {
				case 49: ShowOilCheckpoint(playerid);
				case 50: ShowMedicalCheckpoint(playerid);
				case 51: ShowWeaponsCheckpoint(playerid);
			}			
			return Y_HOOKS_BREAK_RETURN_1;
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

ShowWeaponsCheckpoint(playerid) {
	new string[1024];
	new string2[128];
	format(string, sizeof string, "Product\tPrice\t\n");
	format(string2, sizeof string2, "1x Weapon Box\t$%d\n", SUPPLY_PRICE_WEAPON);
	strcat(string, string2);

	inline Dialog_weapon_supply(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response) {
			new price,
				oil;
			switch(Open_listitem) {
				case 0: { price = SUPPLY_PRICE_WEAPON; oil = 1; }
			}

			if(cash[playerid] < price) { SCM(playerid, HEX_FADE2, "You don't have enough money on hand."); return Y_HOOKS_BREAK_RETURN_1; }
			if(HasPlayerItem(playerid, 51))  { SCM(playerid, HEX_FADE2, "You can only carry one supply item in hand. Use /loadsupply at a trailer."); return Y_HOOKS_BREAK_RETURN_1; }
			
			GivePlayerItem(playerid, 51);
			cash[playerid] -= price;
			GivePlayerMoney(playerid, price*-1);
			SFM(playerid, HEX_WHITE, "You have purchased %d weapon supply box.", oil);
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `loadbays` SET `used` = `used`+1 WHERE type = '51' LIMIT 1");
			mysql_tquery(g_SQL, sql, "", "");
		}
	}	
	Dialog_ShowCallback(playerid, using inline Dialog_weapon_supply, DIALOG_STYLE_TABLIST_HEADERS, "Weapon Supply Depot", string, "Purchase","Exit");
	return 1;
}

ShowMedicalCheckpoint(playerid) {
	if(!IsPlayerInAnyVehicle(playerid)) { SCM(playerid, HEX_FADE2, "You must bring a truck to transport medical supplies."); return Y_HOOKS_BREAK_RETURN_1; }
	//if(!IsTruck(GetPlayerVehicleID(playerid))) { SCM(playerid, HEX_FADE2, "You must bring a truck to transport medical supplies."); return Y_HOOKS_BREAK_RETURN_1; }
	if(!IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)) ) { SCM(playerid, HEX_FADE2, "You must have a trailer attached."); return Y_HOOKS_BREAK_RETURN_1; }
	
	new string[1024];
	new string2[128];
	format(string, sizeof string, "Product\tPrice\t\n");
	format(string2, sizeof string2, "1x Medical Box\t$%d\n", SUPPLY_PRICE_MEDICAL);
	strcat(string, string2);
	format(string2, sizeof string2, "5x Medical Boxes\t$%d\n", SUPPLY_PRICE_MEDICAL*5);
	strcat(string, string2);
	format(string2, sizeof string2, "10x Medical Boxes\t$%d\n", SUPPLY_PRICE_MEDICAL*10);
	strcat(string, string2);

	inline Dialog_medical_supply(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response) {
			new price,
				oil;
			switch(Open_listitem) {
				case 0: { price = SUPPLY_PRICE_MEDICAL; oil = 1; }
				case 1: { price = SUPPLY_PRICE_MEDICAL*5; oil = 5; }
				case 2: { price = SUPPLY_PRICE_MEDICAL*10; oil = 10; }
			}

			new trailerid = GetVehicleTrailer(GetPlayerVehicleID(playerid));

			//if(!IsTruck(GetPlayerVehicleID(playerid))) { SCM(playerid, HEX_FADE2, "You must bring a truck to transport medical supplies."); return Y_HOOKS_BREAK_RETURN_1; }
			if(trailerid == 0) { SCM(playerid, HEX_FADE2, "You must have a trailer attached."); return Y_HOOKS_BREAK_RETURN_1; }
			if(cash[playerid] < price) { SCM(playerid, HEX_FADE2, "You don't have enough money on hand."); return Y_HOOKS_BREAK_RETURN_1; }
			
			new j = -1;
			for(;++j<MAX_TRAILERS;) {
				if(trailerInfo[j][vid] == trailerid) {
					if(trailerInfo[j][cargotype] == 0 || trailerInfo[j][cargotype] == 50) {
						if(trailerInfo[j][cargotype] == 50) {
							if(trailerInfo[j][cargoamount] == 10) { SCM(playerid, HEX_FADE2, "The trailer is already full."); return Y_HOOKS_BREAK_RETURN_1; }
							if(trailerInfo[j][cargoamount] + oil > 10) { SCM(playerid, HEX_FADE2, "The trailer can only hold 10 medical supply boxes."); return Y_HOOKS_BREAK_RETURN_1; }
						}
						cash[playerid] -= price;
						GivePlayerMoney(playerid, price*-1);
						trailerInfo[j][cargotype] = 50;
						trailerInfo[j][cargoamount] += oil;
						SFM(playerid, HEX_WHITE, "You have loaded %d medical supply boxes into your trailer.", oil);
						mysql_format(g_SQL, sql, sizeof sql, "UPDATE `loadbays` SET `used` = `used`+1 WHERE type = '50' LIMIT 1");
						mysql_tquery(g_SQL, sql, "", "");
					}
					else
						SCM(playerid, HEX_FADE2, "This trailer is already loaded.");
					break;
				}
			}


		}
	}	
	Dialog_ShowCallback(playerid, using inline Dialog_medical_supply, DIALOG_STYLE_TABLIST_HEADERS, "Medical Supply Depot", string, "Purchase","Exit");
	return 1;
}

ShowOilCheckpoint(playerid) {
	if(!IsPlayerInAnyVehicle(playerid)) { SCM(playerid, HEX_FADE2, "You must bring a truck to transport oil supplies."); return Y_HOOKS_BREAK_RETURN_1; }
	//if(!IsTruck(GetPlayerVehicleID(playerid))) { SCM(playerid, HEX_FADE2, "You must bring a truck to transport oil supplies."); return Y_HOOKS_BREAK_RETURN_1; }
	if(!IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)) ) { SCM(playerid, HEX_FADE2, "You must have a trailer attached."); return Y_HOOKS_BREAK_RETURN_1; }
	
	new string[1024];
	new string2[128];
	format(string, sizeof string, "Product\tPrice\t\n");
	format(string2, sizeof string2, "1x Oil Barrel\t$%d\n", SUPPLY_PRICE_OIL);
	strcat(string, string2);
	format(string2, sizeof string2, "5x Oil Barrels\t$%d\n", SUPPLY_PRICE_OIL*5);
	strcat(string, string2);
	format(string2, sizeof string2, "10x Oil Barrels\t$%d\n", SUPPLY_PRICE_OIL*10);
	strcat(string, string2);

	inline Dialog_oil_supply(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response) {
			new price,
				oil;
			switch(Open_listitem) {
				case 0: { price = SUPPLY_PRICE_OIL; oil = 1; }
				case 1: { price = SUPPLY_PRICE_OIL*5; oil = 5; }
				case 2: { price = SUPPLY_PRICE_OIL*10; oil = 10; }
			}

			new trailerid = GetVehicleTrailer(GetPlayerVehicleID(playerid));

			//if(!IsTruck(GetPlayerVehicleID(playerid))) { SCM(playerid, HEX_FADE2, "You must bring a truck to transport oil supplies."); return Y_HOOKS_BREAK_RETURN_1; }
			if(trailerid == 0) { SCM(playerid, HEX_FADE2, "You must have a trailer attached."); return Y_HOOKS_BREAK_RETURN_1; }
			if(cash[playerid] < price) { SCM(playerid, HEX_FADE2, "You don't have enough money on hand."); return Y_HOOKS_BREAK_RETURN_1; }
			
			new j = -1;
			for(;++j<MAX_TRAILERS;) {
				if(trailerInfo[j][vid] == trailerid) {
					if(trailerInfo[j][cargotype] == 0 || trailerInfo[j][cargotype] == 49) {
						if(trailerInfo[j][cargotype] == 49) {
							if(trailerInfo[j][cargoamount] == 10) { SCM(playerid, HEX_FADE2, "The trailer is already full."); return Y_HOOKS_BREAK_RETURN_1; }
							if(trailerInfo[j][cargoamount] + oil > 10) { SCM(playerid, HEX_FADE2, "The trailer can only hold 10 barrels of oil."); return Y_HOOKS_BREAK_RETURN_1; }
						}
						cash[playerid] -= price;
						GivePlayerMoney(playerid, price*-1);
						trailerInfo[j][cargotype] = 49;
						trailerInfo[j][cargoamount] += oil;
						SFM(playerid, HEX_WHITE, "You have loaded %d barrels of oil into your trailer.", oil);
						mysql_format(g_SQL, sql, sizeof sql, "UPDATE `loadbays` SET `used` = `used`+1 WHERE type = '49' LIMIT 1");
						mysql_tquery(g_SQL, sql, "", "");
					}
					else
						SCM(playerid, HEX_FADE2, "This trailer is already loaded.");
					break;
				}
			}


		}
	}	
	Dialog_ShowCallback(playerid, using inline Dialog_oil_supply, DIALOG_STYLE_TABLIST_HEADERS, "Oil Supply Depot", string, "Purchase","Exit");
	return 1;
}



hook OnGameModeInit() {
	LoadSupplies();
	//LoadTrailers();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

/*LoadTrailers() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `trailers` WHERE state > 0 LIMIT %d", MAX_TRAILERS);
	inline LoadSupplyData() {
		if(!cache_num_rows()) {
			print("No supplies found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", trailerInfo[i][sqlid]);
			cache_get_value_int(i, "type", trailerInfo[i][brand]);
			cache_get_value_float(i, "posx", trailerInfo[i][pos][0]);
			cache_get_value_float(i, "posy", trailerInfo[i][pos][1]);
			cache_get_value_float(i, "posz", trailerInfo[i][pos][2]);
			if(IsTrailerModel(trailerInfo[i][brand]))
				trailerInfo[i][vid] = CreateVehicle(trailerInfo[i][brand], trailerInfo[i][pos][0], trailerInfo[i][pos][1], trailerInfo[i][pos][2], 0.0, random(64), random(64), -1, 0);
		}
		printf("%d trailers loaded.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadSupplyData, sql);
	return 1;
}

LoadSupplies() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `loadbays` WHERE state > 0");
	inline LoadSupplyData() {
		if(!cache_num_rows()) {
			print("No supplies found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", supplyInfo[i][sqlid]);
			cache_get_value_int(i, "type", supplyInfo[i][brand]);
			cache_get_value_float(i, "posx", supplyInfo[i][pos][0]);
			cache_get_value_float(i, "posy", supplyInfo[i][pos][1]);
			cache_get_value_float(i, "posz", supplyInfo[i][pos][2]);
			supplyInfo[i][supplies] = 3;

			switch(supplyInfo[i][brand]) {
				case 49: {
					supplyInfo[i][checkpoint] = CreateDynamicCP(supplyInfo[i][pos][0], supplyInfo[i][pos][1], supplyInfo[i][pos][2], 4.0, 0, 0, -1, 20.0);
					CreateDynamicMapIcon(supplyInfo[i][pos][0], supplyInfo[i][pos][1], supplyInfo[i][pos][2], SUPPLY_MAP_ICON_OIL, 0, 0, 0, -1, 1000.0, MAPICON_GLOBAL, -1, 0);
				}
				case 50: {
					supplyInfo[i][checkpoint] = CreateDynamicCP(supplyInfo[i][pos][0], supplyInfo[i][pos][1], supplyInfo[i][pos][2], 4.0, 0, 0, -1, 20.0);
					CreateDynamicMapIcon(supplyInfo[i][pos][0], supplyInfo[i][pos][1], supplyInfo[i][pos][2], SUPPLY_MAP_ICON_MEDICAL, 0, 0, 0, -1, 1200.0, MAPICON_GLOBAL, -1, 0);
				}
				case 51: {
					supplyInfo[i][checkpoint] = CreateDynamicCP(supplyInfo[i][pos][0], supplyInfo[i][pos][1], supplyInfo[i][pos][2], 1.0, 0, 0, -1, 12.0);
					CreateDynamicMapIcon(supplyInfo[i][pos][0], supplyInfo[i][pos][1], supplyInfo[i][pos][2], SUPPLY_MAP_ICON_WEAPONS, 0, 0, 0, -1, 500.0, MAPICON_GLOBAL, -1, 0);
				}
			}
			
		}
		printf("%d supply depots loaded.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadSupplyData, sql);
	return 1;
}*/

