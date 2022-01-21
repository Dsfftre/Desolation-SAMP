#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new tmpobjid;
    tmpobjid = CreateDynamicObjectEx(14712, -124.740722, -485.328887, 1400.000000, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 7, 14876, "gf4", "mp_gimp_officewall", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 9, 14876, "gf4", "mp_gimp_officewall", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 11, 14584, "ab_abbatoir01", "ab_ceiling1", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 13, 16640, "a51", "concretemanky", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 14, 14584, "ab_abbatoir01", "ab_tiles", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 15, 14584, "ab_abbatoir01", "ab_ceiling1", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, -128.436569, -481.956329, 1398.447387, -90.000000, 0.000000, 0.000000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, -125.511528, -477.926483, 1398.447387, -90.000000, 0.000000, 27.659999, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, -124.044883, -473.823486, 1398.447387, -90.000000, 0.000000, 27.659999, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, -118.060546, -481.851867, 1398.447387, -90.000000, 0.000000, 3.660000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2258, -120.048301, -492.793853, 1398.956298, 0.000000, 0.000000, 180.000000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "crackedgroundb", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2258, -117.121841, -481.593444, 1398.867675, 0.000000, 0.000000, 269.639801, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "crackedgroundb", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2258, -117.148017, -484.503784, 1399.301025, 0.000000, 0.000000, 269.999786, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "crackedgroundb", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2258, -125.456420, -486.490600, 1399.110595, 0.000000, 0.000000, 180.000000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "crackedgroundb", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(19358, -121.417236, -479.394042, 1398.249511, 0.000000, 0.000000, 89.900001, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "des_ghotwood1", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2258, -126.626106, -480.251098, 1399.110595, 0.000000, 0.000000, 89.699996, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "crackedgroundb", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2258, -130.663909, -480.793914, 1399.110595, 0.000000, 0.000000, 89.699996, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "crackedgroundb", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2258, -124.082809, -480.770233, 1399.110595, 0.000000, 0.000000, -90.420036, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "crackedgroundb", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(19358, -123.021057, -480.665069, 1398.249511, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "des_ghotwood1", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(19358, -123.140533, -480.676422, 1398.249511, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "des_ghotwood1", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(19358, -120.897293, -479.404937, 1398.249511, 0.000000, 0.000000, 89.900001, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 16322, "a51_stores", "des_ghotwood1", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2258, -119.064605, -488.094879, 1398.968139, 0.000000, 0.000000, -8.160196, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 10765, "airportgnd_sfse", "crackedgroundb", 0x00000000);
    tmpobjid = CreateDynamicObjectEx(2257, -118.150108, -483.741424, 1398.877685, -90.000000, 0.000000, 3.660000, 400.00, 400.00); 
    SetDynamicObjectMaterial(tmpobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    SetDynamicObjectMaterial(tmpobjid, 1, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    tmpobjid = CreateDynamicObjectEx(2296, -118.591682, -486.021667, 1398.427246, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2142, -122.701736, -481.775817, 1398.429687, 0.000000, 0.000000, 89.500015, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1757, -120.152992, -488.057250, 1398.425537, 0.000000, 0.000000, -7.379930, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1757, -117.156982, -490.770629, 1398.425537, 0.000000, 0.000000, -158.520080, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1827, -116.835533, -487.979919, 1398.998413, 60.000000, 0.000000, -79.079978, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1828, -118.362861, -488.666717, 1398.425903, 0.000000, 0.000000, 79.319999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2525, -130.107696, -480.447174, 1398.425903, 0.000000, 0.000000, 90.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2132, -128.705215, -480.442840, 1398.426879, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(19805, -128.231048, -480.043334, 1400.308715, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2527, -129.886276, -481.699066, 1398.427856, 0.000000, 0.000000, 180.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(14861, -118.050300, -483.815673, 1398.602905, 0.000000, 0.000000, -5.039999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(911, -127.892036, -474.600830, 1399.030273, 0.000000, 0.000000, 96.780006, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1799, -123.752357, -476.105133, 1398.428100, 0.000000, 0.000000, -6.179998, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1421, -122.867187, -478.036926, 1399.131713, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(14556, -127.523933, -477.385650, 1399.947143, 0.000000, 0.000000, -87.059982, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(851, -123.418891, -486.916534, 1398.652587, 0.000000, 0.000000, 3.539999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2676, -121.979499, -490.300231, 1398.530639, 0.000000, 0.000000, 91.860008, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2676, -120.799758, -483.037719, 1398.530639, 0.000000, 0.000000, 73.859992, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2676, -123.099998, -477.025390, 1398.530639, 0.000000, 0.000000, 0.779940, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1743, -122.001792, -491.068847, 1398.427490, 0.000000, 0.000000, 95.880050, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1498, -122.508903, -492.855285, 1398.430297, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(912, -117.898979, -492.279418, 1398.995239, 0.000000, 0.000000, -176.819946, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(928, -117.149246, -489.466766, 1398.605590, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(928, -121.500221, -481.030120, 1398.695556, 0.000000, 0.000000, 31.979999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2831, -119.764259, -480.251770, 1399.528564, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2831, -120.679840, -480.088073, 1399.528564, 0.000000, 0.000000, -26.760000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2822, -121.096496, -480.678649, 1398.345825, 0.000000, 0.000000, -57.060009, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1460, -118.295608, -479.479797, 1400.490234, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(349, -117.533782, -483.556457, 1398.931762, 83.639991, -26.819980, -57.360019, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(911, -123.154800, -488.467742, 1398.941162, 0.000000, 0.000000, 91.800003, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2821, -118.471710, -489.044067, 1398.450683, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2821, -122.532409, -481.085083, 1399.479492, 0.000000, 0.000000, 39.299999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(14863, -125.312980, -474.992309, 1399.043579, 0.000000, 0.000000, 44.400009, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2026, -120.104919, -489.779418, 1401.744018, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2026, -119.733093, -482.164367, 1401.691528, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2907, -117.584182, -481.911895, 1398.439453, 0.000000, 0.000000, 90.240013, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2906, -117.553619, -481.568511, 1398.440429, 0.000000, 0.000000, 48.779998, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2394, -128.134994, -477.256072, 1400.240722, 0.000000, 0.000000, 90.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2394, -128.134994, -477.256072, 1399.237060, 0.000000, 0.000000, 90.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2676, -129.558029, -481.397460, 1398.530639, 0.000000, 0.000000, 11.099988, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2260, -123.233398, -489.480407, 1400.103637, 0.000000, 23.000000, 89.639999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2676, -125.795372, -485.327850, 1398.530639, 0.000000, 0.000000, 114.839988, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1535, -126.109191, -478.674072, 1398.550903, -90.000000, 0.000000, 17.040000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2906, -125.221351, -476.469024, 1398.440429, 0.000000, 0.000000, -49.560001, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(1535, -126.597633, -482.656341, 1398.550903, -90.000000, 0.000000, -14.640008, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2259, -117.289703, -490.734802, 1399.932739, 0.000000, 5.000000, -90.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2275, -122.579917, -479.965606, 1399.964599, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(5088, -127.144287, -488.753112, 1407.254272, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2142, -122.690460, -480.485900, 1398.429687, 0.000000, 0.000000, 89.500015, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2150, -121.588859, -479.735870, 1399.349731, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2143, -120.410018, -479.920379, 1398.429687, 0.000000, 0.000000, -0.899999, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2147, -118.884742, -480.155212, 1398.429687, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2148, -121.714759, -479.835205, 1398.429687, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(2417, -117.843704, -479.865814, 1398.429687, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 
    tmpobjid = CreateDynamicObjectEx(5088, -123.314300, -501.623199, 1407.294189, 0.000000, 0.000000, 0.000000, 400.00, 400.00); 


    return Y_HOOKS_CONTINUE_RETURN_1;
}
