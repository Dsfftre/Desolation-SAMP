#include <YSI_Coding\y_hooks>

GetWeaponModel(weaponid) {
	switch(weaponid) {
	    case 1:
	        return 331;

		case 2..8:
		    return weaponid+331;

        case 9:
		    return 341;

		case 10..15:
			return weaponid+311;

		case 16..18:
		    return weaponid+326;

		case 22..29:
		    return weaponid+324;

		case 30,31:
		    return weaponid+325;

		case 32:
		    return 372;

		case 33..45:
		    return weaponid+324;

		case 46:
		    return 371;
	}
	return 0;
}

IsHiddenWeapon(weaponid) {
	switch(weaponid) {
		case 0..1: return true;
		case 4: return true;
		case 10..13: return true;
		case 16..18: return true;
		case 22: return true;
		case 40..46: return true;
	}

	return false;
}


hook OnPlayerSlowUpdate(playerid) {

	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;

	new weaponid[13],weaponammo[13],pArmedWeapon;
	pArmedWeapon = GetPlayerWeapon(playerid);
	GetPlayerWeaponData(playerid,1,weaponid[1],weaponammo[1]);
	GetPlayerWeaponData(playerid,2,weaponid[2],weaponammo[2]);
	GetPlayerWeaponData(playerid,3,weaponid[3],weaponammo[3]);
	GetPlayerWeaponData(playerid,4,weaponid[4],weaponammo[4]);
	GetPlayerWeaponData(playerid,5,weaponid[5],weaponammo[5]);
	GetPlayerWeaponData(playerid,6,weaponid[6],weaponammo[6]);
	GetPlayerWeaponData(playerid,7,weaponid[7],weaponammo[7]);

	

	if(weaponid[1] && weaponammo[1] > 0){
		if(pArmedWeapon != weaponid[1] && !IsHiddenWeapon(weaponid[1])){
			if(!IsPlayerAttachedObjectSlotUsed(playerid,0)){
				SetPlayerAttachedObject(playerid,0,GetWeaponModel(weaponid[1]),1, 0.199999, -0.139999, 0.030000, 0.500007, -115.000000, 0.000000, 1.000000, 1.000000, 1.000000);
			}
		}
		else {
			if(IsPlayerAttachedObjectSlotUsed(playerid,0)){
				RemovePlayerAttachedObject(playerid,0);
			}
		}
	}
	else if(IsPlayerAttachedObjectSlotUsed(playerid,0)){
		RemovePlayerAttachedObject(playerid,0);
	}
	
	if(weaponid[2] && weaponammo[2] > 0){
		if(pArmedWeapon != weaponid[2] && !IsHiddenWeapon(weaponid[2])){
			if(!IsPlayerAttachedObjectSlotUsed(playerid,1)){
				SetPlayerAttachedObject(playerid,1,GetWeaponModel(weaponid[2]),8, -0.079999, -0.039999, 0.109999, -90.100006, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
			}
		}
		else {
			if(IsPlayerAttachedObjectSlotUsed(playerid,1)){
				RemovePlayerAttachedObject(playerid,1);
			}
		}
	}
	else if(IsPlayerAttachedObjectSlotUsed(playerid,1)){
		RemovePlayerAttachedObject(playerid,1);
	}
	if(weaponid[4] && weaponammo[4] > 0){
		if(pArmedWeapon != weaponid[4] && !IsHiddenWeapon(weaponid[4])){
			if(!IsPlayerAttachedObjectSlotUsed(playerid,2)){
				SetPlayerAttachedObject(playerid,2,GetWeaponModel(weaponid[4]),7, 0.000000, -0.100000, -0.080000, -95.000000, -10.000000, 0.000000, 1.000000, 1.000000, 1.000000);
			}
		}
		else {
			if(IsPlayerAttachedObjectSlotUsed(playerid,2)){
				RemovePlayerAttachedObject(playerid,2);
			}
		}
	}
	else if(IsPlayerAttachedObjectSlotUsed(playerid,2)){
		RemovePlayerAttachedObject(playerid,2);
	}
	if(weaponid[5] && weaponammo[5] > 0){
		if(pArmedWeapon != weaponid[5] && !IsHiddenWeapon(weaponid[5])){
			if(!IsPlayerAttachedObjectSlotUsed(playerid,3)){
				SetPlayerAttachedObject(playerid,3,GetWeaponModel(weaponid[5]),1, 0.200000, -0.119999, -0.059999, 0.000000, 206.000000, 0.000000, 1.000000, 1.000000, 1.000000);
			}
		}
		else {
			if(IsPlayerAttachedObjectSlotUsed(playerid,3)){
				RemovePlayerAttachedObject(playerid,3);
			}
		}
	}
	else if(weaponid[6] && weaponammo[6] > 0){
		if(pArmedWeapon != weaponid[6] && !IsHiddenWeapon(weaponid[6])){
			if(!IsPlayerAttachedObjectSlotUsed(playerid,3)){
				SetPlayerAttachedObject(playerid,3,GetWeaponModel(weaponid[6]),1, 0.200000, -0.119999, -0.059999, 0.000000, 206.000000, 0.000000, 1.000000, 1.000000, 1.000000);
			}
		}
		else {
			if(IsPlayerAttachedObjectSlotUsed(playerid,3)){
				RemovePlayerAttachedObject(playerid,3);
			}
		}
	}
	else if(weaponid[7] && weaponammo[7] > 0){
		if(pArmedWeapon != weaponid[7] && !IsHiddenWeapon(weaponid[7])){
			if(!IsPlayerAttachedObjectSlotUsed(playerid,3)){
				SetPlayerAttachedObject(playerid,3,GetWeaponModel(weaponid[7]),1, 0.200000, -0.119999, -0.059999, 0.000000, 206.000000, 0.000000, 1.000000, 1.000000, 1.000000);
			}
		}
		else {
			if(IsPlayerAttachedObjectSlotUsed(playerid,3)){
				RemovePlayerAttachedObject(playerid,3);
			}
		}
	}
	else if(IsPlayerAttachedObjectSlotUsed(playerid,3)){
		RemovePlayerAttachedObject(playerid,3);
	}

	if(weaponid[3] && weaponammo[3] > 0){
		if(pArmedWeapon != weaponid[3] && !IsHiddenWeapon(weaponid[3])){
			if(!IsPlayerAttachedObjectSlotUsed(playerid,4)){
				SetPlayerAttachedObject(playerid,4,GetWeaponModel(weaponid[3]),1,0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 1.099999, 1.000000, 1.000000);
			}
		}
		else {
			if(IsPlayerAttachedObjectSlotUsed(playerid,4)){
				RemovePlayerAttachedObject(playerid,4);
			}
		}
	}
	else if(IsPlayerAttachedObjectSlotUsed(playerid,4)){
		RemovePlayerAttachedObject(playerid,4);
	}


	return Y_HOOKS_CONTINUE_RETURN_1;
}

/*

	SetItemTypeHolsterable(item_Spade,			1, 0.179000, -0.032000, 0.000000, 0.000000, -112.199981, -78.399993, 600, "GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_Baton,			8, 0.061868, 0.008748, 0.136682, 254.874801, 0.318417, 0.176398, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_Sword,			1, 0.123097, -0.129424, -0.139251, 0.000000, 301.455871, 0.000000, 600, "GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_M9Pistol,		8, 0.061868, 0.008748, 0.136682, 254.874801, 0.318417, 0.176398, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_M9PistolSD,		8, 0.061868, 0.008748, 0.136682, 254.874801, 0.318417, 0.176398, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_DesertEagle,	8, 0.061868, 0.008748, 0.136682, 254.874801, 0.318417, 0.176398, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_PumpShotgun,	1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_Sawnoff,		8, 0.061868, 0.008748, 0.136682, 254.874801, 0.318417, 0.176398, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_Spas12,			1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_Mac10,			8, 0.061868, 0.008748, 0.136682, 254.874801, 0.318417, 0.176398, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_MP5,			1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_WASR3Rifle,		1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_M16Rifle,		1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_Tec9,			8, 0.061868, 0.008748, 0.136682, 254.874801, 0.318417, 0.176398, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_SemiAutoRifle,	1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_SniperRifle,	1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_RocketLauncher,	1, 0.181966, -0.238397, -0.094830, 252.7912, 353.8938, 357.5294, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_Heatseeker,		1, 0.181966, -0.238397, -0.094830, 252.7912, 353.8938, 357.5294, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_AK47Rifle,		1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_M77RMRifle,		1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_DogsBreath,		8, 0.176000, -0.005000, 0.062999, -14.499991, -0.900000, 1.099991, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_StunGun,		8, 0.061868, 0.008748, 0.136682, 254.874801, 0.318417, 0.176398, 300,	"PED",		"PHONE_IN");
	SetItemTypeHolsterable(item_Shield,			1, 0.027000, -0.039999, 0.170000, 270.0000, -171.0000, 90.0000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_Mailbox,		1, 0.457000, -0.094999, -0.465000,  2.099999, -42.600, -94.500, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_Model70Rifle,	1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");
	SetItemTypeHolsterable(item_LenKnocksRifle,	1, 0.214089, -0.126031, 0.114131, 0.000000, 159.522552, 0.000000, 800,	"GOGGLES",	"GOGGLES_PUT_ON");


*/