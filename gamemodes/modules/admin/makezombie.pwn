YCMD:makezombie(playerid, params[], help)
{
	if(adminlevel[playerid] < 2) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /makezombie [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	if(Bit_Get(pzombie, targetid)) return SCM(playerid, HEX_RED, "Error: That player is already a zombie.");

	Bit_Let(pzombie, targetid);
	Group_SetPlayer(g_Zombie, targetid, true);
	SetPlayerSkin(targetid, RandomZombieSkin());
	SetPlayerColor(targetid, COLOR_ZOMBIE);
	if(Group_GetPlayer(g_AdminDuty, targetid))
		SetPlayerColor(targetid, COLOR_ADMIN);
	GameTextForPlayer(targetid, "~r~You turned into a zombie!", 1700, 0);
	Bit_Vet(infected, targetid);
	SCM(targetid, HEX_FADE2, "You are a zombie now! Attack other players to infect them. You can become a human again (/human) once you infected three players.");
	if(Bit_Get(tutorial, targetid))	{		
		SCM(targetid, HEX_FADE2, "Hint: You are considered player-killed. If you become a human again you will not remember any of this, it's only for fun.");
		SCM(targetid, HEX_FADE2, "Hint: Use /mutation to change your zombie class.");
	}
	
	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has turned %s into a zombie.", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid));
	SendAdminMessage(HEX_YELLOW, string, true);
	if(playerid != targetid) {
		format(string, sizeof string, "[STAFF]: %s %s has turned you into a zombie.", AdminNames[adminlevel[playerid]], PlayerName(playerid));
		SCM(targetid, HEX_YELLOW, string);
	}
	return 1;
}