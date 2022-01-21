#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	
	CreateDynamicObject(2927, 283.05347, 1869.28796, 9.39943,   0.00000, 0.00000, 90.00000, 81); // interior 81 laboratory 2 rooms in a51
	CreateDynamicObject(2927, 268.62985, 1864.10327, 9.39940,   0.00000, 0.00000, 0.00000, 81); // interior 81 laboratory 2 rooms in a51

	return Y_HOOKS_CONTINUE_RETURN_1;
}
