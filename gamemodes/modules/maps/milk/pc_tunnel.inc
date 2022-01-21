#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new tempobjid;
    tempobjid = CreateDynamicObject(3171, 1829.9592, -345.9800, 42.9431, 4.0998, -0.0998, 114.8999, -1, -1, -1, 200.0, 200.0); //trailer5_01
    //tempobjid = CreateDynamicObject(1281, 1834.8630, -342.4927, 53.2635, 29.8997, 87.5998, 27.7999, -1, -1, -1, 200.0, 200.0); //parktable1
    tempobjid = CreateDynamicObject(19367, 1678.3598, -321.6686, 35.4934, -12.5999, -33.7999, 80.6998, -1, -1, -1, 200.0, 200.0); //wall015
    SetDynamicObjectMaterialText(tempobjid, 0, "Est. 2020", OBJECT_MATERIAL_SIZE_256x128, "Tahoma", 24, 1, 0xFFB22222, 0x00000000, 0);
    tempobjid = CreateDynamicObject(825, 1857.3332, -341.0986, 41.8042, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //genVEG_bushy
    //CreateDynamicObject(874, 1856.1931, -350.3710, 43.9024, -11.6000, -0.9998, -40.6999, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1228, 1849.1517, -336.9537, 41.0993, 0.0000, 0.0000, 15.8999, -1, -1, -1, 200.0, 200.0); //roadworkbarrier1
    tempobjid = CreateDynamicObject(1228, 1848.7036, -335.3530, 41.0806, 0.0000, 12.6000, 22.0000, -1, -1, -1, 200.0, 200.0); //roadworkbarrier1
    tempobjid = CreateDynamicObject(1228, 1847.8515, -333.8771, 41.1001, 0.0000, 11.3999, 37.2000, -1, -1, -1, 200.0, 200.0); //roadworkbarrier1
    tempobjid = CreateDynamicObject(3594, 1844.5854, -338.4103, 41.7518, 7.6999, -0.0998, 133.0998, -1, -1, -1, 200.0, 200.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(19420, 1844.5567, -338.4287, 42.4147, 0.0000, 0.0000, -44.5000, -1, -1, -1, 200.0, 200.0); //police_lights02
    tempobjid = CreateDynamicObject(1711, 1659.1629, -332.7539, 27.4237, 1.0000, 11.5999, 164.5998, -1, -1, -1, 200.0, 200.0); //kb_chair01
    tempobjid = CreateDynamicObject(3525, 1653.1955, -336.2380, 30.2530, 36.2000, 12.8000, 171.6000, -1, -1, -1, 200.0, 200.0); //exbrtorch01
    tempobjid = CreateDynamicObject(3525, 1653.6270, -318.4501, 30.0114, 27.9999, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //exbrtorch01
    tempobjid = CreateDynamicObject(6865, 1647.7735, -325.1784, 34.5066, -4.3000, -35.0000, -50.0000, -1, -1, -1, 200.0, 200.0); //steerskull
    tempobjid = CreateDynamicObject(19087, 1647.7713, -325.4064, 38.2210, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //Rope1
    //CreateDynamicObject(874, 1627.9144, -335.1166, 22.3136, -10.0000, -1.2999, 72.3000, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    //CreateDynamicObject(874, 1639.9118, -335.8695, 24.8430, -10.0000, -1.2999, 72.3000, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(341, 1790.2193, -350.7836, 46.7939, 0.0000, 27.7000, 0.0000, -1, -1, -1, 200.0, 200.0); //chnsaw
    tempobjid = CreateDynamicObject(19836, 1789.8464, -350.3512, 46.6130, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //BloodPool1
    tempobjid = CreateDynamicObject(3012, 1789.8049, -350.4776, 45.8288, -4.5000, 78.0999, -24.2000, -1, -1, -1, 200.0, 200.0); //chopcop_head
    tempobjid = CreateDynamicObject(19426, 1831.2712, -332.4624, 45.5337, 0.0000, 0.4999, 14.5999, -1, -1, -1, 200.0, 200.0); //wall066
    SetDynamicObjectMaterialText(tempobjid, 0, "DEATH", OBJECT_MATERIAL_SIZE_256x128, "Segoe UI", 24, 1, 0xFFFF0000, 0x00000000, 0);
    tempobjid = CreateDynamicObject(3864, 1845.7854, -341.2969, 47.6935, 1.3998, -6.6999, -125.0000, -1, -1, -1, 200.0, 200.0); //WS_floodlight
    tempobjid = CreateDynamicObject(19088, 1836.4433, -345.1116, 51.6329, 0.0000, 0.0000, 139.3999, -1, -1, -1, 200.0, 200.0); //Rope2
    tempobjid = CreateDynamicObject(3092, 1836.6617, -345.0744, 48.1062, 0.0000, 0.0000, -64.7997, -1, -1, -1, 200.0, 200.0); //dead_tied_cop
    //CreateDynamicObject(874, 1836.4498, -328.3013, 43.1086, -6.6999, 1.9998, -61.7000, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1634.4350, -311.7141, 23.0590, 5.7999, -4.8998, 0.0000, -1, -1, -1, 200.0, 200.0); //genVEG_bushy
    //CreateDynamicObject(874, 1641.5643, -315.8109, 24.7110, 14.3999, 5.0999, -112.1999, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 1844.5854, -338.4103, 41.7518, 7.6999, -0.0997, 133.0997, -1, -1, -1, 200.0, 200.0); //la_fuckcar1
    tempobjid = CreateDynamicObject(19420, 1844.5566, -338.4287, 42.4146, 0.0000, 0.0000, -44.5000, -1, -1, -1, 200.0, 200.0); //police_lights02
    tempobjid = CreateDynamicObject(12957, 1650.8138, -324.5830, 25.9627, 15.1000, -1.3999, -91.4999, -1, -1, -1, 200.0, 200.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3525, 1653.1955, -336.2380, 30.2530, 36.2000, 12.8000, 171.6000, -1, -1, -1, 200.0, 200.0); //exbrtorch01
    tempobjid = CreateDynamicObject(3525, 1653.6269, -318.4501, 30.0114, 27.9999, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //exbrtorch01
    tempobjid = CreateDynamicObject(6865, 1647.7735, -325.1784, 34.5065, -4.3000, -35.0000, -50.0000, -1, -1, -1, 200.0, 200.0); //steerskull
    tempobjid = CreateDynamicObject(19087, 1647.7712, -325.4064, 38.2210, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //Rope1
    tempobjid = CreateDynamicObject(2370, 1789.4283, -351.1018, 45.7238, 0.0000, 0.0000, -38.8997, -1, -1, -1, 200.0, 200.0); //Shop_set_1_Table
    tempobjid = CreateDynamicObject(19583, 1789.8437, -350.0534, 46.5931, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //MarcosKnife1
    //CreateDynamicObject(874, 1633.4261, -314.8348, 22.4815, 14.3999, 5.0999, -112.1999, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 1624.0870, -331.3135, 21.0394, -7.9998, -15.7999, 0.0000, -1, -1, -1, 200.0, 200.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(992, 1666.4226, -333.5979, 30.4720, -9.0999, -8.8000, 33.5998, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(3864, 1845.7854, -341.2969, 47.6935, 1.3997, -6.6999, -125.0000, -1, -1, -1, 200.0, 200.0); //WS_floodlight
    tempobjid = CreateDynamicObject(12957, 1835.8253, -343.5293, 43.2467, 7.7999, -1.5999, 118.9997, -1, -1, -1, 200.0, 200.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(1735, 1814.0848, -348.4136, 47.8978, 0.0000, 0.0000, 118.3999, -1, -1, -1, 200.0, 200.0); //CJ_EASYCHAIR1
    tempobjid = CreateDynamicObject(3172, 1820.9395, -349.3265, 43.9081, -5.5998, 1.6999, -73.9000, -1, -1, -1, 200.0, 200.0); //trailer6_01
    tempobjid = CreateDynamicObject(3172, 1809.7917, -350.4353, 44.8508, -2.0999, 0.2000, -64.6998, -1, -1, -1, 200.0, 200.0); //trailer6_01
    tempobjid = CreateDynamicObject(1428, 1807.1519, -349.6639, 46.5284, 0.5999, -0.6998, -149.7998, -1, -1, -1, 200.0, 200.0); //DYN_LADDER
    tempobjid = CreateDynamicObject(2060, 1814.6655, -347.2170, 47.8496, 0.0000, 0.0000, -65.5000, -1, -1, -1, 200.0, 200.0); //CJ_SANDBAG
    tempobjid = CreateDynamicObject(2060, 1815.1053, -348.1813, 47.8496, 0.0000, 0.0000, -65.5000, -1, -1, -1, 200.0, 200.0); //CJ_SANDBAG
    tempobjid = CreateDynamicObject(2060, 1815.3875, -348.8001, 47.8496, 0.0000, 0.0000, -73.6998, -1, -1, -1, 200.0, 200.0); //CJ_SANDBAG
    tempobjid = CreateDynamicObject(2060, 1814.9719, -347.6849, 48.1195, 0.0000, 0.0000, -65.0998, -1, -1, -1, 200.0, 200.0); //CJ_SANDBAG
    tempobjid = CreateDynamicObject(2060, 1815.4333, -348.6824, 48.1195, 0.0000, 0.0000, -65.0998, -1, -1, -1, 200.0, 200.0); //CJ_SANDBAG
    tempobjid = CreateDynamicObject(2060, 1814.5539, -347.0101, 48.1195, 0.0000, 0.0000, -46.1999, -1, -1, -1, 200.0, 200.0); //CJ_SANDBAG
    tempobjid = CreateDynamicObject(1271, 1742.7569, -340.1424, 44.3844, 0.0000, -4.8998, 0.0000, -1, -1, -1, 200.0, 200.0); //gunbox
    tempobjid = CreateDynamicObject(1728, 1802.4812, -351.7591, 45.2602, 2.9999, -3.0999, -152.3997, -1, -1, -1, 200.0, 200.0); //mrk_seating3
    tempobjid = CreateDynamicObject(3171, 1795.4896, -351.7326, 45.4622, -2.1998, 0.0000, -90.9999, -1, -1, -1, 200.0, 200.0); //trailer5_01
    tempobjid = CreateDynamicObject(19831, 1787.5936, -350.8872, 45.7393, 0.0000, 0.0000, -130.4998, -1, -1, -1, 200.0, 200.0); //Barbeque1
    tempobjid = CreateDynamicObject(2906, 1787.4237, -350.9403, 46.6208, 2.4999, 91.9999, -16.0000, -1, -1, -1, 200.0, 200.0); //kmb_deadarm
    tempobjid = CreateDynamicObject(14872, 1785.1191, -351.1213, 46.2659, 0.0000, 0.0000, 72.9000, -1, -1, -1, 200.0, 200.0); //Kylie_logs
    tempobjid = CreateDynamicObject(14872, 1784.0095, -350.7802, 46.2659, 0.0000, 0.0000, 72.9000, -1, -1, -1, 200.0, 200.0); //Kylie_logs
    tempobjid = CreateDynamicObject(1460, 1776.0128, -350.0354, 46.6239, 0.0000, 0.0000, -69.4000, -1, -1, -1, 200.0, 200.0); //DYN_F_R_WOOD_3
    tempobjid = CreateDynamicObject(1460, 1773.1274, -347.6763, 46.6102, 0.0000, 0.0000, -3.0999, -1, -1, -1, 200.0, 200.0); //DYN_F_R_WOOD_3
    tempobjid = CreateDynamicObject(11712, 1775.1092, -347.9277, 47.3448, 0.0000, 0.0000, -144.1999, -1, -1, -1, 200.0, 200.0); //Cross1
    tempobjid = CreateDynamicObject(16444, 1773.3791, -349.7255, 46.1637, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //des_blackbags
    tempobjid = CreateDynamicObject(1463, 1781.5660, -350.2932, 46.1629, 0.0000, 0.0000, 61.4000, -1, -1, -1, 200.0, 200.0); //DYN_WOODPILE2
    tempobjid = CreateDynamicObject(2248, 1781.0056, -343.7713, 46.4056, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //Plant_Pot_16
    tempobjid = CreateDynamicObject(2248, 1781.6562, -343.7713, 46.4056, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //Plant_Pot_16
    tempobjid = CreateDynamicObject(2248, 1782.2768, -343.7713, 46.4056, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //Plant_Pot_16
    tempobjid = CreateDynamicObject(1807, 1783.0356, -344.0166, 46.3835, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //CJ_MEDIUMPOTS1
    tempobjid = CreateDynamicObject(3172, 1656.0555, -327.4023, 26.4855, 0.1000, 10.5999, 170.6000, -1, -1, -1, 200.0, 200.0); //trailer6_01
    tempobjid = CreateDynamicObject(1271, 1743.5008, -339.8222, 44.4785, 0.0000, -4.8998, 0.0000, -1, -1, -1, 200.0, 200.0); //gunbox
    tempobjid = CreateDynamicObject(1271, 1743.5008, -340.6520, 44.4785, 0.0000, -4.8998, 0.0000, -1, -1, -1, 200.0, 200.0); //gunbox
    tempobjid = CreateDynamicObject(1271, 1743.0224, -340.2018, 45.1301, 0.0000, -4.8998, 0.0000, -1, -1, -1, 200.0, 200.0); //gunbox
    tempobjid = CreateDynamicObject(2912, 1744.3470, -340.3363, 44.2173, 0.0000, -4.8000, 0.0000, -1, -1, -1, 200.0, 200.0); //temp_crate1
    tempobjid = CreateDynamicObject(2912, 1743.8658, -340.2562, 44.9096, 0.0000, -4.8000, 0.0000, -1, -1, -1, 200.0, 200.0); //temp_crate1
    tempobjid = CreateDynamicObject(917, 1746.2163, -341.0936, 44.5353, 1.1000, -0.8999, 0.0000, -1, -1, -1, 200.0, 200.0); //FRUITCRATE1
    tempobjid = CreateDynamicObject(917, 1745.6561, -341.0935, 44.5052, 0.0998, -3.7000, 0.0000, -1, -1, -1, 200.0, 200.0); //FRUITCRATE1
    tempobjid = CreateDynamicObject(2971, 1746.0317, -339.7858, 44.2910, 0.0000, -4.8000, 0.0000, -1, -1, -1, 200.0, 200.0); //k_smashboxes
    tempobjid = CreateDynamicObject(2971, 1748.4370, -340.2807, 44.5424, 0.0000, -4.8000, -15.1999, -1, -1, -1, 200.0, 200.0); //k_smashboxes
    tempobjid = CreateDynamicObject(3171, 1753.7452, -341.0627, 45.0266, -4.0999, -0.8999, 72.8000, -1, -1, -1, 200.0, 200.0); //trailer5_01
    tempobjid = CreateDynamicObject(1820, 1759.0915, -343.2202, 45.4902, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //COFFEE_LOW_4
    tempobjid = CreateDynamicObject(1781, 1759.4281, -342.2636, 45.9555, 0.0000, 0.0000, 25.5000, -1, -1, -1, 200.0, 200.0); //MED_TV_1
    tempobjid = CreateDynamicObject(3593, 1645.0372, -335.1018, 25.6308, 0.0998, -16.7000, -6.6999, -1, -1, -1, 200.0, 200.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 1645.9947, -328.3298, 25.1039, -4.4998, -16.8999, -6.6999, -1, -1, -1, 200.0, 200.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 1646.6306, -321.6026, 25.3092, 7.5998, -16.8999, -6.6999, -1, -1, -1, 200.0, 200.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(3593, 1646.7026, -316.8457, 25.7364, -14.9998, -17.3999, 80.1998, -1, -1, -1, 200.0, 200.0); //la_fuckcar2
    tempobjid = CreateDynamicObject(12957, 1650.5074, -328.6687, 26.0594, 15.1000, -1.3999, -94.4000, -1, -1, -1, 200.0, 200.0); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(1428, 1657.5085, -328.1946, 28.3628, -12.6000, 0.0000, 83.6998, -1, -1, -1, 200.0, 200.0); //DYN_LADDER
    tempobjid = CreateDynamicObject(2035, 1662.6324, -326.4292, 27.8603, 0.3998, -11.1998, 0.0000, -1, -1, -1, 200.0, 200.0); //CJ_M16
    tempobjid = CreateDynamicObject(2035, 1662.6258, -326.7391, 27.8873, -12.8000, -0.6998, 87.8000, -1, -1, -1, 200.0, 200.0); //CJ_M16
    tempobjid = CreateDynamicObject(2035, 1662.2574, -326.8771, 27.8831, -12.8000, -11.8999, 29.5000, -1, -1, -1, 200.0, 200.0); //CJ_M16
    tempobjid = CreateDynamicObject(2040, 1664.2669, -326.6716, 28.3448, 2.7999, -13.5000, -8.0999, -1, -1, -1, 200.0, 200.0); //AMMO_BOX_M1
    tempobjid = CreateDynamicObject(2040, 1664.5075, -326.7088, 28.4029, 2.7999, -13.5000, -8.0999, -1, -1, -1, 200.0, 200.0); //AMMO_BOX_M1
    tempobjid = CreateDynamicObject(2040, 1664.7281, -326.7430, 28.4566, 2.7999, -13.5000, -8.0999, -1, -1, -1, 200.0, 200.0); //AMMO_BOX_M1
    tempobjid = CreateDynamicObject(11738, 1661.3244, -325.6387, 27.5750, -0.4999, -15.5000, 1.5000, -1, -1, -1, 200.0, 200.0); //MedicCase1
    tempobjid = CreateDynamicObject(1358, 1739.0290, -339.7572, 44.9058, -6.5998, 0.6999, 63.8998, -1, -1, -1, 200.0, 200.0); //CJ_SKIP_Rubbish
    tempobjid = CreateDynamicObject(2984, 1658.4941, -323.8587, 28.1758, -12.1998, 0.3998, 80.6999, -1, -1, -1, 200.0, 200.0); //portaloo
    //CreateDynamicObject(874, 1862.0157, -353.5357, 43.7210, -11.6000, 1.6000, -28.1998, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1820, 1659.8260, -332.0089, 27.3801, -0.6000, -13.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //COFFEE_LOW_4
    //CreateDynamicObject(874, 1853.9084, -359.5476, 45.7766, -1.6999, 11.4998, 61.6999, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(2855, 1660.2597, -331.2471, 27.9881, 0.0000, -12.1999, 0.0000, -1, -1, -1, 200.0, 200.0); //gb_bedmags05
    //CreateDynamicObject(874, 1850.1147, -349.3959, 43.7677, -3.2999, -15.9998, -72.0999, -1, -1, -1, 200.0, 200.0); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19995, 1660.5655, -331.7304, 28.1198, 0.0000, -18.2999, 0.0000, -1, -1, -1, 200.0, 200.0); //CutsceneAmmoClip1
    tempobjid = CreateDynamicObject(19995, 1660.5019, -331.7105, 28.0972, 0.0000, -17.2999, 0.0000, -1, -1, -1, 200.0, 200.0); //CutsceneAmmoClip1
    tempobjid = CreateDynamicObject(825, 1847.2408, -358.5678, 46.3291, 0.0000, 0.0000, 0.0000, -1, -1, -1, 200.0, 200.0); //genVEG_bushy
    tempobjid = CreateDynamicObject(19367, 1675.5992, -322.7958, 37.2358, -12.5999, -33.7999, 80.6998, -1, -1, -1, 200.0, 200.0); //wall015
    tempobjid = CreateDynamicObject(19367, 1673.9399, -322.6672, 36.7682, -12.5999, -33.7999, 80.6998, -1, -1, -1, 200.0, 200.0); //wall015
    SetDynamicObjectMaterialText(tempobjid, 0, "Welcome To", OBJECT_MATERIAL_SIZE_256x128, "Tahoma", 24, 1, 0xFFB22222, 0x00000000, 0);
    tempobjid = CreateDynamicObject(19367, 1680.4428, -322.0090, 35.9648, -12.5999, -33.7999, 80.6998, -1, -1, -1, 200.0, 200.0); //wall015
    SetDynamicObjectMaterialText(tempobjid, 0, "Population = 30", OBJECT_MATERIAL_SIZE_256x128, "Tahoma", 24, 1, 0xFFB22222, 0x00000000, 0);
    tempobjid = CreateDynamicObject(19367, 1685.7104, -324.2941, 39.4510, -12.5999, -33.7999, 80.6998, -1, -1, -1, 200.0, 200.0); //wall015
    SetDynamicObjectMaterialText(tempobjid, 0, "General Rules:", OBJECT_MATERIAL_SIZE_256x128, "Tahoma", 24, 1, 0xFFB22222, 0x00000000, 0);
    tempobjid = CreateDynamicObject(19367, 1685.8875, -323.9516, 38.9156, -12.5999, -33.7999, 80.6998, -1, -1, -1, 200.0, 200.0); //wall015
    SetDynamicObjectMaterialText(tempobjid, 0, "Respect Eachother", OBJECT_MATERIAL_SIZE_256x128, "Tahoma", 24, 1, 0xFFB22222, 0x00000000, 0);
    tempobjid = CreateDynamicObject(19367, 1686.0943, -323.5520, 38.2913, -12.5999, -33.7999, 80.6998, -1, -1, -1, 200.0, 200.0); //wall015
    SetDynamicObjectMaterialText(tempobjid, 0, "Help Eachother", OBJECT_MATERIAL_SIZE_256x128, "Tahoma", 24, 1, 0xFFB22222, 0x00000000, 0);
    tempobjid = CreateDynamicObject(19367, 1686.3011, -323.1509, 37.6668, -12.5999, -33.7999, 80.6998, -1, -1, -1, 200.0, 200.0); //wall015
    SetDynamicObjectMaterialText(tempobjid, 0, "No Strangers", OBJECT_MATERIAL_SIZE_256x128, "Tahoma", 24, 1, 0xFFB22222, 0x00000000, 0);
    tempobjid = CreateDynamicObject(19386, 1690.4199, -337.4767, 35.6556, 0.0000, 0.0000, -6.6999, -1, -1, -1, 200.0, 200.0); //wall034
    tempobjid = CreateDynamicObject(992, 1669.1579, -331.6809, 30.9827, -9.0999, -8.8000, 33.5998, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(992, 1671.9422, -330.9974, 31.4724, -1.8998, -10.3000, -8.4998, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(992, 1675.1871, -331.5044, 32.0682, -1.8998, -10.1999, -10.1000, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(992, 1678.5163, -331.7626, 32.6562, -1.8998, -10.1999, 0.5999, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(992, 1681.7054, -332.2012, 33.2752, 1.7999, -9.1000, -17.8999, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(992, 1684.8343, -332.0140, 33.7997, -1.8998, -10.1999, 20.6998, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(992, 1687.3658, -332.2933, 34.3959, 4.5999, -6.0999, -38.5999, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(992, 1689.4304, -334.6213, 34.7742, 3.8998, -4.0999, -57.5998, -1, -1, -1, 200.0, 200.0); //bar_barrier10b
    tempobjid = CreateDynamicObject(19302, 1690.4658, -337.4248, 35.4281, 0.0000, 0.0000, -97.5000, -1, -1, -1, 200.0, 200.0); //subbridge07

    return Y_HOOKS_CONTINUE_RETURN_1;
}
