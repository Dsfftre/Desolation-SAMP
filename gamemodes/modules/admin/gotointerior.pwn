YCMD:gotointerior(playerid, params[], help) {
	if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid;
	if(sscanf(params, "i",targetid)) return SCM(playerid, HEX_FADE2, "Usage: /gotointerior [id] (0-145)");
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `interiorlist` WHERE id = '%i' LIMIT 1", targetid);

	inline LoadSAMPInterior() {
		if(!cache_num_rows()) {
			SCM(playerid, HEX_RED, "Error: Invalid interior id.");
			@return 0;
		}
		
		new Float:gotointerior_pos[4];
		new gotointerior_int;
		new gotointerior_intname[128];
		
		cache_get_value_int(0, "interior", gotointerior_int);
		cache_get_value(0, "name", gotointerior_intname, 128);		
		cache_get_value_float(0, "posx", gotointerior_pos[0]);
		cache_get_value_float(0, "posy", gotointerior_pos[1]);
		cache_get_value_float(0, "posz", gotointerior_pos[2]);
		cache_get_value_float(0, "posf", gotointerior_pos[3]);
		
		SetPlayerInterior(playerid, gotointerior_int);
		SetPlayerPos(playerid, gotointerior_pos[0],gotointerior_pos[1],gotointerior_pos[2]);
		SetPlayerFacingAngle(playerid,gotointerior_pos[3]);
		SFM(playerid, HEX_FADE2, "You have teleported to interior %s (%i), int: %i, world: %i.",gotointerior_intname,targetid,gotointerior_int,GetPlayerVirtualWorld(playerid));
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadSAMPInterior, sql);

	return 1;
}

enum CustomIntEnum {
	i_name[64],
	i_interior,
	Float:i_posx,
	Float:i_posy,
	Float:i_posz,
	Float:i_posf
}

static const CustomInt[][CustomIntEnum] = {
	{"Safezone Cafe", 2, 1955.5952, -1998.9495, 1063.5750, 90.0},
	{"Safezone Pawnshop", 2, 2273.1345, -1667.9946, 1065.3430, 180.1347},
	{"Safezone PoliceStation", 2, 622.8486, -568.0578, 1929.6150, 84.2538},
	{"Safezone Weaponfactory", 2, 1916.7504, -2348.8569, 1519.0699, 178.2780},
	{"Safezone Fightclub", 2, 2002.1653, 1106.2167, 330.8099, 178.8813},
	{"Safezone Hospital", 2, 1174.3527, -1332.4786, 3001.0859, 92.2790},
	{"Safezone Diner", 2, 2293.9482, -776.0465, 2553.7168, 91.3155},
	{"Looted Cluckinbell", 2, 2423.3564, -1497.0662, -52.8550, 90.8572},
	{"Looted Binco", 2, 1085.5973, 1006.8934, 2051.9688, 2.4964},
	{"Looted House 1", 2, 847.3362, 19.1004, 993.8686, 92.4005},
	{"Looted Office", 2, 987.4308, -1522.6240, 2200.7690, 85.5071},
	{"Looted PDHQ", 2, 417.1591, -1857.9792, 2186.0859, 2.1831},
	{"Looted Radiostation", 2, 995.5084, 1000.1140, 2001.0859, 266.9522},
	{"Clean Complex 1", 2, 2502.8689, 2509.7087, 2008.6106, 176.7114},
	{"Clean Complex 2", 2, 2354.8618, -188.4357, 1723.1368, 91.3155},
	{"Clean Complex 2 gym", 2, 2342.7437, -175.6942, 1722.6959, 93.1955},
	{"Clean Complex 3", 2, 2528.1917, 2504.3120, 2006.1947, 180.0131},
	{"Clean House 1", 2, 2431.9436, -810.8047, 995.5314, 268.6638},
	{"Clean House 2", 2, -1635.6831, -2494.9480, 895.1804, 184.2311},
	{"Clean House 3", 2, 2399.2400, -1791.6987, 1044.5859, 182.9781},
	{"Narcotics Bunker", 2, 2318.8069, -1786.4036, 1600.7520, 89.6039},
	{"Office Building", 2, 3314.7646, 708.5524, 5123.2979, 181.5331},
	{"Sewers 1", 2, 1888.0081, 1343.1454, 1009.0684, 91.7972},
	{"Sewers 2", 2, 1859.1727, 1318.4072, 1009.0692, 267.8688},
	{"Sewers 3", 2, 1840.1903, 1384.9451, 1009.0692, 179.3630},
	{"Looted Ammunation 1", 1, 326.7263, -110.9184, 1001.5156, 359.0497},
	{"Looted Ammunation 2", 1, 401.6580, 1203.4679, 1000.9688, 358.2781},
	{"Looted Apartment 1", 1, 1905.0692, -985.4296, 2156.1067, 86.9288},
	{"Looted Apartment 2", 1, 1942.4396, 2074.2366, 3029.0938, 89.6273},
	{"Looted Bar 1", 1, -2322.6809, 130.6004, 1000.9688, 270.1090},
	{"Safe Bunker 1", 1, 1365.7102, -441.3046, 1399.3302, 180.7613},
	{"Safe Bunker 2", 1, -713.1433, -1029.4358, 1595.0590, 359.3396},
	{"Looted Binco 2", 1, 2453.7983, -1932.1008, -3.1491, 2.5198},
	{"Looted Complex 1", 1, 2116.9978, 2581.4089, 335.5385, 95.5573},
	{"Looted Complex 2", 1, 524.4856, 140.5326, 1162.8711, 357.7963},
	{"Looted FurnitureStore 1", 1, 335.0212, 2892.1687, 401.1924, 268.8322},
	{"Looted Generalstore 1", 1, 1308.1613, 1074.2542, 1000.2685, 272.7372},
	{"Looted Generalstore 2", 1, 1003.2439, -166.8055, 1134.1066, 181.8697},
	{"Looted Restaurant 1", 1, 395.1567, -159.1624, 1001.5212, 5.0031},
	{"Looted Restaurant 2", 1, 2170.0764, 1002.4383, 1116.8955, 2.9781},
	{"Clean Trailer 1", 1, 1216.3113, 1913.8573, 600.3439, 356.0847},
	{"Clean Trailer 2", 1, 1400.5338, 1601.8823, 408.9659, 182.8097},
	{"Warehouse", 1, -1777.2828, 1446.2596, 1001.0000, 178.7363}
};


YCMD:customints(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);

	new i = -1, string[1024], tmpstring[128];
	for(;++i<sizeof(CustomInt);) {
		format(tmpstring, sizeof tmpstring, "%s:[%d]; ", CustomInt[i][i_name], i);
		strcat(string, tmpstring);
		tmpstring = "";
		if(i%5==0 && i > 0) {
			SCM(playerid, HEX_FADE2, string);
			string = "";
		}
	}
	if(strlen(string) > 3)
		SCM(playerid, HEX_FADE2, string);

	return 1;
}


YCMD:gotocustomint(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);

	new cint;
	if(sscanf(params, "d", cint)) return SCM(playerid, HEX_FADE2, "Usage: /gotocustomint [id] (Hint: Use /customints to check the list.)");

	if(cint < 0 || cint >= sizeof(CustomInt)) return SCM(playerid, HEX_RED, "Error: Invalid id. Check /customints");

	SetPlayerVirtualWorld(playerid, 1);
	SetPlayerInterior(playerid, CustomInt[cint][i_interior]);
	SetPlayerPos(playerid, CustomInt[cint][i_posx], CustomInt[cint][i_posy], CustomInt[cint][i_posz]);
	SetPlayerFacingAngle(playerid, CustomInt[cint][i_posf]);

	SFM(playerid, HEX_FADE2, "You have teleported to custom interior %s:[%d].", CustomInt[cint][i_name], cint);

	return 1;
}