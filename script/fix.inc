
#include <YSI_Coding\y_hooks>
/*
hook OnGameModeInit() {

	return Y_HOOKS_CONTINUE_RETURN_1;
}*/
/*
hook  OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

	if (FIXES_gsSettings & e_FIXES_SETTINGS_IN_CHARGE) {
		if ((newkeys & KEY_CROUCH) && !(oldkeys & KEY_CROUCH) && GetPlayerState (playerid) == PLAYER_STATE_PASSENGER && GetPlayerCameraMode(playerid) == 55 && !(FIXES_gsPlayerBools[playerid])) {
			_FIXES_HideDriveByWeapon(playerid);
		}
	}


	return Y_HOOKS_CONTINUE_RETURN_1;
}

static stock _FIXES_HideDriveByWeapon(playerid) {
	FIXES_gsDriveByWeapon[playerid] = GetPlayerWeapon__(playerid),
	FIXES_gsPlayerBools[playerid] |= e_FIXES_BOOLS_DRIVE_BY,
	SetPlayerArmedWeapon__(playerid, 0),
	ApplyAnimation__(playerid, "PED", "CAR_GETIN_RHS", 4.1, 0, 0, 0, 0, 1, 1),
	SetTimerEx__(FIXES_gscDriveBy, 500, 0, FIXES_gscSpec@i, playerid);
}*/


/*
0	PLAYER_STATE_NONE	Empty (while initializing)
1	PLAYER_STATE_ONFOOT	Player is on foot
2	PLAYER_STATE_DRIVER	Player is the driver of a vehicle
3	PLAYER_STATE_PASSENGER	Player is passenger of a vehicle
4	PLAYER_STATE_EXIT_VEHICLE	Player exits a vehicle
5	PLAYER_STATE_ENTER_VEHICLE_DRIVER	Player enters a vehicle as driver
6	PLAYER_STATE_ENTER_VEHICLE_PASSENGER	Player enters a vehicle as passenger
7	PLAYER_STATE_WASTED	Player is dead or on class selection
8	PLAYER_STATE_SPAWNED	Player is spawned
9	PLAYER_STATE_SPECTATING
 */
/*
static const pstates[][] = {
	"PLAYER_STATE_NONE",
	"PLAYER_STATE_ONFOOT",
	"PLAYER_STATE_DRIVER",
	"PLAYER_STATE_PASSENGER",
	"PLAYER_STATE_EXIT_VEHICLE",
	"PLAYER_STATE_ENTER_VEHICLE_DRIVER",
	"PLAYER_STATE_ENTER_VEHICLE_PASSENGER",
	"PLAYER_STATE_WASTED",
	"PLAYER_STATE_SPAWNED",
	"PLAYER_STATE_SPECTATING"
};*/
/*
hook OnPlayerStateChange(playerid, newstate, oldstate) {
    
	SFM(playerid, HEX_FADE2, "debug state changed from %s to %s", pstates[oldstate], pstates[newstate]);

    return Y_HOOKS_CONTINUE_RETURN_1;
}*/