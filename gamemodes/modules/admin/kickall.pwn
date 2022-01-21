YCMD:kickall(playerid, params[], help) {
	if(adminlevel[playerid] < 5) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	GameTextForAll("~Y~Server restarting soon!", 10000, 1);

	foreach(new i : Player) {
		SCM(i, HEX_WHITE, "[Desolation] The server is restarting! You are being kicked to save your data.");
		KickPlayer(i);
	}

	SendRconCommand("password residents");

	return 1;
}