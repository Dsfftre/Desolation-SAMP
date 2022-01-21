YCMD:z(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new text[256],string[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /z [message]");

	format(string, sizeof(string), ""HEX_TESTER"(( Zombie [%i] "HEX_ADMIN"%s"HEX_TESTER": %s ))", playerid, PlayerName(playerid), text);
	
	foreach(new i:GroupMember[g_Zombie]) 
	{
		if(!Group_GetPlayer(g_AdminDuty, i))
		SCM(i, HEX_TESTER, string);
	}
	foreach(new j:GroupMember[g_AdminDuty]) 
	{
			SCM(j, HEX_TESTER, string);
	}

	return 1;
}