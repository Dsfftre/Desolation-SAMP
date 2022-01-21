#include <YSI_Coding\y_hooks>

PerkSelection(playerid)
{
	new string[1250];
	string="Athlete - Huge boost to your characters Staminia\nPilot - The ability to fly aircraft\nMiner - Gain more ore from mining\nCraftsmen - Your character will start with level 3 crafting\nMerchant - Better buy & sell prices";
	inline Dialog_SkillSelect1(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[])
    {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response)
        {
			switch(Open_listitem) 
            {
				case 0:
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Athlete skill!");
                    MYSQL_Update_Character(playerid, "athlete", 1);
                }
				case 1: 
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Pilot skill!");
                    MYSQL_Update_Character(playerid, "pilot", 1);
                }
				case 2: 
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Miner skill!");
                    MYSQL_Update_Character(playerid, "miner", 1);
                }
				case 3: 
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Craftsmen skill!");
                    MYSQL_Update_Character(playerid, "craftsmen", 1);
                    MYSQL_Update_Character(playerid, "craft", 3);
                    MYSQL_Update_Character(playerid, "craftskill", 3);

                }
				case 4: 
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Merchant skill!");
                    MYSQL_Update_Character(playerid, "tradeskill", 200);
                    MYSQL_Update_Character(playerid, "merchant", 1);
                }
			}
        }
        PlayerPlaySound(playerid, 1057 , 0.0, 0.0, 0.0); 
        First_Spawn(playerid);
	}	
    Dialog_ShowCallback(playerid, using inline Dialog_SkillSelect1, DIALOG_STYLE_LIST, "Select your characters skill", string, "Select");
	return 1;
}

PerkSelection2(playerid)
{
	new string[1250];
	string="Athlete - Huge boost to your characters Staminia\nPilot - The ability to fly aircraft\nMiner - Gain more ore from mining\nCraftsmen - Your character will start with level 3 crafting\nMerchant - You gain more money from selling items and receive lower buy prices at stores.";
	inline Dialog_SkillSelect1(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[])
    {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response)
        {
			switch(Open_listitem) 
            {
				case 0:
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Athlete skill!");
                    MYSQL_Update_Character(playerid, "athlete", 1);
                }
				case 1: 
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Pilot skill!");
                    MYSQL_Update_Character(playerid, "pilot", 1);
                }
				case 2: 
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Miner skill!");
                    MYSQL_Update_Character(playerid, "miner", 1);
                }
				case 3: 
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Craftsmen skill!");
                    MYSQL_Update_Character(playerid, "craftsmen", 1);
                    MYSQL_Update_Character(playerid, "craft", 3);
                }
				case 4: 
                {
                    SCM(playerid, HEX_FADE2, "[Desolation]: You have selected the Merchant skill!");
                    MYSQL_Update_Character(playerid, "tradeskill", 200);
                    MYSQL_Update_Character(playerid, "merchant", 1);
                }
			}
        }
        PlayerPlaySound(playerid, 1057 , 0.0, 0.0, 0.0); 
	}	
    Dialog_ShowCallback(playerid, using inline Dialog_SkillSelect1, DIALOG_STYLE_LIST, "Select your characters skill", string, "Select");
	return 1;
}