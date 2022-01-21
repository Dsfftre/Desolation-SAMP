#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    
    
    #if defined MG_OnGameModeInit
        return MG_OnGameModeInit();
    #else
        return Y_HOOKS_CONTINUE_RETURN_1;
    #endif
}

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif

#define OnGameModeInit MG_OnGameModeInit
#if defined MG_OnGameModeInit
    forward MG_OnGameModeInit();
#endif

hook OnPlayerConnect(playerid) {
    
    #if defined MG_OnPlayerConnect
        return MG_OnPlayerConnect(playerid);
    #else
        return Y_HOOKS_CONTINUE_RETURN_1;
    #endif
}

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect MG_OnPlayerConnect
#if defined MG_OnPlayerConnect
    forward MG_OnPlayerConnect(playerid);
#endif