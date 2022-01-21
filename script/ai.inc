/*#if defined _inc_ai
	#undef _inc_ai
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

#define AI_MODE_HOSTILE 3
#define AI_MODE_NEUTRAL 2
#define AI_MODE_FRIENDLY 1
#define IN_ZOMBIE_SIGHT 19.5
//#define IN_SHOOTING_SIGHT 30.0
#define IN_SHOOTING_SIGHT 35.0
#define DISTANCE_CHECK_TIMER 2000

forward AI_OnPlayerApproachNPC(playerid, npcid, Float:distance = IN_SHOOTING_SIGHT);
//new Timer:AI_DistTimer[420][420] = {Timer:-1, ...};

hook OnGameModeInit() {
	//MapAndreas_Init(MAP_ANDREAS_MODE_FULL);
	//FCNPC_UseMoveMode(FCNPC_MOVE_MODE_COLANDREAS);
	FCNPC_UseMovePathfinding(FCNPC_MOVE_PATHFINDING_RAYCAST);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

AI_SetReaction(npcid, AI_MODE) {
	if(IsPlayerNPC(npcid)) {
		SetPVarInt(npcid, "react", AI_MODE);
		return 1;
	}
	return 0;
}

AI_GetReaction(npcid) {
	new returnval = GetPVarInt(npcid,  "react");
	return returnval;
}

stock IsFactionAI(playerid, npcid) {
	//if player faction == npc faction return 1
	//else
		return 0;
}

/*hook FCNPC_OnStreamIn(npcid, forplayerid) {
	//SFM(forplayerid, HEX_FADE2, "DEBUG FCNPC_OnStreamIn(npcid %d, forplayerid %d)", npcid, forplayerid);
	AI_DistTimer[forplayerid][npcid] = repeat AI_OnDistancecheck(forplayerid, npcid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}*/

/*hook FCNPC_OnStreamOut(npcid, forplayerid) {
	stop AI_DistTimer[forplayerid][npcid];
	//printf("DEBUG FCNPC_OnStreamOut(npcid %d, forplayerid %d)", npcid, forplayerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}*/



/*timer AI_OnDistancecheck[DISTANCE_CHECK_TIMER](playerid, npcid) {
	if(!IsPlayerNPC(npcid) || !IsPlayerConnected(playerid))
		stop AI_DistTimer[playerid][npcid];
	else {
		new Float:pos[3];
		FCNPC_GetPosition(npcid, pos[0], pos[1], pos[2]);
		if(GetPlayerDistanceFromPoint(playerid, pos[0], pos[1], pos[2]) < IN_SHOOTING_SIGHT) {
			CallRemoteFunction("AI_OnPlayerApproachNPC", "dd", playerid, npcid);
			stop AI_DistTimer[playerid][npcid];
		}
	}
}*/

Float:CalculateCrouch(playerid) {

	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_DUCK) return 5.0;
	return 0.0;
}

task AI_OnDistancecheck[AI_CHECK_TIME]() {
	new Float:pos[3];
	
	foreach(new i:GroupMember[npc_Zombie]) {

		if(!FCNPC_IsDead(i)) {

			foreach(new j:Player) {

				if(GetPlayerState(j) != PLAYER_STATE_SPECTATING && !Bit_Get(dead, j)) {
					
					FCNPC_GetPosition(i, pos[0], pos[1], pos[2]);
					if(IsZombie(i)) {
						if(GetPlayerDistanceFromPoint(j, pos[0], pos[1], pos[2]) < (IN_ZOMBIE_SIGHT - CalculateCrouch(j))) {
							CallRemoteFunction("AI_OnPlayerApproachNPC", "dd", j, i);
						}
					}
					else if(GetPlayerDistanceFromPoint(j, pos[0], pos[1], pos[2]) < (IN_SHOOTING_SIGHT - CalculateCrouch(j))) {
						CallRemoteFunction("AI_OnPlayerApproachNPC", "dd", j, i);
					}

				}

			}
		}
	}


	foreach(new k:GroupMember[npc_a51]) {

		if(!FCNPC_IsDead(k)) {

			foreach(new l:Player) {

				if(GetPlayerState(l) != PLAYER_STATE_SPECTATING && !Bit_Get(dead, l)) {
					
					FCNPC_GetPosition(k, pos[0], pos[1], pos[2]);
					if(IsZombie(k)) {
						if(GetPlayerDistanceFromPoint(l, pos[0], pos[1], pos[2]) < (IN_ZOMBIE_SIGHT - CalculateCrouch(l))) {
							CallRemoteFunction("AI_OnPlayerApproachNPC", "dd", l, k);
						}
					}
					else if(GetPlayerDistanceFromPoint(l, pos[0], pos[1], pos[2]) < (IN_SHOOTING_SIGHT - CalculateCrouch(l))) {
						CallRemoteFunction("AI_OnPlayerApproachNPC", "dd", l, k);
					}

				}

			}

		}

	}

}

/*timer AI_OnDistancecheck[DISTANCE_CHECK_TIMER](playerid, npcid) {
	printf("AI_OnDistancecheck playerid %d, npcid %d", playerid, npcid);
	if(!IsPlayerNPC(npcid) || !IsPlayerConnected(playerid) || IsPlayerNPC(playerid)) {
		stop AI_DistTimer[playerid][npcid];
	}

	else if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING) {
		new Float:pos[3];
		FCNPC_GetPosition(npcid, pos[0], pos[1], pos[2]);
		if(IsZombie(npcid)) {
			if(GetPlayerDistanceFromPoint(playerid, pos[0], pos[1], pos[2]) < IN_ZOMBIE_SIGHT) {
				CallRemoteFunction("AI_OnPlayerApproachNPC", "dd", playerid, npcid);
				stop AI_DistTimer[playerid][npcid];
			}
		}
		else if(GetPlayerDistanceFromPoint(playerid, pos[0], pos[1], pos[2]) < IN_SHOOTING_SIGHT) {
			CallRemoteFunction("AI_OnPlayerApproachNPC", "dd", playerid, npcid);
			stop AI_DistTimer[playerid][npcid];
		}
	}
}*/

hook FCNPC_OnTakeDamage(npcid, issuerid, Float:amount, weaponid, bodypart) {

	if(IsPlayerNPC(issuerid) && IsPlayerNPC(npcid)) {
		if(Group_GetPlayer(npc_a51, npcid) && Group_GetPlayer(npc_a51, issuerid) || Group_GetPlayer(npc_Zombie, npcid) && Group_GetPlayer(npc_Zombie, issuerid))
			FCNPC_StopAim(issuerid);
	}
	else if(AI_GetReaction(npcid) == AI_MODE_HOSTILE || AI_GetReaction(npcid) == AI_MODE_NEUTRAL) {
		AI_Attack(npcid, issuerid);
		AI_Helpcheck(npcid, issuerid);
	}


	DamageNPC(npcid, weaponid);

	return Y_HOOKS_CONTINUE_RETURN_1;
}


AI_Attack(npcid, playerid) {
	if(FCNPC_GetWeapon(npcid) > 0) {
		FCNPC_Stop(npcid);
		FCNPC_StopAim(npcid);
		FCNPC_AimAtPlayer(npcid, playerid, true, -1, true);		
		SetPVarInt(npcid, "aim", playerid);
	}

	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason) {
	if(IsPlayerNPC(killerid)) {
		FCNPC_StopAim(killerid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1; 
}

hook OnGameModeExit() {
	foreach (new npcid : FCNPC) {
		FCNPC_Destroy(npcid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}