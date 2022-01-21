#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
	new g_Object[96];
	g_Object[0] = CreateDynamicObject(3929, 362.4114, -520.8660, 18.8957, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[1] = CreateDynamicObject(3929, 363.1545, -520.8733, 19.3402, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[2] = CreateDynamicObject(3929, 362.9853, -522.2452, 17.8900, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[3] = CreateDynamicObject(3929, 361.8842, -521.2866, 17.5542, -4.1000, 71.3000, 155.5999); //d_rock
	g_Object[4] = CreateDynamicObject(19387, 362.4722, -519.4223, 17.9500, 0.0000, 0.0000, -39.5000); //wall035
	g_Object[5] = CreateDynamicObject(3929, 362.3835, -521.1200, 18.5552, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[6] = CreateDynamicObject(905, 364.3535, -518.3619, 18.0178, -7.3000, 0.5999, 48.4999); //rockbrkq
	g_Object[7] = CreateDynamicObject(905, 363.7112, -518.3815, 18.7486, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[8] = CreateDynamicObject(3929, 364.6254, -517.8847, 17.1693, 0.0000, 0.0000, 95.1999); //d_rock
	g_Object[9] = CreateDynamicObject(905, 363.6709, -519.1118, 19.2186, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[10] = CreateDynamicObject(3929, 364.6943, -518.6411, 17.5293, 0.0000, 0.0000, 95.1999); //d_rock
	g_Object[11] = CreateDynamicObject(17031, 380.4671, -507.9139, 3.4170, 0.0000, 0.0000, 123.3001); //cunt_rockgp2_13
	g_Object[12] = CreateDynamicObject(905, 364.3209, -519.4021, 19.0886, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[13] = CreateDynamicObject(905, 363.5423, -520.4104, 19.5778, -10.8999, -66.2000, 48.5999); //rockbrkq
	g_Object[14] = CreateDynamicObject(19362, 363.5604, -520.3179, 17.5927, 0.0000, 0.0000, -38.2000); //wall010
	g_Object[15] = CreateDynamicObject(3929, 362.1561, -521.0747, 18.0509, -4.1000, 71.3000, 155.5999); //d_rock
	g_Object[16] = CreateDynamicObject(3929, 362.6271, -521.6990, 18.0875, -4.1000, 71.3000, 155.5999); //d_rock
	g_Object[17] = CreateDynamicObject(905, 364.0398, -519.9854, 19.6274, -10.8999, -66.2000, 48.5999); //rockbrkq
	g_Object[18] = CreateDynamicObject(905, 364.3811, -519.0122, 18.7486, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[19] = CreateDynamicObject(905, 364.1893, -520.7243, 19.6250, -10.8999, -66.2000, 48.5999); //rockbrkq
	g_Object[20] = CreateDynamicObject(3929, 362.4114, -520.8660, 18.8957, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[21] = CreateDynamicObject(3502, 363.9874, -520.7166, 17.5473, 0.8000, 145.8999, 47.3999); //vgsN_con_tube
	g_Object[22] = CreateDynamicObject(3929, 364.0378, -517.9383, 16.9793, 0.0000, 0.0000, 95.1999); //d_rock
	g_Object[23] = CreateDynamicObject(905, 363.2886, -519.3230, 19.4345, -10.8999, -66.2000, 48.5999); //rockbrkq
	g_Object[24] = CreateDynamicObject(905, 363.4111, -518.8120, 19.2586, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[25] = CreateDynamicObject(905, 361.8951, -520.3903, 19.4095, -10.8999, -87.0999, 142.6999); //rockbrkq
	g_Object[26] = CreateDynamicObject(905, 362.9239, -519.8657, 19.4190, -10.8999, -66.2000, 48.5999); //rockbrkq
	g_Object[27] = CreateDynamicObject(905, 362.4433, -520.4419, 19.3128, -10.8999, -87.0999, 48.5999); //rockbrkq
	g_Object[28] = CreateDynamicObject(3929, 361.9475, -521.3646, 16.7896, -4.1000, 71.3000, 155.5999); //d_rock
	g_Object[29] = CreateDynamicObject(3929, 363.1545, -520.8732, 19.3402, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[30] = CreateDynamicObject(3929, 362.4485, -521.7681, 17.4981, -4.1000, 71.3000, 155.5999); //d_rock
	g_Object[31] = CreateDynamicObject(905, 361.6841, -520.7102, 18.6613, -10.8999, -81.9999, 117.6999); //rockbrkq
	g_Object[32] = CreateDynamicObject(3929, 361.5033, -521.0375, 17.0026, 0.0000, 0.0000, 0.0000); //d_rock
	g_Object[33] = CreateDynamicObject(3929, 362.4114, -520.8660, 18.8957, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[34] = CreateDynamicObject(905, 362.5417, -521.9205, 18.7801, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[35] = CreateDynamicObject(905, 362.7919, -521.6502, 19.1201, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[36] = CreateDynamicObject(3929, 361.5033, -520.5475, 16.1926, 0.0000, 0.0000, 0.0000); //d_rock
	g_Object[37] = CreateDynamicObject(3929, 361.1427, -520.9715, 17.8260, -4.1000, 71.3000, 155.5999); //d_rock
	g_Object[38] = CreateDynamicObject(3929, 363.1545, -520.8732, 19.3402, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[39] = CreateDynamicObject(905, 363.1576, -517.7979, 16.4539, 0.0000, 0.0000, -26.1999); //rockbrkq
	g_Object[40] = CreateDynamicObject(905, 362.0947, -520.4787, 18.7520, -10.8999, -87.0999, 119.3999); //rockbrkq
	g_Object[41] = CreateDynamicObject(3929, 362.9852, -522.2451, 17.8899, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[42] = CreateDynamicObject(900, 373.5307, -523.7575, 18.1448, 0.0000, 0.0000, -108.3999); //searock04
	g_Object[43] = CreateDynamicObject(900, 372.4859, -528.9990, 16.9648, 0.0000, 0.0000, 0.0000); //searock04
	g_Object[44] = CreateDynamicObject(905, 362.2819, -519.8825, 19.5324, -10.8999, -87.0999, 142.6999); //rockbrkq
	g_Object[45] = CreateDynamicObject(905, 362.8493, -519.1378, 19.6701, 1.8000, -85.5999, 142.6999); //rockbrkq
	g_Object[46] = CreateDynamicObject(905, 363.4667, -518.3269, 19.6381, 1.8000, -85.5999, 142.6999); //rockbrkq
	g_Object[47] = CreateDynamicObject(2949, 363.0349, -518.9077, 16.1997, 0.0000, 0.0000, -41.9000); //kmb_lockeddoor
	g_Object[48] = CreateDynamicObject(3929, 361.8841, -521.2866, 17.5541, -4.0999, 71.3000, 155.5998); //d_rock
	g_Object[49] = CreateDynamicObject(19387, 362.4721, -519.4223, 17.9500, 0.0000, 0.0000, -39.5000); //wall035
	g_Object[50] = CreateDynamicObject(3929, 362.3835, -521.1199, 18.5552, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[51] = CreateDynamicObject(19370, 363.4668, -520.6762, 15.8258, -2.5000, 100.4000, -45.2999); //wall018
	SetDynamicObjectMaterial(g_Object[51], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	g_Object[52] = CreateDynamicObject(905, 364.3534, -518.3618, 18.0177, -7.3000, 0.5999, 48.4999); //rockbrkq
	g_Object[53] = CreateDynamicObject(905, 363.7112, -518.3814, 18.7486, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[54] = CreateDynamicObject(3929, 364.6253, -517.8847, 17.1693, 0.0000, 0.0000, 95.1998); //d_rock
	g_Object[55] = CreateDynamicObject(905, 363.6708, -519.1118, 19.2185, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[56] = CreateDynamicObject(3929, 364.6943, -518.6411, 17.5293, 0.0000, 0.0000, 95.1998); //d_rock
	g_Object[57] = CreateDynamicObject(17031, 380.4671, -507.9139, 3.4170, 0.0000, 0.0000, 123.3001); //cunt_rockgp2_13
	g_Object[58] = CreateDynamicObject(905, 364.3208, -519.4020, 19.0886, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[59] = CreateDynamicObject(905, 363.5422, -520.4104, 19.5778, -10.8999, -66.1999, 48.5998); //rockbrkq
	g_Object[60] = CreateDynamicObject(19362, 363.5603, -520.3178, 17.5926, 0.0000, 0.0000, -38.2000); //wall010
	g_Object[61] = CreateDynamicObject(3929, 362.1560, -521.0747, 18.0508, -4.0999, 71.3000, 155.5998); //d_rock
	g_Object[62] = CreateDynamicObject(3929, 362.6271, -521.6989, 18.0874, -4.0999, 71.3000, 155.5998); //d_rock
	g_Object[63] = CreateDynamicObject(905, 364.0397, -519.9854, 19.6273, -10.8999, -66.1999, 48.5998); //rockbrkq
	g_Object[64] = CreateDynamicObject(905, 364.3811, -519.0122, 18.7486, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[65] = CreateDynamicObject(905, 364.1893, -520.7243, 19.6250, -10.8999, -66.1999, 48.5998); //rockbrkq
	g_Object[66] = CreateDynamicObject(3502, 363.9873, -520.7166, 17.5473, 0.8000, 145.8999, 47.3998); //vgsN_con_tube
	g_Object[67] = CreateDynamicObject(3929, 364.0378, -517.9382, 16.9792, 0.0000, 0.0000, 95.1998); //d_rock
	g_Object[68] = CreateDynamicObject(905, 363.2886, -519.3229, 19.4344, -10.8999, -66.1999, 48.5998); //rockbrkq
	g_Object[69] = CreateDynamicObject(905, 363.4111, -518.8120, 19.2586, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[70] = CreateDynamicObject(905, 361.8951, -520.3903, 19.4095, -10.8999, -87.0998, 142.6999); //rockbrkq
	g_Object[71] = CreateDynamicObject(905, 362.9238, -519.8657, 19.4190, -10.8999, -66.1999, 48.5998); //rockbrkq
	g_Object[72] = CreateDynamicObject(905, 362.4432, -520.4418, 19.3127, -10.8999, -87.0998, 48.5998); //rockbrkq
	g_Object[73] = CreateDynamicObject(3929, 361.9475, -521.3646, 16.7896, -4.0999, 71.3000, 155.5998); //d_rock
	g_Object[74] = CreateDynamicObject(3929, 362.4484, -521.7681, 17.4981, -4.0999, 71.3000, 155.5998); //d_rock
	g_Object[75] = CreateDynamicObject(905, 361.6841, -520.7102, 18.6613, -10.8999, -81.9999, 117.6998); //rockbrkq
	g_Object[76] = CreateDynamicObject(3929, 361.5032, -521.0374, 17.0025, 0.0000, 0.0000, 0.0000); //d_rock
	g_Object[77] = CreateDynamicObject(3929, 361.5032, -520.5474, 16.1926, 0.0000, 0.0000, 0.0000); //d_rock
	g_Object[78] = CreateDynamicObject(3929, 361.1427, -520.9714, 17.8260, -4.0999, 71.3000, 155.5998); //d_rock
	g_Object[79] = CreateDynamicObject(905, 363.1575, -517.7979, 16.4538, 0.0000, 0.0000, -26.1998); //rockbrkq
	g_Object[80] = CreateDynamicObject(905, 362.0946, -520.4786, 18.7520, -10.8999, -87.0998, 119.3999); //rockbrkq
	g_Object[81] = CreateDynamicObject(900, 373.5307, -523.7575, 18.1448, 0.0000, 0.0000, -108.3999); //searock04
	g_Object[82] = CreateDynamicObject(900, 372.4859, -528.9990, 16.9647, 0.0000, 0.0000, 0.0000); //searock04
	g_Object[83] = CreateDynamicObject(905, 362.2818, -519.8825, 19.5324, -10.8999, -87.0998, 142.6999); //rockbrkq
	g_Object[84] = CreateDynamicObject(905, 362.8493, -519.1378, 19.6700, 1.7999, -85.5998, 142.6999); //rockbrkq
	g_Object[85] = CreateDynamicObject(905, 363.4667, -518.3269, 19.6380, 1.7999, -85.5998, 142.6999); //rockbrkq
	g_Object[86] = CreateDynamicObject(2949, 363.0349, -518.9077, 16.1996, 0.0000, 0.0000, -41.9000); //kmb_lockeddoor
	g_Object[87] = CreateDynamicObject(19370, 363.4667, -520.6762, 15.8257, -2.5000, 100.4000, -45.2999); //wall018
	SetDynamicObjectMaterial(g_Object[87], 0, 10101, "2notherbuildsfe", "Bow_Abpave_Gen", 0x00000000);
	g_Object[88] = CreateDynamicObject(3929, 362.9852, -522.2451, 17.8899, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[89] = CreateDynamicObject(3929, 361.8841, -521.2866, 17.5541, -4.0999, 71.3000, 155.5998); //d_rock
	g_Object[90] = CreateDynamicObject(19387, 362.4721, -519.4223, 17.9500, 0.0000, 0.0000, -39.5000); //wall035
	g_Object[91] = CreateDynamicObject(3929, 362.3835, -521.1199, 18.5552, 94.4999, -103.5000, 6.2999); //d_rock
	g_Object[92] = CreateDynamicObject(905, 364.3534, -518.3618, 18.0177, -7.3000, 0.5999, 48.4999); //rockbrkq
	g_Object[93] = CreateDynamicObject(905, 363.7112, -518.3814, 18.7486, 0.0000, 0.0000, 0.0000); //rockbrkq
	g_Object[94] = CreateDynamicObject(3929, 364.6253, -517.8847, 17.1693, 0.0000, 0.0000, 95.1998); //d_rock
	g_Object[95] = CreateDynamicObject(905, 363.6708, -519.1118, 19.2185, 0.0000, 0.0000, 0.0000); //rockbrkq

    return Y_HOOKS_CONTINUE_RETURN_1;
}
