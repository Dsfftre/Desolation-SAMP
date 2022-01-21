#if defined _inc_startcolandreas
	#undef _inc_startcolandreas
#endif

/*
#if defined _inc_hooks
	#undef _inc_hooks
#endif
*/
#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	CA_RemoveBreakableBuildings();
	CA_Init();
	return Y_HOOKS_CONTINUE_RETURN_1;
}
