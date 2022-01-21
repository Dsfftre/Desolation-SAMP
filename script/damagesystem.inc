/*#if defined _inc_damagesystem
	#undef _inc_damagesystem
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

#define MAX_DAMAGES 32

enum DamageInfoEnum {
	issuer[MAX_DAMAGES],
	weapon[MAX_DAMAGES],
	brand[MAX_DAMAGES],
	hitbodypart[MAX_DAMAGES],
	Float:dmg[MAX_DAMAGES],
	time[MAX_DAMAGES]
}
new DamageInfo[MAX_PLAYERS][DamageInfoEnum];
/*
#define DAMAGE_COLT45 25 * 0.33 //8.25
#define DAMAGE_SILENCED 40 * 0.33 //13.200012
#define DAMAGE_DEAGLE 140 * 0.33 //46.200013
#define DAMAGE_SHOTGUN 10 * 0.33 //30.0 (probably because of pellets)
#define DAMAGE_SAWEDOFF 10 * 0.33 //30.0 (probably because of pellets)
#define DAMAGE_SHOTGSPA 15 * 0.33 //30.0 (probably because of pellets)
#define DAMAGE_UZI 20 * 0.33 //6.599976
#define DAMAGE_TEC9 20 * 0.33//6.599976
#define DAMAGE_MP5 25 * 0.33 //8.25
#define DAMAGE_AK47 30 * 0.33 //9.900024
#define DAMAGE_M4 30 * 0.33 //9.900024
#define DAMAGE_RIFLE 75 * 0.33 //24.799987
#define DAMAGE_SNIPER 125 * 0.33 //41.299987
#define DAMAGE_MINIGUN 140 * 0.33 //46.200013
*/
#define REDMG_COLT45 25.0
#define REDMG_SILENCED 25.0
#define REDMG_DEAGLE 40.0
#define REDMG_SHOTGUN 40.0
#define REDMG_SAWEDOFF 30.0
#define REDMG_SHOTGSPA 30.0
#define REDMG_UZI 25.0
#define REDMG_TEC9 25.0
#define REDMG_MP5 25.0
#define REDMG_AK47 30.0
#define REDMG_M4 30.0
#define REDMG_RIFLE 60.0
#define REDMG_SNIPER 150.0
#define REDMG_MINIGUN 15.0

#define REDMG_GOLFCLUB 10.0
#define REDMG_NIGHTSTICK 15.0
#define REDMG_KNIFE 20.0
#define REDMG_BASEBALLBAT 15.0
#define REDMG_SHOVEL 15.0
#define REDMG_POOLSTICK 10.0
#define REDMG_KATANA 40.0

#define REDMG_HULKSDMG 20.0


hook OnPlayerSpawn(playerid) {
	SetPlayerTeam(playerid, 4);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook FCNPC_OnSpawn(npcid) {
	SetPlayerTeam(npcid, 4);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart) {

	//SFM(playerid, HEX_FADE2, " >>> DMG >>> OnPlayerTakeDamage(playerid %d, issuerid %d, amount %f, weaponid %d, bodypart %d", playerid, issuerid, amount, weaponid, bodypart);

	if(!IsPlayerNPC(playerid) && !IsPlayerNPC(issuerid) && !Group_GetPlayer(g_AdminDuty, playerid) && weaponid != 0 && issuerid != INVALID_PLAYER_ID && !Bit_Get(dead, playerid)) {
		new Float:health, Float:armor;
		GetPlayerHealth(playerid, health);
		GetPlayerArmour(playerid, armor);

		if(((health + armor - amount) <= 5.0) && !Bit_Get(dead, playerid)) {
			SetPlayerHealth(playerid, 50.0);
			SetPlayerArmour(playerid, 0.0);
			AddHit(playerid, issuerid, weaponid, bodypart, amount, false);
			StartFakeDeath(playerid, issuerid);
			return Y_HOOKS_BREAK_RETURN_0;	
		}

		//printf("OnPlayerTakeDamage(playerid %d, issuerid %d, amount %f, weaponid %d, bodypart %d", playerid, issuerid, amount, weaponid, bodypart);

		if(IsZombie(issuerid) && (IsHulks(issuerid) || IsTyrant(issuerid) )&& weaponid == 0) {
			DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_HULKSDMG);
		}
		else if(IsZombie(issuerid) && weaponid == 0) {
			DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_HULKSDMG/2.0);
		}
		else if(health + armor > amount) {
			switch(weaponid) {
				case 2:
					//if(health + armor + 1.0 > REDMG_GOLFCLUB)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_GOLFCLUB);
				case 3:
					//if(health + armor + 1.0 > REDMG_NIGHTSTICK)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_NIGHTSTICK);
				case 4:
					//if(health + armor + 1.0 > REDMG_KNIFE)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_KNIFE);
				case 5:
					//if(health + armor + 1.0 > REDMG_BASEBALLBAT)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_BASEBALLBAT);
				case 7:
					//if(health + armor + 1.0 > REDMG_POOLSTICK)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_POOLSTICK);
				case 8:
					//if(health + armor + 1.0 > REDMG_KATANA)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_KATANA);
				case 22:
					//if(health + armor + 1.0 > REDMG_COLT45)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_COLT45);
				case 23:
					//if(health + armor + 1.0 > REDMG_SILENCED)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_SILENCED);
				case 24:
					//if(health + armor + 1.0 > REDMG_DEAGLE)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_DEAGLE);
				case 25:
					//if(health + armor + 1.0 > REDMG_SHOTGUN)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_SHOTGUN);
				case 26:
					//if(health + armor + 1.0 > REDMG_SAWEDOFF)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_SAWEDOFF);
				case 27:
					//if(health + armor + 1.0 > REDMG_SHOTGSPA)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_SHOTGSPA);
				case 28:
					//if(health + armor + 1.0 > REDMG_UZI)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_UZI);
				case 29:
					//if(health + armor + 1.0 > REDMG_MP5)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_MP5);
				case 30:
					//if(health + armor + 1.0 > REDMG_AK47)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_AK47);
				case 31:
					//if(health + armor + 1.0 > REDMG_M4)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_M4);
				case 32:
					//if(health + armor + 1.0 > REDMG_TEC9)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_TEC9);
				case 33:
					//if(health + armor + 1.0 > REDMG_RIFLE)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_RIFLE);
				case 34:
					//if(health + armor + 1.0 > REDMG_SNIPER)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_SNIPER);
				case 38:
					//if(health + armor + 1.0 > REDMG_MINIGUN)
						DamagePlayer(playerid, issuerid, weaponid, bodypart, REDMG_MINIGUN);
				default:
					AddHit(playerid, issuerid, weaponid, bodypart, amount, false);
			}
		}
		else
			AddHit(playerid, issuerid, weaponid, bodypart, amount, false);

	}
	return Y_HOOKS_BREAK_RETURN_0;
}

DamagePlayer(playerid, issuerid, weaponid, bodypart, Float:damage) {
	//printf("DamagePlayer(playerid %d, issuerid %d, weaponid %d, bodypart %d, damage %f", playerid, issuerid, weaponid, bodypart, damage);
	if(damage == 0.0) return 0;
	new Float:health, Float:armor, Float:amount;
	GetPlayerHealth(playerid, health);
	GetPlayerArmour(playerid, armor);

	if((health + armor - damage <= 5.0) && !Bit_Get(dead, playerid)) {
		SetPlayerHealth(playerid, 50.0);
		SetPlayerArmour(playerid, 0.0);
		AddHit(playerid, issuerid, weaponid, bodypart, damage, false);
		StartFakeDeath(playerid, issuerid);
		if(IsPlayerConnected(issuerid) && !IsPlayerNPC(issuerid) && !IsPlayerNPC(playerid) && IsHuman(playerid) && IsHuman(issuerid)) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `kills` = `kills`+1 WHERE id = %d LIMIT 1",  CharacterSQL[issuerid]);
			mysql_tquery(g_SQL, sql, "", "");
			SetPVarInt(playerid, "killedby", issuerid);
			SetPVarInt(playerid, "weaponby", weaponid);
		}
	}
	else if(!Bit_Get(dead, playerid)) {

		if(armor > 0.0) {
			amount = armor - damage;
			if(amount <= 0.0) {
				SetPlayerHealth(playerid,health-damage+armor);
				SetPlayerArmour(playerid, 0);
				AddHit(playerid, issuerid, weaponid, bodypart, damage, true);
			}
			else {
				SetPlayerArmour(playerid,armor-damage);
				AddHit(playerid, issuerid, weaponid, bodypart, damage, true);
			}
		}
		else {
			SetPlayerHealth(playerid, health - damage);
			AddHit(playerid, issuerid, weaponid, bodypart, damage, false);
		}
		GetPlayerHealth(playerid, health);
		GetPlayerArmour(playerid, armor);

	}

	return 1;
}

AddHit(playerid, issuerid, weaponid, bodypart, Float:damage, bool:kevlarhit) {
	if(IsPlayerNPC(issuerid)) return 0;
	new i = -1;
	for(;++i<MAX_DAMAGES;) {
		if(DamageInfo[playerid][hitbodypart][i] != 0) continue;
		DamageInfo[playerid][hitbodypart][i] = bodypart;
		DamageInfo[playerid][issuer][i] = CharacterSQL[issuerid];
		DamageInfo[playerid][weapon][i] = weaponid;
		DamageInfo[playerid][dmg][i] = damage;
		DamageInfo[playerid][brand][i] = kevlarhit;
		DamageInfo[playerid][time][i] = gettime();
		break;
	}
	if(i == MAX_DAMAGES/2) {
		for(;++i<MAX_DAMAGES;) {
			DamageInfo[playerid][hitbodypart][i] = 0;
			DamageInfo[playerid][issuer][i] = 0;
			DamageInfo[playerid][weapon][i] = 0;
			DamageInfo[playerid][dmg][i] = 0.0;
			DamageInfo[playerid][brand][i] = 0;
			break;
		}
	}
	else if(i == MAX_DAMAGES-1) {//devnote this could be optimized better
		i = -1;
		for(;++i<MAX_DAMAGES/2;) {
			DamageInfo[playerid][hitbodypart][i] = 0;
			DamageInfo[playerid][issuer][i] = 0;
			DamageInfo[playerid][weapon][i] = 0;
			DamageInfo[playerid][dmg][i] = 0.0;
			DamageInfo[playerid][brand][i] = 0;
			break;
		}
	}
	return 1;
}

ShowPlayerDamages(playerid, toid) {
	new str[2048], str1[128], count = 0;
	new i = -1;
	for(;++i<MAX_DAMAGES;) {
		if(DamageInfo[playerid][hitbodypart][i] != 0) ++count;
	}
	if(count == 0) {
		format(str1, sizeof(str1),"%s's damages",PlayerName(playerid));
		inline Empty(pid, dialogid, response, listitem, string:inputtext[]) {
			#pragma unused pid, dialogid, response, listitem, inputtext
		}
		Dialog_ShowCallback(toid, using inline Empty, DIALOG_STYLE_MSGBOX, str1, "No wounds.", "Close");
		return 1;
	}
	if(Group_GetPlayer(g_AdminDuty, toid)) {
		str = "Issuer\tDamage\tWeapon\tTime\n";
		i = -1;
		for(;++i<MAX_DAMAGES;) {
			if(DamageInfo[playerid][hitbodypart][i] != 0) {
				if(DamageInfo[playerid][brand][i])
					format(str1,sizeof(str1),"%s\t%.1fK\t%s\t%i mp\n",
					GetSQLCharname(DamageInfo[playerid][issuer][i]),
					DamageInfo[playerid][dmg][i],
					DeathReason(DamageInfo[playerid][weapon][i]),
					gettime() - DamageInfo[playerid][time][i]);
				else
					format(str1,sizeof(str1),"%s\t%.1f\t%s\t%i mp\n",
					GetSQLCharname(DamageInfo[playerid][issuer][i]),
					DamageInfo[playerid][dmg][i],
					DeathReason(DamageInfo[playerid][weapon][i]),
					gettime() - DamageInfo[playerid][time][i]);
					
				strcat(str, str1);
			}
		}
	}
	else {
		str = "Damage\tWeapon\tBodypart\tTime\n";
		i = -1;
		for(;++i<MAX_DAMAGES;) {
			if(DamageInfo[playerid][hitbodypart][i] != 0) {
				if(DamageInfo[playerid][brand][i])
					format(str1,sizeof(str1),"%.1f\t%s\t%s (K)\t%i mp\n",
					DamageInfo[playerid][dmg][i],
					DeathReason(DamageInfo[playerid][weapon][i]),
					GetBodypartName(DamageInfo[playerid][hitbodypart][i]),
					gettime() - DamageInfo[playerid][time][i]);
				else
					format(str1,sizeof(str1),"%.1f\t%s\t%s\t%i mp\n",
					DamageInfo[playerid][dmg][i],
					DeathReason(DamageInfo[playerid][weapon][i]),
					GetBodypartName(DamageInfo[playerid][hitbodypart][i]),
					gettime() - DamageInfo[playerid][time][i]);
					
				strcat(str, str1);
			}
		}
	}
	format(str1, sizeof(str1),"%s's damages",PlayerName(playerid));
	inline Empty(pid, dialogid, response, listitem, string:inputtext[]) {
		#pragma unused pid, dialogid, response, listitem, inputtext
	}
	Dialog_ShowCallback(toid, using inline Empty, DIALOG_STYLE_TABLIST, str1, str, "Close");
	return 1;
}

GetBodypartName(bodypart) {
	new string[32] = "Unknown";
	switch(bodypart) {
		case 3: string = "Torso";
		case 4: string = "Crotch";
		case 5: string = "Left arm";
		case 6: string = "Right arm";
		case 7: string = "Left leg";
		case 8: string = "Right leg";
		case 9: string = "Head";
	}
	return string;
}

YCMD:damages(playerid, params[], help) {
	new target=INVALID_PLAYER_ID;
	if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /damages [id]");
	if(target == INVALID_PLAYER_ID) {
		unformat(params, "i", target);
		if(!IsPlayerConnected(target) || IsPlayerNPC(target))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	new Float:tpos[3];
	GetPlayerPos(target, tpos[0], tpos[1], tpos[2]);
	if(Group_GetPlayer(g_AdminDuty, playerid) || playerid == target)
		ShowPlayerDamages(target, playerid);
	else if(!Bit_Get(spectating, target) && Bit_Get(dead, target) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(target) && GetPlayerInterior(playerid) == GetPlayerInterior(target) && IsPlayerInRangeOfPoint(playerid, 20.0, tpos[0], tpos[1], tpos[2]))
    	ShowPlayerDamages(target, playerid);
	else
		SCM(playerid, HEX_RED, "Error: You need to be closer!");
	return 1;
}

public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) {
	return 0;
}