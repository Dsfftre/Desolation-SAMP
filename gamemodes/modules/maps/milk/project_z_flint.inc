#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new g_Object[709];
    g_Object[0] = CreateDynamicObject(1442, -56.1169, -1586.9291, 2.2137, 0.0000, 0.0000, 0.0000); //DYN_FIREBIN0
    g_Object[1] = CreateDynamicObject(3585, -140.3609, -1024.0799, 12.0184, 0.0000, 0.0000, 13.3000); //lastran1_LA02
    g_Object[2] = CreateDynamicObject(3593, -75.2928, -1122.2556, 0.5781, 0.0000, 0.0000, -55.9000); //la_fuckcar2
    g_Object[3] = //CreateDynamicObject(874, -89.1305, -947.6688, 21.1681, -4.0998, 0.0000, -30.7999); //veg_procgrasspatch
    g_Object[4] = CreateDynamicObject(3593, -121.7994, -975.1895, 24.9375, -7.2999, 0.0000, 0.0000); //la_fuckcar2
    g_Object[5] = //CreateDynamicObject(874, -112.9328, -944.2318, 21.8178, -4.0998, -4.5998, -43.4000); //veg_procgrasspatch
    g_Object[6] = //CreateDynamicObject(874, -107.8113, -981.8114, 25.3204, -1.0000, -2.1998, -32.4000); //veg_procgrasspatch
    g_Object[7] = //CreateDynamicObject(874, -91.8777, -968.8950, 23.6860, -1.9996, -6.6999, -101.6996); //veg_procgrasspatch
    g_Object[8] = //CreateDynamicObject(874, -80.3980, -958.6821, 22.1506, -8.8000, 5.1999, 0.0000); //veg_procgrasspatch
    g_Object[9] = //CreateDynamicObject(874, -122.3358, -960.0734, 24.4202, -4.0998, -4.8997, -42.0000); //veg_procgrasspatch
    g_Object[10] = //CreateDynamicObject(874, -129.9967, -953.2598, 23.5436, -5.5998, -2.9999, -42.0000); //veg_procgrasspatch
    g_Object[11] = CreateDynamicObject(672, -97.6202, -960.9133, 22.5827, 0.0000, 0.0000, 0.0000); //sm_veg_tree5
    g_Object[12] = CreateDynamicObject(703, -97.8302, -984.5626, 24.1695, -1.6999, 0.0000, 0.0000); //sm_veg_tree7_big
    g_Object[13] = CreateDynamicObject(708, -126.1539, -952.3792, 22.1380, -2.8998, 0.0000, 0.0000); //sm_veg_tree4_vbig
    g_Object[14] = CreateDynamicObject(3594, -105.5658, -946.2686, 21.2891, -5.9998, -0.3000, -28.3999); //la_fuckcar1
    g_Object[15] = //CreateDynamicObject(874, -75.4281, -942.3950, 19.4605, -4.0998, -4.0998, -89.8999); //veg_procgrasspatch
    g_Object[16] = //CreateDynamicObject(874, -111.1305, -927.5828, 19.2541, -9.9996, 1.6000, 44.9999); //veg_procgrasspatch
    //g_Object[17] = CreateDynamicObject(3593, -93.0108, -932.3234, 19.1326, -6.1999, 0.0000, 0.0000); //la_fuckcar2
    g_Object[18] = CreateDynamicObject(3594, -108.9243, -952.4802, 22.0312, -5.9998, 0.1999, -21.1000); //la_fuckcar1
    g_Object[19] = CreateDynamicObject(12957, -112.6249, -969.6843, 24.0118, 4.0998, -8.6000, 176.4998); //sw_pickupwreck01
    g_Object[20] = CreateDynamicObject(1228, -92.2620, -1023.9074, 23.2807, 0.5999, -106.5998, -55.4000); //roadworkbarrier1
    g_Object[21] = CreateDynamicObject(3594, -98.0639, -1014.2932, 23.7084, 0.0000, 0.0000, 0.0000); //la_fuckcar1
    g_Object[22] = //CreateDynamicObject(874, -101.0391, -989.9572, 25.1105, 3.2999, 0.1000, -32.4000); //veg_procgrasspatch
    g_Object[23] = CreateDynamicObject(639, -137.0189, -978.5598, 29.1133, 0.0000, 0.0000, -35.2000); //veg_ivy_balcny_kb3
    g_Object[24] = CreateDynamicObject(639, -117.3152, -990.2866, 29.4001, 0.0000, 0.0000, -42.2999); //veg_ivy_balcny_kb3
    g_Object[25] = //CreateDynamicObject(874, -129.5296, -965.3201, 25.8430, -0.2000, -12.4996, -129.0000); //veg_procgrasspatch
    g_Object[26] = //CreateDynamicObject(874, -139.5386, -956.9647, 26.7670, -0.2000, -19.0998, -129.0000); //veg_procgrasspatch
    g_Object[27] = CreateDynamicObject(3594, -107.6994, -1010.2644, 23.6630, 0.0000, -2.6998, 25.0000); //la_fuckcar1
    g_Object[28] = CreateDynamicObject(3593, -89.7714, -1027.7723, 23.5858, 0.0000, -2.0999, 29.7999); //la_fuckcar2
    g_Object[29] = CreateDynamicObject(1228, -92.4389, -1033.7137, 23.3386, 0.0000, -102.7994, 0.0000); //roadworkbarrier1
    g_Object[30] = CreateDynamicObject(3594, -98.8071, -1027.4527, 23.7084, 0.0000, 0.0000, -131.3997); //la_fuckcar1
    g_Object[31] = //CreateDynamicObject(874, -335.7943, -1654.1462, 23.2523, 0.0000, 12.4998, 0.0000); //veg_procgrasspatch
    g_Object[32] = CreateDynamicObject(19420, -98.0429, -1014.0966, 24.3145, 0.0000, 0.0000, -5.1999); //police_lights02
    g_Object[33] = CreateDynamicObject(639, -207.6380, -936.5579, 58.4827, -8.3999, 0.0000, -126.5000); //veg_ivy_balcny_kb3
    g_Object[34] = CreateDynamicObject(1228, -94.0764, -1035.7873, 23.6821, 0.0000, 0.0000, -56.2999); //roadworkbarrier1
    g_Object[35] = CreateDynamicObject(9812, -101.9897, -1005.8372, 15.5311, 0.0000, 0.0000, 122.5998); //veg_ivy_balcny_kb08
    g_Object[36] = CreateDynamicObject(9812, -109.3610, -1010.4420, 15.5311, 0.0000, 0.0000, -57.2998); //veg_ivy_balcny_kb08
    g_Object[37] = CreateDynamicObject(691, -132.9915, -990.4929, 23.4804, 1.6000, 0.0000, 0.0000); //sm_veg_tree4_big
    g_Object[38] = //CreateDynamicObject(874, -150.4329, -970.4232, 27.6068, -3.2999, -7.0998, -129.0000); //veg_procgrasspatch
    g_Object[39] = CreateDynamicObject(1238, -94.8675, -1019.4815, 23.2444, 0.0000, -105.0998, 0.0000); //trafficcone
    g_Object[40] = CreateDynamicObject(639, -194.3887, -946.5609, 56.1730, -4.7999, 0.0000, -126.5000); //veg_ivy_balcny_kb3
    g_Object[41] = CreateDynamicObject(639, -180.9624, -956.3333, 55.4308, 0.3000, 0.0000, -126.5000); //veg_ivy_balcny_kb3
    g_Object[42] = CreateDynamicObject(639, -184.7808, -953.5076, 55.4659, 0.3000, 0.0000, -126.5000); //veg_ivy_balcny_kb3
    g_Object[43] = CreateDynamicObject(639, -222.1793, -925.8228, 61.8997, -12.8000, 0.0000, -126.5000); //veg_ivy_balcny_kb3
    g_Object[44] = CreateDynamicObject(639, -230.8365, -919.4171, 64.6026, -15.6997, 0.0000, -126.5000); //veg_ivy_balcny_kb3
    g_Object[45] = CreateDynamicObject(639, -235.1885, -916.1967, 65.9999, -15.6997, 0.0000, -126.5000); //veg_ivy_balcny_kb3
    g_Object[46] = CreateDynamicObject(639, -206.9967, -947.6812, 57.9323, 6.6999, 0.0000, 52.8997); //veg_ivy_balcny_kb3
    g_Object[47] = CreateDynamicObject(639, -221.0171, -937.5670, 60.6273, 11.7999, 0.0000, 55.2998); //veg_ivy_balcny_kb3
    g_Object[48] = CreateDynamicObject(639, -225.4290, -934.3789, 61.7644, 11.7999, 0.0000, 53.2999); //veg_ivy_balcny_kb3
    g_Object[49] = //CreateDynamicObject(874, -79.9160, -1039.0926, 22.1958, 4.9998, 9.8999, -32.0998); //veg_procgrasspatch
    g_Object[50] = CreateDynamicObject(639, -165.9857, -967.3422, 55.0811, -10.3999, 0.0000, -125.0000); //veg_ivy_balcny_kb3
    g_Object[51] = CreateDynamicObject(639, -153.3271, -976.2791, 52.5923, -7.0998, 0.0000, -125.0000); //veg_ivy_balcny_kb3
    g_Object[52] = CreateDynamicObject(639, -148.8238, -979.4321, 51.9076, -7.0998, 0.0000, -125.0000); //veg_ivy_balcny_kb3
    g_Object[53] = CreateDynamicObject(639, -127.2985, -994.7719, 49.6021, -3.7999, 0.0000, -125.5000); //veg_ivy_balcny_kb3
    g_Object[54] = CreateDynamicObject(639, -115.2164, -1003.3167, 48.8273, -2.3998, 0.0000, -125.5000); //veg_ivy_balcny_kb3
    g_Object[55] = CreateDynamicObject(639, -110.9729, -1006.2824, 48.6902, -0.8999, 0.0000, -125.6996); //veg_ivy_balcny_kb3
    g_Object[56] = CreateDynamicObject(639, -106.4542, -1009.5045, 48.6529, -0.8999, 0.0000, -124.9000); //veg_ivy_balcny_kb3
    g_Object[57] = CreateDynamicObject(639, -92.2751, -1019.3964, 49.0717, 1.8997, 0.0000, -124.0998); //veg_ivy_balcny_kb3
    g_Object[58] = CreateDynamicObject(639, -76.2611, -1030.8553, 50.8358, 7.2999, 0.0000, -125.0998); //veg_ivy_balcny_kb3
    g_Object[59] = CreateDynamicObject(639, -148.6940, -988.2462, 51.7639, 6.5000, -0.6998, 56.5998); //veg_ivy_balcny_kb3
    g_Object[60] = CreateDynamicObject(639, -131.8110, -999.6160, 50.1068, 2.5999, -0.6998, 55.4999); //veg_ivy_balcny_kb3
    g_Object[61] = CreateDynamicObject(639, -107.8346, -1015.9066, 49.0926, -0.8999, -1.2999, 55.4999); //veg_ivy_balcny_kb3
    g_Object[62] = CreateDynamicObject(639, -103.4884, -1018.8330, 49.1758, -0.8999, -1.2999, 55.4999); //veg_ivy_balcny_kb3
    g_Object[63] = CreateDynamicObject(639, -90.2070, -1027.8149, 49.8805, -4.2999, -1.2999, 55.4999); //veg_ivy_balcny_kb3
    g_Object[64] = CreateDynamicObject(3244, -64.4280, -1043.1224, 18.0846, 0.0000, 0.0000, 38.7999); //pylon_big1_
    SetDynamicObjectMaterial(g_Object[64], 0, 3900, "station", "rustd64", 0x00000000);
    g_Object[65] = //CreateDynamicObject(874, -90.9393, -1048.2602, 21.1403, 18.0998, -1.6999, 0.0996); //veg_procgrasspatch
    g_Object[66] = //CreateDynamicObject(874, -59.7444, -1050.8459, 19.1152, 16.0000, -6.7999, 26.6998); //veg_procgrasspatch
    g_Object[67] = //CreateDynamicObject(874, -58.9692, -1035.7668, 20.3829, -5.9998, -5.3997, 0.0000); //veg_procgrasspatch
    g_Object[68] = //CreateDynamicObject(874, -69.0345, -1035.8100, 19.9661, -7.5998, -5.3997, 0.0000); //veg_procgrasspatch
    g_Object[69] = CreateDynamicObject(825, -80.0063, -1030.7158, 23.1937, 3.7000, 7.6999, 0.0000); //genVEG_bushy
    g_Object[70] = CreateDynamicObject(669, -73.0401, -1050.9514, 17.7786, 0.0000, 3.2000, 0.0000); //sm_veg_tree4
    g_Object[71] = //CreateDynamicObject(874, -63.8451, -1067.3620, 14.7917, 17.6000, -2.8998, 9.9996); //veg_procgrasspatch
    g_Object[72] = //CreateDynamicObject(874, -66.8627, -1076.3756, 11.8816, 18.5000, 6.5998, -15.3999); //veg_procgrasspatch
    g_Object[73] = //CreateDynamicObject(874, -69.2908, -1089.8027, 7.3021, 18.5000, 6.5998, -15.3999); //veg_procgrasspatch
    g_Object[74] = //CreateDynamicObject(874, -66.7294, -1098.5494, 4.8846, -5.3997, 11.3000, -108.9000); //veg_procgrasspatch
    g_Object[75] = CreateDynamicObject(703, -64.4240, -1094.1610, 3.5933, 0.0000, 0.0000, 0.0000); //sm_veg_tree7_big
    g_Object[76] = //CreateDynamicObject(874, -91.6023, -1058.5067, 18.2751, 18.0998, -1.6999, -14.5000); //veg_procgrasspatch
    g_Object[77] = CreateDynamicObject(825, -129.1764, -994.0894, 25.8511, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[78] = CreateDynamicObject(825, -112.1128, -979.6290, 25.0498, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[79] = CreateDynamicObject(825, -116.6212, -952.9431, 23.2406, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[80] = CreateDynamicObject(825, -88.4888, -937.3037, 19.9785, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[81] = CreateDynamicObject(825, -89.9412, -1066.2397, 15.6920, 11.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[82] = CreateDynamicObject(825, -64.9207, -1048.4575, 19.3682, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[83] = CreateDynamicObject(825, -146.9644, -955.1038, 28.6816, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[84] = CreateDynamicObject(19362, -109.2200, -970.2423, 22.8745, -5.0998, 92.3000, -1.4996); //wall010
    SetDynamicObjectMaterial(g_Object[84], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[85] = CreateDynamicObject(19362, -108.4324, -970.2583, 22.8474, -8.6997, 79.9000, -13.5998); //wall010
    SetDynamicObjectMaterial(g_Object[85], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[86] = CreateDynamicObject(2907, -109.1712, -969.9514, 22.9687, -0.7997, 0.0000, 21.0000); //kmb_deadtorso
    g_Object[87] = CreateDynamicObject(2906, -108.9123, -969.8878, 22.9549, 0.0000, 0.0000, 0.0000); //kmb_deadarm
    g_Object[88] = CreateDynamicObject(19354, -98.0137, -1025.9598, 23.0317, 0.0000, 90.0000, 90.0000); //wall002
    SetDynamicObjectMaterial(g_Object[88], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[89] = CreateDynamicObject(19354, -99.6035, -1014.5498, 23.0816, 0.6998, 89.0000, 91.2994); //wall002
    SetDynamicObjectMaterial(g_Object[89], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[90] = CreateDynamicObject(19088, -68.5929, -1045.9388, 48.9793, 0.0000, 0.0000, 0.0000); //Rope2
    g_Object[91] = CreateDynamicObject(3092, -68.5867, -1046.1671, 45.5251, 0.0000, 0.0000, 123.8000); //dead_tied_cop
    g_Object[92] = CreateDynamicObject(825, -71.2014, -1066.1020, 14.9856, 10.8999, 0.0000, 0.0000); //genVEG_bushy
    g_Object[93] = //CreateDynamicObject(874, -91.6893, -1073.1174, 13.4509, 22.1000, -0.1000, -14.0000); //veg_procgrasspatch
    g_Object[94] = //CreateDynamicObject(874, -99.3376, -1109.5113, 1.5951, 0.0000, 0.0000, -32.2000); //veg_procgrasspatch
    g_Object[95] = //CreateDynamicObject(874, -97.2873, -1104.4088, 2.8989, 17.5998, 1.6999, -38.7999); //veg_procgrasspatch
    g_Object[96] = //CreateDynamicObject(874, -109.5121, -1134.1239, 1.3451, 0.0000, 0.0000, -41.2000); //veg_procgrasspatch
    g_Object[97] = CreateDynamicObject(825, -102.3059, -1159.7541, 2.1844, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[98] = //CreateDynamicObject(874, -117.0436, -1138.4144, 1.7755, 0.0000, 0.0000, -41.2000); //veg_procgrasspatch
    g_Object[99] = //CreateDynamicObject(874, -121.5904, -1156.1638, 2.4453, 0.0000, 0.0000, -30.7999); //veg_procgrasspatch
    g_Object[100] = //CreateDynamicObject(874, -103.9391, -1166.6861, 2.4453, 0.0000, 0.0000, -30.7999); //veg_procgrasspatch
    g_Object[101] = //CreateDynamicObject(874, -109.0659, -1176.0290, 2.4453, 0.0000, 0.0000, -30.7999); //veg_procgrasspatch
    g_Object[102] = //CreateDynamicObject(874, -101.4561, -1159.6938, 1.9155, 0.0000, 0.0000, 149.0997); //veg_procgrasspatch
    g_Object[103] = CreateDynamicObject(825, -110.3311, -1178.2248, 2.8905, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[104] = CreateDynamicObject(825, -116.7070, -1151.8166, 1.6539, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[105] = CreateDynamicObject(639, -88.5494, -1138.5327, 1.5398, 0.0000, 0.0000, 63.4000); //veg_ivy_balcny_kb3
    g_Object[106] = CreateDynamicObject(825, -75.0802, -1097.8714, 5.2168, 9.3000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[107] = //CreateDynamicObject(874, -128.7893, -1168.7495, 3.1872, 1.0999, 0.0000, 156.0997); //veg_procgrasspatch
    g_Object[108] = CreateDynamicObject(825, -129.8807, -1177.3750, 3.3104, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[109] = CreateDynamicObject(17072, -43.4832, -1118.7701, 1.7934, 8.2999, 0.0000, 0.0000); //smltrukext
    g_Object[110] = CreateDynamicObject(10984, -54.9323, -1124.5312, 1.0348, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[111] = CreateDynamicObject(10984, -40.5340, -1123.2445, 1.0348, 0.0000, 0.0000, -17.6000); //rubbled01_SFS
    g_Object[112] = CreateDynamicObject(10984, -54.5787, -1133.0577, 1.0348, 0.0000, 0.0000, -17.6000); //rubbled01_SFS
    g_Object[113] = CreateDynamicObject(10985, -45.5172, -1138.2617, 0.4781, 0.0000, 0.0000, 0.0000); //rubbled02_SFS
    g_Object[114] = CreateDynamicObject(10986, -36.0936, -1134.4652, 1.0598, 0.0000, 0.0000, -26.8999); //rubbled03_SFS
    g_Object[115] = CreateDynamicObject(10984, -38.3230, -1127.6064, 0.8733, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[116] = //CreateDynamicObject(874, -60.0928, -1117.2988, 1.1828, 0.0000, 0.0000, -80.9999); //veg_procgrasspatch
    g_Object[117] = //CreateDynamicObject(874, -46.0792, -1116.7392, 1.1828, 0.0000, 0.0000, -110.4999); //veg_procgrasspatch
    g_Object[118] = CreateDynamicObject(3594, -78.7985, -1114.9621, 0.6467, 0.0000, 0.0000, 0.0000); //la_fuckcar1
    g_Object[119] = //CreateDynamicObject(874, -86.2078, -1145.1395, 1.7252, 0.0000, 0.0000, -120.5000); //veg_procgrasspatch
    g_Object[120] = CreateDynamicObject(3566, -67.3328, -1123.8011, 1.7209, 0.0000, 90.1996, 0.0000); //lasntrk1
    g_Object[121] = //CreateDynamicObject(874, -78.1539, -1149.0599, 1.7252, 0.0000, 0.0000, 61.9995); //veg_procgrasspatch
    g_Object[122] = CreateDynamicObject(670, -166.0216, -1229.5672, 9.2426, 0.0000, -0.8999, 0.0000); //sm_firtallded
    g_Object[123] = CreateDynamicObject(3566, -48.2210, -1148.5322, 2.5136, 0.0000, 0.0000, 66.7994); //lasntrk1
    g_Object[124] = CreateDynamicObject(10984, -39.9817, -1146.0926, 1.1036, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[125] = CreateDynamicObject(825, -71.0158, -1149.5943, 2.1844, 0.0000, 0.0000, 15.3999); //genVEG_bushy
    g_Object[126] = CreateDynamicObject(1221, -68.7518, -1134.5345, 0.5382, 0.0000, 0.0000, 32.9999); //cardboardbox4
    g_Object[127] = CreateDynamicObject(1221, -66.1259, -1135.7862, 0.5382, 90.1996, 0.0000, 32.9999); //cardboardbox4
    g_Object[128] = CreateDynamicObject(928, -66.9804, -1135.8946, 0.3276, 0.0000, 0.0000, 0.0000); //RUBBISH_BOX1
    g_Object[129] = CreateDynamicObject(2059, -68.0829, -1134.7663, 0.1080, 0.0000, 0.0000, 0.0000); //CJ_GUNSTUFF1
    g_Object[130] = CreateDynamicObject(3005, -66.8750, -1134.0561, 0.0979, 0.0000, 0.0000, 37.5000); //smash_box_stay
    g_Object[131] = CreateDynamicObject(19358, -73.6735, -1122.9707, 0.0281, 0.0000, 90.0000, 0.0000); //wall006
    SetDynamicObjectMaterial(g_Object[131], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[132] = CreateDynamicObject(19358, -78.7638, -1119.0808, 0.0281, 0.0000, 89.6996, -54.7999); //wall006
    SetDynamicObjectMaterial(g_Object[132], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[133] = CreateDynamicObject(19358, -71.3125, -1102.9278, 0.1981, 0.0000, 0.0000, 70.1996); //wall006
    SetDynamicObjectMaterial(g_Object[133], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFF800000);
    g_Object[134] = CreateDynamicObject(19358, -71.3125, -1102.9278, 0.0081, 0.0000, 90.0000, 70.1996); //wall006
    SetDynamicObjectMaterial(g_Object[134], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFF800000);
    g_Object[135] = CreateDynamicObject(2907, -71.6744, -1103.0140, 0.3158, -90.7994, 0.0000, 162.1999); //kmb_deadtorso
    g_Object[136] = CreateDynamicObject(2905, -71.9496, -1103.2497, 0.1465, 6.0998, 87.9000, 156.3000); //kmb_deadleg
    g_Object[137] = CreateDynamicObject(2906, -72.0223, -1102.9840, 0.5033, -154.0997, 100.5998, -73.3999); //kmb_deadarm
    g_Object[138] = CreateDynamicObject(2036, -71.3429, -1103.7547, 0.0979, 0.0000, 0.0000, 0.0000); //CJ_psg1
    g_Object[139] = CreateDynamicObject(1486, -72.0436, -1102.8520, 0.2231, 0.0000, 0.0000, 0.0000); //DYN_BEER_1
    g_Object[140] = CreateDynamicObject(19358, -77.0727, -1103.8725, -0.0017, 0.0000, 90.0000, 70.1996); //wall006
    SetDynamicObjectMaterial(g_Object[140], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFF800000);
    g_Object[141] = CreateDynamicObject(2907, -76.9263, -1104.1949, 0.1307, 0.0000, 0.0000, 0.0000); //kmb_deadtorso
    g_Object[142] = CreateDynamicObject(1486, -76.2990, -1104.6975, 0.1027, -89.5998, 46.2000, 0.0000); //DYN_BEER_1
    g_Object[143] = CreateDynamicObject(1486, -76.4513, -1104.6335, 0.2231, 0.0000, 0.0000, 0.0000); //DYN_BEER_1
    g_Object[144] = CreateDynamicObject(2035, -76.1434, -1103.9265, 0.0881, 0.0000, 0.0000, 20.1998); //CJ_M16
    g_Object[145] = //CreateDynamicObject(874, -20.6725, -1135.5289, 4.6666, 0.0000, -27.3999, 0.0000); //veg_procgrasspatch
    g_Object[146] = CreateDynamicObject(10984, -70.4660, -1140.1140, 0.7350, 0.0000, 0.0000, -74.6996); //rubbled01_SFS
    g_Object[147] = //CreateDynamicObject(874, -55.8600, -1101.9222, 4.9190, 0.0000, -11.8000, 69.2994); //veg_procgrasspatch
    g_Object[148] = CreateDynamicObject(969, -87.8822, -1125.2220, 0.1694, 0.0000, 0.0000, 65.8000); //Electricgate
    SetDynamicObjectMaterial(g_Object[148], 0, 3439, "xrefairtree", "rustadark128", 0x00000000);
    g_Object[149] = CreateDynamicObject(969, -91.9729, -1134.3249, 0.1694, -89.5998, 15.3000, 65.8000); //Electricgate
    SetDynamicObjectMaterial(g_Object[149], 0, 3439, "xrefairtree", "rustadark128", 0x00000000);
    g_Object[150] = //CreateDynamicObject(874, -42.9048, -1105.5183, 5.4720, 1.7999, 7.0998, -116.0998); //veg_procgrasspatch
    g_Object[151] = //CreateDynamicObject(874, -32.3884, -1109.1883, 5.9854, 1.7999, 7.0998, -116.0998); //veg_procgrasspatch
    g_Object[152] = CreateDynamicObject(659, -36.7933, -1108.3103, 4.9113, 0.0000, 0.0000, 0.0000); //pinetree01
    g_Object[153] = CreateDynamicObject(660, -39.1896, -1104.7026, 4.5345, 0.0000, 0.0000, 0.0000); //pinetree03
    g_Object[154] = CreateDynamicObject(657, -32.6939, -1104.0080, 6.8087, 0.0000, 0.0000, 0.0000); //pinetree02
    g_Object[155] = CreateDynamicObject(654, -29.5333, -1111.1850, 5.7571, 0.0000, 0.0000, 143.4998); //pinetree08
    g_Object[156] = //CreateDynamicObject(874, -23.2147, -1113.2176, 6.0718, 0.0000, -14.3000, 69.2994); //veg_procgrasspatch
    g_Object[157] = //CreateDynamicObject(874, -20.6725, -1145.2695, 4.6666, 18.6998, -19.7999, -30.3999); //veg_procgrasspatch
    g_Object[158] = //CreateDynamicObject(874, -36.5335, -1166.5323, 2.8255, -3.6998, 12.5999, 77.2994); //veg_procgrasspatch
    g_Object[159] = CreateDynamicObject(825, -19.3029, -1144.5517, 5.2445, 0.0000, -17.1000, 0.0000); //genVEG_bushy
    g_Object[160] = CreateDynamicObject(825, -43.8064, -1168.4851, 3.0339, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[161] = CreateDynamicObject(703, -116.9457, -1208.9465, 1.4127, 0.0000, 0.0000, 0.0000); //sm_veg_tree7_big
    g_Object[162] = CreateDynamicObject(639, -59.1935, -1057.1274, 48.6575, -16.1000, 0.0000, -174.3997); //veg_ivy_balcny_kb3
    g_Object[163] = CreateDynamicObject(639, -57.7876, -1069.5194, 45.2667, -12.6997, 0.0000, -172.5997); //veg_ivy_balcny_kb3
    g_Object[164] = CreateDynamicObject(639, -57.1104, -1074.7336, 44.0820, -12.6997, 0.0000, -172.5997); //veg_ivy_balcny_kb3
    g_Object[165] = CreateDynamicObject(639, -55.7055, -1086.2513, 41.7033, -10.3999, 0.0000, -172.5997); //veg_ivy_balcny_kb3
    g_Object[166] = CreateDynamicObject(639, -54.2732, -1098.4449, 39.4504, -9.1000, 0.0000, -172.5997); //veg_ivy_balcny_kb3
    g_Object[167] = CreateDynamicObject(639, -51.8600, -1117.8790, 36.7285, -7.3000, 0.0000, -172.8995); //veg_ivy_balcny_kb3
    g_Object[168] = CreateDynamicObject(639, -49.5068, -1137.3374, 35.3367, -3.7000, 0.0000, -174.2996); //veg_ivy_balcny_kb3
    g_Object[169] = CreateDynamicObject(639, -47.3292, -1154.6207, 35.5134, -0.6000, 0.0000, -175.6996); //veg_ivy_balcny_kb3
    g_Object[170] = CreateDynamicObject(639, -65.0584, -1050.7677, 51.3652, 15.1997, 0.0000, 5.1002); //veg_ivy_balcny_kb3
    g_Object[171] = CreateDynamicObject(639, -64.0569, -1064.2392, 47.3016, 15.1997, 0.0000, 3.8001); //veg_ivy_balcny_kb3
    g_Object[172] = CreateDynamicObject(639, -63.4006, -1073.5157, 44.9719, 13.6997, 0.0000, 3.8001); //veg_ivy_balcny_kb3
    g_Object[173] = CreateDynamicObject(639, -62.3422, -1088.1097, 41.7783, 12.2999, 0.0000, 5.3000); //veg_ivy_balcny_kb3
    g_Object[174] = CreateDynamicObject(639, -61.8656, -1093.7867, 40.5363, 10.8998, 0.0000, 5.3000); //veg_ivy_balcny_kb3
    g_Object[175] = CreateDynamicObject(639, -60.8474, -1106.8177, 38.4668, 8.6997, 0.0000, 3.6001); //veg_ivy_balcny_kb3
    g_Object[176] = CreateDynamicObject(639, -59.6440, -1123.0085, 36.4570, 6.2996, 0.0000, 5.3000); //veg_ivy_balcny_kb3
    g_Object[177] = CreateDynamicObject(639, -58.1547, -1142.2015, 35.2676, 1.6998, 0.0000, 5.3000); //veg_ivy_balcny_kb3
    g_Object[178] = //CreateDynamicObject(874, -112.6958, -1201.7839, 3.1078, 0.0000, 0.0000, -115.5998); //veg_procgrasspatch
    g_Object[179] = //CreateDynamicObject(874, -104.6408, -1207.3680, 3.1078, 0.0000, 0.0000, -14.0000); //veg_procgrasspatch
    g_Object[180] = //CreateDynamicObject(874, -101.0080, -1217.4908, 2.8979, 0.0000, 0.0000, 51.7999); //veg_procgrasspatch
    g_Object[181] = //CreateDynamicObject(874, -88.7030, -1220.5937, 2.8979, 0.0000, 0.0000, 82.9999); //veg_procgrasspatch
    g_Object[182] = CreateDynamicObject(825, -116.6147, -1196.8437, 2.6953, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[183] = CreateDynamicObject(825, -190.4745, -1198.2718, 8.1805, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[184] = //CreateDynamicObject(874, -78.1771, -1215.6097, 2.8979, 0.0000, 0.0000, 140.9998); //veg_procgrasspatch
    g_Object[185] = //CreateDynamicObject(874, -74.0613, -1203.9643, 2.8979, 0.0000, 0.0000, 140.9998); //veg_procgrasspatch
    g_Object[186] = //CreateDynamicObject(874, -68.3671, -1192.3867, 2.8979, 0.0000, 0.0000, 140.9998); //veg_procgrasspatch
    g_Object[187] = //CreateDynamicObject(874, -61.8395, -1180.6861, 2.8979, 0.0000, 0.0000, 134.7998); //veg_procgrasspatch
    g_Object[188] = //CreateDynamicObject(874, -55.0009, -1169.8210, 2.8979, 0.0000, 0.0000, -30.2999); //veg_procgrasspatch
    g_Object[189] = CreateDynamicObject(14553, -183.0240, -1181.3470, 1.3341, 4.2999, 2.6998, 31.6000); //androm_des_obj
    g_Object[190] = CreateDynamicObject(10984, -152.0926, -1140.6722, 2.3984, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[190], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[191] = CreateDynamicObject(10984, -163.4226, -1146.8828, 3.3684, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[191], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[192] = CreateDynamicObject(10984, -158.9026, -1177.4123, 3.8083, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[192], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[193] = CreateDynamicObject(10984, -154.8851, -1164.1921, 2.7483, 0.0000, 1.2999, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[193], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[194] = CreateDynamicObject(10984, -156.7926, -1151.9621, 2.3984, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[194], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[195] = CreateDynamicObject(10984, -165.8226, -1200.2628, 5.0482, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[195], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[196] = CreateDynamicObject(10984, -162.8726, -1208.4018, 5.1984, -0.5000, 0.0000, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[196], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[197] = CreateDynamicObject(10984, -167.6515, -1212.8530, 6.2486, -0.5000, 5.4998, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[197], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[198] = CreateDynamicObject(10984, -175.8441, -1202.5096, 6.5253, -2.2999, 5.4998, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[198], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[199] = CreateDynamicObject(10984, -180.6618, -1191.5594, 6.5496, -2.2999, 5.4998, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[199], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[200] = CreateDynamicObject(10984, -197.1286, -1197.6673, 7.2280, -2.2999, -3.0999, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[200], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[201] = CreateDynamicObject(10984, -213.1405, -1197.6909, 6.6416, -2.2999, -3.0999, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[201], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[202] = CreateDynamicObject(10984, -206.8175, -1195.7856, 6.4969, -2.2999, -3.0999, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[202], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[203] = CreateDynamicObject(10984, -219.3094, -1195.7679, 6.9317, -2.2999, -3.0999, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[203], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[204] = CreateDynamicObject(10984, -227.8829, -1195.7519, 7.3182, -2.2999, -3.0999, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[204], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[205] = CreateDynamicObject(10984, -234.0713, -1197.5666, 7.1545, -2.2999, -3.0999, -139.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[205], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[206] = CreateDynamicObject(10984, -203.7485, -1147.9560, 4.4635, 1.2000, -3.0999, -139.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[206], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[207] = CreateDynamicObject(10984, -211.3587, -1139.2662, 3.4425, 1.2000, -3.0999, -139.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[207], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[208] = CreateDynamicObject(670, -193.3889, -1216.4073, 11.4027, 0.0000, -0.8999, 0.0000); //sm_firtallded
    g_Object[209] = CreateDynamicObject(670, -182.5876, -1230.8172, 11.4026, 0.0000, -0.8999, 0.0000); //sm_firtallded
    g_Object[210] = CreateDynamicObject(722, -149.8842, -1221.7468, -4.0590, 0.0000, 31.6998, 0.0000); //veg_largefurs03
    g_Object[211] = CreateDynamicObject(10984, -154.9205, -1217.6705, 4.3312, -0.5000, 5.4998, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[211], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[212] = CreateDynamicObject(10984, -163.2619, -1217.6634, 5.1345, -0.5000, 5.4998, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[212], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[213] = CreateDynamicObject(723, -172.9084, -1232.5246, -4.2975, 0.0000, 0.0000, 0.0000); //veg_largefurs04
    g_Object[214] = CreateDynamicObject(723, -194.9485, -1232.5246, -4.2975, 0.0000, 0.0000, -78.6996); //veg_largefurs04
    g_Object[215] = //CreateDynamicObject(874, -155.9100, -1176.7882, 4.3892, 0.0000, 0.0000, -33.5998); //veg_procgrasspatch
    g_Object[216] = //CreateDynamicObject(874, -154.8831, -1203.2357, 4.9896, 2.5000, 2.1998, 13.8000); //veg_procgrasspatch
    g_Object[217] = //CreateDynamicObject(874, -165.6224, -1222.0699, 5.7119, 3.1998, 4.4000, 42.6999); //veg_procgrasspatch
    g_Object[218] = //CreateDynamicObject(874, -172.4532, -1214.5434, 7.3685, 3.1998, 4.4000, 42.6999); //veg_procgrasspatch
    g_Object[219] = //CreateDynamicObject(874, -222.6145, -1202.9215, 7.3582, 0.0000, 0.0000, 90.5998); //veg_procgrasspatch
    g_Object[220] = //CreateDynamicObject(874, -211.0552, -1202.8005, 7.3582, 0.0000, 0.0000, 58.5000); //veg_procgrasspatch
    g_Object[221] = //CreateDynamicObject(874, -208.8426, -1147.2624, 4.8853, -9.6997, 0.0000, 0.0000); //veg_procgrasspatch
    g_Object[222] = //CreateDynamicObject(874, -196.6291, -1144.8292, 4.2684, -1.3997, 0.0000, 0.0000); //veg_procgrasspatch
    g_Object[223] = //CreateDynamicObject(874, -154.9196, -1135.0227, 3.6057, 0.0000, 0.0000, 88.9999); //veg_procgrasspatch
    g_Object[224] = CreateDynamicObject(825, -148.3719, -1151.0589, 2.9279, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[225] = CreateDynamicObject(825, -155.3437, -1209.4443, 4.9590, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[226] = //CreateDynamicObject(874, -181.0247, -1106.8824, 3.7667, 0.0000, 0.0000, 61.2000); //veg_procgrasspatch
    g_Object[227] = CreateDynamicObject(690, -137.7539, -1085.8479, 3.3656, 0.0000, 0.0000, 0.0000); //sm_fir_copse2
    g_Object[228] = CreateDynamicObject(723, -180.6031, -1123.6125, 9.4687, -39.4000, -3.5000, -78.6996); //veg_largefurs04
    g_Object[229] = CreateDynamicObject(10984, -188.8327, -1127.1739, 3.3684, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    SetDynamicObjectMaterial(g_Object[229], 0, 13624, "innertrak", "AH_dirt64b2", 0x00000000);
    g_Object[230] = //CreateDynamicObject(874, -143.0702, -1107.4698, 4.9190, 0.0000, 0.0000, -108.4999); //veg_procgrasspatch
    g_Object[231] = CreateDynamicObject(10984, -66.3206, -1167.8702, 1.4967, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[232] = CreateDynamicObject(639, -59.0055, -1167.0273, 35.3236, 11.7995, 0.0000, -41.0998); //veg_ivy_balcny_kb3
    g_Object[233] = CreateDynamicObject(639, -67.0177, -1176.3789, 32.8838, 8.7995, 0.0000, -41.0998); //veg_ivy_balcny_kb3
    g_Object[234] = CreateDynamicObject(639, -70.6958, -1180.7635, 32.0461, 5.1996, 0.0000, -41.0998); //veg_ivy_balcny_kb3
    g_Object[235] = CreateDynamicObject(639, -79.2675, -1190.6650, 30.8544, 5.1996, 0.0000, -41.0998); //veg_ivy_balcny_kb3
    g_Object[236] = CreateDynamicObject(639, -92.8638, -1206.7395, 30.1835, -1.9002, 0.0000, -40.0998); //veg_ivy_balcny_kb3
    g_Object[237] = CreateDynamicObject(639, -101.0242, -1216.4305, 30.8738, -5.0001, 0.0000, -40.0998); //veg_ivy_balcny_kb3
    g_Object[238] = CreateDynamicObject(639, -108.7555, -1225.3790, 32.3600, -9.0002, 0.0000, -40.1996); //veg_ivy_balcny_kb3
    g_Object[239] = CreateDynamicObject(639, -97.6789, -1224.4908, 32.0768, 6.0995, 0.0000, 139.2001); //veg_ivy_balcny_kb3
    g_Object[240] = CreateDynamicObject(639, -90.1705, -1215.7926, 30.6275, 6.0995, 0.0000, 139.2001); //veg_ivy_balcny_kb3
    g_Object[241] = CreateDynamicObject(639, -83.5233, -1208.0909, 30.1137, 2.4997, 0.0000, 139.2001); //veg_ivy_balcny_kb3
    g_Object[242] = CreateDynamicObject(19876, -71.6063, -1178.7297, 2.7906, 0.0000, 0.0000, -25.7999); //DillimoreGasExt1
    SetDynamicObjectMaterial(g_Object[242], 1, 2905, "dead_mantxd", "billyblood", 0x00000000);
    g_Object[243] = CreateDynamicObject(10984, -83.0800, -1176.0399, 0.5048, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[244] = CreateDynamicObject(10984, -80.2798, -1170.6590, 0.9146, 0.0000, 0.0000, -23.0998); //rubbled01_SFS
    g_Object[245] = CreateDynamicObject(10984, -70.2500, -1173.2607, 1.4967, 0.0000, 0.0000, 26.8999); //rubbled01_SFS
    g_Object[246] = CreateDynamicObject(3593, -80.8030, -1198.6832, 1.7876, -5.5998, 0.0000, -13.8999); //la_fuckcar2
    g_Object[247] = CreateDynamicObject(639, -82.3264, -1164.1556, 4.7114, 0.0000, 0.0000, -25.8999); //veg_ivy_balcny_kb3
    g_Object[248] = CreateDynamicObject(639, -84.6025, -1168.8425, 4.6514, 0.0000, 0.0000, -25.8999); //veg_ivy_balcny_kb3
    g_Object[249] = CreateDynamicObject(639, -88.3320, -1183.0544, 4.6514, 0.0000, 0.0000, 63.4000); //veg_ivy_balcny_kb3
    g_Object[250] = //CreateDynamicObject(874, -78.9729, -1168.0589, 1.8753, 0.0000, 0.0000, -51.3997); //veg_procgrasspatch
    g_Object[251] = CreateDynamicObject(639, -79.3513, -1189.3529, 3.3914, 0.0000, 0.0000, 63.4000); //veg_ivy_balcny_kb3
    g_Object[252] = CreateDynamicObject(636, -84.7005, -1185.0395, 5.0932, -1.1000, -86.2994, 66.1996); //veg_fern_balcny_kb2
    g_Object[253] = CreateDynamicObject(635, -78.3292, -1188.3955, 7.4720, 0.0000, -90.8000, 64.5000); //veg_fern_balcny_kb1
    g_Object[254] = CreateDynamicObject(10984, -85.9197, -1179.8492, 0.5048, 0.0000, 0.0000, -80.8999); //rubbled01_SFS
    g_Object[255] = CreateDynamicObject(3594, -99.9486, -1188.0959, 1.6287, 0.0000, 2.0999, 0.0000); //la_fuckcar1
    g_Object[256] = CreateDynamicObject(3593, -90.3516, -1167.1927, 1.8451, -1.9996, 0.0000, -43.7000); //la_fuckcar2
    g_Object[257] = CreateDynamicObject(3594, -87.5091, -1159.3060, 1.5686, -3.1998, 1.0000, -1.8997); //la_fuckcar1
    g_Object[258] = CreateDynamicObject(3761, -73.9645, -1184.8425, 1.5000, 0.0000, 89.6996, 0.0000); //industshelves
    g_Object[259] = CreateDynamicObject(17066, -91.2207, -1210.1334, -0.3359, -8.6000, 0.0000, 0.0000); //cw2_genstore
    g_Object[260] = CreateDynamicObject(10984, -83.7117, -1210.2535, 2.2967, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[261] = CreateDynamicObject(10984, -93.4418, -1210.2535, 2.2967, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[262] = //CreateDynamicObject(874, -121.8815, -1220.8780, 2.8979, 0.0000, 0.0000, 154.4998); //veg_procgrasspatch
    g_Object[263] = //CreateDynamicObject(874, -126.4505, -1232.0832, 3.1977, 0.0000, 0.0000, 154.4998); //veg_procgrasspatch
    g_Object[264] = CreateDynamicObject(19358, -76.3447, -1185.3840, 0.7110, 0.0000, 90.0000, 0.0000); //wall006
    SetDynamicObjectMaterial(g_Object[264], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[265] = CreateDynamicObject(19358, -75.8748, -1185.3840, 0.4510, 0.0000, 0.0000, 0.0000); //wall006
    SetDynamicObjectMaterial(g_Object[265], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[266] = CreateDynamicObject(2907, -75.9608, -1185.1512, 0.7458, -176.4998, 0.0000, 97.0000); //kmb_deadtorso
    g_Object[267] = CreateDynamicObject(2906, -76.4095, -1184.9930, 0.7910, 0.0000, 0.0000, 83.0000); //kmb_deadarm
    g_Object[268] = CreateDynamicObject(2908, -76.8346, -1185.3562, 0.8227, 0.0000, 0.0000, -56.2999); //kmb_deadhead
    g_Object[269] = CreateDynamicObject(3594, -87.8526, -1188.7856, 1.2178, 0.0000, 2.4999, 128.8000); //la_fuckcar1
    g_Object[270] = CreateDynamicObject(19420, -87.9934, -1188.9305, 1.8157, 0.0000, 0.0000, -49.4999); //police_lights02
    g_Object[271] = CreateDynamicObject(19834, -79.5662, -1183.4692, 1.0592, 0.0000, -51.2000, 56.5998); //PoliceLineTape1
    g_Object[272] = //CreateDynamicObject(874, -182.6340, -1028.9831, 12.2910, 0.0000, -4.5000, 105.5998); //veg_procgrasspatch
    g_Object[273] = CreateDynamicObject(639, -157.5811, -1036.6013, 15.1041, 0.0000, 0.0000, 105.2994); //veg_ivy_balcny_kb3
    g_Object[274] = //CreateDynamicObject(874, -193.6273, -1032.1141, 13.0389, 2.5000, -6.5998, 105.5998); //veg_procgrasspatch
    g_Object[275] = //CreateDynamicObject(874, -174.8818, -1048.5251, 10.3007, -1.0999, 16.8999, -72.0000); //veg_procgrasspatch
    g_Object[276] = CreateDynamicObject(825, -135.9745, -1300.5880, 3.0471, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[277] = CreateDynamicObject(639, -149.1701, -1034.2989, 15.1041, 0.0000, 0.0000, 105.2994); //veg_ivy_balcny_kb3
    g_Object[278] = CreateDynamicObject(639, -149.9971, -1022.6859, 15.1041, 0.0000, 0.0000, -74.9000); //veg_ivy_balcny_kb3
    g_Object[279] = CreateDynamicObject(639, -160.8105, -1025.6031, 15.1639, 0.0000, 0.0000, -74.9000); //veg_ivy_balcny_kb3
    g_Object[280] = CreateDynamicObject(9812, -147.8618, -1032.5683, 3.5834, 0.1000, 0.0000, 15.6997); //veg_ivy_balcny_kb08
    g_Object[281] = CreateDynamicObject(9812, -150.2734, -1024.0427, 3.6038, 0.1000, 0.0000, -164.8997); //veg_ivy_balcny_kb08
    g_Object[282] = //CreateDynamicObject(874, -119.7024, -1034.0343, 10.4791, 5.5998, 17.7999, -86.3999); //veg_procgrasspatch
    g_Object[283] = //CreateDynamicObject(874, -101.6781, -1029.3592, 12.7201, 5.2999, 9.1997, -76.5000); //veg_procgrasspatch
    g_Object[284] = //CreateDynamicObject(874, -138.4384, -1059.2956, 2.9893, 0.0000, -9.0000, -26.8999); //veg_procgrasspatch
    g_Object[285] = //CreateDynamicObject(874, -131.1799, -1275.3874, 3.1187, 0.0000, 0.0000, -9.6997); //veg_procgrasspatch
    g_Object[286] = //CreateDynamicObject(874, -156.4290, -1271.0460, 3.1187, 0.0000, 0.0000, 168.5997); //veg_procgrasspatch
    g_Object[287] = CreateDynamicObject(690, -44.8596, -1458.2049, 4.5092, 0.0000, 0.0000, -172.9998); //sm_fir_copse2
    g_Object[288] = CreateDynamicObject(639, -114.4914, -1249.8564, 33.7900, -8.3999, 0.0000, 155.1000); //veg_ivy_balcny_kb3
    g_Object[289] = CreateDynamicObject(639, -118.3451, -1258.2534, 32.5569, -6.4998, 0.0000, 155.1000); //veg_ivy_balcny_kb3
    g_Object[290] = CreateDynamicObject(639, -122.4189, -1267.1717, 31.6109, -5.8997, 0.0000, 155.1000); //veg_ivy_balcny_kb3
    g_Object[291] = CreateDynamicObject(639, -126.0448, -1275.2685, 30.8651, -4.6999, 0.0000, 155.1000); //veg_ivy_balcny_kb3
    g_Object[292] = CreateDynamicObject(639, -131.3634, -1286.7248, 30.2381, -2.7999, 0.0000, 155.1000); //veg_ivy_balcny_kb3
    g_Object[293] = CreateDynamicObject(639, -136.1782, -1297.2397, 29.8826, -0.7997, 0.0000, 155.1000); //veg_ivy_balcny_kb3
    g_Object[294] = CreateDynamicObject(639, -146.3654, -1319.3988, 30.1618, 2.9000, 0.0000, 155.1000); //veg_ivy_balcny_kb3
    g_Object[295] = CreateDynamicObject(639, -153.1385, -1334.1789, 31.3460, 4.5998, 0.0000, 154.9001); //veg_ivy_balcny_kb3
    g_Object[296] = CreateDynamicObject(639, -156.9523, -1342.3911, 32.4056, 5.8997, 0.0000, 155.8000); //veg_ivy_balcny_kb3
    g_Object[297] = CreateDynamicObject(639, -162.0258, -1353.6800, 34.3381, 8.3999, 0.0000, 155.8000); //veg_ivy_balcny_kb3
    g_Object[298] = CreateDynamicObject(639, -157.3251, -1321.1988, 30.4491, -4.6999, 0.0000, -23.8997); //veg_ivy_balcny_kb3
    g_Object[299] = CreateDynamicObject(639, -163.4824, -1334.7241, 31.6707, -6.0998, 0.0000, -24.3997); //veg_ivy_balcny_kb3
    g_Object[300] = CreateDynamicObject(639, -169.1837, -1347.0738, 33.2853, -10.1997, 0.0000, -24.3997); //veg_ivy_balcny_kb3
    g_Object[301] = CreateDynamicObject(639, -149.0926, -1303.2640, 29.9304, -0.5999, 0.0000, -24.6998); //veg_ivy_balcny_kb3
    g_Object[302] = CreateDynamicObject(639, -143.0738, -1290.1771, 30.2296, 1.5000, 0.0000, -25.1998); //veg_ivy_balcny_kb3
    g_Object[303] = CreateDynamicObject(639, -140.8475, -1285.3292, 30.4293, 3.2999, 0.0000, -24.7998); //veg_ivy_balcny_kb3
    g_Object[304] = CreateDynamicObject(639, -135.2754, -1273.2220, 31.1977, 3.2999, 0.0000, -24.7998); //veg_ivy_balcny_kb3
    g_Object[305] = CreateDynamicObject(639, -129.4812, -1260.6107, 32.4584, 5.5000, 0.0000, -24.7998); //veg_ivy_balcny_kb3
    g_Object[306] = CreateDynamicObject(639, -122.6024, -1245.6037, 34.6208, 7.6999, 0.0000, -24.7998); //veg_ivy_balcny_kb3
    g_Object[307] = CreateDynamicObject(639, -175.7230, -1363.1461, 35.4048, 5.8997, 0.0000, -13.1997); //veg_ivy_balcny_kb3
    g_Object[308] = CreateDynamicObject(639, -179.7816, -1380.4488, 33.2667, 4.1999, 0.0000, -13.1997); //veg_ivy_balcny_kb3
    g_Object[309] = CreateDynamicObject(639, -180.9891, -1385.5975, 32.9183, 3.0999, 0.0000, -13.1997); //veg_ivy_balcny_kb3
    g_Object[310] = CreateDynamicObject(639, -183.6376, -1396.9770, 32.6762, 0.6998, 0.0000, -11.3999); //veg_ivy_balcny_kb3
    g_Object[311] = CreateDynamicObject(639, -186.1540, -1408.0996, 33.0158, -2.9999, 0.0000, -13.6000); //veg_ivy_balcny_kb3
    g_Object[312] = CreateDynamicObject(639, -189.9712, -1424.5167, 34.3097, -5.8997, 0.0000, -13.6000); //veg_ivy_balcny_kb3
    g_Object[313] = CreateDynamicObject(639, -194.3560, -1443.3221, 36.8680, -10.0000, 0.0000, -13.6000); //veg_ivy_balcny_kb3
    g_Object[314] = CreateDynamicObject(639, -197.0386, -1454.6660, 39.3092, -13.3000, 0.0000, -13.6000); //veg_ivy_balcny_kb3
    g_Object[315] = CreateDynamicObject(639, -182.4082, -1433.3608, 34.7192, 4.6999, 0.0000, 166.3999); //veg_ivy_balcny_kb3
    g_Object[316] = CreateDynamicObject(639, -178.3937, -1416.4698, 33.2919, 2.7000, 0.0000, 166.3999); //veg_ivy_balcny_kb3
    g_Object[317] = CreateDynamicObject(639, -174.5693, -1400.4068, 32.6231, 1.2000, 0.0000, 167.8000); //veg_ivy_balcny_kb3
    g_Object[318] = CreateDynamicObject(639, -173.3188, -1395.0008, 32.5470, -0.0996, 0.0000, 165.8000); //veg_ivy_balcny_kb3
    g_Object[319] = CreateDynamicObject(639, -169.2057, -1377.8481, 33.3666, -5.5998, 0.0000, 165.8000); //veg_ivy_balcny_kb3
    g_Object[320] = CreateDynamicObject(639, -166.3990, -1366.1877, 34.8041, -6.0998, 0.0000, 166.3000); //veg_ivy_balcny_kb3
    g_Object[321] = CreateDynamicObject(639, -187.3444, -1453.7641, 37.8600, 10.2999, 0.0000, 166.3999); //veg_ivy_balcny_kb3
    g_Object[322] = CreateDynamicObject(639, -201.2256, -1464.8121, 40.8465, 5.0998, 0.0000, -40.4000); //veg_ivy_balcny_kb3
    g_Object[323] = CreateDynamicObject(639, -209.0171, -1473.7065, 39.5707, 5.9000, 0.0000, -42.0000); //veg_ivy_balcny_kb3
    g_Object[324] = CreateDynamicObject(639, -212.5446, -1477.6246, 39.0259, 4.9000, 0.0000, -42.0000); //veg_ivy_balcny_kb3
    g_Object[325] = CreateDynamicObject(639, -224.4333, -1490.9930, 37.8837, 2.0999, 0.0000, -40.7999); //veg_ivy_balcny_kb3
    g_Object[326] = CreateDynamicObject(639, -234.6983, -1502.7954, 37.0699, 2.0999, 0.0000, -41.5998); //veg_ivy_balcny_kb3
    g_Object[327] = CreateDynamicObject(639, -246.2265, -1515.7795, 36.5834, 1.6000, 0.0000, -41.2000); //veg_ivy_balcny_kb3
    g_Object[328] = CreateDynamicObject(639, -249.5576, -1519.5847, 36.5219, -0.5999, 0.0000, -41.2000); //veg_ivy_balcny_kb3
    g_Object[329] = CreateDynamicObject(639, -258.6893, -1529.9549, 36.7568, -1.7999, 0.0000, -41.2000); //veg_ivy_balcny_kb3
    g_Object[330] = CreateDynamicObject(639, -268.4692, -1541.0809, 37.5125, -4.8997, 0.0000, -41.2000); //veg_ivy_balcny_kb3
    g_Object[331] = CreateDynamicObject(639, -277.8676, -1551.7099, 38.7288, -5.4998, 0.0000, -40.2999); //veg_ivy_balcny_kb3
    g_Object[332] = CreateDynamicObject(639, -281.3930, -1555.7270, 39.3338, -6.8997, 0.0000, -40.2999); //veg_ivy_balcny_kb3
    g_Object[333] = CreateDynamicObject(639, -284.8453, -1559.6579, 40.0474, -8.7999, 0.0000, -41.2999); //veg_ivy_balcny_kb3
    g_Object[334] = CreateDynamicObject(639, -280.9572, -1570.0096, 41.4093, 8.8000, 0.0000, 138.3997); //veg_ivy_balcny_kb3
    g_Object[335] = CreateDynamicObject(639, -277.1495, -1565.6473, 40.5125, 8.8000, 0.0000, 138.3997); //veg_ivy_balcny_kb3
    g_Object[336] = CreateDynamicObject(639, -268.6275, -1556.0489, 38.7787, 5.9000, 0.0000, 138.3997); //veg_ivy_balcny_kb3
    g_Object[337] = CreateDynamicObject(639, -259.0447, -1545.2237, 37.6166, 4.0000, 0.0000, 139.0997); //veg_ivy_balcny_kb3
    g_Object[338] = CreateDynamicObject(639, -246.9163, -1531.4687, 36.9654, 0.8999, 0.0000, 138.3999); //veg_ivy_balcny_kb3
    g_Object[339] = CreateDynamicObject(639, -243.1257, -1527.1988, 36.8759, 0.8999, 0.0000, 138.3999); //veg_ivy_balcny_kb3
    g_Object[340] = CreateDynamicObject(639, -234.1020, -1517.0349, 36.9123, -1.9996, 0.0000, 138.3999); //veg_ivy_balcny_kb3
    g_Object[341] = CreateDynamicObject(639, -223.0464, -1504.5826, 37.4337, -1.9996, 0.0000, 138.3999); //veg_ivy_balcny_kb3
    g_Object[342] = CreateDynamicObject(639, -211.4093, -1491.4753, 38.3861, -2.9999, 0.0000, 138.3999); //veg_ivy_balcny_kb3
    g_Object[343] = CreateDynamicObject(639, -198.2368, -1476.6357, 40.0595, -5.5998, 0.0000, 138.3999); //veg_ivy_balcny_kb3
    g_Object[344] = CreateDynamicObject(639, -294.2528, -1571.7197, 41.6565, -0.2998, 0.0000, -31.1000); //veg_ivy_balcny_kb3
    g_Object[345] = CreateDynamicObject(639, -297.2127, -1576.6273, 41.5965, -0.2998, 0.0000, -31.2999); //veg_ivy_balcny_kb3
    g_Object[346] = CreateDynamicObject(639, -304.2579, -1588.0416, 41.7863, -3.8998, 0.0000, -31.6000); //veg_ivy_balcny_kb3
    g_Object[347] = CreateDynamicObject(639, -307.3211, -1593.0206, 42.1851, -3.8998, 0.0000, -31.6000); //veg_ivy_balcny_kb3
    g_Object[348] = CreateDynamicObject(639, -310.1755, -1597.6601, 42.5564, -3.8998, 0.0000, -31.6000); //veg_ivy_balcny_kb3
    g_Object[349] = CreateDynamicObject(639, -316.7080, -1608.2788, 43.8069, -6.8997, 0.0000, -31.7000); //veg_ivy_balcny_kb3
    g_Object[350] = CreateDynamicObject(639, -322.2072, -1617.2397, 45.2405, -9.1997, 0.0000, -31.1000); //veg_ivy_balcny_kb3
    g_Object[351] = CreateDynamicObject(639, -328.5693, -1627.6510, 47.5816, -11.9996, 0.0000, -31.8999); //veg_ivy_balcny_kb3
    g_Object[352] = CreateDynamicObject(639, -334.5187, -1637.2102, 50.4552, -16.2999, 0.0000, -32.2000); //veg_ivy_balcny_kb3
    g_Object[353] = CreateDynamicObject(639, -341.3320, -1648.0295, 54.9953, -21.7000, 0.0000, -32.2000); //veg_ivy_balcny_kb3
    g_Object[354] = CreateDynamicObject(639, -316.4627, -1626.1407, 46.6920, 10.5000, 0.0000, 147.3999); //veg_ivy_balcny_kb3
    g_Object[355] = CreateDynamicObject(639, -323.5479, -1637.6280, 49.6096, 15.3999, 0.0000, 148.3000); //veg_ivy_balcny_kb3
    g_Object[356] = CreateDynamicObject(639, -329.2868, -1646.9759, 52.8596, 18.7999, 0.0000, 148.3000); //veg_ivy_balcny_kb3
    g_Object[357] = CreateDynamicObject(639, -332.1737, -1651.6500, 54.7825, 18.7999, 0.0000, 148.3000); //veg_ivy_balcny_kb3
    g_Object[358] = CreateDynamicObject(639, -309.8781, -1615.4366, 44.5256, 8.3999, 0.0000, 147.6999); //veg_ivy_balcny_kb3
    g_Object[359] = CreateDynamicObject(639, -304.3215, -1606.4394, 43.3786, 6.3000, 0.0000, 149.3000); //veg_ivy_balcny_kb3
    g_Object[360] = CreateDynamicObject(639, -295.6145, -1592.2862, 42.1072, 2.5000, 0.0000, 148.4998); //veg_ivy_balcny_kb3
    g_Object[361] = CreateDynamicObject(639, -289.6484, -1582.5500, 41.8689, -0.9998, 0.0000, 148.2998); //veg_ivy_balcny_kb3
    g_Object[362] = //CreateDynamicObject(874, -136.3905, -1291.6711, 3.1187, 0.0000, 0.0000, 152.8999); //veg_procgrasspatch
    g_Object[363] = //CreateDynamicObject(874, -158.7171, -1287.7353, 3.1187, 0.0000, 0.0000, -6.5998); //veg_procgrasspatch
    g_Object[364] = //CreateDynamicObject(874, -125.4944, -1322.2274, 2.6287, 0.0000, 0.0000, 144.8999); //veg_procgrasspatch
    g_Object[365] = //CreateDynamicObject(874, -127.1677, -1332.9569, 2.4586, 0.0000, 0.0000, -26.0998); //veg_procgrasspatch
    g_Object[366] = //CreateDynamicObject(874, -131.3381, -1347.4370, 1.9486, 0.0000, 0.0000, 163.5000); //veg_procgrasspatch
    g_Object[367] = //CreateDynamicObject(874, -137.2996, -1379.2801, 2.7871, -0.5999, 0.0000, -16.8999); //veg_procgrasspatch
    g_Object[368] = //CreateDynamicObject(874, -136.9425, -1404.4327, 3.2455, -0.5999, -2.7000, 8.6000); //veg_procgrasspatch
    g_Object[369] = //CreateDynamicObject(874, -133.4665, -1416.8623, 3.4539, -0.5999, -2.7000, 14.6000); //veg_procgrasspatch
    g_Object[370] = //CreateDynamicObject(874, -157.9842, -1425.0809, 3.2372, -0.5999, -0.2000, 14.6000); //veg_procgrasspatch
    g_Object[371] = //CreateDynamicObject(874, -151.6204, -1442.3658, 3.3299, -0.5999, -1.7999, -158.2998); //veg_procgrasspatch
    g_Object[372] = CreateDynamicObject(9812, -118.2422, -1419.1839, 6.5050, 0.0000, -0.4999, -135.3999); //veg_ivy_balcny_kb08
    g_Object[373] = CreateDynamicObject(9812, -160.5390, -1463.4353, 6.8101, 0.0000, -0.2998, -132.0997); //veg_ivy_balcny_kb08
    g_Object[374] = CreateDynamicObject(9812, -200.0079, -1509.6604, 8.2580, 0.0000, -2.0000, -128.8997); //veg_ivy_balcny_kb08
    g_Object[375] = CreateDynamicObject(9812, -236.5713, -1557.5334, 9.8302, 0.0000, -0.6000, -126.5998); //veg_ivy_balcny_kb08
    g_Object[376] = CreateDynamicObject(9812, -104.5960, -1459.5432, 6.5574, 0.0000, 0.1000, 45.2999); //veg_ivy_balcny_kb08
    g_Object[377] = CreateDynamicObject(9812, -146.7239, -1503.2955, 7.1233, -4.9000, 1.2999, 46.5998); //veg_ivy_balcny_kb08
    g_Object[378] = CreateDynamicObject(9812, -188.2841, -1551.2075, 8.8751, -4.9000, 1.2999, 51.9000); //veg_ivy_balcny_kb08
    g_Object[379] = CreateDynamicObject(9812, 26.6968, -1347.4438, 3.8073, 0.0000, 0.1999, 37.9000); //veg_ivy_balcny_kb08
    g_Object[380] = CreateDynamicObject(9812, 73.4896, -1311.0166, 5.0503, 0.0000, -2.0000, 37.9000); //veg_ivy_balcny_kb08
    g_Object[381] = CreateDynamicObject(9812, 63.2770, -1297.8653, 5.3797, 0.0000, 2.6998, -139.8999); //veg_ivy_balcny_kb08
    g_Object[382] = CreateDynamicObject(9812, 17.3626, -1335.9520, 3.8275, 0.0000, 0.4999, -141.5997); //veg_ivy_balcny_kb08
    g_Object[383] = CreateDynamicObject(9812, 8.2405, -1324.7248, 5.1170, 0.0000, -1.7000, 39.2000); //veg_ivy_balcny_kb08
    g_Object[384] = CreateDynamicObject(9812, 58.4425, -1286.4858, 7.2905, 0.0000, -1.7000, 35.2999); //veg_ivy_balcny_kb08
    g_Object[385] = CreateDynamicObject(9812, -1.2179, -1313.1230, 5.1170, 0.0000, 2.1998, -141.8999); //veg_ivy_balcny_kb08
    g_Object[386] = CreateDynamicObject(9812, 43.8474, -1277.8503, 7.3154, 0.0000, 2.1998, -141.8999); //veg_ivy_balcny_kb08
    g_Object[387] = CreateDynamicObject(9812, 92.5774, -1277.5654, 21.6805, 0.0000, 0.0000, -55.0000); //veg_ivy_balcny_kb08
    g_Object[388] = //CreateDynamicObject(874, -186.3388, -1458.5041, 7.4559, -5.0998, -0.2000, 35.2999); //veg_procgrasspatch
    g_Object[389] = //CreateDynamicObject(874, -195.4743, -1467.3824, 8.8246, 6.3000, -6.5998, -131.0997); //veg_procgrasspatch
    g_Object[390] = //CreateDynamicObject(874, -286.7590, -1569.0600, 7.7891, -0.6998, 11.6997, 0.0000); //veg_procgrasspatch
    g_Object[391] = //CreateDynamicObject(874, -280.3746, -1569.0760, 6.4670, -2.0999, -12.3999, -167.5000); //veg_procgrasspatch
    g_Object[392] = //CreateDynamicObject(874, -296.2532, -1572.7264, 9.9441, -2.0999, -12.3999, -167.5000); //veg_procgrasspatch
    g_Object[393] = //CreateDynamicObject(874, -131.1206, -1477.1291, 3.2144, 0.0000, 0.0000, 36.0998); //veg_procgrasspatch
    g_Object[394] = //CreateDynamicObject(874, -110.3503, -1462.9614, 3.2144, 0.0000, 0.0000, 36.0998); //veg_procgrasspatch
    g_Object[395] = //CreateDynamicObject(874, -100.4039, -1476.7684, 3.1045, 0.0000, 0.0000, -147.8999); //veg_procgrasspatch
    g_Object[396] = //CreateDynamicObject(874, -113.4346, -1499.5224, 3.2044, 0.8999, -0.5999, -134.1999); //veg_procgrasspatch
    g_Object[397] = //CreateDynamicObject(874, -87.6638, -1514.3059, 3.1891, -0.9998, -2.0999, -118.0000); //veg_procgrasspatch
    g_Object[398] = //CreateDynamicObject(874, -72.0382, -1520.2154, 2.8097, 2.2999, 3.0000, 61.5998); //veg_procgrasspatch
    g_Object[399] = //CreateDynamicObject(874, -36.9934, -1538.5482, 2.5831, 2.2999, -1.7999, -25.2999); //veg_procgrasspatch
    g_Object[400] = //CreateDynamicObject(874, -15.0347, -1548.9399, 2.8561, 1.5000, -1.7999, -18.5000); //veg_procgrasspatch
    g_Object[401] = //CreateDynamicObject(874, -10.7103, -1536.0683, 2.6819, 1.5000, -1.7999, -6.1999); //veg_procgrasspatch
    g_Object[402] = //CreateDynamicObject(874, -77.8050, -1482.8879, 2.7153, -2.9000, 10.9996, -99.0000); //veg_procgrasspatch
    g_Object[403] = //CreateDynamicObject(874, -62.1846, -1482.1920, 2.8375, 2.3998, -13.3999, 73.6996); //veg_procgrasspatch
    g_Object[404] = //CreateDynamicObject(874, -6.8161, -1506.9742, 2.7783, 5.9000, -1.7999, -111.0000); //veg_procgrasspatch
    g_Object[405] = //CreateDynamicObject(874, 8.5458, -1507.8365, 3.6312, -1.0999, 0.2000, -111.0000); //veg_procgrasspatch
    g_Object[406] = //CreateDynamicObject(874, 22.9743, -1543.8138, 3.4962, 6.0000, 10.6000, -111.0000); //veg_procgrasspatch
    g_Object[407] = //CreateDynamicObject(874, -99.9095, -1549.7237, 2.9776, 0.0996, -2.0999, -57.0998); //veg_procgrasspatch
    g_Object[408] = //CreateDynamicObject(874, -108.8507, -1557.3874, 3.0151, 0.0996, -2.0999, -57.0998); //veg_procgrasspatch
    g_Object[409] = //CreateDynamicObject(874, -99.1203, -1607.7060, 2.8375, -1.3997, 0.0000, 15.5999); //veg_procgrasspatch
    g_Object[410] = //CreateDynamicObject(874, 26.3598, -1479.4510, 7.6901, 3.5000, -15.5999, 0.0000); //veg_procgrasspatch
    g_Object[411] = //CreateDynamicObject(874, 22.1602, -1464.9737, 6.6936, 3.5000, -15.5999, 0.0000); //veg_procgrasspatch
    g_Object[412] = //CreateDynamicObject(874, -27.2525, -1398.5250, 2.5243, -2.2999, 1.6999, -88.7995); //veg_procgrasspatch
    g_Object[413] = //CreateDynamicObject(874, -21.4783, -1398.4040, 2.2922, 3.3998, -2.0000, 102.4000); //veg_procgrasspatch
    g_Object[414] = //CreateDynamicObject(874, -41.5942, -1372.2624, 4.3962, -3.9999, -2.1998, 0.0000); //veg_procgrasspatch
    g_Object[415] = //CreateDynamicObject(874, -35.7975, -1367.3061, 4.1069, 5.3000, -0.7997, -160.8000); //veg_procgrasspatch
    g_Object[416] = //CreateDynamicObject(874, -104.2527, -1279.3446, 3.4644, 4.0998, -12.8999, -89.9000); //veg_procgrasspatch
    g_Object[417] = //CreateDynamicObject(874, -9.7199, -1291.2226, 3.0285, -0.1000, 0.6998, 0.0000); //veg_procgrasspatch
    g_Object[418] = //CreateDynamicObject(874, -12.9026, -1279.0858, 3.6881, 4.1999, 0.6998, 9.5999); //veg_procgrasspatch
    g_Object[419] = CreateDynamicObject(9812, -228.8988, -1608.2799, 9.5916, -4.9000, 0.1000, 56.2000); //veg_ivy_balcny_kb08
    g_Object[420] = //CreateDynamicObject(874, -76.6548, -1629.8664, 3.8429, 0.0000, 0.0000, -78.5998); //veg_procgrasspatch
    g_Object[421] = //CreateDynamicObject(874, -67.1349, -1625.4012, 3.8429, 0.0000, 0.0000, -73.4000); //veg_procgrasspatch
    g_Object[422] = CreateDynamicObject(723, -137.5811, -1507.2307, 9.2777, 35.7999, -37.3997, -78.6996); //veg_largefurs04
    g_Object[423] = //CreateDynamicObject(874, -231.6183, -1686.5112, 3.6435, 1.4996, -9.8000, -28.1998); //veg_procgrasspatch
    g_Object[424] = //CreateDynamicObject(874, -223.5278, -1686.7165, 4.2972, 0.8999, 11.8000, 167.6000); //veg_procgrasspatch
    g_Object[425] = //CreateDynamicObject(874, -128.9304, -1642.8885, 3.1814, 1.9996, 1.5999, -98.1996); //veg_procgrasspatch
    g_Object[426] = //CreateDynamicObject(874, -154.6537, -1617.5080, 3.8266, 2.5999, -4.4998, 83.8000); //veg_procgrasspatch
    g_Object[427] = //CreateDynamicObject(874, -211.0570, -1628.3575, 3.3127, 1.7999, -0.2998, -71.3000); //veg_procgrasspatch
    g_Object[428] = //CreateDynamicObject(874, -157.5867, -1642.1273, 2.7648, 0.8999, -7.1999, 75.1996); //veg_procgrasspatch
    g_Object[429] = //CreateDynamicObject(874, -4.0507, -1450.7998, 5.7072, 0.0000, 0.0000, -9.8000); //veg_procgrasspatch
    g_Object[430] = //CreateDynamicObject(874, -4.3126, -1463.9471, 5.3976, 4.7999, 2.9999, -30.4999); //veg_procgrasspatch
    g_Object[431] = CreateDynamicObject(723, -134.4411, -1565.9698, 5.9941, 88.5000, -36.9000, 71.5000); //veg_largefurs04
    g_Object[432] = CreateDynamicObject(16302, -144.7223, -1557.2408, 4.6381, 0.0000, 0.0000, 0.0000); //des_gravelpile04
    SetDynamicObjectMaterial(g_Object[432], 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    g_Object[433] = CreateDynamicObject(16302, -123.8591, -1584.0677, 2.3752, 6.0000, 3.7999, 0.0000); //des_gravelpile04
    SetDynamicObjectMaterial(g_Object[433], 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    g_Object[434] = //CreateDynamicObject(874, -138.8677, -1576.8641, 8.4427, 5.9000, 0.0000, 97.5998); //veg_procgrasspatch
    g_Object[435] = //CreateDynamicObject(874, -130.9147, -1556.1960, 5.2683, -10.9996, 5.8997, 0.0000); //veg_procgrasspatch
    g_Object[436] = CreateDynamicObject(708, -86.2061, -1465.9857, 4.1378, 0.0000, 0.0000, 0.0000); //sm_veg_tree4_vbig
    g_Object[437] = CreateDynamicObject(690, -47.0251, -1440.5675, 4.5092, 0.0000, 0.0000, -151.8999); //sm_fir_copse2
    g_Object[438] = CreateDynamicObject(690, -90.4384, -1359.2623, 0.8791, 0.0000, 0.0000, -176.1999); //sm_fir_copse2
    g_Object[439] = CreateDynamicObject(690, -105.7729, -1333.3020, 0.8791, 0.0000, 0.0000, -126.9999); //sm_fir_copse2
    g_Object[440] = CreateDynamicObject(695, -30.3395, -1302.0034, 4.8551, 0.0000, 0.0000, -125.3999); //sm_fir_scabtg
    g_Object[441] = //CreateDynamicObject(874, -350.9739, -1364.9460, 15.9933, -3.5999, 15.6997, -29.8999); //veg_procgrasspatch
    g_Object[442] = //CreateDynamicObject(874, -357.1913, -1376.3227, 17.8122, -13.5000, 10.3000, -50.3997); //veg_procgrasspatch
    g_Object[443] = //CreateDynamicObject(874, -367.0006, -1386.0312, 21.1744, -11.8000, 4.0000, -58.2000); //veg_procgrasspatch
    g_Object[444] = //CreateDynamicObject(874, -340.2503, -1382.3540, 14.7179, 12.0999, -8.4996, 140.1999); //veg_procgrasspatch
    g_Object[445] = //CreateDynamicObject(874, -354.9971, -1426.5848, 23.4204, -2.0000, 15.0999, -14.6000); //veg_procgrasspatch
    g_Object[446] = //CreateDynamicObject(874, -357.5852, -1447.7856, 24.3871, -6.2999, 14.1997, -14.6000); //veg_procgrasspatch
    g_Object[447] = //CreateDynamicObject(874, -364.8785, -1461.9693, 25.7896, 0.0000, 0.0000, -62.7999); //veg_procgrasspatch
    g_Object[448] = //CreateDynamicObject(874, -395.6043, -1460.9134, 25.7089, 0.0000, 0.0000, 24.2999); //veg_procgrasspatch
    g_Object[449] = //CreateDynamicObject(874, -414.8287, -1436.0705, 25.0382, -0.8000, -8.2999, -3.8998); //veg_procgrasspatch
    g_Object[450] = //CreateDynamicObject(874, -412.6950, -1417.2862, 24.3861, -6.0998, 3.6998, 92.2995); //veg_procgrasspatch
    g_Object[451] = CreateDynamicObject(689, -347.8927, -1564.7385, 16.1222, 0.0000, 0.0000, 0.0000); //sm_fir_copse1
    g_Object[452] = CreateDynamicObject(791, -333.6816, -1447.0958, 2.8050, 0.0000, 0.0000, -24.8999); //vbg_fir_copse
    g_Object[453] = CreateDynamicObject(791, -288.9161, -1279.5318, 1.8193, 0.0000, 0.0000, 0.0000); //vbg_fir_copse
    g_Object[454] = CreateDynamicObject(825, -157.4405, -1295.8038, 2.9653, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[455] = CreateDynamicObject(825, -127.3805, -1318.0980, 2.7019, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[456] = CreateDynamicObject(825, -139.7525, -1396.2683, 2.8101, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[457] = CreateDynamicObject(825, -164.9754, -1420.9012, 3.1507, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[458] = CreateDynamicObject(825, -106.5465, -1502.2674, 2.9992, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[459] = CreateDynamicObject(825, -91.5149, -1479.3016, 3.7938, 7.0998, 0.0000, 0.0000); //genVEG_bushy
    g_Object[460] = CreateDynamicObject(825, -63.5116, -1524.2967, 2.1328, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[461] = CreateDynamicObject(825, -48.0018, -1506.2573, 1.9529, 1.6999, 0.0000, 27.4999); //genVEG_bushy
    g_Object[462] = CreateDynamicObject(825, -97.3105, -1427.5229, 12.5242, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[463] = CreateDynamicObject(825, -165.4868, -1363.0207, 3.2797, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[464] = CreateDynamicObject(825, -176.1670, -1356.0610, 3.2797, 0.0000, 0.0000, -141.0000); //genVEG_bushy
    g_Object[465] = CreateDynamicObject(691, -129.5652, -1363.6424, 0.5623, 0.0000, 0.0000, 0.0000); //sm_veg_tree4_big
    g_Object[466] = CreateDynamicObject(703, -173.5576, -1431.2513, 1.5123, 0.0000, 0.0000, 0.0000); //sm_veg_tree7_big
    g_Object[467] = CreateDynamicObject(703, -163.9288, -1589.7949, 6.0644, 0.0000, 0.0000, 0.0000); //sm_veg_tree7_big
    g_Object[468] = CreateDynamicObject(672, -39.5531, -1597.2341, 2.7613, 0.0000, 0.0000, 0.0000); //sm_veg_tree5
    g_Object[469] = CreateDynamicObject(705, -47.3208, -1488.8625, 0.7145, 0.0000, 0.0000, -92.5000); //sm_veg_tree7vbig
    g_Object[470] = CreateDynamicObject(790, 10.1905, -1207.7556, 12.5493, 0.0000, 0.0000, 127.7995); //sm_fir_tallgroup
    g_Object[471] = CreateDynamicObject(690, -64.1582, -1261.4658, 2.2616, 0.0000, 0.0000, -162.1999); //sm_fir_copse2
    g_Object[472] = //CreateDynamicObject(874, 59.3428, -1182.2091, 7.0240, 6.0998, 0.0000, -43.8997); //veg_procgrasspatch
    g_Object[473] = //CreateDynamicObject(874, 61.5587, -1170.8060, 7.9538, 4.3997, -2.7999, 26.7999); //veg_procgrasspatch
    g_Object[474] = //CreateDynamicObject(874, 22.1487, -1147.6544, 7.7031, 5.3997, -5.5998, -106.6996); //veg_procgrasspatch
    g_Object[475] = //CreateDynamicObject(874, -101.7845, -1431.5106, 12.8148, 0.0000, 0.0000, -54.2000); //veg_procgrasspatch
    g_Object[476] = //CreateDynamicObject(874, -114.5578, -1440.7639, 12.8148, 0.0000, 0.0000, 125.8999); //veg_procgrasspatch
    g_Object[477] = //CreateDynamicObject(874, -124.5130, -1448.7723, 12.8148, 0.0000, 0.0000, 125.8999); //veg_procgrasspatch
    g_Object[478] = //CreateDynamicObject(874, -141.8735, -1468.2424, 12.8148, 0.0000, 0.0000, 14.3999); //veg_procgrasspatch
    g_Object[479] = //CreateDynamicObject(874, -164.6721, -1497.8669, 13.4245, 0.0000, 0.0000, -119.9000); //veg_procgrasspatch
    g_Object[480] = //CreateDynamicObject(874, -176.8130, -1509.3574, 14.0176, -1.8997, 0.0000, -46.2999); //veg_procgrasspatch
    g_Object[481] = //CreateDynamicObject(874, -187.0307, -1521.3492, 14.5375, -1.8997, 0.0000, -42.2000); //veg_procgrasspatch
    g_Object[482] = //CreateDynamicObject(874, -197.0746, -1532.1699, 15.2165, 3.7999, 0.0000, 133.6999); //veg_procgrasspatch
    g_Object[483] = //CreateDynamicObject(874, -218.6761, -1559.2452, 15.8626, 3.7999, 0.0000, 137.3000); //veg_procgrasspatch
    g_Object[484] = //CreateDynamicObject(874, -226.9900, -1573.3271, 16.0783, 0.0000, -2.9000, -50.8997); //veg_procgrasspatch
    g_Object[485] = //CreateDynamicObject(874, -243.5052, -1597.7508, 16.1303, 0.0000, -2.9000, -50.8997); //veg_procgrasspatch
    g_Object[486] = //CreateDynamicObject(874, -258.5479, -1620.0224, 16.2049, 0.8000, -2.0999, 142.8999); //veg_procgrasspatch
    g_Object[487] = //CreateDynamicObject(874, -267.6416, -1635.9593, 15.8718, 0.8000, -2.0999, 142.8999); //veg_procgrasspatch
    g_Object[488] = //CreateDynamicObject(874, -298.2322, -1648.6020, 15.6843, 0.5000, -0.3000, 150.6000); //veg_procgrasspatch
    g_Object[489] = //CreateDynamicObject(874, -302.1083, -1660.3303, 15.8556, 2.7000, -4.8000, 160.1999); //veg_procgrasspatch
    g_Object[490] = //CreateDynamicObject(874, -278.9902, -1662.4814, 15.1688, 0.8000, -2.0999, 156.6000); //veg_procgrasspatch
    g_Object[491] = //CreateDynamicObject(874, -281.3652, -1677.2740, 14.7416, 1.2999, 0.4999, -34.3997); //veg_procgrasspatch
    g_Object[492] = //CreateDynamicObject(874, -230.7140, -1645.5290, 3.0971, 1.7999, -0.2998, -47.9000); //veg_procgrasspatch
    g_Object[493] = CreateDynamicObject(825, -128.7382, -1453.5893, 12.8044, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[494] = CreateDynamicObject(825, -169.2032, -1502.8183, 13.2742, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[495] = CreateDynamicObject(825, -205.7695, -1539.3680, 15.4004, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[496] = CreateDynamicObject(825, -223.2478, -1568.9139, 15.9504, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[497] = CreateDynamicObject(825, -263.4779, -1622.1976, 16.0562, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[498] = CreateDynamicObject(825, -279.8102, -1670.2978, 15.2065, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[499] = CreateDynamicObject(825, -301.8710, -1666.4925, 15.9195, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[500] = CreateDynamicObject(806, -8.0368, -1387.9597, 3.1786, 0.0000, 0.0000, 0.0000); //genVEG_tallgrass
    g_Object[501] = CreateDynamicObject(3336, -128.8415, -1319.7032, 0.8238, 32.9000, 0.0000, -116.6996); //cxrf_frway1sig
    g_Object[502] = CreateDynamicObject(3594, -132.7559, -1320.3232, 1.7474, 0.0000, 0.0000, 118.4000); //la_fuckcar1
    g_Object[503] = CreateDynamicObject(639, -77.7098, -1431.0423, 19.5293, 0.0000, 0.0000, -131.4998); //veg_ivy_balcny_kb3
    g_Object[504] = CreateDynamicObject(639, -97.4813, -1413.2164, 19.5293, 0.0000, 0.0000, -132.6999); //veg_ivy_balcny_kb3
    g_Object[505] = CreateDynamicObject(639, -85.1249, -1424.3332, 19.5293, 0.0000, 0.0000, -132.6999); //veg_ivy_balcny_kb3
    g_Object[506] = CreateDynamicObject(639, -90.0345, -1422.6593, 17.3591, 0.0000, 0.0000, 48.0000); //veg_ivy_balcny_kb3
    g_Object[507] = CreateDynamicObject(639, -104.5485, -1409.5909, 17.3591, 0.0000, 0.0000, 48.0000); //veg_ivy_balcny_kb3
    g_Object[508] = //CreateDynamicObject(874, 30.5445, -1148.6319, 7.8522, 5.3997, -4.5998, -106.6996); //veg_procgrasspatch
    g_Object[509] = CreateDynamicObject(9812, 80.8507, -1025.2628, 15.3023, 0.0000, 0.0000, 0.0000); //veg_ivy_balcny_kb08
    g_Object[510] = CreateDynamicObject(9812, 80.0194, -1015.7437, 15.3023, 0.0000, 0.0000, 179.3999); //veg_ivy_balcny_kb08
    g_Object[511] = //CreateDynamicObject(874, 29.9083, -1035.3828, 22.0955, -7.9998, 1.7000, -93.9000); //veg_procgrasspatch
    g_Object[512] = //CreateDynamicObject(874, 32.7896, -999.0974, 24.7887, -11.4996, 7.4998, -78.2995); //veg_procgrasspatch
    g_Object[513] = //CreateDynamicObject(874, -60.6114, -1241.7402, 4.7322, 4.0000, -3.3998, -67.5000); //veg_procgrasspatch
    g_Object[514] = //CreateDynamicObject(874, -51.1669, -1236.1671, 5.8520, 4.0000, -4.6999, -58.5998); //veg_procgrasspatch
    g_Object[515] = //CreateDynamicObject(874, -12.5094, -1198.4709, 6.8913, -0.2998, -4.6999, -38.4000); //veg_procgrasspatch
    g_Object[516] = //CreateDynamicObject(874, -6.0727, -1187.4449, 6.6767, -0.2998, -4.6999, -38.4000); //veg_procgrasspatch
    g_Object[517] = CreateDynamicObject(16302, -135.1022, -1510.1706, 4.6381, 0.0000, 0.0000, -78.7996); //des_gravelpile04
    SetDynamicObjectMaterial(g_Object[517], 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    g_Object[518] = //CreateDynamicObject(874, 5.2121, -1418.1236, 3.2132, 0.0000, 0.0000, 42.5000); //veg_procgrasspatch
    g_Object[519] = CreateDynamicObject(806, -8.0368, -1398.2696, 3.1786, 0.0000, 0.0000, -45.6999); //genVEG_tallgrass
    g_Object[520] = CreateDynamicObject(806, 4.0082, -1359.7540, 2.6621, 0.0000, 0.0000, 0.0000); //genVEG_tallgrass
    g_Object[521] = CreateDynamicObject(806, 2.7235, -1354.2999, 3.0473, 0.0000, 0.0000, -112.5000); //genVEG_tallgrass
    g_Object[522] = CreateDynamicObject(806, 3.0227, -1329.4631, 1.9716, 0.0000, 0.0000, 0.0000); //genVEG_tallgrass
    g_Object[523] = CreateDynamicObject(3172, -146.8782, -1027.3662, 0.2080, 0.0000, 0.0000, 25.8999); //trailer6_01
    g_Object[524] = CreateDynamicObject(3585, -157.7357, -1028.5091, 11.9182, 0.0000, 0.0000, 16.5000); //lastran1_LA02
    g_Object[525] = CreateDynamicObject(3585, -149.1286, -1026.1573, 12.0184, 0.0000, 0.0000, 13.8000); //lastran1_LA02
    g_Object[526] = CreateDynamicObject(3585, -166.1062, -1030.9885, 11.9182, -4.6999, 0.0000, 37.7000); //lastran1_LA02
    g_Object[527] = CreateDynamicObject(3585, -176.4786, -1039.0024, 12.1983, 89.3999, 0.0000, -9.5999); //lastran1_LA02
    g_Object[528] = CreateDynamicObject(3585, -185.7467, -1037.4322, 12.3881, 89.1997, -3.9999, -120.6997); //lastran1_LA02
    g_Object[529] = CreateDynamicObject(19632, -152.1492, -1025.3773, 0.1949, 0.0000, 0.0000, -98.4999); //FireWood1
    g_Object[530] = //CreateDynamicObject(874, -132.6389, -1016.1580, 12.1449, 0.6000, 16.6998, -109.0000); //veg_procgrasspatch
    g_Object[531] = CreateDynamicObject(14872, -149.6629, -1026.9521, 0.6847, 0.0000, 0.0000, -168.1999); //Kylie_logs
    g_Object[532] = CreateDynamicObject(17453, -10.0263, -1459.2192, 3.2169, 0.0000, 0.0000, -143.6997); //brownwater
    g_Object[533] = CreateDynamicObject(1328, -150.3285, -1021.8339, 0.5835, 0.0000, 0.0000, 0.0000); //BinNt10_LA
    g_Object[534] = CreateDynamicObject(1440, -147.2745, -1031.6800, 0.9545, 0.0000, 0.0000, -63.2000); //DYN_BOX_PILE_3
    g_Object[535] = CreateDynamicObject(1369, -153.4313, -1023.6557, 0.7372, 0.0000, 0.0000, 32.2999); //CJ_WHEELCHAIR1
    g_Object[536] = //CreateDynamicObject(874, -153.0563, -1037.9610, 2.1166, 0.0000, 7.4000, 0.0000); //veg_procgrasspatch
    g_Object[537] = //CreateDynamicObject(874, -157.9564, -1057.7248, 1.9148, 0.0000, 0.0000, -60.9000); //veg_procgrasspatch
    g_Object[538] = CreateDynamicObject(3005, -145.8795, -1032.9707, 0.4320, 1.3997, 1.1999, 93.0998); //smash_box_stay
    g_Object[539] = //CreateDynamicObject(874, -165.9174, -1015.7907, 1.2956, 0.0000, 0.0000, 25.5000); //veg_procgrasspatch
    g_Object[540] = CreateDynamicObject(12957, -162.6502, -1009.1126, 0.5356, 0.0000, 0.0000, 42.8997); //sw_pickupwreck01
    g_Object[541] = CreateDynamicObject(19354, -164.7801, -1007.7028, -0.2144, -1.7999, 90.8999, -8.6997); //wall002
    SetDynamicObjectMaterial(g_Object[541], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[542] = CreateDynamicObject(1370, -162.9136, -1008.6251, 0.9294, 0.0000, 0.0000, 0.0000); //CJ_FLAME_Drum_(F)
    g_Object[543] = CreateDynamicObject(1370, -162.9136, -1007.7548, 0.9294, 0.0000, 0.0000, -82.2997); //CJ_FLAME_Drum_(F)
    SetDynamicObjectMaterial(g_Object[543], 0, 5408, "tempstuff_lae", "sl_metalbndrust1", 0x00000000);
    g_Object[544] = CreateDynamicObject(806, 4.0226, -1330.3332, 1.9716, 0.0000, 0.0000, -31.3999); //genVEG_tallgrass
    g_Object[545] = CreateDynamicObject(10984, 94.6184, -1018.7039, 22.0102, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[546] = CreateDynamicObject(10984, 91.3394, -1018.7039, 24.4181, 0.0000, -29.9999, 0.0000); //rubbled01_SFS
    g_Object[547] = //CreateDynamicObject(874, -15.0431, -1030.4560, 23.1646, 6.1999, -22.2999, -93.9000); //veg_procgrasspatch
    g_Object[548] = CreateDynamicObject(880, 72.1576, -1027.0061, 0.0538, 0.0000, 0.0000, 0.0000); //p_rubble0bcol
    g_Object[549] = CreateDynamicObject(17453, 115.8196, -1287.8093, 3.2869, 0.0000, 0.0000, 5.6999); //brownwater
    g_Object[550] = CreateDynamicObject(17453, 208.0713, -1294.7125, 3.1868, 0.0000, 0.0000, 5.6999); //brownwater
    g_Object[551] = CreateDynamicObject(17453, -3.3013, -1155.5211, 3.4068, 0.0000, 0.0000, -133.5000); //brownwater
    g_Object[552] = CreateDynamicObject(17453, 176.8432, -1142.3658, 3.6068, 0.0000, 0.0000, 45.9999); //brownwater
    g_Object[553] = CreateDynamicObject(17453, 14.9397, -973.9970, 3.5769, -0.2998, 0.0000, -149.7003); //brownwater
    g_Object[554] = CreateDynamicObject(880, 68.1000, -1023.9970, 0.0538, 0.0000, 0.0000, -76.4000); //p_rubble0bcol
    g_Object[555] = CreateDynamicObject(880, 64.8246, -1024.7895, 0.0538, 0.0000, 0.0000, 131.0997); //p_rubble0bcol
    g_Object[556] = CreateDynamicObject(880, 58.4168, -1025.2180, 0.0538, 0.0000, 0.0000, 131.0997); //p_rubble0bcol
    g_Object[557] = CreateDynamicObject(880, 62.3562, -1024.8199, 0.0538, 0.0000, 0.0000, 131.0997); //p_rubble0bcol
    g_Object[558] = CreateDynamicObject(897, 4.3576, -889.4016, -1.8896, 0.0000, 0.0000, 0.0000); //searock01
    g_Object[559] = CreateDynamicObject(897, 32.8475, -934.0020, -1.8896, 0.0000, 0.0000, 0.0000); //searock01
    g_Object[560] = CreateDynamicObject(897, 27.9118, -926.5437, -1.5872, 0.0000, 0.0000, -39.5998); //searock01
    g_Object[561] = CreateDynamicObject(897, 22.7907, -919.1251, -1.5872, 0.0000, 0.0000, -152.3999); //searock01
    g_Object[562] = CreateDynamicObject(897, 17.9930, -914.0275, -1.5872, 0.0000, 0.0000, -111.9000); //searock01
    g_Object[563] = CreateDynamicObject(897, 12.9102, -906.7243, -1.5872, 0.0000, 0.0000, -51.5998); //searock01
    g_Object[564] = CreateDynamicObject(897, 9.4316, -902.3358, -1.5872, 0.0000, 0.0000, -82.0998); //searock01
    g_Object[565] = CreateDynamicObject(897, 7.7428, -894.5297, -2.5652, 0.0000, -47.2999, -82.0998); //searock01
    g_Object[566] = CreateDynamicObject(2935, 66.6445, -1204.3430, -0.0091, 10.1997, 0.0000, -61.0000); //kmb_container_yel
    SetDynamicObjectMaterial(g_Object[566], 0, -1, "none", "none", 0xFFFFFAFA);
    g_Object[567] = CreateDynamicObject(2934, 73.6579, -1208.4737, 0.2370, -3.6998, 0.0000, -32.0000); //kmb_container_red
    SetDynamicObjectMaterial(g_Object[567], 0, -1, "none", "none", 0xFFFFFAFA);
    g_Object[568] = CreateDynamicObject(3043, 73.1622, -1199.3885, 0.3921, 0.0000, 0.0000, 0.0000); //kmb_container_open
    g_Object[569] = CreateDynamicObject(806, 1.9627, -1319.5434, 1.9716, 0.0000, 0.0000, 0.0000); //genVEG_tallgrass
    g_Object[570] = CreateDynamicObject(806, 25.8474, -1133.2065, 1.7401, 0.0000, 0.0000, 0.0000); //genVEG_tallgrass
    g_Object[571] = CreateDynamicObject(17453, -3.3013, -1155.5211, 3.2969, 0.0000, 0.0000, -133.5000); //brownwater
    g_Object[572] = CreateDynamicObject(806, 41.3174, -1139.2569, 3.5701, 0.0000, 0.0000, 46.0000); //genVEG_tallgrass
    g_Object[573] = CreateDynamicObject(806, 17.6844, -1116.6446, 3.5833, 0.0000, 0.0000, 16.5000); //genVEG_tallgrass
    g_Object[574] = CreateDynamicObject(806, 6.9730, -1097.7558, 3.4107, 0.0000, 0.0000, 0.0000); //genVEG_tallgrass
    g_Object[575] = CreateDynamicObject(17453, 72.3367, -1121.2176, 2.9897, -0.2998, 0.0000, -149.7003); //brownwater
    g_Object[576] = CreateDynamicObject(17005, -389.9118, -1434.3105, 30.3453, -4.1999, 5.2999, 0.0000); //farmhouse
    g_Object[577] = CreateDynamicObject(10985, -388.5596, -1422.3121, 25.8677, 0.0000, 0.0000, 0.0000); //rubbled02_SFS
    g_Object[578] = CreateDynamicObject(10985, -401.9096, -1422.3121, 24.9577, 0.0000, 0.0000, 62.1999); //rubbled02_SFS
    g_Object[579] = CreateDynamicObject(10985, -402.8587, -1432.1103, 24.9577, 0.0000, 0.0000, 93.8999); //rubbled02_SFS
    g_Object[580] = CreateDynamicObject(10985, -394.6109, -1437.5316, 25.4878, 0.0000, 0.0000, 93.8999); //rubbled02_SFS
    g_Object[581] = CreateDynamicObject(10985, -393.0025, -1446.8647, 25.5177, 0.0000, -1.5000, 93.8999); //rubbled02_SFS
    g_Object[582] = CreateDynamicObject(10985, -384.5632, -1448.0334, 25.4722, 0.0000, -1.6000, 93.8999); //rubbled02_SFS
    g_Object[583] = CreateDynamicObject(10985, -385.3952, -1435.8298, 25.5739, 0.0000, -1.6000, 93.8999); //rubbled02_SFS
    g_Object[584] = CreateDynamicObject(17000, -405.5964, -1453.9693, 25.3703, 93.0998, 0.0000, 0.0000); //wt6suppsxc
    SetDynamicObjectMaterial(g_Object[584], 0, 3900, "station", "rustd64", 0x00000000);
    SetDynamicObjectMaterial(g_Object[584], 1, 3900, "station", "rustd64", 0x00000000);
    SetDynamicObjectMaterial(g_Object[584], 2, 3900, "station", "rustd64", 0x00000000);
    SetDynamicObjectMaterial(g_Object[584], 3, 3900, "station", "rustd64", 0x00000000);
    SetDynamicObjectMaterial(g_Object[584], 4, 3900, "station", "rustd64", 0x00000000);
    SetDynamicObjectMaterial(g_Object[584], 5, 19297, "matlights", "invisible", 0x00000000);
    g_Object[585] = CreateDynamicObject(16304, -405.0415, -1457.5400, 24.7387, 0.0000, 0.0000, 0.0000); //des_gravelpile05
    SetDynamicObjectMaterial(g_Object[585], 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    g_Object[586] = CreateDynamicObject(16304, -405.0415, -1474.3902, 24.3687, 0.0000, 0.0000, 0.0000); //des_gravelpile05
    SetDynamicObjectMaterial(g_Object[586], 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    g_Object[587] = CreateDynamicObject(639, -361.3854, -1429.2425, 31.1025, 0.0000, 0.0000, 178.8997); //veg_ivy_balcny_kb3
    g_Object[588] = CreateDynamicObject(639, -361.1813, -1418.6346, 31.1025, 0.0000, 0.0000, 179.4998); //veg_ivy_balcny_kb3
    g_Object[589] = CreateDynamicObject(639, -368.8890, -1415.5251, 31.1613, 0.0000, 0.0000, -90.6997); //veg_ivy_balcny_kb3
    g_Object[590] = CreateDynamicObject(639, -369.2608, -1432.2613, 31.1186, 0.0000, 0.0000, 87.9999); //veg_ivy_balcny_kb3
    g_Object[591] = CreateDynamicObject(3425, -372.1694, -1445.3089, 32.9949, 0.0000, -5.6999, 0.0000); //nt_windmill
    g_Object[592] = //CreateDynamicObject(874, -330.4248, -1266.2501, 21.9535, 11.8999, 14.1000, 0.0000); //veg_procgrasspatch
    g_Object[593] = //CreateDynamicObject(874, -247.4808, -1166.0793, 8.6964, -5.3000, 13.6998, -56.2000); //veg_procgrasspatch
    g_Object[594] = //CreateDynamicObject(874, -235.4633, -1154.3089, 6.8829, -13.1998, 24.2999, -56.2000); //veg_procgrasspatch
    g_Object[595] = //CreateDynamicObject(874, -223.7178, -1301.8779, 8.8158, -2.7000, 4.5000, 0.0000); //veg_procgrasspatch
    g_Object[596] = //CreateDynamicObject(874, -218.3014, -1301.4919, 7.9805, -2.7000, 4.5000, 171.1000); //veg_procgrasspatch
    g_Object[597] = CreateDynamicObject(19354, -153.0673, -1189.2677, 3.2913, 2.0000, -85.7998, -2.0999); //wall002
    SetDynamicObjectMaterial(g_Object[597], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[598] = CreateDynamicObject(19354, -213.6596, -1175.2534, 7.3211, -6.2999, 90.9999, 87.3000); //wall002
    SetDynamicObjectMaterial(g_Object[598], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[599] = CreateDynamicObject(19354, -206.3614, -1215.7607, 7.9695, 0.0000, 75.7998, -60.9999); //wall002
    SetDynamicObjectMaterial(g_Object[599], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[600] = CreateDynamicObject(19354, -191.4523, -1207.9515, 7.6441, -5.6999, 92.7998, -21.6000); //wall002
    SetDynamicObjectMaterial(g_Object[600], 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    g_Object[601] = CreateDynamicObject(2907, -206.4346, -1215.3800, 7.9825, -16.0000, -8.4998, 0.0000); //kmb_deadtorso
    g_Object[602] = CreateDynamicObject(2907, -191.5169, -1207.6955, 7.7273, -2.0999, 0.0000, -165.1000); //kmb_deadtorso
    g_Object[603] = CreateDynamicObject(2905, -191.4557, -1208.3614, 7.8027, 6.8000, 0.0000, -173.0000); //kmb_deadleg
    g_Object[604] = CreateDynamicObject(2906, -191.9385, -1207.4442, 7.7220, 0.0000, 0.0000, 94.2998); //kmb_deadarm
    g_Object[605] = CreateDynamicObject(2905, -213.1694, -1174.8780, 7.4703, 0.0000, 0.0000, -32.7999); //kmb_deadleg
    g_Object[606] = CreateDynamicObject(2906, -213.4127, -1175.6534, 7.4629, 0.0000, 0.0000, -64.7998); //kmb_deadarm
    g_Object[607] = CreateDynamicObject(2907, -153.4452, -1189.0711, 3.4505, -5.1999, 0.0000, -144.3999); //kmb_deadtorso
    g_Object[608] = CreateDynamicObject(19624, -149.6094, -1191.3891, 3.1036, 86.8000, 0.0000, 0.0000); //Case1
    g_Object[609] = CreateDynamicObject(19624, -161.2095, -1184.5124, 4.1434, -92.7998, 0.0000, 0.0000); //Case1
    g_Object[610] = CreateDynamicObject(2844, -214.6457, -1174.6495, 7.2683, 0.0000, 0.0000, 0.0000); //gb_bedclothes03
    g_Object[611] = CreateDynamicObject(19624, -214.2852, -1174.4593, 7.7270, 0.0000, -6.1999, 31.0998); //Case1
    SetDynamicObjectMaterial(g_Object[611], 3, 2905, "dead_mantxd", "billyblood", 0x00000000);
    g_Object[612] = CreateDynamicObject(2845, -190.5370, -1207.5555, 7.5015, 0.0000, 0.0000, 0.0000); //gb_bedclothes04
    g_Object[613] = CreateDynamicObject(2846, -193.5420, -1208.1053, 7.7799, 0.3000, 3.0999, 0.0000); //gb_bedclothes05
    g_Object[614] = CreateDynamicObject(2843, -150.6531, -1190.0177, 3.1180, 0.6998, 4.3998, 0.0000); //gb_bedclothes02
    g_Object[615] = CreateDynamicObject(2844, -151.5771, -1189.7857, 3.2235, 0.0000, 4.4998, 0.0000); //gb_bedclothes03
    g_Object[616] = CreateDynamicObject(2846, -161.7982, -1185.2535, 4.0777, 0.0000, 0.0000, 0.0000); //gb_bedclothes05
    g_Object[617] = CreateDynamicObject(635, -367.7832, -1413.1059, 28.1056, -0.2000, -89.9000, -91.1000); //veg_fern_balcny_kb1
    g_Object[618] = //CreateDynamicObject(874, -346.4342, -1243.0061, 29.4244, -8.7999, 9.5999, -94.0998); //veg_procgrasspatch
    g_Object[619] = CreateDynamicObject(17457, -569.0811, -1493.1510, 11.6211, 0.0000, 6.0998, 42.2000); //sjmoldbarn04
    g_Object[620] = CreateDynamicObject(10984, -563.4771, -1499.7761, 8.6658, 0.0000, 0.0000, 0.0000); //rubbled01_SFS
    g_Object[621] = CreateDynamicObject(10984, -572.1273, -1494.5262, 8.6658, 0.0000, 0.0000, -168.3000); //rubbled01_SFS
    g_Object[622] = CreateDynamicObject(10984, -578.1126, -1491.6607, 8.6658, 0.0000, 0.0000, -168.3000); //rubbled01_SFS
    g_Object[623] = CreateDynamicObject(10984, -572.7929, -1486.3309, 9.2958, 0.0000, 0.0000, -168.3000); //rubbled01_SFS
    g_Object[624] = CreateDynamicObject(10984, -568.7080, -1491.7556, 9.2958, 0.0000, 0.0000, -168.3000); //rubbled01_SFS
    g_Object[625] = //CreateDynamicObject(874, -344.3367, -1654.1462, 25.1462, 4.8000, -14.0999, -173.8999); //veg_procgrasspatch
    g_Object[626] = CreateDynamicObject(791, -232.4734, -1446.4387, 2.8050, 0.0000, 0.0000, 138.6000); //vbg_fir_copse
    g_Object[627] = CreateDynamicObject(18688, -56.2346, -1587.0273, 1.0532, 0.0000, 0.0000, 0.0000); //fire
    g_Object[628] = CreateDynamicObject(1442, -65.2570, -1598.5294, 2.2137, 0.0000, 0.0000, 0.0000); //DYN_FIREBIN0
    g_Object[629] = CreateDynamicObject(661, -101.5815, -1543.8489, 1.5850, 0.0000, 0.0000, 0.0000); //pinetree07
    g_Object[630] = //CreateDynamicObject(874, -82.3221, -1548.3654, 2.6107, 0.0000, 0.0000, 0.0000); //veg_procgrasspatch
    g_Object[631] = //CreateDynamicObject(874, -51.6921, -1556.0155, 2.6107, 0.0000, 0.0000, -171.3000); //veg_procgrasspatch
    g_Object[632] = //CreateDynamicObject(874, -83.2145, -1595.0766, 2.6107, 0.0000, 0.0000, 0.0000); //veg_procgrasspatch
    g_Object[633] = //CreateDynamicObject(874, -103.2793, -1571.9017, 2.6171, 0.0000, 0.0000, -20.8999); //veg_procgrasspatch
    g_Object[634] = CreateDynamicObject(18688, -76.3713, -1586.9223, 1.1871, 0.0000, 0.0000, 0.0000); //fire
    g_Object[635] = //CreateDynamicObject(874, -64.8779, -1560.5860, 2.4070, 0.0000, 0.0000, 0.0000); //veg_procgrasspatch
    g_Object[636] = //CreateDynamicObject(874, -64.8779, -1585.8560, 2.4070, 0.0000, 0.0000, -87.4000); //veg_procgrasspatch
    g_Object[637] = CreateDynamicObject(18688, -65.3491, -1598.5687, 0.9686, 0.0000, 0.0000, 0.0000); //fire
    g_Object[638] = CreateDynamicObject(1442, -76.3469, -1586.7189, 2.2137, 0.0000, 0.0000, 0.0000); //DYN_FIREBIN0
    g_Object[639] = CreateDynamicObject(1442, -92.9169, -1586.7189, 2.2137, 0.0000, 0.0000, 71.7999); //DYN_FIREBIN0
    g_Object[640] = CreateDynamicObject(1442, -87.6360, -1568.9273, 2.2137, 0.0000, 0.0000, 71.7999); //DYN_FIREBIN0
    g_Object[641] = CreateDynamicObject(1442, -64.8260, -1551.2567, 2.1737, 0.0000, 0.0000, 71.7999); //DYN_FIREBIN0
    g_Object[642] = CreateDynamicObject(18688, -64.9893, -1551.4047, 1.1471, 0.0000, 0.0000, 0.0000); //fire
    g_Object[643] = CreateDynamicObject(19869, -57.7821, -1588.1397, 1.6925, 0.0000, -2.5000, 0.0000); //MeshFence2
    g_Object[644] = CreateDynamicObject(19641, -62.4305, -1597.4219, 0.3199, 0.0000, 0.0000, 50.0000); //FenceSection1
    g_Object[645] = CreateDynamicObject(19641, -68.0753, -1602.9455, 0.3199, 0.0000, 0.0000, 39.6999); //FenceSection1
    g_Object[646] = CreateDynamicObject(19641, -74.4237, -1607.4320, 1.2499, 0.0000, 0.0000, 30.3000); //FenceSection1
    g_Object[647] = CreateDynamicObject(3593, -59.0965, -1600.0179, 2.1765, -1.6000, 0.0000, -43.9999); //la_fuckcar2
    g_Object[648] = CreateDynamicObject(19641, -74.4237, -1607.4320, 1.2499, 0.0000, 0.0000, 30.3000); //FenceSection1
    g_Object[649] = CreateDynamicObject(19641, -81.2579, -1611.3677, 1.2499, 0.0000, 0.0000, 28.3000); //FenceSection1
    g_Object[650] = CreateDynamicObject(19641, -88.1169, -1615.0603, 1.2499, 0.0000, 0.0000, 28.3000); //FenceSection1
    g_Object[651] = CreateDynamicObject(19641, -93.2542, -1613.3851, 1.2499, 0.0000, 0.0000, -64.1000); //FenceSection1
    g_Object[652] = CreateDynamicObject(19641, -96.6742, -1606.3421, 1.2499, 0.0000, 0.0000, -64.1000); //FenceSection1
    g_Object[653] = CreateDynamicObject(19641, -100.1031, -1599.2808, 1.2499, 0.0000, 0.0000, -64.1000); //FenceSection1
    g_Object[654] = CreateDynamicObject(19641, -103.9641, -1592.5533, 1.2499, 0.0000, 0.0000, -56.4000); //FenceSection1
    g_Object[655] = CreateDynamicObject(19641, -108.2806, -1586.0550, 1.2499, 0.0000, 0.0000, -56.4000); //FenceSection1
    g_Object[656] = CreateDynamicObject(19641, -112.6025, -1579.5521, 1.2499, 0.0000, 0.0000, -56.4000); //FenceSection1
    g_Object[657] = CreateDynamicObject(19641, -116.9190, -1573.0551, 1.2499, 0.0000, 0.0000, -56.4000); //FenceSection1
    g_Object[658] = CreateDynamicObject(19641, -116.1819, -1567.1800, 1.2499, 0.0000, 0.0000, -137.7000); //FenceSection1
    g_Object[659] = CreateDynamicObject(19641, -110.4053, -1561.9235, 1.2499, 0.0000, 0.0000, -137.7000); //FenceSection1
    g_Object[660] = CreateDynamicObject(19641, -104.6510, -1556.6871, 1.2499, 0.0000, 0.0000, -137.7000); //FenceSection1
    g_Object[661] = CreateDynamicObject(19641, -98.8892, -1551.4448, 1.2499, 0.0000, 0.0000, -137.7000); //FenceSection1
    g_Object[662] = CreateDynamicObject(19641, -93.1275, -1546.2025, 1.2499, 0.0000, 0.0000, -137.7000); //FenceSection1
    g_Object[663] = CreateDynamicObject(19641, -87.3658, -1540.9597, 1.2499, 0.0000, 0.0000, -137.7000); //FenceSection1
    g_Object[664] = CreateDynamicObject(19641, -81.6040, -1535.7171, 1.2499, 0.0000, 0.0000, -137.7000); //FenceSection1
    g_Object[665] = CreateDynamicObject(19641, -75.8424, -1530.4752, 1.2499, 0.0000, 0.0000, -137.7000); //FenceSection1
    g_Object[666] = CreateDynamicObject(19641, -69.6732, -1530.0371, 1.2499, 0.0000, 0.0000, 145.7999); //FenceSection1
    g_Object[667] = CreateDynamicObject(19641, -63.2302, -1534.4156, 1.2499, 0.0000, 0.0000, 145.7999); //FenceSection1
    g_Object[668] = CreateDynamicObject(19641, -56.7790, -1538.8007, 1.2499, 0.0000, 0.0000, 145.7999); //FenceSection1
    g_Object[669] = CreateDynamicObject(19641, -50.3360, -1543.1795, 1.2499, 0.0000, 0.0000, 145.7999); //FenceSection1
    g_Object[670] = CreateDynamicObject(19641, -43.9014, -1547.5550, 1.2499, 0.0000, 0.0000, 145.7999); //FenceSection1
    g_Object[671] = CreateDynamicObject(19641, -37.4667, -1551.9284, 1.2499, 0.0000, 0.0000, 145.7999); //FenceSection1
    g_Object[672] = CreateDynamicObject(19641, -35.7432, -1557.7324, 1.2499, 0.0000, 0.0000, 67.2999); //FenceSection1
    g_Object[673] = CreateDynamicObject(19641, -39.2023, -1564.7224, 1.2499, 0.0000, 0.0000, 60.1999); //FenceSection1
    g_Object[674] = CreateDynamicObject(19641, -42.9648, -1571.5534, 1.2499, 0.0000, 0.0000, 61.9999); //FenceSection1
    g_Object[675] = CreateDynamicObject(19641, -46.6219, -1578.4317, 1.2499, 0.0000, 0.0000, 61.9999); //FenceSection1
    g_Object[676] = CreateDynamicObject(19641, -50.9173, -1584.8779, 1.2499, 0.0000, 0.0000, 50.6999); //FenceSection1
    g_Object[677] = CreateDynamicObject(825, -36.8035, -1548.6341, 2.0741, 0.0000, 0.0000, -71.3999); //genVEG_bushy
    g_Object[678] = CreateDynamicObject(661, -95.0815, -1537.9188, 1.5850, 0.0000, 0.0000, -124.1999); //pinetree07
    g_Object[679] = CreateDynamicObject(659, -59.9107, -1527.2343, 1.0263, 0.0000, 0.0000, 0.0000); //pinetree01
    g_Object[680] = CreateDynamicObject(656, -38.1635, -1544.4041, 1.2684, 0.0000, 0.0000, 0.0000); //pinetree05
    g_Object[681] = CreateDynamicObject(656, -124.1320, -1572.0926, 3.5971, 0.0000, 0.0000, 0.0000); //pinetree05
    g_Object[682] = CreateDynamicObject(656, -106.0320, -1572.0926, 1.4671, 0.0000, 0.0000, 0.0000); //pinetree05
    g_Object[683] = CreateDynamicObject(656, -110.6120, -1526.6528, 1.4671, 0.0000, 0.0000, -120.5999); //pinetree05
    g_Object[684] = //CreateDynamicObject(874, -34.9917, -1591.0461, 3.4128, 0.0000, 0.0000, -50.5999); //veg_procgrasspatch
    g_Object[685] = //CreateDynamicObject(874, -119.3984, -1617.1497, 3.0671, 0.0000, 0.0000, -81.1000); //veg_procgrasspatch
    g_Object[686] = CreateDynamicObject(3593, -82.7874, -1585.5988, 2.0713, 0.0000, 0.0000, 0.0000); //la_fuckcar2
    g_Object[687] = CreateDynamicObject(3594, -63.5626, -1563.2001, 2.1671, 0.0000, 0.0000, 0.0000); //la_fuckcar1
    g_Object[688] = CreateDynamicObject(3594, -42.2904, -1587.6503, 2.4964, 0.0000, 1.6999, 0.0000); //la_fuckcar1
    g_Object[689] = CreateDynamicObject(3594, -42.1947, -1582.5678, 2.8210, -9.3000, 0.0000, 0.0000); //la_fuckcar1
    g_Object[690] = CreateDynamicObject(3594, -37.9949, -1569.7969, 2.0029, -3.3999, 0.0000, -21.2999); //la_fuckcar1
    g_Object[691] = CreateDynamicObject(656, -143.6635, -1643.2734, 1.9184, 0.0000, 0.0000, -32.4000); //pinetree05
    g_Object[692] = CreateDynamicObject(825, -30.1510, -1581.9223, 2.9533, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[693] = CreateDynamicObject(825, -60.1641, -1617.0357, 3.2060, 0.0000, 0.0000, 0.0000); //genVEG_bushy
    g_Object[694] = CreateDynamicObject(3594, -120.0549, -1174.7480, 2.1739, 0.0000, 0.0000, -10.1000); //la_fuckcar1
    g_Object[695] = CreateDynamicObject(656, -54.4120, -1572.0926, 1.1571, 0.0000, 0.0000, 0.0000); //pinetree05
    g_Object[696] = CreateDynamicObject(12957, -96.8385, -1123.3457, 0.7090, 0.0000, 0.0000, -20.8999); //sw_pickupwreck01
    g_Object[697] = CreateDynamicObject(3594, -121.6208, -1189.5833, 2.1739, 0.0000, 0.0000, 155.0999); //la_fuckcar1
    g_Object[698] = CreateDynamicObject(3593, -142.8326, -1245.2119, 2.1436, 0.1999, -0.2999, 18.4999); //la_fuckcar2
    g_Object[699] = CreateDynamicObject(3594, -140.5071, -1249.6206, 2.5794, -9.6999, 0.0000, -145.3999); //la_fuckcar1
    g_Object[700] = CreateDynamicObject(3594, -142.5835, -1252.2220, 2.2739, -0.3999, 0.0000, -169.1999); //la_fuckcar1
    g_Object[701] = //CreateDynamicObject(874, -141.7882, -1245.8786, 2.0353, 0.0000, 0.0000, 0.0000); //veg_procgrasspatch
    g_Object[702] = CreateDynamicObject(3594, -149.0622, -1294.4454, 2.2239, 0.0000, 0.0000, 7.4999); //la_fuckcar1
    g_Object[703] = CreateDynamicObject(3593, -147.9924, -1332.2791, 2.1666, 0.0000, -0.6999, -2.6999); //la_fuckcar2
    g_Object[704] = CreateDynamicObject(3594, -154.2739, -1389.2778, 2.1839, 0.0000, 0.0000, 6.9000); //la_fuckcar1
    g_Object[705] = CreateDynamicObject(3594, -139.9844, -1431.4221, 2.2539, 0.0000, 0.9999, -142.1999); //la_fuckcar1
    g_Object[706] = CreateDynamicObject(3594, -143.1367, -1427.0263, 2.6334, -7.6000, 0.0000, 34.6999); //la_fuckcar1
    g_Object[707] = CreateDynamicObject(12957, -113.1808, -1477.0310, 2.3159, 0.0000, 0.0000, -135.5999); //sw_pickupwreck01
    g_Object[708] = CreateDynamicObject(3593, -62.2720, -1509.3441, 1.4590, 0.9999, 1.4000, 0.0000); //la_fuckcar2

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 17000, -406.9140, -1448.9699, 24.6406, 0.10); // wt6suppsxc
    RemoveBuildingForPlayer(playerid, 17005, -391.1409, -1432.9899, 32.4296, 0.10); // farmhouse
    RemoveBuildingForPlayer(playerid, 17006, -394.9609, -1433.9699, 32.4453, 0.10); // D5002whi
    RemoveBuildingForPlayer(playerid, 3425, -370.3750, -1446.9699, 35.9530, 0.10); // nt_windmill
    RemoveBuildingForPlayer(playerid, 3336, -128.2890, -1317.9399, 1.1015, 0.10); // cxrf_frway1sig
    RemoveBuildingForPlayer(playerid, 17066, -86.8750, -1207.2399, 1.6875, 0.10); // cw2_genstore
    RemoveBuildingForPlayer(playerid, 1676, -92.1016, -1161.7900, 2.9609, 0.10); // washgaspump
    RemoveBuildingForPlayer(playerid, 1676, -97.0702, -1173.7500, 3.0312, 0.10); // washgaspump
    RemoveBuildingForPlayer(playerid, 17065, -90.1952, -1169.6700, 5.3125, 0.10); // cw2_garagecanopy
    RemoveBuildingForPlayer(playerid, 1676, -85.2422, -1165.0300, 2.6328, 0.10); // washgaspump
    RemoveBuildingForPlayer(playerid, 1676, -90.1406, -1176.6300, 2.6328, 0.10); // washgaspump
    RemoveBuildingForPlayer(playerid, 17064, -75.4688, -1174.5500, 0.8750, 0.10); // cw2_garage
    RemoveBuildingForPlayer(playerid, 1447, -63.2812, -1155.4399, 2.1015, 0.10); // DYN_MESH_4
    RemoveBuildingForPlayer(playerid, 1413, -58.7030, -1157.5999, 2.0234, 0.10); // DYN_MESH_3
    RemoveBuildingForPlayer(playerid, 17072, -54.9921, -1130.7299, 4.5781, 0.10); // smltrukext
    RemoveBuildingForPlayer(playerid, 17350, -54.9921, -1130.7299, 4.5781, 0.10); // LOD Model of smltrukext
    RemoveBuildingForPlayer(playerid, 17073, -56.1250, -1130.1700, 4.4921, 0.10); // smlltrukint
    RemoveBuildingForPlayer(playerid, 3244, -63.3437, -1042.9300, 19.1093, 0.10); // pylon_big1_
    RemoveBuildingForPlayer(playerid, 3338, -63.3437, -1042.9300, 19.1093, 0.10); // LOD Model of pylon_big1_
    RemoveBuildingForPlayer(playerid, 17457, -570.7340, -1490.3199, 15.0703, 0.10); // sjmoldbarn04

    return Y_HOOKS_CONTINUE_RETURN_1;
}
