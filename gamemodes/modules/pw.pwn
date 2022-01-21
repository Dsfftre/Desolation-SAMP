#if defined _inc_hooks
	#undef _inc_hooks
#endif


#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {

    SendRconCommand("password 0");
    //SendRconCommand("password rebooted");

    return Y_HOOKS_CONTINUE_RETURN_1;
}