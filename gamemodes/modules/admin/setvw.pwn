YCMD:setvw(playerid, params[], help) {
    if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

    new targetid, vw;
    if(sscanf(params, "dd",targetid, vw)) return SCM(playerid, HEX_FADE2, "Usage: /setvw [id] [vw]");

    SetPlayerVirtualWorld(targetid, vw);

    new string[256];
    format(string, sizeof string, "[LOG]: %s %s has set %s virtual to %d", AdminNames[adminlevel[playerid]], PlayerName(playerid), GetSQLCharname(targetid), vw);
	SendAdminMessage(HEX_YELLOW, string, true);

    return 1;
}
