#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

	if((newkeys & KEY_YES) && !(oldkeys & KEY_YES)) {

		if(GetPlayerVehicleSeat(playerid) == 0)
			return Y_HOOKS_CONTINUE_RETURN_1;

		new wepid = GetPlayerWeapon(playerid);
		if(wepid < 22 || wepid > 37) {
			wepid = GetPVarInt(playerid, "wepid");
			SetPlayerArmedWeapon(playerid, wepid);
			if(GetPlayerAmmo(playerid) > 0) {
				SCM(playerid, HEX_RED, "Error: You must select your weapon.");
				return Y_HOOKS_CONTINUE_RETURN_1;
			}
		}
		if(wepid < 22 || wepid > 37) {
			return Y_HOOKS_CONTINUE_RETURN_1;
		}

		ReloadGun(playerid, wepid);
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) {

	SetPVarInt(playerid, "wepid", weaponid);

	return Y_HOOKS_CONTINUE_RETURN_1;
}

ReloadGun(playerid, weaponid) {

	if(Bit_Get(dead, playerid)) {
		SCM(playerid, HEX_RED, "Error: You cannot reload your weapon now.");
		return 0;
	}
	if(!IsHuman(playerid)) {
		return 0;
	}

	if(Bit_Get(frozen, playerid)) {
		return 0;
	}
	if(IsPlayerInAnyVehicle(playerid) && GetPlayerVehicleSeat(playerid) == 0) {
		return 0;
	}

	new ammoitem = GetAmmoItemFromWeaponid(weaponid);
	if(!ammoitem) return 0;

	new ammoamount = CountPlayerItem(playerid, ammoitem, false);
	new defamount = WeaponAmmo(weaponid);
	if(GetPlayerAmmo(playerid) >= defamount) return 0;
	if(ammoamount < 1) return SCM(playerid, HEX_YELLOW, "No matching ammo.");
	if(ammoamount > defamount) {
		ammoamount = defamount - GetPlayerAmmo(playerid);
	}

	RemovePlayerItem(playerid, ammoitem, ammoamount);

	GivePlayerWeapon(playerid, weaponid, ammoamount);
	SetPlayerArmedWeapon(playerid, weaponid);

	defer ActualizeWeaponAmmo(playerid, weaponid);

	ApplyAnimation(playerid, "PYTHON", "python_reload", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "reloads.");

	return 1;
}

timer ActualizeWeaponAmmo[250](playerid, weaponid) {

	if(IsPlayerConnected(playerid)) {
		SetPlayerArmedWeapon(playerid, weaponid);
		if(weaponid == p_weapon[playerid][0]) {
			p_ammos[playerid][0] = GetPlayerAmmo(playerid);
		}
		else if(weaponid == p_weapon[playerid][1]) {
			p_ammos[playerid][1] = GetPlayerAmmo(playerid);
		}
		else if(weaponid == p_weapon[playerid][2]) {
			p_ammos[playerid][2] = GetPlayerAmmo(playerid);
		}	
	}
}