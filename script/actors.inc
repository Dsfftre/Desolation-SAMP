/*#if defined _inc_actors
	#undef _inc_actors
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

#define ACTOR_RESPAWNTIME 150000

hook OnGameModeInit() {
	LoadActors();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadActors() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `actor` WHERE state > 0 LIMIT %d", MAX_ACTORS);
	inline LoadActorData() 
	{
		if(!cache_num_rows()) 
		{
			print("No actors found.");
			@return 0;
		}
		new i = -1;
		enum actorInfoEnum {
			id,
			Float:posx,
			Float:posy,
			Float:posz,
			Float:posf,
			skin,
			a_virtualworld,
			animlib[12],
			animname[23],
			loopanim,
			animtime,
			animfreeze,
			lockx,
			locky
		}
		new actorInfo[actorInfoEnum];
		for(;++i<cache_num_rows();) 
		{
			cache_get_value_float(i, "posx", actorInfo[posx]);
			cache_get_value_float(i, "posy", actorInfo[posy]);
			cache_get_value_float(i, "posz", actorInfo[posz]);
			cache_get_value_float(i, "posf", actorInfo[posf]);
			cache_get_value_int(i, "skin", actorInfo[skin]);
			cache_get_value_int(i, "virtualworld", actorInfo[a_virtualworld]);
			cache_get_value(i, "animlib", actorInfo[animlib], 12);
			cache_get_value(i, "animname", actorInfo[animname], 23);
			cache_get_value_int(i, "loopanim", actorInfo[loopanim]);
			cache_get_value_int(i, "animtime", actorInfo[animtime]);
			cache_get_value_int(i, "animfreeze", actorInfo[animfreeze]);
			cache_get_value_int(i, "lockx", actorInfo[lockx]);
			cache_get_value_int(i, "locky", actorInfo[locky]);
			actorInfo[id] = CreateActor(actorInfo[skin], actorInfo[posx], actorInfo[posy], actorInfo[posz], actorInfo[posf]);
			SetActorInvulnerable(actorInfo[id], false);
			SetActorVirtualWorld(actorInfo[id], actorInfo[a_virtualworld]);
			if(strlen(actorInfo[animlib]) > 2) 
			{
				ApplyActorAnimation(actorInfo[id], actorInfo[animlib], actorInfo[animname], 4.1, actorInfo[loopanim], actorInfo[lockx], actorInfo[locky], actorInfo[animfreeze], actorInfo[animtime]);
				ApplyActorAnimation(actorInfo[id], actorInfo[animlib], actorInfo[animname], 4.1, actorInfo[loopanim], actorInfo[lockx], actorInfo[locky], actorInfo[animfreeze], actorInfo[animtime]);
			}


		}
		printf("%d actors loaded.", i);
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadActorData, sql);
	return 1;
}


YCMD:addactor(playerid, params[], help) {
	new Float:pos[4],
		actorskin,
		vw;

    if(sscanf(params,"i", actorskin)) return SCM(playerid, HEX_FADE2, "Usage: /addactor [skinid]");
    if(actorskin > 311 || actorskin < 0) return SCM(playerid, HEX_RED, "Error: Invalid skin id.");

	vw = GetPlayerVirtualWorld(playerid);

    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
    GetPlayerFacingAngle(playerid, pos[3]);
	CreateDynamicActor(actorskin, pos[0], pos[1], pos[2], pos[3], 0, 100.0, vw, -1);

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `actor` (`posx`, `posy`, `posz`, `posf`, `skin`, `virtualworld`) VALUES ('%f', '%f', '%f', '%f', '%d', '%d')",  pos[0], pos[1], pos[2], pos[3], actorskin, vw);
	mysql_tquery(g_SQL, sql, "", "");	

	return 1;
}

hook OnPlayerGiveDamageActor(playerid, damaged_actorid, Float:amount, weaponid, bodypart) {
	if(!IsPlayerNPC(playerid)) 
	{
		new Float:actorhp;
		GetActorHealth(damaged_actorid, actorhp);
		if(actorhp != 99.7654) 
		{
			SetActorHealth(damaged_actorid, 99.7654);
			ActorDeathAnimation(damaged_actorid);
			SetActorInvulnerable(damaged_actorid, true);
			defer ReviveActor(damaged_actorid);
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

timer ReviveActor[ACTOR_RESPAWNTIME](actorid) {
	SetActorHealth(actorid, 100.0);
	ClearActorAnimations(actorid);
	SetActorInvulnerable(actorid, false);
}
/*
#define ACTOR_AIMCHECK_TIMER 2500
ptask ACTOR_AIM_HANDSUP[ACTOR_AIMCHECK_TIMER](playerid) {
	if(GetPlayerTargetActor(playerid) != INVALID_ACTOR_ID) {
		new Float:pos[3],
			target = GetPlayerTargetActor(playerid);
		GetActorPos(target, pos[0], pos[1], pos[2]);
		if(GetPlayerDistanceFromPoint(playerid, pos[0], pos[1], pos[2]) < 5.0) {
			ApplyActorAnimation(target, "SHOP", "SHP_Rob_HandsUp", 4.1, 1, 0, 0, 0, 0);
			defer ClearActorAnim[3000+random(6000)](target);
		}
	}
}

timer ClearActorAnim[5000](actorid) {
	ClearActorAnimations(actorid);
}*/