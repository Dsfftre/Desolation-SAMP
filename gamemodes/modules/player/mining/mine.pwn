#include <YSI_Coding\y_hooks>
#define MAX_ORES 100

enum MineInfo {
	SQLID,
	MineName,
	type,
	Float:minepos[3],
	Text3D:LabelID,
	objectid
}
new Mines[MAX_LOOT][MineInfo], Total_Mines_Created;
new Iterator:MineIndex<MAX_ORES>;
hook OnGameModeInit()
{
	LoadMines();

	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadMines()
{
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `mining_ores` WHERE state > 0");
	inline LoadMineData()
	{		
		if(!cache_num_rows()) 
		{
			print("Mine_ore Loot table is empty.");
			@return 1;
		}
		//new str[300];
		new i = -1;		
    	for(;++i<cache_num_rows();) 
        {
			cache_get_value_int(i, "id", Mines[i][SQLID]);
			cache_get_value(i, "minename", Mines[i][MineName], 32);
			cache_get_value_float(i, "posx", Mines[i][minepos][0]);
			cache_get_value_float(i, "posy", Mines[i][minepos][1]);
			cache_get_value_float(i, "posz", Mines[i][minepos][2]);
			cache_get_value_int(i, "objectid", Mines[i][objectid]);

			Total_Mines_Created++;

			//format(str, sizeof(str), "%s", Mines[i][MineName]);
	  		//Mines[i][LabelID] = CreateDynamic3DTextLabel(str, 0xFFFF00, Mines[i][minepos][0],Mines[i][minepos][1],Mines[i][minepos][2], 100, 0, 0);
			Mines[i][objectid] = CreateDynamicObject(Mines[i][objectid], Mines[i][minepos][0], Mines[i][minepos][1], Mines[i][minepos][2]-1.0, 0.0, 0.0, 0.0, 0, 0);

			Iter_Add(MineIndex, i);
		}
		printf("%d mines loaded.", Total_Mines_Created);
		return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadMineData, sql);
	return 1;
}

YCMD:addmine(playerid, params[], help) {
	if(adminlevel[playerid] < 6) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	
	new Float:pos[3];

    if(sscanf(params,"i")) return SCM(playerid, HEX_FADE2, "Usage: /addmine");

    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `mining_ores` (`posx`, `posy`, `posz`) VALUES ('%f', '%f', '%f')", pos[0], pos[1], pos[2]);
	mysql_tquery(g_SQL, sql, "", "");

	printf("%s", sql);

	SCM(playerid, HEX_FADE2, "Mine created in the database. It will spawn after the next restart!");

	return 1;
}

YCMD:mine(playerid, params[], help) {
	if(Bit_Get(loggedin, playerid))
	{
		new i = GetClosestMineID(playerid);
		if (i == -1)
		{
			SCM(playerid, HEX_FADE2, "[Desolation] You're not near a mine!");
			return 1;
		}

		DestroyDynamicObject(Mines[i][objectid]);
		ApplyAnimation(playerid,"CHAINSAW","WEAPON_csawlo", 4.1, 1, 0, 1, 1, 1);
		GivePlayerItem(playerid, 61);
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `materials` = `materials`+25 WHERE id = '%d' LIMIT 1", CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
		//defer TimedGameTextForPlayer(playerid, "~y~Material ~w~looted!", 2200, 4);
		defer TimedPlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);

	}
	return 1;
}

GetClosestMineID(playerid)
{
	foreach(new i : MineIndex)
	{
		if(IsValidDynamicObject(Mines[i][objectid]) && IsPlayerInRangeOfPoint(playerid, 1.2, Mines[i][minepos][0], Mines[i][minepos][1], Mines[i][minepos][2]))
		{
			return i;
		}
	}
	return -1;
}
