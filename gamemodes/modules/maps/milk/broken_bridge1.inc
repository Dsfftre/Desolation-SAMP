#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	new tmpobjid;
	//tmpobjid =  CreateDynamicObjectEx(-2119, -998.477233, -430.410308, 35.001308, 0.199999, 0.000000, 0.000000, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 17146, "cuntwroad", "Tar_1line256HVblenddrtdot", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 17146, "cuntwroad", "Tar_1line256HVblenddrtdot", 0x00000000);
	//tmpobjid =  CreateDynamicObjectEx(-2118, -968.666137, -340.429077, -26.436225, 0.000000, 0.000000, 14.000012, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 17003, "countrys", "rustc256128", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 2, 17003, "countrys", "rustc256128", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 3, 17146, "cuntwroad", "Tar_1line256HVblenddrtdot", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 4, 7555, "bballcpark1", "ws_carparknew2", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObjectEx(12957, -986.709106, -408.726470, 36.035495, 0.000000, 0.000000, 145.399932, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, -981.197265, -407.832946, 35.713924, 0.000000, 0.000000, 173.599990, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, -979.979003, -396.971099, 35.713924, 0.000000, 0.000000, 116.699974, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(12957, -976.151000, -401.041320, 36.035495, 0.000000, 0.000000, -159.300109, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, -983.359863, -409.496246, 35.406581, 0.000000, 0.000000, 103.899986, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, -983.649902, -396.876281, 35.406581, 0.000000, 0.000000, 103.899986, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, -957.984863, -305.164886, 35.843921, 0.000000, 0.000000, -25.500001, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, -959.673339, -287.213104, 35.843921, 0.000000, 0.000000, 23.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, -951.274169, -274.087799, 36.063911, 0.000000, 0.000000, -36.600009, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(800, -963.653259, -303.432464, 34.031009, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(800, -963.653259, -286.982574, 34.031009, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(800, -948.823364, -274.222625, 34.031009, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, -958.039978, -302.576202, 35.492759, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, -960.506408, -291.549865, 35.592754, 0.000000, 0.000000, 93.100006, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, -954.029785, -282.065856, 35.652744, 0.000000, -0.699999, 93.100006, 600.00, 600.00); 

	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {

	/*RemoveBuildingForPlayer(playerid, 17199, -975.882, -365.445, 34.992, 0.250);
	RemoveBuildingForPlayer(playerid, 17337, -967.992, -341.289, -27.289, 0.250);
	RemoveBuildingForPlayer(playerid, 17198, -975.882, -365.445, 34.992, 0.250);
	RemoveBuildingForPlayer(playerid, 17003, -967.992, -341.289, -27.289, 0.250);*/
	RemoveBuildingForPlayer(playerid, 4508, -953.882, -271.203, 38.421, 0.250);
	RemoveBuildingForPlayer(playerid, 4509, -981.953, -410.187, 38.421, 0.250);
	    
    return Y_HOOKS_CONTINUE_RETURN_1;

}