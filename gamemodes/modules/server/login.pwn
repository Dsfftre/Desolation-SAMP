#include <YSI_Coding\y_hooks>

AccountLogin(playerid) {
    mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `account` WHERE name = '%e' LIMIT 1", PlayerName(playerid));
    inline loadAccount() 
    {
        if(!cache_num_rows()) 
        {
            SetPVarInt(playerid, "registering", 1);
            @return showRegisterDialog(playerid);
        }
        new passwordHash[BCRYPT_HASH_LENGTH], banstatus=0;
        cache_get_value_int(0, "id", AccountSQL[playerid]);
        cache_get_value_int(0, "banned", banstatus);
        cache_get_value_int(0, "adminlevel", adminlevel[playerid]);
        cache_get_value(0, "password", passwordHash, BCRYPT_HASH_LENGTH);
        cache_get_value(0, "name", accountname[playerid], MAX_PLAYER_NAME);
        
        cache_get_value_int(0, "TOG_TUTORIAL", banstatus);
        if(banstatus)
            Bit_Let(tutorial, playerid);
        else
            Bit_Vet(tutorial, playerid);

        cache_get_value_int(0, "TOG_JOIN", banstatus);
        if(banstatus)
            Bit_Let(togsjoin, playerid);
        else
            Bit_Vet(togsjoin, playerid);

        cache_get_value_int(0, "TOG_HUD", banstatus);
        if(banstatus)
            Bit_Let(togshud, playerid);
        else
            Bit_Vet(togshud, playerid);

        cache_get_value_int(0, "TOG_ZONES", banstatus);
        if(banstatus)
            Bit_Let(togszones, playerid);
        else
            Bit_Vet(togszones, playerid);

        cache_get_value_int(0, "TOG_NPCHEALTH", banstatus);
        if(banstatus)
            Bit_Let(togsnpchp, playerid);
        else
            Bit_Vet(togsnpchp, playerid);

        Bit_Let(togzchat, playerid);
        Bit_Let(togfam, playerid);

        new string[128];
        format(string, sizeof string, "Welcome back %s!", PlayerName(playerid));
        
        inline Dialog_bcrypt_login(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) 
        {
            #pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
            if(Open_response) 
            {
                bcrypt_check(Open_inputtext, passwordHash, "OnPasswordChecked", "d", Open_pid);
            }
            else 
                Kick(Open_pid);
        }	
        Dialog_ShowCallback(playerid, using inline Dialog_bcrypt_login, DIALOG_STYLE_PASSWORD, string, "This account name is taken.\nIf you want to create a new account press Quit.\nDo not try to log into another user's account!\n\nEnter your password:","Login","Quit");
    }
    MySQL_TQueryInline(g_SQL, using inline loadAccount, sql);
    return 1;
}

hook OnPasswordChecked(playerid)
{
    //print("debug OnPasswordChecked(playerid)");
    new bool:match = bcrypt_is_equal();
    if(match) 
    {
        SCM(playerid, HEX_FADE2, "You are now logged in.");
        Bit_Let(loggedin, playerid);
        CharacterSelection(playerid);
        DeletePVar(playerid, "invalidlogin");
        //print("debug OnPasswordChecked(playerid) LOGGEDIN GOOD PW");
    }
    else 
    {
        SCM(playerid, HEX_RED, "Error: Invalid password.");
        AccountLogin(playerid);
        SetPVarInt(playerid, "invalidlogin", GetPVarInt(playerid, "invalidlogin") +1);
        if(GetPVarInt(playerid, "invalidlogin") > 20)
            Kick(playerid);
        //print("debug OnPasswordChecked(playerid) INVALID PW");
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}


CharacterSelection(playerid) {
    mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player` WHERE accountId = '%d' AND state = 1 LIMIT %d", AccountSQL[playerid], MAX_CHARACTERS);
    inline loadAccount() 
    {
        if(!cache_num_rows()) 
        {
            @return StartCharacterCreation(playerid);
        }

        enum characterMenuEnum 
        {
            sqlid,
            name[MAX_PLAYER_NAME],
            zombiep,
            crashedp,
            spawnInteriors,
            skin,
            cfaction,
            pos_virtualworld,
            pos_interior,
            Float:pos[4]
        }
        new characterMenu[MAX_CHARACTERS][characterMenuEnum];

        new i, string[512], string2[128];
        for(i = 0; i < cache_num_rows(); ++i) 
        {
            cache_get_value_int(i, "id", characterMenu[i][sqlid]);
            cache_get_value(i, "name", characterMenu[i][name], MAX_PLAYER_NAME);
            cache_get_value_int(i, "crashed", characterMenu[i][crashedp]);
            cache_get_value_int(i, "pzombie", characterMenu[i][zombiep]);
            cache_get_value_int(i, "spawnInteriors", characterMenu[i][spawnInteriors]);
            cache_get_value_int(i, "skin", characterMenu[i][skin]);
            cache_get_value_int(i, "factionId", characterMenu[i][cfaction]);            
            cache_get_value_float(i, "posx", characterMenu[i][pos][0]);
            cache_get_value_float(i, "posy", characterMenu[i][pos][1]);
            cache_get_value_float(i, "posz", characterMenu[i][pos][2]);
            cache_get_value_float(i, "posf", characterMenu[i][pos][3]);
            cache_get_value_int(i, "virtualworld", characterMenu[i][pos_virtualworld]);
            cache_get_value_int(i, "interior", characterMenu[i][pos_interior]);
            format(string2, sizeof string2, "%s\tSkin %d\n", characterMenu[i][name], characterMenu[i][skin]);
            strcat(string, string2);
        }
        if(i < 3)
        strcat(string, ""HEX_WHITE"Create a new character");
        inline Dialog_bcrypt_login(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) 
        {
            #pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
            if(Open_response) 
            {
                if(Open_listitem == i) 
                {
                    @return StartCharacterCreation(playerid);
                }
                Bit_Let(character, playerid);
                format(string2, sizeof string2, "~W~Welcome~n~~Y~%s", PlayerName(playerid, false));
                CharacterSQL[playerid] = characterMenu[Open_listitem][sqlid];
                if(characterMenu[Open_listitem][cfaction] > 0) 
                {
                    faction[playerid] = characterMenu[Open_listitem][cfaction];
                    Group_SetPlayer(g_Faction[FactionID(faction[playerid])], playerid, true);
                    Group_SetPlayer(g_Factiontype[fInfo[FactionID(faction[playerid])][brand]], playerid, true);

                    switch(fInfo[FactionID(faction[playerid])][brand]) 
                    {
                        case 0: format(string2, sizeof string2, "~W~Welcome~n~~g~%s", PlayerName(playerid, false));//survivor
                        case 1: format(string2, sizeof string2, "~W~Welcome~n~~b~%s", PlayerName(playerid, false));//ct
                        case 2: format(string2, sizeof string2, "~W~Welcome~n~~h~~r~%s", PlayerName(playerid, false));//research
                        case 3: format(string2, sizeof string2, "~W~Welcome~n~~r~%s", PlayerName(playerid, false));//bandit
                        case 4: format(string2, sizeof string2, "~W~Welcome~n~~p~%s", PlayerName(playerid, false));//tribal
                        default: format(string2, sizeof string2, "~W~Welcome~n~~y~%s", PlayerName(playerid, false));
                    }

                }
                if(adminlevel[playerid] > 0)
                    Group_SetPlayer(g_Admin, playerid, true);
                else
                    Group_SetPlayer(g_Admin, playerid, false);
                if(adminlevel[playerid] == -1)
                    Group_SetPlayer(g_HiddenAdmin, playerid, true);
                else
                    Group_SetPlayer(g_HiddenAdmin, playerid, false);
                SetPlayerName(playerid, characterMenu[Open_listitem][name]);
                SetPlayerSkin(playerid, characterMenu[Open_listitem][skin]);
                p_skin[playerid] = characterMenu[Open_listitem][skin];
                if(characterMenu[Open_listitem][crashedp])
                    Bit_Let(crashed, playerid);
                else
                    Bit_Vet(crashed, playerid);

                if(characterMenu[Open_listitem][zombiep] && !Bit_Get(crashed, playerid)) 
                {
                    Group_SetPlayer(g_Zombie, playerid, true);
                    RandomZombieSpawn(playerid);
                }
                else {
                    SetSpawnInfo(playerid, NO_TEAM, characterMenu[Open_listitem][skin], characterMenu[Open_listitem][pos][0], characterMenu[Open_listitem][pos][1], characterMenu[Open_listitem][pos][2], characterMenu[Open_listitem][pos][3], 0, 0, 0, 0, 0, 0);//give default weapons?
                    SetPlayerInterior(playerid, characterMenu[Open_listitem][pos_interior]);
                    SetPlayerVirtualWorld(playerid, characterMenu[Open_listitem][pos_virtualworld]);
                }
                    
                TogglePlayerSpectating(playerid, false);
                TogglePlayerControllable(playerid, false);
                Bit_Let(frozen, playerid);
                SpawnFreezeTimer[playerid] = SetTimerEx("SpawnFreeze", GetPlayerPing(playerid)*20+2000, 0, "%i", playerid);
                LoadCharacterData(playerid);
                GameTextForPlayer(playerid, string2, 5000, 1);
                
                CreateBars(playerid);
                StopAudioStreamForPlayer(playerid);
                Bit_Let(newbiechat, playerid);
                LogConnection(playerid);
                //Audio_Play(playerid, 1);
            }
            else 
                Kick(Open_pid);
        }	
        Dialog_ShowCallback(playerid, using inline Dialog_bcrypt_login, DIALOG_STYLE_TABLIST, "Select your character", string,"Spawn","Quit");
    }
    MySQL_TQueryInline(g_SQL, using inline loadAccount, sql);
    return 1;
}

/*SetPlayerSpawnToInteriors(playerid, interiorsId)  {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `Interiors` WHERE id = '%d' LIMIT 1", interiorsId);
	new Cache:result = mysql_query(g_SQL, sql);
	if(cache_num_rows()) {
		new Float:intispawn[4], inti_int, inti_vw;
        cache_get_value_float(0, "outx", intispawn[0]);
        cache_get_value_float(0, "outy", intispawn[1]);
        cache_get_value_float(0, "outz", intispawn[2]);
        cache_get_value_float(0, "outf", intispawn[3]);
        cache_get_value_int(0, "outvw", inti_vw);
        cache_get_value_int(0, "outint", inti_int);

        SetPlayerInterior(playerid, inti_int);
        SetPlayerVirtualWorld(playerid, inti_vw);

        SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], intispawn[0], intispawn[1], intispawn[2], intispawn[3], 0, 0, 0, 0, 0, 0);

        cache_delete(result);
		return 1;
	}
	SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    RandomHumanSpawn(playerid);
	return 0;
}*/

LoadCharacterData(playerid) {
    /*SSCANF_Leave(playerid);
	SSCANF_Join(playerid, PlayerName(playerid), 0);*/
    mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player` WHERE id = '%d' LIMIT 1", CharacterSQL[playerid]);
	inline LoadPData() {
		if(!cache_num_rows()) 
        {
			@return 0;
		}
        Bit_Vet(togzchat, playerid);
        new tmp,
            Float:ftmp;
        cache_get_value_int(0, "factionLeader", tmp);
        if(tmp)
            Bit_Let(factionleader, playerid);
        cache_get_value_int(0, "factionOwner", tmp);
        if(tmp)
            Bit_Let(factionowner, playerid);

        cache_get_value_int(0, "cityruler", tmp);
        if(tmp)
            Bit_Let(cityruler, playerid);
        cache_get_value_int(0, "citycommissioner", tmp);
        if(tmp)
            Bit_Let(citycommissioner, playerid);

        cache_get_value_int(0, "infected", tmp);
        if(tmp)
            Bit_Let(infected, playerid);

        cache_get_value_int(0, "deadstatus", tmp);
        if(tmp == 1) {
            Bit_Let(dead, playerid);
        }
        if(tmp == 2) {
            Bit_Let(frozen, playerid);
            Bit_Let(dead, playerid);
        }

        Bit_Let(crashed, playerid);//dev note check where is first setspawninfo
        cache_get_value_int(0, "interior", tmp);
        SetPlayerInterior(playerid, tmp);
        cache_get_value_int(0, "virtualworld", tmp);
        SetPlayerVirtualWorld(playerid, tmp);
        cache_get_value_float(0, "health", ftmp);
        SetPlayerHealth(playerid, ftmp);
        cache_get_value_float(0, "armor", ftmp);
        SetPlayerArmour(playerid, ftmp);
        cache_get_value_int(0, "cash",  cash[playerid]);
        cache_get_value_int(0, "cityId", city[playerid]);
        cache_get_value_int(0, "minutes", minutes[playerid]);
        cache_get_value_int(0, "experience", experience[playerid]);
        cache_get_value_float(0, "hunger", hunger[playerid]);
        cache_get_value_float(0, "thirst", thirst[playerid]);
        cache_get_value_int(0, "level", level[playerid]);
        cache_get_value_int(0, "talkstyle", talkstyle[playerid]);

        cache_get_value_int(0, "athlete", Athlete[playerid]);
        cache_get_value_int(0, "pilot", Pilot[playerid]);
        cache_get_value_int(0, "miner", Miner[playerid]);
        cache_get_value_int(0, "craftsmen", Craftsmen[playerid]);

        cache_get_value_int(0, "mechskill", MechSkill[playerid]);
        cache_get_value_int(0, "luckskill", LuckSkill[playerid]);
        cache_get_value_int(0, "craftskill", CraftSkill[playerid]);
        cache_get_value_int(0, "tradeskill", TradeSkill[playerid]);


        cache_get_value_int(0, "craft", Craft[playerid]);
        cache_get_value_int(0, "craftxp", CraftXP[playerid]);
        cache_get_value_int(0, "materials", Materials[playerid]);

        SetPlayerScore(playerid, level[playerid]);
        if(Bit_Get(tutorial, playerid) && level[playerid] < 3)
            SCM(playerid, HEX_FADE2, "Hint messages are enabled. Type /toghints to turn them off.");
        cache_get_value(0, "rank", factionrank[playerid], 32);
        cache_get_value_int(0, "pzombie", race[playerid]);
        if(race[playerid])
            Bit_Let(pzombie, playerid);
        else
            Bit_Vet(pzombie, playerid);
        if(!IsHuman(playerid)) {
            SetPlayerTeam(playerid, ZOMBIE_TEAM);
            Group_SetPlayer(g_Zombie, playerid, true);
            SetPlayerColor(playerid, COLOR_ZOMBIE);
            SetPlayerSkin(playerid, RandomZombieSkin());
        }
        else
            SetPlayerColor(playerid,COLOR_PLAYER);
        cache_get_value_int(0, "race", race[playerid]);
        cache_get_value_int(0, "zombierace", zombierace[playerid]);

        ResetHuds(playerid);

        printf("[LOAD] %s data loaded!", PlayerName(playerid));

        if(Athlete[playerid] == 0 && Pilot[playerid] == 0 && Miner[playerid] == 0 && Craftsmen[playerid] == 0 && Merchant[playerid] == 0) 
        {
            SCM(playerid, HEX_SAMP, "[Desolation] Select your characters new perk!");
            SCM(playerid, HEX_SAMP, "[Desolation] The old skill system has been torn down, skills will now be something a character has by default.");
            SCM(playerid, HEX_SAMP, "[Desolation] Over being available to access all skills you can choose ONE perk.");
            PerkSelection2(playerid);
        }
        
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadPData, sql);
    return 1;
}