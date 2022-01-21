YCMD:report(playerid, params[], help) {
	if(!SpamPrevent(playerid)) return 1;	
	if(!Bit_Get(character, playerid)) return SCM(playerid, HEX_RED, "Error: You must spawn a character.");

	new reportid, string[256];
	if(sscanf(params, "ds[256]", reportid, string)) return SCM(playerid, HEX_FADE2, "Usage: /report [id] [reason]");

	SCM(playerid, HEX_FADE2, "[Desolation] Your report has been sent to all online Administrators!");
	format(string, sizeof(string), "> Report [%i] %s has reported: %s for %s", playerid, PlayerName(playerid), PlayerName(reportid), string);
	SendAdminMessage(HEX_CYAN, string);
	//ReportLog(string);
	
	return 1;
}

