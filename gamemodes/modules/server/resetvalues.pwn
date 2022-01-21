/*#if defined _inc_ai
	#undef _inc_ai
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason) {
    EmptyPlayerVariables(playerid);
    AccountSQL[playerid] = 0;
    Bit_Vet(loggedin, playerid);
    accountname[playerid] = "";
    adminlevel[playerid] = 0;
    return Y_HOOKS_CONTINUE_RETURN_1;
}

EmptyPlayerVariables(playerid) {
    CharacterSQL[playerid] = 0;
    faction[playerid] = 0;
    factionrank[playerid] = "";
    //MiningOre[playerid] = false;
    count_infest[playerid] = 0;
    level[playerid] = 0;
    experience[playerid] = 0;
    minutes[playerid] = 0;
    cash[playerid] = 0;
    p_skin[playerid] = 0;
    Delete3DTextLabel(DamageLabel[playerid]);
    DestroyPlayerProgressBar(playerid, thirstbar[playerid]);
    DestroyPlayerProgressBar(playerid, hungerbar[playerid]);
    Bit_Vet(character, playerid);
    Bit_Vet(blindfolded, playerid);
    Bit_Vet(masked, playerid);
    Bit_Vet(spectating, playerid);
	Bit_Vet(dead, playerid);
	Bit_Vet(frozen, playerid);
	Bit_Vet(inanim, playerid);
	Bit_Vet(ContestedArea, playerid);
	Bit_Let(tutorial, playerid);
	Bit_Vet(togsjoin, playerid);
    Bit_Vet(togsnpchp, playerid);
    Bit_Let(togshud, playerid);
	Bit_Vet(factionleader, playerid);
	Bit_Vet(factionowner, playerid);
	Bit_Vet(radiation, playerid);
    Bit_Vet(deathspawn, playerid);
    Bit_Vet(infected, playerid);
    return 1;
}