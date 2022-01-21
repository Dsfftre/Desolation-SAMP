#define DIALOG_CRAFT 5
#define DIALOG_CRAFT_CONFIRM 6
#define DIALOG_CRAFT_LIST 7

#define DIALOG_CRAFT_MEDICAL 8
//#define CRAFT_WEP_COUNT 22
enum CraftEnum
{
	wName[25],
	wID,
	wCost,
	wLvl
}
static const CraftWeps[][CraftEnum] = { // Name, WepID, MaterialCost, Level
	{"Knife", 4, 25, 0},
	{"Bat", 5, 25, 0},
	{"Shovel", 6, 25, 0},
	{"Katana", 8, 25, 0},
	{"Pistol", 19, 100, 0},
	{"9mm", 39, 100, 0},

	{"Silenced 9mm", 20, 125, 1},
	{"Shotgun", 22, 250, 1},
	{"Sawnoff Shotgun", 23, 250, 1},
	{"12 gauge", 40, 25, 1},
	

	{"Deagle", 21, 350, 2},
	{"Micro-Uzi", 25, 350, 2},
	{"Tec-9", 29, 350, 2},
	{"MP5", 26, 350, 2},
	{"Bolt Action Rifle", 30, 400, 2},
	{".45ACP", 41, 15, 2},

	{"Combat Shotgun", 24, 450, 3},

	{"AK-47", 27, 1000, 4},
	{"M4 Assault Rifle", 28, 1000, 4},
	{"7.62 Magazine", 42, 200, 4},
	{"5.56 Magazine", 43, 350, 4},

	{"Sniper Rifle", 31, 2000, 5}
};

/*enum CraftVehEnum
{
	vName[25],
	vID,
	vCost,
	vLvl
}
static const CraftVehicles[][CraftVehEnum] = {

};

enum CraftMedEnum
{
	mName[25],
	mID,
	mCost,
	mLvl
}
static const CraftMeds[][CraftMedEnum] = {
	hName[25],
	hID,
	hCost,
	hLevel
};*/

YCMD:craft(playerid, params[], help) {
	if(!Bit_Get(loggedin, playerid)) return SendErrorMessage(playerid, ERROR_LOGGEDIN);
    if(IsZombie(playerid)) return SendErrorMessage(playerid, "You're a Zombie. You can't use this command.");

	ShowPlayerDialog(playerid, DIALOG_CRAFT_LIST, DIALOG_STYLE_LIST, "Crafting", "Weapons\nVehicles\nMedical", "Select", "Close");
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DIALOG_CRAFT_LIST)
	{
		if (response)
		{
			switch(listitem)
			{
				case 0:
				{
					mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player` WHERE id = %d", CharacterSQL[playerid]);
					inline LoadCraft() 
					{
						if(!cache_num_rows()) 
						{
							@return 0;
						}
    				    cache_get_value_int(0, "craftskill", CraftSkill[playerid]);		
						cache_get_value_int(0, "craftxp", CraftXP[playerid]);	
						cache_get_value_int(0, "materials", Materials[playerid]);
					    new str[1024];
					    //for(new i = 0; i < CRAFT_WEP_COUNT; i++) 
						for(new i = 0; i < sizeof(CraftWeps); i++) 
					    {
					    	if(Craft[playerid] < CraftWeps[i][wLvl]) continue;
					    	if(isnull(str)) 
					    	{
					    		format(str, 1024, "%s", CraftWeps[i][wName]);
					    	} 
					    	else format(str, 1024, "%s\n%s", str, CraftWeps[i][wName]);
					    }
					    new str2[100];
					    format(str2, 100, "[Crafting] Skill: %d", CraftSkill[playerid]);
					    ShowPlayerDialog(playerid, DIALOG_CRAFT, DIALOG_STYLE_LIST, str2, str, "Select", "Close");
    				    @return 1;
    				}
    				MySQL_TQueryInline(g_SQL, using inline LoadCraft, sql);

				}
				case 1: SCM(playerid, HEX_FADE2, "[Desolation] Feature under development.");
				case 2: SCM(playerid, HEX_FADE2, "[Desolation] Feature under development.");
			}
		}
		return Y_HOOKS_CONTINUE_RETURN_1;
	}
    if(dialogid == DIALOG_CRAFT) // Crafting menu
	{
		if(!response) return Y_HOOKS_CONTINUE_RETURN_1;

		new strung[172];
		format(strung, 172, "Name: {33FF66}%s.\n{FFFFFF}Level: {33FF66}%d/%d.\n{FFFFFF}Cost: {33FF66}%d/%d materials.", CraftWeps[listitem][wName], CraftSkill[playerid], CraftWeps[listitem][wLvl], CraftWeps[listitem][wCost], Materials[playerid]);
		ShowPlayerDialog(playerid, DIALOG_CRAFT_CONFIRM, DIALOG_STYLE_MSGBOX, "Are you sure you want to craft this?", strung, "Craft", "Close");
		SetPVarInt(playerid, "CraftID", listitem);
	}
	if(dialogid == DIALOG_CRAFT_CONFIRM) // Crafting confirm
	{
		if(!response) 
        {
            DeletePVar(playerid, "CraftID");
            return Y_HOOKS_CONTINUE_RETURN_1;
        }
		if(Materials[playerid] < CraftWeps[GetPVarInt(playerid, "CraftID")][wCost]) {
			SCM(playerid, HEX_ORANGE, "You don't have enough materials for this!");
			return Y_HOOKS_CONTINUE_RETURN_1;
		}
		//GivePlayerItem(playerid, CraftWeps[GetPVarInt(playerid, "CraftID")][wID], AddMatchingAmmo(playerid, CraftWeps[GetPVarInt(playerid, "CraftID")][wID]));
		GivePlayerItem(playerid, CraftWeps[GetPVarInt(playerid, "CraftID")][wID], 1);
		if(CraftSkill[playerid] > 0 && CraftSkill[playerid] < 10)
		{
			CraftXP[playerid] +=4;
			SCM(playerid, HEX_SAMP, "[CRAFT] You have gained 4xp from crafting");
		}
		if(CraftSkill[playerid] > 10 && CraftSkill[playerid] < 40)
		{
			CraftXP[playerid] +=3;
			SCM(playerid, HEX_SAMP, "[CRAFT] You have gained 3xp from crafting");
		}
		if(CraftSkill[playerid] > 40 && CraftSkill[playerid] < 90)
		{
			CraftXP[playerid] +=2;
			SCM(playerid, HEX_SAMP, "[CRAFT] You have gained 2xp from crafting");
		}
		if(CraftSkill[playerid] > 90 && CraftSkill[playerid] < 200)
		{
			CraftXP[playerid] +=1;
			SCM(playerid, HEX_SAMP, "[CRAFT] You have gained 1xp from crafting");
		}
		Materials[playerid] -= CraftWeps[GetPVarInt(playerid, "CraftID")][wCost];
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `materials` = '%d', `craftskill` = '%d' WHERE id = '%d' LIMIT 1", Materials[playerid], CraftSkill[playerid], CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
		printf("%s", sql);
	}
    return Y_HOOKS_CONTINUE_RETURN_1;
}

stock GetCraftEXP(playerid)
{
	if(CraftSkill[playerid] > 0) 
	{ 
		return 25*CraftSkill[playerid];
	}
	return 15;
}