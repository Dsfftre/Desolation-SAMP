#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	
	CreateDynamicObject(-2003, 2501.51563, 2781.28906, 9.82030,   0.00000, 0.00000, 0.00000); // textured gates

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {

	RemoveBuildingForPlayer(playerid, 7023, 2501.5156, 2781.2891, 9.8203, 0.25);

	return Y_HOOKS_CONTINUE_RETURN_1;
}