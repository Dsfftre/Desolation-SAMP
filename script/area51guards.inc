/*#if defined _inc_area51guards
	#undef _inc_area51guards
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

#define A51_REVIVE_TIME 1200000
//#define A51_REVIVE_TIME 10000 //for debugging the revive system


hook OnGameModeInit()
{
	npc_a51 = Group_Create("a51npcs");
	FCNPC_SetUpdateRate(80);
	//SetTimerEx("createSoldiers", 3000, false, "");
	LoadGuards();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadGuards() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `npc_guards` WHERE state > 0 ORDER BY RAND() LIMIT %d", MAX_GUARDS);
	inline LoadGuardsData() {
		if(!cache_num_rows()) {
			print("No guards found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			new zname[MAX_PLAYER_NAME];
			new zscore;
			cache_get_value_int(i, "type", SoldierType[i]);
			cache_get_value_int(i, "skin", SoldierSkin[i]);
			cache_get_value(i, "name", zname);
			cache_get_value_int(i, "score", zscore);
			cache_get_value_float(i, "posx", SoldierPositions[i][0]);
			cache_get_value_float(i, "posy", SoldierPositions[i][1]);
			cache_get_value_float(i, "posz", SoldierPositions[i][2]);
			cache_get_value_float(i, "posf", SoldierPositions[i][3]);
			


			format(zname, sizeof(zname), "%s_%i", zname, i);

			Soldier[i] = FCNPC_Create(zname);

			Group_SetPlayer(npc_a51, Soldier[i], true);

			if(SoldierSkin[i] > 0)
				FCNPC_Spawn(Soldier[i], SoldierSkin[i], SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
			else {
				if(SoldierType[i] == 0) {
					switch(random(10)) {
						case 1: FCNPC_Spawn(Soldier[i], 287, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
						case 2: FCNPC_Spawn(Soldier[i], 191, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
						case 3: FCNPC_Spawn(Soldier[i], 179, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
						case 4: FCNPC_Spawn(Soldier[i], 191, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
						default: FCNPC_Spawn(Soldier[i], 287, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
					}

				}

				if(SoldierType[i] > 0) {

					switch(random(10)) {
						case 1: FCNPC_Spawn(Soldier[i], 310, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
						case 2: FCNPC_Spawn(Soldier[i], 302, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
						case 3: FCNPC_Spawn(Soldier[i], 311, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
						default: FCNPC_Spawn(Soldier[i], 310, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
					}
				}
			}
			
			FCNPC_SetHealth(Soldier[i], 100.0 + frandom(50.0));
			FCNPC_SetArmour(Soldier[i], 100.0);
			FCNPC_SetInvulnerable(Soldier[i], false);
			FCNPC_SetPosition(Soldier[i], SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
			FCNPC_SetAngle(Soldier[i], SoldierPositions[i][3]);
			SetPVarInt(Soldier[i], "a51id", i);
			SetPlayerColor(Soldier[i], COLOR_NPC);
			SetPlayerScore(Soldier[i], zscore);
			cache_get_value_int(i, "id", zscore);
			SetPVarInt(Soldier[i], "gsqlid", zscore);
			SetPVarInt(Soldier[i], "lootable", 1);
			SetPVarInt(Soldier[i], "lootedby", -1);

			if(SoldierType[i] == 0) {
				switch(random(3)) { 
					case 0: { FCNPC_SetWeapon(Soldier[i], 31); FCNPC_SetWeaponAccuracy(Soldier[i], 31, 0.8); }
					case 1: { FCNPC_SetWeapon(Soldier[i], 29); FCNPC_SetWeaponAccuracy(Soldier[i], 29, 1.1); }
					case 2: { FCNPC_SetWeapon(Soldier[i], 30); FCNPC_SetWeaponAccuracy(Soldier[i], 30, 0.8); }
				}
				SetPVarInt(Soldier[i], "npcgun", FCNPC_GetWeapon(Soldier[i]));				
				FCNPC_SetWeaponSkillLevel(Soldier[i], WEAPONSKILL_AK47, 1000);
				FCNPC_SetWeaponSkillLevel(Soldier[i], WEAPONSKILL_M4, 999);
				FCNPC_SetWeaponSkillLevel(Soldier[i], WEAPONSKILL_MP5, 1000);
				FCNPC_SetAmmo(Soldier[i], 9999);
				AI_SetReaction(Soldier[i], AI_MODE_HOSTILE);
				startPatrol(Soldier[i]);
			}

			if(SoldierType[i] > 0) {
				switch(random(2)) { 
					case 0: { FCNPC_SetWeapon(Soldier[i], 30); FCNPC_SetWeaponAccuracy(Soldier[i], 30, 0.8); }
					case 1: { FCNPC_SetWeapon(Soldier[i], 31); FCNPC_SetWeaponAccuracy(Soldier[i], 31, 0.8); }
				}
				SetPVarInt(Soldier[i], "npcgun", FCNPC_GetWeapon(Soldier[i]));				
				FCNPC_SetWeaponSkillLevel(Soldier[i], WEAPONSKILL_AK47, 1000);
				FCNPC_SetWeaponSkillLevel(Soldier[i], WEAPONSKILL_M4, 999);
				FCNPC_SetAmmo(Soldier[i], 9999);
				AI_SetReaction(Soldier[i], AI_MODE_NEUTRAL);
			}
		}
		printf("%d bandits loaded.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadGuardsData, sql);
	return 1;
}

task ZombieGuard[1000]() {
	foreach(new i:GroupMember[npc_a51]) {
		if(SoldierType[GetPVarInt(i, "a51id")] > 0 && FCNPC_GetVirtualWorld(i) == 0) {
			CheckZombiesToKill(i);
		}
	}
}

CheckZombiesToKill(npcid) {
	new Float:spos[3];
	FCNPC_GetPosition(npcid, spos[0], spos[1], spos[2]);
	foreach(new j:GroupMember[npc_Zombie]) {
		if(IsPlayerInRangeOfPoint(j, IN_SHOOTING_SIGHT, spos[0], spos[1], spos[2])) {
			new Float:spos2[3];
			FCNPC_GetPosition(j, spos2[0], spos2[1], spos2[2]);
			if(IsInLOS(spos, spos2) && FCNPC_GetHealth(j) > 0.0) {
				FCNPC_StopAim(npcid);
				FCNPC_Stop(npcid);
				SetPVarInt(npcid, "aim", j);
				FCNPC_AimAtPlayer(npcid, j, true, -1, true);
				return 1;
			}
		}
	}
	SetPVarInt(npcid, "aim", -1);
	FCNPC_StopAim(npcid);
	return 0;
}

/*
forward createSoldiers();
public createSoldiers() {
	new string[12];
	for(new i = 0; i < 40; i++) {
	    format(string, sizeof(string), "A51guard_%i", i);
	    Soldier[i] = FCNPC_Create(string);
		Group_SetPlayer(npc_a51, Soldier[i], true);
		FCNPC_Spawn(Soldier[i], 20001, SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
		FCNPC_SetHealth(Soldier[i], 150.0);
		FCNPC_SetArmour(Soldier[i], 100.0);
		FCNPC_SetInvulnerable(Soldier[i], false);
		switch(random(3)) { 
			case 0: { FCNPC_SetWeapon(Soldier[i], 31); FCNPC_SetWeaponAccuracy(Soldier[i], 31, 0.8); }
			case 1: { FCNPC_SetWeapon(Soldier[i], 29); FCNPC_SetWeaponAccuracy(Soldier[i], 29, 0.8); }
			case 2: { FCNPC_SetWeapon(Soldier[i], 30); FCNPC_SetWeaponAccuracy(Soldier[i], 30, 0.8); }
		}
		FCNPC_SetWeaponSkillLevel(Soldier[i], WEAPONSKILL_AK47, 1000);
		FCNPC_SetWeaponSkillLevel(Soldier[i], WEAPONSKILL_M4, 999);
		FCNPC_SetWeaponSkillLevel(Soldier[i], WEAPONSKILL_MP5, 1000);
		FCNPC_SetAmmo(Soldier[i], 9999);
		FCNPC_SetPosition(Soldier[i], SoldierPositions[i][0], SoldierPositions[i][1], SoldierPositions[i][2]);
		FCNPC_SetAngle(Soldier[i], frandom(360.0));
		AI_SetReaction(Soldier[i], AI_MODE_HOSTILE);
		SetPVarInt(Soldier[i], "a51id", i);
		startPatrol(Soldier[i]);
		SetPlayerColor(Soldier[i], COLOR_PLAYER);
	}
	return 1;
}*/

/*hook FCNPC_OnSpawn(npcid) {
	printf("max players: %d", MAX_PLAYERS);
	if(Group_GetPlayer(npc_a51, npcid)) 
		printf("fcnpc spawn: %d", npcid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}*/

hook OnPlayerDeath(playerid, killerid, reason) {

	foreach(new i:GroupMember[npc_a51]) {
		if(GetPVarInt(i, "aim") == playerid) {
			FCNPC_StopAim(i);
			FCNPC_Stop(i);
			FCNPC_SetKeys(i, 0, 0, 0);
			SetPVarInt(i, "aim", -1);
			if(SoldierType[GetPVarInt(i, "a51id")] == 0)
				startPatrol(i);
		}
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook AI_OnPlayerApproachNPC(playerid, npcid) {
	//printf("AI_OnPlayerApproachNPC(playerid %d, npcid %d)", playerid, npcid);	

	if(AI_GetReaction(npcid) == AI_MODE_NEUTRAL || AI_GetReaction(npcid) == AI_MODE_HOSTILE || IsZombie(playerid)) {
		if(Group_GetPlayer(npc_a51, npcid) && !Group_GetPlayer(g_AdminDuty, playerid) && !IsFriendly(playerid, npcid)) {
			new bool:engageperm = false;
			if(AI_GetReaction(npcid) == AI_MODE_HOSTILE) engageperm = true;
			if(AI_GetReaction(npcid) == AI_MODE_NEUTRAL) {
				if(SoldierType[GetPVarInt(npcid, "a51id")] == 4) {
					if((GetPlayerWeapon(playerid) > 15 && GetPlayerWeapon(playerid) < 41) || GetPlayerWeapon(playerid) == 4 || GetPlayerWeapon(playerid) == 8)
						engageperm = true;
				} 
			}

			new
				Float:pos2[3],
				Float:pos[3];
			GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
			FCNPC_GetPosition(npcid, pos2[0], pos2[1], pos2[2]);
			if(IsInLOS(pos, pos2) && !Bit_Get(dead, playerid) && engageperm) {
				SetPVarInt(npcid, "aim", playerid);
				FCNPC_StopAim(npcid);
				FCNPC_Stop(npcid);
				FCNPC_AimAtPlayer(npcid, playerid, true, -1, true);
				
			}
			/*else
				AI_DistTimer[playerid][npcid] = repeat AI_OnDistancecheck(playerid, npcid);*/
		}
	}
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook FCNPC_OnDeath(npcid, killerid, weaponid) {
	if(Group_GetPlayer(npc_a51, npcid)) {
		defer A51_revive(npcid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

timer A51_revive[A51_REVIVE_TIME](npcid) {
	if(Group_GetPlayer(npc_a51, npcid)) {
		FCNPC_Respawn(npcid);
		FCNPC_SetHealth(npcid, 150.0);
		FCNPC_SetArmour(npcid, 100.0);
		FCNPC_SetInvulnerable(npcid, false);
		new soldierid = GetPVarInt(npcid, "a51id");
		FCNPC_SetPosition(npcid, SoldierPositions[soldierid][0], SoldierPositions[soldierid][1], SoldierPositions[soldierid][2]);
		if(SoldierType[soldierid] == 0)
			startPatrol(npcid);
		switch(random(3)) {
			case 0: FCNPC_SetWeapon(npcid, 31);
			case 1: FCNPC_SetWeapon(npcid, 29);
			case 2: FCNPC_SetWeapon(npcid, 30);
		}
		FCNPC_SetWeaponSkillLevel(npcid, WEAPONSKILL_AK47, 1000);
		FCNPC_SetWeaponSkillLevel(npcid, WEAPONSKILL_M4, 999);
		FCNPC_SetWeaponSkillLevel(npcid, WEAPONSKILL_MP5, 1000);
		FCNPC_SetAmmo(npcid, 9999);
		SetPVarInt(npcid, "lootedby", -1);
		SetPVarInt(npcid, "npcgun", FCNPC_GetWeapon(npcid));
	}
}


hook FCNPC_OnWeaponShot(npcid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) {
	if(Group_GetPlayer(npc_a51, npcid)) {
		if(!random(4)) {
			new
				target,
				Float:pos2[3],
				Float:pos[3];
			target = GetPVarInt(npcid, "aim");
			GetPlayerPos(target, pos[0], pos[1], pos[2]);
			FCNPC_GetPosition(npcid, pos2[0], pos2[1], pos2[2]);

			if(!IsInLOS(pos, pos2)) {
			//if(hittype != BULLET_HIT_TYPE_PLAYER && hittype != BULLET_HIT_TYPE_VEHICLE) {
				//SFM(target, HEX_FADE2, "Debug FCNPC Stopaim %d", npcid);
				FCNPC_AimAtPlayer(npcid, target, false, -1, false);
				FCNPC_StopAim(npcid);
				FCNPC_SetKeys(npcid, 0, 0, 0);
				//AI_DistTimer[target][npcid] = repeat AI_OnDistancecheck(target, npcid);
				if(SoldierType[GetPVarInt(npcid, "a51id")] == 0)
					startPatrol(npcid);
			}
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

/*hook FCNPC_OnWeaponShot(npcid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) {
	
	if(hittype == BULLET_HIT_TYPE_PLAYER) {

		if(IsPlayerNPC(hitid)) return Y_HOOKS_CONTINUE_RETURN_1;

		if(Bit_Get(dead, hitid)) {
			
			FCNPC_StopAim(npcid);
			FCNPC_Stop(npcid);
			FCNPC_SetKeys(npcid, 0, 0, 0);
			SetPVarInt(npcid, "aim", -1);
			if(SoldierType[GetPVarInt(npcid, "a51id")] == 0)
				startPatrol(npcid);

			return Y_HOOKS_BREAK_RETURN_0;
		}

		new Float:health, Float:armor;
		GetPlayerHealth(hitid, health);
		GetPlayerArmour(hitid, armor);

		new bodypart = random(7)+3;


		switch(weaponid) {
			case 2:
				//if(health + armor + 1.0 > REDMG_GOLFCLUB)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_GOLFCLUB);
			case 3:
				//if(health + armor + 1.0 > REDMG_NIGHTSTICK)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_NIGHTSTICK);
			case 4:
				//if(health + armor + 1.0 > REDMG_KNIFE)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_KNIFE);
			case 5:
				//if(health + armor + 1.0 > REDMG_BASEBALLBAT)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_BASEBALLBAT);
			case 7:
				//if(health + armor + 1.0 > REDMG_POOLSTICK)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_POOLSTICK);
			case 8:
				//if(health + armor + 1.0 > REDMG_KATANA)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_KATANA);
			case 22:
				//if(health + armor + 1.0 > REDMG_COLT45)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_COLT45);
			case 23:
				//if(health + armor + 1.0 > REDMG_SILENCED)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_SILENCED);
			case 24:
				//if(health + armor + 1.0 > REDMG_DEAGLE)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_DEAGLE);
			case 25:
				//if(health + armor + 1.0 > REDMG_SHOTGUN)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_SHOTGUN);
			case 26:
				//if(health + armor + 1.0 > REDMG_SAWEDOFF)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_SAWEDOFF);
			case 27:
				//if(health + armor + 1.0 > REDMG_SHOTGSPA)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_SHOTGSPA);
			case 28:
				//if(health + armor + 1.0 > REDMG_UZI)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_UZI);
			case 29:
				//if(health + armor + 1.0 > REDMG_MP5)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_MP5);
			case 30:
				//if(health + armor + 1.0 > REDMG_AK47)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_AK47);
			case 31:
				//if(health + armor + 1.0 > REDMG_M4)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_M4);
			case 32:
				//if(health + armor + 1.0 > REDMG_TEC9)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_TEC9);
			case 33:
				//if(health + armor + 1.0 > REDMG_RIFLE)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_RIFLE);
			case 34:
				//if(health + armor + 1.0 > REDMG_SNIPER)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_SNIPER);
			case 38:
				//if(health + armor + 1.0 > REDMG_MINIGUN)
					DamagePlayer(hitid, npcid, weaponid, bodypart, REDMG_MINIGUN);
		}

	}
	else {

		if(random(5)) {
			FCNPC_StopAim(npcid);
			FCNPC_Stop(npcid);
			FCNPC_SetKeys(npcid, 0, 0, 0);
			SetPVarInt(npcid, "aim", -1);
			if(SoldierType[GetPVarInt(npcid, "a51id")] == 0)
				startPatrol(npcid);
		}

	}

	return Y_HOOKS_BREAK_RETURN_0;
}*/

hook FCNPC_OnWpnStateChange(npcid, weapon_state) {
	if(Group_GetPlayer(npc_a51, npcid) && weapon_state == WEAPONSTATE_RELOADING) {
		//print("FCNPC_OnWpnStateChange weapon_state == WEAPONSTATE_RELOADING");
		new
			target,
			Float:pos2[3],
			Float:pos[3];
		target = GetPVarInt(npcid, "aim");
		if(target == -1) {
			if(SoldierType[GetPVarInt(npcid, "a51id")] == 0)
				startPatrol(npcid);
			return Y_HOOKS_CONTINUE_RETURN_1;
		}			
		GetPlayerPos(target, pos[0], pos[1], pos[2]);
		FCNPC_GetPosition(npcid, pos2[0], pos2[1], pos2[2]);

		if(!IsInLOS(pos, pos2) || Bit_Get(dead, target)) {
			//FCNPC_AimAtPlayer(npcid, target, false, -1, false);
			FCNPC_StopAim(npcid);
			FCNPC_Stop(npcid);
			FCNPC_SetKeys(npcid, 0, 0, 0);
			SetPVarInt(npcid, "aim", -1);
			if(SoldierType[GetPVarInt(npcid, "a51id")] == 0)
				startPatrol(npcid);
			//AI_DistTimer[target][npcid] = repeat AI_OnDistancecheck(target, npcid);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;

}

hook FCNPC_OnGiveDamage(npcid, damagedid, Float:amount, weaponid, bodypart) {

	if(IsPlayerNPC(damagedid)) return Y_HOOKS_CONTINUE_RETURN_1;
	if(Bit_Get(dead, damagedid)) {
		
		FCNPC_StopAim(npcid);
		FCNPC_Stop(npcid);
		FCNPC_SetKeys(npcid, 0, 0, 0);
		SetPVarInt(npcid, "aim", -1);
		if(SoldierType[GetPVarInt(npcid, "a51id")] == 0)
			startPatrol(npcid);

		return Y_HOOKS_BREAK_RETURN_0;
	}

	new Float:health, Float:armor;
	GetPlayerHealth(damagedid, health);
	GetPlayerArmour(damagedid, armor);

	if(((health + armor - amount) <= 5.0) && !Bit_Get(dead, damagedid)) {
		SetPlayerHealth(damagedid, 50.0);
		SetPlayerArmour(damagedid, 0.0);
		AddHit(damagedid, npcid, weaponid, bodypart, amount, false);
		StartFakeDeath(damagedid, npcid);
		return Y_HOOKS_BREAK_RETURN_0;
	}

	else {
		switch(weaponid) {
			case 2:
				//if(health + armor + 1.0 > REDMG_GOLFCLUB)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_GOLFCLUB);
			case 3:
				//if(health + armor + 1.0 > REDMG_NIGHTSTICK)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_NIGHTSTICK);
			case 4:
				//if(health + armor + 1.0 > REDMG_KNIFE)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_KNIFE);
			case 5:
				//if(health + armor + 1.0 > REDMG_BASEBALLBAT)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_BASEBALLBAT);
			case 7:
				//if(health + armor + 1.0 > REDMG_POOLSTICK)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_POOLSTICK);
			case 8:
				//if(health + armor + 1.0 > REDMG_KATANA)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_KATANA);
			case 22:
				//if(health + armor + 1.0 > REDMG_COLT45)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_COLT45);
			case 23:
				//if(health + armor + 1.0 > REDMG_SILENCED)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_SILENCED);
			case 24:
				//if(health + armor + 1.0 > REDMG_DEAGLE)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_DEAGLE);
			case 25:
				//if(health + armor + 1.0 > REDMG_SHOTGUN)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_SHOTGUN);
			case 26:
				//if(health + armor + 1.0 > REDMG_SAWEDOFF)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_SAWEDOFF);
			case 27:
				//if(health + armor + 1.0 > REDMG_SHOTGSPA)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_SHOTGSPA);
			case 28:
				//if(health + armor + 1.0 > REDMG_UZI)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_UZI);
			case 29:
				//if(health + armor + 1.0 > REDMG_MP5)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_MP5);
			case 30:
				//if(health + armor + 1.0 > REDMG_AK47)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_AK47);
			case 31:
				//if(health + armor + 1.0 > REDMG_M4)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_M4);
			case 32:
				//if(health + armor + 1.0 > REDMG_TEC9)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_TEC9);
			case 33:
				//if(health + armor + 1.0 > REDMG_RIFLE)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_RIFLE);
			case 34:
				//if(health + armor + 1.0 > REDMG_SNIPER)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_SNIPER);
			case 38:
				//if(health + armor + 1.0 > REDMG_MINIGUN)
					DamagePlayer(damagedid, npcid, weaponid, bodypart, REDMG_MINIGUN);
		}
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}

startPatrol(npcid) {
	if(Group_GetPlayer(npc_a51, npcid)) {
		FCNPC_StopAim(npcid);
		FCNPC_SetKeys(npcid, 0, 0, 0);
		new soldierid = GetPVarInt(npcid, "a51id");
		new Float:pos[3];
		FCNPC_GetPosition(npcid, pos[0],pos[1], pos[2]);

		if(pos[2] < 20.0 && pos[2] > 16.0) {

			new attempt = -1;
			new Float:add[3];
			for(;++attempt<30;) {
				add[0] = frandom(15.0)+3.1;
				if(random(1))
					add[0] += pos[0];
				else
					add[0] = pos[0]-add[0];

				add[1] = frandom(15.0)+3.1;
				if(random(1))
					add[1] += pos[1];
				else
					add[1] = pos[1]-add[1];

				CA_FindZ_For2DCoord(add[0], add[1], add[2]);
				add[2] += 0.6;

				if(IsInLOS(pos, add, false)) {
					SoldierPatrol[soldierid][0] = add[0];
					SoldierPatrol[soldierid][1] = add[1];
					SoldierPatrol[soldierid][2] = add[2];
					FCNPC_GoTo(npcid, SoldierPatrol[soldierid][0], SoldierPatrol[soldierid][1], SoldierPatrol[soldierid][2], FCNPC_MOVE_TYPE_WALK, FCNPC_MOVE_SPEED_WALK, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 250);
					return 1;
				}
			}
		}
	}
	return 0;
}

hook FCNPC_OnReachDest(npcid) {
	if(Group_GetPlayer(npc_a51, npcid)) {
		FCNPC_StopAim(npcid);
		FCNPC_SetKeys(npcid, 0, 0, 0);
		defer a51patrolturn[random(20000)+3000](npcid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

timer a51patrolturn[10000](npcid) {
	new soldierid = GetPVarInt(npcid, "a51id");
	if(IsPlayerInRangeOfPoint(npcid, 3.0, SoldierPositions[soldierid][0], SoldierPositions[soldierid][1], SoldierPositions[soldierid][2])) {
		FCNPC_GoTo(npcid, SoldierPatrol[soldierid][0], SoldierPatrol[soldierid][1], SoldierPatrol[soldierid][2], FCNPC_MOVE_TYPE_WALK, FCNPC_MOVE_SPEED_WALK, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 250);
		//printf("a51patrolturn SoldierPatrol %d npcid %d soldierid: %f %f %f", npcid, soldierid, SoldierPatrol[soldierid][0], SoldierPatrol[soldierid][1], SoldierPatrol[soldierid][2]);
	}
	else {
		FCNPC_GoTo(npcid, SoldierPositions[soldierid][0], SoldierPositions[soldierid][1], SoldierPositions[soldierid][2], FCNPC_MOVE_TYPE_WALK, FCNPC_MOVE_SPEED_WALK, FCNPC_MOVE_MODE_COLANDREAS, FCNPC_MOVE_PATHFINDING_RAYCAST, 0.0, true, 0.0, 250);
		//printf("a51patrolturn SoldierPositions %d npcid %d soldierid: %f %f %f", npcid, soldierid, SoldierPositions[soldierid][0], SoldierPositions[soldierid][1], SoldierPositions[soldierid][2]);
	}
}

IsFriendly(playerid, npcid) {
	if(!IsPlayerConnected(playerid) || !IsPlayerNPC(npcid)) return false;
	if(IsZombie(playerid) && !IsZombie(npcid)) return false;

	//if(faction[playerid] == 3 && Group_GetPlayer(npc_a51, npcid)) return true;//a51 npc friendly to faction 3 (Unused Research Group)
	if(faction[playerid] == 5 && SoldierType[GetPVarInt(npcid, "a51id")] == 1 && !IsZombie(playerid)) return true;//type 1 (scarville guard) friendly to faction 5 National Guard
	if(faction[playerid] == 1 && SoldierType[GetPVarInt(npcid, "a51id")] == 2 && !IsZombie(playerid)) return true;//type 2 (fallen tree guards and terminal guards) friendly to faction 2 Enclave
	if(faction[playerid] == 4 && SoldierType[GetPVarInt(npcid, "a51id")] == 3 && !IsZombie(playerid)) return true;//type 3 bandit guards with faction 4 The Osomething
	if(faction[playerid] == 3 && SoldierType[GetPVarInt(npcid, "a51id")] == 4 && !IsZombie(playerid)) return true;//type 4 elysium guards with faction 3 elysium labs stuff

	return false;
}

AI_Helpcheck(npcid, issuerid) {

	if(SoldierType[GetPVarInt(npcid, "a51id")] > 0) {	

		foreach(new i:GroupMember[npc_a51]) {
			if(SoldierType[GetPVarInt(i, "a51id")] == SoldierType[GetPVarInt(npcid, "a51id")]) {

				new Float:spos[3];
				FCNPC_GetPosition(i, spos[0], spos[1], spos[2]);

				if(IsPlayerInRangeOfPoint(issuerid, IN_SHOOTING_SIGHT, spos[0], spos[1], spos[2])) {
					new Float:spos2[3];
					GetPlayerPos(issuerid, spos2[0], spos2[1], spos2[2]);

					if(IsInLOS(spos, spos2)) {
						FCNPC_StopAim(i);
						FCNPC_Stop(i);
						SetPVarInt(i, "aim", issuerid);
						FCNPC_AimAtPlayer(i, issuerid, true, -1, true);
					}
				}
			}
		}
	}
	return 1;
}