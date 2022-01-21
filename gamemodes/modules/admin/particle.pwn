#include <YSI_Coding\y_hooks>

enum ParticlesEnum {
	sqlid,
	ParticleObject,
	ownerid,
	ParticleVW,
	ParticleInt,
	Float:ParticlePos[3]
}
new ParticleInfo[MAX_ADMIN_PARTICLES][ParticlesEnum];
new Iterator:ParticleLoop<MAX_ADMIN_PARTICLES>;

enum ParticleListEnum {
	ParticleID,
	ParticleName[32]
}

new ParticleList[22][ParticleListEnum] = {
	{18688,"fire"},
	{18689,"fire_bike"},
	{18690,"fire_car"},
	{18691,"fire_large"},
	{18692,"fire_med"},
	{18693,"Flame99"},
	{18703,"overheat_car"},
	{18704,"overheat_car_elec"},
	{18723,"riot_smoke"},
	{18725,"smoke30lit"},
	{18727,"smoke50lit"},
	{18728,"smoke_flare"},
	{18748,"WS_factorysmoke"},
	{1437,"DYN_LADDER_2"},
	{1428,"DYN_LADDER"},
	{1438,"DYN_BOX_PILE_2"},
	{19632,"FireWood1"},
	{1442,"DYN_FIREBIN"},
	{1463,"DYN_WOODPILE2"},
	{18740,"water_hydrant"},
	{-2000,"Military tent"},
	{-2004,"Sandbag Barricade"}
};

new SelectParticle[MAX_PLAYERS];

GetLastParticle() {
	new idx = Iter_Free(ParticleLoop);
	if(idx == INVALID_ITERATOR_SLOT) {
		return -1;
	}
	return idx;
}


hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) {

	if(!Group_GetPlayer(g_AdminDuty, playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
	if(GetPlayerWeapon(playerid) != 23) return Y_HOOKS_CONTINUE_RETURN_1;
	if(SelectParticle[playerid] == 0) return Y_HOOKS_CONTINUE_RETURN_1;

	new idx=GetLastParticle();
	if(!(-1 < idx <= MAX_ADMIN_PARTICLES)) return SCM(playerid, HEX_RED, "The server has reached the maximum particle capacity.");

	static Float:tmp;
	GetPlayerLastShotVectors(playerid, tmp, tmp, tmp, fX, fY, fZ);
	
	if(fX == 0)
		GetPlayerPos(playerid, fX, fY, fZ);

	ParticleInfo[idx][sqlid] = CreateDynamicObject(SelectParticle[playerid], fX, fY, fZ, 0.0, 0.0, 0.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
	ParticleInfo[idx][ParticlePos][0] = fX;
	ParticleInfo[idx][ParticlePos][1] = fY;
	ParticleInfo[idx][ParticlePos][2] = fZ;
	ParticleInfo[idx][ParticleVW] = GetPlayerVirtualWorld(playerid);
	ParticleInfo[idx][ParticleInt] = GetPlayerInterior(playerid);
	ParticleInfo[idx][ownerid] = CharacterSQL[playerid];
	ParticleInfo[idx][ParticleObject] = SelectParticle[playerid];
	SelectParticle[playerid] = ParticleInfo[idx][sqlid];
	EditDynamicObject(playerid, ParticleInfo[idx][sqlid]);
	SelectParticle[playerid] = 0;
	
	Iter_Add(ParticleLoop, idx);
	RemovePlayerWeapon(playerid, 23);

	new string[256];
	format(string, sizeof string, "[LOG]: %s %s has created a particle. (It will disappear when the server restarts.)", AdminNames[adminlevel[playerid]], PlayerName(playerid));
	SendAdminMessage(HEX_YELLOW, string, true);
	
	return Y_HOOKS_BREAK_RETURN_0;
}

hook OnPlayerDisconnect(playerid, reason) {
	SelectParticle[playerid] = 0;
	return Y_HOOKS_CONTINUE_RETURN_1; 
}

hook OnPlayerEditDynObject(playerid, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ) {
	if(objectid!=ParticleInfo[SelectParticle[playerid]][sqlid]) return Y_HOOKS_CONTINUE_RETURN_1;
	switch(response) {
		case EDIT_RESPONSE_FINAL: {
			ParticleInfo[SelectParticle[playerid]][ParticlePos][0] = fX;
			ParticleInfo[SelectParticle[playerid]][ParticlePos][1] = fY;
			ParticleInfo[SelectParticle[playerid]][ParticlePos][2] = fZ;
			//MoveDynamicObject(objectid, fX, fY, fZ, 20.0, fRotX, fRotY, fRotZ);
			SetDynamicObjectPos(objectid, fX, fY, fZ);
			SetDynamicObjectRot(objectid, fRotX, fRotY, fRotZ);
		}
		case EDIT_RESPONSE_CANCEL: {
			Iter_Remove(ParticleLoop, SelectParticle[playerid]);
			DestroyDynamicObject(objectid);
			new CLEAR_ARRAY[ParticlesEnum];
			ParticleInfo[SelectParticle[playerid]] = CLEAR_ARRAY;
		}
	}
	SelectParticle[playerid] = 0;
	return Y_HOOKS_BREAK_RETURN_0;
}



YCMD:particle(playerid,params[],help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new parameter[16];
	if(sscanf(params,"s[16]{}",parameter)||!strlen(parameter)) return SCM(playerid, HEX_FADE2, "Usage: /particle [new, id, remove]");
	if(!strcmp(parameter,"new")) {
		new i=-1,body[512],line[64];
		for(;++i<sizeof(ParticleList);) {
			format(line, sizeof(line), "%i\t%s\n", ParticleList[i][ParticleID], ParticleList[i][ParticleName]);
			strcat(body, line);
		}
		inline Dialog_ShowParticleGun(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
			#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
			if(Open_response) {
				SelectParticle[Open_pid] = ParticleList[Open_listitem][ParticleID];
				GivePlayerWeapon(Open_pid, WEAPON_SILENCED, 1);
				SCM(Open_pid, HEX_FADE2, "You have equipped the particle gun.");
			}
		}	
		Dialog_ShowCallback(playerid, using inline Dialog_ShowParticleGun, DIALOG_STYLE_TABLIST, "{FFFFFF}Particle selection", body,"Select","Cancel");
		return 1;
	}
	if(!strcmp(parameter,"id")) {
		foreach(new i:ParticleLoop) {
			if(IsPlayerInRangeOfPoint(playerid, 8.0, ParticleInfo[i][ParticlePos][0], ParticleInfo[i][ParticlePos][1], ParticleInfo[i][ParticlePos][2]) && 
			GetPlayerInterior(playerid) == ParticleInfo[i][ParticleInt] && GetPlayerVirtualWorld(playerid) == ParticleInfo[i][ParticleVW]) {
				SFM(playerid, HEX_WHITE, "The closest particle id: %i (Object ID: %i Name: %s)", i, ParticleInfo[i][ParticleObject], GetSQLCharname(ParticleInfo[i][ownerid]));
				return 1;
			}
		}
		SCM(playerid, HEX_LRED, "There is no particle nearby! (range 8.0)");
		return 1;
	}
	if(!strcmp(parameter,"remove")) {
		new deleteid;
		if(sscanf(params,"{s[16]}i", deleteid) || deleteid<0 || deleteid>MAX_ADMIN_PARTICLES) return SCM(playerid, HEX_LRED, "Usage: /particle remove [particle id] (/particle id)");
		if(ParticleInfo[deleteid][ParticleObject]==0) return SCM(playerid, HEX_LRED, "No particle found!");
		Iter_Remove(ParticleLoop, deleteid);
		if(ParticleInfo[deleteid][sqlid]!=0) {
			DestroyDynamicObject(ParticleInfo[deleteid][sqlid]);
		}
		/* clear array */
		new CLEAR_ARRAY[ParticlesEnum];
		ParticleInfo[deleteid] = CLEAR_ARRAY;
		/* clear array */
		SFM(playerid, HEX_LRED, "You have removed particle id %i.", deleteid);
		return 1;
	}
	return 1;
}