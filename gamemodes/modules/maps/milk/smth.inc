#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new g_Object[34];
    g_Object[0] = CreateDynamicObject(3564, 2075.4040, -364.8062, 63.6846, -0.3998, 6.0000, 15.9998); //lastran1_LA01
    SetDynamicObjectMaterial(g_Object[0], 0, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[0], 1, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[0], 2, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[0], 3, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[0], 4, -1, "none", "none", 0xFF778899);
    g_Object[1] = CreateDynamicObject(3564, 2067.7062, -367.4548, 64.5409, -0.3998, 6.0000, 20.8999); //lastran1_LA01
    SetDynamicObjectMaterial(g_Object[1], 0, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[1], 1, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[1], 2, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[1], 3, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[1], 4, -1, "none", "none", 0xFF778899);
    g_Object[2] = CreateDynamicObject(3564, 2083.2260, -362.5667, 62.8284, -0.3998, 6.0000, 15.9998); //lastran1_LA01
    SetDynamicObjectMaterial(g_Object[2], 0, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[2], 1, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[2], 2, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[2], 3, -1, "none", "none", 0xFF778899);
    SetDynamicObjectMaterial(g_Object[2], 4, -1, "none", "none", 0xFF778899);
    g_Object[3] = CreateDynamicObject(1428, 2080.5898, -361.5188, 62.8375, -0.1999, -4.5000, -161.7996); //DYN_LADDER
    g_Object[4] = CreateDynamicObject(3585, 2090.9858, -360.5835, 61.8970, -0.4999, 6.7000, 14.0000); //lastran1_LA02
    SetDynamicObjectMaterial(g_Object[4], 0, -1, "none", "none", 0xFF708090);
    SetDynamicObjectMaterial(g_Object[4], 1, -1, "none", "none", 0xFF708090);
    SetDynamicObjectMaterial(g_Object[4], 2, -1, "none", "none", 0xFF708090);
    SetDynamicObjectMaterial(g_Object[4], 3, -1, "none", "none", 0xFF708090);
    g_Object[5] = CreateDynamicObject(5153, 2089.9948, -357.3944, 60.1984, -5.3000, 3.5999, -77.4999); //stuntramp7_las2
    g_Object[6] = CreateDynamicObject(1764, 2089.9604, -361.6009, 61.2218, 6.4999, -6.7999, 151.6000); //LOW_COUCH_2
    g_Object[7] = CreateDynamicObject(19358, 2069.0385, -365.5603, 63.2008, 5.7000, -0.9000, 111.5999); //wall006
    SetDynamicObjectMaterialText(g_Object[7], 0, "Ku Klux Klan", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFF000000, 0x00000000, 0);
    g_Object[8] = CreateDynamicObject(1820, 2092.4545, -360.4526, 60.9163, -0.4000, 5.8999, 20.8999); //COFFEE_LOW_4
    g_Object[9] = CreateDynamicObject(19942, 2092.4511, -360.0073, 61.5057, -0.6000, 6.2999, 0.0000); //PoliceRadio1
    g_Object[10] = CreateDynamicObject(19575, 2092.5500, -360.1599, 61.4405, 0.0000, 0.0000, 0.0000); //Apple1
    g_Object[11] = CreateDynamicObject(3524, 2065.2138, -368.5453, 64.5997, 0.0000, 0.0000, -70.2999); //skullpillar01_lvs
    g_Object[12] = CreateDynamicObject(19357, 2084.3347, -360.9069, 60.9470, 20.6000, -1.4000, 106.8000); //wall005
    SetDynamicObjectMaterialText(g_Object[12], 0, "White Supremacy", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFFFF0000, 0x00000000, 0);
    g_Object[13] = CreateDynamicObject(18664, 2077.1757, -362.8865, 63.8109, -5.1000, -1.6000, -77.5000); //SprayTag6
    g_Object[14] = CreateDynamicObject(3134, 2095.7602, -354.7398, 60.1146, 5.1999, 5.2999, 0.0000); //quarry_barrel
    g_Object[15] = CreateDynamicObject(3134, 2095.7392, -355.6761, 60.0132, -3.6999, 0.9999, -84.5000); //quarry_barrel
    g_Object[16] = CreateDynamicObject(3134, 2094.8049, -354.5072, 60.4342, 25.2999, -0.6999, -84.5000); //quarry_barrel
    g_Object[17] = CreateDynamicObject(1362, 2091.9694, -357.4682, 60.6522, 1.0999, 6.8999, 1.6999); //CJ_FIREBIN_(L0)
    g_Object[18] = CreateDynamicObject(1271, 2093.4692, -350.8932, 60.0273, -25.0000, -13.4000, 0.0000); //gunbox
    g_Object[19] = CreateDynamicObject(1271, 2093.3901, -348.0351, 59.0537, -18.9000, -101.3999, 2.1000); //gunbox
    g_Object[20] = CreateDynamicObject(19036, 2094.7292, -358.3189, 63.0000, -0.6999, 18.9000, 55.9999); //HockeyMask1
    SetDynamicObjectMaterial(g_Object[20], 0, -1, "none", "none", 0xFFFFFFFF);
    g_Object[21] = CreateDynamicObject(5153, 2115.7893, -359.1662, 57.7262, -0.5999, 0.5999, 2.7000); //stuntramp7_las2
    g_Object[22] = CreateDynamicObject(2991, 2118.7446, -359.0318, 58.0175, -6.8999, -0.0999, -89.1999); //imy_bbox
    g_Object[23] = CreateDynamicObject(3525, 2117.9555, -355.1828, 60.8337, 30.7999, 0.0000, 0.0000); //exbrtorch01
    g_Object[24] = CreateDynamicObject(3525, 2118.0903, -364.2072, 61.0200, -50.6999, 0.0000, 1.0000); //exbrtorch01
    g_Object[25] = CreateDynamicObject(2762, 2119.2817, -359.0222, 58.9918, -7.0999, 0.2999, -89.0000); //CJ_CHICK_TABLE
    g_Object[26] = CreateDynamicObject(2908, 2120.9802, -358.9185, 57.2151, 0.0000, 0.0000, 0.0000); //kmb_deadhead
    g_Object[27] = CreateDynamicObject(2908, 2120.1494, -358.9185, 57.3251, 0.0000, 0.0000, -122.5000); //kmb_deadhead
    g_Object[28] = CreateDynamicObject(2908, 2120.2214, -359.2719, 57.3251, -9.0999, 20.3000, -67.8000); //kmb_deadhead
    g_Object[29] = CreateDynamicObject(2908, 2119.9301, -358.5515, 57.3257, -2.4999, -7.2999, -168.2000); //kmb_deadhead
    g_Object[30] = CreateDynamicObject(19353, 2105.4736, -365.3359, 59.9055, -6.8999, -0.8999, -84.8999); //wall001
    SetDynamicObjectMaterialText(g_Object[30], 0, "Terms:", OBJECT_MATERIAL_SIZE_256x128, "Arial", 16, 1, 0xFF000000, 0x00000000, 0);
    g_Object[31] = CreateDynamicObject(19353, 2109.6533, -364.9177, 58.8284, -6.1999, 5.4999, -84.1999); //wall001
    SetDynamicObjectMaterialText(g_Object[31], 0, "Sacrifice a Nigger", OBJECT_MATERIAL_SIZE_256x128, "Arial", 24, 1, 0xFF000000, 0x00000000, 0);
    g_Object[32] = CreateDynamicObject(19353, 2105.3811, -365.4453, 59.4330, -5.9000, -1.8000, -84.6000); //wall001
    SetDynamicObjectMaterialText(g_Object[32], 0, "Cut the head", OBJECT_MATERIAL_SIZE_256x128, "Arial", 15, 1, 0xFF000000, 0x00000000, 0);
    g_Object[33] = CreateDynamicObject(19353, 2109.3447, -361.8869, 64.4351, 1.6000, -81.3999, 2.4999); //wall001
    SetDynamicObjectMaterialText(g_Object[33], 0, "K.K.K", OBJECT_MATERIAL_SIZE_256x128, "Cambria", 60, 1, 0xFF000000, 0x00000000, 0);

    return Y_HOOKS_CONTINUE_RETURN_1;
}
