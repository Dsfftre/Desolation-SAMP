#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	new g_Object[60];
	g_Object[0] = CreateDynamicObject(14576, 2713.3193, -1742.1202, -71.3740, 0.0000, 0.0000, 0.0000); //vault_door
	SetDynamicObjectMaterial(g_Object[0], 3, 10864, "bridgeland_sfse", "ws_altz_wall1", 0x00000000);
	SetDynamicObjectMaterial(g_Object[0], 4, 18038, "vegas_munation", "mp_gun_floorred", 0x00000000);
	SetDynamicObjectMaterial(g_Object[0], 5, 10891, "bakery_sfse", "ws_altz_wall4", 0x00000000);
	SetDynamicObjectMaterial(g_Object[0], 6, 14603, "bikeskool", "motel_wall3", 0x00000000);
	g_Object[1] = CreateDynamicObject(6400, 2718.8679, -1756.7409, -70.1975, 0.0000, 0.0000, 90.0000); //spraydoor_LAw2
	SetDynamicObjectMaterial(g_Object[1], 0, 12844, "cos_liquorstore", "b_wtilesreflect", 0x00000000);
	g_Object[2] = CreateDynamicObject(1498, 2712.6650, -1765.8159, -77.5894, 0.0000, 0.0000, 0.0000); //Gen_doorEXT03
	g_Object[3] = CreateDynamicObject(6400, 2714.5454, -1754.7591, -78.1475, 0.0000, 0.0000, 90.0000); //spraydoor_LAw2
	SetDynamicObjectMaterial(g_Object[3], 0, 12844, "cos_liquorstore", "b_wtilesreflect", 0x00000000);
	g_Object[4] = CreateDynamicObject(6400, 2718.9680, -1757.2314, -70.1975, 0.0000, 0.0000, 0.0000); //spraydoor_LAw2
	SetDynamicObjectMaterial(g_Object[4], 0, 12844, "cos_liquorstore", "b_wtilesreflect", 0x00000000);
	g_Object[5] = CreateDynamicObject(6400, 2718.9880, -1759.1232, -66.4376, 0.0000, 0.0000, 0.0000); //spraydoor_LAw2
	SetDynamicObjectMaterial(g_Object[5], 0, 12844, "cos_liquorstore", "b_wtilesreflect", 0x00000000);
	g_Object[6] = CreateDynamicObject(6400, 2718.3374, -1756.8811, -64.8376, 0.0000, 0.0000, 90.0000); //spraydoor_LAw2
	SetDynamicObjectMaterial(g_Object[6], 0, 12844, "cos_liquorstore", "b_wtilesreflect", 0x00000000);
	g_Object[7] = CreateDynamicObject(4227, 2719.0354, -1766.2038, -76.1191, 0.0000, 0.0000, 270.0000); //graffiti_lan01
	g_Object[8] = CreateDynamicObject(1498, 2716.4157, -1765.8159, -77.5894, 0.0000, 0.0000, 0.0000); //Gen_doorEXT03
	g_Object[9] = CreateDynamicObject(1498, 2716.4157, -1765.8159, -73.3994, 0.0000, 0.0000, 0.0000); //Gen_doorEXT03
	g_Object[10] = CreateDynamicObject(1498, 2712.6137, -1765.8159, -73.3994, 0.0000, 0.0000, 0.0000); //Gen_doorEXT03
	g_Object[11] = CreateDynamicObject(1498, 2712.6137, -1765.8159, -69.2396, 0.0000, 0.0000, 0.0000); //Gen_doorEXT03
	g_Object[12] = CreateDynamicObject(1498, 2716.4753, -1765.8159, -69.2396, 0.0000, 0.0000, 0.0000); //Gen_doorEXT03
	g_Object[13] = CreateDynamicObject(1498, 2718.0573, -1756.8861, -75.3896, 0.0000, 0.0000, 180.0000); //Gen_doorEXT03
	g_Object[14] = CreateDynamicObject(1498, 2718.1574, -1756.8659, -71.1696, 0.0000, 0.0000, 180.0000); //Gen_doorEXT03
	g_Object[15] = CreateDynamicObject(1498, 2714.2451, -1756.8961, -71.1696, 0.0000, 0.0000, 180.0000); //Gen_doorEXT03
	g_Object[16] = CreateDynamicObject(1498, 2714.2451, -1756.8961, -66.9795, 0.0000, 0.0000, 180.0000); //Gen_doorEXT03
	g_Object[17] = CreateDynamicObject(1498, 2717.7182, -1756.8759, -66.9795, 0.0000, 0.0000, 180.0000); //Gen_doorEXT03
	g_Object[18] = CreateDynamicObject(1498, 2719.0295, -1759.2180, -66.9795, 0.0000, 0.0000, 90.0000); //Gen_doorEXT03
	g_Object[19] = CreateDynamicObject(1498, 2719.0295, -1759.4282, -71.1996, 0.0000, 0.0000, 90.0000); //Gen_doorEXT03
	g_Object[20] = CreateDynamicObject(1498, 2714.3146, -1756.8861, -75.3896, 0.0000, 0.0000, 180.0000); //Gen_doorEXT03
	g_Object[21] = CreateDynamicObject(19176, 2713.3405, -1755.0434, -78.1047, 0.0000, 0.0000, 0.0000); //LSOffice1Door1
	SetDynamicObjectMaterial(g_Object[21], 0, 10377, "cityhall_sfs", "ws_bigblackdoor", 0x00000000);
	g_Object[22] = CreateDynamicObject(14856, 2702.9973, -1772.8242, -67.2894, 0.0000, 0.0000, 90.0000); //cellsa
	SetDynamicObjectMaterial(g_Object[22], 0, -1, "none", "none", 0xFF696969);
	g_Object[23] = CreateDynamicObject(1362, 2712.0466, -1762.7078, -76.9855, 0.0000, 0.0000, 0.0000); //CJ_FIREBIN_(L0)
	SetDynamicObjectMaterial(g_Object[23], 0, -1, "none", "none", 0xFFD3D3D3);
	g_Object[24] = CreateDynamicObject(14856, 2702.9973, -1772.8242, -71.5194, 0.0000, 0.0000, 90.0000); //cellsa
	SetDynamicObjectMaterial(g_Object[24], 0, -1, "none", "none", 0xFF696969);
	g_Object[25] = CreateDynamicObject(14856, 2702.9973, -1772.8242, -75.7094, 0.0000, 0.0000, 90.0000); //cellsa
	SetDynamicObjectMaterial(g_Object[25], 0, -1, "none", "none", 0xFF696969);
	g_Object[26] = CreateDynamicObject(19360, 2711.3662, -1757.3280, -79.7658, 0.0000, 0.0000, 0.0000); //wall008
	SetDynamicObjectMaterial(g_Object[26], 0, 4981, "wiresetc2_las", "ganggraf03_LA", 0x00000000);
	g_Object[27] = CreateDynamicObject(11727, 2711.7004, -1757.3520, -77.1189, 0.0000, 0.0000, 90.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[27], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[28] = CreateDynamicObject(11727, 2718.9426, -1764.1741, -71.1091, 0.0000, 0.0000, 270.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[28], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[29] = CreateDynamicObject(11727, 2718.9426, -1764.1741, -66.7191, 0.0000, 0.0000, 270.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[29], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[30] = CreateDynamicObject(11727, 2718.9426, -1764.1741, -75.3191, 0.0000, 0.0000, 270.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[30], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[31] = CreateDynamicObject(11727, 2711.7004, -1758.5131, -72.9390, 0.0000, 0.0000, 90.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[31], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[32] = CreateDynamicObject(11727, 2711.7004, -1758.5131, -68.6991, 0.0000, 0.0000, 90.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[32], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[33] = CreateDynamicObject(11727, 2711.7004, -1758.5131, -64.6591, 0.0000, 0.0000, 90.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[33], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[34] = CreateDynamicObject(1526, 2713.3688, -1760.4294, -65.2635, 0.0000, 0.0000, 270.0000); //tag_rifa
	SetDynamicObjectMaterial(g_Object[34], 0, -1, "none", "none", 0xFF000000);
	g_Object[35] = CreateDynamicObject(1497, 2711.8872, -1762.8298, -69.1465, -9.6999, 0.0000, 0.0000); //Gen_doorEXT02
	g_Object[36] = CreateDynamicObject(2673, 2718.1101, -1764.9405, -77.4788, 0.0000, 0.0000, 0.0000); //PROC_RUBBISH_5
	g_Object[37] = CreateDynamicObject(2666, 2712.8881, -1765.7741, -75.2377, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[37], 0, "1", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[38] = CreateDynamicObject(2675, 2713.7263, -1758.6934, -66.8900, 0.0000, 0.0000, -19.5999); //PROC_RUBBISH_6
	g_Object[39] = CreateDynamicObject(1362, 2718.6003, -1765.4188, -72.7654, 0.0000, 0.0000, 0.0000); //CJ_FIREBIN_(L0)
	SetDynamicObjectMaterial(g_Object[39], 0, -1, "none", "none", 0xFFD3D3D3);
	g_Object[40] = CreateDynamicObject(1362, 2718.6003, -1757.3281, -66.3755, 0.0000, 0.0000, 0.0000); //CJ_FIREBIN_(L0)
	SetDynamicObjectMaterial(g_Object[40], 0, -1, "none", "none", 0xFFD3D3D3);
	g_Object[41] = CreateDynamicObject(2674, 2714.6611, -1758.1096, -75.3428, 0.0000, 0.0000, -40.2000); //PROC_RUBBISH_2
	g_Object[42] = CreateDynamicObject(2673, 2713.1223, -1758.2358, -75.2720, 0.0000, 0.0000, 0.0000); //PROC_RUBBISH_5
	g_Object[43] = CreateDynamicObject(2666, 2716.6413, -1765.7741, -75.2377, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[43], 0, "2", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[44] = CreateDynamicObject(2677, 2717.1628, -1764.0245, -68.8806, 0.0000, 0.0000, 0.0000); //PROC_RUBBISH_7
	g_Object[45] = CreateDynamicObject(2666, 2717.7724, -1756.9820, -73.0277, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[45], 0, "3", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[46] = CreateDynamicObject(2676, 2714.0351, -1764.2966, -69.0599, 0.0000, 0.0000, 19.7999); //PROC_RUBBISH_8
	g_Object[47] = CreateDynamicObject(2671, 2716.2199, -1763.7927, -73.3501, 0.0000, 0.0000, 0.0000); //PROC_RUBBISH_3
	g_Object[48] = CreateDynamicObject(2671, 2713.2556, -1757.1463, -79.5402, 0.0000, 0.0000, -97.6999); //PROC_RUBBISH_3
	g_Object[49] = CreateDynamicObject(2666, 2714.0205, -1756.9820, -73.0277, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[49], 0, "4", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[50] = CreateDynamicObject(2666, 2712.8393, -1765.7724, -71.0377, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[50], 0, "5", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[51] = CreateDynamicObject(2666, 2716.6706, -1765.7724, -71.0377, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[51], 0, "6", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[52] = CreateDynamicObject(2666, 2718.9829, -1759.2237, -68.3877, 0.0000, 0.0000, 90.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[52], 0, "7", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[53] = CreateDynamicObject(2666, 2717.8718, -1756.9840, -68.3877, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[53], 0, "8", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[54] = CreateDynamicObject(2666, 2713.9680, -1756.9840, -68.7577, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[54], 0, "9", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[55] = CreateDynamicObject(2666, 2712.9270, -1765.7655, -66.8478, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[55], 0, "10", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[56] = CreateDynamicObject(2666, 2716.7995, -1765.7655, -66.8478, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[56], 0, "11", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[57] = CreateDynamicObject(2666, 2718.9709, -1758.9333, -64.1878, 0.0000, 0.0000, 90.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[57], 0, "12", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[58] = CreateDynamicObject(2666, 2717.3898, -1756.9929, -64.1878, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[58], 0, "13", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);
	g_Object[59] = CreateDynamicObject(2666, 2713.9287, -1756.9929, -64.5978, 0.0000, 0.0000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[59], 0, "14", OBJECT_MATERIAL_SIZE_256x128, "Franklin Gothic Medium", 50, 1, 0xFF000000, 0x00000000, 0);


    return Y_HOOKS_CONTINUE_RETURN_1;
}
