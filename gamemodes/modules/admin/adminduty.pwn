#include <YSI_Coding\y_hooks>

new Float:	spawn_PosX[MAX_PLAYERS];
new Float:	spawn_PosY[MAX_PLAYERS];
new Float:	spawn_PosZ[MAX_PLAYERS];

YCMD:adminduty(playerid, params[], help) {
	if(Group_GetPlayer(g_Admin, playerid)) 
	{
		new string[90];
		//new Float:x, Float:y, Float:z;
		if(Group_GetPlayer(g_AdminDuty, playerid)) 
		{
			format(string, sizeof string, "[NOTICE]: %s is now off adminduty", PlayerName(playerid));
			SendAdminMessage(HEX_YELLOW, string);
			Group_SetPlayer(g_AdminDuty, playerid, false);
			SetPlayerColor(playerid, COLOR_PLAYER);
			//GetPlayerSpawnPos(playerid, x, y, z);
			//SetPlayerPos(playerid, x, y, z);
			//SetPlayerSkin(playerid, p_skin[playerid]);
			if(Group_GetPlayer(g_Zombie, playerid))
			{
				SetPlayerColor(playerid, COLOR_ZOMBIE);
			}
		}
		else 
		{
			Group_SetPlayer(g_AdminDuty, playerid, true);	
			format(string, sizeof string, "[NOTICE]: %s is now on adminduty.", PlayerName(playerid));
			SendAdminMessage(HEX_YELLOW, string);
			SetPlayerColor(playerid, COLOR_ADMIN);	
			SCM(playerid, HEX_FADE2, "Usage: Use /ah to see a list of your admin commands!");
			//SetPlayerSkin(playerid, 217); this is so retarded i threw up
			//GetPlayerPos(playerid, x, y, z);
			//SetPlayerSpawnPos(playerid, x, y, z);
		}
		//AdminLog(string);

	}
	return 1;
}

hook OnPlayerSpawn(playerid) {
	if(Group_GetPlayer(g_AdminDuty, playerid))
	{
		SetPlayerColor(playerid, COLOR_ADMIN);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}


stock SetPlayerSpawnPos(playerid, &Float:x, &Float:y, &Float:z)
{
	if(!IsPlayerConnected(playerid))
		return 0;

	spawn_PosX[playerid] = x;
	spawn_PosY[playerid] = y;
	spawn_PosZ[playerid] = z;

	return 1;
}

stock GetPlayerSpawnPos(playerid, &Float:x, &Float:y, &Float:z)
{
	if(!IsPlayerConnected(playerid))
		return 0;

	x = spawn_PosX[playerid];
	y = spawn_PosY[playerid];
	z = spawn_PosZ[playerid];

	return 1;
}