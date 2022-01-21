/*#if defined _inc_server
	#undef _inc_server
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new
        ServerName[128],
        ServerVersion[128],
        ServerLanguage[128],
        ServerWebsite[128],
        ServerMap[128],
        tempStr[256];
        //ServerStreamerItems;

    new ret = GetEnv("SERVER_HOSTNAME", ServerName);
    GetEnv("SERVER_VERSION", ServerVersion);
    GetEnv("SERVER_LANGUAGE", ServerLanguage);
    //GetEnv("SERVER_STREAMITEMS", ServerStreamerItems);
    GetEnv("SERVER_MAPNAME", ServerMap);
    GetEnv("SERVER_WEBSITE", ServerWebsite);

    if(ret) {
        format(tempStr,sizeof tempStr, "hostname %s", ServerName);
        SendRconCommand(tempStr);

        format(tempStr,sizeof tempStr, "gamemodetext %s", ServerVersion);
        SendRconCommand(tempStr); 

        format(tempStr,sizeof tempStr, "language %s",ServerLanguage);
        SendRconCommand(tempStr);

        format(tempStr,sizeof tempStr, "mapname %s",ServerMap);
        SendRconCommand(tempStr);

        format(tempStr,sizeof tempStr, "weburl %s",ServerWebsite);
        SendRconCommand(tempStr);

        //Streamer_VisibleItems(STREAMER_TYPE_OBJECT, ServerStreamerItems);
        print("Server profile loaded.");
    } else {
        print("Failed to read .env file.");
    }

    EnableStuntBonusForAll(0);
    DisableInteriorEnterExits();

    new sHour, sMinute, sSecond;
	gettime(sHour, sMinute, sSecond);
	ServerTime[weather] = 18;
	ServerTime[hour] = sHour;
    ServerTime[minute] = sMinute;
	SetWorldTime(ServerTime[hour]);
	SetWeather(ServerTime[weather]);
    ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);

    repeat WorldtimeChange();

    return Y_HOOKS_CONTINUE_RETURN_1;
}

timer WorldtimeChange[60000*30]() {
    new sHour, sMinute, sSecond;
	gettime(sHour, sMinute, sSecond);
    switch(random(10)) {
        case 0: ServerTime[weather] = 18;
        case 1:  ServerTime[weather] = 12;
        case 2:  ServerTime[weather] = 19;
        case 3:  ServerTime[weather] = 9;
        case 4:  ServerTime[weather] = 20;
        default: ServerTime[weather] = 18;
    }	
	ServerTime[hour] = sHour;
	SetWorldTime(ServerTime[hour]);
	SetWeather(ServerTime[weather]);

    printf("%d:%d:%d WorldtimeChange: weather %d time %d", sHour, sMinute, sSecond, ServerTime[weather], ServerTime[hour]);

    /*if(sHour == 5) {
        GameTextForAll("~Y~Server automatically restarting soon!", 10000, 1);
        foreach(new i : Player) {
            SCM(i, HEX_WHITE, "[Desolation] The server is automatically restarting! You are being kicked to save your data.");
            KickPlayer(i);
        }
        SendRconCommand("password residents");
        defer RestartServer();
    }*/
}

/*timer RestartServer[6000]() {
    SendRconCommand("gmx");
}*/

YCMD:updates(playerid, params[], help) {
    ShowUpdates(playerid);
    return 1;
}

ShowUpdates(playerid) {

    Dialog_Show(playerid, DIALOG_STYLE_MSGBOX, ""HEX_ORANGE"Recent updates", UPDATES_DIALOG, "Ok", "");

    return 1;
}

YCMD:desync(playerid, params[], help) {
    new string[256];
    format(string, sizeof string, "> %s is logging out.", PlayerName(playerid, true));
    ProxMSG(HEX_WHITE, NAMETAG_DISTANCE, playerid, string);
    TogglePlayerControllable(playerid, false);
    SetPlayerName(playerid, accountname[playerid]);

    defer ForceReconnect(playerid);

    return 1;
}


timer ForceReconnect[500](playerid) {

    SCM(playerid, HEX_WHITE, "If you do not log out properly please reconnect manually.");

    new ipadr[16];
    GetPlayerIp(playerid, ipadr, sizeof ipadr);
    BlockIpAddress(ipadr, 10180);

}