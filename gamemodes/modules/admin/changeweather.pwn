YCMD:changeweather(playerid, params[], help) {
	if(adminlevel[playerid] == 0 || adminlevel[playerid] == 1) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetwet;

	if(sscanf(params, "d", targetwet)) return SCM(playerid, HEX_FADE2, "Usage: /changeweather [weather id] (18 default sunny, 16 rainy, 9 foggy or check /weatherlist)");
	if(targetwet < 0 || targetwet > 20) return SCM(playerid, HEX_RED, "Error: Invalid weather. (Choose from 0 to 20.)");

	ServerTime[weather] = targetwet;
	SetWeather(ServerTime[weather]);

	return 1;
}

YCMD:weatherlist(playerid, params[], help) {
	SCM(playerid, HEX_YELLOW, "SAMP WEATHER LIST:");
	SCM(playerid, HEX_FADE2, "[0 = EXTRASUNNY_LA] [1 = SUNNY_LA[2 = EXTRASUNNY_SMOG_LA] [3 = SUNNY_SMOG_LA] [4 = CLOUDY_LA] [5 = SUNNY_SF]");
	SCM(playerid, HEX_FADE2, "[6 = EXTRASUNNY_SF] [7 = CLOUDY_SF] [8 = RAINY_SF] [9 = FOGGY_SF] [10 = SUNNY_VEGAS]");
	SCM(playerid, HEX_FADE2, "[11 = EXTRASUNNY_VEGAS (heat waves)] [12 = CLOUDY_VEGAS] [13 = EXTRASUNNY_COUNTRYSIDE] [14 = SUNNY_COUNTRYSIDE] [15 = CLOUDY_COUNTRYSIDE]");
	SCM(playerid, HEX_FADE2, "[16 = RAINY_COUNTRYSIDE] [17 = EXTRASUNNY_DESERT] [18 = SUNNY_DESERT] [19 = SANDSTORM_DESERT] [20 = UNDERWATER (greenish, foggy)]");
	return 1;
}