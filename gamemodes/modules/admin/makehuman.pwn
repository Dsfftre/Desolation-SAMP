YCMD:makehuman(playerid, params[], help) {
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /makehuman [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	if(IsHuman(targetid)) return SCM(playerid, HEX_RED, "Error: That player is already a human.");
	Bit_Vet(infected, targetid);
	Bit_Vet(pzombie, targetid);
	SetPlayerColor(targetid, COLOR_PLAYER);
	if(Group_GetPlayer(g_AdminDuty, targetid))
		SetPlayerColor(targetid, COLOR_ADMIN);
	Group_SetPlayer(g_Zombie, targetid, false);
	if(Bit_Get(tutorial, targetid))
		SFM(targetid, HEX_FADE2, "Hint: In-character %s was never a zombie. This period was only for fun!", PlayerName(playerid));
	p_skin[playerid] = HumansSkins[random(sizeof(HumansSkins))];
	if(p_skin[playerid] <= 0) p_skin[playerid] = 177;
	SetPlayerSkin(targetid, p_skin[playerid]);
	
	
	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has turned %s into a human.", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid);
	SendAdminMessage(HEX_YELLOW, string, true);
	if(playerid != targetid) 
	{
		format(string, sizeof string, "[Desolation]: %s %s has turned you into a human.", AdminNames[adminlevel[playerid]], PlayerName(playerid));
		SCM(targetid, HEX_YELLOW, string);
	}
	return 1;
}