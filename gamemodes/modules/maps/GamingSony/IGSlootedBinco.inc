#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new tmpobjid;




    tmpobjid = CreateDynamicObject(6959, 1081.458007, 1010.080017, 2051.000000, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 18031, "cj_exp", "mp_furn_floor", 0x00000000);
    tmpobjid = CreateDynamicObject(2376, 1088.375000, 1015.507019, 2050.935058, 0.000000, 0.000000, -90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 1730, "cj_furniture", "CJ_WOOD5", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 1730, "cj_furniture", "CJ_WOOD5", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 2, 1730, "cj_furniture", "CJ_WOOD5", 0x00000000);
    tmpobjid = CreateDynamicObject(2403, 1088.653076, 1013.802978, 2050.925048, 0.000000, 0.000000, -90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19426, "all_walls", "mirror01", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 1730, "cj_furniture", "CJ_WOOD5", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1088.153076, 1003.242004, 2052.711914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1083.473999, 1005.585021, 2052.711914, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1080.406982, 1008.213012, 2052.711914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1092.884033, 1007.971984, 2052.711914, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(2403, 1088.604003, 1014.786987, 2050.925048, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 19426, "all_walls", "mirror01", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 1730, "cj_furniture", "CJ_WOOD5", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1092.804931, 1020.562011, 2052.711914, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1094.442016, 1012.299987, 2052.711914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1094.442016, 1021.932006, 2052.711914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1083.299072, 1021.632995, 2052.711914, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1080.406982, 1017.846008, 2052.711914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(2446, 1082.616943, 1013.122009, 2050.963867, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1714, "cj_office", "la_kitch3", 0x00000000);
    tmpobjid = CreateDynamicObject(2447, 1082.646972, 1012.119995, 2050.963867, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 2, 19426, "all_walls", "mirror01", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 3, 1714, "cj_office", "la_kitch3", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 4, 1714, "cj_office", "la_kitch3", 0x00000000);
    tmpobjid = CreateDynamicObject(2448, 1082.648925, 1015.119018, 2050.963867, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 2, 19426, "all_walls", "mirror01", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 3, 1714, "cj_office", "la_kitch3", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 4, 1714, "cj_office", "la_kitch3", 0x00000000);
    tmpobjid = CreateDynamicObject(2450, 1082.855957, 1011.408020, 2050.967041, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1714, "cj_office", "la_kitch3", 0x00000000);
    tmpobjid = CreateDynamicObject(2446, 1082.616943, 1014.122009, 2050.963867, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1714, "cj_office", "la_kitch3", 0x00000000);
    tmpobjid = CreateDynamicObject(2450, 1082.619018, 1017.523986, 2050.967041, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1714, "cj_office", "la_kitch3", 0x00000000);
    tmpobjid = CreateDynamicObject(2446, 1081.859985, 1011.408996, 2050.963867, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1714, "cj_office", "la_kitch3", 0x00000000);
    tmpobjid = CreateDynamicObject(2446, 1080.859985, 1011.408996, 2050.963867, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1714, "cj_office", "la_kitch3", 0x00000000);
    tmpobjid = CreateDynamicObject(19431, 1087.482910, 1021.101989, 2052.711914, 0.000000, 0.000000, 45.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19431, 1080.981933, 1021.101989, 2052.711914, 0.000000, 0.000000, -45.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1083.136962, 1003.242004, 2052.711914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19450, 1078.406005, 1007.973999, 2052.711914, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 8639, "chinatownmall", "ctmall15_128", 0x00000000);
    tmpobjid = CreateDynamicObject(19172, 1080.502929, 1011.559997, 2053.120117, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3979, "civic01_lan", "sl_dwntwnshpfrnt1", 0x00000000);
    tmpobjid = CreateDynamicObject(19172, 1080.502929, 1017.666015, 2053.120117, 0.000000, 0.000000, 90.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 3979, "civic01_lan", "sl_dwntwnshpfrnt1", 0x00000000);
    tmpobjid = CreateDynamicObject(6959, 1081.458007, 1010.080017, 2054.390136, 0.000000, 180.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 6869, "vegastemp1", "vgnbarb_wall_128", 0x00000000);
    tmpobjid = CreateDynamicObject(2194, 1082.663085, 1017.317016, 2052.294921, 0.000000, 0.000000, -30.540000, -1, 2, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(tmpobjid, 1, 1560, "7_11_door", "CJ_CHROME2", 0x00000000);
    tmpobjid = CreateDynamicObject(1514, 1082.755004, 1013.135986, 2052.120117, 0.000000, 0.000000, 68.878997, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(1886, 1081.564941, 1021.036987, 2054.659179, 10.000000, 0.000000, 20.040000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2412, 1087.656005, 1007.986022, 2050.984863, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2372, 1081.435058, 1008.898986, 2050.949951, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2878, 1084.818969, 1021.559997, 2052.141113, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2876, 1082.346923, 1008.002014, 2052.141113, 0.000000, 0.000000, 180.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(1532, 1085.636962, 1005.666015, 2050.922851, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(1532, 1084.136962, 1005.666015, 2050.922851, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2878, 1082.405029, 1021.559997, 2052.141113, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2412, 1084.300048, 1007.986022, 2050.984863, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2374, 1089.457031, 1009.096984, 2052.300048, 0.000000, 0.000000, -165.539001, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2377, 1090.025024, 1009.260009, 2052.300048, 0.000000, 0.000000, -164.759002, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2389, 1090.729980, 1009.547973, 2052.300048, 0.000000, 0.000000, -157.500000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2390, 1091.424072, 1009.971984, 2052.300048, 0.000000, 0.000000, -142.679992, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2391, 1092.057006, 1010.554016, 2052.300048, 0.000000, 0.000000, -133.679992, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2383, 1092.562011, 1011.193969, 2052.300048, 0.000000, 0.000000, -219.899993, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2378, 1092.986083, 1011.900024, 2052.300048, 0.000000, 0.000000, -113.699996, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2377, 1093.164062, 1012.669006, 2052.300048, 0.000000, 0.000000, -102.779998, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2374, 1093.388916, 1015.369995, 2052.300048, 0.000000, 0.000000, -83.760002, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2378, 1093.135009, 1016.255981, 2052.300048, 0.000000, 0.000000, -71.400001, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2383, 1092.768066, 1017.031005, 2052.300048, 0.000000, 0.000000, -149.998992, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2389, 1092.270996, 1017.731994, 2052.300048, 0.000000, 0.000000, -47.459999, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2390, 1091.713989, 1018.327026, 2052.300048, 0.000000, 0.000000, -42.240001, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2391, 1091.051025, 1018.809997, 2052.300048, 0.000000, 0.000000, -29.399999, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2396, 1090.321044, 1019.159973, 2052.300048, 0.000000, 0.000000, -20.760000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2397, 1089.538085, 1019.403991, 2052.300048, 0.000000, 0.000000, -6.780000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2386, 1089.491943, 1019.359985, 2051.375000, 0.000000, 0.000000, -8.760000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2386, 1091.647949, 1018.218017, 2051.375000, 0.000000, 0.000000, -40.258998, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2386, 1092.039062, 1017.848022, 2051.375000, 0.000000, 0.000000, -48.240001, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2386, 1093.296020, 1013.255981, 2051.375000, 0.000000, 0.000000, -101.040000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2386, 1092.015014, 1010.695983, 2051.375000, 0.000000, 0.000000, -142.378997, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2386, 1090.882080, 1009.752014, 2051.375000, 0.000000, 0.000000, -146.039001, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2386, 1090.323974, 1009.471984, 2051.375000, 0.000000, 0.000000, -158.878997, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2705, 1081.219970, 1008.653015, 2051.586914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2706, 1081.650024, 1008.820800, 2051.036621, -91.200004, 1.499997, 131.400009, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2704, 1081.219970, 1008.989013, 2051.586914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2705, 1081.219970, 1009.353027, 2050.986816, 90.000000, -31.200008, 90.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2705, 1081.219970, 1009.520996, 2051.586914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2705, 1082.039916, 1009.691284, 2051.017089, 90.000000, -91.599998, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2706, 1081.219970, 1009.913024, 2051.586914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2706, 1081.219970, 1010.080993, 2051.586914, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2704, 1082.800292, 1009.027038, 2050.977050, 90.000000, -21.500001, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19039, 1082.928955, 1011.841003, 2052.254882, -10.000000, 0.000000, -81.480003, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19040, 1082.928955, 1011.981994, 2052.254882, -10.000000, 0.000000, -81.480003, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19041, 1082.928955, 1012.122985, 2052.254882, -10.000000, 0.000000, -81.480003, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19042, 1082.928955, 1012.263977, 2052.254882, -10.000000, 0.000000, -81.480003, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19043, 1082.928955, 1012.405029, 2052.254882, -10.000000, 0.000000, -81.480003, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19022, 1082.801025, 1014.867980, 2052.281982, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19023, 1082.801025, 1015.062011, 2052.281982, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19024, 1082.801025, 1015.255981, 2052.281982, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19025, 1082.801025, 1015.450012, 2052.281982, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19026, 1082.801025, 1015.643981, 2052.281982, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19027, 1082.801025, 1015.838012, 2052.281982, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19028, 1082.790039, 1016.049011, 2052.281982, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19029, 1082.790039, 1016.242980, 2052.281982, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19030, 1082.790039, 1016.630981, 2052.281982, 0.000000, 0.000000, -16.260000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2384, 1088.675048, 1014.789978, 2051.354003, 0.000000, 0.000000, -97.980003, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2384, 1088.644042, 1013.726989, 2051.354003, 0.000000, 0.000000, -92.638999, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(18639, 1088.697021, 1015.078002, 2051.885986, 0.000000, -90.000000, -53.580001, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(18946, 1088.697021, 1014.633972, 2051.852050, -9.000000, -90.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(18947, 1088.697021, 1014.106018, 2051.854003, -10.000000, -90.000000, 280.438995, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(18948, 1088.734008, 1013.703002, 2051.854003, -10.000000, -90.000000, 237.779006, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(11706, 1081.310058, 1020.598022, 2050.967041, 0.000000, 0.000000, 36.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19814, 1084.338012, 1021.541992, 2051.297851, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(19828, 1081.102050, 1011.645996, 2051.789062, 0.000000, 0.000000, 180.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2372, 1083.070190, 1008.704406, 2051.384277, -0.499998, -98.999992, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2819, 1089.022094, 1017.478881, 2050.953613, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2843, 1090.552368, 1012.898315, 2050.954345, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2844, 1083.651977, 1012.898315, 2050.983398, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2845, 1085.022216, 1014.518432, 2050.984375, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(2846, 1080.921142, 1013.938476, 2050.964355, 0.000000, 0.000000, 0.000000, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(14520, 1080.272094, 1012.785400, 2050.954101, 0.000000, 0.000000, -73.000030, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(14863, 1089.900390, 1010.839050, 2051.053710, 0.000000, 0.000000, -12.399998, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(14520, 1085.328735, 1014.133972, 2051.294433, 0.000000, 0.000000, -73.000030, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(14520, 1085.328735, 1014.133972, 2051.294433, 0.000000, 0.000000, 165.799972, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(14863, 1090.896484, 1010.620178, 2051.564208, 0.000000, 0.000000, -12.399998, -1, 2, -1, 300.00, 300.00); 
    tmpobjid = CreateDynamicObject(14863, 1085.031982, 1019.230285, 2051.564208, 0.000000, 0.000000, 40.799976, -1, 2, -1, 300.00, 300.00); 

    return Y_HOOKS_CONTINUE_RETURN_1;
}