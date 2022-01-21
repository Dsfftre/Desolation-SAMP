#include <YSI_Coding\y_hooks>
#define MAX_SEARCHES 50

enum SearchInfo
{
    search_sqlid,
	category,
    Float:search_pos[3],
	Text3D:search_label,
	bool:search_looted
}

new Searches[MAX_SEARCHES][SearchInfo], Total_Searches_Created;
new Iterator:SearchIndex<MAX_SEARCHES>;

hook OnGameModeInit()
{
	new cmd = Command_GetID("search");
	Group_SetGlobalCommand(cmd, true);
	Group_SetCommand(g_Admin, cmd, false);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
	LoadSearches();


	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadSearches()
{
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `searches`");
	inline LoadSearchData()
	{		
		if(!cache_num_rows()) 
		{
			print("Searches Loot table is empty.");
			@return 0;
		}
		new string[300];
    	foreach (new i : Range(0, cache_num_rows()))
        {
			cache_get_value_int(i, "id", Searches[i][search_sqlid]);
			cache_get_value_int(i, "category", Searches[i][category]);
			cache_get_value_float(i, "x", Searches[i][search_pos][0]);
			cache_get_value_float(i, "y", Searches[i][search_pos][1]);
			cache_get_value_float(i, "z", Searches[i][search_pos][2]);

			Searches[i][search_looted] = false;

			Total_Searches_Created++;

			format(string, sizeof(string), "[/search point] %d", Searches[i][search_sqlid]);
			Searches[i][search_label] = CreateDynamic3DTextLabel(string, -1, Searches[i][search_pos][0], Searches[i][search_pos][1], Searches[i][search_pos][2], 50, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, -1, -1, -1, 10.0);
			//CreateDynamic3DTextLabel(const text[], color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA areaid = STREAMER_TAG_AREA -1)
			Iter_Add(SearchIndex, i);
		}
		printf("%d Search points have been successfully loaded from the database.", Total_Searches_Created);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadSearchData, sql);
	return 1;
}

YCMD:addsearch(playerid, params[], help) {
	if(adminlevel[playerid] < 6) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	
	new Float:pos[3];

    if(sscanf(params,"i")) return SCM(playerid, HEX_FADE2, "Usage: /addsearch");

    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new int = GetPlayerInterior(playerid);
	new vw = GetPlayerVirtualWorld(playerid);

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `searches` (`x`, `y`, `z`) VALUES ('%f', '%f', '%f')", pos[0], pos[1], pos[2]);
	mysql_tquery(g_SQL, sql, "", "");

	printf("%s", sql);

	SCM(playerid, HEX_FADE2, "Search point created in the database. It will spawn after the next restart!");

	return 1;
}

YCMD:search(playerid, params[], help) {
	if(Bit_Get(loggedin, playerid))
	{
		foreach(new i:SearchIndex)
		{
			if(IsPlayerInRangeOfPoint(playerid, 1.5, Searches[i][search_pos][0], Searches[i][search_pos][1], Searches[i][search_pos][2]))
			{
				if(Searches[i][search_looted] == true)
				{
					new str[256];
					format(str, sizeof(str), "* %s found nothing ((Looks like this area has been searched recently)) *", PlayerName(playerid));
					ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, str);
				}
				else
				{
					new rand = random(1);
					if(Searches[i][category] == 1)
					{
						switch(rand)
						{
							case 0:
							{
								GivePlayerItem(playerid, 4, 1);
							}
						}
					}
				}
			}
		}
	}
	return 1;
}