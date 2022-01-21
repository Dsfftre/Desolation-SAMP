/*#if defined _inc_territories
	#undef _inc_territories
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

new active_territories = 0;
new Iterator:Territories<MAX_TERRITORIES>;

enum territoryInfoEnum {
	sqlid,
	name[128],
	brand,
	factionId,
	cityId,
	groupId,
	Float:corners[8],
	Float:territory_cp[3],
	territory_checkpoint,
	stocks,
	area,
	gangzone
}
new territoryInfo[MAX_TERRITORIES][territoryInfoEnum];

static const TerritoryTypeName[][] = {
	"wasteland",
	"outpost",
	"headquarters",
	"farm",
	"laboratory",
	"factory"
};

hook OnGameModeInit() {
	LoadTerritories();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadTerritories() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `territory` WHERE state > 0");
	inline LoadTerritoriyData() {
		if(!cache_num_rows()) {
			print("No territories found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", territoryInfo[i][sqlid]);
			cache_get_value(i, "name", territoryInfo[i][name], 128);
			cache_get_value_int(i, "type", territoryInfo[i][brand]);
			cache_get_value_int(i, "factionId", territoryInfo[i][factionId]);			
			cache_get_value_int(i, "cityId", territoryInfo[i][cityId]);
			cache_get_value_int(i, "groupId", territoryInfo[i][groupId]);

			cache_get_value_float(i, "corner0", territoryInfo[i][corners][0]);
			cache_get_value_float(i, "corner1", territoryInfo[i][corners][1]);
			cache_get_value_float(i, "corner2", territoryInfo[i][corners][2]);
			cache_get_value_float(i, "corner3", territoryInfo[i][corners][3]);
			cache_get_value_float(i, "corner4", territoryInfo[i][corners][4]);
			cache_get_value_float(i, "corner5", territoryInfo[i][corners][5]);
			cache_get_value_float(i, "corner6", territoryInfo[i][corners][6]);
			cache_get_value_float(i, "corner7", territoryInfo[i][corners][7]);

			cache_get_value_float(i, "cp_x", territoryInfo[i][territory_cp][0]);
			cache_get_value_float(i, "cp_y", territoryInfo[i][territory_cp][1]);
			cache_get_value_float(i, "cp_z", territoryInfo[i][territory_cp][2]);

			cache_get_value_int(i, "stocks", territoryInfo[i][stocks]);

			territoryInfo[i][area] = Area_AddPoly(
				territoryInfo[i][corners][0], territoryInfo[i][corners][1], // Bottom left
				territoryInfo[i][corners][2], territoryInfo[i][corners][3], // Bottom right
				territoryInfo[i][corners][4], territoryInfo[i][corners][5], // Top right
				territoryInfo[i][corners][6], territoryInfo[i][corners][7]  // Top left
			);

			territoryInfo[i][gangzone] = GangZoneCreate(territoryInfo[i][corners][6], territoryInfo[i][corners][7], territoryInfo[i][corners][2], territoryInfo[i][corners][3]);

			territoryInfo[i][territory_checkpoint] = CreateDynamicCP(territoryInfo[i][territory_cp][0], territoryInfo[i][territory_cp][1], territoryInfo[i][territory_cp][2], CHECKPOINT_SIZE, 0, 0, -1, CHECKPOINT_RANGE);
			printf("Territory '%s' loaded.", territoryInfo[i][name]);
			Iter_Add(Territories, i);
			++active_territories;
		}
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadTerritoriyData, sql);
	return 1;
}

YCMD:setcorner(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");
	new whichcorner[3];
	if(sscanf(params,"s[3]",whichcorner)) return SCM(playerid, HEX_FADE2,"Usage: /setcorner [bl/br/tr/tl] (Hint: bottom left[bl], bottom right[br], top right[tr], top left[tl] - please be careful)");

	new Float:cornerpos[3];
	GetPlayerPos(playerid, cornerpos[0], cornerpos[1], cornerpos[2]);

	if(!strcmp(whichcorner, "bl", true)) {
		SetPVarFloat(playerid, "corner0",  cornerpos[0]);
		SetPVarFloat(playerid, "corner1",  cornerpos[1]);
		SCM(playerid, HEX_FADE2, "Bottom left corner selected!");
	}
	else if(!strcmp(whichcorner, "br", true)) {
		SetPVarFloat(playerid, "corner2",  cornerpos[0]);
		SetPVarFloat(playerid, "corner3",  cornerpos[1]);
		SCM(playerid, HEX_FADE2, "Bottom right corner selected!");
	}
	else if(!strcmp(whichcorner, "tr", true)) {
		SetPVarFloat(playerid, "corner4",  cornerpos[0]);
		SetPVarFloat(playerid, "corner5",  cornerpos[1]);
		SCM(playerid, HEX_FADE2, "Top right corner selected!");
	}
	else if(!strcmp(whichcorner, "tl", true)) {
		SetPVarFloat(playerid, "corner6",  cornerpos[0]);
		SetPVarFloat(playerid, "corner7",  cornerpos[1]);
		SCM(playerid, HEX_FADE2, "Top left corner selected!");
	}
	else
		SCM(playerid, HEX_FADE2,"Usage: /setcorner [bl/br/tr/tl] (Hint: bottom left[bl], bottom right[br], top right[tr], top left[tl] - please be careful)");

	return 1;
}


YCMD:newterritory(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");
	if(active_territories >= MAX_TERRITORIES)  return SCM(playerid, HEX_RED, "Error: Territory number limit reached. Increase MAX_TERRITORIES in the script!");
	new territorytype, territoryname[128];
	if(sscanf(params,"is[128]",territorytype, territoryname)) return SCM(playerid, HEX_FADE2,"Usage: /newterritory [brand] [name] (Hint: wasteland[0], outpost[1], headquarters[2], farm[3], laboratory[4], factory[5])");
	if(GetPVarFloat(playerid, "corner0") == 0.0 || GetPVarFloat(playerid, "corner2") == 0.0 || GetPVarFloat(playerid, "corner4") == 0.0 || GetPVarFloat(playerid, "corner6") == 0.0) return SCM(playerid, HEX_RED, "Error: Please select the territory corners first. Use: /setcorner");

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `territory` (`name`, `type`, `corner0`, `corner1`, `corner2`, `corner3`, `corner4`, `corner5`, `corner6`, `corner7`) VALUES ('%e', '%d', '%f', '%f', '%f', '%f', '%f', '%f', '%f', '%f')", territoryname, territorytype, GetPVarFloat(playerid, "corner0"), GetPVarFloat(playerid, "corner1"), GetPVarFloat(playerid, "corner2"), GetPVarFloat(playerid, "corner3"), GetPVarFloat(playerid, "corner4"), GetPVarFloat(playerid, "corner5"), GetPVarFloat(playerid, "corner6"), GetPVarFloat(playerid, "corner7"));
    mysql_tquery(g_SQL, sql, "", "");

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has created a new type %d territory named '%s'.", PlayerName(playerid), playerid, territorytype, territoryname);
	SendAdminMessage(HEX_YELLOW, string, true);

	DeletePVar(playerid, "corner0");
	DeletePVar(playerid, "corner1");
	DeletePVar(playerid, "corner2");
	DeletePVar(playerid, "corner3");
	DeletePVar(playerid, "corner4");
	DeletePVar(playerid, "corner5");
	DeletePVar(playerid, "corner6");
	DeletePVar(playerid, "corner7");
	LoadLastTerritory();

	return 1;
}


LoadLastTerritory() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `territory` WHERE state > 0 ORDER BY id DESC LIMIT 1");
	inline LoadTerritoriyData() {
		if(!cache_num_rows()) {
			print("Error: No territory found during LoadLastTerritory().");
			@return 0;
		}

		cache_get_value_int(0, "id", territoryInfo[active_territories][sqlid]);
		cache_get_value(0, "name", territoryInfo[active_territories][name], 128);
		cache_get_value_int(0, "type", territoryInfo[active_territories][brand]);
		cache_get_value_int(0, "factionId", territoryInfo[active_territories][factionId]);			
		cache_get_value_int(0, "cityId", territoryInfo[active_territories][cityId]);
		cache_get_value_int(0, "groupId", territoryInfo[active_territories][groupId]);

		cache_get_value_float(0, "corner0", territoryInfo[active_territories][corners][0]);
		cache_get_value_float(0, "corner1", territoryInfo[active_territories][corners][1]);
		cache_get_value_float(0, "corner2", territoryInfo[active_territories][corners][2]);
		cache_get_value_float(0, "corner3", territoryInfo[active_territories][corners][3]);
		cache_get_value_float(0, "corner4", territoryInfo[active_territories][corners][4]);
		cache_get_value_float(0, "corner5", territoryInfo[active_territories][corners][5]);
		cache_get_value_float(0, "corner6", territoryInfo[active_territories][corners][6]);
		cache_get_value_float(0, "corner7", territoryInfo[active_territories][corners][7]);

		cache_get_value_float(0, "cp_x", territoryInfo[active_territories][territory_cp][0]);
		cache_get_value_float(0, "cp_y", territoryInfo[active_territories][territory_cp][1]);
		cache_get_value_float(0, "cp_z", territoryInfo[active_territories][territory_cp][2]);

		cache_get_value_int(0, "stocks", territoryInfo[active_territories][stocks]);

		territoryInfo[active_territories][area] = Area_AddPoly(
			territoryInfo[active_territories][corners][0], territoryInfo[active_territories][corners][1], // Bottom left
			territoryInfo[active_territories][corners][2], territoryInfo[active_territories][corners][3], // Bottom right
			territoryInfo[active_territories][corners][4], territoryInfo[active_territories][corners][5], // Top right
			territoryInfo[active_territories][corners][6], territoryInfo[active_territories][corners][7]  // Top left
		);

		territoryInfo[active_territories][territory_checkpoint] = CreateDynamicCP(territoryInfo[active_territories][territory_cp][0], territoryInfo[active_territories][territory_cp][1], territoryInfo[active_territories][territory_cp][2], CHECKPOINT_SIZE, 0, 0, -1, CHECKPOINT_RANGE);

		printf("Territory '%s' loaded.", territoryInfo[active_territories][name]);

		
		++active_territories;

	}
	MySQL_TQueryInline(g_SQL, using inline LoadTerritoriyData, sql);
	return 1;
}


hook OnPlayerEnterArea(playerid, areaid) {
	if(DEBUGMSG && adminlevel[playerid] != 0) SFM(playerid, HEX_YELLOW, "Debug: You entered area id %d.", areaid);

	if(Bit_Get(togszones, playerid)) {

		new i = GetTerritoryIdFromArea(areaid);
		if(i == -1) return Y_HOOKS_CONTINUE_RETURN_1;

		new string[256];
		format(string, sizeof string, "~w~%s~n~~y~Type: %s~n~~b~Faction: %s~b~~n~City: %s", territoryInfo[i][name], TerritoryTypeName[territoryInfo[i][brand]], GetSQLFactionname(territoryInfo[i][factionId]), GetSQLCityname(territoryInfo[i][cityId]));

		GameTextForPlayer(playerid, string, 5000, 4);

		if(Group_GetPlayer(g_AdminDuty, playerid))
			SFM(playerid, HEX_YELLOW, "Territory sqlid:[%d] name:[%s] type:[%s] faction:[%s] city:[%s]", territoryInfo[i][sqlid], territoryInfo[i][name], TerritoryTypeName[territoryInfo[i][brand]], GetSQLFactionname(territoryInfo[i][factionId]), GetSQLCityname(territoryInfo[i][cityId]));


		//if(adminlevel[playerid] != 0) SFM(playerid, HEX_YELLOW, string);

	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}


GetTerritoryIdFromArea(areaid) {
	foreach(new i:Territories) {
		if(territoryInfo[i][area] == areaid) 
			return i;
	}
	return -1;
}


GetTerritoryId(terid) {
	foreach(new i:Territories) {
		if(territoryInfo[i][sqlid] == terid) 
			return i;
	}
	return -1;
}


YCMD:territorycp(playerid, params[], help) {// dev note: could display territory name, reload checkpoint and use area id (or name) instead of sqlid
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");
	new targetter;
	if(sscanf(params,"d",targetter)) return SCM(playerid, HEX_FADE2,"Usage: /territorycp [sqlid]");

	new terid = GetTerritoryId(targetter);
	if(terid == -1)  return SCM(playerid, HEX_RED,"Error: Invalid territory id.");

	new Float:ter_cp[3];
	GetPlayerPos(playerid, ter_cp[0], ter_cp[1], ter_cp[2]);

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `territory` SET `cp_x` = %f, `cp_y` = %f, `cp_z` = %f WHERE id = %d LIMIT 1", ter_cp[0], ter_cp[1], ter_cp[2], targetter);
	mysql_tquery(g_SQL, sql, "", "");

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has moved territory %s's checkpoint.", PlayerName(playerid), playerid, territoryInfo[terid][name]);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}


YCMD:territoryfaction(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");
	new targetter, factionter;
	if(sscanf(params,"dd",targetter, factionter)) return SCM(playerid, HEX_FADE2,"Usage: /territoryfaction [sqlid] [factionid]");

	new terid = GetTerritoryId(targetter);
	if(terid == -1)  return SCM(playerid, HEX_RED,"Error: Invalid territory id.");
	if(!FactionExists(factionter)) return SCM(playerid, HEX_RED, "Error: Invalid faction.");
	

	territoryInfo[terid][factionId] = factionter;

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `territory` SET `factionId` = %d WHERE id = %d LIMIT 1", factionter, targetter);
	mysql_tquery(g_SQL, sql, "", "");

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has changed territory %s's faction to %s [%d].", PlayerName(playerid), playerid, territoryInfo[terid][name], fInfo[factionter][name], factionter);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

YCMD:territorycity(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");
	new targetter, cityter;
	if(sscanf(params,"dd",targetter, cityter)) return SCM(playerid, HEX_FADE2,"Usage: /territorycity [sqlid] [cityid]");

	new terid = GetTerritoryId(targetter);
	if(terid == -1)  return SCM(playerid, HEX_RED,"Error: Invalid territory id.");
	if(!CityExists(cityter)) return SCM(playerid, HEX_RED, "Error: Invalid microcity.");

	territoryInfo[terid][cityId] = cityter;

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `territory` SET `cityId` = %d WHERE id = %d LIMIT 1", cityter, targetter);
	mysql_tquery(g_SQL, sql, "", "");

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has changed territory %s's city to %s [%d].", PlayerName(playerid), playerid, territoryInfo[terid][name], cityInfo[cityter][name], cityter);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

YCMD:territorytype(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");
	new targetter, typeter;
	if(sscanf(params,"dd",targetter, typeter)) return SCM(playerid, HEX_FADE2,"Usage: /territorytype [sqlid] [brand] (Hint: wasteland[0], outpost[1], headquarters[2], farm[3], laboratory[4], factory[5])");

	new terid = GetTerritoryId(targetter);
	if(terid == -1)  return SCM(playerid, HEX_RED,"Error: Invalid territory id.");

	territoryInfo[terid][brand] = typeter;

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `territory` SET `type` = %d WHERE id = %d LIMIT 1", typeter, targetter);
	mysql_tquery(g_SQL, sql, "", "");
	printf("%s", sql);

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has changed territory %s's type to %d.", PlayerName(playerid), playerid, territoryInfo[terid][name], typeter);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

YCMD:territoryname(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");
	new targetter, nameter[128];
	if(sscanf(params,"ds[128]",targetter, nameter)) return SCM(playerid, HEX_FADE2,"Usage: /territoryname [sqlid] [name])");

	new terid = GetTerritoryId(targetter);
	if(terid == -1) return SCM(playerid, HEX_RED,"Error: Invalid territory id.");

	territoryInfo[terid][name] = nameter;

	//format(territoryInfo[terid][name], sizeof territoryInfo[terid][name], "%s", nameter);

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `territory` SET `name` = '%e' WHERE id = %d LIMIT 1", nameter, targetter);
	mysql_tquery(g_SQL, sql, "", "");
	printf("%s", sql);

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has changed territory %s's name to %s.", PlayerName(playerid), playerid, territoryInfo[terid][name], nameter);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

hook OnPlayerEnterDynamicCP(playerid, checkpointid) {
	foreach(new i:Territories) {
		if(territoryInfo[i][territory_checkpoint] == checkpointid) {
			//SetPVarInt(playerid, "activeterritory", i);
			ShowTerritoryDialog(playerid, territoryInfo[i][brand], i);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}


ShowTerritoryDialog(playerid, terrtype, territoryid) {
	new string[512];

	switch(terrtype) {
		case 0: string="This territory is currently not functioning.\n\nTo make use of this territory claim it, then role-play building something on it. \nYou can submit a request on the forums to change the current type.\n\nList of types:\n\t0 - wasteland\n\t1 - outpost\n\t2 - headquarters\n\t3 - farm\n\t4 - laboratory\n\t5 - factory";
		case 1: string="This territory is an outpost.\n\nOnly the owner can request safehouse changes in this area.";
		case 2: string="This territory is an HQ.\n\nOnly the owner can request safehouse changes in this area.";
		case 3: string="This territory is a farm.\n\nFood can be requested from the staff team upon role-playing production.";
		case 4: string="This territory is a laboratory.\n\nMedical equipments can be requested from the staff team upon role-playing production.";
		case 5: string="This territory is a factory.\n\nWeapons can be requested from the staff team upon role-playing production.";
		case 6: string="This territory is an oil well.\n\nWIP! For now, unfortunately nothing can be requested from the staff team upon role-playing production.";
	}

	inline Dialog_territory_Main(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		//DeletePVar(playerid, "activeterritory");
		@return 1;
	}	
	Dialog_ShowCallback(playerid, using inline Dialog_territory_Main, DIALOG_STYLE_MSGBOX, territoryInfo[territoryid][name], string, "Exit");

	return 1;
}
 

stock TerritoryColor(ter_type) {

	switch(ter_type) {
		case 1: return 0x141228AA;
		case 2: return 0x2e3442AA;
		case 3: return 0xf1ca7fAA;
		case 4: return 0xb7d2cdAA;
		case 5: return 0xe35d5eAA;

	}
	return 0xf6f1eeAA;
}

ResetTerritoryGangzones(playerid) {

	foreach(new i:Territories) {
		GangZoneHideForPlayer(playerid, territoryInfo[i][gangzone]);
		if(Bit_Get(togszones, playerid))
			GangZoneShowForPlayer(playerid, territoryInfo[i][gangzone], TerritoryColor(territoryInfo[i][brand]));
	}

	return 1;
}

hook OnPlayerSpawn(playerid) {

	ResetTerritoryGangzones(playerid);

	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:aterritoryhelp(playerid, params[], help) {
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");
	
	SCM(playerid, HEX_YELLOW, "Territory commands:");
	SCM(playerid, HEX_FADE2, "To create a territory first set it's corners with /setcorner, then use /newterritory");
	SCM(playerid, HEX_FADE2, "/territoryname /territorytype /territorycity /territoryfaction /territorycp");

	return 1;
}