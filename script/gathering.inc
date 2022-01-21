/*#if defined _inc_territories
	#undef _inc_territories
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

static active_gathering_nodes = 0;
new Iterator:Gathering<MAX_GATHERABLES>;

enum gatheringInfoEnum {
	sqlid,
	gattype,
	glevel,
	bool:status,//devnote should be turned into a bit
	Float:gpos[3],
	interior,
	virtualworld
}
new gatheringInfo[MAX_GATHERABLES][gatheringInfoEnum];

hook OnGameModeInit() {
	LoadGatherables();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadGatherables() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `gathering` WHERE state > 0");
	inline LoadGatheringData() {
		if(!cache_num_rows()) {
			print("No gathering nodes found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", gatheringInfo[i][sqlid]);
			cache_get_value_int(i, "type", gatheringInfo[i][gattype]);
			cache_get_value_int(i, "level", gatheringInfo[i][glevel]);

			gatheringInfo[i][status] = 0;

			cache_get_value_float(i, "posx", gatheringInfo[i][gpos][0]);
			cache_get_value_float(i, "posy", gatheringInfo[i][gpos][1]);
			cache_get_value_float(i, "posz", gatheringInfo[i][gpos][2]);

			cache_get_value_int(i, "interior", gatheringInfo[i][interior]);
			cache_get_value_int(i, "virtualworld", gatheringInfo[i][virtualworld]);

			CreateGatherable(i);

			Iter_Add(Gathering, i);
			++active_gathering_nodes;
		}
		printf("%d gatherables loaded.", active_gathering_nodes);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadGatheringData, sql);
	return 1;
}

stock Float:GetZFix(objectid) {
	switch(objectid) {
		case 857: return 0.9;
		case 861: return 0.9;
		case 862: return 0.9;
		case 1271: return 0.7;
		case 1773: return 0.4;
		case 2943: return 0.4;
		case 2976: return 0.9;
		case 3929: return 0.7;
		case 3930: return 0.7;
		case 3931: return 0.7;
	}
	return 0.0;
}


CreateGatherable(gatherid) {
	if(gatheringInfo[gatherid][status] == 1) return 0;
	gatheringInfo[gatherid][status] = 1;
	new gmodelid = GetRandomGatherableObject(gatheringInfo[gatherid][gattype], gatheringInfo[gatherid][glevel]);
	CreateDynamicObject(gmodelid, gatheringInfo[gatherid][gpos][0], gatheringInfo[gatherid][gpos][1], gatheringInfo[gatherid][gpos][2]-GetZFix(gmodelid), 0.0, 0.0, 0.0, gatheringInfo[gatherid][virtualworld], gatheringInfo[gatherid][interior]);
	return 1;
}

GetRandomGatherableObject(gat_type, gat_level) {
	switch(gat_type) {
		case 0: {//archeology / scavenging
			switch(gat_level) {
				case 0: return 1271;
				case 1: return 2943;
				case 2: return 1773;
				default: return 1271;
			}
		}
		case 1: {//biological
			switch(gat_level) {
				case 0: return 861;
				case 1: return 862;
				case 2: return 857;
				default: return 861;
			}
		}
		case 2: {//mining
			switch(gat_level) {
				case 0: return 3929;
				case 1: return 3930;
				case 2: return 3931;
				default: return 3929;
			}
		}
	}
	return 2114;
}

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
}