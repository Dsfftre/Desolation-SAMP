/*#if defined _inc_zombies
	#undef _inc_zombies
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

#define Z_REVIVE_TIME 600000
#define Z_ATTACK_TIME 2000

new Zombies[MAX_ZOMBIES];

new Float:ZPos[MAX_ZOMBIES][3],
	Float:ZRoam[MAX_ZOMBIES][3];

RandomZombieSkin() {
	switch(random(21)) 
	{
		case 0: return 25001;
		case 1: return 25002;
		case 2: return 25003;
		case 3: return 25004;
		case 4: return 25005;
		case 5: return 25006;
		case 6: return 25007;
		case 7: return 25008;
		case 8: return 25009;
		case 9: return 25010;
		case 10: return 25011;
		case 11: return 25012;
		case 12: return 25013;
		case 13: return 25014;
		case 14: return 25015;
		case 15: return 25016;
		case 16: return 25017;
		case 17: return 25018;
		case 18: return 25019;
		case 19: return 25020;
		case 20: return 25021;
		default: return 78; 
	}
	return 20110;
}

LoadZombies() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `npc_zombies` WHERE state > 0 ORDER BY RAND() LIMIT %d", MAX_ZOMBIES_SPAWNING);
	inline LoadZombieData()
	{
		if(!cache_num_rows()) 
		{
			print("No zombies found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) 
		{
			new zname[MAX_PLAYER_NAME];
			new zscore;
			cache_get_value(i, "name", zname);
			cache_get_value_int(i, "score", zscore);
			format(zname, sizeof(zname), "%s_%i", zname, i);
			Zombies[i] = FCNPC_Create(zname);

			/*printf("debug of zombie spawning slots: zombies[i] = %d, where i = %d, while MAX_ZOMBIES = %d", Zombies[i], i, MAX_ZOMBIES);
			printf("debug of zombie spawning slots: max playeres set to %d", MAX_PLAYERS);*/

			cache_get_value_float(i, "posx", ZPos[i][0]);
			cache_get_value_float(i, "posy", ZPos[i][1]);
			cache_get_value_float(i, "posz", ZPos[i][2]);

			
			Group_SetPlayer(npc_Zombie, Zombies[i], true);
			FCNPC_Spawn(Zombies[i], RandomZombieSkin(), ZPos[i][0], ZPos[i][1], ZPos[i][2]);
			FCNPC_SetHealth(Zombies[i], ZOMBIE_BASE_HP + frandom(ZOMBIE_BASE_HP)  + frandom(ZOMBIE_BASE_HP));
			FCNPC_SetInvulnerable(Zombies[i], false);
			FCNPC_SetPosition(Zombies[i], ZPos[i][0], ZPos[i][1], ZPos[i][2]);
			FCNPC_SetAngle(Zombies[i], frandom(360.0));
			SetPlayerScore(Zombies[i], zscore);
			cache_get_value_int(i, "id", zscore);
			SetPVarInt(Zombies[i], "zsqlid", zscore);
			AI_SetReaction(Zombies[i], AI_MODE_HOSTILE);
			SetPVarInt(Zombies[i], "ztarget", -1);
			SetPVarInt(Zombies[i], "lootable", 1);
			SetPVarInt(Zombies[i], "zackid", i);
			SetPlayerTeam(Zombies[i], ZOMBIE_TEAM);
			SetPlayerColor(Zombies[i], COLOR_ZOMBIE);
			startRoaming(Zombies[i]);
		}
		printf("%d zombies loaded.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadZombieData, sql);
	return 1;
}

IsZombie(playerid) {
    if(Group_GetPlayer(npc_Zombie, playerid))
        return 1;
	if(Group_GetPlayer(g_Zombie, playerid))
        return 1;
	if(Bit_Get(pzombie, playerid))
		return 1;
    return 0;
}

hook OnGameModeInit() {
	g_Zombie = Group_Create("zombie");
	npc_Zombie = Group_Create("npc_zombies");
	LoadZombies();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook AI_OnPlayerApproachNPC(playerid, npcid) {
    if(Group_GetPlayer(npc_Zombie, npcid) && !Group_GetPlayer(g_AdminDuty, playerid) && IsHuman(playerid)) 
	{
		if(FCNPC_IsMovingAtPlayer(npcid, GetPVarInt(npcid, "ztarget"))) return Y_HOOKS_CONTINUE_RETURN_1;
        new Float:pos2[3],Float:pos[3];
        GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
        FCNPC_GetPosition(npcid, pos2[0], pos2[1], pos2[2]);
        if(IsInLOS(pos, pos2)) 
		{
			FCNPC_GoToPlayer(npcid, playerid, FCNPC_MOVE_TYPE_SPRINT, FCNPC_MOVE_SPEED_SPRINT, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 1.5, 250);
			SetPVarInt(npcid, "ztarget", playerid);
			//PlayRandomZombieNoise(pos[0], pos[1], pos[2]);
		}
		/*else
            AI_DistTimer[playerid][npcid] = repeat AI_OnDistancecheck(playerid, npcid);*/
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook FCNPC_OnReachDest(npcid) {
	if(Group_GetPlayer(npc_Zombie, npcid)) 
	{
		new Float:pos[3];
		new target = GetPVarInt(npcid, "ztarget");
		FCNPC_GetPosition(npcid, pos[0], pos[1], pos[2]);
		if(IsPlayerConnected(target) && !Group_GetPlayer(g_AdminDuty, target) && IsHuman(target)) 
		{
			if(GetPlayerDistanceFromPoint(target, pos[0], pos[1], pos[2]) < 1.1) 
			{
				FCNPC_MeleeAttack(npcid, -1, false);
				defer StopZombieAttack(npcid, target);
			}
			else if(GetPlayerDistanceFromPoint(target, pos[0], pos[1], pos[2]) < IN_ZOMBIE_SIGHT*2) 
			{
				new Float:pos2[3];
				GetPlayerPos(target, pos2[0], pos2[1], pos2[2]);
				if(IsInLOS(pos, pos2)) 
					FCNPC_GoToPlayer(npcid, target, FCNPC_MOVE_TYPE_SPRINT, FCNPC_MOVE_SPEED_SPRINT, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 1.0, 250);
				else {
					//AI_DistTimer[target][npcid] = repeat AI_OnDistancecheck(target, npcid);
					startRoaming(npcid);
					//PlayRandomZombieNoise(pos[0], pos[1], pos[2]);
				}
			}
		}
		else {
			FCNPC_StopAim(npcid);
			FCNPC_SetKeys(npcid, 0, 0, 0);
			defer roamingturn[random(30000)+5000](npcid);
		}

	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

timer StopZombieAttack[Z_ATTACK_TIME](npcid, target) {
	new Float:pos[3];
	FCNPC_GetPosition(npcid, pos[0], pos[1], pos[2]);
	if(GetPlayerDistanceFromPoint(target, pos[0], pos[1], pos[2]) < 1.1) 
	{
		defer StopZombieAttack(npcid, target);
	}
	else if(GetPlayerDistanceFromPoint(target, pos[0], pos[1], pos[2]) < IN_ZOMBIE_SIGHT*3) 
	{
		FCNPC_StopAttack(npcid);
		new Float:pos2[3];
		GetPlayerPos(target, pos2[0], pos2[1], pos2[2]);
		if(IsInLOS(pos, pos2)) 
			FCNPC_GoTo(npcid, pos[0], pos[1], pos[2], FCNPC_MOVE_TYPE_SPRINT, FCNPC_MOVE_SPEED_SPRINT, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 250);
		/*else
			AI_DistTimer[target][npcid] = repeat AI_OnDistancecheck(target, npcid);*/
	}
	else if(FCNPC_IsStreamedIn(npcid, target)) 
	{
		FCNPC_StopAttack(npcid);
		//AI_DistTimer[target][npcid] = repeat AI_OnDistancecheck(target, npcid);
	}
}

hook FCNPC_OnGiveDamage(npcid, damagedid, Float:amount, weaponid, bodypart) {
	if(Bit_Get(dead, damagedid)) return Y_HOOKS_BREAK_RETURN_0;
	if(Group_GetPlayer(npc_Zombie, npcid)) 
	{
		if(Group_GetPlayer(g_AdminDuty, damagedid) || Bit_Get(dead, damagedid) || !IsHuman(damagedid)) 
		{
			FCNPC_StopAttack(npcid);
			if(Bit_Get(dead, damagedid))
			ApplyDeathAnimation(damagedid);
		}
		else if(weaponid == 0 && !IsPlayerNPC(damagedid)) 
		{
			if(!Bit_Get(infected, damagedid) && !Group_GetPlayer(g_AdminDuty, damagedid) && IsHuman(damagedid)) 
			{
				if(!random(INFECTION_CHANCE)) {//infect player
					Bit_Let(infected, damagedid);
					SCM(damagedid, HEX_YELLOW, "You have been infected!");
					new string[128];
					format(string, sizeof string, "[LOG]: %s[%d] has been infected.", PlayerName(damagedid), damagedid);
					SendAdminMessage(HEX_YELLOW, string, true);
					SetPlayerDrunkLevel(damagedid, 4500);
					new Float:pos[3];
	    			FCNPC_GetPosition(npcid, pos[0], pos[1], pos[2]);
					//PlayRandomZombieNoise(pos[0], pos[1], pos[2]);
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook FCNPC_OnDeath(npcid, killerid, weaponid) {
	if(Group_GetPlayer(npc_Zombie, npcid)) 
	{
		if(halloween_event)
			defer Z_revive[Z_REVIVE_TIME/3](npcid);
		else
			defer Z_revive(npcid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

timer Z_revive[Z_REVIVE_TIME](npcid) {
	FCNPC_Respawn(npcid);
	FCNPC_SetPosition(npcid, ZPos[GetPVarInt(npcid, "zackid")][0], ZPos[GetPVarInt(npcid, "zackid")][1], ZPos[GetPVarInt(npcid, "zackid")][2]);
	FCNPC_SetHealth(npcid, ZOMBIE_BASE_HP + frandom(ZOMBIE_BASE_HP) + frandom(ZOMBIE_BASE_HP));
	FCNPC_SetInvulnerable(npcid, false);
	SetPVarInt(npcid, "lootable", 1);
	startRoaming(npcid);
}

hook FCNPC_OnTakeDamage(npcid, issuerid, Float:amount, weaponid, bodypart) {
	if(Group_GetPlayer(npc_Zombie, npcid)) 
	{
		if(FCNPC_IsMovingAtPlayer(npcid, issuerid)) return Y_HOOKS_CONTINUE_RETURN_1;
		new target = GetPVarInt(npcid, "ztarget");
		if((FCNPC_IsMoving(npcid) && target == -1) || IsPlayerInAnyVehicle(target) || !FCNPC_IsMoving(npcid)) 
		{
			FCNPC_GoToPlayer(npcid, issuerid, FCNPC_MOVE_TYPE_SPRINT, FCNPC_MOVE_SPEED_SPRINT, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 1.5, 250);
			SetPVarInt(npcid, "ztarget", issuerid);
			//new Float:pos[3];
	    	//FCNPC_GetPosition(npcid, pos[0], pos[1], pos[2]);
			//PlayRandomZombieNoise(pos[0], pos[1], pos[2]);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook FCNPC_OnStreamOut(npcid, forplayerid) {
	if(Group_GetPlayer(npc_Zombie, npcid)) 
	{
		if(GetPVarInt(npcid, "ztarget") == forplayerid) 
		{
			if(FCNPC_IsAttacking(npcid))
			FCNPC_StopAttack(npcid);
			FCNPC_Stop(npcid);
			SetPVarInt(npcid, "ztarget", -1);
			startRoaming(npcid);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

BiteMechanism(playerid, targetid) {
	ApplyAnimation(playerid, "BASEBALL", "BAT_HIT_2", 4.0, 0, 1, 1, 0, 0, 1);
	ApplyAnimation(targetid, "FIGHT_E", "HIT_FIGHTKICK", 4.1, 0, 1, 1, 0, 0, 1);

	new Float:health;
	if(!Bit_Get(infected, targetid)) 
	{//infect player
		Bit_Let(infected, targetid);
		SCM(targetid, HEX_YELLOW, "You have been infected!");
		new string[128];
		format(string, sizeof string, "[LOG]: %s[%d] has been infected by %s[%d].", PlayerName(targetid), targetid,  PlayerName(playerid), playerid);
		SendAdminMessage(HEX_YELLOW, string, true);
		SetPlayerDrunkLevel(targetid, 2500);
		RandomInfectionMessage(playerid, targetid);
		++count_infest[playerid];
		hunger[playerid] += frandom(20.0);
		thirst[playerid] += frandom(20.0);
		hunger[targetid] -= frandom(10.0);
		thirst[targetid] -= frandom(10.0);
		RefreshBars(playerid);
		RefreshBars(targetid);
	}
	else 
	{	
		SetPlayerDrunkLevel(targetid, 3500);
		RandomInfectionMessage(playerid, targetid);
		++count_infest[playerid];
		hunger[playerid] += frandom(10.0);
		thirst[playerid] += frandom(10.0);
		RefreshBars(playerid);
		GetPlayerHealth(playerid, health);
		health += frandom(20.0);
		SetPlayerHealth(playerid, health);
	}
	GetPlayerHealth(targetid, health);
	if(!random(3)) 
	{
		if(health > 100.0) SetPlayerHealth(targetid, 100.0);
		else if(health > 80.0) SetPlayerHealth(targetid, 80.0);
		else if(health > 60.0) SetPlayerHealth(targetid, 60.0);
		else if(health > 40.0) SetPlayerHealth(targetid, 40.0);
		else if(health > 20.0) SetPlayerHealth(targetid, 20.0);
	}
	return 1;
}

/*hook OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart) {
	if(weaponid == 0 && !IsPlayerNPC(issuerid) && !IsPlayerNPC(playerid)) {
		if(!Group_GetPlayer(g_AdminDuty, playerid) && IsHuman(playerid) && !IsHuman(issuerid)) {
			BiteMechanism(issuerid, playerid);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}*/

RandomInfectionMessage(playerid, target) {
	new string[256];
	switch(random(8)) 
	{
		case 0: format(string, sizeof string, "> %s bites into the flesh of %s.", PlayerName(playerid, false), PlayerName(target, false));
		case 1: format(string, sizeof string, "> %s grabs %s, biting into their shoulder.", PlayerName(playerid, false), PlayerName(target, false));
		case 2: format(string, sizeof string, "> %s jumps on %s, biting into their neck.", PlayerName(playerid, false), PlayerName(target, false));
		case 3: format(string, sizeof string, "> %s grabs %s, biting into their arm.", PlayerName(playerid, false), PlayerName(target, false));
		case 4: format(string, sizeof string, "> %s spits it's salvia into the face of %s.", PlayerName(playerid, false), PlayerName(target, false));
		case 5: format(string, sizeof string, "> %s makes a gash in %s.", PlayerName(playerid, false), PlayerName(target, false));
		case 6: format(string, sizeof string, "> %s wounds %s with their nails.", PlayerName(playerid, false), PlayerName(target, false));
		case 7: format(string, sizeof string, "> %s tears into %s.", PlayerName(playerid, false), PlayerName(target, false));
	}
	//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE);
	//ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, string);
	PlayerAction(playerid, string, false);
	return 1;
}

ChooseZombieType(playerid) { // 
	
	new string[512];
	string="Wanderer\t(Classic zombie.)\nJumper\t(May leap over huge walls with sprint + jump.)\nRunner\t(Sprints indefinitely with Y.)\nBloater\t(Explodes upon death.)\nScreecher\t(May temporarily immobilize nearby humans with Y.)\nSniffer\t(Detects nearby humans with N.)\nHulks\t(Increased strength.)";
	inline Dialog_zombietype_main(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) 
	{
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response)
			ChangeZombieType(playerid, Open_listitem);
	}	
	Dialog_ShowCallback(playerid, using inline Dialog_zombietype_main, DIALOG_STYLE_LIST, "Select your mutation!", string, "Choose","Exit");
	return 1;
}

ChangeZombieType(playerid, chosen_listid) {
	zombierace[playerid] = chosen_listid;
	SCM(playerid, HEX_YELLOW, "Your zombie race has been changed!");
	return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(Bit_Get(pzombie, playerid)) {
		if(!IsPlayerInAnyVehicle(playerid)) 
		{
			if((!IsHuman(playerid) && (IsRunner(playerid) || IsTyrant(playerid))) || IsTHT(playerid) ) 
			{ // sprinter zombie sprinting with Y
				if((newkeys & KEY_YES) && !(oldkeys & KEY_YES))
				ApplyAnimation(playerid, "PED", "sprint_civi", 7.0, 1, 1, 1, 1, 1, 1);
				if((oldkeys & KEY_YES) && !(newkeys & KEY_YES))
				ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0, 1);
			}

			if(!IsHuman(playerid) && (newkeys & KEY_WALK) ) 
			{

				new Float:z_pos[3];
				new targetid = GetPlayerTargetPlayer(playerid);
				GetPlayerPos(targetid, z_pos[0], z_pos[1], z_pos[2]);

				if(!IsPlayerInRangeOfPoint(playerid, 2.1, z_pos[0], z_pos[1], z_pos[2])) SCM(playerid, HEX_RED, "Error: You need to be closer.");
				else if(targetid == INVALID_PLAYER_ID || IsPlayerNPC(targetid) || !IsHuman(targetid)) SCM(playerid, HEX_RED, "Error: You must target a player human with holding right click.");
				else
					BiteMechanism(playerid, targetid);
			}

			if(!IsHuman(playerid) && (IsJumper(playerid) || IsTyrant(playerid)) ) 
			{ // jumper zombie jumping with SPACE + SHIFT
				if((newkeys & KEY_SPRINT) && (newkeys & KEY_JUMP)) 
				{
					if(Bit_Get(spellcooldown, playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
					new Float:vx, Float:vy, Float:vz;
					new Float:rot;
					GetPlayerFacingAngle(playerid, rot);
					rot = 360 - rot;
					GetPlayerVelocity(playerid,vx,vy,vz);
					SetPlayerVelocity(playerid,vx+(3*0.02)*floatsin(rot, degrees),vy+(3*0.02)*floatcos(rot,degrees),vz+(3*0.1));
					Bit_Let(spellcooldown, playerid);
					defer Cooldown[5000](playerid);
				}
			}
				
			if(!IsHuman(playerid) && (IsScreecher(playerid) || IsTyrant(playerid)) ) 
			{ // screamer zombie screaming with Y
				if((oldkeys & KEY_YES) && !(newkeys & KEY_YES)) 
				{
					if(Bit_Get(spellcooldown, playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
					new Float:zppos[3];
					GetPlayerPos(playerid, zppos[0], zppos[1], zppos[2]);
					PlayerAction(playerid, "screams.");
					Bit_Let(spellcooldown, playerid);
					defer Cooldown(playerid);
					GameTextForPlayer(playerid, "~y~You can scream again in 60 seconds.", 3400, 4);
					foreach(new i:Player) 
					{
						if(GetPlayerInterior(playerid) == GetPlayerInterior(i) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i)) 
						{
							if(IsPlayerInRangeOfPoint(i, 25.0, zppos[0], zppos[1], zppos[2]) && IsHuman(i))
							StunPlayer(i);
						}
					}
				}
			}

			if((!IsHuman(playerid) && (IsSniffer(playerid) || IsTyrant(playerid))) || IsTHT(playerid) ) 
			{ // sniffing with N
				if((oldkeys & KEY_NO) && !(newkeys & KEY_NO)) 
				{
					if(Bit_Get(spellcooldown, playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
					new Float:zppos[3];
					GetPlayerPos(playerid, zppos[0], zppos[1], zppos[2]);
					PlayerAction(playerid, "sniffs.");
					Bit_Let(spellcooldown, playerid);
					defer Cooldown(playerid);
					defer StopDetection(playerid);
					ApplyAnimation(playerid, "INT_SHOP", "shop_lookA", 4.0, 0, 1, 1, 0, 0, 1);
					SCM(playerid, HEX_YELLOW, "You can sniff again in 60 seconds.");
					foreach(new i:Player) 
					{
						if(!Bit_Get(spectating, i) && GetPlayerInterior(playerid) == GetPlayerInterior(i) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i)) 
						{
							if(IsPlayerInRangeOfPoint(i, 125.0, zppos[0], zppos[1], zppos[2]))
							DetectInrange(playerid, i);
						}
					}
					foreach(new j:GroupMember[npc_Zombie]) 
					{
						if(GetPlayerInterior(playerid) == GetPlayerInterior(j) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(j)) 
						{
							if(IsPlayerInRangeOfPoint(j, 125.0, zppos[0], zppos[1], zppos[2]))
							DetectInrange(playerid, j);
						}
					}
					foreach(new k:GroupMember[npc_a51]) 
					{
						if(GetPlayerInterior(playerid) == GetPlayerInterior(k) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(k)) 
						{
							if(IsPlayerInRangeOfPoint(k, 125.0, zppos[0], zppos[1], zppos[2]))
							DetectInrange(playerid, k);
						}
					}
				}
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

timer Cooldown[ZOMBIE_SPELL_COOLDOWN](playerid) {
	Bit_Vet(spellcooldown, playerid);
}

DetectInrange(playerid, targetid) {
	if(IsZombie(targetid) || IsTHT(targetid))
		SetPlayerMarkerForPlayer(playerid, targetid, COLOR_ZOMBIE_SNIFF);
	else
		SetPlayerMarkerForPlayer(playerid, targetid, COLOR_HUMAN_SNIFF);
	return 1;
}

timer StopDetection[SNIFF_DURATION](playerid) {
	HidePlayerMarkers(playerid);
}

StunPlayer(playerid) {
	if(Bit_Get(dead, playerid) || Bit_Get(frozen, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) return 0;
	if(IsPlayerInAnyVehicle(playerid)) return 0;
	if(Bit_Get(spectating, playerid)) return 0;

	SetPlayerDrunkLevel(playerid, 4500);
	ApplyAnimation(playerid, "FIGHT_E", "HIT_FIGHTKICK_B", 3.0, 0, 1, 1, 0, 0, 1);
	PlayerHiddenAction(playerid, "has been stunned.");
	
	return 1;
}

YCMD:human(playerid, params[], help) {
	if(!IsRPName(PlayerName(playerid))) return SCM(playerid, HEX_RED, "Error: You do not have a roleplay name, therefore you cannot turn into human. Please create a new character if you want to play as a human!");
	if(IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Only zombies can use this command.");
	if(count_infest[playerid] < 3 && !Group_GetPlayer(g_AdminDuty, playerid)) return SFM(playerid, HEX_RED, "Error: You need to infect 3 humans before turning back. (%d/3)", count_infest[playerid]);

	inline Dialog_help_Main(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response) {
			Bit_Vet(infected, playerid);
			Bit_Vet(pzombie, playerid);
			Group_SetPlayer(g_Zombie, playerid, false);
			SCM(playerid, HEX_YELLOW, "You are human again!");
			if(Bit_Get(tutorial, playerid))
				SFM(playerid, HEX_FADE2, "Hint: In-character %s was never a zombie.", PlayerName(playerid, false));
			
			/*mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `deaths` = `deaths`-1 WHERE id = '%d' LIMIT 1",  CharacterSQL[playerid]);
			mysql_tquery(g_SQL, sql, "", "");*/
			RandomHumanSpawn(playerid);
			SpawnPlayer(playerid);
			SetPlayerSkin(playerid, 29);
		}
	}	
	Dialog_ShowCallback(playerid, using inline Dialog_help_Main, DIALOG_STYLE_MSGBOX, "Race change confirmation", "\nAre you sure you want to turn into human?\n", "Confirm","Back");
	return 1;
}

YCMD:mutation(playerid, params[], help) {
	if(!IsHuman(playerid)) ChooseZombieType(playerid);
	else SCM(playerid, HEX_RED, "Error: Only zombies can use this command.");
	return 1;
}


startRoaming(npcid) {
	if(Group_GetPlayer(npc_Zombie, npcid)) 
	{
		FCNPC_StopAim(npcid);
		FCNPC_SetKeys(npcid, 0, 0, 0);
		new zombieid = GetPVarInt(npcid, "zackid");
		new Float:pos[3];
		FCNPC_GetPosition(npcid, pos[0], pos[1], pos[2]);

		new attempt = -1;
		new Float:add[3];
		for(;++attempt<30;) {
			add[0] = frandom(5.0)+2.1;
			if(random(1))
				add[0] += pos[0];
			else
				add[0] = pos[0]-add[0];

			add[1] = frandom(5.0)+2.1;
			if(random(1))
				add[1] += pos[1];
			else
				add[1] = pos[1]-add[1];

			CA_FindZ_For2DCoord(add[0], add[1], add[2]);
			add[2] += 0.6;

			if(IsInLOS(pos, add, false) && add[2]-pos[2] < 3.0) {
				ZRoam[zombieid][0] = add[0];
				ZRoam[zombieid][1] = add[1];
				ZRoam[zombieid][2] = add[2];
				FCNPC_GoTo(npcid, ZRoam[zombieid][0], ZRoam[zombieid][1], ZRoam[zombieid][2], FCNPC_MOVE_TYPE_WALK, FCNPC_MOVE_SPEED_WALK, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 250);
				//printf("startroaming %d npcid %d zombieid: %f %f %f", npcid, zombieid, ZRoam[zombieid][0], ZRoam[zombieid][1], ZRoam[zombieid][2]);
				return 1;
			}
		}
	}
	return 0;
}

timer roamingturn[30000](npcid) {
	new zombieid = GetPVarInt(npcid, "zackid");
	if(IsPlayerInRangeOfPoint(npcid, 3.0, ZPos[zombieid][0], ZPos[zombieid][1], ZPos[zombieid][2])) {
		FCNPC_GoTo(npcid, ZRoam[zombieid][0], ZRoam[zombieid][1], ZRoam[zombieid][2], FCNPC_MOVE_TYPE_WALK, FCNPC_MOVE_SPEED_WALK, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 250);
		//printf("roamingturn %d npcid %d zombieid: %f %f %f", npcid, zombieid, ZRoam[zombieid][0], ZRoam[zombieid][1], ZRoam[zombieid][2]);
	}
	else {
		FCNPC_GoTo(npcid, ZPos[zombieid][0], ZPos[zombieid][1], ZPos[zombieid][2], FCNPC_MOVE_TYPE_WALK, FCNPC_MOVE_SPEED_WALK, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 250);
		//printf("FCNPC_GoTo Zpos %d npcid %d zombieid: %f %f %f", npcid, zombieid, ZPos[zombieid][0], ZPos[zombieid][1], ZPos[zombieid][2]);
	}
}

hook OnPlayerDeath(playerid, killerid, reason) {
	if(IsPlayerConnected(playerid) && !IsPlayerNPC(playerid) && (reason > 15 || GetPVarInt(playerid, "weaponby") > 15)) {
		if(IsZombie(playerid) && IsBloater(playerid)) {
			BloaterExplosion(playerid);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

BloaterExplosion(playerid) {
	new Float:expos[3];
	GetPlayerPos(playerid, expos[0], expos[1], expos[2]);
	CreateExplosion(expos[0], expos[1], expos[2], 7, 16.0);
	CreateExplosion(expos[0], expos[1], expos[2], 7, 12.0);
	return 1;
}

stock Play3DSound(audio_id, Float:x, Float:y, Float:z, Float:distance=25.0, world=0, soundid = 0) {
	foreach(new playerid : Player) 
	{
		if(GetPlayerVirtualWorld(playerid) == world) 
		{
			if(IsPlayerInRangeOfPoint(playerid, distance + 5.0, x, y, z)) 
			{
				if (Audio_IsClientConnected(playerid))
				{
					new handle = Audio_Play(playerid, audio_id, true);

					Audio_Set3DPosition(playerid, handle, x, y, z, 25.0);

					Audio_Resume(playerid, handle);
				}
				else
				{
				    if (soundid > 0)
				    {
				        PlayerPlaySound(playerid, soundid, x, y, z);
				    }
				}
			}
		}
	}
}

/*stock //PlayRandomZombieNoise(Float:x, Float:y, Float:z, Float:distance=25.0, world=0) {
	foreach(new playerid : Player) 
	{
		if(GetPlayerVirtualWorld(playerid) == world) 
		{
			if(IsPlayerInRangeOfPoint(playerid, distance + 5.0, x, y, z)) 
			{
				if (Audio_IsClientConnected(playerid))
				{
					switch(random(17)) 
					{
						case 0: Audio_Play(playerid, 3);
						case 1: Audio_Play(playerid, 4);
						case 2: Audio_Play(playerid, 5);
						case 3: Audio_Play(playerid, 6);
						case 4: Audio_Play(playerid, 7);
						case 5: Audio_Play(playerid, 8);
						case 6: Audio_Play(playerid, 9);
						case 7: Audio_Play(playerid, 10);
						case 8: Audio_Play(playerid, 11);
						case 9: Audio_Play(playerid, 12);
						case 10: Audio_Play(playerid, 13);
						case 11: Audio_Play(playerid, 14);
						case 12: Audio_Play(playerid, 15);
						case 13: Audio_Play(playerid, 16);
						case 14: Audio_Play(playerid, 17);
						case 15: Audio_Play(playerid, 18);
						case 16: Audio_Play(playerid, 19);
						case 17: Audio_Play(playerid, 20);
					}
				}
			}
		}
	}
}*/
DamageNPC(npcid, weaponid) {

	if(FCNPC_GetArmour(npcid) > 10.0)
		switch(weaponid) {
			case 2: FCNPC_GiveArmour(npcid, REDMG_GOLFCLUB*-1);
			case 3: FCNPC_GiveArmour(npcid, REDMG_NIGHTSTICK*-1);
			case 4: FCNPC_GiveArmour(npcid, REDMG_KNIFE*-1);
			case 5: FCNPC_GiveArmour(npcid, REDMG_BASEBALLBAT*-1);
			case 7: FCNPC_GiveArmour(npcid, REDMG_POOLSTICK*-1);
			case 8: FCNPC_GiveArmour(npcid, REDMG_KATANA*-1);
			case 22: FCNPC_GiveArmour(npcid, REDMG_COLT45*-1);
			case 23: FCNPC_GiveArmour(npcid, REDMG_SILENCED*-1);
			case 24: FCNPC_GiveArmour(npcid, REDMG_DEAGLE*-1);
			case 25: FCNPC_GiveArmour(npcid, REDMG_SHOTGUN*-1);
			case 26: FCNPC_GiveArmour(npcid, REDMG_SAWEDOFF*-1);
			case 27: FCNPC_GiveArmour(npcid, REDMG_SHOTGSPA*-1);
			case 28: FCNPC_GiveArmour(npcid, REDMG_UZI*-1);
			case 29: FCNPC_GiveArmour(npcid, REDMG_MP5*-1);
			case 30: FCNPC_GiveArmour(npcid, REDMG_AK47*-1);
			case 31: FCNPC_GiveArmour(npcid, REDMG_M4*-1);
			case 32: FCNPC_GiveArmour(npcid, REDMG_TEC9*-1);
			case 33: FCNPC_GiveArmour(npcid, REDMG_RIFLE*-1);
			case 34: FCNPC_GiveArmour(npcid, REDMG_SNIPER*-1);
			case 38: FCNPC_GiveArmour(npcid, REDMG_MINIGUN*-1);
		}
	else
		switch(weaponid) {
			case 2: if(FCNPC_GetHealth(npcid) - REDMG_GOLFCLUB >= 1.0) FCNPC_GiveHealth(npcid, REDMG_GOLFCLUB*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 3: if(FCNPC_GetHealth(npcid) - REDMG_NIGHTSTICK >= 1.0) FCNPC_GiveHealth(npcid, REDMG_NIGHTSTICK*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 4: if(FCNPC_GetHealth(npcid) - REDMG_KNIFE >= 1.0) FCNPC_GiveHealth(npcid, REDMG_KNIFE*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 5: if(FCNPC_GetHealth(npcid) - REDMG_BASEBALLBAT >= 1.0) FCNPC_GiveHealth(npcid, REDMG_BASEBALLBAT*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 7: if(FCNPC_GetHealth(npcid) - REDMG_POOLSTICK >= 1.0) FCNPC_GiveHealth(npcid, REDMG_POOLSTICK*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 8: if(FCNPC_GetHealth(npcid) - REDMG_KATANA >= 1.0) FCNPC_GiveHealth(npcid, REDMG_KATANA*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 22: if(FCNPC_GetHealth(npcid) - REDMG_COLT45 >= 1.0) FCNPC_GiveHealth(npcid, REDMG_COLT45*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 23: if(FCNPC_GetHealth(npcid) - REDMG_SILENCED >= 1.0) FCNPC_GiveHealth(npcid, REDMG_SILENCED*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 24: if(FCNPC_GetHealth(npcid) - REDMG_DEAGLE >= 1.0) FCNPC_GiveHealth(npcid, REDMG_DEAGLE*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 25: if(FCNPC_GetHealth(npcid) - REDMG_SHOTGUN >= 1.0) FCNPC_GiveHealth(npcid, REDMG_SHOTGUN*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 26: if(FCNPC_GetHealth(npcid) - REDMG_SAWEDOFF >= 1.0) FCNPC_GiveHealth(npcid, REDMG_SAWEDOFF*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 27: if(FCNPC_GetHealth(npcid) - REDMG_SHOTGSPA >= 1.0) FCNPC_GiveHealth(npcid, REDMG_SHOTGSPA*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 28: if(FCNPC_GetHealth(npcid) - REDMG_UZI >= 1.0) FCNPC_GiveHealth(npcid, REDMG_UZI*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 29: if(FCNPC_GetHealth(npcid) - REDMG_MP5 >= 1.0) FCNPC_GiveHealth(npcid, REDMG_MP5*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 30: if(FCNPC_GetHealth(npcid) - REDMG_AK47 >= 1.0) FCNPC_GiveHealth(npcid, REDMG_AK47*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 31: if(FCNPC_GetHealth(npcid) - REDMG_M4 >= 1.0) FCNPC_GiveHealth(npcid, REDMG_M4*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 32: if(FCNPC_GetHealth(npcid) - REDMG_TEC9 >= 1.0) FCNPC_GiveHealth(npcid, REDMG_TEC9*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 33: if(FCNPC_GetHealth(npcid) - REDMG_RIFLE >= 1.0) FCNPC_GiveHealth(npcid, REDMG_RIFLE*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 34: if(FCNPC_GetHealth(npcid) - REDMG_SNIPER >= 1.0) FCNPC_GiveHealth(npcid, REDMG_SNIPER*-1); else FCNPC_SetHealth(npcid, 1.0);
			case 38: if(FCNPC_GetHealth(npcid) - REDMG_MINIGUN >= 1.0) FCNPC_GiveHealth(npcid, REDMG_MINIGUN*-1); else FCNPC_SetHealth(npcid, 1.0);
		}
	return 1;
}