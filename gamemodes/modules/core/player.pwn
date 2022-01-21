/*#if defined _inc_player
	#undef _inc_player
#endif*/

#include "..\..\gamemodes\modules\player\shops\stores.pwn"
//#include "..\..\gamemodes\modules\player\searches\search.pwn"
//#include "..\..\gamemodes\modules\player\mining\mine.pwn"
#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>
/*#include <YSI_Coding\y_timers>
#include <YSI_Coding\y_inline>
#include <YSI_Data\y_foreach>
#include <YSI_Data\y_bit>
#include <YSI_Players\y_groups>
#include <YSI_Visual\y_commands>
#include <YSI_Visual\y_dialog>*/

hook FCNPC_OnDeath(npcid, killerid, weaponid) {
	if(killerid == INVALID_PLAYER_ID || IsPlayerNPC(killerid) || !IsZombie(npcid)) return Y_HOOKS_CONTINUE_RETURN_1;
	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `zkills` = `zkills`+1 WHERE id = %d LIMIT 1",  CharacterSQL[killerid]);
	mysql_tquery(g_SQL, sql, "", "");
	//printf("%s", sql);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDeath(playerid, killerid, reason) {

	//printf("DEBUG: OnPlayerDeath %d %d", playerid, killerid);

	if(IsPlayerNPC(killerid)) {
		if(Group_GetPlayer(npc_Zombie, killerid) && GetPVarInt(killerid, "zsqlid") > 0) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `npc_zombies` SET `score` = `score`+1 WHERE id = %d LIMIT 1",  GetPVarInt(killerid, "zsqlid"));
			mysql_tquery(g_SQL, sql, "", "");
			SetPlayerScore(killerid, GetPlayerScore(killerid)+1);
		}
		else if(Group_GetPlayer(npc_a51, killerid) && GetPVarInt(killerid, "gsqlid") > 0) {
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `npc_guards` SET `score` = `score`+1 WHERE id = %d LIMIT 1",  GetPVarInt(killerid, "gsqlid"));
			mysql_tquery(g_SQL, sql, "", "");
			SetPlayerScore(killerid, GetPlayerScore(killerid)+1);
		}

	}
	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;

	HandlePlayerDeath(playerid, killerid, false);

	return Y_HOOKS_CONTINUE_RETURN_1;
}

StartFakeSpawn(playerid) {
	//printf("DEBUG: StartFakeSpawn %d", playerid);
	if(DEBUGMSG && adminlevel[playerid] != 0) SFM(playerid, HEX_FADE2, "Debug: Player StartFakeSpawn called. Your death (0 false anything else true) %d.", Bit_Get(dead, playerid));

	if(IsPlayerNPC(playerid)) {
		if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You spawned as an NPC. The script thinks you're an NPC. :S");
		return 1;
	}

	HidePlayerMarkers(playerid);
	RefreshBars(playerid);
	//ResetPlayerNPCbars(playerid);
	MilitaryWeaponSkills(playerid);
	ChangeMaskVW(playerid);

	SetPVarInt(playerid, "killedby", -1);
	//ResetPlayerMoney(playerid);
	//GivePlayerMoney(playerid, cash[playerid]);
	/*if(p_skin[playerid] <= 0 || p_skin[playerid] >= 30000) {
		if(DEBUGMSG && adminlevel[playerid] != 0) SFM(playerid, HEX_FADE2, "Debug: ON StartFakeSpawn Your pskin: %d, and your skin id: %d", p_skin[playerid], GetPlayerSkin(playerid));
		p_skin[playerid] = 177;
	}
	SetPlayerSkin(playerid, p_skin[playerid]);*/

	if(Bit_Get(deathspawn, playerid)) {

		if(Bit_Get(dead, playerid) && GetPVarInt(playerid, "deathtime") > 0) 
		{
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: FakeSpawning with controllable status.");
			//SetPlayerSkin(playerid, p_skin[playerid]);
			Bit_Vet(dead, playerid);
			Bit_Vet(frozen, playerid);
			DeletePVar(playerid, "deathtime");
			Delete3DTextLabel(DamageLabel[playerid]);
			TogglePlayerControllable(playerid, true);
		}

		if(Bit_Get(dead, playerid)) 
		{
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: FakeSpawning with uncontrollable status.");
			//SetPlayerSkin(playerid, p_skin[playerid]);
			new Float:pos[4];
			GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
			//GetPlayerFacingAngle(playerid, pos[3]);
			//SetPlayerInterior(playerid, GetPVarInt(playerid, "deadinterior"));
			//SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "deadvw"));
			//SetPlayerPos(playerid, GetPVarFloat(playerid, "deadx"), GetPVarFloat(playerid, "deady"), GetPVarFloat(playerid, "deadz"));
			//SetPlayerFacingAngle(playerid, GetPVarInt(playerid, "deadf"));
			//SetCameraBehindPlayer(playerid);
			new string[256];
			format(string, sizeof(string), "(( %s is brutally wounded.\n/damages and /loot %d for more information. ))",PlayerName(playerid), playerid);
			DamageLabel[playerid] = Create3DTextLabel(string, COLOR_PINK, pos[0], pos[1], pos[2], NAMETAG_DISTANCE*2, GetPlayerVirtualWorld(playerid), 1);
			Attach3DTextLabelToPlayer(DamageLabel[playerid], playerid, 0.0, 0.0, 0.6);
			ApplyDeathAnimation(playerid);
			SCM(playerid, HEX_FADE2, "You have been brutally wounded, but you can still be saved by medics.");
			SCM(playerid, HEX_FADE2, "To respawn use /respawnme in a minute, if noone's roleplaying with you.");

			//RandomHumanSpawn(playerid);
			
			SetPlayerHealth(playerid, 50.0);
			SetPVarInt(playerid, "deathtime", 1);
			defer BrutallyWounded(playerid);
			//TogglePlayerControllable(playerid, false);
		}

		if(IsZombie(playerid)) {
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: FakeSpawning as a zombie.");
			if(GetPVarInt(playerid, "deadvw") > 0) {
				SetPlayerInterior(playerid, GetPVarInt(playerid, "deadinterior"));
				SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "deadvw"));
				DeletePVar(playerid, "deadvw");
				DeletePVar(playerid, "deadinterior");
			}
			SetPlayerSkin(playerid, RandomZombieSkin());
		}

		Bit_Vet(deathspawn, playerid);

	}

	SetPlayerWeather(playerid, ServerTime[weather]);
	SetPlayerTime(playerid, ServerTime[hour], 30);

	return 1;
}


StartFakeDeath(playerid, killerid) {

	if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: StartFakeDeath() started!");
	//printf("DEBUG: HandlePlayerDeath %d %d", playerid, killerid);
	if(DEBUGMSG && adminlevel[playerid] != 0) SFM(playerid, HEX_FADE2, "Debug: ON StartFakeDeath Your pskin: %d, and your skin id: %d", p_skin[playerid], GetPlayerSkin(playerid));
	Bit_Let(deathspawn, playerid);

	//p_skin[playerid] = GetPlayerSkin(playerid);

	ShowPlayerDialog(playerid, -1, DIALOG_STYLE_MSGBOX, "", "", "", "");
	CloseInventory(playerid);

	SetPlayerHealth(playerid, 99999999.0);
	defer FixHealth[2000](playerid);
	

	if(GetPVarInt(playerid, "killedby") == -1 && !IsPlayerNPC(killerid) && killerid != INVALID_PLAYER_ID) {
		if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died and your killer is getting the kill counted now.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `kills` = `kills`+1 WHERE id = %d LIMIT 1",  CharacterSQL[killerid]);
		mysql_tquery(g_SQL, sql, "", "");
		//printf("%s", sql);
	}
	

	if(Bit_Get(dead, playerid) && GetPVarInt(playerid, "deathtime") > 0) {
		if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died when you were already dead. Final death.");
		RandomHumanSpawn(playerid);
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `deaths` = `deaths`+1 WHERE id = %d LIMIT 1",  CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
		//printf("%s", sql);
	}

	if(!Bit_Get(dead, playerid)) 
	{
		if(Bit_Get(tutorial, playerid) && Bit_Get(ContestedArea, playerid) && IsHuman(playerid))
			SCM(playerid, HEX_FADE2, "Hint: You died in a contested area. You are free to kill in constested areas without reason.");

		new Float:newz_pos[4];
		GetPlayerPos(playerid, newz_pos[0], newz_pos[1], newz_pos[2]);
		GetPlayerFacingAngle(playerid, newz_pos[3]);
		SetPVarInt(playerid, "deadinterior", GetPlayerInterior(playerid));
		SetPVarInt(playerid, "deadvw", GetPlayerVirtualWorld(playerid));
		SetPVarFloat(playerid, "deadx", newz_pos[0]);
		SetPVarFloat(playerid, "deady", newz_pos[1]);
		SetPVarFloat(playerid, "deadz", newz_pos[2]);
		SetPVarFloat(playerid, "deadf", newz_pos[3]);
		
		if(IsHuman(playerid)) 
		{
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died as a human. You should respawn where you died.");
			Bit_Let(dead, playerid);
			StartFakeSpawn(playerid);
		}
		else {
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died as a zombie. You should respawn randomly.");
			TogglePlayerSpectating(playerid, true);
			RandomZombieSpawn(playerid);
			defer Specoffdelay(playerid);
			Bit_Vet(infected, playerid);
		}
	}

	return 1;


}

timer FixHealth[2000](playerid) {

	SetPlayerHealth(playerid, 50.0);

}

HandlePlayerDeath(playerid, killerid, freshspawn = false) {
	if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: HandlePlayerDeath() started!");
	//printf("DEBUG: HandlePlayerDeath %d %d", playerid, killerid);
	if(DEBUGMSG && adminlevel[playerid] != 0) SFM(playerid, HEX_FADE2, "Debug: ON DEATH Your pskin: %d, and your skin id: %d", p_skin[playerid], GetPlayerSkin(playerid));
	Bit_Let(deathspawn, playerid);

	//p_skin[playerid] = GetPlayerSkin(playerid);

	ShowPlayerDialog(playerid, -1, DIALOG_STYLE_MSGBOX, "", "", "", "");
	CloseInventory(playerid);
	
	if(!freshspawn) {
		if(GetPVarInt(playerid, "killedby") == -1 && !IsPlayerNPC(killerid) && killerid != INVALID_PLAYER_ID) 
		{
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died and your killer is getting the kill counted now.");
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `kills` = `kills`+1 WHERE id = %d LIMIT 1",  CharacterSQL[killerid]);
			mysql_tquery(g_SQL, sql, "", "");
			//printf("%s", sql);
		}
	}

	if(Bit_Get(dead, playerid) && GetPVarInt(playerid, "deathtime") > 0) 
	{
		if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died when you were already dead. Final death.");
		RandomHumanSpawn(playerid);
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `deaths` = `deaths`+1 WHERE id = %d LIMIT 1",  CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");
		//printf("%s", sql);
	}

	if(!Bit_Get(dead, playerid)) 
	{
		if(Bit_Get(tutorial, playerid) && Bit_Get(ContestedArea, playerid) && IsHuman(playerid))
			SCM(playerid, HEX_FADE2, "Hint: You died in a contested area. You are free to kill in constested areas without reason.");

		new Float:newz_pos[4];
		GetPlayerPos(playerid, newz_pos[0], newz_pos[1], newz_pos[2]);
		GetPlayerFacingAngle(playerid, newz_pos[3]);
		SetPVarInt(playerid, "deadinterior", GetPlayerInterior(playerid));
		SetPVarInt(playerid, "deadvw", GetPlayerVirtualWorld(playerid));
		SetPVarFloat(playerid, "deadx", newz_pos[0]);
		SetPVarFloat(playerid, "deady", newz_pos[1]);
		SetPVarFloat(playerid, "deadz", newz_pos[2]);
		SetPVarFloat(playerid, "deadf", newz_pos[3]);
		
		if(IsHuman(playerid)) 
		{
			/*if(Bit_Get(infected, playerid) ) 
			{
				if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died as an infected. You should respawn where you died.");
				Bit_Let(pzombie, playerid);
				Group_SetPlayer(g_Zombie, playerid, true);
				SetPlayerColor(playerid, COLOR_ZOMBIE);
				if(Group_GetPlayer(g_AdminDuty, playerid))
					SetPlayerColor(playerid, COLOR_ADMIN);
				SCM(playerid, HEX_YELLOW, "You turned into a zombie!");
				new rskin = RandomZombieSkin();
				//printf("%d random z skin", rskin);
				TogglePlayerSpectating(playerid, true);
				SetSpawnInfo(playerid, ZOMBIE_TEAM, rskin, newz_pos[0], newz_pos[1], newz_pos[2], newz_pos[3], 0, 0, 0, 0, 0, 0);
				defer Specoffdelay(playerid);
				Bit_Vet(infected, playerid);
				SCM(playerid, HEX_FADE2, "You are a zombie now! Attack humans (with right click + alt) to infect them. You can become a human again (/human) once you infected three players.");
				if(Bit_Get(tutorial, playerid))	{		
					SCM(playerid, HEX_FADE2, "Hint: You are considered player-killed. If you become a human again you will not remember any of this, it's only for fun.");
					SCM(playerid, HEX_FADE2, "Hint: Use /mutation to change your zombie class.");
				}
			}
			else {
				if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died as a human. You should respawn where you died.");
				Bit_Let(dead, playerid);
				TogglePlayerSpectating(playerid, true);
				SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], newz_pos[0], newz_pos[1], newz_pos[2], newz_pos[3], 0, 0, 0, 0, 0, 0);
				defer Specoffdelay(playerid);
			}*/
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died as a human. You should respawn where you died.");
			Bit_Let(dead, playerid);
			TogglePlayerSpectating(playerid, true);
			
			//if(p_skin[playerid] <= 0) p_skin[playerid] = 177;
			//SetSpawnInfo(playerid, NO_TEAM, p_skin[playerid], newz_pos[0], newz_pos[1], newz_pos[2], newz_pos[3], 0, 0, 0, 0, 0, 0);
			defer Specoffdelay(playerid);
		}
		else {
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You died as a zombie. You should respawn randomly.");
			TogglePlayerSpectating(playerid, true);
			RandomZombieSpawn(playerid);
			defer Specoffdelay(playerid);
			Bit_Vet(infected, playerid);
		}
	}

	return 1;
}

timer Specoffdelay[2000](playerid)
{
    TogglePlayerSpectating(playerid, false);
}


hook OnPlayerSpawn(playerid) {
	//printf("DEBUG: onplayerspawn %d", playerid);
	if(DEBUGMSG && adminlevel[playerid] != 0) SFM(playerid, HEX_FADE2, "Debug: Player onplayerspawn called. Your death (0 false anything else true) %d.", Bit_Get(dead, playerid));

	if(IsPlayerNPC(playerid)) {
		if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: You spawned as an NPC. The script thinks you're an NPC. :S");
		return Y_HOOKS_CONTINUE_RETURN_1;
	}

	SetPVarInt(playerid, "spect", -1);

	HidePlayerMarkers(playerid);
	RefreshBars(playerid);
	
	MilitaryWeaponSkills(playerid);
	ChangeMaskVW(playerid);

	SetPVarInt(playerid, "killedby", -1);
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, cash[playerid]);
	if(p_skin[playerid] <= 0 || p_skin[playerid] >= 30000) {
		if(DEBUGMSG && adminlevel[playerid] != 0) SFM(playerid, HEX_FADE2, "Debug: ON SPAWN Your pskin: %d, and your skin id: %d", p_skin[playerid], GetPlayerSkin(playerid));
		p_skin[playerid] = 177;
	}
	SetPlayerSkin(playerid, p_skin[playerid]);

	if(Bit_Get(deathspawn, playerid)) {

		if(Bit_Get(dead, playerid) && GetPVarInt(playerid, "deathtime") > 0) 
		{
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: Spawning with controllable status.");
			//SetPlayerSkin(playerid, p_skin[playerid]);
			Bit_Vet(dead, playerid);
			Bit_Vet(frozen, playerid);
			DeletePVar(playerid, "deathtime");
			Delete3DTextLabel(DamageLabel[playerid]);
			TogglePlayerControllable(playerid, true);
		}

		if(Bit_Get(dead, playerid)) 
		{
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: Spawning with uncontrollable status.");
			//SetPlayerSkin(playerid, p_skin[playerid]);
			new Float:pos[4];
			GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
			GetPlayerFacingAngle(playerid, pos[3]);
			SetPlayerInterior(playerid, GetPVarInt(playerid, "deadinterior"));
			SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "deadvw"));
			SetPlayerPos(playerid, GetPVarFloat(playerid, "deadx"), GetPVarFloat(playerid, "deady"), GetPVarFloat(playerid, "deadz"));
			SetPlayerFacingAngle(playerid, GetPVarInt(playerid, "deadf"));
			SetCameraBehindPlayer(playerid);
			new string[256];
			format(string, sizeof(string), "(( %s is brutally wounded.\n/damages and /loot %d for more information. ))",PlayerName(playerid), playerid);
			DamageLabel[playerid] = Create3DTextLabel(string, COLOR_PINK, pos[0], pos[1], pos[2], NAMETAG_DISTANCE*2, GetPlayerVirtualWorld(playerid), 1);
			Attach3DTextLabelToPlayer(DamageLabel[playerid], playerid, 0.0, 0.0, 0.6);
			ApplyDeathAnimation(playerid);
			SCM(playerid, HEX_FADE2, "You have been brutally wounded, but you can still be saved by medics.");
			SCM(playerid, HEX_FADE2, "To respawn use /respawnme in a minute, if noone's roleplaying with you.");

			//RandomHumanSpawn(playerid);
			
			SetPlayerHealth(playerid, 50.0);
			SetPVarInt(playerid, "deathtime", 1);
			defer BrutallyWounded(playerid);
			//TogglePlayerControllable(playerid, false);
		}

		if(IsZombie(playerid)) {
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: Spawning as a zombie.");
			if(GetPVarInt(playerid, "deadvw") > 0) {
				SetPlayerInterior(playerid, GetPVarInt(playerid, "deadinterior"));
				SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "deadvw"));
				DeletePVar(playerid, "deadvw");
				DeletePVar(playerid, "deadinterior");
			}
			SetPlayerSkin(playerid, RandomZombieSkin());
		}

		Bit_Vet(deathspawn, playerid);

	}

	SetPlayerWeather(playerid, ServerTime[weather]);
	SetPlayerTime(playerid, ServerTime[hour], 30);


	return Y_HOOKS_CONTINUE_RETURN_1;
}

timer BrutallyWounded[BW_TIME](playerid) {
	if(Bit_Get(dead, playerid) && GetPVarInt(playerid, "deathtime") > 0) 
	{
		SCM(playerid, HEX_WHITE, "You can accept your death now.");
		SetPVarInt(playerid, "deathtime", 2);
	}
}

hook OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart) {
	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
	if(Bit_Get(dead, playerid)) {
		SetPlayerHealth(playerid, 50.0+amount);
		
	}
	if(Bit_Get(dead, playerid) && GetPVarInt(playerid, "deathtime") > 0) 
	{
		if(!Bit_Get(frozen, playerid)) 
		{
			Bit_Let(frozen, playerid);
			Update3DTextLabelText(DamageLabel[playerid], COLOR_PINK, "(( THIS PLAYER IS DEAD. ))");
			TogglePlayerControllable(playerid, false);
			SCM(playerid, HEX_FADE2, "You are now dead.");
			ApplyDeathAnimation(playerid);
			ApplyDeathAnimation(playerid);
		}
		if(IsPlayerNPC(issuerid))
			FCNPC_StopAim(issuerid);
	}


	return Y_HOOKS_CONTINUE_RETURN_1;	
}

hook OnPlayerConnect(playerid) {
	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;

	new ip[18];
    GetPlayerIp(playerid, ip, sizeof(ip));

	foreach(new i : Player) {
		if(i != playerid) {
			if(Bit_Get(togsjoin, i)) {
				if(Group_GetPlayer(g_AdminDuty, i))
					SFM(i, HEX_FADE2, "[JOIN] %s[%d] has joined the server. (IP: %s) There are %d players online.", PlayerName(playerid), playerid, ip, GetConnectedPlayers());
				else
					SFM(i, HEX_FADE2, "[JOIN] %s[%d] has joined the server.", PlayerName(playerid), playerid);
			}
		}
	}
	MilitaryWeaponSkills(playerid);
	RemoveDefaultVendingMachines(playerid);
	SetPVarInt(playerid, "spect", -1);
	//ResetPlayerNPCbars(playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

MilitaryWeaponSkills(playerid) {
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 40);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 999);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 999);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 999);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 200);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 999);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 50);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 999);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 999);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 999);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 999);
	return 1;
}

WorseWeaponSkills(playerid) {
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL, 20);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_PISTOL_SILENCED, 600);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_DESERT_EAGLE, 300);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SHOTGUN, 300);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SAWNOFF_SHOTGUN, 150);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SPAS12_SHOTGUN, 150);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MICRO_UZI, 25);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_MP5, 300);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_AK47, 300);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_M4, 300);
	SetPlayerSkillLevel(playerid, WEAPONSKILL_SNIPERRIFLE, 450);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;

	new Float:qpos[3];
	GetPlayerPos(playerid, qpos[0], qpos[1], qpos[2]);

	foreach(new i : Player) {
		if(i != playerid) {
			if(IsPlayerInRangeOfPoint(i, NAMETAG_DISTANCE, qpos[0], qpos[1], qpos[2]) && GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i) && GetPlayerInterior(playerid) == GetPlayerInterior(i))
				SFM(i, HEX_FADE2, "* %s has left the server. (%s)", PlayerName(playerid, true), LeaveReason(reason));
			else if(Bit_Get(togsjoin, i))
				SFM(i, HEX_FADE2, "[LEAVE] %s has left the server. (%s)", PlayerName(playerid), LeaveReason(reason));
		}
	}

	

	if(reason == 0)
		Bit_Let(crashed, playerid);
	else
		Bit_Vet(crashed, playerid);	

	SavePlayer(playerid);
	printf("save player called for %s", PlayerName(playerid));

	/*if(IsValidDynamic3DTextLabel(GetPVarInt(playerid, "3d_scene"))) {
		DestroyDynamic3DTextLabel(GetPVarInt(playerid, "3d_scene"));
	}*/
	return Y_HOOKS_CONTINUE_RETURN_1;
}

new Text:BlindfoldTD;
hook OnGameModeInit() {
	CreateRadiations();

	Command_AddAltNamed("stopaudio", "fixr");


	BlindfoldTD = TextDrawCreate(641.199951, 1.500000, "usebox");
	TextDrawLetterSize(BlindfoldTD, 0.000000, 49.378147);
	TextDrawTextSize(BlindfoldTD, -2.000000, 0.000000);
	TextDrawAlignment(BlindfoldTD, 3);
	TextDrawColor(BlindfoldTD, -1);
	TextDrawUseBox(BlindfoldTD, true);
	TextDrawBoxColor(BlindfoldTD, 255);
	TextDrawSetShadow(BlindfoldTD, 0);
	TextDrawSetOutline(BlindfoldTD, 0);
	TextDrawBackgroundColor(BlindfoldTD, 255);
	TextDrawFont(BlindfoldTD, 1);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

public e_COMMAND_ERRORS:OnPlayerCommandReceived(playerid, cmdtext[], e_COMMAND_ERRORS:success) {
	Command_SetDeniedReturn(true);
    if(!Bit_Get(loggedin, playerid)) 
	{
        SCM(playerid, HEX_RED, "[Desolation]: You must be logged in.");
        return COMMAND_DENIED;
    }
	if(!Bit_Get(character, playerid)) 
	{
        SCM(playerid, HEX_RED, "[Desolation]: You must spawn a character.");
        return COMMAND_DENIED;
    }

    switch (success) 
	{ 
        case COMMAND_UNDEFINED: 
		{ 
            SCM(playerid, HEX_RED, "[Desolation]: Invalid command.");
			return COMMAND_DENIED;
        }
        case COMMAND_DENIED: 
		{ 
            SCM(playerid, HEX_RED, "[Desolation]: Access denied! You lack permission to use this command.");
			return COMMAND_DENIED;
        }
    } 
    
	return COMMAND_OK;
}

public e_COMMAND_ERRORS:OnPlayerCommandPerformed(playerid, cmdtext[], e_COMMAND_ERRORS:success)
{
    return COMMAND_OK;
}

hook OnPlayerText(playerid, text[]) {
	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
	if(!Bit_Get(character, playerid)) {
		SCM(playerid, HEX_RED, "[Desolation]: You must spawn a character.");
		return Y_HOOKS_BREAK_RETURN_0;
	}
	if(Bit_Get(spectating, playerid)) {
		SCM(playerid, HEX_RED, "[Desolation]: You are in spectator mode.");
		return Y_HOOKS_BREAK_RETURN_0;
	}
	new formatText[256];
	if(IsHuman(playerid)) 
	{
		if(Bit_Get(dead, playerid)) SCM(playerid, HEX_RED, "[Desolation]: You are dead.");
		else 
		{
			format(formatText,sizeof formatText, "%s says: %s", PlayerName(playerid,false),text);
			//ProxDetector(NAMETAG_DISTANCE, playerid, formatText, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
			WhiteProxMSG(NAMETAG_DISTANCE, playerid, formatText);
			TalkAnim(playerid, strlen(text));
			//PublicLog(text);
		}
	}
	else 
	{
		if(Group_GetPlayer(g_AdminDuty, playerid))
			format(formatText, sizeof(formatText), ""HEX_TESTER"(( Zombie [%i] "HEX_ADMIN"%s"HEX_TESTER": %s ))", playerid, PlayerName(playerid), text);
		else
			format(formatText, sizeof(formatText), "(( Zombie [%i] %s: %s ))", playerid, PlayerName(playerid), text);
		foreach(new i:GroupMember[g_Zombie]) {
			if(!Group_GetPlayer(g_AdminDuty, i) && !Bit_Get(togzchat, i))
				SCM(i, HEX_TESTER, formatText);
		}
		foreach(new j:GroupMember[g_AdminDuty]) {
			if(!Bit_Get(togzchat, j))
				SCM(j, HEX_TESTER, formatText);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_0;
}

hook OnPlayerStateChange(playerid, newstate, oldstate) {
	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
	
	if(newstate == PLAYER_STATE_DRIVER)
	{
		FixSpectators(playerid);
		SetPlayerArmedWeapon(playerid, 0);
	}
	else if(newstate == PLAYER_STATE_PASSENGER) 
	{
		FixSpectators(playerid);
		new tmp_wep = GetPlayerWeapon(playerid);
		switch(tmp_wep) 
		{
			case 22: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 23: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 25: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 26: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 27: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 28: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 29: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 30: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 31: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 32: SetPlayerArmedWeapon(playerid, tmp_wep);
			case 33: SetPlayerArmedWeapon(playerid, tmp_wep);
			default: SetPlayerArmedWeapon(playerid, 0);
		}
	}
	else if(newstate == PLAYER_STATE_ONFOOT) {
		FixSpectators(playerid);
	}

	

	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:respawnme(playerid, params[], help) {
	if(!Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You are not dead.");
	if(GetPVarInt(playerid, "deathtime") == 1 && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot respawn yet.");

	Bit_Vet(dead, playerid);
	Bit_Vet(frozen, playerid);
	Bit_Vet(infected, playerid);
	DeletePVar(playerid, "deathtime");

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `deaths` = `deaths`+1 WHERE id = %d LIMIT 1",  CharacterSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");
	printf("%s", sql);

	Delete3DTextLabel(DamageLabel[playerid]);
	TogglePlayerControllable(playerid, true);
	ClearAnimations(playerid, true);
	ResetPlayerWeapons(playerid);
	/*
	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND state = 1",  CharacterSQL[playerid]);
	mysql_query(g_SQL, sql);

	new j = -1;
    for(;++j<MAX_INVENTORY_SLOTS;) {
        inventory_used[playerid][j] = false;
	}*/

	SetPlayerHealth(playerid, 90.0);
	SetPlayerArmour(playerid, 0.0);

	if(IsPlayerInAnyVehicle(playerid))
		RemovePlayerFromVehicle(playerid);	

	mysql_format(g_SQL, sql, sizeof sql, "SELECT `spawnInteriors` FROM `player` WHERE id = '%d' AND state = 1 LIMIT 1", CharacterSQL[playerid]);
	inline LoadRespawnInfo() {
		if(!cache_num_rows()) {
			SCM(playerid, HEX_FADE2, "You do not have a saved /setspawn location, therefore you respawn in the wilderness.");
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			switch(random(5)) {
				case 0: SetPlayerPos(playerid, 29.1471,119.3594,2.7324);
				case 1: SetPlayerPos(playerid, 1232.1644,-216.8703,36.3415);
				case 2: SetPlayerPos(playerid, 59.8838,-687.3679,10.0368);
				case 3: SetPlayerPos(playerid, 169.7242,13.8764,1.4450);
				case 4: SetPlayerPos(playerid, 822.7242,-233.5299,18.8311);
				default: SetPlayerPos(playerid, 327.0460,-375.4874,11.5797);
			}
			SetPlayerFacingAngle(playerid, 180.6704);
			ChangeMaskVW(playerid);
			@return 0;
		}
		
        new spawninginti;
		cache_get_value_int(0, "spawnInteriors", spawninginti);
		new bool:spawnedatinti = false;
		foreach(new i:Entrances) {
			if(IntInfo[i][sqlid] == spawninginti) {
				SetPlayerVirtualWorld(playerid, IntInfo[i][outvw]);
				SetPlayerInterior(playerid, IntInfo[i][outint]);
				SetPlayerPos(playerid, IntInfo[i][outx],IntInfo[i][outy],IntInfo[i][outz]);
				SetPlayerFacingAngle(playerid, IntInfo[i][outf]);
				ChangeMaskVW(playerid);
				spawnedatinti = true;
				break;
			}
		}

		if(!spawnedatinti) {
			SCM(playerid, HEX_FADE2, "You do not have a valid saved /setspawn location, therefore you respawn in the wilderness.");
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			//SetPlayerPos(playerid, 803.9145, -535.4553, 16.4004);
			switch(random(6)) {
				case 0: SetPlayerPos(playerid, 29.1471,119.3594,2.7324);
				case 1: SetPlayerPos(playerid, 1232.1644,-216.8703,36.3415);
				case 2: SetPlayerPos(playerid, 59.8838,-687.3679,10.0368);
				case 3: SetPlayerPos(playerid, 169.7242,13.8764,1.4450);
				case 4: SetPlayerPos(playerid, 822.7242,-233.5299,18.8311);
				default: SetPlayerPos(playerid, 327.0460,-375.4874,11.5797);
			}
			SetPlayerFacingAngle(playerid, 90.6704);
			ChangeMaskVW(playerid);
			@return 0;
		}

		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadRespawnInfo, sql);

	return 1;
}

YCMD:toghints(playerid, params[], help) {
	if(Bit_Get(tutorial, playerid)) 
	{
		Bit_Vet(tutorial, playerid);
		SCM(playerid, HEX_FADE2, "You turned off hint messages.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_TUTORIAL` = 0 WHERE id = %d", AccountSQL[playerid]);
	}
	else 
	{
		Bit_Let(tutorial, playerid);
		SCM(playerid, HEX_FADE2, "You turned on hint messages.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_TUTORIAL` = 1 WHERE id = %d", AccountSQL[playerid]);
	}
	mysql_tquery(g_SQL, sql, "", "");
	return 1;
}

YCMD:togzones(playerid, params[], help) {
	if(Bit_Get(togszones, playerid)) 
	{
		Bit_Vet(togszones, playerid);
		SCM(playerid, HEX_FADE2, "You turned off the territory HUD.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_ZONES` = 0 WHERE id = %d", AccountSQL[playerid]);
	}
	else 
	{
		Bit_Let(togszones, playerid);
		SCM(playerid, HEX_FADE2, "You turned on the territory HUD.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_ZONES` = 1 WHERE id = %d", AccountSQL[playerid]);
	}
	mysql_tquery(g_SQL, sql, "", "");
	ResetTerritoryGangzones(playerid);
	return 1;
}

YCMD:togjoin(playerid, params[], help) {
	if(Bit_Get(togsjoin, playerid)) 
	{
		Bit_Vet(togsjoin, playerid);
		SCM(playerid, HEX_FADE2, "You turned off login messages.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_JOIN` = 0 WHERE id = %d", AccountSQL[playerid]);
	}
	else 
	{
		Bit_Let(togsjoin, playerid);
		SCM(playerid, HEX_FADE2, "You turned on login messages.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_JOIN` = 1 WHERE id = %d", AccountSQL[playerid]);
	}
	mysql_tquery(g_SQL, sql, "", "");
	return 1;
}

YCMD:tognpcnames(playerid, params[], help) {
	/*if(Bit_Get(togsnpchp, playerid)) 
	{
		Bit_Vet(togsnpchp, playerid);
		SCM(playerid, HEX_FADE2, "You turned off NPC names and health bars. They are no longer visible in the tablist.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_NPCHEALTH` = 0 WHERE id = %d", AccountSQL[playerid]);
	}
	else 
	{
		Bit_Let(togsnpchp, playerid);
		SCM(playerid, HEX_FADE2, "You turned on NPC names and health bars. They are also visible now in the tablist!");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_NPCHEALTH` = 1 WHERE id = %d", AccountSQL[playerid]);
	}
	ResetPlayerNPCbars(playerid);
	mysql_tquery(g_SQL, sql, "", "");*/
	return 1;
}

YCMD:toghud(playerid, params[], help) {
	if(Bit_Get(togshud, playerid)) 
	{
		Bit_Vet(togshud, playerid);
		SCM(playerid, HEX_FADE2, "You turned off Desolation's head-up display.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_HUD` = 0 WHERE id = %d", AccountSQL[playerid]);
	}
	else 
	{
		Bit_Let(togshud, playerid);
		SCM(playerid, HEX_FADE2, "You turned on Desolation's head-up display.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `TOG_HUD` = 1 WHERE id = %d", AccountSQL[playerid]);
	}
	ResetHuds(playerid);
	mysql_tquery(g_SQL, sql, "", "");
	return 1;
}

ResetHuds(playerid) {
	if(Bit_Get(togshud, playerid)) {
		ShowPlayerProgressBar(playerid, hungerbar[playerid]);
		ShowPlayerProgressBar(playerid, thirstbar[playerid]);

		PlayerTextDrawShow(playerid, racetd[playerid]);
	}
	else {
		HidePlayerProgressBar(playerid, hungerbar[playerid]);
		HidePlayerProgressBar(playerid, thirstbar[playerid]);

		PlayerTextDrawHide(playerid, racetd[playerid]);
	}
	return 1;
}

ResetPlayerNPCbars(playerid) {
	if(Bit_Get(togsnpchp, playerid)) {
		foreach(new j:GroupMember[npc_Zombie]) {
			FCNPC_ShowInTabListForPlayer(j, playerid);
		}
		foreach(new k:GroupMember[npc_a51]) {
			FCNPC_ShowInTabListForPlayer(k, playerid);	
		}
	}
	else {
		foreach(new j:GroupMember[npc_Zombie]) {
			FCNPC_HideInTabListForPlayer(j, playerid);
		}
		foreach(new k:GroupMember[npc_a51]) {
			FCNPC_HideInTabListForPlayer(k, playerid);
		}
	}
	return 1;
}

YCMD:togzombie(playerid, params[], help) {
	if(Bit_Get(togzchat, playerid)) 
	{
		Bit_Vet(togzchat, playerid);
		SCM(playerid, HEX_FADE2, "You turned off zombie messages.");
	}
	else {
		Bit_Let(togzchat, playerid);
		SCM(playerid, HEX_FADE2, "You turned on zombie messages.");
	}
	return 1;
}

YCMD:cmdlist(playerid, params[], help) {
	
	SCM(playerid, HEX_FADE2, "Command list:");
	new count = Command_GetPlayerCommandCount(playerid);
	new string[256];
	new bool:sent;
	for (new i = 0; i != count; ++i) {
		strcat(string, Command_GetNext(i, playerid));
		strcat(string, "; ");
		sent = false;
		if(i%5 == 0 && i > 0) {
			SCM(playerid, HEX_FADE2, string);
			string = "";
			sent = true;
		}
	}
	if(!sent)
		SCM(playerid, HEX_FADE2, string);
    return 1;
}

YCMD:stats(playerid, params[], help) {
	new Hour, Minute, Second;
	gettime(Hour, Minute, Second);
	new Year, Month, Day;
	getdate(Year, Month, Day);
	new Float:healthp[2];
	GetPlayerHealth(playerid, healthp[0]);
	GetPlayerArmour(playerid, healthp[1]);
	new killstat[3];

	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player` WHERE id = %d", CharacterSQL[playerid]);
	inline LoadStats() 
	{
		if(!cache_num_rows()) 
		{
			@return 0;
		}		
		cache_get_value_int(0, "kills", killstat[0]);		
		cache_get_value_int(0, "zkills", killstat[1]);
		cache_get_value_int(0, "deaths", killstat[2]);
		if(playerid == playerid)
		SFM(playerid, HEX_ORANGE, ":: ________ :: Stats of %s on %02d/%02d/%d %02d:%02d:%02d :: ________ ::",PlayerName(playerid, true), Year, Month, Day, Hour, Minute, Second);
		else
		SFM(playerid, HEX_ADMIN, ":: ________ :: Stats of %s on %02d/%02d/%d %02d:%02d:%02d :: ________ ::",PlayerName(playerid, true), Year, Month, Day, Hour, Minute, Second);
		SFM(playerid, HEX_FADE2, "Account | accountid:[%d] accountname:[%s] adminlevel:[%d]", AccountSQL[playerid], accountname[playerid], adminlevel[playerid]);
		SFM(playerid, HEX_FADE2, "Player | level:[%d] experience:[%d] cash:[%d] skin:[%d]", GetPlayerScore(playerid), experience[playerid], cash[playerid], GetPlayerSkin(playerid));
		SFM(playerid, HEX_FADE2, "Player | player kills:[%d] zombie kills:[%d] deaths:[%d]", killstat[0], killstat[1], killstat[2]);
		if(faction[playerid] > 0)
			ShowFactionStats(playerid, playerid);
		if(city[playerid] > 0)
			ShowCityStats(playerid, playerid);
		SFM(playerid, HEX_FADE2, "Flags | zombie:[%d] infected:[%d] dead:[%d] frozen:[%d] hints:[%d] radiation:[%d]", onezero(Bit_Get(pzombie, playerid)), onezero(Bit_Get(infected, playerid)), onezero(Bit_Get(dead, playerid)), onezero(Bit_Get(frozen, playerid)), onezero(Bit_Get(tutorial, playerid)), onezero(Bit_Get(radiation, playerid)) );
		//SFM(playerid, HEX_FADE2, "Skills | talent1: [%s] talent2: [%s] talent3: [%s]", Talents[skill1[playerid]], Talents[skill2[playerid]], Talents[skill3[playerid]]);
		if(playerid == playerid)
		SFM(playerid, HEX_ORANGE, ":: ________ :: Stats of %s on %02d/%02d/%d %02d:%02d:%02d :: ________ ::",PlayerName(playerid, true), Year, Month, Day, Hour, Minute, Second);
		else
		SFM(playerid, HEX_ADMIN, ":: ________ :: Stats of %s on %02d/%02d/%d %02d:%02d:%02d :: ________ ::",PlayerName(playerid, true), Year, Month, Day, Hour, Minute, Second);
		SCM(playerid, HEX_FADE2, "Hint: Your data is saved whenever you log out.");
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadStats, sql);
	return 1;
}

YCMD:mask(playerid, params[], help)  {
	if(Bit_Get(masked, playerid)) 
	{
		MaskPlayer(playerid, false, true);
	}
	else 
	{
		MaskPlayer(playerid, true, true);
	}
	return 1;
}

MaskPlayer(playerid, bool:updatemask, showmsg = true) {
	if(updatemask) 
	{
		Bit_Let(masked, playerid);
		if(showmsg)
			GameTextForPlayer(playerid, "~g~Masked!", 2000, 3);
		MaskText[playerid] = Create3DTextLabel(PlayerName(playerid, false), COLOR_WHITE, 0.0, 0.0, 0.0, NAMETAG_DISTANCE, GetPlayerVirtualWorld(playerid), 1);
		Attach3DTextLabelToPlayer(MaskText[playerid], playerid, 0.0, 0.0, 0.2);
		foreach(new i : Player) 
		{	
			ShowPlayerNameTagForPlayer(i, playerid, false);
		}
	}
	else 
	{
		Bit_Vet(masked, playerid);
		if(showmsg)
			GameTextForPlayer(playerid, "~w~Unmasked!", 2000, 3);
		Delete3DTextLabel(MaskText[playerid]);
		foreach(new i : Player) 
		{
			ShowPlayerNameTagForPlayer(i, playerid, true);
		}
	}
	return 1;
}

hook OnPlayerStreamIn(playerid, forplayerid) {

	if(Bit_Get(masked, playerid)) {
		ShowPlayerNameTagForPlayer(forplayerid, playerid, false);
	}
	else
		ShowPlayerNameTagForPlayer(forplayerid, playerid, true);
	if(Bit_Get(masked, forplayerid)) {
		ShowPlayerNameTagForPlayer(playerid, forplayerid, false);
	}
	else
		ShowPlayerNameTagForPlayer(playerid, forplayerid, true);

	return Y_HOOKS_CONTINUE_RETURN_1;
}

SavePlayer(playerid) {
	if(Bit_Get(loggedin, playerid) && Bit_Get(character, playerid))  
	{
		new Float:phealth[2];
		GetPlayerHealth(playerid, phealth[0]);
		GetPlayerArmour(playerid, phealth[1]);
		new Float:playerpos[4];
		GetPlayerPos(playerid, playerpos[0], playerpos[1], playerpos[2]);
		GetPlayerFacingAngle(playerid, playerpos[3]);

		new dstatus = 0;
		if(Bit_Get(dead, playerid)) {
			++dstatus;
			if(Bit_Get(frozen, playerid))
				++dstatus;
		}

		new crashstatus = Bit_Get(crashed, playerid);
		if(crashstatus > 0) crashstatus = 1;
		else
			crashstatus = 0;

		if(IsHuman(playerid))
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `level`= '%d', `health` = '%f', `armor` = '%f', `experience` = '%d', `cash` = '%d', `minutes` = '%d', `mechskill` = '%d', `luckskill` = '%d', `craftskill` = '%d', `tradeskill` = '%d', `skin` = '%d', `pzombie` = '0' ,`count_infest` = `count_infest` + '%d' ,`posx` = '%f', `posy` = '%f', `posz` = '%f', `posf` = '%f',`interior` = '%d',`virtualworld` = '%d', `factionId` = '%d', `rank` = '%e', `crashed` = '%d', `deadstatus` = %d, `hunger` = '%f', `thirst` = '%f', `infected` = '%d' WHERE id = '%d'  LIMIT 1", GetPlayerScore(playerid), phealth[0], phealth[1], experience[playerid], cash[playerid], minutes[playerid], MechSkill[playerid], LuckSkill[playerid], CraftSkill[playerid], TradeSkill[playerid], p_skin[playerid], count_infest[playerid], playerpos[0], playerpos[1], playerpos[2], playerpos[3], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), faction[playerid], factionrank[playerid], crashstatus, dstatus, hunger[playerid], thirst[playerid], onezero(Bit_Get(infected, playerid)), CharacterSQL[playerid]);
		else
			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `level`= '%d', `health` = '%f', `armor` = '%f', `experience` = '%d', `cash` = '%d', `minutes` = '%d', `skin` = '%d' ,`pzombie` = '1' ,`count_infest` = `count_infest` + '%d' ,`posx` = '%f', `posy` = '%f', `posz` = '%f', `posf` = '%f',`interior` = '%d',`virtualworld` = '%d', `factionId` = '%d', `rank` = '%e', `crashed` = '%d', `deadstatus` = %d, `hunger` = '%f', `thirst` = '%f', `infected` = '%d' WHERE id = '%d'  LIMIT 1", GetPlayerScore(playerid), phealth[0], phealth[1], experience[playerid], cash[playerid], minutes[playerid], p_skin[playerid], count_infest[playerid], playerpos[0], playerpos[1], playerpos[2], playerpos[3], GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), faction[playerid], factionrank[playerid], crashstatus, dstatus, hunger[playerid], thirst[playerid], onezero(Bit_Get(infected, playerid)), CharacterSQL[playerid]);
		mysql_tquery(g_SQL, sql, "", "");

		printf("DEBUG: --- Character [%s] [ID:%d] [ACCOUNT ID:%d] [CHARACTER ID:%d] ", PlayerName(playerid), playerid, AccountSQL[playerid], CharacterSQL[playerid]);
		printf("[SAVE] %s data saved!", PlayerName(playerid));

	}
	else
	{
		printf("[CHECK] %s is being called - CHECK BITS IF THIS MESSAGE SHOWS.", PlayerName(playerid));
	}
	return 1;
}

IsHuman(playerid) {
	if(Bit_Get(pzombie, playerid))
		return false;
	else
		return true;
}

YCMD:help(playerid, params[], help) {
	new	string[1024];
    inline _response(pid, dialogid, response, listitem, string:inputtext[]) 
	{
        #pragma unused dialogid, pid, inputtext
        if (!response) 
		{
            return 0;
        }

        switch(listitem) 
		{
            case 0: OpenInventory(playerid);
			case 1:
            {
                //strcat(string, ""HEX_ORANGE"General Commands
				strcat(string, ""HEX_ORANGE"/r "HEX_WHITE"- To use the public radio ( IC Channel )\n\
                    "HEX_SAMP"/setfreq "HEX_WHITE"- Set the frequency to a specific channel [channel 1-8] [frequency 1-10000] \n\
                    "HEX_SAMP"/cure "HEX_WHITE"- Inject the cure into yourself or other infected humans\n\
					"HEX_SAMP"/heal "HEX_WHITE"- Heal yourself or other injured survivor\n\
					"HEX_SAMP"/report "HEX_WHITE"- To report any rulebreakers or cheaters\n\
					"HEX_SAMP"/mine "HEX_WHITE"- To mine any metal node\n\
					"HEX_SAMP"/stats "HEX_WHITE"- To see your own stats\n\
					"HEX_SAMP"/debugme "HEX_WHITE"- To unstuck yourself and reset your position\n\
					"HEX_SAMP"/description "HEX_WHITE"- To set your character description (max 128 characters)\n\
					"HEX_SAMP"/examine "HEX_WHITE"- To see someone's description\n\
					"HEX_SAMP"F button "HEX_WHITE"- press F to enter or exit an interior"
			    );
                Dialog_Show(playerid, DIALOG_STYLE_MSGBOX, ""HEX_ORANGE"General Commands", string, "Close", "");
            }
            case 2:
            {
                strcat(string, ""HEX_ORANGE"Faction and City Commands\n\
					"HEX_SAMP"/cityhelp "HEX_WHITE"- To see all available city commands\n\
					"HEX_SAMP"/factionhelp "HEX_WHITE"- To see all available faction commands\n\
                    "HEX_SAMP"/factions "HEX_WHITE"- To view the list of official factions\n\
                    "HEX_SAMP"/f "HEX_WHITE"- OOC Faction Chat"
			    );
                Dialog_Show(playerid, DIALOG_STYLE_MSGBOX, ""HEX_ORANGE"Faction Commands", string, "Close", "");
            }
            case 3: 
            {
                strcat(string, ""HEX_ORANGE"Safehouse Commands\n\
                    "HEX_SAMP"/storagehelp "HEX_WHITE"- To see storage safe commands\n\
					"HEX_SAMP"/lock "HEX_WHITE"- To lock/unlock your personal safehouse\n\
                    "HEX_SAMP"/grantkey (WIP) "HEX_WHITE"- Give a selected player the ability to lock/unlock your safehouse"
			    );
                Dialog_Show(playerid, DIALOG_STYLE_MSGBOX, ""HEX_ORANGE"Safehouse Commands", string, "Close", "");
            }
            case 4:
            {
                strcat(string, ""HEX_ORANGE"Zombie Commands\n\
                    "HEX_SAMP"/z "HEX_WHITE"- An OOC chat for zombies\n\
                    "HEX_SAMP"/mutation "HEX_WHITE"- To view and any special zombie skills available to you, depending on your level\n\
                    "HEX_SAMP"LEFT ALT "HEX_WHITE"- Use left alt to infect humans"
			    );
                Dialog_Show(playerid, DIALOG_STYLE_MSGBOX, ""HEX_ORANGE"Zombie Commands", string, "Close", "");
            }
            case 5:
            {
                strcat(string, ""HEX_ORANGE"Attachments\n\
                    "HEX_SAMP"/attach "HEX_WHITE"- Attachments are free, usable by any player, obtainable as in game items\n\
                    "HEX_SAMP"UNDER DEVELOPMENT "HEX_WHITE" Attachment features have NOT been added yet"
			    );
                Dialog_Show(playerid, DIALOG_STYLE_MSGBOX, ""HEX_ORANGE"Attachments", string, "Close", "");
            }
			case 6:
            {
                strcat(string, ""HEX_ORANGE"Crafting\n\
                    "HEX_SAMP"/craft "HEX_WHITE"- Craft your very own weapons, increase your crafting level by simply crafting\n\
                    "HEX_SAMP"UNDER DEVELOPMENT "HEX_WHITE" Medical and Vehicle crafting is still in the works"
			    );
                Dialog_Show(playerid, DIALOG_STYLE_MSGBOX, ""HEX_ORANGE"Crafting", string, "Close", "");
            }
            case 7:
            {
				Toggles(playerid);

            }
        }
	}
    Dialog_ShowCallback
	(
        playerid,
        using inline _response,
        DIALOG_STYLE_LIST,
        "Server Commands & Keys",
        "Open Inventory (H)\n\
		General\n\
        Factions and Cities\n\
        Safehouse\n\
        Zombies\n\
        Attachments\n\
		Crafting\n\
        Settings",
        "Select",
        "Close"
    );
    return 1;
}

YCMD:enter(playerid, params[], help) {

	SCM(playerid, HEX_FADE2, "Press KEY_RETURN (F by default) to enter or exit an interior.");

	return 1;
}

YCMD:exit(playerid, params[], help) {

	SCM(playerid, HEX_FADE2, "Press KEY_RETURN (F by default) to enter or exit an interior.");

	return 1;
}

Toggles(playerid)
{
	inline _response(pid, dialogid, response, listitem, string:inputtext[])
	{
		#pragma unused dialogid, pid, inputtext
		if (!response) 
		{
            return 0;
        }
        switch(listitem) 
		{
			case 0:
			{

			}
			case 1:
			{

			}
			case 2:
			{
				
			}
		}
	}
    Dialog_ShowCallback
	(
        playerid,
        using inline _response,
        DIALOG_STYLE_LIST,
        "3DText Labels",
        "Music\n\
		Map Icons\n\
        Zombie Audio",
        "Select",
        "Close"
    );
    return 1;
}

GetSQLCharname(csqlid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT name FROM `player`  WHERE id = '%d' LIMIT 1", csqlid);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnval[MAX_PLAYER_NAME];
	if(cache_num_rows()) {
		cache_get_value(0, "name", returnval, sizeof(returnval));
	}
	else
		returnval = "NO_PLAYER";
	cache_delete(result);
	return returnval;
}


YCMD:fixr(playerid, params[], help) {
	StopAudioStreamForPlayer(playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:theme(playerid, params[], help) {
	PlayAudioStreamForPlayer(playerid, "https://ds-rp.com/ambience.mp3");
	return Y_HOOKS_CONTINUE_RETURN_1;
}


YCMD:me(playerid, params[], help) {
	new text[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /me [action]");
	new string[256];
	format(string, sizeof(string), "* %s %s", PlayerName(playerid,false), text);
	//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE);
	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, string);
	//PublicLog(string);
	return 1;
}

YCMD:my(playerid, params[], help) {
	new text[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /me [action]");
	new string[256];
	format(string, sizeof(string), "* %s's %s", PlayerName(playerid,false), text);
	//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE);
	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, string);
	return 1;
}

YCMD:melow(playerid, params[], help) {
	new text[256];
	if(sscanf(params, "s[256]",text)) {
		SCM(playerid, HEX_FADE2, "Usage: /melow [action]");
		if(Bit_Get(tutorial, playerid))
			SFM(playerid, HEX_FADE2, "Hint: /do and /me is visible from nametag distance (%02f), while /dolow and /melow gets only half as far (%02f).", NAMETAG_DISTANCE, NAMETAG_DISTANCE/2.0);
		return 1;
	}
	new string[256];
	format(string, sizeof(string), "* %s %s", PlayerName(playerid,false), text);
	//ProxDetector(NAMETAG_DISTANCE/2.0, playerid, string, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE);
	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE/2.0, playerid, string);
	return 1;
}

YCMD:ame(playerid, params[], help) {
	new text[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /ame [action]");
	PlayerAction(playerid, text);
	return 1;
}

YCMD:amy(playerid, params[], help) {
	new text[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /amy [action]");
	format(text, sizeof text, "* %s's %s", PlayerName(playerid, false), text);
	PlayerAction(playerid, text, false);
	return 1;
}

YCMD:do(playerid, params[], help) {
	new text[256],string[256];
	if(sscanf(params, "s[256]", text)) return SCM(playerid, HEX_FADE2, "Usage: /do [action]");
	format(string, sizeof(string), "* %s (( %s ))",text,PlayerName(playerid,false));
	//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE);
	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE/2.0, playerid, string);
	return 1;
}

YCMD:dolow(playerid, params[], help) {
	new text[256],string[256];
	if(sscanf(params, "s[256]", text)) {
		SCM(playerid, HEX_FADE2, "Usage: /dolow [action]");
		if(Bit_Get(tutorial, playerid))
			SFM(playerid, HEX_FADE2, "Hint: /do and /me is visible from nametag distance (%02f), while /dolow and /melow gets only half as far (%02f).", NAMETAG_DISTANCE, NAMETAG_DISTANCE/2.0);
		return 1;
	}
	format(string, sizeof(string), "* %s (( %s ))",text,PlayerName(playerid,false));
	//ProxDetector(NAMETAG_DISTANCE/2.0, playerid, string, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE);
	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE/2.0, playerid, string);
	return 1;
}

YCMD:low(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new text[256],string[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /low [message]");
	format(string, sizeof(string), "%s says [low]: %s", PlayerName(playerid,false), text);
	//ProxDetector(NAMETAG_DISTANCE/2.0, playerid, string, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
	WhiteProxMSG(NAMETAG_DISTANCE/2.0, playerid, string);
	return 1;
}

YCMD:s(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new text[256],string[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /s [message]");
	format(string, sizeof(string), "%s shouts: %s", PlayerName(playerid,false), text);
	//ProxDetector(NAMETAG_DISTANCE*2, playerid, string, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
	WhiteProxMSG(NAMETAG_DISTANCE*2, playerid, string);
	return 1;
}

YCMD:b(playerid, params[], help) {
	new text[256],string[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /b [message]");
	if(Group_GetPlayer(g_AdminDuty, playerid)) {
		format(string, sizeof(string), ""HEX_FADE3"(( [%i] "HEX_ADMIN"%s"HEX_FADE3": %s ))", playerid, PlayerName(playerid), text);
		//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_FADE3, COLOR_FADE3, COLOR_FADE3, COLOR_FADE3, COLOR_FADE3);
		//WhiteProxMSG(NAMETAG_DISTANCE, playerid, string);
		ProxMSG(HEX_FADE3, NAMETAG_DISTANCE, playerid, string);
	}
	else {
		format(string, sizeof(string), "(( [%i] %s: %s ))", playerid, PlayerName(playerid), text);
		//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_FADE1, COLOR_FADE2, COLOR_FADE3, COLOR_FADE4, COLOR_FADE5);
		WhiteProxMSG(NAMETAG_DISTANCE, playerid, string);

	}
	return 1;
}

YCMD:w(playerid, params[], help){
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new text[256],targetid,string[256], Float:pos[3];
	if(sscanf(params, "rs[256]", targetid, text)) return SCM(playerid, HEX_FADE2, "Usage: /w [id] [message]");
    if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "is[256]", targetid, text);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(playerid == targetid) return SCM(playerid, HEX_RED, "[Desolation]: You cannot message yourself.");
	GetPlayerPos(targetid, pos[0],pos[1],pos[2]);
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, pos[0],pos[1],pos[2]) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	format(string, sizeof(string), "%s whispers: %s", PlayerName(playerid,false), text);
	SCM(targetid,HEX_YELLOW,string);
	SCM(playerid,HEX_YELLOW,string);	
	PlayerHiddenAction(playerid, "whispers.");
	return 1;
}

YCMD:cb(playerid, params[], help) {
	new text[256],string[256];
	if(sscanf(params, "s[256]", text)) return SCM(playerid, HEX_FADE2, "Usage: /cb [message]");
	new targetcar = GetPlayerVehicleID(playerid);
	if(!targetcar) return SCM(playerid, HEX_RED, "[Desolation]: You must be in a vehicle.");
	
	if(Group_GetPlayer(g_AdminDuty, playerid))
		format(string, sizeof(string), ""HEX_YELLOW"(( [%i] "HEX_ORANGE"%s"HEX_YELLOW" (car): %s ))", playerid, PlayerName(playerid), text);
	else
		format(string, sizeof(string), "(( [%d] %s (car): %s ))", playerid, PlayerName(playerid,false), text);
	foreach(new i:Player) {
		if(GetPlayerVehicleID(i) == targetcar)
			SCM(i,HEX_YELLOW,string);
	}
	return 1;
}

YCMD:cw(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new text[256],string[256];
	if(sscanf(params, "s[256]", text)) return SCM(playerid, HEX_FADE2, "Usage: /cw [message]");
	new targetcar = GetPlayerVehicleID(playerid);
	if(!targetcar) return SCM(playerid, HEX_RED, "[Desolation]: You must be in a vehicle.");
	format(string, sizeof(string), "%s whispers (car): %s", PlayerName(playerid,false), text);
	foreach(new i:Player) {
		if(GetPlayerVehicleID(i) == targetcar)
			SCM(i,HEX_YELLOW,string);
	}
	return 1;
}

YCMD:pm(playerid, params[], help) {
	
	new text[256],targetid,string[256];
	if(sscanf(params, "rs[256]", targetid, text)) return SCM(playerid, HEX_FADE2, "Usage: /pm [id] [message]");
    if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "is[256]", targetid, text);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}
	if(playerid == targetid) return SCM(playerid, HEX_RED, "Error: You cannot message yourself.");
	
	if(Group_GetPlayer(g_AdminDuty, playerid))
		format(string, sizeof(string), "(( PM from [%i] "HEX_ADMIN"%s"HEX_YELLOW": %s ))",  playerid, PlayerName(playerid),text);
	else
		format(string, sizeof(string), "(( PM from [%i] %s: %s ))", playerid, PlayerName(playerid), text);
	SCM(targetid,HEX_YELLOW,string);
	
	if(Group_GetPlayer(g_AdminDuty, targetid))
		format(string, sizeof(string), "(( PM to [%i] "HEX_ADMIN"%s"HEX_YELLOW": %s ))", targetid, PlayerName(targetid), text);
	else
		format(string, sizeof(string), "(( PM to [%i] %s: %s ))", targetid, PlayerName(targetid), text);
	SCM(playerid,HEX_YELLOW,string);	
	return 1;
}

YCMD:blindfold(playerid, params[], help) {
	if(Bit_Get(blindfolded, playerid)) {
		TextDrawHideForPlayer(playerid, BlindfoldTD);
		Bit_Vet(blindfolded, playerid);
	} else {
		TextDrawShowForPlayer(playerid, BlindfoldTD);
		Bit_Let(blindfolded, playerid);
	}
	return 1;
}

YCMD:smoke(playerid, params[], help) {
	
	if(!IsHuman(playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	if(Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_NONE || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_SITTING)
	{
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
	}
	else if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_SMOKE_CIGGY)
	{
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	}
	return 1;
}

YCMD:sprunk(playerid, params[], help) {
	if(!IsHuman(playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	if(Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_NONE || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_SITTING)
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_SPRUNK);
	else if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DRINK_SPRUNK)
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return 1;
}

YCMD:wine(playerid, params[], help) {
	if(!IsHuman(playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	if(Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_NONE || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_SITTING)
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_WINE);
	else if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DRINK_WINE)
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return 1;
}

YCMD:beer(playerid, params[], help) {
	if(!IsHuman(playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	if(Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_NONE || GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_SITTING)
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_BEER);
	else if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DRINK_BEER)
		SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
	return 1;
}

YCMD:time(playerid, params[], help) {
	if(!IsHuman(playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	if(Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	PlayerAction(playerid, "checks the time.");
	new c_time[3];
	gettime(c_time[0], c_time[1], c_time[2]);
	new string[128];
	format(string, sizeof string, "~w~~y~Time:~n~~w~%02d:%02d", c_time[0], c_time[1]);
	GameTextForPlayer(playerid, string, 3000, 1);
	return 1;
}

YCMD:skin(playerid, params[], help) {
	if(!IsHuman(playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	if(Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	SkinSelector(playerid);
	return 1;
}

YCMD:revive(playerid, params[], help) {
	if(Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(!IsHuman(playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /revive [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	if(!Group_GetPlayer(g_AdminDuty, playerid)) 
	{
		if(playerid == targetid)  return SCM(playerid, HEX_RED, "[Desolation]: You cannot revive yourself.");
		if(GetPlayerInterior(playerid) != GetPlayerInterior(targetid) && GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
		new Float:pos[3];
		GetPlayerPos(targetid, pos[0], pos[1], pos[2]);
		if(!IsPlayerInRangeOfPoint(playerid, 1.5, pos[0], pos[1], pos[2])) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
		if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
		if(!Bit_Get(dead, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is not dead.");
		if(Bit_Get(frozen, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player died and cannot be saved.");
		if(!HasPlayerItem(playerid, 47, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You need a Medical Case to revive this player.");
		RemovePlayerItem(playerid, 47, 1);
	}

	new string[128];
	format(string, sizeof string, "uses a Medical Case on %s.", PlayerName(targetid, false));
	PlayerHiddenAction(playerid, string);
	PlayerHiddenAction(targetid, "has been revived.");
	format(string, sizeof(string), "> %s has revived %s.", PlayerName(playerid,false),PlayerName(targetid,false));
	//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE, COLOR_PURPLE);
	ProxMSG(HEX_PURPLE, NAMETAG_DISTANCE, playerid, string);
	Bit_Vet(frozen, targetid);
	Bit_Vet(dead, targetid);
	DeletePVar(targetid, "deathtime");
	TogglePlayerControllable(targetid, true);
	ClearAnimations(targetid, 1);
	SetPlayerHealth(targetid, 41.0);
	Delete3DTextLabel(DamageLabel[targetid]);

	return 1;
}

YCMD:weapons(playerid, params[], help) {
	
	new weapons[13][2];
	new string[512], string2[128];
	new bool:match = false;
	for (new i = 0; i <= 12; i++) {
		GetPlayerWeaponData(playerid, i, weapons[i][0], weapons[i][1]);
		if(weapons[i][0] > 0) {
			format(string2, sizeof string2, "%s[%d]; ", DeathReason(weapons[i][0]), weapons[i][1]);
			strcat(string, string2);
			match = true;
		}
	}
	if(match) {
		SFM(playerid, HEX_FADE2, "%s's weapons:", PlayerName(playerid));
		SCM(playerid, HEX_FADE2, string);
	}
	else
		SFM(playerid, HEX_FADE2, "%s has no weapon.", PlayerName(playerid));
	return 1;
}

/*
YCMD:createscene(playerid, params[], help) {
	if(GetPVarInt(playerid, "3d_scene") > 0) return SCM(playerid, HEX_LRED, "Use /clearscene to remove your previous scene.");
	new string[144];
	if(sscanf(params, "s[144]", string)) return SCM(playerid, HEX_LRED, "Usage: /createscene [text]");
	new scene_str[256];
	format(scene_str, sizeof(scene_str), "%s (( %s ))", string, PlayerName(playerid));
	new Float:pPos[3];
	GetPlayerPos(playerid, pPos[0], pPos[1], pPos[2]);

	new Text3D:a = CreateDynamic3DTextLabel( scene_str, COLOR_PURPLE, pPos[0], pPos[1], pPos[2], 50.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), -1, STREAMER_3D_TEXT_LABEL_SD, -1, 0);
	SetPVarInt(playerid, "3d_scene", a);
	return 1;
}

YCMD:clearscene(playerid, params[], help) {
	if(IsValidDynamic3DTextLabel(GetPVarInt(playerid, "3d_scene"))) {
		DestroyDynamic3DTextLabel(GetPVarInt(playerid, "3d_scene"));
		SCM(playerid, HEX_FADE2, "Scene removed!");
	}
	else
		SCM(playerid, HEX_LRED, "You have not created a scene. You are free to use /createscene now.");
	DeletePVar(playerid, "3d_scene");
	return 1;
}*/


YCMD:levelup(playerid, params[], help) {
	++level[playerid];
	SFM(playerid, HEX_FADE2, "You have %d/%d experience points.", experience[playerid], 3*(level[playerid]*level[playerid])-(3*level[playerid]));
	--level[playerid];
	SCM(playerid, HEX_FADE2, "You will level up automatically.");
	return 1;
}

YCMD:rnumber(playerid, params[], help) {
	new n1, n2;
	if(sscanf(params, "dd", n1, n2)) return SCM(playerid, HEX_FADE2, "Usage: /rnumber [min] [max]");

	if(n1 < 0 || n2 < 0 || n2 == n1)
		return SCM(playerid, HEX_RED, "[Desolation]: Use positive different numbers.");

	if(n2 < n1) {
		new n3 = n2;
		n2 = n1;
		n1 = n3;
	}
	
	new result = random(n2-n1)+n1;
	new string[256];
	format(string, sizeof(string), "%s random number (from %d to %d): %d", PlayerName(playerid,true), n1, n2, result);
	//ProxDetector(NAMETAG_DISTANCE, playerid, string, COLOR_WHITE, COLOR_WHITE, COLOR_WHITE, COLOR_WHITE, COLOR_WHITE);
	ProxMSG(HEX_WHITE, NAMETAG_DISTANCE, playerid, string);
	return 1;
}

YCMD:stopaudio(playerid, params[], help) {
	StopAudioStreamForPlayer(playerid);
	return 1;
}


YCMD:pay(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new targetid, amount;
	if(sscanf(params, "dd",targetid, amount)) return SCM(playerid, HEX_FADE2, "Usage: /pay [id] [amount]");
	if(targetid == INVALID_PLAYER_ID) 
	{
		unformat(params, "ii", targetid, amount);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(targetid == playerid) return SCM(playerid, HEX_RED, "[Desolation]: You cannot pay yourself.");
	if(amount < 1) return SCM(playerid, HEX_RED, "[Desolation]: Invalid amount.");
	if(amount > cash[playerid]) return SCM(playerid, HEX_RED, "[Desolation]: You do not have enough cash.");
	if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	if(GetPlayerInterior(playerid) != GetPlayerInterior(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	new Float:p_pos[3];
	GetPlayerPos(targetid, p_pos[0], p_pos[1], p_pos[2]);
	if(!IsPlayerInRangeOfPoint(playerid, 5.0, p_pos[0], p_pos[1], p_pos[2]))  return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	if(!IsHuman(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: Your target is a zombie.");
	cash[playerid] -= amount;
	cash[targetid] += amount;

	GivePlayerMoney(playerid, amount*-1);
	GivePlayerMoney(targetid, amount);

	new string[256];
	format(string, sizeof string, "hands over money to %s.", PlayerName(targetid, false));
	PlayerAction(playerid, string);

	SavePlayer(playerid);
	SavePlayer(targetid);

	SFM(playerid, HEX_FADE2, "* You have paid %s $%d.", PlayerName(targetid, false), amount);
	SFM(targetid, HEX_FADE2, "* %s paid you $%d.", PlayerName(playerid, false), amount);

	format(string, sizeof string, "[MONEY]: %s[%d] has paid %s[%d] $%d. (Their sql data has been saved!)", PlayerName(playerid), playerid, PlayerName(targetid), targetid, amount);
	SendAdminMessage(HEX_YELLOW, string, true);

	return 1;
}

enum E_VENDING_MACHINE {
			e_Model,
			e_Interior,
	Float:e_PosX,
	Float:e_PosY,
	Float:e_PosZ,
	Float:e_RotX,
	Float:e_RotY,
	Float:e_RotZ,
	Float:e_FrontX,
	Float:e_FrontY
}

static const Float:sc_VendingMachines[][E_VENDING_MACHINE] = {
	{955, 0, -862.82, 1536.60, 21.98, 0.00, 0.00, 180.00, -862.84, 1537.60},
	{956, 0, 2271.72, -76.46, 25.96, 0.00, 0.00, 0.00, 2271.72, -77.46},
	{955, 0, 1277.83, 372.51, 18.95, 0.00, 0.00, 64.00, 1278.73, 372.07},
	{956, 0, 662.42, -552.16, 15.71, 0.00, 0.00, 180.00, 662.41, -551.16},
	{955, 0, 201.01, -107.61, 0.89, 0.00, 0.00, 270.00, 200.01, -107.63},
	{955, 0, -253.74, 2597.95, 62.24, 0.00, 0.00, 90.00, -252.74, 2597.95},
	{956, 0, -253.74, 2599.75, 62.24, 0.00, 0.00, 90.00, -252.74, 2599.75},
	{956, 0, -76.03, 1227.99, 19.12, 0.00, 0.00, 90.00, -75.03, 1227.99},
	{955, 0, -14.70, 1175.35, 18.95, 0.00, 0.00, 180.00, -14.72, 1176.35},
	{1977, 7, 316.87, -140.35, 998.58, 0.00, 0.00, 270.00, 315.87, -140.36},
	{1775, 17, 373.82, -178.14, 1000.73, 0.00, 0.00, 0.00, 373.82, -179.14},
	{1776, 17, 379.03, -178.88, 1000.73, 0.00, 0.00, 270.00, 378.03, -178.90},
	{1775, 17, 495.96, -24.32, 1000.73, 0.00, 0.00, 180.00, 495.95, -23.32},
	{1776, 17, 500.56, -1.36, 1000.73, 0.00, 0.00, 0.00, 500.56, -2.36},
	{1775, 17, 501.82, -1.42, 1000.73, 0.00, 0.00, 0.00, 501.82, -2.42},
	{956, 0, -1455.11, 2591.66, 55.23, 0.00, 0.00, 180.00, -1455.13, 2592.66},
	{955, 0, 2352.17, -1357.15, 23.77, 0.00, 0.00, 90.00, 2353.17, -1357.15},
	{955, 0, 2325.97, -1645.13, 14.21, 0.00, 0.00, 0.00, 2325.97, -1646.13},
	{956, 0, 2139.51, -1161.48, 23.35, 0.00, 0.00, 87.00, 2140.51, -1161.53},
	{956, 0, 2153.23, -1016.14, 62.23, 0.00, 0.00, 127.00, 2154.03, -1015.54},
	{955, 0, 1928.73, -1772.44, 12.94, 0.00, 0.00, 90.00, 1929.73, -1772.44},
	{1776, 1, 2222.36, 1602.64, 1000.06, 0.00, 0.00, 90.00, 2223.36, 1602.64},
	{1775, 1, 2222.20, 1606.77, 1000.05, 0.00, 0.00, 90.00, 2223.20, 1606.77},
	{1775, 1, 2155.90, 1606.77, 1000.05, 0.00, 0.00, 90.00, 2156.90, 1606.77},
	{1775, 1, 2209.90, 1607.19, 1000.05, 0.00, 0.00, 270.00, 2208.90, 1607.17},
	{1776, 1, 2155.84, 1607.87, 1000.06, 0.00, 0.00, 90.00, 2156.84, 1607.87},
	{1776, 1, 2202.45, 1617.00, 1000.06, 0.00, 0.00, 180.00, 2202.43, 1618.00},
	{1776, 1, 2209.24, 1621.21, 1000.06, 0.00, 0.00, 0.00, 2209.24, 1620.21},
	{1776, 3, 330.67, 178.50, 1020.07, 0.00, 0.00, 0.00, 330.67, 177.50},
	{1776, 3, 331.92, 178.50, 1020.07, 0.00, 0.00, 0.00, 331.92, 177.50},
	{1776, 3, 350.90, 206.08, 1008.47, 0.00, 0.00, 90.00, 351.90, 206.08},
	{1776, 3, 361.56, 158.61, 1008.47, 0.00, 0.00, 180.00, 361.54, 159.61},
	{1776, 3, 371.59, 178.45, 1020.07, 0.00, 0.00, 0.00, 371.59, 177.45},
	{1776, 3, 374.89, 188.97, 1008.47, 0.00, 0.00, 0.00, 374.89, 187.97},
	{1775, 2, 2576.70, -1284.43, 1061.09, 0.00, 0.00, 270.00, 2575.70, -1284.44},
	{1775, 15, 2225.20, -1153.42, 1025.90, 0.00, 0.00, 270.00, 2224.20, -1153.43},
	{955, 0, 1154.72, -1460.89, 15.15, 0.00, 0.00, 270.00, 1153.72, -1460.90},
	{956, 0, 2480.85, -1959.27, 12.96, 0.00, 0.00, 180.00, 2480.84, -1958.27},
	{955, 0, 2060.11, -1897.64, 12.92, 0.00, 0.00, 0.00, 2060.11, -1898.64},
	{955, 0, 1729.78, -1943.04, 12.94, 0.00, 0.00, 0.00, 1729.78, -1944.04},
	{956, 0, 1634.10, -2237.53, 12.89, 0.00, 0.00, 0.00, 1634.10, -2238.53},
	{955, 0, 1789.21, -1369.26, 15.16, 0.00, 0.00, 270.00, 1788.21, -1369.28},
	{956, 0, -2229.18, 286.41, 34.70, 0.00, 0.00, 180.00, -2229.20, 287.41},
	{955, 256, -1980.78, 142.66, 27.07, 0.00, 0.00, 270.00, -1981.78, 142.64},
	{955, 256, -2118.96, -423.64, 34.72, 0.00, 0.00, 255.00, -2119.93, -423.40},
	{955, 256, -2118.61, -422.41, 34.72, 0.00, 0.00, 255.00, -2119.58, -422.17},
	{955, 256, -2097.27, -398.33, 34.72, 0.00, 0.00, 180.00, -2097.29, -397.33},
	{955, 256, -2092.08, -490.05, 34.72, 0.00, 0.00, 0.00, -2092.08, -491.05},
	{955, 256, -2063.27, -490.05, 34.72, 0.00, 0.00, 0.00, -2063.27, -491.05},
	{955, 256, -2005.64, -490.05, 34.72, 0.00, 0.00, 0.00, -2005.64, -491.05},
	{955, 256, -2034.46, -490.05, 34.72, 0.00, 0.00, 0.00, -2034.46, -491.05},
	{955, 256, -2068.56, -398.33, 34.72, 0.00, 0.00, 180.00, -2068.58, -397.33},
	{955, 256, -2039.85, -398.33, 34.72, 0.00, 0.00, 180.00, -2039.86, -397.33},
	{955, 256, -2011.14, -398.33, 34.72, 0.00, 0.00, 180.00, -2011.15, -397.33},
	{955, 2048, -1350.11, 492.28, 10.58, 0.00, 0.00, 90.00, -1349.11, 492.28},
	{956, 2048, -1350.11, 493.85, 10.58, 0.00, 0.00, 90.00, -1349.11, 493.85},
	{955, 0, 2319.99, 2532.85, 10.21, 0.00, 0.00, 0.00, 2319.99, 2531.85},
	{956, 0, 2845.72, 1295.04, 10.78, 0.00, 0.00, 0.00, 2845.72, 1294.04},
	{955, 0, 2503.14, 1243.69, 10.21, 0.00, 0.00, 180.00, 2503.12, 1244.69},
	{956, 0, 2647.69, 1129.66, 10.21, 0.00, 0.00, 0.00, 2647.69, 1128.66},
	{1209, 0, -2420.21, 984.57, 44.29, 0.00, 0.00, 90.00, -2419.21, 984.57},
	{1302, 0, -2420.17, 985.94, 44.29, 0.00, 0.00, 90.00, -2419.17, 985.94},
	{955, 0, 2085.77, 2071.35, 10.45, 0.00, 0.00, 90.00, 2086.77, 2071.35},
	{956, 0, 1398.84, 2222.60, 10.42, 0.00, 0.00, 180.00, 1398.82, 2223.60},
	{956, 0, 1659.46, 1722.85, 10.21, 0.00, 0.00, 0.00, 1659.46, 1721.85},
	{955, 0, 1520.14, 1055.26, 10.00, 0.00, 0.00, 270.00, 1519.14, 1055.24},
	{1775, 6, -19.03, -57.83, 1003.63, 0.00, 0.00, 180.00, -19.05, -56.83},
	{1775, 18, -16.11, -91.64, 1003.63, 0.00, 0.00, 180.00, -16.13, -90.64},
	{1775, 16, -15.10, -140.22, 1003.63, 0.00, 0.00, 180.00, -15.11, -139.22},
	{1775, 17, -32.44, -186.69, 1003.63, 0.00, 0.00, 180.00, -32.46, -185.69},
	{1775, 16, -35.72, -140.22, 1003.63, 0.00, 0.00, 180.00, -35.74, -139.22},
	{1776, 6, -36.14, -57.87, 1003.63, 0.00, 0.00, 180.00, -36.16, -56.87},
	{1776, 18, -17.54, -91.71, 1003.63, 0.00, 0.00, 180.00, -17.56, -90.71},
	{1776, 16, -16.53, -140.29, 1003.63, 0.00, 0.00, 180.00, -16.54, -139.29},
	{1776, 17, -33.87, -186.76, 1003.63, 0.00, 0.00, 180.00, -33.89, -185.76}
};

stock RemoveDefaultVendingMachines(playerid) {
	RemoveBuildingForPlayer(playerid, 955, 0.0, 0.0, 0.0, 20000.0); // CJ_EXT_SPRUNK
	RemoveBuildingForPlayer(playerid, 956, 0.0, 0.0, 0.0, 20000.0); // CJ_EXT_CANDY
	RemoveBuildingForPlayer(playerid, 1209, 0.0, 0.0, 0.0, 20000.0); // vendmach
	RemoveBuildingForPlayer(playerid, 1302, 0.0, 0.0, 0.0, 20000.0); // vendmachfd
	RemoveBuildingForPlayer(playerid, 1775, 0.0, 0.0, 0.0, 20000.0); // CJ_SPRUNK1
	RemoveBuildingForPlayer(playerid, 1776, 0.0, 0.0, 0.0, 20000.0); // CJ_CANDYVENDOR
	RemoveBuildingForPlayer(playerid, 1977, 0.0, 0.0, 0.0, 20000.0); // vendin3

	// Make sure they're all gone..
	for (new i = 0; i < sizeof(sc_VendingMachines); i++) {
		RemoveBuildingForPlayer(
			playerid,
			sc_VendingMachines[i][e_Model],
			sc_VendingMachines[i][e_PosX],
			sc_VendingMachines[i][e_PosY],
			sc_VendingMachines[i][e_PosZ],
			1.0
		);
	}
	return 1;
}

SendRandomHintMessage(playerid) {
	if(level[playerid] < 3) {
		switch(random(7)) {
			case 0: SCM(playerid, HEX_FADE2, "Hint: You are recommended to relog after spending an hour.");
			case 1: SCM(playerid, HEX_FADE2, "Hint: Avoid zombies reaching you, because their infection slowly kills you.");
			case 2: SCM(playerid, HEX_FADE2, "Hint: Be nice to other players, so they will play with you again.");
			case 3: SCM(playerid, HEX_FADE2, "Hint: Most of the loots are inside enterable buildings. Crouch over an item and press 'N' to loot.");
			case 4: SCM(playerid, HEX_FADE2, "Hint: You can create your own faction on the forum: https://ds-rp.com");
			case 5: SCM(playerid, HEX_FADE2, "Hint: If you need more space to store your items you can have a safe. Check out /storagehelp for more info!");
			default: SCM(playerid, HEX_FADE2, "Hint: You can turn off hint messages with /toghints.");
		}
	}
	else {
		switch(random(7)) {
			case 0: SCM(playerid, HEX_FADE2, "Hint: You are recommended to relog after spending an hour.");
			case 1: SCM(playerid, HEX_FADE2, "Hint: Avoid zombies reaching you, because their infection slowly kills you.");
			case 2: SCM(playerid, HEX_FADE2, "Hint: Be nice to other players, so they will play with you again.");
			case 3: SCM(playerid, HEX_FADE2, "Hint: You can turn off territory marks and messages with /togzones.");
			case 4: SCM(playerid, HEX_FADE2, "Hint: You can create your own faction on the forum: https://ds-rp.com");
			case 5: SCM(playerid, HEX_FADE2, "Hint: If you need more space to store your items you can have safes. Check out /storagehelp for more info!");
			default: SCM(playerid, HEX_FADE2, "Hint: You can turn off hint messages with /toghints.");
		}
	}
	return 1;
}

YCMD:talkstyle(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	OpenTalkstyleSelector(playerid);
	return 1;
}

static const TalkStyles[][] =
{
	"None",
	"Normal",
	"Gang A",
	"Gang B",
	"Gang C",
	"Gang D",
	"Gang E",
	"Gang F",
	"Gang G",
	"Gang H"
};

OpenTalkstyleSelector(playerid) {

	new string[256];

	new i = -1;
	for(;++i<sizeof(TalkStyles);) {
		strcat(string, TalkStyles[i]);
		strcat(string, "\n");
	}

	inline selectTalkStyle(pid, dialogid, response, listitem, string:inputtext[]) {
		#pragma unused pid, dialogid, response, listitem, inputtext
		if(response) {
			if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
			if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");

			talkstyle[playerid] = listitem;

			SFM(playerid, HEX_FADE2, "Your talkstyle has been changed to style %s (%d).", TalkStyles[talkstyle[playerid]], talkstyle[playerid]);

			mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET talkstyle = %d WHERE id = %d LIMIT 1", talkstyle[playerid], CharacterSQL[playerid]);
			mysql_tquery(g_SQL, sql, "", "");

		}
	}
	Dialog_ShowCallback(playerid, using inline selectTalkStyle, DIALOG_STYLE_LIST, "Select your talkstyle", string, "Select", "Close");

	return 1;
}

YCMD:frisk(playerid, params[], help){
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
	if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	if(!SpamPrevent(playerid)) return 1;
	new targetid, string[256], Float:pos[3];
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /frisk [id]");
    if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	GetPlayerPos(targetid, pos[0],pos[1],pos[2]);
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, pos[0],pos[1],pos[2]) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");

	format(string, sizeof string, "frisks %s.", PlayerName(targetid, false));
	PlayerAction(playerid, string);

	mysql_format(g_SQL, sql, sizeof sql, "SELECT pi.*, il.name FROM `player_items` AS pi INNER JOIN `itemlist` AS il ON il.id = pi.itemId WHERE pi.state = 1 AND pi.playerId = %d LIMIT %d", CharacterSQL[targetid], MAX_INVENTORY_SLOTS);
	inline LoadInventoryData() {
		if(!cache_num_rows()) {
			SFM(playerid, HEX_FADE2, "%s's inventory is empty.", PlayerName(targetid, false));
			@return 1;
		}

		SFM(playerid,HEX_LORANGE,"%s's items:", PlayerName(targetid));
		new string2[2048];
		new tmp_return[32];
		new tmp_string[128], tmp_amount, i = -1;
		for(;++i<cache_num_rows();) {
			tmp_return = "ERROR";
			cache_get_value_int(i, "amount", tmp_amount);
			cache_get_value(i, "name", tmp_return, 32);
			
			if(tmp_amount > 1)
				format(tmp_string,sizeof(tmp_string),"[%i. %s (%i) ] ",i+1, tmp_return,tmp_amount);
			else
				format(tmp_string,sizeof(tmp_string),"[%i. %s ] ",i+1, tmp_return);
			strcat(string2,tmp_string);
			if(i%5==0 && i != 0) {
				SCM(playerid,HEX_WHITE,string);
				string2 = "";
			}
		}
		if(!IsPlayerConnected(playerid)) @return 1;
		if(strlen(string2)>0)
			SCM(playerid, HEX_WHITE, string2);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadInventoryData, sql);

	

	return 1;
}

YCMD:description(playerid, params[], help) {

	if(!SpamPrevent(playerid)) return 1;
	new string[256];
	if(sscanf(params, "s[128]", string)) return SCM(playerid, HEX_FADE2, "Usage: /description [text] (Hint: Others will see this text - used as character description - if they use /examine)");

	if(strlen(string) < 4) return SCM(playerid, HEX_RED, "Your description must be at least 4 characters long. (Hint: Use /examine to check someone's character description.)");

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `description` = '%e' WHERE id = %d", string, CharacterSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");

	SFM(playerid, HEX_YELLOW, "You set your character description to '%s'.", string);

	new sendText[256];
	format(sendText, sizeof sendText, "AdmWarn: %s[%d] has set their character description to '%s'.", PlayerName(playerid), playerid, string);
	SendAdminMessage(HEX_LRED, sendText, true);

	return 1;
}


YCMD:examine(playerid, params[], help) {

	if(!SpamPrevent(playerid)) return 1;
	new targetid;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /examine [id]");
    if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	mysql_format(g_SQL, sql, sizeof sql, "SELECT description FROM `player` WHERE state = 1 AND id = %d LIMIT 1", CharacterSQL[targetid]);
	inline LoadPlayerDesc() {
		if(!cache_num_rows()) {
			SFM(playerid, HEX_FADE2, "%s's description is empty.", PlayerName(targetid, false));
			@return 1;
		}

		new string[128];
		cache_get_value(0, "description", string, 128);

		if(!IsPlayerConnected(playerid)) @return 1;
		
		SFM(playerid, HEX_FADE2, "%s's description: %s", PlayerName(targetid, false), string);

		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadPlayerDesc, sql);

	return 1;
}

YCMD:grantkey(playerid, params[], help) {

	SCM(playerid, HEX_FADE2, "Use /grantdoorkey or /grantsafekey.");

	return 1;
}