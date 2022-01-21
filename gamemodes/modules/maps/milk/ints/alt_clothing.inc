#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	new g_Object[90];
	g_Object[0] = CreateDynamicObject(19380, 2456.8486, -1932.9110, 0.8877, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[0], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[1] = CreateDynamicObject(6959, 2472.6740, -1913.7657, -4.1178, 0.0000, 0.0000, 0.0000); //vegasNbball1
	SetDynamicObjectMaterial(g_Object[1], 0, 18045, "gen_munation", "mp_gun_floor", 0x00000000);
	g_Object[2] = CreateDynamicObject(19380, 2466.4470, -1932.9110, 0.8877, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[2], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[3] = CreateDynamicObject(19380, 2452.1477, -1929.1405, 0.8877, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[3], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[4] = CreateDynamicObject(19380, 2458.6303, -1919.0404, 0.8877, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[4], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[5] = CreateDynamicObject(19380, 2462.0905, -1929.1405, 0.8877, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[5], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[6] = CreateDynamicObject(6959, 2472.6740, -1913.7657, -0.5077, 0.0000, 0.0000, 0.0000); //vegasNbball1
	SetDynamicObjectMaterial(g_Object[6], 0, 4835, "airoads_las", "concretenewb256", 0x00000000);
	g_Object[7] = CreateDynamicObject(1536, 2453.1945, -1932.8890, -4.1749, 0.0000, 0.0000, 0.0000); //Gen_doorEXT15
	g_Object[8] = CreateDynamicObject(19380, 2462.0905, -1919.5417, 0.8877, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[8], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[9] = CreateDynamicObject(2394, 2454.8937, -1928.3863, -3.5378, 0.0000, 0.0000, 0.0000); //CJ_CLOTHES_STEP_1
	g_Object[10] = CreateDynamicObject(3032, 2458.5778, -1932.8116, -2.3494, 0.0000, 0.0000, 0.0000); //bd_window_shatter
	SetDynamicObjectMaterial(g_Object[10], 0, 17503, "furniture_lae2", "inwindow4", 0x00000000);
	g_Object[11] = CreateDynamicObject(19384, 2460.4611, -1923.7939, -2.6205, 0.0000, 0.0000, 90.0000); //wall032
	SetDynamicObjectMaterial(g_Object[11], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[12] = CreateDynamicObject(19380, 2463.6845, -1923.7910, 4.3576, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[12], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[13] = CreateDynamicObject(19380, 2453.5854, -1918.1297, 0.8877, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[13], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[14] = CreateDynamicObject(19380, 2463.1872, -1918.1297, 0.8877, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[14], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[15] = CreateDynamicObject(19380, 2455.2971, -1922.1816, 0.8877, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[15], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[16] = CreateDynamicObject(2371, 2460.5012, -1930.9969, -4.1848, 0.0000, 0.0000, 90.0000); //CLOTHES_RAIL
	g_Object[17] = CreateDynamicObject(19384, 2453.7773, -1926.9139, -2.6205, 0.0000, 0.0000, 90.0000); //wall032
	SetDynamicObjectMaterial(g_Object[17], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[18] = CreateDynamicObject(2371, 2455.4687, -1930.9969, -4.1848, 0.0000, 0.0000, 90.0000); //CLOTHES_RAIL
	g_Object[19] = CreateDynamicObject(2371, 2455.4687, -1928.7668, -4.1848, 0.0000, 0.0000, 90.0000); //CLOTHES_RAIL
	g_Object[20] = CreateDynamicObject(19380, 2452.1477, -1919.5300, 0.8877, 0.0000, 0.0000, 0.0000); //wall028
	SetDynamicObjectMaterial(g_Object[20], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[21] = CreateDynamicObject(19380, 2454.0495, -1923.7915, 0.8877, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[21], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[22] = CreateDynamicObject(19380, 2450.5583, -1926.9134, 4.3576, 0.0000, 0.0000, 90.0000); //wall028
	SetDynamicObjectMaterial(g_Object[22], 0, 9524, "blokmodb", "Bow_Grimebrick", 0x00000000);
	g_Object[23] = CreateDynamicObject(18762, 2464.0573, -1925.9222, -3.6995, 0.0000, 90.0000, 0.0000); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(g_Object[23], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFC0C0C0);
	g_Object[24] = CreateDynamicObject(18762, 2459.0659, -1925.9222, -3.6995, 0.0000, 90.0000, 0.0000); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(g_Object[24], 0, 16322, "a51_stores", "des_ghotwood1", 0xFFC0C0C0);
	g_Object[25] = CreateDynamicObject(1491, 2452.9995, -1926.9178, -4.3779, 0.0000, 0.0000, 0.0000); //Gen_doorINT01
	SetDynamicObjectMaterial(g_Object[25], 0, -1, "none", "none", 0xFFDCDCDC);
	g_Object[26] = CreateDynamicObject(2843, 2460.2788, -1922.9355, -4.1420, 0.0000, 0.0000, 0.0000); //gb_bedclothes02
	g_Object[27] = CreateDynamicObject(2371, 2457.2766, -1930.5179, -4.1848, 0.0000, 0.0000, 0.0000); //CLOTHES_RAIL
	g_Object[28] = CreateDynamicObject(2371, 2460.4797, -1928.7668, -4.1848, 0.0000, 0.0000, 90.0000); //CLOTHES_RAIL
	g_Object[29] = CreateDynamicObject(2392, 2457.6433, -1929.4801, -3.5260, 0.0000, 0.0000, 0.0000); //CJ_8_JEANS_MED
	g_Object[30] = CreateDynamicObject(2392, 2456.9826, -1930.3907, -3.5260, 0.0000, 0.0000, 0.0000); //CJ_8_JEANS_MED
	SetDynamicObjectMaterial(g_Object[30], 0, 2381, "cloth_trackies", "trackTr", 0x00000000);
	SetDynamicObjectMaterial(g_Object[30], 1, 2381, "cloth_trackies", "trackTr", 0x00000000);
	g_Object[31] = CreateDynamicObject(2845, 2454.0644, -1925.1601, -4.1406, 0.0000, 0.0000, 0.0000); //gb_bedclothes04
	g_Object[32] = CreateDynamicObject(14863, 2454.0783, -1930.3863, -3.5680, 0.0000, 0.0000, -135.8999); //clothes
	g_Object[33] = CreateDynamicObject(2382, 2459.3991, -1931.2856, -3.5690, 0.0000, 0.0000, 90.0000); //CJ_8_JEANS_Light
	g_Object[34] = CreateDynamicObject(2394, 2454.8769, -1930.6208, -3.5322, 0.0000, 0.0000, 0.0000); //CJ_CLOTHES_STEP_1
	SetDynamicObjectMaterial(g_Object[34], 0, 2374, "cloth_track_t", "tshirterisyell", 0x00000000);
	SetDynamicObjectMaterial(g_Object[34], 2, 2374, "cloth_track_t", "tshirterisyell", 0x00000000);
	g_Object[35] = CreateDynamicObject(2382, 2460.3300, -1931.2856, -3.5690, 0.0000, 0.0000, 90.0000); //CJ_8_JEANS_Light
	g_Object[36] = CreateDynamicObject(2394, 2454.8247, -1931.3077, -3.5415, 0.0000, 0.0000, 0.0000); //CJ_CLOTHES_STEP_1
	SetDynamicObjectMaterial(g_Object[36], 0, 2819, "gb_bedroomclths01", "GB_clothesbed05", 0x00000000);
	SetDynamicObjectMaterial(g_Object[36], 2, 2381, "cloth_trackies", "trackTrpro", 0x00000000);
	g_Object[37] = CreateDynamicObject(2819, 2458.5891, -1932.5804, -4.1689, 0.0000, 0.0000, 46.5000); //gb_bedclothes01
	g_Object[38] = CreateDynamicObject(2843, 2458.9182, -1928.1174, -4.1525, 0.0000, 0.0000, 0.0000); //gb_bedclothes02
	g_Object[39] = CreateDynamicObject(14864, 2457.3908, -1929.3386, -4.0064, 0.0000, 0.0000, 0.0000); //shoes
	g_Object[40] = CreateDynamicObject(10985, 2459.8356, -1918.3221, -4.8825, -4.4000, 0.4999, 0.0000); //rubbled02_SFS
	SetDynamicObjectMaterial(g_Object[40], 0, 1574, "dyn_trash", "trash", 0x00000000);
	g_Object[41] = CreateDynamicObject(2845, 2460.4184, -1920.3730, -3.5327, 0.0000, 8.1997, 0.0000); //gb_bedclothes04
	g_Object[42] = CreateDynamicObject(2845, 2459.0888, -1920.3730, -3.7258, 0.0000, -13.6000, 0.0000); //gb_bedclothes04
	g_Object[43] = CreateDynamicObject(2704, 2455.0476, -1929.0655, -3.5206, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_3
	SetDynamicObjectMaterial(g_Object[43], 1, 18901, "matclothes", "bandanacamo", 0xFFFFFFFF);
	g_Object[44] = CreateDynamicObject(2704, 2454.0666, -1929.0655, -3.5206, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_3
	SetDynamicObjectMaterial(g_Object[44], 1, 18901, "matclothes", "bandanacamo", 0xFFFFFFFF);
	g_Object[45] = CreateDynamicObject(2846, 2459.6198, -1923.4890, -4.1307, 0.0000, 1.1000, 0.0000); //gb_bedclothes05
	g_Object[46] = CreateDynamicObject(2382, 2460.3300, -1930.6152, -3.5690, 0.0000, 0.0000, 90.0000); //CJ_8_JEANS_Light
	g_Object[47] = CreateDynamicObject(2666, 2461.1860, -1929.8499, -4.1739, 90.0000, 16.2000, 0.0000); //CJ_PIZ_POSTER2
	SetDynamicObjectMaterial(g_Object[47], 0, 2729, "cj_binc_sign", "BINC_tshirt", 0x00000000);
	g_Object[48] = CreateDynamicObject(11727, 2453.9375, -1930.5280, -0.5011, 90.0000, 0.0000, 0.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[48], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[49] = CreateDynamicObject(1721, 2452.4843, -1924.1468, -4.1598, 0.0000, 0.0000, -127.7994); //est_chair1
	g_Object[50] = CreateDynamicObject(14863, 2457.8188, -1923.8802, -3.5608, 0.0000, 0.0000, 133.2998); //clothes
	g_Object[51] = CreateDynamicObject(2844, 2459.5664, -1921.8736, -4.1015, 23.2000, 0.0000, 0.0000); //gb_bedclothes03
	g_Object[52] = CreateDynamicObject(1959, 2457.0458, -1925.9453, -3.2820, 0.0000, 0.0000, 180.0000); //shop_till
	SetDynamicObjectMaterial(g_Object[52], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[53] = CreateDynamicObject(1491, 2459.6752, -1923.7967, -4.3779, 0.0000, 0.0000, 0.0000); //Gen_doorINT01
	SetDynamicObjectMaterial(g_Object[53], 0, -1, "none", "none", 0xFFDCDCDC);
	g_Object[54] = CreateDynamicObject(2846, 2460.2312, -1921.7229, -4.0205, 25.1998, 7.8997, 0.0000); //gb_bedclothes05
	g_Object[55] = CreateDynamicObject(2843, 2460.0590, -1920.7274, -3.5374, -7.3997, 3.9999, 0.0000); //gb_bedclothes02
	g_Object[56] = CreateDynamicObject(2819, 2460.0407, -1919.3436, -3.4059, 0.0000, 13.8000, 0.0000); //gb_bedclothes01
	g_Object[57] = CreateDynamicObject(2819, 2459.8405, -1920.3546, -3.4602, 0.0000, 11.8999, 0.0000); //gb_bedclothes01
	g_Object[58] = CreateDynamicObject(2845, 2460.8945, -1921.3404, -3.9625, 22.3999, 16.6000, -34.9000); //gb_bedclothes04
	g_Object[59] = CreateDynamicObject(2845, 2460.9399, -1919.4610, -3.5694, 0.0000, 15.6000, 0.0000); //gb_bedclothes04
	g_Object[60] = CreateDynamicObject(2846, 2458.6967, -1921.0882, -3.9851, 0.0000, -20.0000, 0.0000); //gb_bedclothes05
	g_Object[61] = CreateDynamicObject(2846, 2459.3566, -1921.0882, -3.7026, 0.0000, -8.0000, 0.0000); //gb_bedclothes05
	g_Object[62] = CreateDynamicObject(2819, 2459.2155, -1919.4554, -3.7757, -6.9998, -20.0000, 29.7999); //gb_bedclothes01
	g_Object[63] = CreateDynamicObject(2704, 2455.2478, -1929.0655, -3.5206, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_3
	SetDynamicObjectMaterial(g_Object[63], 1, 18901, "matclothes", "bandanacamo", 0xFFFFFFFF);
	g_Object[64] = CreateDynamicObject(2689, 2459.0454, -1928.3808, -3.5478, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_2
	SetDynamicObjectMaterial(g_Object[64], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[65] = CreateDynamicObject(2689, 2459.2155, -1928.3808, -3.5478, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_2
	SetDynamicObjectMaterial(g_Object[65], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[66] = CreateDynamicObject(2689, 2460.0563, -1928.3808, -3.5478, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_2
	SetDynamicObjectMaterial(g_Object[66], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[67] = CreateDynamicObject(2689, 2460.7170, -1928.3808, -3.5478, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_2
	SetDynamicObjectMaterial(g_Object[67], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[68] = CreateDynamicObject(2689, 2459.8862, -1928.3808, -3.5478, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_2
	SetDynamicObjectMaterial(g_Object[68], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[69] = CreateDynamicObject(2689, 2460.2065, -1928.3808, -3.5478, 0.0000, 0.0000, 90.0000); //CJ_HOODIE_2
	SetDynamicObjectMaterial(g_Object[69], 0, -1, "none", "none", 0xFFFFFFFF);
	g_Object[70] = CreateDynamicObject(2394, 2459.9018, -1929.0393, -3.5322, 0.0000, 0.0000, 0.0000); //CJ_CLOTHES_STEP_1
	SetDynamicObjectMaterial(g_Object[70], 0, 2374, "cloth_track_t", "trackytop1pro", 0x00000000);
	SetDynamicObjectMaterial(g_Object[70], 1, 2374, "cloth_track_t", "sweatrstar", 0x00000000);
	SetDynamicObjectMaterial(g_Object[70], 2, 2374, "cloth_track_t", "trackytop2eris", 0x00000000);
	g_Object[71] = CreateDynamicObject(19622, 2461.5878, -1923.5069, -3.4577, 17.0000, 0.3998, 0.0000); //Broom1
	g_Object[72] = CreateDynamicObject(2713, 2461.5815, -1923.5393, -4.0057, 0.0000, 0.0000, 0.0000); //cj_bucket
	g_Object[73] = CreateDynamicObject(3032, 2452.2358, -1929.9017, -2.3494, 0.0000, 0.0000, 90.0000); //bd_window_shatter
	SetDynamicObjectMaterial(g_Object[73], 0, 17503, "furniture_lae2", "inwindow4", 0x00000000);
	g_Object[74] = CreateDynamicObject(4227, 2462.0842, -1940.7009, -2.7906, 0.0000, 0.0000, 270.0000); //graffiti_lan01
	g_Object[75] = CreateDynamicObject(11727, 2459.7531, -1930.5280, -0.5011, 90.0000, 0.0000, 0.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[75], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[76] = CreateDynamicObject(11727, 2456.7602, -1930.5280, -0.5011, 90.0000, 0.0000, 0.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[76], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[77] = CreateDynamicObject(11727, 2456.7602, -1926.1185, -0.5011, 90.0000, 0.0000, 0.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[77], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[78] = CreateDynamicObject(11727, 2459.9333, -1926.1185, -0.5011, 90.0000, 0.0000, 0.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[78], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[79] = CreateDynamicObject(11727, 2453.7880, -1925.2375, -0.5011, 90.0000, 0.0000, 0.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[79], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[80] = CreateDynamicObject(11727, 2460.3420, -1920.6676, -0.5011, 90.0000, 0.0000, 0.0000); //PaperChaseLight1
	SetDynamicObjectMaterial(g_Object[80], 0, 1259, "billbrd", "spotlight_64", 0x00000000);
	g_Object[81] = CreateDynamicObject(19810, 2460.4128, -1923.8974, -1.6504, 0.0000, 0.0000, 180.0000); //StaffOnlySign1
	g_Object[82] = CreateDynamicObject(2384, 2452.6179, -1924.3009, -3.5669, 0.0000, 0.0000, -37.5999); //CJ_8_JEANS_DARK
	g_Object[83] = CreateDynamicObject(2845, 2459.6379, -1919.9298, -3.4326, 0.0000, 0.0000, 0.0000); //gb_bedclothes04
	g_Object[84] = CreateDynamicObject(2819, 2460.2697, -1920.3144, -3.6524, 0.0000, 0.0000, -55.4000); //gb_bedclothes01
	g_Object[85] = CreateDynamicObject(2819, 2460.8918, -1919.5799, -3.7823, 0.0000, 0.0000, -55.4000); //gb_bedclothes01
	g_Object[86] = CreateDynamicObject(2843, 2459.8034, -1921.3188, -3.6380, 7.5998, 1.3998, 0.0000); //gb_bedclothes02
	g_Object[87] = CreateDynamicObject(2843, 2458.7509, -1922.0272, -4.1542, 6.8000, -13.8999, 16.8999); //gb_bedclothes02
	g_Object[88] = CreateDynamicObject(2846, 2460.3398, -1919.5887, -3.3915, 0.0000, 17.0000, 0.0000); //gb_bedclothes05
	g_Object[89] = CreateDynamicObject(2845, 2458.2402, -1926.6822, -3.2021, 0.0000, 0.0000, 43.8998); //gb_bedclothes04


    return Y_HOOKS_CONTINUE_RETURN_1;
}
