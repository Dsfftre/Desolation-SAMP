/*#if defined _inc_admin
	#undef _inc_admin
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

/*RaceName(id) {
    new string[32] = "Unknown";
    switch (id) 
    {
        case 0: string = "Jumper";
        case 1: string = "Native";
        case 2: string = "Asurmen";
        case 3: string = "Cimmerians";
        case 4: string = "Type Human Tyrant";
        case 5: string = "Ancient Atlantean";
    }
    return string;
}*/

ZombieRaceName(id) {
    new string[32] = "Unknown";
    switch (id) 
    {
        case 0: string = "Wanderer";
        case 1: string = "Jumper";
        case 2: string = "Runner";
        case 3: string = "Bloater";
        case 4: string = "Screecher";
        case 5: string = "Sniffer";
        case 6: string = "Hulks";
        case 7: string = "Tyrant";
    }
    return string;
}

IsTHT(playerid) {
    if(race[playerid] == 4 && !IsZombie(playerid))
        return true;
    return false;
}

IsJumper(playerid) {
    if(zombierace[playerid] == 1) return true;
    return false;
}

IsRunner(playerid) {
    if(zombierace[playerid] == 2) return true;
    return false;
}

IsBloater(playerid) {
    if(zombierace[playerid] == 3) return true;
    return false;
}

IsScreecher(playerid) {
    if(zombierace[playerid] == 4) return true;
    return false;
}

IsSniffer(playerid) {
    if(zombierace[playerid] == 5) return true;
    return false;
}

IsHulks(playerid) {
    if(zombierace[playerid] == 6) return true;
    return false;
}

IsTyrant(playerid) {
    if(zombierace[playerid] == 7) return true;
    return false;
}

new radGzs[8];
new gAreadradGzs[8];
new gAreaMontgomery;
CreateRadiations() 
{

    //yellow: 0, 2, 4, 5
    //red: 1, 3, 6, 7
    
    gAreaMontgomery = Area_AddPoly
    (
        1035.0, 82.7634, // Bottom left
        1447.0, 95.0439, // Bottom right
        1568.0, 455.3877, // Top right
        1248.0, 587.9936  // Top left
    );
    Area_SetWorld(gAreaMontgomery, 0, true);

    /*radGzs[0] = GangZoneCreate(995, 889, 2680, 2287); //"radiation_lv" 
    radGzs[1] = GangZoneCreate(460, -1697, 2796, -927); //"radiation_ls" 
    radGzs[2] = GangZoneCreate(2040, -2086, 2796, -1697); //"radiation_ls" */

    radGzs[0] = GangZoneCreate(1872, -2848, 2814, -1687);
    radGzs[1] = GangZoneCreate(-2934, 571, -1467, 1453);
    radGzs[2] = GangZoneCreate(-2934, -222, -1706, 573);
    radGzs[3] = GangZoneCreate(-518, 1453, 970, 2901);
    radGzs[4] = GangZoneCreate(-2934, 1453, -518, 2901);
    radGzs[5] = GangZoneCreate( -1470, 577, 974, 1453);
    radGzs[6] = GangZoneCreate(970, 577, 2950, 2621);
    radGzs[7] = GangZoneCreate(161, -1695, 2897, -1167);
            
    gAreadradGzs[0] = Area_AddPoly
    (
        1872.0, -2848.96875, // Bottom left
        2814.0, -2848.96875, // Bottom right
        2814.0, -1687.96875, // Top right
        1872.0, -1687.96875  // Top left
    );
    Area_SetWorld(gAreadradGzs[0], 0, true);
        
    gAreadradGzs[1] = Area_AddPoly
    (
        -2934.0, 571.03125, // Bottom left
        -1467.0, 571.03125, // Bottom right
        -1467.0, 1453.03125, // Top right
        -2934.0, 1453.03125  // Top left
    );
    Area_SetWorld(gAreadradGzs[1], 0, true);
    
    gAreadradGzs[2] = Area_AddPoly
    (
        -2934.0, -222.9375, // Bottom left
        -1706.0, -222.9375, // Bottom right
        -1706.0, 573.0625, // Top right
        -2934.0, 573.0625  // Top left
    );
    Area_SetWorld(gAreadradGzs[2], 0, true);

    gAreadradGzs[3] = Area_AddPoly
    (
        -518.0, 1453.0625, // Bottom left
        970.0, 1453.0625, // Bottom right
        970.0, 2901.0625, // Top right
        -518.0, 2901.0625  // Top left
    );
    Area_SetWorld(gAreadradGzs[3], 0, true);

    gAreadradGzs[4] = Area_AddPoly
    (
        -2934.0, 1453.0625, // Bottom left
        -518.0, 1453.0625, // Bottom right
        -518.0, 2901.0625, // Top right
        -2934.0, 2901.0625  // Top left
    );
    Area_SetWorld(gAreadradGzs[4], 0, true);

    gAreadradGzs[5] = Area_AddPoly
    (
        -1470.0, 577.0625, // Bottom left
        974.0, 577.0625, // Bottom right
        974.0, 1453.0625, // Top right
        -1470.0, 1453.0625  // Top left
    );
    Area_SetWorld(gAreadradGzs[5], 0, true);

    gAreadradGzs[6] = Area_AddPoly
    (
        970.0, 577.0625, // Bottom left
        2950.0, 577.0625, // Bottom right
        2950.0, 2621.0625, // Top right
        970.0, 2621.0625  // Top left
    );
    Area_SetWorld(gAreadradGzs[6], 0, true);

    gAreadradGzs[7] = Area_AddPoly
    (
        161.0, -1695.9375, // Bottom left
        2897.0, -1695.9375, // Bottom right
        2897.0, -1167.9375, // Top right
        161.0, -1167.9375  // Top left
    );
    Area_SetWorld(gAreadradGzs[7], 0, true);


    //radGzs[0] = GangZoneCreate(995, 889, 2680, 2287); //"radiation_lv" 
    /*gAreadradGzs[0] = Area_AddPoly
    (
        995.0, 889.0, // Bottom left
        2680.0, 889.0, // Bottom right
        2680.0, 2287.0, // Top right
        995.0, 2287.0  // Top left
    );
    Area_SetWorld(gAreadradGzs[0], 0, true);
    gAreadradGzs[1] = Area_AddPoly
    (
        460.0, -1697.0, // Bottom left
        2796.0, -1697.0, // Bottom right
        2796.0, -927.0, // Top right
        460.0, -927.0  // Top left
    );
    Area_SetWorld(gAreadradGzs[1], 0, true);
    gAreadradGzs[2] = Area_AddPoly
    (
        2040.0, -2086.0, // Bottom left
        2796.0, -2086.0, // Bottom right
        2796.0, -1697.0, // Top right
        2040.0, -1697.0  // Top left
    );
    Area_SetWorld(gAreadradGzs[2], 0, true);*/
    return 1;
}



ShowRadiations(playerid) 
{
    GangZoneShowForPlayer(playerid, radGzs[0], 0xFF000088);
    GangZoneShowForPlayer(playerid, radGzs[1], 0xFF000088);
    GangZoneShowForPlayer(playerid, radGzs[2], 0xFFFF0088);
    GangZoneShowForPlayer(playerid, radGzs[3], 0xFFFF0088);
    GangZoneShowForPlayer(playerid, radGzs[4], 0xFF000088);
    GangZoneShowForPlayer(playerid, radGzs[5], 0xFFFF0088);
    GangZoneShowForPlayer(playerid, radGzs[6], 0xFF000088);
    GangZoneShowForPlayer(playerid, radGzs[7], 0xFFFF0088);
    return 1;
}

hook OnGameModeInit() {
    SetNameTagDrawDistance(NAMETAG_DISTANCE);	
    
    //CreateRadiations();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterArea(playerid, areaid) {

    if(areaid == gAreaMontgomery && !Bit_Get(ContestedArea, playerid)) {
        Bit_Let(ContestedArea, playerid);
        SCM(playerid, HEX_YELLOW, "You have entered a contested area!");
        if(Bit_Get(tutorial, playerid))
            SCM(playerid, HEX_FADE2, "Hint: You are free to shoot anyone in this open Player versus Player area. Valuable loot spawns more frequently here.");
    }
    else
        defer RadiationEnter(playerid, areaid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

timer RadiationEnter[100](playerid, areaid) {
    //SFM(playerid, HEX_LRED, "DEBUG: YOU ARE ENTERING AREA ID: %d", areaid);
    //SFM(playerid, HEX_FADE2, "Montgomery: %d, Rad0: %d, Rad1: %d, Rad2: %d, Rad3: %d, Rad4: %d, Rad5: %d, Rad6: %d, Rad7: %d", gAreaMontgomery, gAreadradGzs[0], gAreadradGzs[1], gAreadradGzs[2], gAreadradGzs[3], gAreadradGzs[4], gAreadradGzs[5], gAreadradGzs[6], gAreadradGzs[7]);


    if(GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0) {
        if(areaid == gAreadradGzs[0] || areaid == gAreadradGzs[1] ||  areaid == gAreadradGzs[2] ||  areaid == gAreadradGzs[3] ||  areaid == gAreadradGzs[4] ||  areaid == gAreadradGzs[5] ||  areaid == gAreadradGzs[6] ||  areaid == gAreadradGzs[7]) {
            if(!Group_GetPlayer(g_AdminDuty, playerid))
                Bit_Let(radiation, playerid);
            SCM(playerid, HEX_YELLOW, "You have entered a radioactive area!");
            if(Bit_Get(tutorial, playerid))
                SCM(playerid, HEX_FADE2, "Hint: You die in minutes inside the radiation zone.");

            if(!Bit_Get(dead, playerid) && Bit_Get(radiation, playerid) && !Group_GetPlayer(g_AdminDuty, playerid))  {
                new Float:health;
                GetPlayerHealth(playerid, health);
                SetPlayerHealth(playerid, health-10.0);
                SCM(playerid, HEX_YELLOW, "You are losing health due to the radiation!");
            }

            if(areaid == gAreadradGzs[1] || areaid == gAreadradGzs[3] ||  areaid == gAreadradGzs[6] ||  areaid == gAreadradGzs[7])
                defer RadiationEffect(playerid, 1);
            else
                defer RadiationEffect(playerid, 0);

            //yellow: 0, 2, 4, 5
            //red: 1, 3, 6, 7

        }
    }

}

timer RadiationEffect[RADIATION_EFFECT_TIME](playerid, redzone) {
    //new areaid = Area(playerid);
    //if(areaid == gAreadradGzs[0] || areaid == gAreadradGzs[1] ||  areaid == gAreadradGzs[2] ||  areaid == gAreadradGzs[3] ||  areaid == gAreadradGzs[4] ||  areaid == gAreadradGzs[5] ||  areaid == gAreadradGzs[6] ||  areaid == gAreadradGzs[7]) {
    if(Bit_Get(radiation, playerid)) {
        if(GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0) {
            if(!Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid))  {
                new Float:health;
                GetPlayerHealth(playerid, health);
                if(redzone)
                    SetPlayerHealth(playerid, health-25.0);
                else
                    SetPlayerHealth(playerid, health-15.0);
                SCM(playerid, HEX_YELLOW, "You are losing health due to the radiation!");
                if(redzone)
                    defer RadiationEffect(playerid, 1);
                else
                    defer RadiationEffect(playerid, 0);
            }
        }
    }
    //}
}

hook OnPlayerLeaveArea(playerid, areaid) {
    if(areaid == gAreaMontgomery) {
        if(GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0) {
            GameTextForPlayer(playerid, "~w~You left the contested territory.", 3000, 4);
            Bit_Vet(ContestedArea, playerid);
        }
    }
    else if(Bit_Get(radiation, playerid)) {
        if(areaid == gAreadradGzs[0] || areaid == gAreadradGzs[1] ||  areaid == gAreadradGzs[2] ||  areaid == gAreadradGzs[3] ||  areaid == gAreadradGzs[4] ||  areaid == gAreadradGzs[5] ||  areaid == gAreadradGzs[6] ||  areaid == gAreadradGzs[7]) {
            Bit_Vet(radiation, playerid);
            SCM(playerid, HEX_YELLOW, "You left the radiated area.");
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

RandomHumanSpawn(playerid) {
    if(p_skin[playerid] <= 0) p_skin[playerid] = 177;
    switch(random(6)) 
    {
        /*case 0: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 2537.7395,-1663.2736,15.1546, 180.0995, 0, 0, 0, 0, 0, 0); // grove street
        case 1: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 2234.9417,-1188.8092,33.5313, 173.1582, 0, 0, 0, 0, 0, 0); // jefferson motel roof
        case 2: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 1300.2935,-883.1429,42.8753, 180.0285, 0, 0, 0, 0, 0, 0); // temple
        case 3: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 1110.8468,-1186.9547,18.3465, 89.3946, 0, 0, 0, 0, 0, 0); // temple
        default: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 2537.7395,-1663.2736,15.1546, 180.0995, 0, 0, 0, 0, 0, 0); // grove street*/
        case 0: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 29.1471,119.3594,2.7324,234.8686, 0, 0, 0, 0, 0, 0);
        case 1: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 1232.1644,-216.8703,36.3415,34.1269, 0, 0, 0, 0, 0, 0);
        case 2: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 59.8838,-687.3679,10.0368,33.5629, 0, 0, 0, 0, 0, 0);
        case 3: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 169.7242,13.8764,1.4450,197.9170, 0, 0, 0, 0, 0, 0);
        case 4: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 822.7242,-233.5299,18.8311,197.9170, 0, 0, 0, 0, 0, 0);
        default: SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], 327.0460,-375.4874,11.5797,194.5330, 0, 0, 0, 0, 0, 0);
    }
    return 1;
}

RandomZombieSpawn(playerid) {
    /*switch(random (3)) 
    {
        case 0: SetSpawnInfo(playerid, ZOMBIE_TEAM, RandomZombieSkin(), 1412.7528,-1360.5892,8.5547, 354.7747, 0, 0, 0, 0, 0, 0); // ls downtown sewers
        case 1: SetSpawnInfo(playerid, ZOMBIE_TEAM, RandomZombieSkin(), 832.9378, -1080.8154, 24.2762, 22.4330, 0, 0, 0, 0, 0, 0); // ls cementery
        case 2: SetSpawnInfo(playerid, ZOMBIE_TEAM, RandomZombieSkin(), 1912.0243, -1782.1296, 13.3748, 97.1225, 0, 0, 0, 0, 0, 0); // ls idlewood gas
        default: SetSpawnInfo(playerid, ZOMBIE_TEAM, RandomZombieSkin(), 272.4928, -40.3757, 1.8783, 57.1972, 0, 0, 0, 0, 0, 0); // blueberry
    }*/
    switch(random(2)) 
    {
        case 0: SetSpawnInfo(playerid, ZOMBIE_TEAM, RandomZombieSkin(), 2156.6184,30.0580,26.2667,290.8859, 0, 0, 0, 0, 0, 0);
        case 1: SetSpawnInfo(playerid, ZOMBIE_TEAM, RandomZombieSkin(), 2352.0073,239.9916,26.4577,155.9241, 0, 0, 0, 0, 0, 0);
        default: SetSpawnInfo(playerid, ZOMBIE_TEAM, RandomZombieSkin(), 1933.6552,112.5678,31.8162,227.1534, 0, 0, 0, 0, 0, 0);
    }
    return 1;
}

CreateBars(playerid) {
    hungerbar[playerid] = CreatePlayerProgressBar(playerid, 548.50, 24.00, 55.5, 3.2, 0xffca1cFF, 100.0, BAR_DIRECTION_RIGHT);
    thirstbar[playerid] = CreatePlayerProgressBar(playerid, 548.50, 35.50, 55.5, 3.2, 0x3842ffFF, 100.0, BAR_DIRECTION_RIGHT);

    ShowPlayerProgressBar(playerid, hungerbar[playerid]);
    ShowPlayerProgressBar(playerid, thirstbar[playerid]);

    RefreshBars(playerid);
    return 1;
}

RefreshBars(playerid) {
    SetPlayerProgressBarValue(playerid, hungerbar[playerid], hunger[playerid]);
    SetPlayerProgressBarValue(playerid, thirstbar[playerid], thirst[playerid]);
    ResetHuds(playerid);

    if(hunger[playerid] < 45.0 || thirst[playerid] < 45.0) {
        WorseWeaponSkills(playerid);
        //SCM(playerid, HEX_YELLOW, "Your weapon skills are lowered.");
    }
    else {
        MilitaryWeaponSkills(playerid);
    }


    return 1;
}

new Timer:P_MinTimer[MAX_PLAYERS];
hook OnPlayerConnect(playerid) {
    if(IsPlayerConnected(playerid) && !IsPlayerNPC(playerid))
        P_MinTimer[playerid] = repeat OneMin(playerid);
    ShowRadiations(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason) {
    if(!IsPlayerNPC(playerid))
        stop P_MinTimer[playerid];
    return Y_HOOKS_CONTINUE_RETURN_1;
}

timer OneMin[60000](playerid) {
    if(IsPlayerConnected(playerid) && !IsPlayerNPC(playerid)) 
    {
        if(Bit_Get(loggedin, playerid) && Bit_Get(character, playerid)) 
        {
            if(GetPlayerSkin(playerid) <= 0 || GetPlayerSkin(playerid) >= 30000) {
                printf("[Debug] Player %s[%d] has skin %d under one minute timer while their p_skin is %d, fixing.", PlayerName(playerid), playerid, GetPlayerSkin(playerid), p_skin[playerid]);
                if(p_skin[playerid] > 0 && p_skin[playerid] < 30000) {
                    SFM(playerid, HEX_FADE2, "You've been detected to have an invalid CJ skin. A fix was run to set your skin id to %d!", p_skin[playerid]);
                    SetPlayerSkin(playerid, p_skin[playerid]);
                }
                else {
                    SCM(playerid, HEX_FADE2, "You've been detected to have an invalid CJ skin. Please use /skin!");
                    SetPlayerSkin(playerid, 177);
                    p_skin[playerid] = 177;
                }
                if(IsZombie(playerid))
                    SetPlayerSkin(playerid, RandomZombieSkin());
            }
            ChangeMaskVW(playerid);
            ++minutes[playerid];
            SetPlayerTime(playerid, ServerTime[hour], ServerTime[minute]);
            SetPlayerWeather(playerid, ServerTime[weather]);

            if(minutes[playerid] == 30)
                SendRandomHintMessage(playerid);

            if(minutes[playerid] > 59) 
            {
                minutes[playerid] = 0;
                ++experience[playerid];
                ++level[playerid];
                ++LuckSkill[playerid];
                if(3*(level[playerid]*level[playerid])-(3*level[playerid]) <= experience[playerid]) 
                {
                    SFM(playerid, HEX_YELLOW, "Congratulations, you have reached level %d!", level[playerid]);
                    SetPlayerScore(playerid, level[playerid]);
                }
                else 
                {
                    --level[playerid];
                    GameTextForPlayer(playerid, "~w~+1~g~ experience", 2000, 1);
                    GameTextForPlayer(playerid, "~w~+1~g~ luck", 2000, 1);
                }
            }

            hunger[playerid] -= frandom(1.0);
            thirst[playerid] -= frandom(1.0);

            if(Bit_Get(infected, playerid)) 
            {
                hunger[playerid] -= frandom(2.5);
                thirst[playerid] -= frandom(2.5);
                
                if(!random(10)) 
                {
                    if(!Bit_Get(spectating, playerid)) {
                        if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && !random(5)) {
                            PlayerAction(playerid, "throws up.");
                            ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);
                            hunger[playerid] -= frandom(10.0);
                            thirst[playerid] -= frandom(10.0);
                        }
                        else {
                            PlayerAction(playerid, "sweats.");
                        }
                    }
                }
            }

            if(hunger[playerid] < 0.0) hunger[playerid] = 0.0;
            if(thirst[playerid] < 0.0) thirst[playerid] = 0.0;

            RefreshBars(playerid);

            new Float:chp;
            GetPlayerHealth(playerid, chp);
            if(hunger[playerid] < 10.0) SetPlayerHealth(playerid, chp-frandom(2.0));
            GetPlayerHealth(playerid, chp);
            if(thirst[playerid] < 10.0) SetPlayerHealth(playerid, chp-frandom(2.0));

            if(chp < 150.0) 
            {
                if(hunger[playerid] > 90.0) SetPlayerHealth(playerid, chp+frandom(10.0));
                GetPlayerHealth(playerid, chp);
                if(thirst[playerid] > 90.0) SetPlayerHealth(playerid, chp+frandom(10.0));
            }

            GetPlayerHealth(playerid, chp);
            if(chp > 150.0)
                SetPlayerHealth(playerid, 150.0);

        }
        else if(!random(12))//responsible for kicking players who didn't log in
            Kick(playerid);
    }
}

timer TimedGameTextForPlayer[1000](tg_playerid, string:tg_string[], tg_time, tg_style)
{
    if(IsPlayerConnected(tg_playerid))
        GameTextForPlayer(tg_playerid, tg_string, tg_time, tg_style);
}


timer TimedPlayerPlaySound[1000](ps_playerid, ps_soundid, Float:ps_x, Float:ps_y, Float:ps_z)
{
    if(IsPlayerConnected(ps_playerid))
        PlayerPlaySound(ps_playerid, ps_soundid, ps_x, ps_y, ps_z);
}


TalkAnim(playerid, time) {
    if(!Bit_Get(inanim, playerid) && !Bit_Get(dead, playerid) && !IsPlayerInAnyVehicle(playerid)) {
        switch(talkstyle[playerid]) {
            case 1: ApplyAnimation(playerid, "PED", "IDLE_CHAT", 4.1, 1, 1, 1, 1, 1, 1);
            case 2: ApplyAnimation(playerid, "GANGS", "prtial_gngtlkA", 4.1, 1, 1, 1, 1, 1, 1);
            case 3: ApplyAnimation(playerid, "GANGS", "prtial_gngtlkB", 4.1, 1, 1, 1, 1, 1, 1);
            case 4: ApplyAnimation(playerid, "GANGS", "prtial_gngtlkC", 4.1, 1, 1, 1, 1, 1, 1);
            case 5: ApplyAnimation(playerid, "GANGS", "prtial_gngtlkD", 4.1, 1, 1, 1, 1, 1, 1);
            case 6: ApplyAnimation(playerid, "GANGS", "prtial_gngtlkE", 4.1, 1, 1, 1, 1, 1, 1);
            case 7: ApplyAnimation(playerid, "GANGS", "prtial_gngtlkF", 4.1, 1, 1, 1, 1, 1, 1);
            case 8: ApplyAnimation(playerid, "GANGS", "prtial_gngtlkG", 4.1, 1, 1, 1, 1, 1, 1);
            case 9: ApplyAnimation(playerid, "GANGS", "prtial_gngtlkH", 4.1, 1, 1, 1, 1, 1, 1);
        }

        Bit_Let(inanim, playerid);
        new counttime = time*100;
        if(counttime > 6000) counttime = 6000;
        defer TalkTime[counttime](playerid);
    }

    return 1;
}

timer TalkTime[1000](playerid) {
    if(Bit_Get(inanim, playerid)) {
        Bit_Vet(inanim, playerid);
        if(!Bit_Get(dead, playerid)) {
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
            ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
        }
    }
}

/*

Template:
{ "[name]", [minx], [miny], [maxx], [maxy], 0x[color-hex]FF },

---
{ "Zone r", 1872, -2848.96875, 2814, -1687.96875, 0xFF0000FF },
{ "Zone r", -2934, 571.03125, -1467, 1453.03125, 0xFF0000FF },
{ "Zone y", -2934, -222.9375, -1706, 573.0625, 0xFFFF00FF },
{ "Zone y", -518, 1453.0625, 970, 2901.0625, 0xFFFF00FF },
{ "Zone r", -2934, 1453.0625, -518, 2901.0625, 0xFF0000FF },
{ "Zone y", -1470, 577.0625, 974, 1453.0625, 0xFFFF00FF },
{ "Zone r", 970, 577.0625, 2950, 2621.0625, 0xFF0000FF },
{ "Zone y", 161, -1695.9375, 2897, -1167.9375, 0xFFFF00FF },

*/