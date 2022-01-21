#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    //CreateDynamicObject(-2103, -94.2525, -930.5345, 17.4185, -0.1999, -1.3999, -116.5000, -1, -1, -1, 350.0, 350.0); //
    //CreateDynamicObject(-2104, -128.7726, -931.2713, 17.5184, 0.0000, 0.0000, -60.4999, -1, -1, -1, 350.0, 350.0); //EnExMarker3
    CreateDynamicObject(1437, -99.3912, -925.9898, 19.8274, 0.0000, 0.0000, 153.0999, -1, -1, -1, 350.0, 350.0); //DYN_LADDER_2
    //CreateDynamicObject(-2104, -72.8042, -958.8909, 17.3084, 0.0000, 0.0000, 11.5000, -1, -1, -1, 350.0, 350.0); //EnExMarker3
    CreateDynamicObject(3279, -104.1629, -932.0599, 18.8534, -1.9999, -1.7000, -118.1000, -1, -1, -1, 350.0, 350.0); //a51_spottower
    CreateDynamicObject(3864, -97.1640, -923.6580, 24.2434, 0.0000, -1.8999, -119.0000, -1, -1, -1, 350.0, 350.0); //WS_floodlight

    return Y_HOOKS_CONTINUE_RETURN_1;
}