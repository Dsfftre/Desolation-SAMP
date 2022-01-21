#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	new g_Object[156];
	g_Object[0] = CreateDynamicObject(19380, 1400.2342, 1097.8275, -26.0209, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[0], 0, 10756, "airportroads_sfse", "Heliconcrete", 0x00000000);
	g_Object[1] = CreateDynamicObject(19380, 1400.2342, 1088.2071, -26.0209, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[1], 0, 10756, "airportroads_sfse", "Heliconcrete", 0x00000000);
	g_Object[2] = CreateDynamicObject(19380, 1410.7248, 1088.2071, -26.0209, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[2], 0, 10756, "airportroads_sfse", "Heliconcrete", 0x00000000);
	g_Object[3] = CreateDynamicObject(19380, 1410.7248, 1078.5771, -26.0209, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[3], 0, 10756, "airportroads_sfse", "Heliconcrete", 0x00000000);
	g_Object[4] = CreateDynamicObject(5069, 1405.3315, 1067.6805, -24.5436, 0.0000, 0.0000, 90.0000); //ctscene1_las
	SetDynamicObjectMaterial(g_Object[4], 0, -1, "none", "none", 0xFFF5F5F5);
	g_Object[5] = CreateDynamicObject(19380, 1395.0572, 1078.5804, -20.8572, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[5], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[6] = CreateDynamicObject(19380, 1395.0572, 1088.1910, -20.8572, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[6], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[7] = CreateDynamicObject(19380, 1395.0572, 1097.8105, -20.8572, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[7], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[8] = CreateDynamicObject(19380, 1399.9365, 1102.5710, -20.8572, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[8], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[9] = CreateDynamicObject(19380, 1409.5168, 1102.5710, -20.8572, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[9], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[10] = CreateDynamicObject(19380, 1400.2336, 1068.9658, -26.0209, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[10], 0, 10756, "airportroads_sfse", "Heliconcrete", 0x00000000);
	g_Object[11] = CreateDynamicObject(19380, 1410.7253, 1068.9658, -26.0209, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[11], 0, 10756, "airportroads_sfse", "Heliconcrete", 0x00000000);
	g_Object[12] = CreateDynamicObject(19380, 1395.0572, 1068.9514, -20.8572, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[12], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[13] = CreateDynamicObject(19380, 1415.8795, 1097.8105, -20.8572, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[13], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[14] = CreateDynamicObject(19380, 1415.8795, 1088.2202, -20.8572, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[14], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[15] = CreateDynamicObject(19380, 1415.8795, 1078.6296, -20.8572, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[15], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[16] = CreateDynamicObject(3029, 1415.1800, 1064.3485, -25.9186, 0.0000, 0.0000, 90.0000); //cr1_door
	SetDynamicObjectMaterial(g_Object[16], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[17] = CreateDynamicObject(19380, 1401.3812, 1064.2390, -20.8572, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[17], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[18] = CreateDynamicObject(19380, 1411.0023, 1064.2390, -20.8572, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[18], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[19] = CreateDynamicObject(19380, 1391.7795, 1064.2390, -20.8572, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[19], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[20] = CreateDynamicObject(19380, 1419.1384, 1102.5710, -20.8572, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[20], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[21] = CreateDynamicObject(19380, 1395.0572, 1068.9514, -10.3872, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[21], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[22] = CreateDynamicObject(19380, 1395.0572, 1078.5527, -10.3872, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[22], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[23] = CreateDynamicObject(19380, 1395.0572, 1088.1427, -10.3872, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[23], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[24] = CreateDynamicObject(19380, 1410.7230, 1097.8275, -26.0209, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[24], 0, 10756, "airportroads_sfse", "Heliconcrete", 0x00000000);
	g_Object[25] = CreateDynamicObject(19380, 1399.9365, 1102.5710, -10.3971, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[25], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[26] = CreateDynamicObject(19380, 1409.5465, 1102.5710, -10.3971, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[26], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[27] = CreateDynamicObject(19380, 1419.1571, 1102.5710, -10.3971, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[27], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[28] = CreateDynamicObject(19380, 1415.8795, 1097.8105, -10.3872, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[28], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[29] = CreateDynamicObject(19380, 1415.8795, 1088.1999, -10.3872, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[29], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[30] = CreateDynamicObject(19380, 1415.8795, 1078.6092, -10.3872, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[30], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[31] = CreateDynamicObject(19380, 1415.8795, 1069.0177, -10.3872, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[31], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[32] = CreateDynamicObject(19380, 1411.0106, 1064.2390, -10.3971, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[32], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[33] = CreateDynamicObject(19380, 1401.4195, 1064.2390, -10.3971, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[33], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[34] = CreateDynamicObject(19380, 1391.8166, 1064.2390, -10.3971, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[34], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[35] = CreateDynamicObject(19380, 1410.7154, 1078.5948, -11.5607, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[35], 0, 3080, "adjumpx", "rustyboltpanel", 0x00000000);
	g_Object[36] = CreateDynamicObject(19380, 1410.7154, 1088.1955, -11.5607, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[36], 0, 3080, "adjumpx", "rustyboltpanel", 0x00000000);
	g_Object[37] = CreateDynamicObject(19380, 1410.7154, 1097.7960, -11.5607, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[37], 0, 3080, "adjumpx", "rustyboltpanel", 0x00000000);
	g_Object[38] = CreateDynamicObject(19380, 1400.2635, 1097.7960, -11.5607, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[38], 0, 3080, "adjumpx", "rustyboltpanel", 0x00000000);
	g_Object[39] = CreateDynamicObject(19380, 1410.7154, 1068.9847, -11.5607, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[39], 0, 3080, "adjumpx", "rustyboltpanel", 0x00000000);
	g_Object[40] = CreateDynamicObject(3062, 1407.2469, 1096.1037, -24.5429, 0.0000, 0.0000, 25.6000); //container_door
	SetDynamicObjectMaterial(g_Object[40], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[41] = CreateDynamicObject(19380, 1400.2635, 1078.5754, -11.5607, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[41], 0, 3080, "adjumpx", "rustyboltpanel", 0x00000000);
	g_Object[42] = CreateDynamicObject(19380, 1400.2635, 1068.9737, -11.5607, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[42], 0, 3080, "adjumpx", "rustyboltpanel", 0x00000000);
	g_Object[43] = CreateDynamicObject(19380, 1395.0572, 1097.7320, -10.3872, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[43], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[44] = CreateDynamicObject(19450, 1395.0736, 1069.1584, -14.8401, 0.0000, 0.0000, 0.0000); //wall090
	SetDynamicObjectMaterial(g_Object[44], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[45] = CreateDynamicObject(16095, 1394.8590, 1067.2341, -26.6065, 0.0000, 0.0000, 180.0000); //des_a51guardbox02
	SetDynamicObjectMaterial(g_Object[45], 0, 12850, "cunte_block1", "ws_redbrickold", 0xFFFFFFFF);
	SetDynamicObjectMaterial(g_Object[45], 1, 12946, "ce_bankalley1", "newindow13", 0x00000000);
	SetDynamicObjectMaterial(g_Object[45], 2, 1495, "ext_doors2", "CJ_WOODDOOR4", 0x00000000);
	g_Object[46] = CreateDynamicObject(19450, 1395.0736, 1078.7690, -14.8401, 0.0000, 0.0000, 0.0000); //wall090
	SetDynamicObjectMaterial(g_Object[46], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[47] = CreateDynamicObject(19450, 1395.0736, 1088.3801, -14.8401, 0.0000, 0.0000, 0.0000); //wall090
	SetDynamicObjectMaterial(g_Object[47], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[48] = CreateDynamicObject(19450, 1395.0736, 1097.9604, -14.8401, 0.0000, 0.0000, 0.0000); //wall090
	SetDynamicObjectMaterial(g_Object[48], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[49] = CreateDynamicObject(19450, 1399.9571, 1102.5649, -14.8401, 0.0000, 0.0000, 90.0000); //wall090
	SetDynamicObjectMaterial(g_Object[49], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[50] = CreateDynamicObject(19450, 1409.5382, 1102.5649, -14.8401, 0.0000, 0.0000, 90.0000); //wall090
	SetDynamicObjectMaterial(g_Object[50], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[51] = CreateDynamicObject(19450, 1419.1578, 1102.5649, -14.8401, 0.0000, 0.0000, 90.0000); //wall090
	SetDynamicObjectMaterial(g_Object[51], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[52] = CreateDynamicObject(19450, 1415.8756, 1078.5383, -14.8401, 0.0000, 0.0000, 0.0000); //wall090
	SetDynamicObjectMaterial(g_Object[52], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[53] = CreateDynamicObject(16775, 1405.4095, 1064.2318, -22.0438, 0.0000, 0.0000, 0.0000); //door_savhangr2
	SetDynamicObjectMaterial(g_Object[53], 0, 16640, "a51", "a51_blastdoor", 0x00000000);
	g_Object[54] = CreateDynamicObject(19450, 1415.8756, 1097.7790, -14.8401, 0.0000, 0.0000, 0.0000); //wall090
	SetDynamicObjectMaterial(g_Object[54], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[55] = CreateDynamicObject(19450, 1415.8756, 1088.1489, -14.8401, 0.0000, 0.0000, 0.0000); //wall090
	SetDynamicObjectMaterial(g_Object[55], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[56] = CreateDynamicObject(19450, 1401.4277, 1064.2711, -14.8401, 0.0000, 0.0000, 90.0000); //wall090
	SetDynamicObjectMaterial(g_Object[56], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[57] = CreateDynamicObject(19450, 1415.8756, 1068.9482, -14.8401, 0.0000, 0.0000, 0.0000); //wall090
	SetDynamicObjectMaterial(g_Object[57], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[58] = CreateDynamicObject(19450, 1391.8160, 1064.2711, -14.8401, 0.0000, 0.0000, 90.0000); //wall090
	SetDynamicObjectMaterial(g_Object[58], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[59] = CreateDynamicObject(19450, 1411.0277, 1064.2711, -14.8401, 0.0000, 0.0000, 90.0000); //wall090
	SetDynamicObjectMaterial(g_Object[59], 0, 5180, "lashops93_las2", "Window1164HV", 0x00000000);
	g_Object[60] = CreateDynamicObject(18980, 1401.8310, 1075.9162, -14.7292, 0.0000, 0.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[60], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[61] = CreateDynamicObject(18762, 1408.8845, 1089.8153, -17.3323, 90.0000, 0.0000, 0.0000); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(g_Object[61], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[62] = CreateDynamicObject(18980, 1408.8955, 1092.8044, -14.7292, 0.0000, 0.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[62], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[63] = CreateDynamicObject(18980, 1408.8955, 1081.8326, -14.7292, 0.0000, 0.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[63], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[64] = CreateDynamicObject(18980, 1401.8310, 1086.8431, -14.7292, 0.0000, 0.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[64], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[65] = CreateDynamicObject(18980, 1406.8735, 1075.8679, -17.3292, 0.0000, 90.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[65], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[66] = CreateDynamicObject(19380, 1400.2635, 1088.1844, -11.5607, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[66], 0, 3080, "adjumpx", "rustyboltpanel", 0x00000000);
	g_Object[67] = CreateDynamicObject(18980, 1406.8735, 1086.8404, -17.3292, 0.0000, 90.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[67], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[68] = CreateDynamicObject(18762, 1401.8227, 1089.7955, -17.3323, 90.0000, 0.0000, 0.0000); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(g_Object[68], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[69] = CreateDynamicObject(18980, 1406.8735, 1081.8287, -17.3292, 0.0000, 90.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[69], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[70] = CreateDynamicObject(18762, 1401.8227, 1078.8824, -17.3323, 90.0000, 0.0000, 0.0000); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(g_Object[70], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[71] = CreateDynamicObject(18762, 1408.8845, 1078.8624, -17.3323, 90.0000, 0.0000, 0.0000); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(g_Object[71], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[72] = CreateDynamicObject(18762, 1408.8845, 1084.8049, -17.3323, 90.0000, 0.0000, 0.0000); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(g_Object[72], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[73] = CreateDynamicObject(18980, 1401.8310, 1092.7757, -14.7292, 0.0000, 0.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[73], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[74] = CreateDynamicObject(18762, 1401.8227, 1084.7944, -17.3323, 90.0000, 0.0000, 0.0000); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(g_Object[74], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[75] = CreateDynamicObject(18980, 1401.8310, 1081.8319, -14.7292, 0.0000, 0.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[75], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[76] = CreateDynamicObject(2567, 1399.8293, 1074.3994, -24.0438, 0.0000, 0.0000, -5.2999); //ab_warehouseShelf
	SetDynamicObjectMaterial(g_Object[76], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[77] = CreateDynamicObject(18980, 1408.8819, 1075.9162, -14.7292, 0.0000, 0.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[77], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[78] = CreateDynamicObject(942, 1412.1650, 1074.6046, -23.9118, 63.2000, 0.0000, -4.2999); //CJ_DF_UNIT_2
	SetDynamicObjectMaterial(g_Object[78], 2, 19297, "matlights", "invisible", 0x00000000);
	g_Object[79] = CreateDynamicObject(5088, 1430.2568, 1090.6505, -17.1110, 0.0000, 0.0000, 90.0000); //alphbrk5_las
	g_Object[80] = CreateDynamicObject(3761, 1412.5788, 1081.8304, -23.9612, 0.0000, 0.0000, 90.0000); //industshelves
	SetDynamicObjectMaterial(g_Object[80], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
	g_Object[81] = CreateDynamicObject(18980, 1408.8955, 1086.8138, -14.7292, 0.0000, 0.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[81], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[82] = CreateDynamicObject(2567, 1412.5227, 1086.8203, -24.0449, 0.0000, 0.0000, 0.0000); //ab_warehouseShelf
	SetDynamicObjectMaterial(g_Object[82], 0, -1, "none", "none", 0xFFFFFFFF);
	SetDynamicObjectMaterial(g_Object[82], 1, 19297, "matlights", "invisible", 0x00000000);
	SetDynamicObjectMaterial(g_Object[82], 5, 19297, "matlights", "invisible", 0x00000000);
	g_Object[83] = CreateDynamicObject(18980, 1406.8735, 1092.7915, -17.3292, 0.0000, 90.0000, 0.0000); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(g_Object[83], 0, 3629, "arprtxxref_las", "rustybolts", 0x00000000);
	g_Object[84] = CreateDynamicObject(19321, 1412.1662, 1095.2386, -24.4444, 0.0000, 0.0000, 270.0000); //cuntainer
	g_Object[85] = CreateDynamicObject(3761, 1412.5788, 1092.7745, -20.0212, 0.0000, 0.0000, 90.0000); //industshelves
	SetDynamicObjectMaterial(g_Object[85], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
	g_Object[86] = CreateDynamicObject(2934, 1412.1936, 1095.2395, -21.5461, 0.0000, 0.0000, 270.0000); //kmb_container_red
	SetDynamicObjectMaterial(g_Object[86], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[87] = CreateDynamicObject(3761, 1398.2076, 1081.8398, -23.9612, 0.0000, 0.0000, 90.0000); //industshelves
	SetDynamicObjectMaterial(g_Object[87], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[88] = CreateDynamicObject(19380, 1400.2342, 1078.5760, -26.0209, 0.0000, 90.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[88], 0, 10756, "airportroads_sfse", "Heliconcrete", 0x00000000);
	g_Object[89] = CreateDynamicObject(2567, 1412.5227, 1086.8203, -20.5949, 0.0000, 0.0000, 0.0000); //ab_warehouseShelf
	SetDynamicObjectMaterial(g_Object[89], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[90] = CreateDynamicObject(2567, 1398.3398, 1092.8514, -24.0449, 0.0000, 0.0000, 0.0000); //ab_warehouseShelf
	SetDynamicObjectMaterial(g_Object[90], 0, -1, "none", "none", 0xFFFFFFFF);
	SetDynamicObjectMaterial(g_Object[90], 1, 19297, "matlights", "invisible", 0x00000000);
	SetDynamicObjectMaterial(g_Object[90], 5, 19297, "matlights", "invisible", 0x00000000);
	g_Object[91] = CreateDynamicObject(3062, 1408.6418, 1093.6672, -24.5429, 0.0000, 0.0000, 137.1999); //container_door
	SetDynamicObjectMaterial(g_Object[91], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[92] = CreateDynamicObject(3761, 1412.5788, 1078.3070, -23.9192, 0.0000, -35.8997, 90.0000); //industshelves
	SetDynamicObjectMaterial(g_Object[92], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
	g_Object[93] = CreateDynamicObject(942, 1411.0769, 1072.5129, -25.3756, 90.0000, 132.7998, 22.7999); //CJ_DF_UNIT_2
	SetDynamicObjectMaterial(g_Object[93], 2, 19297, "matlights", "invisible", 0x00000000);
	g_Object[94] = CreateDynamicObject(3006, 1407.5356, 1073.6684, -26.0263, 0.0000, 0.0000, 119.4999); //smash_box_brk
	SetDynamicObjectMaterial(g_Object[94], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[95] = CreateDynamicObject(4227, 1399.4333, 1064.2464, -24.5690, 0.0000, 0.0000, 180.0000); //graffiti_lan01
	g_Object[96] = CreateDynamicObject(3005, 1409.0931, 1069.2646, -25.9230, 0.0000, 0.0000, 85.7994); //smash_box_stay
	SetDynamicObjectMaterial(g_Object[96], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[97] = CreateDynamicObject(3761, 1398.2076, 1086.8404, -20.0011, 0.0000, 0.0000, 90.0000); //industshelves
	SetDynamicObjectMaterial(g_Object[97], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
	g_Object[98] = CreateDynamicObject(2666, 1397.8415, 1067.5002, -25.2681, 0.0000, 10.8000, 270.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[98], 0, "INSIDE", OBJECT_MATERIAL_SIZE_256x128, "Comic Sans MS", 60, 1, 0xFF000000, 0x00000000, 0);
	g_Object[99] = CreateDynamicObject(2666, 1397.8409, 1067.5190, -24.7879, 0.0000, 10.8000, 270.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterialText(g_Object[99], 0, "DEAD", OBJECT_MATERIAL_SIZE_256x128, "Comic Sans MS", 60, 1, 0xFF000000, 0x00000000, 0);
	g_Object[100] = CreateDynamicObject(19321, 1412.1643, 1100.9165, -24.4545, 0.0000, 0.0000, 270.0000); //cuntainer
	SetDynamicObjectMaterial(g_Object[100], 0, 10850, "bakerybit2_sfse", "frate64_red", 0x00000000);
	SetDynamicObjectMaterial(g_Object[100], 1, 10850, "bakerybit2_sfse", "frate_doors128red", 0x00000000);
	g_Object[101] = CreateDynamicObject(3062, 1408.6483, 1102.4503, -24.5429, 0.0000, 0.0000, -115.1001); //container_door
	SetDynamicObjectMaterial(g_Object[101], 0, 10850, "bakerybit2_sfse", "frate_doors128red", 0xFFFFFFFF);
	g_Object[102] = CreateDynamicObject(3062, 1408.6108, 1099.3370, -24.5128, 0.0000, 0.0000, 126.3996); //container_door
	SetDynamicObjectMaterial(g_Object[102], 0, 10850, "bakerybit2_sfse", "frate_doors128red", 0xFFFFFFFF);
	g_Object[103] = CreateDynamicObject(2567, 1398.3398, 1092.8514, -20.6047, 0.0000, 0.0000, 0.0000); //ab_warehouseShelf
	SetDynamicObjectMaterial(g_Object[103], 0, -1, "none", "none", 0xFFFFFFFF);
	SetDynamicObjectMaterial(g_Object[103], 1, 19297, "matlights", "invisible", 0x00000000);
	SetDynamicObjectMaterial(g_Object[103], 5, 19297, "matlights", "invisible", 0x00000000);
	g_Object[104] = CreateDynamicObject(3043, 1398.7862, 1095.7407, -24.4643, 0.0000, 0.0000, 90.0000); //kmb_container_open
	g_Object[105] = CreateDynamicObject(3043, 1398.7862, 1095.7407, -21.5543, 0.0000, 0.0000, 90.0000); //kmb_container_open
	SetDynamicObjectMaterial(g_Object[105], 0, 10850, "bakerybit2_sfse", "frate64_yellow", 0x00000000);
	SetDynamicObjectMaterial(g_Object[105], 1, 10850, "bakerybit2_sfse", "frate_doors64yellow", 0x00000000);
	g_Object[106] = CreateDynamicObject(3062, 1402.2934, 1094.2009, -24.5429, 0.0000, 0.0000, 89.8000); //container_door
	SetDynamicObjectMaterial(g_Object[106], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[107] = CreateDynamicObject(3062, 1403.6168, 1096.4342, -24.5429, 0.0000, 0.0000, 146.8000); //container_door
	SetDynamicObjectMaterial(g_Object[107], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[108] = CreateDynamicObject(3062, 1402.3186, 1095.7486, -21.6128, 0.0000, 0.0000, 91.0000); //container_door
	SetDynamicObjectMaterial(g_Object[108], 0, 10850, "bakerybit2_sfse", "frate_doors64yellow", 0xFFFFFFFF);
	g_Object[109] = CreateDynamicObject(3062, 1402.3454, 1094.1772, -21.6128, 0.0000, 0.0000, -52.3997); //container_door
	SetDynamicObjectMaterial(g_Object[109], 0, 10850, "bakerybit2_sfse", "frate_doors64yellow", 0xFFFFFFFF);
	g_Object[110] = CreateDynamicObject(1431, 1414.5233, 1096.3868, -25.3924, 0.0000, 0.0000, 0.0000); //DYN_BOX_PILE
	g_Object[111] = CreateDynamicObject(2567, 1405.3581, 1075.7541, -24.0538, 0.0000, 0.0000, 18.2999); //ab_warehouseShelf
	SetDynamicObjectMaterial(g_Object[111], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[112] = CreateDynamicObject(19087, 1404.1247, 1075.8750, -16.9001, 0.0000, 0.0000, 0.0000); //Rope1
	g_Object[113] = CreateDynamicObject(19380, 1415.8795, 1069.0091, -20.8572, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[113], 0, 12850, "cunte_block1", "ws_redbrickold", 0x00000000);
	g_Object[114] = CreateDynamicObject(1800, 1398.7711, 1094.7082, -26.0314, 0.0000, 0.0000, 90.0000); //LOW_BED_1
	g_Object[115] = CreateDynamicObject(3761, 1398.2076, 1086.8404, -23.9612, 0.0000, 0.0000, 90.0000); //industshelves
	SetDynamicObjectMaterial(g_Object[115], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
	g_Object[116] = CreateDynamicObject(3761, 1412.5788, 1092.7745, -23.9612, 0.0000, 0.0000, 90.0000); //industshelves
	SetDynamicObjectMaterial(g_Object[116], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
	g_Object[117] = CreateDynamicObject(3006, 1410.3048, 1077.1114, -26.5263, 0.0000, 0.0000, 92.0997); //smash_box_brk
	SetDynamicObjectMaterial(g_Object[117], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[118] = CreateDynamicObject(2632, 1405.2777, 1075.7956, -22.2723, 0.0000, 0.0000, -164.8002); //gym_mat02
	SetDynamicObjectMaterial(g_Object[118], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFF800000);
	g_Object[119] = CreateDynamicObject(2905, 1399.7423, 1075.9665, -25.7901, 0.0000, 90.0000, -14.3999); //kmb_deadleg
	g_Object[120] = CreateDynamicObject(2632, 1399.3946, 1075.8994, -25.9624, 0.0000, 0.0000, -7.1999); //gym_mat02
	SetDynamicObjectMaterial(g_Object[120], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFF800000);
	g_Object[121] = CreateDynamicObject(2632, 1399.5057, 1075.4277, -25.4824, 90.0000, 174.3000, 360.0000); //gym_mat02
	SetDynamicObjectMaterial(g_Object[121], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFF800000);
	g_Object[122] = CreateDynamicObject(2632, 1397.2263, 1067.1579, -25.9824, 0.0000, 0.0000, 0.0996); //gym_mat02
	SetDynamicObjectMaterial(g_Object[122], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFF800000);
	g_Object[123] = CreateDynamicObject(2632, 1397.8403, 1067.2523, -26.7241, -0.4999, -89.6996, 180.0000); //gym_mat02
	SetDynamicObjectMaterial(g_Object[123], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFF800000);
	g_Object[124] = CreateDynamicObject(1800, 1403.2124, 1094.6882, -26.0314, 0.0000, 0.0000, 90.0000); //LOW_BED_1
	g_Object[125] = CreateDynamicObject(1800, 1412.4227, 1094.1477, -26.0314, 0.0000, 0.0000, 90.0000); //LOW_BED_1
	g_Object[126] = CreateDynamicObject(5088, 1412.5406, 1083.6511, -17.1492, 0.0000, 0.0000, 90.0000); //alphbrk5_las
	g_Object[127] = CreateDynamicObject(5088, 1423.8686, 1077.1805, -17.1492, 0.0000, 0.0000, 90.0000); //alphbrk5_las
	g_Object[128] = CreateDynamicObject(5088, 1413.8913, 1099.8581, -17.1492, 0.0000, 0.0000, 90.0000); //alphbrk5_las
	g_Object[129] = CreateDynamicObject(2907, 1399.5388, 1075.5809, -25.4967, -90.8000, -179.6999, -179.3000); //kmb_deadtorso
	g_Object[130] = CreateDynamicObject(2905, 1399.4569, 1076.0083, -25.7901, 0.0000, 90.0000, -0.1999); //kmb_deadleg
	g_Object[131] = CreateDynamicObject(2906, 1399.7452, 1075.5697, -25.5230, -71.2997, -6.4998, -47.9998); //kmb_deadarm
	g_Object[132] = CreateDynamicObject(19087, 1405.9764, 1075.8750, -16.9001, 0.0000, 0.0000, 0.0000); //Rope1
	g_Object[133] = CreateDynamicObject(19793, 1405.3690, 1089.6489, -25.8418, 0.0000, 0.0000, 0.0000); //FireWoodLog1
	g_Object[134] = CreateDynamicObject(19793, 1405.3690, 1089.6489, -25.8418, 0.0000, 0.0000, 90.6997); //FireWoodLog1
	g_Object[135] = CreateDynamicObject(19793, 1405.3690, 1089.6489, -25.8418, 0.0000, 0.0000, 132.1999); //FireWoodLog1
	g_Object[136] = CreateDynamicObject(19793, 1405.3690, 1089.6489, -25.8418, 0.0000, 0.0000, 43.3997); //FireWoodLog1
	g_Object[137] = CreateDynamicObject(1369, 1405.3308, 1091.6217, -25.3903, 0.0000, 0.0000, 0.0000); //CJ_WHEELCHAIR1
	g_Object[138] = CreateDynamicObject(1810, 1406.7292, 1089.7768, -26.0886, 0.0000, 0.0000, -79.2997); //CJ_FOLDCHAIR
	g_Object[139] = CreateDynamicObject(3761, 1398.2076, 1081.8402, -20.0011, 0.0000, 0.0000, 90.0000); //industshelves
	SetDynamicObjectMaterial(g_Object[139], 0, 19297, "matlights", "invisible", 0xFFFFFFFF);
	g_Object[140] = CreateDynamicObject(1711, 1403.9073, 1088.4890, -25.9391, 0.0000, 0.0000, 129.6999); //kb_chair01
	g_Object[141] = CreateDynamicObject(1810, 1404.1551, 1090.5227, -26.0886, 0.0000, 0.0000, 60.5000); //CJ_FOLDCHAIR
	g_Object[142] = CreateDynamicObject(2907, 1404.1522, 1075.8216, -19.8008, -90.0000, 90.0000, 270.0000); //kmb_deadtorso
	g_Object[143] = CreateDynamicObject(2908, 1404.1363, 1075.7755, -19.2511, -90.0000, -270.0000, 180.0000); //kmb_deadhead
	g_Object[144] = CreateDynamicObject(2908, 1405.9781, 1075.7755, -19.2511, -90.0000, -270.0000, 180.0000); //kmb_deadhead
	g_Object[145] = CreateDynamicObject(2907, 1406.0135, 1075.8216, -19.8008, -90.0000, 90.0000, 270.0000); //kmb_deadtorso
	g_Object[146] = CreateDynamicObject(2905, 1404.0196, 1075.7734, -20.5352, -90.0000, 90.0000, 180.0000); //kmb_deadleg
	g_Object[147] = CreateDynamicObject(2905, 1404.2298, 1075.7734, -20.5352, -90.0000, 90.0000, 180.0000); //kmb_deadleg
	g_Object[148] = CreateDynamicObject(2905, 1405.8813, 1075.7734, -20.5352, -90.0000, 90.0000, 180.0000); //kmb_deadleg
	g_Object[149] = CreateDynamicObject(2905, 1406.0915, 1075.7734, -20.5352, -88.4000, 89.3000, 179.3999); //kmb_deadleg
	g_Object[150] = CreateDynamicObject(1800, 1416.7038, 1094.1778, -26.0314, 0.0000, 0.0000, 90.0000); //LOW_BED_1
	g_Object[151] = CreateDynamicObject(1810, 1405.8656, 1088.3094, -26.0886, 0.0000, 0.0000, -149.6997); //CJ_FOLDCHAIR
	g_Object[152] = CreateDynamicObject(1431, 1412.3344, 1096.3868, -25.3924, 0.0000, 0.0000, 0.0000); //DYN_BOX_PILE
	g_Object[153] = CreateDynamicObject(1431, 1410.1729, 1096.3868, -25.3924, 0.0000, 0.0000, 0.0000); //DYN_BOX_PILE
	g_Object[154] = CreateDynamicObject(1431, 1396.3166, 1096.9273, -25.3924, 0.0000, 0.0000, 0.0000); //DYN_BOX_PILE
	g_Object[155] = CreateDynamicObject(1431, 1398.4862, 1096.9273, -25.3924, 0.0000, 0.0000, 0.0000); //DYN_BOX_PILE


    return Y_HOOKS_CONTINUE_RETURN_1;
}
