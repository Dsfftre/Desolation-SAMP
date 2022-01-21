#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new tmpobjid;
    tmpobjid = CreateDynamicObjectEx(2257, 1134.625976, 188.606857, 1200.987548, -90.000000, 0.000000, 39.119998, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, 1130.669555, 193.513854, 1200.987548, -90.000000, 0.000000, 114.960006, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, 1120.714233, 189.421401, 1200.987548, -90.000000, 0.000000, 52.620021, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, 1126.958251, 188.637817, 1202.535766, 0.000000, 0.000000, -180.000000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, 1132.160522, 194.564300, 1201.076171, 0.000000, 0.000000, 0.060019, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, 1120.811401, 195.161590, 1200.987548, -90.000000, 0.000000, 63.840019, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tmpobjid = CreateDynamicObjectEx(15042, 1128.931884, 189.087585, 1202.977172, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(15036, 1132.568359, 193.097137, 1202.073852, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1766, 1126.531372, 194.005172, 1200.974121, 0.000000, 0.000000, -78.240013, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1766, 1120.466674, 193.005950, 1200.974121, 0.000000, 0.000000, -313.559936, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2370, 1123.956054, 191.788497, 1200.974609, 0.000000, 0.000000, 30.120000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(928, 1126.419677, 189.142379, 1201.190917, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2296, 1122.958374, 195.830184, 1200.973388, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2205, 1122.188964, 189.388061, 1200.974487, 0.000000, 0.000000, -192.720077, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2831, 1128.351440, 189.158050, 1202.475341, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2822, 1127.935546, 189.975265, 1202.475585, 0.000000, 0.000000, 47.639999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2828, 1128.486083, 190.300720, 1202.475952, 0.000000, 0.000000, -33.719989, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2825, 1121.140136, 190.686538, 1200.974487, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2825, 1122.232666, 190.137222, 1200.974487, 0.000000, 0.000000, -43.439998, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(854, 1125.769287, 188.804321, 1200.974609, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2673, 1128.430175, 193.391296, 1201.064819, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2673, 1133.675781, 189.849517, 1201.064819, 0.000000, 0.000000, -26.940000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2674, 1126.907714, 190.500839, 1200.986694, 0.000000, 0.000000, 30.600000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2674, 1133.612060, 193.522949, 1200.986694, 0.000000, 0.000000, 30.600000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2674, 1123.825683, 192.162322, 1201.836914, 0.000000, 0.000000, 29.700000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2676, 1130.219604, 190.790176, 1201.077758, 0.000000, 0.000000, 109.019989, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2478, 1129.359863, 194.289215, 1200.975708, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2478, 1129.991455, 193.499023, 1201.223876, 0.000000, 0.000000, -91.980010, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1271, 1123.147216, 194.432464, 1201.358032, 0.000000, 0.000000, 25.319999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1498, 1133.773681, 188.481079, 1200.974853, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1413, 1131.483032, 194.778427, 1203.168823, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1413, 1136.721557, 193.428970, 1203.168823, 0.000000, 0.000000, -90.239967, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1413, 1125.960571, 196.631515, 1203.168823, 0.000000, 0.000000, -42.180000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1413, 1123.021850, 196.158752, 1203.168823, 0.000000, 0.000000, 0.660000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1413, 1119.359130, 194.154525, 1203.168823, 0.000000, 0.000000, 48.479999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1413, 1119.705932, 191.570526, 1203.168823, 0.000000, 0.000000, 88.799980, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2063, 1131.576049, 189.021865, 1201.727416, 0.000000, 0.000000, -183.180038, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1498, 1123.123657, 188.498779, 1200.974853, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(3260, 1134.518798, 188.554870, 1201.588623, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2908, 1131.361206, 193.494796, 1200.980224, 0.000000, 0.000000, -59.939998, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2907, 1121.546142, 195.309860, 1200.976196, 0.000000, 0.000000, -238.620040, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2259, 1131.987304, 189.079940, 1202.623657, 0.000000, 23.000000, -180.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(5088, 1140.655273, 180.026199, 1209.786499, 0.000000, 0.000000, 43.380001, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(5088, 1145.296142, 181.757186, 1192.592041, 0.000000, 90.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(5088, 1111.125244, 204.120178, 1189.034179, 0.000000, 90.000000, -180.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2026, 1134.169067, 191.420974, 1204.958007, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2026, 1125.124755, 191.883087, 1204.958007, 0.000000, 0.000000, 0.000000, 400.00, 400.00);


    return Y_HOOKS_CONTINUE_RETURN_1;
}
