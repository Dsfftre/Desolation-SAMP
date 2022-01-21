#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

new bool:halloween_event = false;

hook OnGameModeInit() {

	new year, month, day;
	getdate(year, month, day);

	if(month == 10 && day >= 2) halloween_event = true;
	if(month == 11 && day <= 4) halloween_event = true;

	return Y_HOOKS_CONTINUE_RETURN_1;
}

