#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {

	new tmpobjid;
	tmpobjid = CreateDynamicObjectEx(3331, 482.746948, 488.077667, -9.793580, -13.898408, -19.200000, 2.530730, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Scrap_Wheel_Rim", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3331, 503.409698, 521.400451, -11.547068, -36.818420, 34.620040, -76.249282, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Scrap_Wheel_Rim", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3331, 429.400878, 564.259521, -3.624969, 47.361579, 19.620000, 2.530730, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Scrap_Wheel_Rim", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3331, 461.946289, 531.717041, -11.547068, -36.818420, 34.620040, -155.089309, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Scrap_Wheel_Rim", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3569, 446.277465, 531.226562, -0.644218, 18.299999, 28.440000, -112.079986, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3569, 502.695892, 511.951904, -0.470239, -6.599998, -46.560020, -189.479980, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3269, 443.902679, 500.923248, -1.497099, -4.380000, 0.180000, 0.000000, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Scrap_Wheel_Rim", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 4, 12992, "ce_oldbridge", "Gen_Scrap_Wheel_Rim", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3498, 524.684509, 478.021697, 15.285449, -123.240020, -18.780029, 0.000000, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	SetDynamicObjectMaterial(tmpobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3498, 520.216308, 475.428009, 15.583008, -132.959976, -49.080028, -0.659990, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3498, 526.902221, 477.302856, 14.667148, -69.839942, -58.680030, -78.840019, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3498, 523.013549, 477.782196, 16.232709, -137.219970, -68.160057, -38.939998, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3498, 517.885253, 474.115753, 15.415988, -147.360031, -52.620079, -38.939998, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 1, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3569, 539.012268, 446.069549, 20.300739, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3569, 565.809448, 405.492919, 20.300739, 0.000000, 0.000000, 44.879989, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3569, 584.174865, 378.009796, 20.300739, 0.000000, 0.000000, 48.899990, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Rusty_Poll", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3331, 537.652343, 434.493347, 24.554700, 0.000000, 0.000000, 35.700000, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Scrap_Wheel_Rim", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(3331, 583.164245, 368.403564, 24.554700, 0.000000, 0.000000, 34.739990, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 12992, "ce_oldbridge", "Gen_Scrap_Wheel_Rim", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(19603, 473.113861, 532.383605, 5.856588, 90.000000, 0.000000, 36.719978, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5069, "ctscene_las", "ruffroadlas", 0x00000000);
	tmpobjid = CreateDynamicObjectEx(19603, 480.533355, 537.797912, 6.363540, 90.000000, 0.000000, 35.219970, 600.00, 600.00); 
	SetDynamicObjectMaterial(tmpobjid, 0, 5069, "ctscene_las", "ruffroadlas", 0x00000000);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	tmpobjid = CreateDynamicObjectEx(16357, 466.974884, 494.950378, -38.859851, 1.881610, -45.420009, -18.300069, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(16357, 458.731689, 550.691955, -39.385509, 1.881610, -45.420009, 116.939933, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 427.686523, 592.733947, 12.971058, 33.600021, 2.100018, -4.380000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 437.296051, 599.265869, 12.971058, 31.260019, -5.219978, 47.400020, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 436.119781, 588.784179, 9.042220, 15.300008, -3.599980, 10.920008, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 424.053894, 585.560791, 7.933588, -9.420000, 9.840020, -88.080009, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 407.002685, 588.902404, 6.977078, -4.440000, 26.040018, -156.659942, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 415.644989, 595.375122, 12.971058, 33.600021, 2.100018, -34.139991, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 413.010345, 578.252014, 5.019370, 0.779999, 12.240018, -124.559951, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 426.726318, 574.947692, 5.019370, 0.779999, 12.240018, -80.879966, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 441.801605, 578.284240, 5.019370, 0.779999, 12.240018, -57.659969, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 395.349609, 590.187622, 1.889438, -4.440000, 26.040018, -156.659942, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 403.025848, 579.089538, 1.889438, -4.440000, 26.040018, -140.819961, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 409.489807, 572.033203, 1.889438, -4.440000, 26.040018, -124.919982, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 423.392150, 567.716308, 1.889438, -4.440000, 26.040018, -95.939956, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 439.284912, 569.521850, 1.529430, -2.099988, 33.660011, -70.559928, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 448.531250, 585.468566, 5.019370, 0.779999, 12.240018, -18.479970, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 449.359405, 599.086669, 5.019370, 0.779999, 12.240018, 16.680019, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 441.512969, 593.883544, 9.042220, 15.300008, -3.599980, 78.839981, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 444.557647, 604.579162, 9.022528, 26.700019, -4.139978, 89.880012, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10984, 442.579650, 607.245727, 11.398260, 36.660018, -5.279980, 81.120033, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(16357, 386.687652, 584.191833, -47.184619, 40.881610, -65.639968, 53.219928, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3330, 429.505218, 581.586853, -2.122210, 15.081588, -14.640000, -24.046920, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3330, 445.238159, 595.641174, -2.122210, 15.081588, -14.640000, 68.293060, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10985, 469.529785, 533.469299, 0.615540, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10985, 478.438110, 541.667236, 0.615540, 0.000000, 0.000000, -20.100000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(16357, 441.575195, 545.720397, -12.725238, -4.118390, -10.739990, -45.720081, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(16357, 447.783447, 483.817535, -8.600270, 3.021610, 8.219988, -88.380081, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 469.685363, 507.231628, -0.037060, 12.600000, 3.839998, -26.639999, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 457.709777, 515.460937, -0.006579, 15.479998, 2.819998, -81.600013, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 458.718536, 529.269104, -0.006579, -5.099998, -1.919999, -119.040023, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 479.988433, 529.630187, -0.037060, 18.719999, 6.780000, -26.639999, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 436.348785, 534.518310, 0.262380, -17.340000, -20.280000, -177.540023, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 463.503173, 550.134033, -0.037060, 12.600000, 3.839998, 57.060001, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 477.031768, 488.763488, -0.037060, 12.600000, 3.839998, 57.060001, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 494.965209, 477.062591, -0.006579, 15.479998, 2.819998, -154.499954, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3567, 459.332946, 498.274047, -1.569700, 11.939998, 2.579998, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3567, 475.208709, 479.804107, -1.113548, -9.840008, 13.619990, 78.539978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(4257, 384.737762, 528.113159, -59.665908, 0.000000, 0.000000, 107.399978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(4257, 451.674530, 497.526489, -69.522186, 0.000000, 0.000000, 113.699996, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(4257, 567.502563, 529.007751, -59.665908, 0.000000, 0.000000, 298.980010, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 492.273406, 492.584167, 2.046580, -12.479990, -4.500000, 13.439998, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3171, 484.784484, 515.010742, -2.414020, -10.020000, -0.600000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3168, 494.962982, 536.915039, -1.677389, -23.700000, -1.799998, -63.060001, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3172, 461.989898, 496.994110, -2.278558, 33.959999, 22.020000, -39.959999, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3073, 465.559570, 487.703918, -0.022368, -17.399999, -10.140000, -66.179992, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2934, 504.829681, 532.338012, 0.425179, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2935, 482.466949, 484.467193, -0.018500, 0.000000, 0.000000, -50.400001, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 495.477142, 495.133209, 1.552729, -10.380000, -4.739998, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 474.228057, 534.531066, 1.436840, 0.000000, 0.000000, -77.759986, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 446.226776, 548.589904, 0.904389, 10.380000, 0.600000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 491.263153, 498.360595, 0.694419, -6.539999, -0.660000, 27.720010, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10985, 475.631469, 496.110260, -0.558269, 0.000000, 0.000000, -34.439998, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(10985, 443.830596, 526.393310, -0.558269, 0.000000, 0.000000, -17.340000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(16653, 494.689849, 473.072998, -1.376250, 14.819998, 11.699998, 35.819999, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3271, 532.451904, 505.517272, -1.874390, -7.440000, -0.540000, -3.240000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(18766, 523.707153, 473.275878, 15.327718, 0.000000, 0.000000, 34.619998, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(18766, 518.836486, 469.768432, 15.327718, 0.000000, 0.000000, 34.619998, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(18766, 521.431762, 476.785003, 16.348789, 39.660041, 1.019999, -109.019943, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(18766, 519.529907, 472.176910, 16.042549, 39.660041, 1.019999, -110.819892, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 508.342895, 482.142944, 4.981860, -47.520069, -28.680019, 29.700000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 523.549255, 467.833923, 18.499259, 0.000000, 0.000000, 18.120000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 535.532714, 458.470184, 18.436700, 0.000000, 0.000000, -126.839988, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 533.710693, 446.165252, 18.436700, 0.000000, 0.000000, -160.619964, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 546.291748, 439.657806, 18.436700, 0.000000, 0.000000, -138.299972, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 552.630004, 422.668334, 18.436700, 0.000000, 0.000000, -121.199943, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 567.089904, 413.333679, 18.436700, 0.000000, 0.000000, -151.199951, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 566.298767, 400.125091, 18.436700, 0.000000, 0.000000, -120.719970, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 578.346008, 393.602813, 18.436700, 0.000000, 0.000000, -144.959976, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 587.436828, 370.666839, 18.436700, 0.000000, 0.000000, -126.900001, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3594, 597.059509, 367.028045, 18.436700, 0.000000, 0.000000, -153.659973, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 526.498901, 456.731994, 18.499259, 0.000000, 0.000000, 45.299991, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 543.441406, 437.731842, 18.499259, 0.000000, 0.000000, 28.679979, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 554.678833, 428.157623, 18.499259, 0.000000, 0.000000, 40.739978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 558.492004, 415.415313, 18.499259, 0.000000, 0.000000, 8.519980, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 569.992309, 405.386627, 18.499259, 0.000000, 0.000000, 65.579978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 576.540588, 387.820495, 18.499259, 0.000000, 0.000000, 47.579978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 586.790771, 383.661590, 18.499259, 0.000000, 0.000000, 20.039979, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(3593, 593.828552, 362.458282, 18.499259, 0.000000, 0.000000, 56.399971, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 546.775207, 441.591461, 17.907890, 0.000000, 0.000000, 3.900000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 554.855285, 421.758239, 17.907890, 0.000000, 0.000000, 3.900000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 569.801940, 410.194061, 17.907890, 0.000000, 0.000000, 7.259990, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 576.578674, 395.596984, 17.907890, 0.000000, 0.000000, 7.259990, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 589.850952, 377.036376, 18.352859, 0.000000, 0.000000, 7.259990, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 606.264892, 349.753204, 18.352859, 0.000000, 0.000000, 7.259990, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(874, 620.593322, 332.739410, 18.352859, 0.000000, 0.000000, 7.259990, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 559.279357, 423.822204, 18.065650, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 547.393554, 428.649078, 18.065650, 0.000000, 0.000000, -34.799999, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 545.344238, 444.820617, 18.065650, 0.000000, 0.000000, -20.219999, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 566.004272, 409.434265, 18.065650, 0.000000, 0.000000, -11.039999, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 570.701721, 394.430145, 18.065650, 0.000000, 0.000000, -55.080001, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 582.447509, 387.242431, 18.065650, 0.000000, 0.000000, -95.940017, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 593.376342, 366.815856, 18.065650, 0.000000, 0.000000, -54.540008, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 605.016662, 356.616790, 18.065650, 0.000000, 0.000000, -31.500009, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 604.661682, 348.035156, 18.065650, 0.000000, 0.000000, -54.540008, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 615.268493, 342.976745, 18.065650, 0.000000, 0.000000, -89.340019, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(9812, 550.006286, 444.617187, 23.317369, 0.000000, 0.000000, 125.219978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(9812, 538.225463, 433.463104, 23.317369, 0.000000, 0.000000, -55.140048, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(9812, 582.416381, 369.110900, 23.317369, 0.000000, 0.000000, -55.140048, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(9812, 596.868225, 378.287750, 23.317369, 0.000000, 0.000000, 125.219978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(864, 597.337890, 357.701690, 17.729290, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 599.006103, 369.054412, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 590.721557, 381.289367, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 581.275085, 393.172790, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 560.989440, 405.462615, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 561.307434, 421.508544, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 543.930297, 432.804077, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 536.193969, 448.151855, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 522.341430, 462.233520, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(866, 530.728637, 452.809967, 17.860979, 0.000000, 0.000000, 0.000000, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 534.916503, 455.892974, 18.065650, 0.000000, 0.000000, -34.799999, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(2676, 526.385131, 469.906646, 18.065650, 0.000000, 0.000000, -88.319992, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(9812, 532.457031, 442.139434, 8.934208, 0.000000, 0.000000, -55.140048, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(9812, 568.860046, 391.091857, 8.934208, 0.000000, 0.000000, -55.140048, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(9812, 545.280090, 451.353546, 8.716488, 0.000000, 0.000000, 125.219978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(9812, 580.250915, 400.820709, 8.716488, 0.000000, 0.000000, 125.219978, 600.00, 600.00); 
	tmpobjid = CreateDynamicObjectEx(5088, 547.575683, 413.111663, 26.860780, 0.000000, 0.000000, -54.779991, 600.00, 600.00); 

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {

	RemoveBuildingForPlayer(playerid, 3332, 445.421, 565.468, 24.554, 0.250);
	RemoveBuildingForPlayer(playerid, 3332, 491.312, 499.937, 24.554, 0.250);
	RemoveBuildingForPlayer(playerid, 16431, 475.125, 537.437, 17.585, 0.250);
	RemoveBuildingForPlayer(playerid, 3331, 445.421, 565.468, 24.554, 0.250);
	RemoveBuildingForPlayer(playerid, 16357, 475.125, 537.437, 17.585, 0.250);
	RemoveBuildingForPlayer(playerid, 3331, 491.312, 499.937, 24.554, 0.250);
	RemoveBuildingForPlayer(playerid, 4514, 440.046, 587.445, 19.734, 0.250);

    return Y_HOOKS_CONTINUE_RETURN_1;
}
