YCMD:setinterior(playerid, params[], help) {
    if(adminlevel[playerid] < 3) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

    new targetid, interiorid;
    if(sscanf(params, "dd",targetid, interiorid)) return SCM(playerid, HEX_FADE2, "Usage: /setinterior [id] [interiorid]");

    SetPlayerInterior(targetid, interiorid);

    new string[256];
    format(string, sizeof string, "[LOG]: %s %s has set %s interior to %d", AdminNames[adminlevel[playerid]], PlayerName(playerid), GetSQLCharname(targetid), interiorid);
	SendAdminMessage(HEX_YELLOW, string, true);

    return 1;
}
