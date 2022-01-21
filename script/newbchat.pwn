#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new cmd = Command_GetID("newb");
	Group_SetGlobalCommand(cmd, true);

    cmd = Command_GetID("togn");
    Group_SetGlobalCommand(cmd, true);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:n(playerid, params[], help) {
	new sendText[256];
	if(sscanf(params, "s[256]", sendText)) 
	{
		SCM(playerid, HEX_FADE2, "Usage: /n [Newbie Chat]");
		return 1;
	}
	if(Bit_Get(newbiechat, playerid))
		format(sendText, sizeof sendText, "[NEWBIE] (%s): %s", PlayerName(playerid), sendText);
	else
		format(sendText, sizeof sendText, "[NEWBIE][%s] %s: %s", AdminNames[adminlevel[playerid]], PlayerName(playerid), sendText);
		foreach(new i: Player) 
		    SCM(i, HEX_CYAN, sendText);{
	}
	return 1;
}

YCMD:togn(playerid, params[], help) {
    if(Bit_Get(loggedin, playerid))
    {
        if(!Bit_Get(newbiechat, playerid))
        {
            Bit_Let(newbiechat, playerid); 
            SCM(playerid, HEX_FADE2, "[Desolation] You have enabled Newbie Chat");
        }
        else if(Bit_Get(newbiechat, playerid))
        {
            Bit_Vet(newbiechat, playerid);
            SCM(playerid, HEX_FADE2, "[Desolation] You have disabled Newbie Chat");
        }
    }
    return 1;
}
