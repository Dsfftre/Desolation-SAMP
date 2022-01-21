YCMD:a(playerid, params[], help) {
	new sendText[256];
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);	
	if(sscanf(params, "s[256]", sendText)) 
	{
		SCM(playerid, HEX_FADE2, "Usage: /a [admin chat]");
		return 1;
	}
	if(adminlevel[playerid] == -1)
		format(sendText, sizeof sendText, "[Hidden Admin] %s (%s): %s", PlayerName(playerid), accountname[playerid], sendText);
	else
		format(sendText, sizeof sendText, "[%s] %s (%s): %s", AdminNames[adminlevel[playerid]], PlayerName(playerid), accountname[playerid], sendText);
	SendAdminMessage(HEX_CYAN, sendText);
	//AdminLog(sendText);
	return 1;
}