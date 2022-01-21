#if defined _inc_a69
	#undef _inc_a69
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	CreateObject(11692, 199.344, 1943.79, 18.2031, 0, 0, 0);										//base
    CreateObject(19905, 206.798950, 1931.643432, 16.450595, 0, 0, 0);
    CreateObject(19905, 188.208908, 1835.033569, 16.450595, 0, 0, 0);
    CreateObject(19905, 230.378875, 1835.033569, 16.450595, 0, 0, 0);
    CreateObject(19907, 142.013977, 1902.538085, 17.633581, 0, 0, 270.0);
    CreateObject(19907, 146.854003, 1846.008056, 16.533580, 0, 0, 0);
    CreateObject(19909, 137.900390, 1875.024291, 16.836734, 0, 0, 270.0);
    CreateObject(19909, 118.170387, 1875.184326, 16.846735, 0, 0, 0);

	CreateDynamicObject(19899, 128.35590, 1907.86414, 17.76266,   0.00000, 0.00000, 0.00000);		//hangar misc (garage)
	CreateDynamicObject(19900, 128.36867, 1906.13184, 17.76270,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19903, 136.67551, 1902.15356, 17.63821,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19922, 131.84174, 1910.27625, 17.73090,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19927, 134.73941, 1910.45007, 17.79280,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19918, 136.76077, 1902.93250, 17.75820,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19817, 148.60953, 1903.47888, 17.80251,   0.00000, 0.00000, 180.00000);
	CreateDynamicObject(19817, 143.60950, 1903.47888, 17.80250,   0.00000, 0.00000, 180.00000);
	CreateDynamicObject(939, 154.43738, 1902.73157, 20.20831,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(2737, 136.05180, 1905.61035, 19.52130,   0.00000, 0.00000, 270.00000);

	CreateDynamicObject(1679, 144.00931, 1836.49658, 17.16052,   0.00000, 0.00000, 0.00000);		//hangar misc (guards)
	CreateDynamicObject(15037, 140.21829, 1834.64355, 17.02813,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(11631, 141.04497, 1839.38171, 17.87240,   0.00000, 0.00000, 0.00000);

	CreateDynamicObject(1771, 113.59286, 1871.47192, 17.30377,   0.00000, 0.00000, 0.00000);		//barracks 1
	CreateDynamicObject(1771, 122.34167, 1870.71472, 17.30380,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(1771, 113.59290, 1878.66016, 17.30380,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1771, 122.34170, 1880.22729, 17.30380,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(1679, 122.68313, 1875.43518, 17.29950,   0.00000, 0.00000, 90.00000);

	CreateDynamicObject(1771, 141.87343, 1879.37366, 17.30380,   0.00000, 0.00000, 90.00000);		//barracks 2
	CreateDynamicObject(1771, 141.87340, 1870.08191, 17.30380,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(1771, 133.10368, 1871.16687, 17.30380,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1771, 133.10370, 1878.28052, 17.30380,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1679, 137.10370, 1870.73865, 17.29950,   0.00000, 0.00000, 90.00000);


	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {
	RemoveBuildingForPlayer(playerid, 16203, 199.344, 1943.79, 18.2031, 250.0); 	// Land
	RemoveBuildingForPlayer(playerid, 16590, 199.344, 1943.79, 18.2031, 250.0); 	// Land LOD
	RemoveBuildingForPlayer(playerid, 16323, 199.336, 1943.88, 18.2031, 250.0); 	// Buildings
	RemoveBuildingForPlayer(playerid, 16619, 199.336, 1943.88, 18.2031, 250.0); 	// Buildings LOD
	RemoveBuildingForPlayer(playerid, 1697, 228.797, 1835.34, 23.2344, 250.0); 		// Solar Panels (they poke through the roof inside)

	return Y_HOOKS_CONTINUE_RETURN_1;
}