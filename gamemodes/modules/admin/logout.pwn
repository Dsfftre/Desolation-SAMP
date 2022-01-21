YCMD:logout(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    //if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
    new string[256];
    format(string, sizeof string, "* %s is logging out to the character selection menu.", PlayerName(playerid, true));
    ProxMSG(HEX_WHITE, NAMETAG_DISTANCE, playerid, string);
    TogglePlayerControllable(playerid, false);
    SavePlayer(playerid);
    SetTimerEx("LogoutTimer", 10000, 0, "d", playerid);
    SCM(playerid, HEX_SAMP,"You are being sent back to the character selection menu, please wait 10 seconds.");
    SetPlayerHealth(playerid, 5000.0);
    format(string, sizeof string, "[LOG]: %s has logged out to the character selection menu.", PlayerName(playerid), playerid);
    SendAdminMessage(HEX_YELLOW, string, true);
    printf("%s",string);

    Group_SetPlayer(g_AdminDuty, playerid, false);
    SetPlayerColor(playerid, COLOR_PLAYER);

    return 1;
}

forward LogoutTimer(playerid);
public LogoutTimer(playerid)
{
    TogglePlayerSpectating(playerid, true);
    defer SpawnCamera(playerid);
    SetPlayerName(playerid, accountname[playerid]);
    EmptyPlayerVariables(playerid);
    CharacterSelection(playerid);
	return 1;
}
