#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new tempobjid;
    tempobjid = CreateDynamicObject(18716, 1388.0710, 466.3312, 15.9151, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //prt_smoke_expand
    //CreateDynamicObject(874, 1073.7495, 542.1558, 19.8826, 0.0000, 0.0000, -52.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 358.0061, 118.9057, 4.5685, 0.0000, 0.0000, -65.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -74.9784, 214.4743, 1.8703, 0.0000, 0.0000, 65.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3168, -473.7106, 296.9710, 2.5448, -0.1999, -93.0998, -94.3999, -1, -1, -1, 400.0, 400.0); //trailer2_01
    tempobjid = CreateDynamicObject(901, 2193.3339, -699.6945, 51.1226, 0.0000, 0.0000, 30.6000, -1, -1, -1, 400.0, 400.0); //searock05
    SetDynamicObjectMaterial(tempobjid, 0, 12871, "ce_ground01", "cs_rockdetail2", 0x00000000);
    //CreateDynamicObject(874, 1691.4078, 402.3648, 30.2115, 0.0000, 0.0000, -128.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(8128, 1732.6988, 508.9880, -23.5128, -13.8999, 4.6999, 0.4999, -1, -1, -1, 400.0, 400.0); //vgsSrdbrdg_lvs
    tempobjid = CreateDynamicObject(901, 2768.9343, 309.9519, 4.8031, 0.0000, -20.6998, 0.0000, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(901, 2762.8801, 310.3839, 5.0875, 0.0000, -12.3999, -116.5998, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(901, 2751.5031, 311.3171, 5.3218, 0.0000, -2.0999, 153.6999, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(901, 2756.7739, 314.5227, 3.2692, 0.0000, -2.0999, 153.6999, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(901, 2767.7939, 315.3684, 2.6507, 0.0000, -2.0999, 153.6999, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(8056, 1734.3863, 514.2324, -3.4546, -13.8999, 4.8000, 0.4900, -1, -1, -1, 400.0, 400.0); //vegasSedge19
    tempobjid = CreateDynamicObject(10354, 2736.5776, 204.3457, 1.5528, -3.6998, 0.0000, 25.0998, -1, -1, -1, 400.0, 400.0); //groundbit_13_SFS
    SetDynamicObjectMaterial(tempobjid, 5, 12871, "ce_ground01", "sw_stones", 0x00000000);
    tempobjid = CreateDynamicObject(3594, -199.7543, 247.6031, 11.8786, 7.9998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(901, 2775.4606, 306.8416, 4.9147, 7.0998, -1.1999, 3.9999, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(901, 2777.4790, 308.5119, 1.5872, 7.0998, -1.1999, -14.7999, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(901, 2771.9677, 312.9937, 0.5152, 7.0998, -10.5999, -14.7999, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(16430, 567.2385, 405.6069, 14.4034, 0.0000, -2.2999, -54.8997, -1, -1, -1, 400.0, 400.0); //des_ebrigroad02
    tempobjid = CreateDynamicObject(3331, 539.8021, 429.0791, 12.7788, -27.3999, 0.0000, 35.5998, -1, -1, -1, 400.0, 400.0); //cxrf_whitebrig
    SetDynamicObjectMaterial(tempobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
    SetDynamicObjectMaterial(tempobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
    tempobjid = CreateDynamicObject(16358, -168.4653, 365.0433, -9.2523, 0.0000, 9.6997, 74.9999, -1, -1, -1, 400.0, 400.0); //des_ebrigroad07
    tempobjid = CreateDynamicObject(3566, 1740.5168, 505.1817, 3.3292, -17.2000, 5.6999, -1.0000, -1, -1, -1, 400.0, 400.0); //lasntrk1
    //CreateDynamicObject(874, 1193.4289, 551.5714, 19.8826, 0.0000, 0.0000, 61.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3381, -192.7962, 302.5307, 2.3907, -25.1998, 0.0000, -15.4996, -1, -1, -1, 400.0, 400.0); //cxrf_redarch
    SetDynamicObjectMaterial(tempobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
    SetDynamicObjectMaterial(tempobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
    tempobjid = CreateDynamicObject(3381, -169.2769, 390.8569, -10.7845, 10.6997, 0.0000, -15.4996, -1, -1, -1, 400.0, 400.0); //cxrf_redarch
    SetDynamicObjectMaterial(tempobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
    SetDynamicObjectMaterial(tempobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
    tempobjid = CreateDynamicObject(3172, -201.6670, 256.3684, 11.7882, -9.8999, -82.0000, -3.7999, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(3171, -189.7563, 258.2164, 10.6197, -9.3999, -88.3999, -19.7000, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(3593, -196.2745, 260.6856, 10.3837, -4.4000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -199.4678, 254.4835, 11.3163, -9.4996, 0.0000, -28.1000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, -184.3621, 249.2532, 10.9916, -4.3997, 0.0000, -19.7000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3593, 1733.3016, 506.9960, 1.4953, -13.0999, -13.2999, -64.6996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1735.4964, 502.7535, 2.7274, 16.2000, -6.3997, 178.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, -213.4485, 259.3788, 10.7812, -4.3997, 0.0000, 52.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1734.7906, 506.4360, 1.8393, -16.0000, 0.6000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10794, 247.3679, 185.1510, 2.2200, 89.3999, -36.9999, 81.4999, -1, -1, -1, 400.0, 400.0); //car_ship_04_SFSe
    tempobjid = CreateDynamicObject(10795, 252.6622, 176.0113, 2.2890, 89.3999, -36.9999, 81.4999, -1, -1, -1, 400.0, 400.0); //car_ship_05_SFSe
    tempobjid = CreateDynamicObject(10793, 213.6840, 112.0233, 2.2242, 89.3999, -36.9999, 81.4999, -1, -1, -1, 400.0, 400.0); //car_ship_03_SFSe
    tempobjid = CreateDynamicObject(10773, 237.5155, 111.0149, 3.9553, -3.0999, 2.0999, 39.8997, -1, -1, -1, 400.0, 400.0); //dk_cargoshp2_SFSe
    tempobjid = CreateDynamicObject(13591, 1688.7463, 413.6914, 29.9353, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kickcar28
    //CreateDynamicObject(874, 1688.8343, 409.5343, 30.2115, 0.0000, 0.0000, -128.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3043, 257.1950, 115.3570, 2.0761, 24.7999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_container_open
    tempobjid = CreateDynamicObject(2932, 278.5216, 178.5299, -0.1673, -3.5000, -41.5000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_container_blue
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    tempobjid = CreateDynamicObject(2934, 300.0704, 191.3190, 0.1133, 22.9999, 54.9999, -88.1996, -1, -1, -1, 400.0, 400.0); //kmb_container_red
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    tempobjid = CreateDynamicObject(2935, 257.2911, 157.0137, -1.1354, 17.2000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_container_yel
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    tempobjid = CreateDynamicObject(2934, 297.1552, 156.7935, 2.8134, -0.9998, 0.0000, 71.5998, -1, -1, -1, 400.0, 400.0); //kmb_container_red
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    tempobjid = CreateDynamicObject(2932, 281.8135, 159.8193, -0.6107, -43.9000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_container_blue
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    tempobjid = CreateDynamicObject(639, 221.0014, 145.4263, 17.6168, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 225.4302, 149.7937, 17.6168, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 229.4669, 153.7183, 17.6168, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 240.7236, 164.7344, 17.7369, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 244.6327, 168.6318, 17.7369, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 252.6212, 176.4250, 17.7667, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 256.3450, 180.0973, 17.8568, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 260.1828, 183.8818, 17.8969, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 264.0704, 187.7156, 17.8969, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 277.6275, 201.0845, 17.9568, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 286.1716, 209.4537, 18.1769, 0.0000, 0.0000, 134.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 231.4304, 107.9717, 14.7665, 0.0000, 0.0000, 45.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 224.3049, 115.1875, 14.7665, 0.0000, 0.0000, 45.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 228.1248, 111.6296, 14.5965, 0.0000, 0.0000, -137.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(13591, 1707.0145, 406.1181, 29.7751, 0.0000, 0.0000, 160.8999, -1, -1, -1, 400.0, 400.0); //kickcar28
    tempobjid = CreateDynamicObject(3593, 1706.8802, 403.2232, 30.1912, 6.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3172, 1705.4244, 414.5555, 29.7534, -14.1997, -94.8000, -16.8999, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(3593, 1713.9930, 403.5906, 30.2028, -3.2000, 0.0000, 116.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3566, 1724.9466, 450.5274, 19.1427, -18.6000, 91.7994, -10.6997, -1, -1, -1, 400.0, 400.0); //lasntrk1
    tempobjid = CreateDynamicObject(3594, 1717.4925, 437.6947, 22.5177, -13.1997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1717.4925, 431.2203, 24.0363, 13.5000, 4.9000, 133.6999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, 1709.3835, 405.8291, 30.4458, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3593, 1727.3868, 472.3153, 12.1436, -15.6997, 3.7999, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1733.7164, 478.1557, 9.9209, 17.2999, 0.0000, 162.1999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1732.0946, 473.6033, 11.3837, 8.3000, 11.7999, 100.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3171, 1734.0920, 468.3789, 13.2615, 14.6997, -92.4000, -178.5997, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(1221, 1725.3424, 438.9042, 21.4260, -15.7999, 4.0998, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1221, 1721.4925, 438.9794, 21.6914, -14.3999, -7.3997, -48.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1230, 1721.0980, 436.0114, 22.4521, -9.1000, -84.5000, -0.3998, -1, -1, -1, 400.0, 400.0); //cardboardbox
    tempobjid = CreateDynamicObject(849, 1719.3126, 434.0913, 22.9692, -14.2999, 4.0998, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(2670, 1723.4416, 437.1734, 21.6385, -11.8999, 3.8998, -2.2999, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_1
    tempobjid = CreateDynamicObject(849, 1729.3957, 470.9656, 12.0703, -0.6998, -12.5999, -137.5000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(3005, 1723.3486, 439.8927, 20.9132, -11.6000, -6.1999, -55.8997, -1, -1, -1, 400.0, 400.0); //smash_box_stay
    tempobjid = CreateDynamicObject(1230, 1724.6263, 436.7625, 21.9841, -1.3997, -88.7001, -50.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox
    tempobjid = CreateDynamicObject(2905, 1731.0471, 469.3734, 12.1941, -13.9996, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2906, 1731.7823, 468.6162, 12.3304, -10.1000, 0.0000, -55.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2907, 1730.7363, 468.1011, 12.5303, 165.1000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 1727.6850, 466.8948, 13.2131, -8.3999, 0.0000, -82.5998, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(3594, 1717.4925, 451.0718, 18.8563, 16.2999, 0.0000, 168.6999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1721.1297, 456.8695, 16.9050, -12.1997, -11.3999, -62.7999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(2907, 1720.3789, 454.9154, 17.3913, -98.1996, 154.7998, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 1720.3645, 454.9353, 17.9535, -100.0998, -106.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2906, 1720.0207, 454.4530, 17.3575, 9.3999, 0.0000, -142.3999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2905, 1721.3215, 454.2182, 17.3148, 12.8000, 0.0000, -126.8999, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(1220, 1720.4704, 451.0097, 18.5107, -14.2999, 4.1999, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox2
    tempobjid = CreateDynamicObject(1220, 1721.7214, 453.1184, 17.7957, -14.2999, 83.4999, -58.0998, -1, -1, -1, 400.0, 400.0); //cardboardbox2
    tempobjid = CreateDynamicObject(3566, 1716.9809, 489.1252, 9.4117, 172.3999, -73.7001, -81.6996, -1, -1, -1, 400.0, 400.0); //lasntrk1
    tempobjid = CreateDynamicObject(3594, 1745.2281, 488.8322, 6.5043, -15.1997, 15.6997, 73.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1742.7425, 486.1105, 6.6515, 16.4999, 7.9000, 157.0997, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1742.2749, 481.0743, 8.4631, -11.1997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 1741.1396, 487.5993, 6.9106, -7.3997, 17.4999, 95.4999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1729.1662, 487.8551, 7.4815, 17.7999, 0.0000, 177.2001, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(2973, 1741.5185, 493.9020, 3.9268, -19.7000, 4.1999, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2973, 1745.8634, 501.1849, 2.7188, -104.8999, 5.8997, -14.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2973, 1749.3977, 519.8416, -1.4630, 16.2000, 19.3999, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2973, 1745.0576, 513.9207, -1.3702, 16.2000, -12.3999, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2907, 1736.7312, 494.5844, 4.3646, -20.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 1736.3243, 493.6394, 4.6798, -23.5998, 22.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2036, 1735.8967, 494.3962, 4.5156, 0.0000, -18.2999, -89.8000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(12957, 1728.3918, 479.3438, 10.2572, 13.1997, 12.8999, 112.5998, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(12957, 1729.8266, 463.4338, 14.5200, 13.0999, -9.5000, -161.8000, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(2906, 1733.5417, 489.5686, 6.1560, -13.6000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2905, 1734.8242, 491.1990, 5.5142, -13.6000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2036, 1733.4039, 490.0733, 6.0226, 6.5998, 14.7999, 100.6996, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(1220, 1730.6656, 493.7958, 5.4446, -16.9999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox2
    tempobjid = CreateDynamicObject(1220, 1732.4350, 492.1206, 5.7747, -5.2999, -15.8999, -94.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox2
    tempobjid = CreateDynamicObject(3594, 1715.8220, 419.2789, 27.1172, 9.5000, -9.1997, -144.1000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1712.0299, 414.2200, 28.4144, -12.2999, -4.0998, -45.7999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1715.7290, 414.8659, 28.5606, -4.4000, -17.7999, -173.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, 1709.3883, 426.3103, 25.9860, 14.1000, -1.0999, 172.9998, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(1450, 1706.6667, 418.0574, 28.1597, 0.0000, 13.6997, 67.9000, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(849, 1713.9654, 417.9263, 27.2416, 4.6999, 14.5999, 76.2994, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1265, 1709.7696, 426.1892, 26.2672, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, 1708.4995, 426.1892, 26.2672, 0.0000, 0.0000, -140.1999, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(3172, 1697.0300, 452.2221, 21.2957, -12.9996, -93.4999, -23.4999, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(639, 1719.5101, 406.9948, 28.6972, 14.3999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1721.1610, 411.8453, 27.3817, 14.3999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1722.9248, 417.0259, 25.9766, 14.3999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1724.7611, 422.2633, 24.5515, 14.3999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1728.0228, 431.7210, 21.7765, 14.3999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1729.6578, 436.4331, 20.4132, 14.3999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1731.4538, 441.5819, 19.0130, 14.3999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1736.1827, 454.7565, 15.0480, 17.1998, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1737.8299, 459.3439, 13.6126, 17.1998, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1739.3927, 463.7467, 12.1666, 17.1998, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1741.0498, 468.4913, 10.7156, 16.4999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1742.7784, 473.3521, 9.1876, 16.4999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1746.4997, 483.7839, 5.9071, 16.4999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1748.2612, 488.8056, 4.3309, 16.4999, 0.0000, 161.1999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 1730.2257, 424.0480, 18.8546, 3.0000, 0.0000, 143.0997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1723.3116, 414.8402, 19.4580, 3.0000, 0.0000, 143.0997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(703, 1736.3913, 421.2236, 17.6002, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(3171, 1709.9565, 458.3992, 17.0613, -16.6998, 0.0000, -18.6998, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(3171, 1698.5178, 445.3786, 21.4962, -16.6998, 2.6998, -5.1999, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(3593, 1714.9918, 476.3193, 12.1351, -15.5999, 5.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 1707.6529, 476.5024, 12.7910, -13.1997, -11.4996, -65.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 1713.8093, 464.6759, 15.4687, -15.4996, 8.9996, 12.5999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1716.6123, 471.7832, 13.3893, -15.3000, -8.6997, -47.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1712.6634, 471.5491, 14.0267, 5.4000, 10.8999, 128.8000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1705.3829, 468.7413, 15.4924, -16.2999, 5.8997, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(1290, 1698.1844, 418.3406, 28.1825, 74.5000, -133.9998, -37.4999, -1, -1, -1, 400.0, 400.0); //lamppost2
    tempobjid = CreateDynamicObject(1290, 1721.5461, 456.6268, 18.4251, -76.1996, 36.5000, -59.0998, -1, -1, -1, 400.0, 400.0); //lamppost2
    tempobjid = CreateDynamicObject(3593, 1707.4571, 451.2489, 19.7159, -15.7999, -1.2999, -20.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1698.5250, 438.0703, 24.0489, -14.9996, 2.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1702.7507, 443.6134, 22.1767, -9.8999, -13.6997, -64.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1694.4604, 421.5244, 28.0767, -7.2999, 9.1997, 40.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 1687.8341, 424.0046, 28.0258, -13.3999, 4.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1691.5234, 422.2748, 29.0323, 0.0000, -10.5999, -110.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, 1702.7751, 454.9692, 19.3456, -16.8999, 3.5999, 7.6999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(12957, 1720.9742, 500.9689, 4.7336, -17.3999, 3.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3594, 1716.0362, 501.1690, 4.7863, -16.8999, 3.6998, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1719.3348, 504.4443, 3.5276, -18.7999, -4.3997, -32.3997, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1726.3918, 504.8392, 2.8735, -20.1998, -2.3998, -26.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1690.3619, 436.4346, 25.1138, -10.2999, -7.0998, -61.1999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(916, 1721.7246, 485.6141, 8.5753, -13.0000, 5.2999, 0.4999, -1, -1, -1, 400.0, 400.0); //FRUITCRATE2
    tempobjid = CreateDynamicObject(924, 1721.0273, 487.2799, 8.3051, -11.8999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //FRUITCRATE3
    tempobjid = CreateDynamicObject(1230, 1719.9033, 486.4963, 8.7144, 81.2994, 0.0000, 1.6999, -1, -1, -1, 400.0, 400.0); //cardboardbox
    tempobjid = CreateDynamicObject(1221, 1723.0312, 485.9757, 8.6422, -19.2000, 0.0000, -31.2999, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(2975, 1707.0533, 484.3038, 10.3050, -13.6000, 7.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo3
    tempobjid = CreateDynamicObject(2973, 1711.1142, 482.6332, 10.3128, -15.8999, 3.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2907, 1705.4658, 465.1672, 16.0179, -54.5998, 0.0000, -162.8999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 1704.9986, 464.9768, 15.8696, 17.1000, 0.0000, 152.6999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, 1705.3574, 465.3992, 16.4957, -112.1996, -96.8000, 5.9000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2036, 1704.5937, 463.7314, 16.2926, -14.9996, 3.7000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(2035, 1703.9470, 466.4136, 16.0417, 0.0000, -76.0998, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_M16
    tempobjid = CreateDynamicObject(849, 1712.9206, 469.2030, 14.1364, -12.1997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(19369, 1738.8680, 503.5487, 3.3450, 0.0000, 6.0998, -2.7999, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterialText(tempobjid, 0, "It's the end!", OBJECT_MATERIAL_SIZE_256x128, "Segoe Print", 50, 1, 0xFFDC143C, 0x00000000, 0);
    tempobjid = CreateDynamicObject(1440, 1705.3756, 454.9902, 18.9768, 6.1999, 17.8999, 94.3000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(12957, 1699.0212, 427.6921, 26.4647, 4.4998, -11.0000, -127.5998, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(849, 1693.5024, 425.3789, 27.1417, -15.7999, 6.9000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(2907, 1698.2934, 435.4507, 25.1592, 4.9998, 0.0000, 176.3000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 1698.3397, 436.1607, 24.8500, 16.2999, 0.0000, 178.6999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2905, 1699.6872, 435.6423, 24.4150, -102.0998, -83.9000, 114.5000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(3593, 1704.4989, 437.1563, 23.5958, -15.7999, -8.3000, -52.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(1217, 243.6105, 142.4660, 0.8744, 92.9000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel2
    tempobjid = CreateDynamicObject(639, 1682.5445, 423.5794, 27.3390, -12.3999, 0.0000, -17.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1685.1733, 431.7171, 25.2539, -13.3999, 0.0000, -17.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1686.7307, 436.7344, 24.0025, -13.3999, 0.0000, -17.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1688.8280, 443.4884, 22.1637, -14.7999, 0.0000, -17.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1690.6650, 448.7578, 20.6583, -14.7999, 0.0000, -19.2000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1694.6018, 459.7402, 17.4951, -14.7999, 0.0000, -18.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1696.4631, 464.9558, 15.9392, -17.0998, 0.0000, -18.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1698.1711, 469.7673, 14.5902, -14.7999, 0.0000, -19.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1701.5654, 479.4056, 11.4561, -16.9999, 0.0000, -19.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1703.4935, 484.8810, 9.6815, -16.9999, 0.0000, -19.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1707.1212, 494.4313, 6.5591, -16.9999, 0.0000, -19.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3593, 1696.0040, 411.6516, 30.0356, 0.8999, 2.2999, 84.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(16302, 186.0569, 113.5522, 3.3694, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(16302, 197.3869, 115.3619, 3.2195, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(16302, 173.4568, 103.4720, 1.6892, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(16302, 179.8368, 107.2822, 1.6892, 0.0000, 0.0000, 26.6998, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(16302, 208.6730, 109.3488, 1.6195, 0.0000, 0.0000, 26.6998, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(16302, 174.8069, 112.5622, 1.6892, 0.0000, 0.0000, -17.7999, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(16302, 178.1696, 123.0354, 1.6892, 0.0000, 0.0000, -17.7999, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(1217, 242.2104, 142.4671, 0.9344, 89.0000, -52.6999, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel2
    tempobjid = CreateDynamicObject(1217, 242.1703, 144.3280, 0.8320, 84.6996, 3.0999, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel2
    tempobjid = CreateDynamicObject(2935, 257.2911, 164.2984, -6.9060, -35.8997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_container_yel
    tempobjid = CreateDynamicObject(1218, 269.8070, 163.8164, -0.2845, 32.2000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel1
    tempobjid = CreateDynamicObject(1218, 262.0968, 163.6618, -0.0390, -43.8997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel1
    tempobjid = CreateDynamicObject(2907, 266.1115, 147.3531, 0.5633, -1.8997, 0.0000, 38.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 253.6891, 143.5160, 0.5037, 0.0000, -90.6996, -170.0997, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2906, 253.9674, 143.5646, 0.4476, 0.0000, 169.6999, -170.0997, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2907, 253.7819, 143.9694, 0.4228, 0.0000, -173.0997, 6.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 253.9308, 142.4727, 0.4821, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2907, 223.0202, 147.7998, 2.7502, -91.5998, 137.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(19362, 223.0090, 147.9591, 4.1476, 0.0000, 0.3998, 134.5000, -1, -1, -1, 400.0, 400.0); //wall010
    SetDynamicObjectMaterialText(tempobjid, 0, "S.O.S", OBJECT_MATERIAL_SIZE_512x512, "Segoe Script", 255, 0, 0xFFDC143C, 0x00000000, 1);
    tempobjid = CreateDynamicObject(2908, 223.0211, 147.7463, 3.2932, -90.5998, -135.5997, -3.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(335, 223.0756, 147.5832, 3.0081, -94.2994, -39.4999, 0.0000, -1, -1, -1, 400.0, 400.0); //knifecur
    tempobjid = CreateDynamicObject(335, 222.9597, 147.4633, 2.6861, -94.2994, -39.4999, 0.0000, -1, -1, -1, 400.0, 400.0); //knifecur
    tempobjid = CreateDynamicObject(335, 223.0294, 147.5684, 3.3201, -94.2994, -39.4999, 0.0000, -1, -1, -1, 400.0, 400.0); //knifecur
    tempobjid = CreateDynamicObject(19836, 222.8480, 147.3385, 1.4529, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BloodPool1
    tempobjid = CreateDynamicObject(19836, 223.2079, 147.4985, 1.4529, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BloodPool1
    tempobjid = CreateDynamicObject(19836, 223.2778, 147.8786, 1.4529, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BloodPool1
    tempobjid = CreateDynamicObject(2905, 223.8002, 147.8320, 1.4601, 0.0000, 0.0000, -121.9999, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(19944, 221.9393, 145.0758, 1.3846, 0.0000, 0.0000, 43.0000, -1, -1, -1, 400.0, 400.0); //BodyBag1
    tempobjid = CreateDynamicObject(19437, 222.7660, 147.7552, 2.1428, 0.0000, -0.2998, -45.5000, -1, -1, -1, 400.0, 400.0); //wall077
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFFDC143C);
    tempobjid = CreateDynamicObject(19944, 221.1493, 144.3392, 1.3846, 0.0000, 0.0000, 43.0000, -1, -1, -1, 400.0, 400.0); //BodyBag1
    tempobjid = CreateDynamicObject(19944, 220.3155, 143.5617, 1.3846, 0.0000, 0.0000, 44.7999, -1, -1, -1, 400.0, 400.0); //BodyBag1
    tempobjid = CreateDynamicObject(19944, 219.5493, 142.8007, 1.3750, 0.0000, 0.0000, 44.7999, -1, -1, -1, 400.0, 400.0); //BodyBag1
    tempobjid = CreateDynamicObject(19369, 253.8226, 143.4494, 0.3750, 179.1999, 89.7994, 9.3999, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19369, 296.5881, 155.4257, 2.0116, 0.0000, 0.0000, 71.4999, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19369, 296.5657, 155.3601, 1.5894, -0.9998, 91.1996, 72.1996, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 296.1220, 154.5016, 1.7424, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 297.1238, 154.8403, 1.7178, 0.0000, 0.0000, 76.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2905, 297.0245, 154.4427, 1.7178, 0.0000, 174.6999, 76.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(19369, 265.6640, 146.9114, 0.4715, 179.6000, 93.4998, 5.8000, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(16302, 256.9768, 113.2220, -1.7503, 15.8000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(1218, 262.0968, 147.4411, 0.5263, 78.3999, -5.5000, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel1
    tempobjid = CreateDynamicObject(1218, 259.3569, 146.0460, 0.4747, 97.8999, 66.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel1
    tempobjid = CreateDynamicObject(1218, 262.3911, 145.3945, 0.3844, 97.8999, -32.5998, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel1
    tempobjid = CreateDynamicObject(19369, 231.8665, 102.8552, 5.0784, 0.0000, 2.2000, 38.5998, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterialText(tempobjid, 0, "Welcome to", OBJECT_MATERIAL_SIZE_256x128, "Segoe Script", 50, 0, 0xFFDC143C, 0x00000000, 1);
    tempobjid = CreateDynamicObject(19369, 232.3493, 102.2042, 4.3288, 0.0000, 2.2000, 38.5998, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterialText(tempobjid, 0, "Body Wash", OBJECT_MATERIAL_SIZE_256x128, "Segoe Script", 50, 0, 0xFFDC143C, 0x00000000, 1);
    tempobjid = CreateDynamicObject(19369, 231.9794, 102.6026, 2.0903, 0.0000, 1.5000, 39.7999, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19369, 231.1652, 101.9244, 2.6080, 0.5999, 91.5998, 39.7000, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2237, 230.6564, 102.6585, 3.5027, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_SHOVEL2
    tempobjid = CreateDynamicObject(2908, 230.6575, 102.6928, 3.7021, -91.0998, -66.1996, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2907, 230.7489, 101.7861, 2.7406, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 231.2389, 100.9569, 2.7121, 0.0000, 0.0000, -42.5998, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(1486, 233.0989, 100.6240, 2.6391, 83.5000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, 232.9087, 100.8414, 2.7576, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, 232.9087, 100.7014, 2.7676, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(341, 229.3372, 102.4474, 2.7227, 91.9000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //chnsaw
    tempobjid = CreateDynamicObject(16302, 225.9568, 111.3022, -0.7404, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(19356, 248.2734, 115.7403, 4.7802, -2.0999, -3.3998, -50.1999, -1, -1, -1, 400.0, 400.0); //wall004
    SetDynamicObjectMaterialText(tempobjid, 0, "HA HA HA HA!", OBJECT_MATERIAL_SIZE_256x128, "Segoe Script", 45, 1, 0xFFDC143C, 0x00000000, 0);
    tempobjid = CreateDynamicObject(19369, 240.2530, 141.2124, 0.7530, 179.8999, 86.9998, 0.6998, -1, -1, -1, 400.0, 400.0); //wall017
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(3330, 525.5092, 464.0025, 0.9225, 0.0000, 0.0000, 32.9999, -1, -1, -1, 400.0, 400.0); //cxrf_brigleg
    tempobjid = CreateDynamicObject(2907, 239.6549, 141.1705, 0.8719, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 240.8361, 141.2082, 0.8442, 0.0000, 0.0000, 136.3000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, 239.8209, 140.3549, 0.8802, 0.0000, 0.0000, 96.1996, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2906, 240.2149, 141.5944, 0.8450, 0.0000, 0.0000, 55.1999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2905, 239.5578, 142.0137, 0.8751, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    //CreateDynamicObject(874, 217.7247, 135.1024, 1.9680, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 224.0449, 124.7322, 2.5281, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 222.5939, 120.1798, 2.5281, 0.0000, 0.0000, -39.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 243.2115, 113.0597, 2.2209, 0.0000, 0.0000, -42.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 176.0605, 133.7946, 1.6095, 0.0000, 0.0000, 77.1996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(2973, 286.6936, 155.9532, 0.5073, 21.2000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2973, 273.0173, 148.4378, 0.3526, 0.0000, -15.7999, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(3594, 521.9077, 465.2481, 12.2833, 0.0000, 0.0000, 19.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 525.6884, 467.3338, 12.1462, 0.0000, 0.0000, 59.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 526.5963, 463.5093, 12.7707, 5.5998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 530.3472, 452.9656, 12.7770, 0.0996, 0.0000, -135.9998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 534.0659, 456.8742, 12.7559, -2.5999, 0.0000, 29.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 535.0476, 450.9057, 12.9252, 0.0000, 0.0000, 37.7999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 537.5286, 452.1177, 13.5450, -9.1997, 0.0000, -116.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 533.6516, 443.6668, 13.5881, -9.3999, 0.0000, -108.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, 542.9390, 442.0079, 13.5340, 0.0000, 0.0000, -128.6999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, 541.0617, 447.4584, 13.1379, -1.2000, 0.0000, 58.7999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(849, 533.1497, 450.2932, 12.7306, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, 528.1135, 463.5140, 12.1808, 0.0000, 2.5999, 90.2994, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1450, 523.0385, 461.5986, 12.4579, 0.0000, -1.1999, 16.7999, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(19364, 539.4796, 438.2272, 12.9490, -0.1000, -92.3000, -53.2999, -1, -1, -1, 400.0, 400.0); //wall012
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 540.1124, 438.6950, 13.1981, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 540.4462, 438.6401, 13.1113, 0.0000, 0.0000, -42.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2905, 539.0258, 438.5895, 13.0711, 0.0000, 0.0000, 48.9000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2908, 539.6875, 437.7015, 13.0888, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2036, 542.9868, 437.7550, 13.1363, 0.0000, -1.6000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(1440, 539.4727, 446.0367, 13.2629, 0.0000, -2.1998, -32.0000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(19364, 535.2686, 443.8757, 12.6764, -0.1000, -92.3000, -53.2999, -1, -1, -1, 400.0, 400.0); //wall012
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 535.9694, 444.3525, 12.7742, 176.0000, 9.3000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 536.2078, 444.7651, 12.7910, 0.0000, 0.0000, -15.6000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, 536.0623, 444.9078, 12.7916, 0.0000, 0.0000, -178.3999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(1265, 532.1561, 453.5455, 12.7243, 0.0000, 0.0000, 83.9999, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(849, 533.5324, 454.4523, 12.4460, 0.0000, 0.0000, 55.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(3172, 577.9625, 387.3630, 16.2772, -0.1999, -90.0998, -56.4999, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(3171, 584.6027, 391.2951, 15.4687, -2.0000, 0.0000, 41.4999, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(3593, 549.1583, 425.8547, 14.1414, -1.7999, 0.0000, 44.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 557.7634, 425.5444, 14.2854, -2.2000, -2.4999, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 554.6527, 417.7018, 14.5354, 2.2999, 0.0000, -155.1000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 554.3021, 422.5057, 14.6077, -4.5998, 0.0000, -115.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 561.5313, 419.4201, 14.5929, 2.2999, 0.0000, -134.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 567.6314, 402.2214, 15.3247, -1.9996, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 571.8850, 403.8063, 15.4891, 2.2999, 0.0000, -134.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 568.2222, 406.9254, 15.2173, 0.0000, 0.0000, 115.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 570.6234, 391.0541, 16.1168, -10.1997, 0.0000, -66.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(849, 558.0504, 420.1932, 14.3001, 0.0000, 0.5000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, 556.8255, 416.1705, 14.3001, 0.0000, 0.5000, 113.9000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1440, 567.5178, 408.7492, 15.1134, 0.0000, 0.0000, -158.1000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(19364, 556.5053, 418.9027, 13.9967, -0.4000, -92.3000, -53.2999, -1, -1, -1, 400.0, 400.0); //wall012
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 556.8024, 418.8395, 14.1182, -6.3000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 557.1154, 418.8023, 14.1211, 0.0000, 0.0000, -34.1999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2906, 556.6035, 418.8806, 14.1195, 0.0000, -177.3999, 10.1000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(1221, 552.4060, 430.5816, 14.0003, -1.5000, -1.8997, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1221, 553.9749, 431.9226, 14.0172, -93.7994, -1.8997, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1221, 554.1491, 426.6777, 14.2255, -93.7994, 75.0998, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1230, 553.0515, 428.6617, 14.0403, -2.7999, -90.8999, 0.1000, -1, -1, -1, 400.0, 400.0); //cardboardbox
    tempobjid = CreateDynamicObject(2673, 554.1397, 428.6510, 13.7753, 0.0000, 0.0000, 55.3997, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_5
    tempobjid = CreateDynamicObject(2674, 553.7836, 430.2102, 13.6555, -1.7000, -1.1000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_2
    tempobjid = CreateDynamicObject(1440, 549.6110, 428.3272, 14.0179, 0.0000, 1.7999, 138.0000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(3005, 569.8175, 402.3547, 15.0305, -0.4999, -0.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //smash_box_stay
    tempobjid = CreateDynamicObject(3594, 576.2188, 395.3117, 15.7824, 2.2999, 0.0000, -175.1000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3171, 576.8333, 384.6921, 15.5935, 0.0000, 0.0000, 127.1996, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(901, 2776.1132, 297.0444, 5.1022, 7.0998, -1.1999, 63.3997, -1, -1, -1, 400.0, 400.0); //searock05
    tempobjid = CreateDynamicObject(3594, 588.4652, 369.1903, 16.9435, 0.0000, 0.0000, 56.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 592.3814, 362.8132, 17.1180, -3.4999, 0.0000, 41.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 597.2727, 358.1997, 17.4631, -3.4999, -1.7999, 18.1998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 601.9091, 352.7247, 17.7772, -1.3997, -0.4999, 41.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 601.3214, 356.0751, 18.1737, -8.2999, 0.0000, -92.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, 598.5490, 364.1250, 17.4006, 2.9999, 0.0000, -175.8999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(1265, 598.8167, 363.8952, 17.6651, 0.0000, -15.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, 597.5437, 363.8952, 17.5447, 0.0000, -2.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(849, 595.3933, 361.7745, 17.0188, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1440, 580.9553, 388.8703, 16.0310, 0.0000, 0.0000, 36.7999, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(1450, 585.1104, 388.0238, 16.3015, 0.0000, -2.2999, -46.7999, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(1442, 582.6602, 386.1018, 16.2996, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(18693, 582.6298, 386.1535, 14.8346, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Flame99
    tempobjid = CreateDynamicObject(1711, 581.9074, 384.1553, 15.7510, 0.0000, 0.0000, 156.7998, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(1711, 584.9057, 385.4515, 15.8311, 4.1999, 0.0000, -123.4000, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(1328, 577.2703, 383.0588, 16.2112, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1328, 576.9989, 382.3529, 15.8999, 2.5999, 90.2994, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(2671, 582.6228, 386.1921, 15.7629, -0.8999, -1.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_3
    tempobjid = CreateDynamicObject(3594, 582.2990, 376.0227, 16.6023, -2.0999, 0.0000, 39.8997, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(2908, 595.0977, 364.4403, 16.7667, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(19364, 594.7916, 364.7405, 16.6616, -0.4000, -92.3000, -53.2999, -1, -1, -1, 400.0, 400.0); //wall012
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2905, 594.4525, 365.4949, 16.7486, 0.0000, 0.0000, 94.1996, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2905, 594.5277, 364.4725, 16.7882, 0.0000, 172.7998, 132.6000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2906, 595.2561, 365.4547, 16.7651, 0.0000, 0.0000, -29.8999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2035, 593.5697, 365.8016, 16.6842, -4.0000, -1.7999, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_M16
    //CreateDynamicObject(874, 608.6525, 324.2654, 19.1863, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 601.9539, 334.9967, 18.1763, 0.0000, 0.0000, 21.7000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 632.9666, 324.2726, 19.7506, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 629.5565, 336.9926, 19.4008, 0.0000, 0.0000, 25.6998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 624.1533, 348.2200, 19.0006, 0.0000, 0.0000, 25.6998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 618.0125, 360.9789, 18.2912, -4.3000, 0.0000, 25.6998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 612.2730, 370.0910, 17.4867, -6.1999, -3.7999, 25.6998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 593.8184, 345.5675, 17.2863, 0.0000, 0.0000, 30.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 587.7282, 356.1159, 16.9363, 0.0000, 0.0000, 30.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, 614.8521, 328.9808, 19.0307, 0.0000, 0.0000, 16.2999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(639, 598.0250, 346.8073, 27.6583, 0.0000, 0.0000, 34.7000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 594.8826, 351.3453, 27.6583, 0.0000, 0.0000, 34.7000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 591.5437, 355.9902, 27.6308, 0.0000, 1.7999, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 586.9611, 362.5108, 27.6308, 0.0000, 1.7999, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 583.7296, 367.1087, 27.6308, 0.0000, 1.7999, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 578.0429, 375.2001, 27.6308, 0.0000, 1.7999, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 574.7769, 379.8471, 27.6308, 0.0000, 1.7999, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 571.5510, 384.4371, 27.6308, 0.0000, 1.7999, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 568.2158, 389.1823, 27.6308, 0.0000, 1.7999, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 611.9451, 357.2742, 27.6214, 0.0000, 2.0999, -145.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 608.7011, 361.9244, 27.6214, 0.0000, 2.0999, -145.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 605.4290, 366.5797, 27.6207, 0.0000, 2.0999, -145.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 602.3109, 371.0498, 27.6107, 0.0000, 2.0999, -145.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 596.5377, 379.3254, 27.6107, 0.0000, 2.0999, -145.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 593.3126, 383.9523, 27.5506, 0.0000, 2.0999, -145.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 587.0249, 392.9656, 27.5506, 0.0000, 2.0999, -145.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 583.7977, 397.5914, 27.5506, 0.0000, 2.0999, -145.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 565.5048, 399.3088, 18.9997, 0.0000, 1.2999, 125.7994, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 573.5598, 405.0816, 19.0004, 0.0000, 1.2999, 125.7994, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 560.5291, 399.3482, 22.3064, 27.3999, 0.0000, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 557.6395, 403.4598, 24.9111, 27.3999, 0.0000, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 554.4415, 407.8536, 27.7276, 27.3999, 0.0000, 35.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 574.6909, 409.4729, 22.3952, -26.8999, 0.0000, -144.6997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 571.6477, 413.6671, 25.0237, -26.8999, 0.0000, -144.6997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 568.7352, 417.7456, 27.5664, -26.8999, 0.0000, -144.6997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 602.3093, 346.9577, 27.4507, 0.0000, 0.0000, 124.6996, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 610.6873, 352.7590, 27.5109, 0.0000, 0.0000, 124.6996, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3594, 614.0045, 333.6015, 19.0853, -7.7999, 0.0000, 11.6000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3171, 624.7774, 324.8432, 19.0160, 0.0000, -67.8999, -170.8000, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(16302, 628.2382, 322.7882, 15.2405, 0.0000, -13.6997, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 12825, "ce_ground08", "cw2_mountdirt", 0x00000000);
    tempobjid = CreateDynamicObject(16302, 628.0244, 327.7087, 15.1885, 0.0000, -13.6997, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 12825, "ce_ground08", "cw2_mountdirt", 0x00000000);
    //CreateDynamicObject(874, 654.9589, 322.7709, 19.7052, 0.0000, 0.0000, 93.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 666.1220, 324.0444, 19.7052, 0.0000, 0.0000, 93.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 675.6040, 324.6242, 19.7052, 0.0000, 0.0000, 93.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 676.9912, 301.9366, 19.7052, 0.0000, 0.0000, 93.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 664.7822, 300.3987, 19.7052, 0.0000, 0.0000, 93.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 717.6118, 330.2265, 19.8826, 0.0000, 0.0000, 94.1996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 705.4824, 328.5433, 19.8826, 0.0000, 0.0000, 98.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 729.5687, 332.3153, 19.8826, 0.0000, 0.0000, 98.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 702.0219, 319.5064, 19.4190, -0.2000, 0.0000, -81.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 694.1621, 318.8301, 19.3232, 0.0000, 0.0000, 104.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 686.9185, 319.0035, 19.3514, 0.0000, 0.0000, -113.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 683.5695, 322.8998, 19.7691, 5.4998, 0.0000, -157.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 683.4445, 317.5353, 19.7742, 8.6000, 0.0000, -48.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(16302, 683.1099, 325.1239, 15.0858, 0.0000, 0.0000, 60.2000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    //CreateDynamicObject(874, 761.9876, 310.9931, 19.9745, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 817.2462, 325.4945, 19.8187, 0.0000, 0.0000, 94.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 805.4672, 320.6445, 19.8187, 0.0000, 0.0000, 94.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 794.7700, 319.1820, 19.8187, 0.0000, 0.0000, 94.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 819.3624, 348.7120, 19.7558, 0.0000, 0.0000, -92.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 808.8980, 346.6170, 19.7558, 0.0000, 0.0000, -92.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, 768.3659, 350.6881, 19.4759, 0.0000, 0.0000, 169.1999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, 747.6082, 344.0086, 19.8115, 0.0000, 0.0000, 49.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 749.7008, 339.3030, 20.0641, -5.3000, 0.0000, -168.6999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 777.3090, 362.0722, 19.3220, 0.0000, -14.6997, 98.6996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, 818.2155, 363.5108, 19.1557, 0.0000, 0.0000, -176.9998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 813.4802, 373.9974, 19.1557, 0.0000, 0.0000, -153.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 808.5654, 383.7265, 18.8257, 0.0000, 0.0000, -153.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 796.2166, 390.5050, 19.6089, -3.3998, 0.0000, -114.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19370, 799.2241, 356.5325, 17.9319, 0.0000, 0.0000, -2.5000, -1, -1, -1, 400.0, 400.0); //wall018
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19370, 799.1516, 356.7156, 18.3320, 0.0000, 90.0000, -2.5000, -1, -1, -1, 400.0, 400.0); //wall018
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 798.5272, 356.3908, 18.4036, 0.0000, 0.0000, 39.8997, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 798.7406, 356.6549, 18.4160, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(3594, 809.2263, 363.7059, 18.7206, 0.0000, 0.0000, -82.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(19370, 808.7827, 358.3569, 18.2819, 0.0000, 90.0000, -2.5000, -1, -1, -1, 400.0, 400.0); //wall018
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19370, 808.7816, 357.7872, 18.2819, 0.0000, 0.0000, 87.0998, -1, -1, -1, 400.0, 400.0); //wall018
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(1711, 807.5518, 358.6697, 18.3519, 0.0000, 0.0000, 128.2998, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(19370, 806.9738, 357.8741, 18.7420, 0.0000, 0.0000, 87.5000, -1, -1, -1, 400.0, 400.0); //wall018
    SetDynamicObjectMaterialText(tempobjid, 0, "Get out of here!", OBJECT_MATERIAL_SIZE_256x128, "Segoe Print", 30, 0, 0xFFDC143C, 0x00000000, 0);
    tempobjid = CreateDynamicObject(1711, 810.5305, 358.4696, 18.3519, 0.0000, 0.0000, -151.3999, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(1442, 808.8792, 359.8280, 18.8010, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(18693, 808.8118, 359.8161, 17.2819, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Flame99
    tempobjid = CreateDynamicObject(1486, 806.5463, 359.9779, 18.4867, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, 806.5463, 360.1080, 18.4867, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, 806.7274, 360.1502, 18.3864, 16.6998, 89.4999, 44.5998, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1265, 801.9937, 358.6770, 18.7045, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, 801.2636, 358.6770, 18.7045, 0.0000, -21.5998, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1328, 799.6030, 358.9211, 18.5303, 179.6999, -89.3999, -57.0998, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(3594, 795.0642, 354.0909, 18.9580, -1.2000, 0.0000, 49.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(760, 765.5000, 360.3127, 19.3927, 18.3999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_bush_small_1
    tempobjid = CreateDynamicObject(759, 774.1082, 366.1036, 19.8038, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_bush_large_1
    tempobjid = CreateDynamicObject(800, 741.0009, 347.7445, 19.6392, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    //CreateDynamicObject(874, 760.7677, 360.0335, 20.5564, 0.0000, 11.6997, -71.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 768.6176, 366.3692, 21.0055, 0.0000, 11.6997, -71.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3284, 761.9708, 373.8721, 22.2262, 0.0000, 12.8000, 0.0000, -1, -1, -1, 400.0, 400.0); //conhoos5
    //CreateDynamicObject(874, 768.1314, 373.9941, 22.0011, -5.4000, 2.0999, -71.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, 742.8778, 378.3781, 22.6823, 0.0000, 0.0000, 143.0997, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(1440, 807.4677, 370.1600, 18.8901, 0.0000, 0.0000, -92.1996, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(2036, 805.8745, 363.6130, 18.8938, 0.0000, -71.5998, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    //CreateDynamicObject(874, 735.4412, 380.6268, 22.7017, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 744.8225, 387.1708, 22.7017, 0.0000, 0.0000, -86.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1217, 807.8272, 374.2261, 18.5412, 0.0000, 103.1996, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel2
    tempobjid = CreateDynamicObject(1217, 808.2208, 375.3103, 18.5244, 17.6000, 91.9000, 41.4000, -1, -1, -1, 400.0, 400.0); //barrel2
    tempobjid = CreateDynamicObject(1328, 786.9000, 376.6267, 20.3577, 0.0000, -84.2994, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1328, 785.7498, 376.8742, 20.7138, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1712, 782.1951, 378.1379, 20.1979, 0.0000, 0.0000, 158.4998, -1, -1, -1, 400.0, 400.0); //kb_couch05
    tempobjid = CreateDynamicObject(1442, 784.8894, 379.4526, 20.7084, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(1265, 789.6162, 375.0132, 20.6075, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, 788.9337, 375.0906, 20.6075, 0.0000, 0.0000, 151.5997, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(849, 791.0712, 376.3171, 20.3491, 5.1999, 2.8998, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(2671, 786.7717, 378.8858, 20.2129, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_3
    tempobjid = CreateDynamicObject(3593, 754.5443, 378.9226, 22.6039, -1.6000, 0.0000, -38.6999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(1447, 813.3131, 354.2867, 19.4610, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_MESH_4
    tempobjid = CreateDynamicObject(1447, 816.0626, 356.9465, 19.4610, 0.0000, 0.0000, 90.0000, -1, -1, -1, 400.0, 400.0); //DYN_MESH_4
    tempobjid = CreateDynamicObject(12957, 813.4467, 356.8965, 18.9190, 0.0000, 0.0000, 173.3999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3171, 792.3842, 391.3392, 20.9675, -7.1999, -95.0000, -113.4000, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(3594, 779.0274, 351.6900, 19.1802, 0.0000, 0.0000, 179.2998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(1711, 789.7971, 354.4124, 18.4482, 0.0000, 0.0000, -126.6996, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(1440, 787.2774, 353.8315, 18.9321, 0.0000, 0.0000, -171.5997, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(19636, 789.6784, 355.9291, 18.5310, 0.0000, 0.0000, -24.1000, -1, -1, -1, 400.0, 400.0); //RedApplesCrate1
    tempobjid = CreateDynamicObject(1343, 773.2816, 343.2008, 19.1058, 83.5998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_Dumpster3
    tempobjid = CreateDynamicObject(2860, 773.1176, 341.8536, 18.8537, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //gb_kitchtakeway05
    //CreateDynamicObject(874, 787.6934, 343.2424, 19.4256, 0.0000, 0.0000, 86.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 742.9196, 338.8013, 19.8826, 0.0000, 0.0000, -10.6000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 730.7395, 297.8699, 19.7229, 0.0000, 0.0000, 12.1000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 734.9672, 298.9512, 19.5743, 0.0000, 0.0000, 16.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 760.0844, 294.3395, 19.9682, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 762.6732, 291.8381, 19.9094, 33.0000, 0.0000, -52.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(16304, 761.6206, 289.6014, 18.3910, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(639, 747.9622, 308.0581, 19.9843, 0.0000, 0.0000, -169.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 749.1298, 301.6029, 19.9843, 0.0000, 0.0000, -169.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3242, 744.3181, 275.0321, 25.9932, 0.0000, -11.5999, 108.1996, -1, -1, -1, 400.0, 400.0); //conhoos1
    tempobjid = CreateDynamicObject(10984, 745.4240, 271.0841, 25.7844, 0.0000, 0.0000, -179.9998, -1, -1, -1, 400.0, 400.0); //rubbled01_SFS
    //CreateDynamicObject(874, 782.2175, 310.9931, 20.2644, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 782.2175, 301.2731, 20.8945, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 782.2175, 282.3930, 22.2345, -5.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 782.2175, 271.4053, 23.6576, -5.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 766.5023, 271.4602, 24.2812, -5.0000, 15.5999, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 766.4780, 261.4807, 25.0673, -5.0000, 15.5999, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(703, 784.5125, 292.6470, 20.4957, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(12957, 772.3850, 314.6516, 19.9594, 0.0000, 0.0000, -113.1996, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    //CreateDynamicObject(874, 768.6837, 252.5708, 25.2287, -5.0000, 15.5999, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 756.6962, 245.9835, 27.0044, -4.9998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 748.8563, 245.9835, 27.0044, -4.9998, -5.5998, -53.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 740.0518, 250.7928, 26.2388, -4.9998, 1.7999, -80.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 751.6326, 276.5191, 26.7031, -1.0000, -3.2999, 26.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 755.4025, 277.6437, 26.6434, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, 691.2985, 295.0440, 19.7366, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 691.2985, 282.3041, 19.7366, 0.0000, 0.0000, -12.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 696.3245, 267.2297, 20.1166, -5.0000, 0.0000, 1.3997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 710.8344, 252.2875, 24.0778, -8.6997, 7.1999, 50.3997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, 741.6781, 253.8374, 26.7164, 0.0000, 0.0000, -166.6999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(19366, 719.3167, 270.1404, 20.7700, 0.0000, 0.0000, 87.0998, -1, -1, -1, 400.0, 400.0); //wall014
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19366, 719.3112, 270.0306, 21.2900, 0.0000, 90.0000, 87.0998, -1, -1, -1, 400.0, 400.0); //wall014
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2677, 738.8886, 254.3715, 26.3915, 1.3997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_7
    tempobjid = CreateDynamicObject(2907, 718.9663, 269.2712, 21.4197, 0.0000, 0.0000, 28.5000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 718.9077, 268.8410, 21.3843, 0.0000, 0.0000, 179.6000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(1327, 744.0617, 250.7245, 26.8533, 0.0000, 20.8999, 29.5000, -1, -1, -1, 400.0, 400.0); //junk_tyre
    tempobjid = CreateDynamicObject(2908, 719.2852, 268.8309, 21.4202, 0.0000, -178.5000, 27.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(1265, 721.6997, 269.6054, 21.6438, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1440, 745.8264, 257.0985, 26.5708, 0.0000, 0.0000, -167.2998, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(1265, 720.6243, 269.6054, 21.4750, 0.0000, -35.5998, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(19366, 724.5028, 269.9273, 22.6399, 0.0000, 0.0000, 87.4999, -1, -1, -1, 400.0, 400.0); //wall014
    SetDynamicObjectMaterialText(tempobjid, 0, "We eat humans", OBJECT_MATERIAL_SIZE_256x128, "Segoe Script", 35, 0, 0xFFDC143C, 0x00000000, 0);
    tempobjid = CreateDynamicObject(2670, 744.0620, 256.8710, 26.1658, 0.0000, 0.0000, 81.7994, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_1
    tempobjid = CreateDynamicObject(2237, 726.0227, 268.5819, 22.1424, 0.0000, 0.0000, -23.8999, -1, -1, -1, 400.0, 400.0); //CJ_SHOVEL2
    tempobjid = CreateDynamicObject(2908, 726.0194, 268.6191, 22.3633, -90.4999, -36.1999, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(1428, 751.6859, 260.5296, 27.5664, 0.0000, 0.0000, -165.6999, -1, -1, -1, 400.0, 400.0); //DYN_LADDER
    tempobjid = CreateDynamicObject(19836, 726.0482, 268.4512, 21.3770, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BloodPool1
    tempobjid = CreateDynamicObject(19836, 725.7979, 268.8912, 21.3770, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BloodPool1
    tempobjid = CreateDynamicObject(1440, 715.2307, 271.7431, 21.8281, 0.0000, 0.0000, -90.0998, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(1431, 745.4547, 257.2456, 29.5401, -14.8999, 0.0000, 15.6000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE
    tempobjid = CreateDynamicObject(1450, 716.8649, 269.6275, 21.9342, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(2912, 727.3037, 271.0989, 21.3316, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //temp_crate1
    tempobjid = CreateDynamicObject(2912, 727.3037, 271.9486, 21.3316, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //temp_crate1
    tempobjid = CreateDynamicObject(2912, 727.3037, 271.4388, 22.0417, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //temp_crate1
    tempobjid = CreateDynamicObject(349, 745.7622, 256.6860, 29.4090, -37.0998, -82.6996, 0.0000, -1, -1, -1, 400.0, 400.0); //chromegun
    tempobjid = CreateDynamicObject(1810, 745.5501, 254.3582, 29.7075, 0.0000, 0.0000, -167.3000, -1, -1, -1, 400.0, 400.0); //CJ_FOLDCHAIR
    //CreateDynamicObject(874, -190.8737, 222.2001, 12.1218, 0.0000, 0.0000, -143.9998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 731.9099, 268.5021, 23.2915, -3.0999, -35.9000, 3.5999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(2673, 745.6798, 256.4566, 29.3064, -10.5000, -2.4999, -10.8999, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_5
    tempobjid = CreateDynamicObject(800, 730.0123, 276.4093, 20.3640, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(12957, 711.4702, 292.6943, 19.7607, 0.0000, 0.0000, -112.6996, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(19632, 746.6400, 254.9282, 29.6539, -20.6998, -3.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //FireWood1
    tempobjid = CreateDynamicObject(1264, 752.9854, 258.6022, 26.4605, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag1
    tempobjid = CreateDynamicObject(3270, 673.2899, 281.1773, 16.7189, 0.0000, 0.0000, -49.0998, -1, -1, -1, 400.0, 400.0); //bonyrd_block2_
    tempobjid = CreateDynamicObject(16304, 682.8300, 294.6310, 18.6921, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(16304, 661.7598, 281.1210, 18.6921, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(1362, 746.8062, 303.8302, 19.8208, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_FIREBIN_(L0)
    tempobjid = CreateDynamicObject(18693, 746.8037, 303.8435, 18.0900, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Flame99
    tempobjid = CreateDynamicObject(1264, 747.0698, 303.0361, 19.6588, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag1
    tempobjid = CreateDynamicObject(800, 727.7877, 292.1484, 18.5827, 0.0000, 0.0000, 64.8999, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(2672, 747.5745, 304.4970, 19.5142, 0.0000, 0.0000, 38.4999, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_4
    tempobjid = CreateDynamicObject(1712, 698.5264, 290.2377, 19.3700, 0.0000, 0.0000, 13.7999, -1, -1, -1, 400.0, 400.0); //kb_couch05
    tempobjid = CreateDynamicObject(1756, 744.7905, 297.1766, 19.2038, 0.0000, 0.0000, 9.8999, -1, -1, -1, 400.0, 400.0); //LOW_COUCH_4
    tempobjid = CreateDynamicObject(1442, 702.9702, 291.0837, 19.8770, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(18693, 702.9965, 291.1250, 18.5739, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Flame99
    tempobjid = CreateDynamicObject(1711, 743.8391, 297.2586, 19.5573, -81.5000, 0.0000, 162.8000, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(2840, 700.5985, 290.3999, 19.4421, 0.0000, 0.0000, 60.2999, -1, -1, -1, 400.0, 400.0); //GB_takeaway05
    tempobjid = CreateDynamicObject(1450, 701.5670, 291.3521, 19.9358, 0.0000, 0.0000, 3.7000, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(1328, 707.5919, 291.9729, 19.7665, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(2676, 744.2545, 296.2648, 19.3600, 0.0000, 0.0000, 43.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_8
    tempobjid = CreateDynamicObject(1328, 708.2395, 291.0227, 19.4771, 0.0000, 86.4999, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(639, 719.4448, 276.0570, 22.3645, 0.0000, 0.0000, -92.6996, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 731.3909, 306.7088, 19.1243, 0.0000, 0.0000, -92.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1450, 742.1369, 296.6990, 19.8164, 0.0000, 0.0000, 15.6000, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(1486, 735.8715, 295.5353, 19.3596, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, 735.9816, 295.5653, 19.3596, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, 735.9816, 295.4052, 19.2395, 0.0000, -90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(3276, 760.2141, 321.0114, 18.9752, 90.5000, 0.0000, 171.9998, -1, -1, -1, 400.0, 400.0); //cxreffencesld
    tempobjid = CreateDynamicObject(3594, 788.1519, 326.5148, 19.3313, 0.0000, 0.0000, 108.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 781.1325, 324.4288, 19.2329, 0.0000, 0.0000, 116.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(1238, 776.8875, 325.8117, 19.1877, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //trafficcone
    tempobjid = CreateDynamicObject(1238, 779.2979, 327.2514, 19.1476, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //trafficcone
    tempobjid = CreateDynamicObject(1238, 782.5681, 328.3515, 19.1476, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //trafficcone
    tempobjid = CreateDynamicObject(1238, 786.1682, 328.6116, 19.1476, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //trafficcone
    tempobjid = CreateDynamicObject(1238, 790.6583, 329.1116, 19.1476, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //trafficcone
    tempobjid = CreateDynamicObject(1282, 774.7943, 324.3645, 19.4880, 0.0000, 0.0000, -11.0999, -1, -1, -1, 400.0, 400.0); //Barrierm
    tempobjid = CreateDynamicObject(1424, 792.6469, 328.0513, 19.4099, 0.0000, 0.0000, -72.6996, -1, -1, -1, 400.0, 400.0); //DYN_ROADBARRIER_2
    tempobjid = CreateDynamicObject(3593, 823.7540, 342.6513, 19.2530, 0.0000, 0.0000, 107.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 832.6234, 343.6187, 19.3390, 0.0000, 0.0000, -84.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 841.2188, 345.4689, 19.2929, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 845.0551, 345.4779, 19.6781, -8.5000, 0.0000, -69.9000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3171, 842.4487, 353.2094, 19.7982, 0.0000, -84.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(16305, 838.8001, 355.9183, 20.8103, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile06
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(19366, 844.3120, 343.0119, 18.8027, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall014
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 844.3214, 343.2015, 18.9554, 0.0000, 0.0000, -59.4999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2935, -945.1735, -277.1817, 36.9421, 0.0000, 0.0000, 78.5998, -1, -1, -1, 400.0, 400.0); //kmb_container_yel
    tempobjid = CreateDynamicObject(2906, 844.4113, 342.8174, 18.9169, 0.0000, 0.0000, -108.9999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2906, 844.0150, 343.4660, 18.9498, 0.0000, 178.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2036, 845.0175, 342.8009, 18.9087, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(16305, -192.5735, 247.6508, 12.4448, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile06
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(849, 842.9904, 346.2962, 19.1730, 0.0000, 0.4999, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(16305, -202.6015, 250.0072, 12.4041, 0.0000, 0.0000, 45.0998, -1, -1, -1, 400.0, 400.0); //des_gravelpile06
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(16305, -195.8533, 248.6188, 12.5038, 0.0000, 0.0000, 45.0998, -1, -1, -1, 400.0, 400.0); //des_gravelpile06
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    //CreateDynamicObject(874, 857.5618, 335.1596, 20.2355, 0.0000, 0.0000, 86.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3566, -185.2035, 302.9024, 4.4643, -10.6997, 2.5999, -0.3000, -1, -1, -1, 400.0, 400.0); //lasntrk1
    //CreateDynamicObject(874, 859.1126, 361.2637, 20.2355, 0.0000, 0.0000, 105.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 630.0750, 311.9252, 19.3554, 0.0000, 0.0000, -62.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 633.7564, 309.1036, 19.3554, 0.0000, 0.0000, -101.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 629.1311, 307.6007, 19.2329, 0.0000, 0.0000, 67.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(13591, -188.3724, 290.8503, 4.6090, -10.3000, 1.2000, 0.0000, -1, -1, -1, 400.0, 400.0); //kickcar28
    tempobjid = CreateDynamicObject(3594, 629.6973, 309.5686, 20.1809, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, 626.0811, 310.3052, 19.0662, 0.0000, 0.0000, -138.1999, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    //CreateDynamicObject(874, -187.8589, 290.3803, 4.6645, -6.0998, 0.0000, -32.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1440, 633.7280, 311.1069, 19.3742, 0.0000, 0.0000, 10.8000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(1450, 633.8864, 307.3330, 19.4591, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(826, -190.2843, 295.2994, 4.7157, -3.1998, -5.3997, -50.3997, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass10
    tempobjid = CreateDynamicObject(849, 631.2960, 304.9667, 19.1263, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(3172, -192.0424, 276.1708, 6.8406, -7.8000, -4.8997, -51.7999, -1, -1, -1, 400.0, 400.0); //trailer6_01
    //CreateDynamicObject(874, 622.7188, 296.8681, 19.8826, 0.0000, 0.0000, -86.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 610.5227, 292.3918, 19.8826, 0.0000, 0.0000, -78.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 598.8637, 313.3251, 19.1895, 2.1998, 0.0000, -80.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 585.5385, 306.4721, 18.6406, 3.0999, 0.0000, -71.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3568, 596.1430, 285.1726, 17.9951, -7.3997, 0.0000, -54.4999, -1, -1, -1, 400.0, 400.0); //lasntrk2
    tempobjid = CreateDynamicObject(3569, 548.6707, 261.5042, 17.0601, 1.5999, -1.0999, 0.0000, -1, -1, -1, 400.0, 400.0); //lasntrk3
    tempobjid = CreateDynamicObject(12957, -190.3562, 270.1329, 8.4833, 8.8999, -1.3997, 179.5997, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(16304, 591.7094, 280.9472, 17.1110, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    //CreateDynamicObject(874, -191.4808, 269.9566, 9.0183, -5.0000, -1.9996, -28.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(16304, 603.8295, 290.8872, 16.8810, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(13591, -196.5287, 237.5345, 11.3674, 0.0000, 0.0000, 38.0998, -1, -1, -1, 400.0, 400.0); //kickcar28
    //CreateDynamicObject(874, 568.7340, 264.4566, 16.8374, 0.0000, 0.0000, -54.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 574.9083, 272.1946, 17.0074, 0.0000, 0.0000, 120.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, -206.1849, 240.0534, 11.6962, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    //CreateDynamicObject(874, 563.5615, 291.6122, 17.2574, 0.0000, 0.0000, 120.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, -205.9046, 233.4230, 11.6469, 0.0000, 0.0000, 144.1999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(2973, 544.3098, 255.5868, 14.4736, 0.5999, 0.0000, -24.8999, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2973, 541.7921, 262.4660, 14.5283, 2.4999, 0.0000, -82.5000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(3594, -210.6717, 243.4423, 11.6169, 0.0000, 0.0000, -136.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, 512.1055, 232.9803, 12.9974, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(19636, 548.6848, 251.9411, 14.9890, 4.6999, 0.0000, -41.0998, -1, -1, -1, 400.0, 400.0); //RedApplesCrate1
    tempobjid = CreateDynamicObject(19637, 546.7404, 251.0243, 14.8528, 3.9999, 0.0000, 36.0998, -1, -1, -1, 400.0, 400.0); //GreenApplesCrate1
    tempobjid = CreateDynamicObject(19636, 548.7177, 249.9989, 14.8830, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //RedApplesCrate1
    tempobjid = CreateDynamicObject(1221, 550.8972, 249.5843, 15.4193, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1221, 550.8972, 252.0442, 15.4193, 0.0000, 0.0000, 55.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(3005, 549.6798, 250.9609, 15.1028, 3.9000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //smash_box_stay
    tempobjid = CreateDynamicObject(2059, 547.6375, 250.4013, 14.9503, 3.2000, -2.2000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_GUNSTUFF1
    //CreateDynamicObject(874, 525.6176, 229.4156, 14.1357, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 532.9052, 264.3363, 15.0670, 0.0000, 0.0000, -63.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 542.3958, 245.3009, 15.0670, 0.0000, 0.0000, -55.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3264, -204.6051, 200.5695, 9.8823, 0.0000, 0.0000, -112.5000, -1, -1, -1, 400.0, 400.0); //privatesign3
    //CreateDynamicObject(874, 504.4064, 210.0520, 13.9131, -6.1999, -9.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 498.8569, 236.6414, 12.8612, 0.0000, 0.0000, -63.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3276, -198.3901, 199.4452, 10.9284, 0.0000, 0.0000, 163.1000, -1, -1, -1, 400.0, 400.0); //cxreffencesld
    tempobjid = CreateDynamicObject(3276, -196.3497, 206.1604, 10.8288, 85.1996, 0.0000, 163.1000, -1, -1, -1, 400.0, 400.0); //cxreffencesld
    tempobjid = CreateDynamicObject(3594, 518.4473, 224.5879, 13.6148, 0.0000, 0.0000, -160.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 515.2692, 230.7534, 13.5549, 0.0000, 2.7999, -115.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3276, -186.5767, 196.2523, 11.0184, 0.0000, 0.0000, -12.3999, -1, -1, -1, 400.0, 400.0); //cxreffencesld
    tempobjid = CreateDynamicObject(3593, 510.5603, 229.6844, 13.0059, 2.4000, -1.8997, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(19366, 514.0145, 227.2841, 12.7080, 0.4000, -94.9999, 1.8997, -1, -1, -1, 400.0, 400.0); //wall014
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(3276, -178.8063, 197.9116, 10.3245, 94.5998, -123.3000, 17.5000, -1, -1, -1, 400.0, 400.0); //cxreffencesld
    tempobjid = CreateDynamicObject(12957, -183.1080, 200.9154, 11.2510, 0.0000, -4.1999, 92.5000, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(2907, 513.8209, 227.2236, 12.8135, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 514.3270, 227.9788, 12.8332, 0.0000, 0.0000, -27.1998, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    //CreateDynamicObject(874, -187.8088, 202.0252, 11.4516, 0.0000, -4.4998, 68.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(849, 518.4143, 228.7729, 13.5312, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(2935, -956.6038, -274.9797, 36.9920, 0.0000, 0.0000, 78.5998, -1, -1, -1, 400.0, 400.0); //kmb_container_yel
    tempobjid = CreateDynamicObject(791, -241.9075, 218.9907, 6.0541, 0.0000, 0.0000, 6.9998, -1, -1, -1, 400.0, 400.0); //vbg_fir_copse
    tempobjid = CreateDynamicObject(721, -238.0803, 222.2288, 4.9169, -80.6996, 0.0000, -39.9000, -1, -1, -1, 400.0, 400.0); //veg_largefurs02
    tempobjid = CreateDynamicObject(16305, -231.1622, 230.3146, 13.3219, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile06
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    //CreateDynamicObject(874, -218.4049, 232.4635, 11.7643, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(2934, -949.6209, -276.2380, 36.9420, 0.0000, 0.0000, 81.0998, -1, -1, -1, 400.0, 400.0); //kmb_container_red
    tempobjid = CreateDynamicObject(2932, -963.5869, -273.5332, 37.0325, 0.0000, 0.0000, 78.1996, -1, -1, -1, 400.0, 400.0); //kmb_container_blue
    tempobjid = CreateDynamicObject(2934, -952.2576, -275.7229, 39.8502, 0.0000, 0.0000, 78.3000, -1, -1, -1, 400.0, 400.0); //kmb_container_red
    tempobjid = CreateDynamicObject(2932, -945.2824, -277.1712, 39.8385, 0.0000, 0.0000, 78.8999, -1, -1, -1, 400.0, 400.0); //kmb_container_blue
    tempobjid = CreateDynamicObject(2932, -959.2426, -274.3994, 39.8725, 0.0000, 0.0000, 79.3999, -1, -1, -1, 400.0, 400.0); //kmb_container_blue
    tempobjid = CreateDynamicObject(2935, -963.6715, -273.5549, 39.8819, 0.0000, 0.0000, 78.5998, -1, -1, -1, 400.0, 400.0); //kmb_container_yel
    tempobjid = CreateDynamicObject(3594, -950.8333, -269.0910, 36.1300, 0.1000, 0.0000, -179.8000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(2935, -945.3416, -276.9046, 42.7321, 0.0000, 0.0000, 78.5998, -1, -1, -1, 400.0, 400.0); //kmb_container_yel
    tempobjid = CreateDynamicObject(2932, -952.3693, -275.6889, 42.7285, 0.0000, 0.0000, 78.8999, -1, -1, -1, 400.0, 400.0); //kmb_container_blue
    tempobjid = CreateDynamicObject(2934, -959.2694, -274.2705, 42.7205, 0.0000, 0.0000, 78.3000, -1, -1, -1, 400.0, 400.0); //kmb_container_red
    tempobjid = CreateDynamicObject(2934, -963.6185, -273.5198, 42.7318, 0.0000, 0.0000, 79.1996, -1, -1, -1, 400.0, 400.0); //kmb_container_red
    tempobjid = CreateDynamicObject(3593, -953.9207, -266.2044, 36.2596, -10.1997, 0.0000, 94.8000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(12957, -944.8551, -268.2904, 36.7248, 0.0000, 0.0000, -32.2999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3171, -960.5631, -265.9872, 37.0587, 0.0000, -88.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(849, -950.6342, -265.2567, 36.0382, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(19366, -953.5750, -263.1784, 35.6090, 2.4999, -90.3999, -9.0000, -1, -1, -1, 400.0, 400.0); //wall014
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -953.2141, -263.2531, 35.7509, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, -954.3012, -263.5136, 35.6996, 0.0000, 0.0000, -38.8997, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(1440, -945.8568, -266.5736, 36.4710, 0.0000, 0.0000, -119.4000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(703, 2819.2045, 190.6734, 12.5008, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(901, 2191.1748, -696.0451, 46.6128, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //searock05
    SetDynamicObjectMaterial(tempobjid, 0, 12871, "ce_ground01", "cs_rockdetail2", 0x00000000);
    tempobjid = CreateDynamicObject(758, 2185.4870, -688.6804, 46.3861, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_scrub_rock6
    tempobjid = CreateDynamicObject(745, 2181.0878, -694.0477, 46.1715, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_scrub_rock5
    tempobjid = CreateDynamicObject(703, 2787.5898, 270.4244, 6.4278, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(806, 2781.8127, 293.3381, 8.2559, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass
    tempobjid = CreateDynamicObject(806, 2781.8127, 300.7384, 8.2559, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass
    //CreateDynamicObject(874, 2780.2382, 284.2297, 7.3979, 0.0000, 9.8999, 25.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2785.4235, 273.3085, 7.3979, 0.0000, 9.8999, 25.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2789.7553, 264.1849, 7.3979, 0.0000, 9.8999, 25.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2785.2607, 245.6925, 11.3374, -2.2999, 13.7999, -7.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2789.7558, 236.1015, 11.4652, -3.2000, 13.7999, -7.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2811.7089, 197.3529, 13.8198, 0.0000, -2.7999, 32.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2804.7800, 208.2568, 12.1618, 0.0000, -2.7999, 32.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2796.4389, 221.2624, 11.4525, 0.0000, -7.3997, 24.6998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2824.6418, 165.8650, 16.8435, -1.9996, 0.0000, -65.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2805.8369, 158.5063, 17.4780, -5.6999, 4.9998, -5.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(691, 2833.3203, 137.3695, 16.8948, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4_big
    tempobjid = CreateDynamicObject(3569, 2854.2004, -150.4488, 21.8574, 1.5999, -0.4000, 26.8999, -1, -1, -1, 400.0, 400.0); //lasntrk3
    tempobjid = CreateDynamicObject(2973, 2855.8535, -160.9588, 18.9197, 7.4000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2973, 2861.9777, -161.0789, 19.9020, 97.1996, 0.0000, 11.3999, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(1230, 2857.5842, -161.6564, 19.2458, 0.0000, 0.0000, 50.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox
    tempobjid = CreateDynamicObject(1221, 2860.4929, -162.5621, 19.2373, 5.1999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1221, 2860.4028, -161.4467, 19.3388, 5.1999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1221, 2860.4028, -162.1755, 20.1762, 5.1999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1220, 2860.0500, -159.1011, 19.5310, 96.2994, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox2
    tempobjid = CreateDynamicObject(2674, 2858.6665, -161.2227, 18.9892, 6.1999, 0.7997, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_2
    tempobjid = CreateDynamicObject(19432, 2855.8801, -162.1105, 18.5683, 0.0000, -7.2999, 89.8999, -1, -1, -1, 400.0, 400.0); //wall072
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 2858.0043, -169.4152, 17.9780, 6.0000, 85.9999, -1.5000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19432, 2855.8642, -162.1147, 18.7320, -1.0000, 83.0000, 91.0998, -1, -1, -1, 400.0, 400.0); //wall072
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 2856.1018, -162.9196, 18.7301, 3.3998, 0.0000, -39.9000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(639, 2779.8833, -463.4010, 15.4849, 0.0000, 0.0000, 66.3000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(2907, 2857.7067, -169.8280, 17.9752, 0.8999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 2858.1704, -170.0263, 18.0079, 0.0000, 0.0000, 32.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2905, 2857.7707, -169.0820, 18.0499, 6.4998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2036, 2856.6491, -169.5393, 17.9654, -3.2999, 9.3999, -144.1000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(3593, 2843.8422, -181.1564, 16.4400, -5.8997, 0.0000, 137.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 2838.8486, -187.3139, 15.9132, 4.5998, -2.6998, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, 2842.4667, -184.7579, 15.8598, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(3594, 2830.3439, -205.0841, 14.5558, -3.9000, 0.0000, 142.1999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 2826.1057, -210.5471, 14.0846, -3.9000, 0.0000, 168.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3171, 2822.6772, -217.1056, 13.1941, -2.5000, 0.0000, 139.3000, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(1450, 2827.8522, -205.2698, 14.5901, 0.0000, 0.0000, -132.2998, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(1440, 2821.9428, -214.7265, 13.7754, 0.0000, 2.3998, -132.8000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    //CreateDynamicObject(874, 2842.1494, -204.8654, 14.7025, 2.7999, 4.8997, -37.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2847.8620, -197.3851, 15.4919, 2.7999, 4.8997, -37.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2823.5322, -229.7816, 12.9777, 5.6999, 3.9000, -23.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2814.3647, -239.2534, 12.0607, 5.6999, 3.9000, -52.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2807.9970, -254.3222, 10.1948, 5.6999, 3.9000, -6.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(849, 2828.2177, -208.7859, 14.1096, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(669, 2843.2351, -199.4273, 14.8688, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4
    tempobjid = CreateDynamicObject(3172, 2788.3190, -265.9432, 8.3912, 0.0000, -78.3000, 24.1000, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(3594, 2789.1652, -260.3373, 8.8577, 3.6998, 0.0000, 11.1997, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 2792.4118, -263.4085, 8.9729, -4.8997, 0.0000, -105.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(16304, 2786.6716, -269.3522, 6.7694, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(16304, 2783.4619, -262.2821, 7.0194, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    //CreateDynamicObject(874, 2792.8454, -280.0975, 8.2536, 0.0000, 0.0000, 25.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2785.5817, -272.8927, 8.2536, 0.0000, 0.0000, -149.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(849, 2793.5239, -265.4020, 8.4195, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1450, 2791.4116, -264.9049, 8.8507, 3.2999, -0.9998, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(12990, 2872.2856, -302.6440, 0.6352, 0.0000, 0.0000, 88.0000, -1, -1, -1, 400.0, 400.0); //sw_jetty
    tempobjid = CreateDynamicObject(639, 2823.2150, -410.1831, 14.3072, 0.0000, 0.0000, -129.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(19360, 2814.0380, -397.1241, 9.2221, -3.5999, 0.0000, -37.7000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterialText(tempobjid, 0, "This tunnel is your death..", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 55, 0, 0xFFFFFFFF, 0x00000000, 0);
    tempobjid = CreateDynamicObject(639, 2819.0417, -406.7557, 14.3072, 0.0000, 0.0000, -129.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 2815.2780, -403.6643, 14.3072, 0.0000, 0.0000, -129.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3035, 2822.7270, -417.3139, 9.5221, 0.0000, 0.0000, -129.4998, -1, -1, -1, 400.0, 400.0); //tmp_bin
    tempobjid = CreateDynamicObject(639, 2784.4880, -465.4229, 15.4849, 0.0000, 0.0000, 66.3000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 2789.2502, -467.5130, 15.4849, 0.0000, 0.0000, 66.3000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(19360, 2814.9836, -395.9012, 8.4636, -3.5999, 0.0000, -37.7000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterialText(tempobjid, 0, "Your only warning..", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 55, 0, 0xFFFFFFFF, 0x00000000, 0);
    //CreateDynamicObject(874, 2822.7172, -383.7189, 9.1728, -4.0998, 15.2999, -36.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2826.6750, -376.2224, 8.6419, -6.8997, 15.2999, -36.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19360, 2812.1430, -399.5823, 8.5108, -3.0999, 0.0000, -37.9000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 2812.6450, -399.5209, 8.6329, -2.5999, 90.0000, -36.2999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2908, 2812.6147, -400.2167, 8.7798, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2907, 2812.8742, -399.4414, 8.6864, -6.8997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 2813.1611, -399.5650, 8.7054, 0.0000, 0.0000, -39.9000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(3172, 2813.0961, -423.3962, 9.2130, -2.0999, 0.0000, -32.2000, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(3171, 2805.7377, -416.7388, 9.1653, 1.0999, 1.9996, 142.4998, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(3171, 2801.4016, -423.4559, 9.3444, 1.0999, 1.9996, 155.6000, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(3172, 2795.8811, -442.5538, 11.0017, 0.0000, -88.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(3593, 2801.6857, -433.5356, 10.0101, -0.6000, 1.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 2798.2292, -432.2120, 10.4855, -7.4000, 0.0000, 54.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 2825.0278, -405.3641, 8.8514, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 2820.9636, -410.0241, 9.1752, 2.5000, 0.0000, 126.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, 2823.2041, -407.4244, 8.6674, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1440, 2806.0849, -419.5086, 9.7915, 0.0000, 0.0000, 49.2999, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(1265, 2812.8164, -420.4241, 9.5093, 0.0000, 0.0000, 63.2000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, 2812.4345, -420.9572, 9.5093, 0.0000, 0.0000, 21.2000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, 2812.7541, -420.7583, 9.8893, 0.0000, 0.0000, 21.2000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1711, 2808.9729, -426.1723, 9.4321, 0.0000, -2.0999, -154.1999, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(2671, 2811.9865, -421.1069, 9.2599, -1.1000, 1.1999, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_3
    tempobjid = CreateDynamicObject(1328, 2802.3608, -425.2510, 10.0248, -3.7000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1328, 2802.9423, -424.4169, 9.5951, -3.7000, 91.4999, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(2673, 2802.8659, -425.1553, 9.6000, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_5
    tempobjid = CreateDynamicObject(849, 2799.7292, -430.9996, 9.8069, 0.0000, 0.0000, -90.1996, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1440, 2798.9040, -434.9963, 10.1096, 0.0000, 0.0000, -22.9999, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(12957, 2811.6298, -410.1465, 9.4638, -1.2999, 0.0000, -35.7999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(10984, 2837.4555, -323.7972, 5.6489, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled01_SFS
    tempobjid = CreateDynamicObject(849, 2823.1655, -416.0585, 9.1499, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1440, 2821.1127, -419.1694, 9.5593, 0.0000, 0.0000, -129.4998, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(1265, 2822.3776, -416.5953, 9.2783, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, 2823.8144, -416.5686, 9.3337, 0.0000, 0.0000, 69.6996, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1331, 2793.6062, -426.2854, 10.4354, 89.9999, 51.1999, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt01_LA
    tempobjid = CreateDynamicObject(1486, 2809.4541, -425.8919, 9.5618, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, 2809.4541, -425.7019, 9.5618, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, 2809.5642, -425.8320, 9.5618, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(2035, 2808.1159, -426.2202, 9.8681, 0.0000, -73.3000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_M16
    //CreateDynamicObject(874, 2791.4230, -496.8142, 10.8203, 0.0000, 0.0000, 17.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2790.0532, -488.1145, 10.5003, 0.0000, 0.0000, -9.6000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 2784.6525, -457.6192, 10.3163, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 2789.1796, -456.7232, 10.2305, 0.0000, 0.0000, -59.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 2788.2248, -460.4223, 10.7264, 5.8997, 0.0000, 31.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 2792.5393, -459.2947, 10.2686, 0.0000, 0.0000, -89.7994, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 2784.9519, -462.5855, 10.5696, 11.0000, 0.0000, -20.4999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(849, 2784.0803, -461.4515, 10.0471, 0.0000, 0.0000, -169.6000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, 2786.6018, -461.5263, 9.9701, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, 2790.1250, -460.9869, 9.9321, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(3593, 2778.1940, -476.4598, 10.1478, -1.2999, 0.0000, -10.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 2777.2321, -484.3673, 10.2461, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3168, 2784.9543, -491.5780, 10.3253, 0.0000, -79.3000, -167.1999, -1, -1, -1, 400.0, 400.0); //trailer2_01
    tempobjid = CreateDynamicObject(3594, 2781.8559, -496.4707, 10.3289, 0.0000, 0.0000, -158.9998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 2786.4116, -501.7283, 10.3289, 0.0000, 0.0000, -107.4999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(19360, 2776.4782, -494.3959, 9.7370, 0.0000, 89.7994, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 2776.6174, -494.4515, 9.8086, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 2776.8850, -494.4753, 9.8280, 2.8998, 5.8997, -27.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2906, 2776.3872, -494.4848, 9.8395, 2.8998, -176.1000, 32.7000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2036, 2776.4882, -493.9765, 9.8163, 0.0000, 0.0000, 71.1996, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(3005, 2786.4150, -455.3398, 9.8210, 0.0000, 0.0000, 42.2999, -1, -1, -1, 400.0, 400.0); //smash_box_stay
    tempobjid = CreateDynamicObject(2673, 2794.7546, -427.3894, 9.8898, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_5
    tempobjid = CreateDynamicObject(1450, 2796.0959, -443.0559, 10.3823, 0.0000, 0.0000, 91.2994, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(1442, 2803.3205, -431.1846, 10.2037, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(12957, 2840.2900, -333.0002, 7.2135, 2.7999, 0.0000, -169.8999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3594, 2839.1105, -326.2835, 6.9713, 0.0000, 0.0000, -152.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 2834.3374, -321.5649, 6.9713, 0.0000, 0.0000, 56.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, 2847.1345, -325.1087, 7.2596, 0.0000, 0.0000, 6.3997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2843.7834, -314.6069, 7.2596, 0.0000, 0.0000, 6.3997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2825.9848, -333.3045, 7.7083, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2823.5395, -325.0002, 7.7083, 0.0000, 0.0000, -174.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3585, 2819.9702, -135.7207, 33.0844, 0.0000, -3.3998, 70.1996, -1, -1, -1, 400.0, 400.0); //lastran1_LA02
    tempobjid = CreateDynamicObject(3585, 2822.7766, -127.9252, 33.5769, 0.0000, -3.3998, 70.1996, -1, -1, -1, 400.0, 400.0); //lastran1_LA02
    tempobjid = CreateDynamicObject(3585, 2817.0957, -143.7041, 32.5806, 0.0000, -3.3998, 70.1996, -1, -1, -1, 400.0, 400.0); //lastran1_LA02
    tempobjid = CreateDynamicObject(3585, 2811.6484, -148.5592, 31.5477, -82.8999, -51.0998, 79.0000, -1, -1, -1, 400.0, 400.0); //lastran1_LA02
    tempobjid = CreateDynamicObject(2985, 2817.8630, -144.0265, 31.7898, 3.4999, 0.0000, -18.5998, -1, -1, -1, 400.0, 400.0); //minigun_base
    tempobjid = CreateDynamicObject(2985, 2821.9597, -127.5970, 32.7829, -3.3998, 0.0000, 160.3999, -1, -1, -1, 400.0, 400.0); //minigun_base
    tempobjid = CreateDynamicObject(19636, 2816.9846, -136.8755, 31.4316, 3.1998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //RedApplesCrate1
    tempobjid = CreateDynamicObject(19637, 2815.9238, -138.1855, 31.3516, 3.0000, 0.0000, -59.5000, -1, -1, -1, 400.0, 400.0); //GreenApplesCrate1
    tempobjid = CreateDynamicObject(19576, 2816.5463, -137.8928, 31.4076, 0.0000, -79.6996, 0.0000, -1, -1, -1, 400.0, 400.0); //Apple2
    tempobjid = CreateDynamicObject(19576, 2816.6394, -138.1779, 31.3920, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Apple2
    tempobjid = CreateDynamicObject(19575, 2816.7163, -137.3999, 31.4580, 0.0000, 87.0000, -78.3999, -1, -1, -1, 400.0, 400.0); //Apple1
    tempobjid = CreateDynamicObject(19575, 2816.9609, -137.3497, 31.4580, -3.0000, 91.5998, -133.1000, -1, -1, -1, 400.0, 400.0); //Apple1
    tempobjid = CreateDynamicObject(19575, 2817.0693, -136.3161, 31.5100, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Apple1
    //CreateDynamicObject(874, 2800.1174, -137.2362, 33.9518, 3.7999, 22.7999, -27.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1221, 2823.2866, -133.5097, 32.2453, 3.5000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1221, 2819.7155, -137.1390, 32.6146, 3.5000, 0.0000, -18.0998, -1, -1, -1, 400.0, 400.0); //cardboardbox4
    tempobjid = CreateDynamicObject(1230, 2822.4011, -134.4927, 32.1342, 4.4000, -1.3997, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox
    tempobjid = CreateDynamicObject(3171, -502.5739, 297.2123, 1.3372, 0.0000, 0.0000, 140.9998, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(1711, -502.1072, 294.7589, 1.4278, 0.0000, 0.0000, 61.2999, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(806, -467.2460, 274.0310, 4.8881, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass
    //CreateDynamicObject(874, -465.6187, 271.8565, 3.3659, -22.1000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -472.2384, 271.8565, 3.3659, -22.1000, 0.0000, 21.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1463, -469.5686, 296.0531, 1.7611, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_WOODPILE2
    tempobjid = CreateDynamicObject(1442, -500.1846, 297.5411, 1.9859, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(18693, -500.1488, 297.5451, 0.5594, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Flame99
    tempobjid = CreateDynamicObject(16304, -469.4454, 296.8970, 0.6542, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5114, "beach_las2", "sw_sand", 0x00000000);
    tempobjid = CreateDynamicObject(2905, -474.2632, 295.9111, 1.4470, 0.0000, 0.0000, 101.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2905, -474.2695, 296.1860, 1.4982, 42.1999, 81.6996, 102.3999, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(1710, -499.0104, 298.1582, 1.4182, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kb_couch07
    tempobjid = CreateDynamicObject(1486, -495.3558, 297.4765, 1.5348, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, -495.2260, 297.4826, 1.4349, 93.4999, 27.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(2670, -498.8066, 297.1134, 1.5196, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_1
    //CreateDynamicObject(874, -491.5103, 272.9776, 3.0748, -1.2999, 7.9998, 67.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3172, -489.3728, 301.2330, 1.3114, 0.0000, 0.0000, 80.7994, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(1442, -487.7246, 298.6812, 1.9859, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    //CreateDynamicObject(874, -287.4436, 274.7698, 4.6331, 0.0000, 0.0000, 79.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -276.4830, 272.0974, 5.6641, 3.7999, 0.0000, -110.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -236.2937, 263.4620, 10.3268, -0.8999, 0.0000, 75.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -251.5092, 267.4537, 8.9497, -2.9000, 0.0000, 75.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(672, -263.5888, 269.7185, 6.9987, 0.0000, -1.3997, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree5
    tempobjid = CreateDynamicObject(669, -293.8041, 275.2850, 3.4542, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4
    //CreateDynamicObject(874, -247.0915, 238.9683, 10.8465, -5.3000, 0.0000, 53.7000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(800, -256.9165, 242.0690, 8.7131, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    //CreateDynamicObject(874, -265.7998, 243.7187, 9.7018, -2.5000, 15.1997, 76.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(759, -316.7807, 275.5602, 1.6469, 0.0000, 0.0000, 117.5998, -1, -1, -1, 400.0, 400.0); //sm_bush_large_1
    //CreateDynamicObject(874, -307.1910, 278.3229, 3.0532, -2.0000, 0.0000, 79.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3593, -264.9281, 256.4490, 7.2259, -7.0998, 0.1999, 70.7994, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -263.0137, 252.6678, 8.1815, 4.9000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, -263.9840, 253.9752, 7.2786, -1.2999, -3.7000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    //CreateDynamicObject(874, -317.7055, 280.2149, 2.6802, -2.0000, 0.0000, 79.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, -292.6878, 263.0028, 4.0356, 4.0000, -5.5998, -64.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -297.2088, 259.9504, 3.6057, -3.2000, -9.6997, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, -297.2796, 255.0113, 4.1824, 7.7999, -9.6997, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(19360, -329.9013, 267.4458, 1.0848, -0.3998, 87.4999, -0.9998, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(16302, -297.2810, 241.4559, 5.3878, 11.5000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile04
    SetDynamicObjectMaterial(tempobjid, 0, 10368, "cathedral_sfs", "dirt64b2", 0x00000000);
    tempobjid = CreateDynamicObject(2905, -300.4967, 263.4215, 2.8027, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2907, -299.5621, 262.6982, 2.8568, -3.2999, 0.0000, 83.4000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(3171, -309.3222, 271.8677, 3.1308, 0.6998, -91.7994, 0.1999, -1, -1, -1, 400.0, 400.0); //trailer5_01
    //CreateDynamicObject(874, -337.1506, 282.8395, 1.8451, -2.0000, 0.0000, 79.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -341.3416, 259.3908, 2.7927, 6.2999, 0.0000, 79.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -348.8489, 284.0043, 2.0780, 0.0000, 0.0000, 81.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(691, -345.3869, 259.5805, 1.0469, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4_big
    //CreateDynamicObject(874, -364.3218, 263.6882, 2.8680, 1.8997, 14.0999, 81.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -371.5343, 264.7070, 2.8768, 1.8997, 14.0999, 81.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, -342.3872, 271.3785, 1.5167, 0.0000, 0.0000, -66.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -348.4024, 270.6260, 1.7510, -7.7999, 0.0000, 84.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, -343.8717, 275.6560, 1.4183, 0.0000, 0.0000, 27.2000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(19360, -299.5314, 262.8262, 2.8320, -0.8999, 84.1996, -2.3998, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -329.9172, 267.1473, 1.2043, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, -330.0845, 266.3027, 1.2173, 0.0000, 0.0000, -47.6999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2906, -329.6545, 267.2199, 1.2244, 0.0000, 0.0000, -27.1000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(3593, -330.1523, 264.7239, 1.5993, 0.8000, -1.2999, -96.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(2036, -330.7489, 267.1451, 1.1497, 0.0000, -3.0999, 81.7994, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(1735, -490.4093, 301.2604, 4.4471, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_EASYCHAIR1
    //CreateDynamicObject(874, -372.4071, 287.5249, 2.0780, 0.0000, 0.0000, 81.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -385.5740, 265.3178, 2.0780, 0.0000, 0.0000, 81.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19360, -427.2167, 296.4042, 0.7541, -7.0998, -89.7994, -1.1999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(3569, -367.3417, 276.7677, 3.2179, 1.5999, -1.0999, -105.2994, -1, -1, -1, 400.0, 400.0); //lasntrk3
    tempobjid = CreateDynamicObject(3569, -496.4088, 274.8959, 2.6744, -1.8997, -89.5998, 13.3000, -1, -1, -1, 400.0, 400.0); //lasntrk3
    tempobjid = CreateDynamicObject(2907, -427.3078, 296.5887, 0.8614, -2.7999, 0.0000, -42.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, -427.5197, 295.8698, 0.9253, -5.0998, 0.0000, 53.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    //CreateDynamicObject(874, -426.8323, 270.0187, 3.6514, 0.0000, 21.6000, 81.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -416.5429, 269.3179, 3.3238, 0.0000, 21.6000, 81.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -370.3638, 253.0686, 6.8470, -2.5999, 19.2999, 81.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -382.5177, 252.8963, 7.0229, 5.3997, 19.2999, 96.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -427.7633, 258.8810, 10.6105, 0.0000, 10.7999, 59.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -438.7709, 264.9301, 9.2360, -4.1999, 23.8999, 59.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(669, -507.5588, 276.3536, 1.1073, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4
    //CreateDynamicObject(874, -510.9804, 273.1177, 3.5171, -3.9997, 7.9998, 67.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3593, -513.2744, 281.4973, 1.4780, 0.0000, 0.0000, 43.4999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -515.6455, 291.2926, 1.6667, 0.0000, 0.0000, -76.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, -543.9572, 273.9974, 2.8984, -3.9997, 11.4996, 69.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -551.6284, 272.7312, 3.2139, -0.5996, 11.4996, 80.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3593, -551.0744, 281.9638, 1.4982, 0.0000, 0.0000, -83.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -550.1405, 285.3948, 1.8437, -10.5999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -554.1718, 285.9826, 1.4867, 0.0000, 0.0000, 57.4999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, -554.4641, 283.3861, 1.3881, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, -548.8441, 284.3062, 1.3881, 0.0000, 0.0000, -41.9000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(19360, -548.0307, 285.7846, 0.9980, 0.0000, -89.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -547.7600, 285.7875, 1.1303, 0.0000, 0.0000, -17.3999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, -548.5722, 284.9812, 1.2422, 37.4999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, -546.9749, 285.3912, 1.1296, 0.0000, 0.0000, -171.0997, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    //CreateDynamicObject(874, -495.7102, 260.2622, 11.6141, 0.0000, 0.0000, 72.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -485.4938, 260.0577, 11.6141, 0.0000, 0.0000, 64.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, -434.5625, 290.5090, 1.8459, 0.0000, 0.0000, 50.0998, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3594, -429.2843, 290.9963, 1.6526, 0.0000, 0.0000, -93.6996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(1440, -436.1351, 289.6752, 1.8199, 0.0000, 0.0000, -38.9999, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(3005, -552.3078, 287.2807, 1.0880, 0.0000, 0.0000, 38.3997, -1, -1, -1, 400.0, 400.0); //smash_box_stay
    tempobjid = CreateDynamicObject(2036, -489.9749, 301.1122, 5.0451, 0.0000, -100.1996, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(11145, -9.1075, 263.9436, 3.9447, 0.0000, 0.0000, -19.0998, -1, -1, -1, 400.0, 400.0); //CARRIER_LOWDECK_SFS
    tempobjid = CreateDynamicObject(3594, -570.7052, 285.0262, 1.4867, 0.0000, 0.0000, -45.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -577.4196, 278.4046, 1.4867, 0.0000, 0.0000, 99.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, -580.4052, 283.4389, 1.7287, 0.0000, 0.0000, 60.3997, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    //CreateDynamicObject(874, -586.2188, 269.8749, 2.6672, 4.1999, 11.1000, 93.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -594.4566, 269.2897, 2.8603, 2.7999, 11.1000, 93.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 20.1770, 248.5590, 17.8589, 0.0000, 0.0000, -19.1000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(825, 1190.1490, 522.1898, 19.5165, 0.0000, 0.0000, -93.6996, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(10770, 50.9594, 235.3224, 38.3324, 0.0000, 0.0000, -19.0000, -1, -1, -1, 400.0, 400.0); //CARRIER_BRIDGE_SFSe
    tempobjid = CreateDynamicObject(10772, 51.6515, 243.0574, 16.9922, 0.0000, 0.0000, -19.0000, -1, -1, -1, 400.0, 400.0); //CARRIER_LINES_SFSe
    tempobjid = CreateDynamicObject(3115, -43.2335, 275.7279, 16.7497, 0.0000, 0.0000, 161.0000, -1, -1, -1, 400.0, 400.0); //CARRIER_LIFT1_SFSE
    tempobjid = CreateDynamicObject(11146, 42.0684, 246.9907, 12.0536, 0.0000, 0.0000, -18.9999, -1, -1, -1, 400.0, 400.0); //CARRIER_HANGAR_SFS
    tempobjid = CreateDynamicObject(11149, 42.8908, 240.6392, 11.6422, 0.0000, 0.0000, -19.0000, -1, -1, -1, 400.0, 400.0); //accorridors_SFS
    tempobjid = CreateDynamicObject(3114, 1.6260, 276.3099, 16.4395, 0.0000, 0.0000, -18.8999, -1, -1, -1, 400.0, 400.0); //CARRIER_LIFT2_SFSE
    tempobjid = CreateDynamicObject(639, 46.4500, 242.2682, 20.9589, 0.0000, 0.0000, -109.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 39.7008, 244.6584, 20.9589, 0.0000, 0.0000, -109.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(11237, 50.6053, 234.8013, 38.2887, 0.0000, 0.0000, -17.1998, -1, -1, -1, 400.0, 400.0); //CARRIER_Bits_SFSe
    tempobjid = CreateDynamicObject(639, 40.4718, 235.9163, 26.6140, 0.0000, 0.0000, 70.1996, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(19360, 27.8880, 249.1609, 17.8187, 0.0000, 0.0000, 70.6996, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFFFFF0F5);
    tempobjid = CreateDynamicObject(639, 43.9780, 234.7283, 26.6140, 0.0000, 0.0000, 72.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(19360, 58.6467, 242.4794, 16.9468, 0.0000, 89.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(9812, 34.1403, 234.0695, 9.2066, 0.0000, 0.0000, -19.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(9812, -23.9220, 253.0711, 9.1258, -9.3999, 0.0000, -19.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(9812, 120.8954, 233.9700, 9.2665, 0.0000, 0.0000, 160.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(9812, 66.2592, 252.9223, 9.2798, 0.0000, 0.0000, 160.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(9812, 40.2975, 261.9009, 9.3366, 0.0000, 0.0000, 160.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(9812, -20.1788, 282.8424, 9.3366, 0.0000, 0.0000, 160.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(636, 59.0858, 226.5590, 28.3470, 0.2998, -87.8000, 72.8000, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(636, 50.7671, 229.3433, 28.3852, 0.2998, -87.8000, 72.8000, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(639, 54.9098, 228.0142, 27.8812, 0.0000, 0.0000, 71.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 63.8585, 221.3197, 8.9118, 0.0000, 0.0000, 70.4999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 69.0055, 219.5287, 8.9118, 0.0000, 0.0000, 70.4999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 78.3842, 216.3244, 8.9118, 0.0000, 0.0000, 70.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(9812, 111.5866, 207.4252, 9.2066, 0.0000, 0.0000, -19.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(639, 62.2294, 225.4665, 27.8812, 0.0000, 0.0000, 71.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 110.6697, 208.1286, 8.9118, 0.0000, 0.0000, 73.8999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 48.5377, 230.2115, 27.8852, 0.0000, 3.0999, 71.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 61.3950, 237.7180, 27.9015, 0.0000, 2.9000, -108.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 56.0783, 239.5390, 27.9029, 0.0000, 2.9000, -108.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 52.8371, 240.6929, 27.9060, 0.0000, 2.9000, -108.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 72.5419, 224.4721, 22.9803, 0.0000, 0.0000, 160.6997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 74.6259, 230.5131, 23.0102, 0.0000, 0.0000, 160.6997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(19360, 28.1375, 249.8739, 16.9160, 0.0000, -90.1996, 70.6996, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFFFFF0F5);
    tempobjid = CreateDynamicObject(2907, 28.3936, 250.0621, 17.0715, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 27.7747, 249.6838, 17.0447, 0.0000, 0.0000, -35.7999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(19360, 8.8388, 253.6123, 16.9160, 0.0996, -89.8999, 70.6996, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFFFFF0F5);
    tempobjid = CreateDynamicObject(19360, 16.1637, 245.8766, 16.9279, 0.0996, -89.8999, 70.6996, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0xFFFFF0F5);
    tempobjid = CreateDynamicObject(2907, 16.1847, 246.0684, 17.0415, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 16.2518, 246.7872, 17.0762, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2906, 15.6913, 246.3489, 17.0429, 0.0000, 0.0000, 27.2000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(3884, 85.9652, 223.1976, 16.4503, 0.0000, 0.0000, -148.3999, -1, -1, -1, 400.0, 400.0); //samsite_SFXRF
    tempobjid = CreateDynamicObject(19360, 68.9962, 242.4794, 16.9468, -1.1999, 89.9999, 45.1999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(647, -110.6315, 202.7518, 3.8761, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //new_bushsm
    //CreateDynamicObject(874, -86.0018, 218.9709, 2.3408, 2.9999, 0.0000, 70.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -96.7012, 222.8018, 2.9363, 2.9999, 0.0000, 61.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -106.5203, 227.1717, 3.9098, 5.2999, 0.0000, 34.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(669, -80.5913, 212.9234, 1.2704, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4
    //CreateDynamicObject(874, -116.2985, 229.7839, 5.1715, 5.2999, 0.0000, 71.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -152.6763, 240.8643, 9.2472, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(672, -157.8795, 237.6705, 9.7151, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree5
    //CreateDynamicObject(874, -127.1660, 229.6020, 6.0187, -5.0998, 0.0000, -124.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -114.4151, 235.5122, 5.1715, 5.2999, 0.0000, 71.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -123.7051, 234.5644, 6.0187, -5.0998, 0.0000, -124.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -140.4974, 210.3251, 7.1542, -5.0998, 0.0000, -106.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -150.5702, 213.2324, 8.2503, -5.0998, 0.0000, -106.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(800, -135.6174, 230.2781, 7.3561, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    //CreateDynamicObject(874, -40.9444, 171.9376, 2.0780, 0.0000, 0.0000, 49.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(647, -80.9281, 214.1056, 2.5826, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //new_bushsm
    //CreateDynamicObject(874, -113.4548, 202.5200, 3.9493, -5.0998, 0.0000, -106.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -122.4636, 205.1201, 4.9670, -5.0998, 0.0000, -106.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -15.5656, 158.0894, 2.0780, 0.0000, 0.0000, 49.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -26.0333, 189.2122, 2.0780, 0.0000, 0.0000, 60.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -14.7256, 181.5110, 2.0780, 0.0000, 0.0000, -126.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(703, -9.5037, 178.6284, 0.5238, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(800, -45.4961, 174.4998, 2.0780, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(672, 111.0494, 125.7479, 1.8336, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree5
    //CreateDynamicObject(874, -8.6222, 153.6150, 2.0780, 0.0000, 0.0000, 49.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 5.4001, 169.8603, 2.0780, 0.0000, 0.0000, 54.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 17.7367, 162.2669, 2.0780, 0.0000, 0.0000, -119.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(800, 58.4396, 108.8833, 2.4296, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    //CreateDynamicObject(874, 51.6985, 115.9235, 2.0780, 0.0000, 0.0000, 47.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -0.2353, 144.9523, 2.0780, 0.0000, 0.0000, 130.5997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 27.7464, 156.8681, 2.0780, 0.0000, 0.0000, -119.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 34.5890, 152.9808, 2.0780, 0.0000, 0.0000, -119.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 22.5123, 131.7218, 2.0780, 0.0000, 0.0000, -119.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 30.5986, 127.1277, 2.0780, 0.0000, 0.0000, -123.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 58.3399, 136.2118, 2.0780, 0.0000, 0.0000, -133.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 49.9463, 141.0959, 2.0780, 0.0000, 0.0000, -138.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 67.5912, 132.1347, 2.0780, 0.0000, 0.0000, 53.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 76.9318, 126.9748, 1.8480, 0.0000, 0.0000, 59.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 85.9449, 121.4897, 1.8480, 0.0000, 0.0000, 59.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(703, 87.3432, 127.6108, 0.4449, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(691, 65.4913, 107.6007, -0.2029, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4_big
    //CreateDynamicObject(874, 69.4104, 104.2005, 2.0780, 0.0000, 0.0000, 47.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 95.6227, 115.8122, 1.8480, 0.0000, 0.0000, 70.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(762, 78.6259, 128.8372, 2.0780, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //new_bushtest
    //CreateDynamicObject(874, 78.5662, 99.0332, 2.0780, 0.0000, 0.0000, 47.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 159.7727, 82.3363, 2.2578, 0.0000, 0.0000, 59.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 102.6212, 110.9085, 1.8480, 0.0000, 0.0000, 59.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 114.0388, 102.5323, 1.8480, 0.0000, 0.0000, -124.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19360, 160.5910, 148.0498, 0.9721, 0.0996, -95.8000, -85.8999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    //CreateDynamicObject(874, 100.6715, 125.2266, 1.8480, 0.0000, 0.0000, -124.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 123.0447, 97.9589, 1.8480, 0.0000, 0.0000, -124.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 119.7863, 108.8208, 1.8480, 0.0000, 0.0000, -124.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 130.2691, 96.4645, 1.8480, 0.0000, 0.0000, 68.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 138.2239, 91.5447, 1.8480, 0.0000, 0.0000, 61.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 128.0498, 71.8302, 1.8480, 0.0000, 0.0000, 44.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 119.6322, 76.6686, 1.8480, 0.0000, 0.0000, 44.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 137.2769, 67.6100, 1.8480, 0.0000, 0.0000, 44.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 148.0101, 62.0666, 1.8480, 0.0000, 0.0000, 44.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 148.4049, 86.6417, 1.8480, 0.0000, 0.0000, 59.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(669, 149.7514, 84.2667, 1.2956, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4
    tempobjid = CreateDynamicObject(10773, 149.8166, 116.2527, 3.7848, -3.0999, 2.0999, -85.3003, -1, -1, -1, 400.0, 400.0); //dk_cargoshp2_SFSe
    tempobjid = CreateDynamicObject(2934, 171.8018, 143.7967, 2.3394, -1.6998, 0.0000, 71.5998, -1, -1, -1, 400.0, 400.0); //kmb_container_red
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    //CreateDynamicObject(874, 155.0010, 124.2416, 1.8480, 0.0000, 0.0000, -124.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(2932, 112.8731, 142.7651, -0.1036, -43.9000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_container_blue
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    //CreateDynamicObject(874, 146.9205, 112.5285, 2.2980, 0.0000, 0.0000, -124.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(2912, 146.8887, 99.3283, 1.6051, 0.0000, -3.9999, 50.0000, -1, -1, -1, 400.0, 400.0); //temp_crate1
    tempobjid = CreateDynamicObject(2906, 160.9476, 148.4161, 1.0542, -5.5998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2905, 159.9261, 148.6405, 0.9944, -2.9000, 0.0000, 32.6999, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(19360, 146.7176, 139.2126, 1.3631, 0.0000, 89.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 154.5876, 139.2126, 1.3767, -0.2998, 89.4999, 27.8999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 91.7518, 148.4830, 0.5335, 0.0000, -61.9999, 67.9000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 72.5474, 147.8634, 1.3494, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, -0.2549, 180.4362, 1.3494, 0.0000, -89.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 146.2377, 139.3885, 1.4651, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2907, 154.2523, 138.9649, 1.5053, 0.0000, 0.0000, 60.5998, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 154.8224, 138.7028, 1.5384, 0.0000, 0.0000, 72.1996, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2973, 135.4895, 124.6818, 1.5468, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2973, 132.7236, 120.1218, 2.5055, -4.3997, -99.9000, -25.3999, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(2912, 149.8359, 99.2311, 1.8126, 0.0000, -1.2999, -29.8999, -1, -1, -1, 400.0, 400.0); //temp_crate1
    tempobjid = CreateDynamicObject(2912, 148.4438, 98.0233, 1.6051, 0.0000, 59.5998, 50.0000, -1, -1, -1, 400.0, 400.0); //temp_crate1
    tempobjid = CreateDynamicObject(18257, 142.8607, 104.5615, 1.2596, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(2907, 91.8460, 148.8511, 0.4275, -29.8999, 178.7998, -24.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 91.9300, 148.4676, 0.5964, 154.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2906, 91.5000, 148.6015, 0.6201, 150.8999, -176.0997, -29.6998, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, 91.2042, 146.7843, 1.4500, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2907, 72.3386, 147.7084, 1.4680, 0.0000, 0.0000, -36.9999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 72.5708, 148.4597, 1.4867, 0.0000, 0.0000, -8.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2905, 0.4848, 179.8450, 1.4766, 0.0000, 0.0000, -134.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2905, -0.5224, 180.7102, 1.4328, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(3594, 20.8299, 144.3690, 1.5664, 0.0000, 0.0000, 61.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, -167.7427, 247.1528, 10.6498, 0.0000, 0.0000, 58.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -178.0260, 250.2407, 11.2398, 0.9998, 0.0000, 62.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, -127.6399, 221.6213, 5.6451, -5.7999, 0.0000, -96.2994, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -129.9089, 217.2395, 5.8189, 0.5000, -7.9998, 153.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -110.2835, 210.3553, 3.5954, 6.7999, 0.0000, 74.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -103.7117, 208.4958, 2.9528, 4.8000, 0.0000, 55.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -34.6282, 178.8509, 1.5483, 0.0000, 0.0000, -110.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -29.4708, 179.5030, 1.5167, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -30.9288, 178.1739, 2.3666, -1.2000, 0.0000, -80.2994, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, -33.2191, 182.2281, 1.6986, 0.0000, 0.0000, 31.1998, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(12957, 15.0684, 147.5092, 1.6785, 0.0000, 0.0000, 57.8997, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3171, 83.8339, 115.6380, 1.5713, 0.0000, -74.8999, -115.3999, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = CreateDynamicObject(3594, 27.0576, 140.9595, 1.5664, 0.0000, 0.0000, 61.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 33.8740, 140.8600, 1.4982, 0.0000, 0.0000, 84.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 39.2024, 138.7893, 2.0060, -9.6997, 0.0000, -120.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = //CreateDynamicObject(855, -115.5919, 251.5433, 0.4726, 0.0000, 0.0000, 97.5000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(3593, 77.0185, 119.0830, 1.5383, 0.0000, 0.0000, 65.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 106.9604, 90.8470, 1.6167, 0.0000, 0.0000, 67.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 113.6603, 89.6435, 1.6167, 0.0000, 0.0000, -85.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 139.8303, 80.0046, 1.5283, 0.0000, 0.0000, 64.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 144.7942, 74.9810, 1.6066, 0.0000, 0.0000, -137.4998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 146.6224, 78.4776, 1.5483, 0.0000, 0.0000, 70.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 147.4201, 75.5080, 2.0388, -10.2999, 0.0000, -122.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 183.0879, 54.8632, 1.5082, 0.3998, 0.0000, -102.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 188.3820, 54.7658, 1.9565, -8.6997, 0.0000, -83.7994, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, -127.0466, 219.5381, 5.3512, 0.0000, 5.6999, 24.3999, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, -106.9813, 210.6903, 2.8938, 0.0000, 8.1000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(19360, -26.1625, 177.4506, 1.0082, 0.0000, -90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -25.9339, 177.4727, 1.1207, 0.0000, 0.0000, -50.6999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, -26.3819, 177.1148, 1.1100, 0.0000, 0.0000, -38.7000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(849, -31.4321, 176.4042, 1.1979, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, 29.8015, 141.7265, 1.2881, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(19360, 103.4439, 92.2332, 0.9983, 0.0000, 89.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 103.7378, 92.3152, 1.3645, -88.0998, -65.4000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 103.4542, 92.6632, 1.1575, 2.8998, 89.5998, 58.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2905, 103.3283, 92.4589, 1.1555, 2.8998, 89.5998, 58.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2906, 103.8759, 92.5298, 1.4240, -56.7999, -67.5000, 1.4996, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, 103.7406, 92.3432, 1.8782, -89.5998, 29.3999, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2036, 103.6248, 93.0802, 1.0779, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    //CreateDynamicObject(874, 177.5025, 74.2126, 2.2578, 0.0000, 0.0000, 73.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 311.8131, 87.4430, 3.5364, 2.5000, 0.0000, -67.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(849, 141.4338, 77.1043, 1.1979, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, 186.3616, 55.9966, 1.2481, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    //CreateDynamicObject(874, 168.7608, 53.2136, 1.8480, 0.0000, 0.0000, 62.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 321.0285, 92.7164, 3.4254, 2.5000, 0.0000, -67.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 327.8908, 97.5475, 3.6224, 2.5000, 0.0000, -67.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(647, 120.7730, 73.1725, 2.0934, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //new_bushsm
    //CreateDynamicObject(762, 143.7745, 60.7028, 2.4296, 0.0000, 0.0000, -114.3999, -1, -1, -1, 400.0, 400.0); //new_bushtest
    tempobjid = CreateDynamicObject(3172, 164.6098, 60.5606, 2.4567, 0.0000, -92.3999, 67.5998, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(1440, 112.6892, 91.4953, 1.5784, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(16444, 179.1058, 138.5966, 1.6337, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_blackbags
    tempobjid = CreateDynamicObject(16444, 181.3159, 140.1065, 1.6337, 0.0000, 0.0000, -108.3999, -1, -1, -1, 400.0, 400.0); //des_blackbags
    tempobjid = CreateDynamicObject(16444, 217.2606, 139.8480, 1.6533, 0.0000, 0.0000, -40.2999, -1, -1, -1, 400.0, 400.0); //des_blackbags
    tempobjid = CreateDynamicObject(1793, 51.1427, 232.8937, 9.7992, 0.0000, 0.0000, -16.6000, -1, -1, -1, 400.0, 400.0); //LOW_BED_2
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = //CreateDynamicObject(855, -111.5904, 252.1811, 0.4726, 0.0000, 0.0000, 103.3999, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -107.2052, 251.1186, 0.4726, 0.0000, 0.0000, 103.3999, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -119.7796, 251.9400, 0.4726, 0.0000, 0.0000, 88.0000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -123.8233, 252.4667, 0.4726, 0.0000, 0.0000, 79.0998, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(703, -100.0839, 230.9476, 2.3633, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = //CreateDynamicObject(855, -62.0381, 224.7247, 0.5443, 0.0000, 0.0000, -55.0998, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -58.6491, 223.0652, 0.5443, 0.0000, 0.0000, -55.0998, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -55.0923, 221.2178, 0.5443, 0.0000, 0.0000, -55.0998, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(2973, -32.0680, 193.7776, 1.3859, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //k_cargo2
    tempobjid = CreateDynamicObject(18257, -61.8580, 208.4376, 1.3193, 0.0000, 0.0000, 179.9998, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(2973, -32.0208, 189.8780, 2.3543, 0.0000, 93.3000, -32.0998, -1, -1, -1, 400.0, 400.0); //k_cargo2
    //CreateDynamicObject(874, -30.3495, 192.5563, 1.5496, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -59.8320, 210.5054, 1.9594, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19636, -33.0079, 183.1065, 1.5858, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //RedApplesCrate1
    tempobjid = //CreateDynamicObject(855, 199.3515, 162.1804, 0.7340, 0.0000, 0.0000, 94.8000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    tempobjid = //CreateDynamicObject(855, 203.8477, 162.1766, 0.3240, 0.0000, 0.0000, 94.8000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    SetDynamicObjectMaterial(tempobjid, 0, -1, "none", "none", 0xFFFFFAFA);
    tempobjid = CreateDynamicObject(18257, 29.9561, 260.3186, 1.6655, 0.0000, 0.0000, 65.6996, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(18260, 5.7202, 248.4057, 11.5030, 0.0000, 0.0000, -20.6998, -1, -1, -1, 400.0, 400.0); //crates01
    tempobjid = CreateDynamicObject(19360, 75.2636, 236.2557, 16.9216, 0.2001, 89.9999, 45.1999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 79.8013, 240.8249, 16.9316, -0.0996, 89.8998, 48.5998, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 90.3125, 223.5518, 16.9146, 0.0000, 89.9999, 45.1999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 98.5335, 226.3383, 16.9347, 0.0000, 89.9999, 45.1999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 98.5567, 226.3166, 17.0613, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 98.4458, 227.1311, 17.0561, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(19360, 38.6011, 235.5408, 10.1905, 0.0000, 0.0000, 70.9999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 38.7345, 236.8802, 9.7705, 0.0000, 90.0000, 70.9999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 38.8880, 236.5272, 9.9055, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 38.8908, 235.9839, 9.8989, 0.0000, 0.0000, 11.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(19360, 32.4425, 240.1851, 10.5031, 0.0000, 0.0000, -19.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 33.2103, 239.9208, 9.7847, 0.0000, -89.9999, -19.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 41.1492, 244.5166, 9.7847, 0.0000, -89.9999, -19.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 33.4263, 239.6891, 9.8957, 0.0000, 0.0000, -61.2000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 33.5055, 239.4573, 9.8872, 0.0000, 0.0000, -81.3000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(339, 33.7294, 239.6894, 10.6777, 0.0000, -169.6999, 0.0000, -1, -1, -1, 400.0, 400.0); //katana
    tempobjid = CreateDynamicObject(18257, 16.4594, 266.9906, 1.6655, 0.0000, 0.0000, 154.2998, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(19360, 33.3978, 242.9519, 11.3760, 14.4996, 0.0000, 161.1000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterialText(tempobjid, 0, "Army.. shit..", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 100, 1, 0xFF8B0000, 0x00000000, 0);
    tempobjid = CreateDynamicObject(1793, 48.5265, 233.6737, 9.7992, 0.0000, 0.0000, -16.6000, -1, -1, -1, 400.0, 400.0); //LOW_BED_2
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 51.5497, 233.5321, 9.7847, 0.0000, -89.9999, -19.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(1793, 51.1427, 232.8937, 9.7992, 0.0000, 0.0000, -16.6000, -1, -1, -1, 400.0, 400.0); //LOW_BED_2
    tempobjid = CreateDynamicObject(1793, 48.5265, 233.6737, 9.7992, 0.0000, 0.0000, -16.6000, -1, -1, -1, 400.0, 400.0); //LOW_BED_2
    tempobjid = CreateDynamicObject(19360, 48.8739, 234.4532, 9.7747, 0.0000, -89.9999, -19.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 49.7028, 235.4140, 10.5031, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 49.6338, 234.7469, 10.4664, 0.0000, 0.0000, -64.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(19360, 59.7285, 232.0424, 17.8854, 0.0000, 0.0000, -19.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(18257, 4.3284, 267.5020, 1.6756, 0.0000, 0.0000, 175.4998, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(19360, 59.7285, 232.0424, 16.8055, 0.0000, 90.0000, -19.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(18257, 1.8644, 267.9688, 1.6756, 0.0000, 0.0000, -31.7999, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(18257, -8.5045, 262.4577, 1.6756, 0.0000, 0.0000, -110.3000, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(2907, 59.1152, 232.7633, 16.9347, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 59.3712, 232.8437, 16.8997, 0.0000, 0.0000, -13.8000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(3796, -0.5388, 265.7510, 1.7165, 0.0000, 0.0000, 68.4000, -1, -1, -1, 400.0, 400.0); //acbox1_SFS
    tempobjid = CreateDynamicObject(3798, 6.0963, 264.0379, 1.7022, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox3_SFS
    tempobjid = CreateDynamicObject(3800, -5.2684, 264.6017, 1.7022, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox4_SFS
    tempobjid = CreateDynamicObject(3798, -8.5479, 262.8601, 1.7122, 0.0000, 0.0000, -17.2999, -1, -1, -1, 400.0, 400.0); //acbox3_SFS
    tempobjid = CreateDynamicObject(3800, -5.9984, 262.6217, 1.7022, 0.0000, 0.0000, -21.2999, -1, -1, -1, 400.0, 400.0); //acbox4_SFS
    tempobjid = CreateDynamicObject(18257, 18.8113, 265.8583, 1.6655, 0.0000, 0.0000, 70.4000, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(3791, 22.2215, 259.5628, 2.1533, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_10_SFXR
    tempobjid = CreateDynamicObject(3798, 12.0459, 262.9880, 1.7022, 0.0000, 0.0000, -45.2999, -1, -1, -1, 400.0, 400.0); //acbox3_SFS
    tempobjid = CreateDynamicObject(3791, 22.2215, 257.6830, 2.1533, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_10_SFXR
    tempobjid = CreateDynamicObject(3791, 22.2215, 255.8627, 2.1533, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_10_SFXR
    tempobjid = CreateDynamicObject(3795, 8.2896, 259.8713, 2.0144, 0.0000, 0.0000, -107.8999, -1, -1, -1, 400.0, 400.0); //missile_04_SFXR
    tempobjid = CreateDynamicObject(3795, 10.0024, 259.3182, 2.0144, 0.0000, 0.0000, -107.8999, -1, -1, -1, 400.0, 400.0); //missile_04_SFXR
    tempobjid = CreateDynamicObject(3787, 5.0254, 261.0599, 2.2295, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_02_SFXR
    tempobjid = CreateDynamicObject(3792, 8.5682, 259.7824, 2.8145, 0.0000, 0.0000, -107.6996, -1, -1, -1, 400.0, 400.0); //missile_08_SFXR
    tempobjid = CreateDynamicObject(3799, 111.8917, 220.5552, 9.8259, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox2_SFS
    tempobjid = CreateDynamicObject(18257, 16.0872, 256.9663, 9.9596, 0.0000, 0.0000, 70.5998, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(18260, -4.3481, 251.4084, 11.5030, 0.0000, 0.0000, -20.6998, -1, -1, -1, 400.0, 400.0); //crates01
    tempobjid = CreateDynamicObject(3796, 37.3376, 250.8936, 9.9207, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox1_SFS
    tempobjid = CreateDynamicObject(18257, 31.9696, 251.2351, 9.9596, 0.0000, 0.0000, -19.1000, -1, -1, -1, 400.0, 400.0); //crates
    tempobjid = CreateDynamicObject(3799, 56.7579, 252.8778, 9.8359, 0.0000, 0.0000, -21.1000, -1, -1, -1, 400.0, 400.0); //acbox2_SFS
    tempobjid = CreateDynamicObject(3800, 54.1049, 251.2057, 9.9462, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox4_SFS
    tempobjid = CreateDynamicObject(3800, 54.1049, 253.5756, 9.9462, 0.0000, 0.0000, -44.7999, -1, -1, -1, 400.0, 400.0); //acbox4_SFS
    tempobjid = CreateDynamicObject(3796, 83.5960, 235.1591, 9.8704, 0.0000, 0.0000, -95.9999, -1, -1, -1, 400.0, 400.0); //acbox1_SFS
    tempobjid = CreateDynamicObject(3800, 109.9018, 225.0050, 10.0563, 0.0000, 0.0000, 27.5000, -1, -1, -1, 400.0, 400.0); //acbox4_SFS
    tempobjid = CreateDynamicObject(3799, 113.5165, 224.9163, 9.8156, 0.0000, 0.0000, -70.5000, -1, -1, -1, 400.0, 400.0); //acbox2_SFS
    tempobjid = CreateDynamicObject(3798, 109.1091, 217.8372, 9.9561, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox3_SFS
    tempobjid = CreateDynamicObject(3800, 107.1004, 219.9140, 9.9462, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox4_SFS
    tempobjid = CreateDynamicObject(3796, 112.0613, 229.3802, 9.9006, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox1_SFS
    tempobjid = CreateDynamicObject(3787, 108.3190, 221.9053, 10.5031, 0.0000, 0.0000, -62.7999, -1, -1, -1, 400.0, 400.0); //missile_02_SFXR
    tempobjid = CreateDynamicObject(3789, 107.2367, 225.0892, 10.2686, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_09_SFXR
    tempobjid = CreateDynamicObject(3793, 108.3964, 230.1900, 10.1723, 50.2000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_06_SFXR
    tempobjid = CreateDynamicObject(19360, 99.5454, 226.2568, 9.8893, 0.0000, -89.9000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 106.0802, 233.1499, 9.8725, 0.0000, -90.0000, 64.1996, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(3788, 51.0326, 253.6522, 10.4357, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_03_SFXR
    tempobjid = CreateDynamicObject(3791, 20.8540, 256.4396, 10.4069, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_10_SFXR
    tempobjid = CreateDynamicObject(3791, 30.5499, 254.8692, 10.3971, 0.0000, 0.0000, -69.7994, -1, -1, -1, 400.0, 400.0); //missile_10_SFXR
    tempobjid = CreateDynamicObject(3791, 24.7835, 256.4580, 10.3872, 0.0000, 0.0000, 39.0998, -1, -1, -1, 400.0, 400.0); //missile_10_SFXR
    tempobjid = CreateDynamicObject(3791, 10.9333, 255.8688, 10.3872, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_10_SFXR
    tempobjid = CreateDynamicObject(3795, -0.9839, 253.1636, 10.2783, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //missile_04_SFXR
    tempobjid = CreateDynamicObject(19360, 6.0134, 254.8896, 9.8795, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, -5.7765, 255.9297, 9.8795, 0.0000, 90.0000, 50.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 6.3941, 254.6174, 10.0424, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 6.2933, 255.4967, 10.0368, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2908, 5.5611, 253.6961, 10.0015, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2906, -5.3571, 255.8276, 9.9939, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(3798, 80.9626, 220.8493, 9.9664, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //acbox3_SFS
    tempobjid = CreateDynamicObject(3800, 78.7089, 222.4929, 9.9561, 0.0000, 0.0000, -57.0998, -1, -1, -1, 400.0, 400.0); //acbox4_SFS
    tempobjid = CreateDynamicObject(3800, 81.4589, 223.5812, 9.9561, 0.0000, 0.0000, -86.1996, -1, -1, -1, 400.0, 400.0); //acbox4_SFS
    tempobjid = CreateDynamicObject(3788, 76.6520, 221.6873, 10.4560, 0.0000, 0.0000, -19.0000, -1, -1, -1, 400.0, 400.0); //missile_03_SFXR
    tempobjid = CreateDynamicObject(3796, 65.9225, 227.4611, 9.9307, 0.0000, 0.0000, -154.1000, -1, -1, -1, 400.0, 400.0); //acbox1_SFS
    tempobjid = CreateDynamicObject(1712, 58.3166, 235.5281, 9.8500, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kb_couch05
    tempobjid = CreateDynamicObject(1710, 55.3137, 231.2917, 9.7768, 0.7997, 0.0000, 71.4000, -1, -1, -1, 400.0, 400.0); //kb_couch07
    tempobjid = CreateDynamicObject(2631, 58.9309, 232.6649, 9.8169, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //gym_mat1
    tempobjid = CreateDynamicObject(956, 59.6543, 228.0847, 10.0605, -87.8999, 5.3997, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_EXT_CANDY
    tempobjid = CreateDynamicObject(955, 63.5471, 230.9456, 10.2537, 0.0000, 0.0000, -108.1996, -1, -1, -1, 400.0, 400.0); //CJ_EXT_SPRUNK
    tempobjid = CreateDynamicObject(19360, 61.1786, 229.6517, 9.7805, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 61.2055, 229.8833, 9.9231, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(1271, 63.8134, 232.2787, 10.1905, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //gunbox
    tempobjid = CreateDynamicObject(2673, 58.9276, 232.7053, 9.9504, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_5
    tempobjid = CreateDynamicObject(2059, 59.9850, 234.8771, 9.8802, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_GUNSTUFF1
    tempobjid = CreateDynamicObject(2670, 58.4622, 231.5231, 9.9405, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_1
    tempobjid = CreateDynamicObject(2036, 60.2033, 235.6643, 10.4427, 0.0000, -101.5998, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(1271, 62.5634, 228.6183, 10.1702, 0.0000, -90.5000, -45.6999, -1, -1, -1, 400.0, 400.0); //gunbox
    tempobjid = CreateDynamicObject(19360, 54.6263, 234.5144, 9.5331, 0.0000, 0.0000, 161.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 54.5035, 234.5569, 9.7728, 0.0000, 90.0000, 161.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 54.9640, 234.7682, 10.1398, -94.2994, 100.8000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 54.9715, 234.9929, 10.1878, -75.4999, -85.5998, -4.1999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2905, 55.1044, 234.6224, 9.9547, 0.0000, 87.7994, -103.1996, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    //CreateDynamicObject(874, -629.0982, 259.0934, 2.0780, 0.0000, 0.0000, -73.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -620.2180, 261.7174, 2.5641, 0.0000, -7.4998, -73.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -638.4368, 256.3977, 2.0780, 0.0000, 0.0000, -73.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 213.3645, 63.4454, 2.4958, 0.0000, -5.0000, 75.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 349.9089, 113.6807, 4.5685, 0.0000, 0.0000, -64.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 365.5598, 124.7966, 4.8585, 0.0000, 0.0000, -64.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 373.1672, 102.2929, 4.9018, 2.6998, 0.0000, -59.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 407.1307, 129.2716, 6.9573, 1.5999, 0.0000, -48.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 415.1289, 138.6398, 7.4394, -1.1000, 0.0000, 110.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 392.4208, 145.8986, 6.9573, 1.5999, 0.0000, -68.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 401.0317, 153.2747, 7.5194, 1.5999, 0.0000, -62.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 422.9389, 170.7014, 8.7489, 2.5999, 0.0000, -56.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 429.4624, 176.6076, 9.4545, 2.5999, 0.0000, -56.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 441.8373, 157.8401, 9.4545, 2.5999, -3.8998, -56.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 451.3847, 166.0717, 9.9118, 2.5999, -3.8998, -56.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 462.5874, 205.0359, 10.9392, 0.0000, 0.0000, -54.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 468.5267, 211.4010, 10.9392, 0.0000, 0.0000, 124.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 475.1268, 187.5218, 10.9392, 0.0000, 0.0000, -54.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(762, 437.3381, 186.5227, 9.4229, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //new_bushtest
    tempobjid = CreateDynamicObject(800, 397.8489, 124.6875, 5.3435, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(647, 347.8500, 110.2639, 4.8418, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //new_bushsm
    //CreateDynamicObject(874, 283.0317, 69.9589, 2.7030, 0.0000, 7.6999, -79.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 271.8529, 65.6194, 2.6191, 0.0000, 7.6999, -79.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 236.7769, 61.7597, 2.4995, 0.0000, 0.0000, 89.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(800, 265.4136, 61.8008, 1.6423, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(19360, 232.9633, 57.3871, 1.4436, 0.0000, 86.6996, 90.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 232.6681, 57.8171, 1.6928, -85.9000, 0.0000, 171.6999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 232.4978, 57.4664, 1.6174, 0.0000, 95.5998, 175.1000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2905, 232.7061, 57.4486, 1.6375, 0.0000, 95.5998, 175.1000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2036, 231.6215, 57.5376, 1.5312, 0.0000, 0.0000, 124.5000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    //CreateDynamicObject(874, 193.7330, 45.0415, 2.0780, 0.0000, 0.0000, 66.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 182.6221, 47.2486, 2.0780, 0.0000, 0.0000, 66.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, 249.0605, 47.6189, 1.8140, 0.0000, 0.0000, 132.3999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(10985, 301.2221, 43.6286, 1.8954, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    //CreateDynamicObject(874, 204.5319, 65.7957, 2.4958, 0.0000, -5.0000, 75.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 282.3558, 45.3959, 2.4296, 0.0000, 0.0000, -66.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 289.9880, 50.0121, 2.2994, 0.0000, 0.0000, -66.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 337.2131, 76.7656, 3.5501, 2.8998, 0.0000, -56.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 316.9819, 65.1016, 3.1454, 0.0000, 0.0000, 107.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3593, 254.5812, 50.1645, 1.4780, 0.0000, 0.0000, 109.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 308.2749, 71.1772, 2.2892, 0.2998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 305.5917, 71.6567, 2.9119, -15.5999, 0.0000, 96.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 312.1412, 75.8125, 2.2822, 0.0000, 0.0000, -30.2000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, 311.1463, 26.9379, 3.3231, 0.0000, -5.9000, -71.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 345.8598, 72.6259, 3.8492, 2.2999, 0.0000, -133.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 355.2265, 65.0826, 4.2505, 2.2999, 0.0000, -160.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10984, 308.1864, 72.3908, 1.3003, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled01_SFS
    //CreateDynamicObject(874, 299.8739, 51.3773, 2.2994, 0.0000, 0.0000, -66.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 352.0628, 54.7658, 3.8793, 2.2999, 0.0000, -58.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 344.7341, 39.1305, 5.9657, 0.0000, 0.0000, 68.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 332.8145, 29.3619, 6.1795, 0.0000, 0.0000, -51.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 288.4417, 18.4797, 2.4844, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 292.0014, 7.3397, 2.4844, 0.0000, 0.0000, 33.3997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 343.1296, 16.2472, 6.0019, 0.0000, 0.0000, -51.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 350.3709, 24.4608, 6.0019, 0.0000, 0.0000, 122.7994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3283, 303.9801, 46.2858, 0.5084, 6.7999, 0.0000, 101.6996, -1, -1, -1, 400.0, 400.0); //conhoos3
    tempobjid = CreateDynamicObject(1442, 330.5256, 72.3731, 3.1965, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(10985, 307.5520, 46.8786, 1.4155, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(3593, 314.6054, 48.2308, 2.2976, 0.0000, 0.0000, 37.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(1442, 288.2207, 34.9281, 2.1010, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(1756, 285.8828, 31.5184, 1.2632, -12.9996, 0.0000, 24.0998, -1, -1, -1, 400.0, 400.0); //LOW_COUCH_4
    tempobjid = CreateDynamicObject(3594, 289.1567, 29.5699, 2.1538, 0.0000, 0.0000, 122.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, 324.6289, 56.6412, 3.1354, 0.0000, 0.0000, -45.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 338.4212, 61.4272, 3.1696, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(635, 335.0617, 37.9589, 7.7052, 0.0996, -85.1996, -50.1001, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(635, 332.9674, 36.2078, 7.7005, 0.0996, -85.1996, -50.1001, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(635, 330.9960, 34.5592, 7.6960, 0.0996, -85.1996, -50.1001, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(635, 328.8706, 32.7358, 7.7582, 0.0996, -85.1996, -50.1001, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(3172, 355.5874, 32.8903, 5.3038, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(3593, 344.1770, 33.8860, 5.8294, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 350.7044, 24.5244, 5.7909, -0.2000, 0.0000, -127.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(1442, 338.1773, 29.3810, 5.9359, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(636, 310.3239, 16.3719, 4.9425, -1.7000, -83.8000, 104.4000, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(636, 314.7868, 17.4111, 4.9590, 0.1999, -84.3000, 103.4000, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(636, 312.5848, 23.8920, 4.9201, -1.2000, -84.9000, -75.5998, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(635, 309.8569, 23.0569, 5.8961, -0.3000, -86.1996, -76.8999, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(635, 316.6065, 24.6263, 5.8797, -0.3000, -86.1996, -76.8999, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(1440, 312.7683, 16.8010, 3.8287, 0.0000, 0.0000, 11.9996, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(12957, 306.1838, 18.2012, 3.9409, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(1299, 305.8385, 18.7136, 4.2315, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //smashboxpile
    tempobjid = CreateDynamicObject(1442, 324.6091, 68.7490, 3.0799, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(18693, 330.4638, 72.4132, 1.9048, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Flame99
    tempobjid = CreateDynamicObject(18693, 324.5726, 68.7901, 1.7783, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Flame99
    tempobjid = CreateDynamicObject(1369, 289.7604, 35.9859, 2.1201, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_WHEELCHAIR1
    tempobjid = CreateDynamicObject(3005, 310.7286, 16.3078, 3.4058, 0.0000, 0.0000, -82.4999, -1, -1, -1, 400.0, 400.0); //smash_box_stay
    tempobjid = CreateDynamicObject(3035, 334.9653, 29.9610, 6.0475, 0.0000, 0.0000, 40.0998, -1, -1, -1, 400.0, 400.0); //tmp_bin
    tempobjid = CreateDynamicObject(2840, 336.1625, 31.0358, 5.3393, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //GB_takeaway05
    tempobjid = CreateDynamicObject(1327, 327.5382, 56.5946, 3.0940, 0.0000, -15.1997, -32.0000, -1, -1, -1, 400.0, 400.0); //junk_tyre
    tempobjid = CreateDynamicObject(1328, 319.2532, 49.0839, 2.5922, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1328, 319.6632, 48.0065, 2.2314, 92.0998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(849, 313.0902, 51.1473, 2.1765, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1265, 316.0390, 52.6230, 2.4586, 0.0000, 0.0000, -139.6999, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, 316.2814, 53.1039, 2.2716, 0.0000, -24.5000, -139.6999, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(636, 340.5032, 65.7901, 4.1132, -1.5000, -84.4999, 34.7999, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(635, 341.9118, 69.3524, 4.9836, -0.8999, -85.7994, -54.3997, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(1328, 342.8334, 65.3694, 3.4191, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1328, 343.5332, 65.7891, 3.4191, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1328, 342.8887, 66.4692, 2.9282, 0.0000, -86.7994, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(2673, 341.9012, 65.9868, 2.9765, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_5
    tempobjid = CreateDynamicObject(635, 319.7319, 57.7122, 4.7241, 0.0000, -85.0998, -36.3997, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(635, 321.4230, 59.9193, 4.7396, -0.3000, -85.0998, -36.3997, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(10985, 2181.6784, -693.7694, 46.6040, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10985, 2185.9450, -690.5554, 46.6040, 0.0000, 0.0000, 135.6000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(3593, 1133.6999, 415.9873, 26.2453, -1.7000, 0.0000, -130.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, 976.7836, 418.2507, 19.8903, 0.0000, 0.0000, 129.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10985, 992.1834, 409.9147, 19.3029, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10986, 983.2374, 410.8344, 18.0428, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled03_SFS
    //CreateDynamicObject(874, 969.3737, 409.8768, 19.8903, 0.0000, 0.0000, 129.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 983.7777, 392.5267, 19.8903, 0.0000, 0.0000, 129.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 995.0582, 401.2615, 19.8903, 0.0000, 0.0000, -55.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 983.5640, 432.5816, 20.0590, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1008.6232, 415.8338, 20.4983, 0.0000, 0.0000, -41.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1238, 965.5034, 397.8984, 19.1576, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //trafficcone
    tempobjid = CreateDynamicObject(1238, 970.2937, 394.2922, 18.9347, -104.1996, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //trafficcone
    //CreateDynamicObject(874, 947.8020, 361.9700, 20.1012, 0.0000, 0.0000, -90.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 933.2525, 384.6353, 20.1012, 0.0000, 0.0000, -83.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 921.6472, 380.3591, 20.1012, 0.0000, 0.0000, 108.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 923.2133, 351.1198, 21.3106, -5.4000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1028.5533, 458.4096, 20.2886, 0.0000, 0.0000, -50.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1001.0335, 458.9218, 19.8826, 0.0000, 0.0000, -35.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1003.0194, 467.8218, 19.8826, 0.0000, 0.0000, 143.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1040.8850, 488.2677, 19.8826, 0.0000, 0.0000, -25.7000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1228, 973.6436, 390.7763, 19.2539, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //roadworkbarrier1
    tempobjid = CreateDynamicObject(1228, 967.9412, 394.9494, 19.2938, 0.0000, 0.0000, 125.0000, -1, -1, -1, 400.0, 400.0); //roadworkbarrier1
    tempobjid = CreateDynamicObject(1228, 963.2435, 395.5975, 19.0191, 0.0000, 102.4000, 0.0000, -1, -1, -1, 400.0, 400.0); //roadworkbarrier1
    //CreateDynamicObject(874, 967.7619, 375.3179, 19.9239, 0.0000, 0.0000, -70.1996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1228, 1002.3806, 431.9526, 19.0358, 0.0000, -97.4000, 48.9000, -1, -1, -1, 400.0, 400.0); //roadworkbarrier1
    tempobjid = CreateDynamicObject(3594, 998.3900, 434.2478, 19.3514, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(825, 1014.3048, 437.9194, 19.7343, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(3593, 1001.4785, 437.0115, 19.6254, -7.8997, 0.0000, -63.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, 1040.6059, 455.4248, 20.5286, 0.0000, 0.0000, -118.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1052.1634, 478.6940, 20.2886, 0.0000, 0.0000, -127.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1484, 986.6685, 431.8792, 22.1802, 0.0000, -58.4000, 0.6998, -1, -1, -1, 400.0, 400.0); //CJ_BEAR_BOTTLE
    tempobjid = CreateDynamicObject(639, 988.9140, 397.0596, 29.4636, 0.0000, 0.0000, 145.7998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1002.4276, 416.7481, 29.4636, 0.0000, 0.0000, 145.7998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3168, 987.4357, 433.0675, 19.0557, 0.0000, 0.5999, -22.8999, -1, -1, -1, 400.0, 400.0); //trailer2_01
    tempobjid = CreateDynamicObject(639, 1005.5972, 421.3410, 29.4636, 0.0000, 0.0000, 145.7998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1017.5036, 440.2221, 29.4636, 0.0000, 0.0000, 155.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1026.0875, 458.9707, 29.2537, 0.0000, 0.0000, 155.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(692, 988.0946, 430.8452, 19.5548, 0.0000, 0.8999, -16.8999, -1, -1, -1, 400.0, 400.0); //sm_des_bush1
    tempobjid = CreateDynamicObject(639, 1020.3253, 449.3547, 29.2537, 0.0000, 0.0000, -25.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1009.5349, 429.2478, 29.2537, 0.0000, 0.0000, -34.2000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 997.0999, 411.0751, 29.3537, 0.0000, 0.0000, -34.7000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1031.4232, 462.2427, 29.1851, 2.7999, 0.0000, -113.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1044.2602, 456.4851, 29.9932, 2.7999, 0.0000, -114.9000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(1428, 990.6677, 435.9107, 20.7423, 0.0000, 0.0000, 63.5998, -1, -1, -1, 400.0, 400.0); //DYN_LADDER
    tempobjid = CreateDynamicObject(639, 1058.9527, 449.7311, 30.7842, 2.7999, 0.0000, -114.9000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1069.0039, 444.2528, 31.6266, 7.3997, 0.0000, -119.9000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(1721, 986.6632, 431.5068, 22.1909, 0.0000, 0.0000, -111.0998, -1, -1, -1, 400.0, 400.0); //est_chair1
    tempobjid = CreateDynamicObject(349, 987.2924, 431.3226, 22.2574, -87.6996, -11.8999, 4.8997, -1, -1, -1, 400.0, 400.0); //chromegun
    tempobjid = CreateDynamicObject(19317, 993.7753, 437.5455, 19.2800, -66.5998, 0.2998, 61.0000, -1, -1, -1, 400.0, 400.0); //bassguitar01
    //CreateDynamicObject(874, 1088.2611, 459.7608, 23.1347, -4.1999, 0.0000, 55.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 1085.4399, 434.6281, 33.6567, 7.3997, 0.0000, -119.9000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1090.5289, 431.7015, 34.2681, 3.7999, 0.0000, -119.9000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 1008.4085, 479.4129, 19.6175, 0.0000, 1.4996, 151.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1013.6773, 489.1159, 19.6175, 0.0000, 1.4996, 127.1996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 1095.1324, 427.4667, 34.6884, -6.6999, 0.0000, 59.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1109.6815, 421.6264, 34.6781, -2.5000, 0.0000, -110.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1078.5118, 437.2780, 32.7937, -6.6999, 0.0000, 59.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1049.8365, 452.4981, 30.2817, -3.1998, 0.0000, 65.7994, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1037.3304, 458.2832, 29.5111, -3.1998, 0.0000, 65.7994, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1140.0709, 410.5693, 34.1444, 1.1999, 0.0000, -110.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 1018.2987, 497.5187, 19.6033, 0.0000, 1.4996, 150.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 1129.1582, 414.6488, 34.0903, 1.3997, 0.0000, 70.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1154.3028, 401.7604, 33.8124, -3.7000, 0.0000, -142.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 1024.1368, 507.7966, 19.6033, 0.0000, 1.4996, 126.7001, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 1157.7363, 397.2874, 33.4477, -3.7000, 0.0000, -142.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1172.6051, 377.1560, 31.2884, -3.7000, 0.0000, -142.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1176.6534, 369.9739, 30.7611, 4.1999, 0.0000, 35.6996, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1186.5152, 365.4822, 30.0412, 1.8997, 0.0000, 85.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 988.7807, 432.6043, 20.1326, 0.0000, 0.0000, 156.8000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1208.7884, 363.7882, 29.3001, 1.8997, 0.0000, 85.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1225.2025, 362.5454, 28.7541, 1.8997, 0.0000, 85.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1198.6009, 365.6918, 29.6965, -1.1999, 0.0000, -94.9000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1217.7546, 364.3912, 29.2346, -1.1999, 0.0000, -94.9000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 1075.0030, 440.6130, 23.1347, -5.2999, 0.0000, 55.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1091.3099, 429.1853, 25.1308, 6.5998, 0.0000, -134.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1127.7580, 430.1968, 26.8840, 0.0000, 0.0000, 51.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1113.9233, 413.0523, 26.8840, 0.0000, 0.0000, 45.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1149.3603, 412.4302, 26.2341, 5.0998, 0.0000, 45.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1159.5432, 401.5791, 24.9043, -4.8997, 0.0000, -136.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1142.4964, 385.0700, 25.3027, -4.8997, 0.0000, -136.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1169.1357, 368.2355, 22.3724, 6.6999, 0.0000, 42.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1180.7735, 362.5639, 20.9596, 6.6999, 0.0000, 42.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1201.1118, 381.1043, 20.7411, 6.6999, 0.0000, 42.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3593, 1038.0511, 499.3340, 19.3229, 0.4999, -0.8999, -27.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1126.2950, 423.0357, 26.5251, 0.0000, 0.0000, -141.6999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, 1057.1357, 448.9956, 21.2632, 5.8000, 0.0000, -118.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1065.4670, 474.3417, 21.2502, 18.6998, -5.0998, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1047.4283, 456.4201, 20.2077, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(3594, 1056.4217, 462.6943, 20.0379, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1058.8286, 460.8297, 20.5631, 4.1999, 0.0000, 74.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(849, 1057.9864, 464.2882, 19.8262, -3.0000, 0.6998, 76.4999, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    //CreateDynamicObject(874, 1028.6977, 519.4887, 20.0279, 0.0000, 1.4996, 153.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1036.1894, 530.5794, 19.9780, 0.0000, 1.4996, -43.2998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1065.7440, 533.0208, 19.8826, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1059.5506, 513.2343, 21.1002, -1.0999, -9.6997, -34.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1063.0067, 524.2678, 20.3099, -1.0999, -9.6997, -34.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1021.3615, 501.9837, 19.8826, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1055.0117, 515.8742, 19.8826, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    //CreateDynamicObject(874, 1041.8509, 540.5515, 20.0492, 0.0000, 1.4996, -43.2998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1047.8016, 549.8109, 20.1021, 0.0000, 1.4996, -43.2998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1052.7950, 558.0288, 20.0625, 0.0000, 1.4996, 124.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(18248, 982.5579, 410.8287, 26.8257, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cuntwjunk01
    //CreateDynamicObject(874, 1082.0876, 551.0501, 19.8826, 0.0000, 0.0000, -49.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1090.0146, 560.1193, 19.8826, 0.0000, 0.0000, 107.1996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1115.3266, 562.5355, 19.8826, 0.0000, 0.0000, 52.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1127.5511, 556.0750, 19.8826, 0.0000, 0.0000, -112.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1147.2248, 547.2985, 19.8826, 0.0000, 0.0000, -112.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1156.2469, 569.5166, 19.8826, 0.0000, 0.0000, -112.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1162.6125, 565.9328, 19.8826, 0.0000, 0.0000, 54.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1156.5163, 544.3062, 19.8826, 0.0000, 0.0000, 68.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1178.9525, 534.5850, 19.8826, 0.0000, 0.0000, 50.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1204.6511, 546.5982, 19.8826, 0.0000, 0.0000, 61.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3381, -215.9337, 382.3240, -32.0213, 7.7999, 83.5998, 33.2000, -1, -1, -1, 400.0, 400.0); //cxrf_redarch
    SetDynamicObjectMaterial(tempobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
    SetDynamicObjectMaterial(tempobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
    //CreateDynamicObject(874, 1226.0937, 533.5656, 19.8826, 0.0000, 0.0000, -135.1997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1209.9864, 517.5709, 19.8826, 0.0000, 0.0000, -119.3998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1235.4245, 504.8439, 19.8826, 0.0000, 0.0000, -119.3998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1259.4669, 517.9146, 19.8826, 0.0000, 0.0000, -119.3998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1270.4969, 514.8048, 19.8826, 0.0000, 0.0000, 270.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1290.9250, 502.1408, 19.8826, 0.0000, 0.0000, -119.3998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1300.2314, 498.9165, 19.8826, 0.0000, 0.0000, 59.6001, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1279.4338, 481.7456, 19.8826, 0.0000, 0.0000, -119.3998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(11088, 1177.6202, 506.8905, 24.5303, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CF_ext_dem_SFS
    tempobjid = CreateDynamicObject(672, 1196.3205, 523.7661, 19.6105, 0.0000, 0.0000, -30.2000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree5
    tempobjid = CreateDynamicObject(10985, 1204.0311, 494.1004, 18.7420, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10985, 1160.1263, 535.5520, 19.7693, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    //CreateDynamicObject(874, 1145.7651, 537.8137, 19.8826, 0.0000, 0.0000, -27.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10985, 1182.8536, 502.3432, 19.4712, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10985, 1156.5040, 505.9934, 18.7212, 0.0000, 0.0000, -66.4999, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10985, 1182.1230, 516.8651, 18.9743, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10985, 1200.0212, 473.3428, 18.8999, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10985, 1180.2076, 471.1947, 20.0536, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10984, 1154.9820, 536.0888, 19.2238, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled01_SFS
    //CreateDynamicObject(874, 1148.4105, 516.6043, 19.8826, 0.0000, 0.0000, -27.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1147.5870, 495.8673, 20.5575, -7.0998, 0.0000, -11.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1145.0052, 483.6188, 22.9731, -7.0998, 0.0000, -11.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1161.7102, 478.3731, 22.6061, 7.0998, 11.1997, 93.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1161.2832, 483.5563, 21.5846, -2.2999, 20.8999, 56.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1169.1711, 466.8623, 23.6865, 3.0000, 12.7999, 69.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1180.7043, 462.6022, 23.2569, 3.0000, 12.7999, 69.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1211.9698, 507.7648, 19.6214, 3.8998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1214.3902, 489.3272, 19.2649, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10985, 1200.0212, 483.7626, 18.7500, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(825, 1206.8281, 521.6433, 19.5228, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    //CreateDynamicObject(874, 1214.3902, 460.5354, 19.8822, -5.3997, 4.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1130.0915, 536.5401, 20.0228, 0.0000, 0.0000, 28.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1137.0498, 523.6710, 20.0228, 0.0000, 0.0000, 28.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1171.1584, 523.4661, 19.3127, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1154.9012, 547.8881, 19.8826, 0.0000, 0.0000, 26.0998, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1149.3424, 525.0421, 19.6972, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1142.4144, 505.6473, 18.9867, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1210.7131, 471.6022, 18.3903, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1219.5384, 512.4464, 19.8143, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(639, 1168.8502, 520.9824, 22.7187, 0.0000, 0.0000, 179.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(688, 1146.8000, 506.2207, 17.9377, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_fir_scabg
    tempobjid = CreateDynamicObject(688, 1219.4698, 485.8121, 16.6077, 0.0000, 0.0000, -62.0000, -1, -1, -1, 400.0, 400.0); //sm_fir_scabg
    tempobjid = CreateDynamicObject(1712, 1205.0754, 504.8208, 19.1900, 0.0000, 0.0000, -140.5000, -1, -1, -1, 400.0, 400.0); //kb_couch05
    tempobjid = CreateDynamicObject(688, 1216.9514, 473.6791, 16.6077, 0.0000, 0.0000, -131.1000, -1, -1, -1, 400.0, 400.0); //sm_fir_scabg
    tempobjid = CreateDynamicObject(1415, 1198.6518, 504.5523, 19.1086, 0.0000, 0.0000, 178.3000, -1, -1, -1, 400.0, 400.0); //DYN_DUMPSTER
    tempobjid = CreateDynamicObject(635, 1164.7595, 538.7636, 24.2282, -0.6998, -87.1996, -90.0000, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(639, 1168.8857, 526.0526, 22.7187, 0.0000, 0.0000, 179.5997, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(636, 1168.7934, 537.3739, 23.2574, 0.2000, -92.4999, 179.9002, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(19360, 1176.8979, 504.9421, 19.1065, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(14861, 1204.0400, 510.1293, 19.5715, 0.0000, 0.0000, 91.9999, -1, -1, -1, 400.0, 400.0); //choochie-bed
    tempobjid = CreateDynamicObject(2370, 1200.6566, 504.1087, 19.0806, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Shop_set_1_Table
    tempobjid = CreateDynamicObject(635, 1167.3690, 538.7636, 24.1963, -0.6998, -87.1996, -90.0000, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(19942, 1201.0185, 505.0733, 19.9666, -91.7994, 1.8997, -94.0000, -1, -1, -1, 400.0, 400.0); //PoliceRadio1
    tempobjid = CreateDynamicObject(2907, 1176.7065, 504.7903, 19.2691, 0.0000, 0.0000, -39.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 1176.3502, 504.3731, 19.2035, 15.1997, 0.0000, -31.2000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(19360, 1201.4880, 491.8710, 19.1065, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2906, 1201.4956, 492.5397, 19.2770, 0.0000, -86.7994, 146.1999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2907, 1201.6844, 493.0682, 19.2129, -11.5000, -176.5000, -34.4000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(346, 1201.4079, 504.7272, 19.9864, -90.0000, 1.7000, 0.7997, -1, -1, -1, 400.0, 400.0); //colt45
    tempobjid = CreateDynamicObject(2908, 1201.1716, 492.0227, 19.2122, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(18641, 1201.2563, 504.4949, 19.9566, 92.4000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //Flashlight1
    tempobjid = CreateDynamicObject(2850, 1200.7110, 504.7705, 19.9864, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //GB_kitchdirt04
    tempobjid = CreateDynamicObject(3594, 1124.0456, 569.5250, 19.3714, 0.0000, 0.0000, 87.6996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(825, 1111.1778, 565.4580, 19.6128, 0.0000, 0.0000, -42.5998, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1148.2358, 571.3308, 19.6627, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1200.0196, 545.5728, 19.8826, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1253.5052, 518.4769, 19.8826, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1274.2899, 488.0346, 19.8826, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(19360, 1201.2253, 488.2705, 19.0424, 0.0000, 0.0000, 90.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(639, 1153.7768, 535.8560, 22.7343, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1153.7768, 520.7653, 22.7343, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1171.6666, 517.9744, 26.9074, 0.0000, 0.0000, 270.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1177.1861, 517.9744, 26.9074, 0.0000, 0.0000, 270.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1203.2849, 517.9061, 26.9111, 0.0000, 0.0000, 270.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1199.9156, 472.9085, 26.9465, 0.0000, 0.0000, 90.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1203.2347, 472.9085, 26.9465, 0.0000, 0.0000, 90.0000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(19360, 1200.1606, 488.2590, 21.1564, 43.2000, 0.0000, 90.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterialText(tempobjid, 0, "Souls were lost..", OBJECT_MATERIAL_SIZE_256x128, "Segoe Print", 40, 1, 0xFF8B0000, 0x00000000, 0);
    tempobjid = CreateDynamicObject(19360, 1201.2253, 489.2301, 19.1025, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 1201.4737, 488.9071, 19.2150, 0.0000, 0.0000, -65.5000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2036, 1201.1623, 488.4778, 19.7306, 9.8000, -81.0000, -66.7994, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(14861, 1204.0400, 510.1293, 19.5715, 0.0000, 0.0000, 91.9999, -1, -1, -1, 400.0, 400.0); //choochie-bed
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 1203.4211, 510.1250, 19.8854, 0.0000, 0.0000, 34.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, 1203.1086, 511.0603, 19.5298, -63.5998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(19360, 1203.8702, 509.9743, 19.1130, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 1204.2027, 504.9371, 19.1130, 0.0000, 90.0000, 26.1000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, 1200.2790, 504.3352, 19.1030, 0.0000, 90.0000, 90.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19367, 1205.6728, 513.1577, 20.9666, 16.3999, -0.1000, -0.7997, -1, -1, -1, 400.0, 400.0); //wall015
    SetDynamicObjectMaterialText(tempobjid, 0, "NO HOPE RUN", OBJECT_MATERIAL_SIZE_256x128, "Segoe Script", 35, 1, 0xFF8B0000, 0x00000000, 0);
    tempobjid = CreateDynamicObject(3593, 1130.6999, 567.1306, 19.3330, 0.0000, 0.0000, 68.9000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1136.7263, 563.0958, 19.4113, 0.0000, 0.0000, 57.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, 1134.3717, 565.9179, 19.0727, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(3593, 1124.0520, 566.5244, 19.2530, 0.0000, 0.0000, -86.6996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1083.3297, 572.5642, 19.4414, 0.0000, 0.0000, -29.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1078.6981, 571.7852, 19.6872, 4.5998, 0.0000, -97.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(849, 1080.6589, 571.6914, 19.1413, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(19420, 1083.4670, 572.9113, 20.0428, 0.0000, 0.0000, -30.5000, -1, -1, -1, 400.0, 400.0); //police_lights02
    tempobjid = CreateDynamicObject(3380, 1190.3664, 547.7545, 19.0421, -20.6998, -29.8999, 60.4999, -1, -1, -1, 400.0, 400.0); //CE_hairpinL
    tempobjid = CreateDynamicObject(3594, 1193.4814, 546.4779, 19.5214, 0.0000, 0.0000, -111.6996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1220.0860, 521.0767, 19.3530, 0.0000, 0.0000, 73.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1226.4361, 517.0087, 19.4514, 0.0000, 3.5000, 69.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1272.3891, 502.7395, 19.3006, 0.0000, 0.0000, 68.6996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1277.5494, 499.0555, 19.6678, -7.2999, 0.0000, -129.6000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1313.6883, 471.5581, 19.4493, 0.0000, 2.5000, 64.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1320.1252, 468.5195, 19.3605, 0.0000, 2.0999, 67.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(1294, 1318.7309, 482.5581, 23.1797, -19.4999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //mlamppost
    tempobjid = CreateDynamicObject(16304, 1321.3802, 482.0971, 17.4650, 7.3997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //des_gravelpile05
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    tempobjid = CreateDynamicObject(3594, 1319.4079, 477.7001, 19.4242, -3.7000, 0.0000, 164.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1322.3354, 473.9945, 19.5508, 4.4000, 0.0000, 60.7999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, 1319.3039, 490.2781, 19.8826, 0.0000, 0.0000, 77.7994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1315.0649, 465.0765, 19.8826, 0.0000, 0.0000, 38.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1331.1667, 481.9226, 19.8826, 0.0000, 0.0000, 57.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1343.0322, 481.0090, 19.8826, 0.0000, 0.0000, 142.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1332.4344, 456.7658, 19.8826, 0.0000, -3.8998, 48.5998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1331.4056, 458.5708, 19.6326, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1338.6080, 478.6440, 19.8122, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1305.3247, 491.5234, 19.7842, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1291.3238, 471.5003, 19.1956, 6.2999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    //CreateDynamicObject(874, 1280.6439, 461.8406, 18.9930, 0.0000, 0.0000, -52.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1289.8481, 466.8738, 18.9930, 0.0000, 0.0000, -89.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19360, 1224.3928, 519.8554, 18.8027, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 1224.5467, 519.8297, 18.9412, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 1224.8133, 519.7446, 18.9027, 0.0000, 0.0000, -29.2000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2905, 1224.4715, 520.5601, 18.9911, 0.0000, 88.3999, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(19360, 1130.7187, 565.1920, 18.8027, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 1130.4433, 564.7083, 18.9454, 0.0000, 0.0000, 80.4999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 1130.5472, 564.9528, 18.9069, 0.0000, 0.0000, 54.5000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(3566, 1175.3055, 530.9495, 21.2702, 0.0000, 0.0000, -166.1999, -1, -1, -1, 400.0, 400.0); //lasntrk1
    tempobjid = CreateDynamicObject(10771, 50.3865, 243.5343, 5.2097, 0.0000, 0.0000, -19.0000, -1, -1, -1, 400.0, 400.0); //CARRIER_HULL_SFSe
    tempobjid = CreateDynamicObject(13296, 1378.4709, 474.0263, 20.6865, 6.4998, -6.3000, 0.0000, -1, -1, -1, 400.0, 400.0); //CE_roadsidegas
    tempobjid = CreateDynamicObject(10985, 1369.0267, 477.6216, 19.6184, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10984, 1390.2302, 477.6539, 19.9538, -1.1999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled01_SFS
    tempobjid = CreateDynamicObject(10986, 1375.3503, 466.3272, 18.5662, -9.4996, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled03_SFS
    //CreateDynamicObject(874, 1360.2176, 493.5046, 19.7423, 0.0000, 0.0000, 62.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1441.5084, 423.5469, 19.8826, 0.0000, 0.0000, -21.1998, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(18716, 1390.8309, 471.2210, 15.9151, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //prt_smoke_expand
    tempobjid = CreateDynamicObject(10984, 1387.5240, 470.5827, 19.9538, 0.0000, 0.0000, -63.2999, -1, -1, -1, 400.0, 400.0); //rubbled01_SFS
    //CreateDynamicObject(874, 1347.1699, 490.6159, 19.8826, 0.0000, 0.0000, 142.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1374.1141, 487.1748, 19.7423, 0.0000, 0.0000, -121.1996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1385.8514, 485.4508, 19.4722, -1.2000, 0.0000, -54.7000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1410.9842, 472.6328, 20.0517, 0.0000, 0.0000, 48.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1420.9753, 453.3918, 19.4517, 0.0000, 0.0000, -7.6999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1416.9604, 441.5072, 19.4517, 0.0000, 0.0000, 132.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1406.5544, 457.1133, 20.1431, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1402.9305, 463.1885, 20.1434, 0.0000, 0.0000, -70.4000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1407.6202, 450.0187, 20.1434, 0.0000, 0.0000, -173.8999, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(3593, 1354.9073, 472.9974, 19.6375, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(639, 1286.1617, 485.4605, 29.4605, 0.0000, 0.0000, -101.4000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1314.1783, 479.4544, 29.4605, 0.0000, 0.0000, -101.4000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1297.3913, 481.7196, 29.4605, 0.0000, 0.0000, 78.9999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1322.5029, 476.3702, 29.4605, 0.0000, 0.0000, 78.9999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1337.1998, 472.1806, 29.1912, 0.0000, 0.0000, 64.1996, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1354.0528, 464.4667, 29.1912, 0.0000, 0.0000, 64.7994, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1366.2093, 458.8344, 29.1912, 0.0000, 0.0000, 66.0998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1348.1069, 468.6000, 29.2112, 0.0000, 0.0000, -114.3000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1361.1302, 462.5982, 29.2112, 0.0000, 0.0000, -114.3000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1376.6662, 455.1690, 29.2112, 0.0000, 0.0000, -117.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1393.9901, 446.1509, 29.2112, 0.0000, 0.0000, -117.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1410.4433, 437.5407, 29.2112, 0.0000, 0.0000, -117.5000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1385.0979, 449.2593, 29.2112, 0.0000, 0.0000, 62.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1403.7065, 439.5686, 29.2112, 0.0000, 0.0000, 62.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1417.9719, 432.3074, 29.0611, 0.0000, 0.0000, -134.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1431.3321, 419.0812, 28.9111, 0.0000, 0.0000, -135.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1442.8695, 407.5101, 28.8612, 0.0000, 0.0000, -135.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1421.8669, 426.7648, 29.0611, 0.0000, 0.0000, 45.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1435.6849, 413.0906, 28.7511, 0.5999, 0.0000, 45.2999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3594, 1358.8745, 473.8522, 19.6928, 0.0000, 0.0000, -141.6000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(849, 1356.8144, 473.7467, 19.3598, 0.4999, 0.0000, 95.0998, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(3594, 1358.5461, 469.3840, 19.8609, -8.1997, 0.0000, -115.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    //CreateDynamicObject(874, 1355.7335, 437.2408, 19.8712, 0.0000, 0.0000, 156.8999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1437.9448, 428.5671, 19.8903, 0.0000, 0.0000, 65.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1462.7950, 415.8514, 19.8903, 0.0000, 0.0000, -123.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1480.5295, 414.2094, 19.8903, 0.0000, 0.0000, -36.7000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1509.8879, 402.8276, 20.1828, 0.0000, 0.0000, 82.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1533.6772, 399.6535, 20.1828, 0.0000, 0.0000, 59.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1561.6440, 395.0234, 19.8826, 0.0000, 0.0000, -105.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(826, 1380.4892, 454.3070, 19.2133, 0.0000, 0.0000, 38.8997, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass10
    //CreateDynamicObject(874, 1622.5078, 393.3652, 19.4762, 0.0000, -3.2000, -105.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1566.8155, 370.7267, 20.1471, 0.0000, 0.0996, -94.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1556.0052, 369.6174, 20.1436, 0.0000, 0.0996, -94.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1532.7773, 374.0130, 20.0391, 0.0000, -1.2000, 68.1996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1505.6617, 411.3468, 19.9643, 0.0000, 0.0000, 178.0997, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(800, 1548.4863, 374.1520, 19.4027, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    //CreateDynamicObject(874, 1661.1827, 397.7911, 20.0557, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1466.7486, 433.0804, 20.1550, 0.0000, 0.0000, -86.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1449.2954, 444.2181, 19.9717, 0.0000, 0.0000, 80.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(800, 1594.6925, 392.5993, 19.4143, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(19360, 1386.2065, 448.6011, 18.7949, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 1385.7131, 448.5426, 18.9664, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 1386.9217, 447.4478, 18.8999, 0.0000, 0.0000, 23.1000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(1442, 1200.2695, 508.0621, 19.7395, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(1442, 1191.5759, 494.6408, 19.7096, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(3594, 1405.8492, 433.0686, 19.4601, 0.0000, 0.0000, -127.9000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1404.4010, 439.3750, 19.5503, 2.1998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1401.0195, 436.4346, 19.8647, -9.3999, 0.0000, 76.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, 1423.4957, 420.9406, 19.5809, 0.0000, 0.0000, 57.9999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3594, 1456.1383, 404.3529, 19.4214, 0.0000, 0.0000, 74.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1462.8736, 401.5921, 19.3707, 0.0000, 0.0000, 65.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1469.5792, 398.6286, 19.4113, 0.0000, 0.0000, 66.2994, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1510.0766, 392.5697, 19.3530, 0.0000, 0.0000, 57.1999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1550.0631, 379.2318, 19.4813, 0.0000, 2.6998, 55.7999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, 1544.7163, 382.3869, 19.4834, 0.0000, 0.0000, 82.8999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, 1540.4427, 383.5267, 19.5037, -5.4998, 0.0000, 80.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1585.6402, 386.2875, 19.4314, 0.0000, 0.0000, -85.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1592.4880, 384.4963, 19.3729, 0.0000, 0.0000, 67.7994, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1635.7928, 384.7962, 19.4260, 0.0000, 0.0000, -84.2994, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 1640.9803, 384.9642, 19.7234, -8.0999, 0.0000, -88.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1647.3790, 382.1101, 19.2590, 0.0000, 0.0000, 61.3997, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(762, 1629.9034, 399.1488, 19.8826, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //new_bushtest
    tempobjid = CreateDynamicObject(928, 1419.0898, 423.2857, 19.1308, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //RUBBISH_BOX1
    tempobjid = CreateDynamicObject(19360, 1513.9945, 390.5422, 18.8127, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 1513.9238, 390.2229, 18.9953, 0.0000, 0.0000, 133.1000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 1514.3210, 390.2774, 18.9368, 0.0000, 0.0000, -64.4000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, 1514.4350, 390.5469, 18.9186, 0.0000, 0.0000, 104.9999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2036, 1512.4195, 389.8771, 19.4696, 0.0000, -98.6996, -38.5998, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(1220, 1422.5273, 421.8916, 19.7838, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox2
    tempobjid = CreateDynamicObject(1220, 1420.7397, 423.1871, 19.1956, 0.0000, 89.8000, 0.0000, -1, -1, -1, 400.0, 400.0); //cardboardbox2
    tempobjid = CreateDynamicObject(10985, 1696.5521, 415.7789, 19.3780, -0.2000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    tempobjid = CreateDynamicObject(2670, 1420.3918, 423.0184, 18.9664, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_1
    tempobjid = CreateDynamicObject(849, 1425.1894, 418.5360, 19.0890, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, 1401.8099, 434.8572, 19.1368, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(639, 1450.6252, 401.8833, 28.7212, 1.0000, 0.0000, -108.6996, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1464.7580, 396.9934, 28.7623, -0.8999, 0.0000, -108.9999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1484.2181, 390.2290, 28.6317, -0.2000, 0.0000, -109.3999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1475.9780, 391.7538, 28.7159, 0.3998, 0.0000, 70.2001, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1457.8177, 398.1216, 28.5603, 0.3998, 0.0000, 71.5998, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1496.7618, 387.1794, 28.7567, 0.1999, 0.0000, -98.9999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1523.1114, 382.7424, 28.8600, 0.1999, 0.0000, -98.9999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1545.1263, 379.1241, 29.0778, 0.1999, 0.0000, -98.9999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1532.6274, 379.9060, 28.9955, 0.1999, 0.0000, 81.6996, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1511.8746, 383.3880, 28.8889, 0.1999, 0.0000, 81.3000, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(10985, 1707.9521, 411.6292, 19.3924, -0.2000, 0.0000, -45.5998, -1, -1, -1, 400.0, 400.0); //rubbled02_SFS
    //CreateDynamicObject(874, 1682.5686, 422.7390, 19.0981, 0.0000, 0.0000, 62.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1673.2501, 425.9100, 19.0981, -2.5999, 3.2000, 62.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, 1640.5063, 381.0585, 19.5097, 0.0000, 0.0000, -142.8999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(19360, 1698.0633, 410.0491, 19.1504, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(10984, 1704.0101, 415.4743, 19.4333, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled01_SFS
    tempobjid = CreateDynamicObject(825, 1688.0289, 416.1853, 19.4713, -1.0999, 0.0000, -45.9999, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 1710.9560, 406.0155, 19.8027, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(639, 1683.4747, 415.2669, 26.4545, 0.0000, 20.3999, 71.4999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1698.1920, 410.3421, 26.4545, 0.0000, 20.3999, 71.4999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 1703.5786, 408.5397, 26.4545, 0.0000, 20.3999, 71.4999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(815, 1673.1135, 423.6777, 18.0949, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush19
    tempobjid = CreateDynamicObject(825, 1676.8819, 419.4028, 19.5958, 0.0000, 0.0000, 104.4000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(2908, 1697.3823, 409.5935, 19.2455, 0.0000, 0.0000, -44.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2907, 1697.9200, 410.0292, 19.2373, 0.0000, -179.9001, -36.8997, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, 1697.5117, 409.8594, 19.2772, 0.0000, 0.0000, 130.0997, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(849, 1637.4858, 383.1441, 19.0811, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1271, 1640.8061, 380.8666, 19.7164, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //gunbox
    tempobjid = CreateDynamicObject(1271, 1640.8061, 379.6267, 19.7164, 0.0000, 0.0000, -71.3999, -1, -1, -1, 400.0, 400.0); //gunbox
    tempobjid = CreateDynamicObject(849, 1643.2452, 383.2207, 19.0389, 0.0000, 0.0000, -29.3999, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(1450, 1647.3989, 384.3554, 19.3546, 0.0000, 0.0000, 157.1999, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(19360, 1644.1903, 381.8193, 18.7068, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 1643.3752, 381.2124, 18.8514, 0.0000, 0.0000, 61.4999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, 1643.8320, 380.9689, 18.8243, 3.2999, 0.0000, 69.6996, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2906, 1643.5969, 380.8168, 18.8122, 0.0000, 0.0000, -142.1999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(849, 1547.9858, 382.5964, 19.1527, -1.7000, 0.0000, -92.3999, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(825, 1414.4925, 436.6069, 19.8903, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(849, 1321.2462, 476.1625, 19.0928, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(800, 1269.5583, 510.1354, 19.1427, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(849, 1125.3524, 568.0562, 19.1226, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(12957, 1169.0559, 378.2066, 21.9353, 3.5999, 5.7999, 0.0000, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, 1165.0373, 379.8611, 22.4496, 0.0996, 0.0000, 83.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 1199.8519, 369.1044, 19.3066, -3.7999, 0.0000, -110.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 1194.0439, 372.5310, 19.6354, 2.7999, -2.4000, 93.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(19420, 1200.0107, 368.9974, 19.9388, 0.0000, 0.0000, 63.2999, -1, -1, -1, 400.0, 400.0); //police_lights02
    tempobjid = CreateDynamicObject(19360, 1196.3553, 370.4729, 18.9102, 1.3997, 93.0998, -0.7997, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, 1196.0797, 370.7734, 19.0839, -2.3998, 0.0000, -49.9000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(800, 1192.5061, 382.6968, 20.4302, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(849, 1167.4591, 378.1445, 21.8104, 3.0999, 0.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(800, 1153.5489, 380.5551, 23.6215, 0.0000, -6.8000, -24.7000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(825, -870.4718, -40.5828, 38.9053, 5.2999, -6.9998, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(672, 1041.6186, 487.5653, 19.7915, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree5
    tempobjid = CreateDynamicObject(760, 1073.8774, 445.7998, 21.5230, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_bush_small_1
    tempobjid = CreateDynamicObject(800, 1107.1954, 443.0494, 25.9029, 0.0000, 0.0000, -10.3000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(703, 873.6688, 335.4147, 18.2299, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(825, 865.8593, 340.1065, 20.0058, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 826.8681, 351.3449, 19.8171, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 779.7083, 319.1546, 20.2266, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 632.7254, 319.5668, 20.7644, 0.0000, 0.0000, -76.2994, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    //CreateDynamicObject(874, 602.8217, 380.9429, 16.6103, 0.0000, 0.0000, 20.1998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 579.2390, 370.8179, 16.1863, -2.2000, 0.0000, 30.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(691, 575.2634, 363.0089, 14.6864, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4_big
    tempobjid = CreateDynamicObject(672, 621.9254, 367.6347, 18.4818, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree5
    //CreateDynamicObject(874, 622.2092, 369.2528, 18.6727, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19420, -577.3997, 278.4234, 2.0927, 0.0000, 0.0000, 97.0998, -1, -1, -1, 400.0, 400.0); //police_lights02
    tempobjid = CreateDynamicObject(3593, -611.8294, 276.7756, 1.5383, 0.0000, 0.0000, 143.1999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -617.3001, 272.8934, 1.6667, 0.0000, 0.0000, 119.4999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -641.2188, 269.9442, 1.5383, 0.0000, 0.0000, 114.4999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(669, -639.8322, 259.7637, 1.6591, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4
    tempobjid = CreateDynamicObject(3594, -647.9718, 265.7802, 1.6864, 0.0000, 0.0000, -96.6996, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -659.7119, 257.8002, 1.6367, 0.0000, 0.0000, -47.7999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -665.4589, 255.7359, 1.8285, 5.2999, 0.0000, -77.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -685.5839, 253.5558, 1.6964, 0.0000, 0.0000, -44.2999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -690.8590, 249.3845, 1.5183, 0.0000, 0.0000, -56.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -728.2666, 220.6920, 1.8717, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -730.5607, 213.9998, 1.8775, 0.0000, 0.0000, -35.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -752.1265, 205.4210, 2.0281, 0.0000, 0.0000, -51.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -762.0427, 189.6024, 2.1382, 2.1998, 0.0000, 157.1999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -765.9475, 186.1071, 2.5130, 2.9999, 0.0000, -58.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, -794.8596, 169.4945, 6.6019, 0.0000, 5.9000, 29.2999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -802.3242, 177.5677, 6.9116, 9.6997, 2.3998, 112.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -787.6066, 145.5655, 8.1253, -3.2999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -791.7669, 158.6622, 6.4194, -5.7999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -688.2736, 233.9351, 2.3485, 0.0000, 2.8998, 94.0998, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, -725.1104, 226.1569, 1.8327, 0.0000, 0.0000, -41.5998, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    //CreateDynamicObject(874, -785.8535, 134.4461, 9.2587, -8.0999, 0.0000, 4.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -781.6024, 123.6601, 10.8339, -8.0999, 0.0000, 15.6997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -806.7387, 116.2505, 11.4883, -4.0000, 3.9999, 33.8997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -808.1823, 127.7052, 10.1478, -4.0000, -3.4000, -12.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(803, -788.2827, 149.2330, 7.0184, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush09
    tempobjid = CreateDynamicObject(800, -792.1259, 168.6959, 5.5651, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    //CreateDynamicObject(874, -812.3728, 151.3307, 9.2853, -1.0000, 5.8000, -35.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(703, -798.7352, 131.9261, 7.4379, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(669, -795.9160, 157.4515, 5.9467, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4
    tempobjid = CreateDynamicObject(672, -812.0692, 145.1475, 8.4884, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree5
    tempobjid = CreateDynamicObject(825, -799.1256, 138.2292, 8.5843, -8.2999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -799.5266, 155.5009, 7.4552, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    //CreateDynamicObject(874, -834.6505, 100.1526, 13.4441, -3.7999, -3.6998, -58.7000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -827.0988, 125.5027, 10.7580, -2.2999, 0.0000, -41.1999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, -777.7426, 139.8829, 8.1856, -9.0000, -1.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(825, -781.6585, 126.0121, 10.3575, 0.0000, 0.0000, -78.7994, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -789.1027, 159.2604, 6.1276, 0.0000, 4.8997, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(3594, -775.1071, 130.2003, 9.6885, -9.0000, 0.4000, 29.1000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -764.1909, 121.7067, 11.6569, -9.1997, -2.3998, 43.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -759.0421, 116.6919, 12.8168, 7.5000, 0.0000, -126.5000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -737.1630, 109.2947, 14.3345, 0.0000, 0.0000, 97.3000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -731.7291, 107.9776, 14.4680, 0.0000, 0.0000, 20.1998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -730.6187, 113.1007, 14.7264, -7.1999, 0.0000, -36.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -735.4691, 114.0429, 14.4622, 0.0000, 0.0000, 39.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -676.5449, 94.3535, 22.8061, -11.5999, -0.5000, 30.9999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -671.5064, 89.4440, 24.3211, -10.5000, 3.1998, 45.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -667.1215, 84.2089, 25.6275, -11.5999, 0.8999, 29.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -680.9697, 41.1343, 32.7583, 1.6999, 0.0000, 115.8000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, -743.6065, 95.2901, 16.7376, -13.2999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -716.1821, 102.4990, 17.5547, -11.3000, 26.7000, 77.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -686.5902, 87.8737, 23.7399, -12.3999, 4.7999, 20.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -691.8469, 49.4305, 33.4715, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -700.3660, 42.3670, 33.4715, 0.0000, 0.0000, -80.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, -703.9655, 110.5369, 16.8332, -9.3999, -1.7999, 63.1999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, -774.1903, 23.4106, 32.6855, 0.0000, 0.0000, 111.9000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, -751.9478, 34.3865, 32.7433, 0.0000, -7.9998, -92.4999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, -705.5452, 26.5328, 34.0474, 0.0000, 0.0000, 95.8999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, -711.5510, 25.6070, 33.7849, 0.0000, -1.7999, -63.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -718.3654, 24.0720, 33.9006, 0.0000, 2.2999, 92.5998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -781.1055, 22.3085, 32.8222, 0.0000, 0.0000, -85.4000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -788.0684, 21.3784, 32.8314, 0.0000, 0.0000, -78.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -818.4746, 9.8430, 32.8348, 0.0000, 0.0000, 108.2994, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3168, -827.4525, 7.0689, 32.1118, 0.0000, 0.0000, 106.1996, -1, -1, -1, 400.0, 400.0); //trailer2_01
    tempobjid = CreateDynamicObject(3593, -835.0783, 3.0285, 32.6734, 0.0000, 0.0000, -46.7999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -861.2138, 1.2338, 32.8151, 0.0000, 0.0000, -24.2000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, -856.8233, 2.2265, 32.8571, -0.3998, 0.0000, -66.1996, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(12957, -878.6193, -23.9892, 32.8493, 0.0000, 2.8998, 147.1999, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3171, -878.8244, -30.9888, 33.4874, 0.0000, -84.0998, 152.8999, -1, -1, -1, 400.0, 400.0); //trailer5_01
    //CreateDynamicObject(874, -777.8825, 32.6786, 33.4048, 0.0000, -2.0000, 95.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -790.4431, 31.4636, 33.5648, 0.0000, -2.0000, 95.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -834.0424, 20.3278, 33.2507, 0.0000, 0.0000, -84.6996, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -897.2874, -19.7656, 33.9972, -2.1998, 3.4999, -48.5000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -906.3549, -29.5664, 35.1579, -4.0998, 5.8997, -18.7000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -866.0385, 40.5746, 30.8565, -1.6000, -17.5998, 22.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -858.6586, 31.1254, 32.4844, 0.5000, -14.1997, 22.3999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -847.9556, 23.3738, 33.3236, 0.0000, 0.0000, 56.9999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -887.0358, 11.1295, 32.0442, -4.1999, 0.3000, -43.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -891.3195, -2.9814, 33.5074, -2.7999, -1.7999, -51.8997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -876.2473, 32.4444, 29.9876, -5.5998, -2.9999, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -853.0161, 13.9144, 33.2265, 2.3998, 0.0000, -78.7994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -873.9976, 9.9670, 32.2260, -9.8000, -2.7999, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(669, -865.8452, 10.5170, 31.7558, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree4
    tempobjid = CreateDynamicObject(672, -898.8131, -9.6124, 33.6716, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree5
    tempobjid = CreateDynamicObject(703, -880.2338, 19.3008, 29.2779, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_veg_tree7_big
    //CreateDynamicObject(874, -900.8905, -37.8647, 34.5456, 0.0000, 8.5999, 18.2000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -793.1828, 7.3204, 34.4421, -1.3997, 26.2999, 97.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -804.1275, 5.3277, 34.4439, -1.3997, 27.9999, 97.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -850.0524, -10.4371, 34.3328, 5.0000, -16.8999, -74.2994, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -897.8040, -53.5368, 37.5275, -17.6998, 14.6997, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, -864.2058, 10.6098, 32.7910, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -899.4873, -13.3549, 34.3945, 0.0000, 0.0000, 59.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -863.0092, 33.5027, 31.1270, 0.0000, -12.5999, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(800, -898.4884, -38.8633, 34.3344, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(800, -887.3474, -3.9182, 32.8493, 0.0000, 1.6000, 59.7999, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    //CreateDynamicObject(874, -726.5468, 62.0632, 27.3017, -10.3999, -22.2000, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -727.2830, 43.1473, 31.2623, -12.6997, -6.3997, -12.1997, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -762.1226, 11.6884, 35.4095, -2.1998, 29.2000, 95.8000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(800, -708.2589, 40.7080, 33.0760, 0.0000, 0.0000, -56.2000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(825, -685.8933, 46.9305, 33.2498, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -743.1018, 102.3675, 14.4326, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -797.8629, 28.0062, 33.2867, 0.0000, 0.0000, 75.6996, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -839.3825, 25.0942, 33.7639, 5.2999, -2.0999, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(817, -894.8436, -14.8444, 33.4594, 0.0000, 5.7999, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_Pflowers01
    tempobjid = CreateDynamicObject(869, -882.3051, 10.2397, 31.4032, -4.6999, -4.3997, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_Pflowerswee
    tempobjid = CreateDynamicObject(869, -901.0338, -28.0060, 33.8661, -1.0999, 7.1999, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_Pflowerswee
    //CreateDynamicObject(874, -841.6491, -32.2849, 41.9407, 8.6000, -14.4996, -93.4000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -845.0134, -56.5012, 43.0013, 7.1999, -18.5000, -72.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -854.4932, -59.5265, 41.7444, 7.1999, -18.5000, -72.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, -838.4334, -32.2028, 43.4813, 9.3000, -2.1998, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(800, -850.7233, -56.0223, 40.8554, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(3594, -862.6032, -51.6301, 39.5223, -7.2999, 0.0000, 106.8999, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -855.1964, -51.6399, 40.3596, 6.7999, 0.0000, -65.1996, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -850.1145, -47.4135, 41.2854, 6.3997, -1.3997, -45.0998, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(19360, -823.6292, 12.7854, 32.1431, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -823.6162, 12.8374, 32.2658, 0.0000, 0.0000, -31.8999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, -823.4672, 12.6667, 32.2472, 0.0000, 0.0000, -48.9999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2906, -823.7722, 12.9259, 32.2663, 0.0000, -179.8999, -22.4999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2036, -824.3916, 9.6513, 32.7901, 4.4998, -70.9000, -63.0998, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(19360, -678.2520, 98.1610, 21.4811, -11.0000, -95.5000, 10.8000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(3264, -731.4033, 227.3108, 1.6145, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //privatesign3
    tempobjid = CreateDynamicObject(2907, -678.0040, 98.2145, 21.6086, -10.3000, -9.2999, -50.7000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, -677.9326, 97.9888, 21.6378, 0.0000, -8.6997, -66.6996, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    //CreateDynamicObject(874, -666.3516, 101.7254, 23.9405, -8.5000, -8.6997, 0.0000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19360, -878.2719, -29.5631, 32.3259, -1.8997, 88.0000, 8.2999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, -877.4511, -29.5310, 32.1380, -1.8997, -5.3997, -27.1000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -877.5969, -29.3388, 32.6394, -89.1996, -63.1999, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2905, -877.8673, -29.0867, 32.5317, -4.0000, 86.1996, 67.1996, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2905, -877.9398, -29.2618, 32.5191, -4.0000, 86.1996, 67.1996, -1, -1, -1, 400.0, 400.0); //kmb_deadleg
    tempobjid = CreateDynamicObject(2906, -877.6582, -29.5123, 32.6910, -100.6996, 92.4999, -19.2999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(1486, -877.9533, -29.5900, 32.4387, 179.8000, -89.9999, 39.3997, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(1486, -877.7158, -29.6375, 32.5680, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_BEER_1
    tempobjid = CreateDynamicObject(2906, -878.7158, -29.4148, 32.4127, 0.0000, 0.0000, 177.5000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, -878.3275, -29.7935, 32.4547, 0.0000, 0.0000, -113.6996, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2036, -877.4144, -28.6690, 32.9626, 6.4998, -76.5998, -21.1000, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(335, -877.6118, -29.5438, 32.5497, -174.1999, -86.8999, -19.7000, -1, -1, -1, 400.0, 400.0); //knifecur
    tempobjid = CreateDynamicObject(2237, -750.1289, 237.2415, 1.2546, 0.0000, 0.0000, 31.7000, -1, -1, -1, 400.0, 400.0); //CJ_SHOVEL2
    tempobjid = CreateDynamicObject(16502, -754.7371, 245.8932, -1.9788, 0.5999, 7.8000, -53.1996, -1, -1, -1, 400.0, 400.0); //cn2_jetty1
    tempobjid = CreateDynamicObject(2237, -750.5885, 236.9579, 1.0046, 0.0000, 0.0000, 31.7000, -1, -1, -1, 400.0, 400.0); //CJ_SHOVEL2
    tempobjid = CreateDynamicObject(2237, -749.7802, 237.4571, 0.8147, 0.0000, 0.0000, 31.7000, -1, -1, -1, 400.0, 400.0); //CJ_SHOVEL2
    tempobjid = CreateDynamicObject(2908, -750.1411, 237.2937, 1.4922, -91.4999, -133.3000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2908, -750.5960, 236.9832, 1.2666, -81.0998, -133.3000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2908, -749.7736, 237.5334, 1.0743, -103.2994, -133.3000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(335, -750.1981, 237.0563, 1.5908, -115.6996, 0.0000, 13.9996, -1, -1, -1, 400.0, 400.0); //knifecur
    tempobjid = CreateDynamicObject(19360, -750.3327, 237.1174, 0.4393, -2.2999, 87.1996, -0.4999, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(849, -755.8128, 246.7976, 1.0111, 2.1998, 0.0000, -80.7994, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = //CreateDynamicObject(855, -753.2819, 237.8513, 0.6215, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -755.8319, 234.3513, 0.6215, 0.0000, 0.0000, 146.0997, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -798.9707, 200.3957, 1.2668, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -802.5709, 200.3957, 1.2668, 0.0000, 0.0000, -11.9996, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(3046, -756.4821, 246.8312, 1.0872, 0.0000, 0.0000, 2.2999, -1, -1, -1, 400.0, 400.0); //kb_barrel
    tempobjid = CreateDynamicObject(3170, -738.5217, 242.1640, 0.6470, 0.4999, 0.0000, -71.8999, -1, -1, -1, 400.0, 400.0); //trailer_large3_01
    tempobjid = CreateDynamicObject(1222, -758.0112, 249.2839, 0.8686, -17.7999, -11.7999, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel3
    tempobjid = CreateDynamicObject(3013, 14.9440, 260.2520, 1.8494, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3013, 14.2040, 260.5520, 1.8494, 0.0000, 0.0000, -42.2999, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3013, 79.6222, 222.9423, 10.0635, 0.0000, 0.0000, -36.5998, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(2674, -757.3997, 250.1246, 0.3230, -17.4999, 0.0000, 38.7999, -1, -1, -1, 400.0, 400.0); //PROC_RUBBISH_2
    tempobjid = CreateDynamicObject(3013, 53.1735, 252.7393, 10.0837, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3013, 53.5637, 252.1194, 10.0837, 0.0000, 0.0000, 50.5000, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3013, -5.5247, 253.8191, 12.0635, 0.0000, 0.0000, -160.6999, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3013, -4.2747, 254.1060, 10.0733, 0.0000, 0.0000, -34.0998, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3013, 109.6388, 225.0970, 11.2735, 0.0000, 0.0000, 57.2000, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3046, -755.8543, 252.2754, 0.0944, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kb_barrel
    tempobjid = CreateDynamicObject(3013, 109.1808, 225.7563, 10.0733, 0.0000, 0.0000, -14.3999, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3013, 106.1395, 220.5738, 10.0937, 0.0000, 0.0000, -32.0998, -1, -1, -1, 400.0, 400.0); //cr_ammobox
    tempobjid = CreateDynamicObject(3172, -754.5697, 223.2436, 1.1540, 3.5999, 0.0000, -160.8999, -1, -1, -1, 400.0, 400.0); //trailer6_01
    tempobjid = CreateDynamicObject(19360, -736.1552, 241.1770, 0.7152, 0.0000, 0.0000, 108.0998, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, -736.6104, 241.7964, 1.0348, 0.0000, 90.0000, 108.0998, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(1440, -741.9373, 238.3542, 1.2776, -2.0000, 0.0000, 17.1998, -1, -1, -1, 400.0, 400.0); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(1450, -733.0767, 241.5348, 1.6641, -2.8998, -1.2999, 20.5998, -1, -1, -1, 400.0, 400.0); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(12957, -750.5645, 228.1829, 1.5980, -0.4000, -4.5000, -86.1996, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(639, -752.2222, 220.7624, 2.5211, 3.9999, 0.0000, -161.6999, -1, -1, -1, 400.0, 400.0); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(1711, -751.4998, 221.4776, 1.4134, 0.0000, 3.7999, 113.4000, -1, -1, -1, 400.0, 400.0); //kb_chair01
    tempobjid = CreateDynamicObject(1328, -736.8950, 240.4346, 1.6030, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1328, -736.1444, 240.5746, 1.6030, 0.0000, 0.0000, 53.6999, -1, -1, -1, 400.0, 400.0); //BinNt10_LA
    tempobjid = CreateDynamicObject(1442, -741.8602, 235.2084, 1.5492, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(1442, -750.2313, 223.1432, 1.8775, -1.5999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(3594, -729.3519, 239.7362, 1.7747, -1.8997, -2.5999, 0.0000, -1, -1, -1, 400.0, 400.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(19967, -742.6815, 220.2117, 1.1345, 0.0000, 0.0000, 41.0998, -1, -1, -1, 400.0, 400.0); //SAMPRoadSign20
    tempobjid = CreateDynamicObject(11700, -735.6353, 225.3618, 1.0305, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //SAMPRoadSign47
    tempobjid = CreateDynamicObject(1217, -739.7600, 244.5762, 1.1497, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel2
    tempobjid = CreateDynamicObject(1217, -738.7321, 244.7274, 1.1999, -1.5000, -2.4999, 0.0000, -1, -1, -1, 400.0, 400.0); //barrel2
    tempobjid = CreateDynamicObject(635, -738.6046, 237.4364, 2.6335, 0.0000, -86.0998, 107.0000, -1, -1, -1, 400.0, 400.0); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(3265, -740.9918, 220.7368, 1.6253, 0.0000, -10.8000, 70.0998, -1, -1, -1, 400.0, 400.0); //privatesign4
    tempobjid = CreateDynamicObject(3262, -716.1992, 240.5778, 0.8269, 0.0000, 0.0000, 94.4000, -1, -1, -1, 400.0, 400.0); //privatesign1
    tempobjid = CreateDynamicObject(3175, -780.5958, 198.6123, 0.8740, 8.3999, 0.0000, -162.5997, -1, -1, -1, 400.0, 400.0); //sm_airstrm_med_
    tempobjid = CreateDynamicObject(1265, -754.8107, 218.5532, 1.6790, -10.1000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, -755.0609, 219.3798, 1.6433, -10.1000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(1265, -754.5748, 218.9145, 1.9565, -10.1000, 0.0000, 165.8999, -1, -1, -1, 400.0, 400.0); //BlackBag2
    tempobjid = CreateDynamicObject(3263, -754.3432, 214.5077, 1.4155, 0.0000, -11.8000, 0.0000, -1, -1, -1, 400.0, 400.0); //privatesign2
    tempobjid = CreateDynamicObject(19360, -756.9860, 222.0431, 1.1454, -3.1998, 88.3000, 5.3997, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -757.1394, 221.8825, 1.2654, -3.3998, 0.0000, -41.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(1712, -731.9442, 237.8209, 1.1345, 0.0000, -1.5999, -80.7994, -1, -1, -1, 400.0, 400.0); //kb_couch05
    tempobjid = CreateDynamicObject(849, -728.0427, 224.2937, 1.5944, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(19360, -611.3480, 275.2611, 0.9980, 0.0000, 90.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -611.0366, 275.6611, 1.1215, 0.0000, -178.3000, 45.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, -610.8778, 275.2221, 1.1181, 0.0000, 0.0000, -141.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2906, -610.6278, 275.5202, 1.1540, -172.6997, 0.0000, 51.1999, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(2908, -610.7011, 275.2322, 1.1210, 0.0000, -4.3997, 48.7999, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(10984, -575.8231, 282.1036, 0.4065, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //rubbled01_SFS
    tempobjid = CreateDynamicObject(3171, -779.7233, 210.3025, 0.3009, -5.4000, -92.6996, -29.1000, -1, -1, -1, 400.0, 400.0); //trailer5_01
    tempobjid = //CreateDynamicObject(855, -776.4658, 214.4308, 1.4814, 0.0000, 0.0000, -52.5998, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(3593, -767.5584, 213.0762, 1.2739, 4.0998, 3.6998, -171.3999, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(849, -762.5792, 192.1336, 1.7315, 0.0000, 0.0000, 35.8997, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(825, -794.5828, 183.9456, 5.2550, 0.0000, 15.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(3276, -718.7100, 248.8871, 2.0415, 0.0000, -2.5999, -74.5000, -1, -1, -1, 400.0, 400.0); //cxreffencesld
    tempobjid = //CreateDynamicObject(855, -725.9351, 256.5531, 2.0750, 0.0000, 0.0000, -44.4999, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(3175, -764.4749, 221.2557, 0.5023, -4.5998, 5.1999, 131.1000, -1, -1, -1, 400.0, 400.0); //sm_airstrm_med_
    tempobjid = CreateDynamicObject(1697, -710.8071, 247.3312, 2.7662, 0.0000, -0.2998, -131.2998, -1, -1, -1, 400.0, 400.0); //roofstuff16
    tempobjid = CreateDynamicObject(1697, -707.0615, 253.2769, 2.5799, 0.0000, -0.2998, -131.2998, -1, -1, -1, 400.0, 400.0); //roofstuff16
    tempobjid = CreateDynamicObject(1810, -739.1339, 239.2422, 1.0532, 0.0000, 0.0000, 53.0998, -1, -1, -1, 400.0, 400.0); //CJ_FOLDCHAIR
    tempobjid = CreateDynamicObject(19360, -741.6118, 220.5865, 1.6690, -1.6999, 90.0998, -0.4000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -741.6096, 220.5265, 1.7818, 0.0000, 0.0000, 37.7999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2906, -741.3024, 220.6443, 1.7838, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(760, -707.6171, 248.5751, 1.4414, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_bush_small_1
    tempobjid = //CreateDynamicObject(855, -722.4318, 258.6203, 2.0750, 0.0000, 0.0000, -100.4999, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(759, -713.2824, 244.7996, 1.4062, 0.0000, 0.0000, 81.7994, -1, -1, -1, 400.0, 400.0); //sm_bush_large_1
    tempobjid = CreateDynamicObject(692, -704.1627, 254.3480, 1.1289, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_des_bush1
    tempobjid = CreateDynamicObject(692, -735.1912, 224.8706, 1.6740, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sm_des_bush1
    tempobjid = //CreateDynamicObject(855, -502.0021, 306.7095, 1.7144, 0.0000, 0.0000, -72.0998, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -498.5621, 306.9588, 1.7144, 0.0000, 0.0000, -117.0998, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -459.4992, 304.8211, 1.3299, 0.0000, 0.0000, -28.3999, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = //CreateDynamicObject(855, -465.2513, 305.3146, 1.3299, 0.0000, 0.0000, -95.4999, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(825, -709.6734, 220.1779, 2.2125, -7.3997, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(800, -801.7896, 117.8694, 10.3261, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(865, -753.8425, 215.0625, 1.7393, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sand_combush02
    tempobjid = CreateDynamicObject(864, -750.3222, 218.7604, 1.6598, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sand_combush1
    tempobjid = CreateDynamicObject(866, -726.4766, 236.4111, 1.3903, -4.5998, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sand_combush03
    tempobjid = CreateDynamicObject(864, -731.6942, 246.1026, 0.9835, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sand_combush1
    tempobjid = CreateDynamicObject(864, -778.0822, 202.1985, 1.0283, -9.0999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sand_combush1
    tempobjid = CreateDynamicObject(865, -760.6187, 221.3717, 1.2624, 4.5998, -5.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //sand_combush02
    tempobjid = CreateDynamicObject(849, 1589.5659, 387.0392, 19.1128, 0.0000, 0.0000, 58.3997, -1, -1, -1, 400.0, 400.0); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(12957, 1392.0870, 457.1541, 19.6832, 2.5000, -1.5999, 0.0000, -1, -1, -1, 400.0, 400.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, 1397.4128, 454.9064, 19.5009, 0.0000, -1.3997, 57.9000, -1, -1, -1, 400.0, 400.0); //la_fuckcar2
    //CreateDynamicObject(874, -725.8895, 127.5728, 15.6091, 0.0000, -10.3999, 93.7995, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -910.5817, -52.5176, 40.7209, -20.3997, 2.5999, -23.7999, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, -834.5507, -53.1618, 44.3888, 7.1999, -18.5000, -72.3000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, -733.2260, 125.6192, 15.0523, 23.0998, 7.8997, -30.2999, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -717.2636, 126.4776, 15.8092, 12.3999, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(3927, -778.1428, 180.3995, 4.3218, 0.0000, 0.0000, -9.5000, -1, -1, -1, 400.0, 400.0); //d_sign01
    tempobjid = CreateDynamicObject(2715, -778.8206, 180.5511, 4.6817, 0.0000, 0.0000, -9.6000, -1, -1, -1, 400.0, 400.0); //CJ_DON_POSTER
    SetDynamicObjectMaterialText(tempobjid, 0, "Ahead..", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    tempobjid = CreateDynamicObject(2715, -778.3671, 180.4745, 5.1117, 0.0000, 0.0000, -9.6000, -1, -1, -1, 400.0, 400.0); //CJ_DON_POSTER
    SetDynamicObjectMaterialText(tempobjid, 0, "Bandit Area..", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    tempobjid = CreateDynamicObject(2715, -778.1898, 180.4445, 4.2817, 0.0000, 0.0000, -9.6000, -1, -1, -1, 400.0, 400.0); //CJ_DON_POSTER
    SetDynamicObjectMaterialText(tempobjid, 0, "You're warned..", OBJECT_MATERIAL_SIZE_256x128, "Gabriola", 80, 1, 0xFFFFFFFF, 0x00000000, 0);
    tempobjid = CreateDynamicObject(3927, -778.1428, 180.3995, 4.3218, 0.0000, 0.0000, -9.5000, -1, -1, -1, 400.0, 400.0); //d_sign01
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(19360, -777.4655, 179.5522, 2.2181, -5.3997, -88.9000, -4.3000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2036, -778.3026, 180.6136, 2.8145, -5.2999, -77.2995, -107.9999, -1, -1, -1, 400.0, 400.0); //CJ_psg1
    tempobjid = CreateDynamicObject(19360, -777.6029, 179.4611, 1.9505, -5.3997, -72.7994, -15.0000, -1, -1, -1, 400.0, 400.0); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(2907, -776.8535, 179.7792, 2.3747, -10.4996, 0.0000, -40.4999, -1, -1, -1, 400.0, 400.0); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, -777.4577, 179.1085, 2.4010, 0.0000, 0.0000, -64.0998, -1, -1, -1, 400.0, 400.0); //kmb_deadhead
    tempobjid = CreateDynamicObject(2906, -776.5233, 178.9226, 2.3431, 0.0000, 0.0000, -157.8000, -1, -1, -1, 400.0, 400.0); //kmb_deadarm
    //CreateDynamicObject(874, 2819.1682, -275.2518, 9.5282, 0.6998, -1.6000, 36.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = //CreateDynamicObject(855, -698.2495, 270.6899, 1.4327, 0.0000, 0.0000, -115.9999, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    //CreateDynamicObject(874, 2828.7910, -285.3876, 8.7629, 0.8999, -1.6000, 36.9000, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(800, 2806.6171, -244.6443, 11.1822, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(825, 2832.3264, -293.9230, 8.1190, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 2825.1520, -318.0643, 7.4368, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 2848.2319, -193.4913, 16.4241, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    //CreateDynamicObject(874, 2772.7727, -287.7973, 10.8718, -4.3000, -7.1999, -75.2001, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 2770.2431, -278.5054, 9.9404, -4.3000, -2.7999, -65.7001, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = //CreateDynamicObject(855, -702.2661, 269.3320, 1.4823, 0.0000, 0.0000, -76.5000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    //CreateDynamicObject(874, 2763.3591, -290.2066, 12.1996, -4.3000, -7.1999, -75.2001, -1, -1, -1, 400.0, 400.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 2800.5014, -287.7423, 8.4933, 0.0000, 0.0000, -69.1996, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(800, 2773.1264, -270.7885, 9.5488, 0.0000, 2.2999, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(825, 2805.4560, -153.1049, 30.7938, 0.0000, 1.6999, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 2827.1853, -145.3757, 31.7709, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(800, 2803.0554, -131.1280, 34.0638, 0.0000, 8.8999, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bush07
    tempobjid = CreateDynamicObject(825, 2827.6867, -223.2418, 13.4758, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = //CreateDynamicObject(855, -318.7033, 290.5346, 1.3351, 0.0000, 0.0000, -78.3000, -1, -1, -1, 400.0, 400.0); //genVEG_tallgrass01
    tempobjid = CreateDynamicObject(825, -255.4194, 263.8143, 8.8402, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -187.0428, 245.3426, 11.6927, 0.0000, 0.0000, 0.0000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -182.2532, 222.7568, 11.2945, 0.0000, 0.4999, -72.4000, -1, -1, -1, 400.0, 400.0); //genVEG_bushy

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 3381, -196.7890, 290.1799, 17.6952, 0.10); // cxrf_redarch
    RemoveBuildingForPlayer(playerid, 3382, -196.7890, 290.1799, 17.6952, 0.10); // LOD Model of cxrf_redarch
    RemoveBuildingForPlayer(playerid, 3330, -178.7189, 326.5390, -3.5390, 0.10); // cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3333, -178.7189, 326.5390, -3.5390, 0.10); // LOD Model of cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3381, -176.3520, 367.5230, 17.6952, 0.10); // cxrf_redarch
    RemoveBuildingForPlayer(playerid, 3382, -176.3520, 367.5230, 17.6952, 0.10); // LOD Model of cxrf_redarch
    RemoveBuildingForPlayer(playerid, 16358, -168.3200, 367.2420, 10.6640, 0.10); // des_ebrigroad07
    RemoveBuildingForPlayer(playerid, 16688, -168.3200, 367.2420, 10.6640, 0.10); // LOD Model of des_ebrigroad07
    RemoveBuildingForPlayer(playerid, 3330, -158.3520, 403.9060, -3.5390, 0.10); // cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3333, -158.3520, 403.9060, -3.5390, 0.10); // LOD Model of cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3381, -155.9839, 444.8909, 17.6952, 0.10); // cxrf_redarch
    RemoveBuildingForPlayer(playerid, 3382, -155.9839, 444.8909, 17.6952, 0.10); // LOD Model of cxrf_redarch
    RemoveBuildingForPlayer(playerid, 3331, 445.4219, 565.4689, 24.5547, 0.10); // cxrf_whitebrig
    RemoveBuildingForPlayer(playerid, 3332, 445.4219, 565.4689, 24.5547, 0.10); // LOD Model of cxrf_whitebrig
    RemoveBuildingForPlayer(playerid, 16357, 475.1250, 537.4379, 17.5858, 0.10); // des_ebrigroad01
    RemoveBuildingForPlayer(playerid, 16431, 475.1250, 537.4379, 17.5858, 0.10); // LOD Model of des_ebrigroad01
    RemoveBuildingForPlayer(playerid, 3330, 475.2340, 537.3200, 3.3203, 0.10); // cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3333, 475.2340, 537.3200, 3.3203, 0.10); // LOD Model of cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3331, 491.3129, 499.9379, 24.5547, 0.10); // cxrf_whitebrig
    RemoveBuildingForPlayer(playerid, 3332, 491.3129, 499.9379, 24.5547, 0.10); // LOD Model of cxrf_whitebrig
    RemoveBuildingForPlayer(playerid, 3330, 521.1170, 471.7890, 3.3203, 0.10); // cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3333, 521.1170, 471.7890, 3.3203, 0.10); // LOD Model of cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3331, 537.1950, 434.4060, 24.5547, 0.10); // cxrf_whitebrig
    RemoveBuildingForPlayer(playerid, 3332, 537.1950, 434.4060, 24.5547, 0.10); // LOD Model of cxrf_whitebrig
    RemoveBuildingForPlayer(playerid, 3330, 567.0079, 406.2500, 3.3203, 0.10); // cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 3333, 567.0079, 406.2500, 3.3203, 0.10); // LOD Model of cxrf_brigleg
    RemoveBuildingForPlayer(playerid, 16430, 566.8980, 406.3750, 17.5858, 0.10); // des_ebrigroad02
    RemoveBuildingForPlayer(playerid, 16432, 566.8980, 406.3750, 17.5858, 0.10); // LOD Model of des_ebrigroad02
    RemoveBuildingForPlayer(playerid, 3242, 744.8359, 275.2030, 28.0077, 0.10); // conhoos1
    RemoveBuildingForPlayer(playerid, 3284, 762.0000, 372.9219, 24.1718, 0.10); // conhoos5
    RemoveBuildingForPlayer(playerid, 12838, 2779.8400, 293.7109, 10.2734, 0.10); // coe_traintrax_09
    RemoveBuildingForPlayer(playerid, 13316, 2779.8400, 293.7109, 10.2734, 0.10); // LOD Model of coe_traintrax_09
    RemoveBuildingForPlayer(playerid, 3411, 2766.7600, 364.9530, -4.4921, 0.10); // cunteRB01
    RemoveBuildingForPlayer(playerid, 3413, 2766.7600, 364.9530, -4.4921, 0.10); // LOD Model of cunteRB01
    RemoveBuildingForPlayer(playerid, 12831, 2766.8601, 468.0469, 7.3203, 0.10); // coe_traintrax_10
    RemoveBuildingForPlayer(playerid, 13317, 2766.8601, 468.0469, 7.3203, 0.10); // LOD Model of coe_traintrax_10
    RemoveBuildingForPlayer(playerid, 3411, 2766.7600, 463.9920, -4.4921, 0.10); // cunteRB01
    RemoveBuildingForPlayer(playerid, 3413, 2766.7600, 463.9920, -4.4921, 0.10); // LOD Model of cunteRB01
    RemoveBuildingForPlayer(playerid, 3412, 2766.7600, 464.1560, -4.4921, 0.10); // cunteRB03
    RemoveBuildingForPlayer(playerid, 3283, 302.4299, 44.0546, 2.2265, 0.10); // conhoos3
    RemoveBuildingForPlayer(playerid, 3299, 302.4299, 44.0546, 2.2265, 0.10); // LOD Model of conhoos3
    RemoveBuildingForPlayer(playerid, 1294, 1316.6300, 481.9450, 23.6641, 0.10); // mlamppost
    RemoveBuildingForPlayer(playerid, 3380, 1191.7900, 546.3829, 18.9531, 0.10); // CE_hairpinL
    RemoveBuildingForPlayer(playerid, 1370, 1373.4499, 469.9689, 19.6952, 0.10); // CJ_FLAME_Drum_(F)
    RemoveBuildingForPlayer(playerid, 13296, 1383.6300, 465.1879, 22.3672, 0.10); // CE_roadsidegas
    RemoveBuildingForPlayer(playerid, 13299, 1383.6300, 465.1879, 22.3672, 0.10); // LOD Model of CE_roadsidegas
    RemoveBuildingForPlayer(playerid, 1688, 1382.6400, 469.3280, 23.8672, 0.10); // gen_roofbit2
    RemoveBuildingForPlayer(playerid, 1346, 1380.2500, 466.5159, 20.4843, 0.10); // CJ_PHONE_KIOSK2
    RemoveBuildingForPlayer(playerid, 1686, 1378.9599, 461.0390, 19.3281, 0.10); // petrolpumpnew
    RemoveBuildingForPlayer(playerid, 1686, 1380.6300, 460.2730, 19.3281, 0.10); // petrolpumpnew
    RemoveBuildingForPlayer(playerid, 1686, 1385.0799, 458.2969, 19.3281, 0.10); // petrolpumpnew
    RemoveBuildingForPlayer(playerid, 1686, 1383.4000, 459.0700, 19.3281, 0.10); // petrolpumpnew
    RemoveBuildingForPlayer(playerid, 1691, 1389.6199, 467.3750, 23.2343, 0.10); // gen_roofbit5
    RemoveBuildingForPlayer(playerid, 1450, 1394.0400, 462.2269, 19.7577, 0.10); // DYN_CRATE_3
    RemoveBuildingForPlayer(playerid, 1482, 1401.9100, 461.3590, 20.5781, 0.10); // DYN_GARRAGE1
    RemoveBuildingForPlayer(playerid, 1370, 1373.1700, 471.1019, 19.6952, 0.10); // CJ_FLAME_Drum_(F)
    RemoveBuildingForPlayer(playerid, 1482, 1390.5100, 472.3980, 20.3516, 0.10); // DYN_GARRAGE1
    RemoveBuildingForPlayer(playerid, 8056, 1735.8599, 519.1560, 25.1562, 0.10); // vegasSedge19
    RemoveBuildingForPlayer(playerid, 8028, 1735.8599, 519.1560, 25.1562, 0.10); // LOD Model of vegasSedge19
    RemoveBuildingForPlayer(playerid, 8128, 1735.8800, 519.0079, 4.3593, 0.10); // vgsSrdbrdg_lvs
    RemoveBuildingForPlayer(playerid, 8129, 1735.8800, 519.0079, 4.3593, 0.10); // LOD Model of vgsSrdbrdg_lvs
    RemoveBuildingForPlayer(playerid, 1290, 1716.7800, 460.8909, 35.9687, 0.10); // lamppost2
    RemoveBuildingForPlayer(playerid, 1290, 1750.1099, 556.5469, 31.0391, 0.10); // lamppost2

    return Y_HOOKS_CONTINUE_RETURN_1;
}
