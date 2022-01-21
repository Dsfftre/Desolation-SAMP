#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {
    new tempobjid;
    tempobjid = CreateDynamicObject(2972, 54.3189, -219.7507, 0.5526, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //k_cargo4
    tempobjid = CreateDynamicObject(639, 24.0741, -276.0869, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 29.4419, -276.2597, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(19360, 234.7803, -303.0941, 0.5081, 0.0000, 90.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //wall008
    SetDynamicObjectMaterial(tempobjid, 0, 14612, "ab_abattoir_box", "ab_bloodfloor", 0x00000000);
    tempobjid = CreateDynamicObject(639, 40.6990, -276.5161, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 46.3973, -276.6553, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 52.0153, -276.8135, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 57.7442, -276.9335, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 63.4617, -277.1137, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 74.9589, -277.3645, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 80.7573, -277.5256, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 86.5559, -277.6369, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 92.2237, -277.8258, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 97.9524, -277.9356, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(2907, 234.4489, -303.0926, 0.6407, 0.0000, 0.0000, -41.5999, -1, -1, -1, 500.0000, 500.0000); //kmb_deadtorso
    tempobjid = CreateDynamicObject(639, 108.6406, -278.1412, 8.9635, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(9812, 80.9053, -294.2956, 18.6170, 0.0000, 0.0000, 178.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(9812, 49.9553, -330.2916, 18.5357, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(635, 222.1771, -302.4383, 2.6168, 0.2999, -93.6000, 89.9001, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(9812, 77.9653, -329.7014, 8.3757, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb08
    tempobjid = CreateDynamicObject(635, 231.2273, -302.3958, 2.6031, 0.2999, -93.6000, 89.9001, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb1
    tempobjid = CreateDynamicObject(639, 44.6664, -292.3255, 23.1434, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 39.1287, -292.1492, 23.1434, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 23.8435, -291.7557, 23.1434, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 29.6923, -291.8681, 23.1434, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 111.6548, -281.5909, 9.7959, 14.1997, 2.3998, 178.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 111.5485, -287.2684, 11.1610, 14.1997, 2.3998, 178.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 111.4654, -291.5913, 12.2551, 14.1997, 2.3998, 178.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 20.7532, -279.1712, 9.7889, -13.1000, 0.0000, -2.1998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 20.6417, -284.4208, 11.0108, -13.1000, 0.0000, -2.1998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 20.4484, -289.4548, 12.3063, -13.1000, 0.0000, -2.1998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 111.3927, -297.0187, 12.8704, -0.5000, 2.3998, 178.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 111.1227, -307.9655, 12.7726, -0.5000, 2.3998, 178.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 110.8104, -313.6907, 12.7741, -0.3000, 2.3998, 178.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 110.4980, -324.9938, 12.8409, -0.3000, 2.3998, 176.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 107.2630, -331.7420, 22.9841, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 101.4832, -331.7521, 22.9437, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 93.4235, -331.7658, 22.8875, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 87.8038, -331.7760, 22.8483, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 82.0931, -331.7460, 22.9284, 1.0000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 43.1721, -331.1242, 12.7264, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 37.5615, -331.1340, 12.7672, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 31.8418, -331.1441, 12.7271, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 25.9820, -331.1546, 12.6864, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 22.2220, -331.1611, 12.6602, -0.4000, 0.0000, 90.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 126.5354, -286.4458, 7.1356, 9.5999, 0.0000, -89.6996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 132.2839, -286.4158, 8.1077, 9.5999, 0.0000, -89.6996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 134.0292, -286.4064, 8.4027, 9.5999, 0.0000, -89.6996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 138.9364, -286.4707, 8.3837, -10.2999, 0.0000, -89.6996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 144.2590, -286.4432, 7.4162, -10.2999, 0.0000, -89.6996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 146.2760, -286.4624, 7.0496, -10.2999, 0.0000, -89.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 149.5281, -289.4172, 6.4861, 0.0000, 0.0000, 180.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 149.5281, -295.2972, 6.4861, 0.0000, 0.0000, 180.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 149.5281, -303.1672, 6.4861, 0.0000, 0.0000, 180.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 149.5281, -309.1473, 6.4861, 0.0000, 0.0000, 180.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 149.5281, -315.0473, 6.4861, 0.0000, 0.0000, 180.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 149.5281, -321.5874, 6.4861, 0.0000, 0.0000, 180.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 123.2440, -289.3887, 6.5465, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 123.2440, -295.1787, 6.5465, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 123.2040, -302.5888, 6.5465, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 123.2040, -308.1188, 6.5465, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 123.1740, -316.7088, 6.5465, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 123.1640, -321.7188, 6.5465, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 126.2835, -324.5877, 7.1027, -8.3999, 0.0000, 89.7994, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 131.5023, -324.6062, 7.9744, -11.3999, 0.0000, 89.7994, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 133.8354, -324.6141, 8.4448, -11.3999, 0.0000, 89.7994, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 138.8444, -324.6116, 8.4582, 10.5999, 0.0000, 89.7994, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 144.2604, -324.6306, 7.4446, 10.5999, 0.0000, 89.7994, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 146.3737, -324.6380, 7.0493, 10.5999, 0.0000, 89.7994, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 152.2474, -289.6845, 2.1749, 0.0000, 0.0000, 270.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 155.8674, -289.6845, 2.1749, 0.0000, 0.0000, 270.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 143.5473, -285.9942, 4.1648, 0.0000, 0.0000, 270.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 137.6674, -285.9942, 4.1648, 0.0000, 0.0000, 270.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 129.2975, -285.9543, 4.1648, 0.0000, 0.0000, 270.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 158.5372, -292.7044, 2.1749, 0.0000, 0.0000, 180.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 158.5372, -296.3243, 2.1749, 0.0000, 0.0000, 180.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 155.6174, -299.2643, 2.1749, 0.0000, 0.0000, 90.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 150.3074, -299.3143, 2.1749, 0.0000, 0.0000, 90.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 74.8815, -201.3040, 10.7349, 0.0000, 0.0000, 86.9999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 56.9062, -200.3621, 10.7349, 0.0000, 0.0000, 86.9999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 35.8750, -199.2601, 10.7349, 0.0000, 0.0000, 86.9999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 43.0611, -198.4040, 10.7349, 0.0000, 0.0000, -92.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 48.8837, -198.6990, 10.7349, 0.0000, 0.0000, -92.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 68.7658, -199.7460, 10.7349, 0.0000, 0.0000, -92.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 28.2901, -197.6560, 10.7349, 0.0000, 0.0000, -92.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 19.4482, -198.1076, 10.7349, 0.0000, 0.0000, -76.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -0.1729, -202.7424, 10.7349, 0.0000, 0.0000, -76.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -17.5000, -206.7841, 10.7349, 0.0000, 0.0000, -76.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -31.7922, -210.1815, 10.7349, 0.0000, 0.0000, -76.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 13.1583, -200.9082, 10.7349, 0.0000, 0.0000, 103.4999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -8.8009, -206.0361, 10.7349, 0.0000, 0.0000, 103.4999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -24.8514, -209.7765, 10.7349, 0.0000, 0.0000, 103.4999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -43.7192, -211.1002, 10.7349, 0.0000, 0.0000, -97.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -57.8250, -209.2238, 10.7349, 0.0000, 0.0000, -98.6996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -70.6902, -207.4877, 10.7349, 0.0000, 0.0000, -97.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -92.5370, -204.5635, 10.7349, 0.0000, 0.0000, -97.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -98.2225, -203.7747, 10.7349, 0.0000, 0.0000, -97.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -51.4933, -211.3090, 10.7349, 0.0000, 0.0000, 82.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -64.8647, -209.5249, 10.7349, 0.0000, 0.0000, 82.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -78.3552, -207.7247, 10.7349, 0.0000, 0.0000, 82.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -84.1341, -206.9537, 10.7349, 0.0000, 0.0000, 82.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -103.8989, -204.3164, 10.7349, 0.0000, 0.0000, 82.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(12859, 56.5772, -257.5693, -2.5139, -6.7999, 11.1997, 8.5999, -1, -1, -1, 500.0000, 500.0000); //sw_cont03
    tempobjid = CreateDynamicObject(10984, 56.9849, -242.3502, 1.3393, 0.0000, 0.0000, 30.2000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(10984, 64.3401, -260.2709, 1.3393, 0.0000, 0.0000, 5.5000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(3571, 62.8036, -250.0343, 1.8933, 0.0000, 0.0000, 37.5998, -1, -1, -1, 500.0000, 500.0000); //lasdkrt3
    tempobjid = CreateDynamicObject(3566, 47.8927, -227.7270, 2.2307, 0.0000, -90.0998, 134.3999, -1, -1, -1, 500.0000, 500.0000); //lasntrk1
    tempobjid = CreateDynamicObject(854, 54.8656, -220.6954, 0.7867, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3b
    tempobjid = CreateDynamicObject(2674, 56.5135, -221.5697, 0.5921, 0.0000, 0.0000, -39.5000, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_2
    tempobjid = CreateDynamicObject(2973, 58.3371, -224.5010, 0.5386, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //k_cargo2
    tempobjid = CreateDynamicObject(2975, 59.1595, -219.8146, 1.1806, -90.1996, 30.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //k_cargo3
    tempobjid = CreateDynamicObject(3005, 58.9211, -221.6640, 0.5914, 0.0000, 0.0000, 47.1999, -1, -1, -1, 500.0000, 500.0000); //smash_box_stay
    tempobjid = CreateDynamicObject(851, 57.5946, -218.4143, 0.8482, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_2
    tempobjid = CreateDynamicObject(639, 45.5541, -233.6437, 1.9752, 0.0000, 4.3997, 134.3997, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 52.1991, -227.1087, 1.9737, 0.0000, 4.3997, 134.3997, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(2974, 189.9257, -316.3291, 1.3494, 0.0000, -90.1996, 50.5998, -1, -1, -1, 500.0000, 500.0000); //k_cargo1
    //CreateDynamicObject(874, 53.9071, -229.2595, 1.5571, 0.0000, 0.0000, -45.2999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 67.4811, -246.2671, 1.4278, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(8335, 189.7120, -302.9317, 4.5521, 0.0000, 0.0000, -0.3998, -1, -1, -1, 500.0000, 500.0000); //vgsfrates08
    tempobjid = CreateDynamicObject(19321, 187.8764, -318.7878, 1.9644, 0.1000, 0.1000, -36.3997, -1, -1, -1, 500.0000, 500.0000); //cuntainer
    tempobjid = CreateDynamicObject(2975, 187.1569, -320.1559, 1.0621, -51.8997, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //k_cargo3
    tempobjid = CreateDynamicObject(2676, 186.6746, -320.3446, 0.7081, 0.0000, 0.0000, 81.5998, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_8
    tempobjid = CreateDynamicObject(3062, 183.8954, -320.5848, 1.8637, -21.1998, 0.0000, -60.0998, -1, -1, -1, 500.0000, 500.0000); //container_door
    tempobjid = CreateDynamicObject(3062, 185.6472, -324.2998, 0.5756, -89.7994, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //container_door
    tempobjid = CreateDynamicObject(850, 183.7523, -323.6177, 0.6779, 0.0000, 0.0000, 60.9999, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_1
    tempobjid = CreateDynamicObject(849, 185.2037, -322.1148, 0.8679, 0.0000, 0.0000, -15.3000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3
    //CreateDynamicObject(874, 195.1029, -317.7723, 0.8798, 0.0000, 0.0000, -18.2999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19970, 198.7055, -316.3709, 0.5112, -12.1000, 0.0000, 88.7994, -1, -1, -1, 500.0000, 500.0000); //SAMPRoadSign23
    tempobjid = CreateDynamicObject(636, 196.0964, -323.7669, 1.5712, -1.2999, -92.6996, -106.9999, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(2345, 195.3491, -316.6477, 2.8940, 0.0000, 0.0000, -12.2999, -1, -1, -1, 500.0000, 500.0000); //Plant_Pot_23
    tempobjid = CreateDynamicObject(3594, 179.5525, -305.3981, 1.1763, 0.0000, 0.0000, -14.8000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, 177.8448, -311.0859, 1.2329, 0.0000, 0.0000, -159.0997, -1, -1, -1, 500.0000, 500.0000); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(854, 178.9355, -309.1405, 0.8022, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3b
    //CreateDynamicObject(874, 179.3838, -308.2001, 1.0721, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -100.6707, -99.8339, 3.7170, 0.0000, 0.0000, -9.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3566, 191.0115, -336.7247, 2.9683, 0.0000, 0.0000, 120.8000, -1, -1, -1, 500.0000, 500.0000); //lasntrk1
    //CreateDynamicObject(874, 180.7388, -335.6986, 1.3308, 0.0000, 0.0000, 88.6996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 171.3083, -337.9613, 1.5309, 0.0000, 0.0000, -124.0998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3571, 190.4929, -320.0841, 1.8975, 0.0000, 0.0000, 53.4999, -1, -1, -1, 500.0000, 500.0000); //lasdkrt3
    tempobjid = CreateDynamicObject(3572, 190.2669, -319.7809, 4.6683, 5.5998, 0.0000, 53.6999, -1, -1, -1, 500.0000, 500.0000); //lasdkrt4
    tempobjid = CreateDynamicObject(721, 136.0579, -382.6499, -0.0013, -66.9000, 0.0000, 27.8999, -1, -1, -1, 500.0000, 500.0000); //veg_largefurs02
    tempobjid = CreateDynamicObject(16305, 133.3164, -378.1127, 8.6365, 1.8997, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //des_gravelpile06
    SetDynamicObjectMaterial(tempobjid, 0, 5397, "barrio1_lae", "dirtgaz64b", 0x00000000);
    //CreateDynamicObject(874, 145.6260, -372.7878, 5.6476, 5.7999, 0.0000, 34.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 138.4304, -367.6246, 6.2526, 3.6998, 3.5999, 73.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -111.3876, -200.5041, 10.7349, 0.0000, 0.0000, -117.5000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -116.3067, -197.9772, 10.7349, 0.0000, 0.0000, -117.5000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -132.5395, -189.8314, 10.7349, 0.0000, 0.0000, -117.5000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -142.7684, -184.6192, 10.7349, 0.0000, 0.0000, -116.4001, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -157.5263, -177.1257, 10.7349, 0.0000, 0.0000, -117.4000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -165.3759, -173.1470, 10.7349, 0.0000, 0.0000, -117.4000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -162.7281, -175.9562, 10.7349, 0.0000, 0.0000, 63.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -151.6593, -181.5231, 10.7349, 0.0000, 0.0000, 63.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -124.8134, -195.0252, 10.7349, 0.0000, 0.0000, 63.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -172.5753, -171.8683, 10.7748, 0.0000, 0.0000, 77.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -184.7839, -169.2303, 10.7748, 0.0000, 0.0000, 77.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -190.5478, -168.0664, 10.8746, 0.0000, 0.0000, 77.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -208.1195, -163.9924, 10.9649, 0.0000, 0.0000, 77.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -217.2144, -162.0005, 11.2545, 0.0000, 0.0000, 78.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -178.3056, -169.3314, 10.7748, 0.0000, 0.0000, -102.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -198.4828, -164.8435, 11.0747, 0.0000, 0.0000, -102.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -224.6381, -164.3813, 10.9347, 4.2999, 0.0000, -36.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -229.1712, -170.7738, 10.3451, 2.4999, 0.0000, -34.7999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -234.2001, -177.6943, 10.2117, 0.1999, 0.0000, -34.7999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -133.3130, -178.6334, 5.4580, 0.0000, 0.0000, 79.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -123.0000, -180.4479, 5.4580, 0.0000, 0.0000, 80.0998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -133.2351, -178.3018, 5.4580, 0.0000, 0.0000, -99.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -122.9875, -180.0756, 5.4580, 0.0000, 0.0000, -99.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -101.5547, -103.7050, 4.8972, 33.4000, 0.0000, -9.0999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -100.2796, -95.7434, 4.8832, -34.9000, 0.0000, -9.0999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -104.2425, -105.6371, 2.5992, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -70.0410, -100.5652, 4.9173, 31.8999, 0.0000, 170.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -71.3848, -108.7209, 4.7101, -33.8997, 0.0000, 170.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -70.9529, -104.4729, 3.9126, -0.7997, 0.0000, 170.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -147.4591, -87.4347, 4.9868, -34.9000, 0.0000, -9.0999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -148.7086, -95.4272, 4.9380, 33.4000, 0.0000, -9.0999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -147.7928, -91.7496, 3.7170, 0.0000, 0.0000, -9.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -118.6087, -100.3451, 4.9109, -33.8997, 0.0000, 170.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -117.1975, -92.1483, 4.8755, 31.8999, 0.0000, 170.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -118.1333, -96.0223, 3.9179, -0.7997, 0.0000, 170.2998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -100.2509, -51.9598, 4.7434, -31.7000, 0.0000, 71.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -92.5680, -54.6052, 5.0514, 32.6999, 0.0000, 71.0000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -96.2406, -53.0722, 3.9051, 0.0000, 0.0000, 70.8000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(13367, -121.8796, -87.3470, 7.9008, 42.5998, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sw_watertower01
    tempobjid = CreateDynamicObject(10984, -124.6464, -80.4085, 2.8582, 0.0000, 0.0000, -100.2994, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    //CreateDynamicObject(874, -104.2425, -95.0774, 2.4293, 0.0000, 0.0000, -30.6000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -112.9016, -89.9561, 2.4293, 0.0000, 0.0000, -30.6000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -116.9449, -102.1567, 2.4293, 0.0000, 0.0000, -42.0998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -123.9309, -77.6921, 2.7792, 0.0000, 0.0000, -97.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -119.5317, -86.8320, 8.3682, 41.6999, 0.0000, 176.0001, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -118.8069, -82.7321, 4.6876, 41.6999, 13.1000, 176.0001, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -124.8666, -82.6744, 4.3193, -41.3997, 9.2999, 4.6001, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -124.5167, -86.5820, 8.0943, -45.0998, 9.2999, 4.6001, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -95.4457, -87.1100, 2.4293, 0.0000, 0.0000, 74.8999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -81.7770, -90.5942, 2.4293, 0.0000, 0.0000, -101.6996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -70.9738, -91.2899, 2.4293, 0.0000, 0.0000, -101.6996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -136.8630, -81.3990, 2.5692, 0.0000, 0.0000, -97.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -147.2288, -81.7842, 2.5692, 0.0000, 0.0000, -47.2999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -153.1284, -92.4196, 2.5692, 0.0000, 0.0000, 167.6000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -145.2924, -108.9253, 2.5692, 0.0000, 0.0000, -105.0998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -133.3108, -112.1583, 2.5692, 0.0000, 0.0000, 70.1996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10986, -102.3479, 21.0142, 3.3396, 0.0000, 5.1999, 111.5998, -1, -1, -1, 500.0000, 500.0000); //rubbled03_SFS
    //CreateDynamicObject(874, -101.5242, -116.8317, 2.5692, 0.0000, 0.0000, 80.6996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(826, 143.6851, -372.9465, 6.0907, 8.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    //CreateDynamicObject(874, -88.2807, -119.0000, 2.5692, 0.0000, 0.0000, 80.6996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -73.9017, -117.5009, 2.5692, 0.0000, 0.0000, 116.0998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3276, -106.9400, -134.9268, 2.1995, -91.7994, 0.0000, -57.9000, -1, -1, -1, 500.0000, 500.0000); //cxreffencesld
    //CreateDynamicObject(874, -93.2416, -78.9421, 2.4293, 0.0000, 0.0000, 88.7994, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1437, 105.2590, -292.0274, 15.4167, -10.8000, 0.0000, 176.0997, -1, -1, -1, 500.0000, 500.0000); //DYN_LADDER_2
    //CreateDynamicObject(874, -95.9784, -62.2966, 2.4293, 0.0000, 0.0000, 115.6996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -107.9514, -59.0475, 2.4293, 0.0000, 0.0000, -165.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -136.5437, -168.5877, 2.2362, 0.0000, 0.0000, -22.2999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -115.5578, -174.8170, 1.9062, 0.0000, 0.0000, -22.2999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(2908, -48.9191, 26.9139, 12.6989, -102.9999, 6.4000, 86.0998, -1, -1, -1, 500.0000, 500.0000); //kmb_deadhead
    tempobjid = CreateDynamicObject(3594, 85.9813, -239.9963, 2.6730, -31.3999, 0.0000, 57.9000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3375, -59.8213, -45.2014, 4.3144, -12.3999, 0.0000, 74.9000, -1, -1, -1, 500.0000, 500.0000); //CE_dblbarn01
    tempobjid = CreateDynamicObject(3375, -104.8498, 0.2389, 5.7245, 0.0000, -7.1999, 81.0998, -1, -1, -1, 500.0000, 500.0000); //CE_dblbarn01
    tempobjid = CreateDynamicObject(1224, 84.2162, -236.2657, 1.1677, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //woodenbox
    tempobjid = CreateDynamicObject(2676, 82.4570, -237.1210, 0.6789, 0.0000, 0.0000, -51.1999, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_8
    //CreateDynamicObject(874, 91.8302, -235.1071, 1.1317, 0.0000, 0.0000, 92.3999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10985, -96.2664, 17.8826, 3.3032, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled02_SFS
    tempobjid = CreateDynamicObject(10985, -108.0009, 20.1907, 3.0631, 0.0000, -2.9999, -167.1997, -1, -1, -1, 500.0000, 500.0000); //rubbled02_SFS
    tempobjid = CreateDynamicObject(12957, 82.2798, -258.0794, 1.2487, 0.0000, 0.0000, -24.3999, -1, -1, -1, 500.0000, 500.0000); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3594, 84.8199, -263.4880, 1.1467, 0.0000, 0.0000, -145.3999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(10984, -111.3535, -12.6822, 2.8556, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(10984, -97.5036, -15.2423, 2.8556, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(3593, 86.0429, -258.4960, 1.7523, 11.8000, 0.0000, 95.5000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(10985, -61.0315, -29.3885, 2.8931, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled02_SFS
    //CreateDynamicObject(874, 86.0979, -259.8074, 1.3249, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10985, -99.6006, 5.4422, 2.7332, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled02_SFS
    tempobjid = CreateDynamicObject(826, 86.8516, -261.2760, 2.0083, 0.0000, 0.0000, -52.7000, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    tempobjid = CreateDynamicObject(10984, -49.8017, -34.0675, 3.1356, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(10985, -59.3927, -67.9869, 2.8931, 0.0000, 0.0000, -97.6996, -1, -1, -1, 500.0000, 500.0000); //rubbled02_SFS
    //CreateDynamicObject(874, -74.8114, -64.5662, 2.4293, 0.0000, 0.0000, -177.1999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10985, -66.5279, -54.2854, 2.9031, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled02_SFS
    tempobjid = CreateDynamicObject(832, -78.1648, -70.0214, 3.7718, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //DEAD_TREE_4
    //CreateDynamicObject(874, -62.8027, -70.0326, 2.9793, 0.0000, 0.0000, 72.7994, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -61.5037, -25.2227, 2.8893, 0.0000, 0.0000, 72.7994, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -49.9164, -27.0510, 2.8893, 0.0000, 0.0000, 72.7994, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -115.8218, -49.2252, 2.4293, 0.0000, 0.0000, -165.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -118.3451, -39.4664, 2.4293, 0.0000, 0.0000, 166.1999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -115.5307, -28.0069, 2.4293, 0.0000, 0.0000, 166.1999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -115.0046, -17.8712, 2.4293, 0.0000, 0.0000, -155.8000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -98.9036, -20.6044, 2.4293, 0.0000, 0.0000, -99.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -92.9766, -12.7650, 2.4293, 0.0000, 0.0000, -29.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -91.2070, 2.7407, 2.4293, 0.0000, 0.0000, -14.1000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -90.4868, 18.0051, 2.8893, 0.0000, 6.3997, -14.1000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -107.5195, 25.0904, 2.6993, 0.0000, 0.0000, 62.6999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -96.0494, 26.7324, 2.6993, 0.0000, 0.0000, 62.6999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(703, -108.3507, -50.9662, 1.2640, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(703, -130.3307, -67.9362, 1.1038, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(3566, 133.1044, -252.4667, 2.9514, 0.0000, 0.0000, -103.3000, -1, -1, -1, 500.0000, 500.0000); //lasntrk1
    tempobjid = CreateDynamicObject(3566, 132.3191, -263.0191, 2.2018, 0.0000, 90.0998, -78.0998, -1, -1, -1, 500.0000, 500.0000); //lasntrk1
    tempobjid = CreateDynamicObject(3566, 109.2618, -233.3625, 2.9514, 0.0000, 0.0000, 39.2999, -1, -1, -1, 500.0000, 500.0000); //lasntrk1
    tempobjid = CreateDynamicObject(2675, 104.2907, -227.3845, 0.6455, 0.0000, 0.0000, -21.7999, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_6
    tempobjid = CreateDynamicObject(639, -88.0000, -53.0092, 2.7871, 0.0000, 0.0000, 161.6000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -85.3805, -45.3245, 2.7871, 0.0000, 0.0000, 160.4001, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -79.9235, -29.7315, 2.7871, 0.0000, 0.0000, 160.4001, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(826, 100.3199, -234.6914, 0.9993, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    tempobjid = CreateDynamicObject(3593, -119.7789, -183.5917, 1.2789, 0.0000, 0.0000, 50.7999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    //CreateDynamicObject(874, 73.5745, -231.0599, 1.1943, 0.0000, -1.6999, 28.7000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, -137.8616, -184.4313, 1.3961, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3171, -126.6445, -197.7286, 0.9049, 0.0000, -34.7999, 75.9000, -1, -1, -1, 500.0000, 500.0000); //trailer5_01
    tempobjid = CreateDynamicObject(12957, 68.5634, -226.9689, 1.2079, 0.0000, 0.0000, -35.2000, -1, -1, -1, 500.0000, 500.0000); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(1756, 68.9570, -226.6060, 1.0305, 0.0000, 0.0000, 31.1000, -1, -1, -1, 500.0000, 500.0000); //LOW_COUCH_4
    tempobjid = CreateDynamicObject(703, -96.9207, -139.7733, 0.9840, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(2671, 70.7397, -224.0433, 0.5755, 0.0000, 0.0000, -47.2999, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_3
    tempobjid = CreateDynamicObject(10985, -67.4169, -36.9257, 2.1131, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled02_SFS
    //CreateDynamicObject(874, -87.8973, -54.7178, 2.4293, 0.0000, 0.0000, 138.9998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -82.4754, -45.1156, 2.4293, 0.0000, 0.0000, 145.0997, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -146.6121, -62.1669, 2.4293, 0.0000, 0.0000, -165.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(10984, -116.5585, 12.1686, 2.1356, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(10984, -111.6007, 2.9971, 2.2855, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(3171, -142.0567, -61.9089, 1.9845, 0.0000, 0.0000, -142.2998, -1, -1, -1, 500.0000, 500.0000); //trailer5_01
    tempobjid = CreateDynamicObject(13591, 117.3703, -265.9988, 0.8820, 0.0000, 0.0000, 35.3997, -1, -1, -1, 500.0000, 500.0000); //kickcar28
    tempobjid = CreateDynamicObject(3172, -134.3032, -40.5550, 2.0487, 0.0000, 0.0000, 121.3999, -1, -1, -1, 500.0000, 500.0000); //trailer6_01
    //CreateDynamicObject(874, 118.3283, -265.4168, 1.2092, 0.0000, 0.0000, -55.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1362, -134.0883, -43.3111, 2.6236, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_FIREBIN_(L0)
    tempobjid = CreateDynamicObject(1224, 112.1455, -257.7055, 4.6543, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //woodenbox
    tempobjid = CreateDynamicObject(1362, -141.3182, -58.4911, 2.6236, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_FIREBIN_(L0)
    tempobjid = CreateDynamicObject(18693, -134.1717, -43.3017, 1.0571, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //Flame99
    tempobjid = CreateDynamicObject(2673, 110.9925, -258.9140, 4.1339, 0.0000, 0.0000, 33.6999, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_5
    tempobjid = CreateDynamicObject(826, 110.3964, -264.7976, 2.0294, 0.0000, 0.0000, 64.5998, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    tempobjid = CreateDynamicObject(1440, -141.6154, -51.8389, 2.5973, 0.0000, 0.0000, 68.8999, -1, -1, -1, 500.0000, 500.0000); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(639, 98.2789, -239.4528, 5.3168, 0.2998, 4.0998, -36.4999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(1265, -134.7987, -42.8871, 2.5438, 0.0000, 0.0000, 30.5000, -1, -1, -1, 500.0000, 500.0000); //BlackBag2
    tempobjid = CreateDynamicObject(1265, -134.0146, -42.4253, 2.5438, 0.0000, 0.0000, -161.8999, -1, -1, -1, 500.0000, 500.0000); //BlackBag2
    tempobjid = CreateDynamicObject(1711, -138.9803, -62.4435, 2.0652, 0.0000, 0.0000, 140.5000, -1, -1, -1, 500.0000, 500.0000); //kb_chair01
    tempobjid = CreateDynamicObject(639, 92.0690, -247.8450, 5.2621, 0.2998, 4.0998, -36.4999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(672, -147.3385, -55.7649, 2.6461, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree5
    tempobjid = CreateDynamicObject(636, 95.3973, -243.4691, 5.7575, -0.6998, -90.3000, -36.4000, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(3594, -134.4566, -56.8763, 2.5557, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -129.2946, -42.9510, 2.5473, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(636, 89.2235, -252.0133, 5.7568, -0.6998, -90.3000, -36.4000, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(2907, -138.9848, -62.5396, 2.7030, -58.3997, 0.6998, 0.0000, -1, -1, -1, 500.0000, 500.0000); //kmb_deadtorso
    tempobjid = CreateDynamicObject(2908, -139.2666, -62.1380, 2.5929, 0.0000, 0.0000, -73.3999, -1, -1, -1, 500.0000, 500.0000); //kmb_deadhead
    //CreateDynamicObject(874, -148.3027, -71.1684, 2.5692, 0.0000, 0.0000, -26.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -130.7066, -129.6336, 2.5692, 0.0000, 0.0000, 70.1996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -102.9766, -134.0879, 2.5692, 0.0000, 0.0000, 42.9000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 103.9869, -251.5484, 5.3495, 0.0000, 3.8998, 143.4998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(800, -101.0920, -31.8845, 3.1171, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bush07
    tempobjid = CreateDynamicObject(639, 98.0811, -259.6307, 5.3537, 0.0000, 3.8998, 143.4998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(636, 107.0960, -247.1434, 5.8656, -0.8999, -90.3000, 144.4998, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(636, 101.0205, -255.6441, 5.7016, -0.8999, -90.3000, 144.4998, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb2
    tempobjid = CreateDynamicObject(639, 110.0557, -237.0321, 3.5787, 0.0000, 4.1999, 38.7999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3374, -76.8102, -3.5920, 1.8844, 15.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //SW_haybreak02
    tempobjid = CreateDynamicObject(635, 103.7545, -226.5433, 4.9229, 0.0000, -92.5000, -51.2999, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb1
    //CreateDynamicObject(874, -79.5643, -22.8705, 2.4293, 0.0000, 0.0000, 176.1000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -78.5597, -8.1344, 2.4293, 0.0000, 0.0000, 176.1000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 108.8554, -269.9125, 1.5255, 0.0000, 0.0000, 29.2000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 104.3133, -229.9969, 3.5782, 0.0000, 4.1999, 38.4000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3374, -78.6902, -11.1875, 2.0645, -14.7999, 0.0000, 53.2999, -1, -1, -1, 500.0000, 500.0000); //SW_haybreak02
    tempobjid = CreateDynamicObject(639, -66.8283, 32.7999, 3.6670, 0.0000, 0.0000, 70.8999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 113.3404, -228.5121, 1.5470, 0.0000, 0.0000, 13.3999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 133.9089, -270.3753, 1.6353, 0.0000, 0.0000, -91.0998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3374, -53.9803, -4.8449, 1.5915, -19.2999, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //SW_haybreak02
    tempobjid = CreateDynamicObject(826, 125.0593, -269.0685, 1.8681, 0.0000, 0.0000, -38.0998, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    //CreateDynamicObject(874, -32.7486, 30.2056, 2.6470, 0.0000, 0.0000, -25.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 154.3898, -275.9169, 2.6319, 0.0000, 0.0000, 90.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -28.3962, 39.3306, 2.6470, 0.0000, 0.0000, -25.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -23.9402, 48.6725, 2.6470, 0.0000, 0.0000, -25.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -16.5753, 45.1595, 2.6470, 0.0000, 0.0000, -25.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -12.6920, 53.3008, 2.6470, 0.0000, 0.0000, -25.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 146.9799, -275.9428, 2.6319, 0.0000, 0.0000, 90.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -6.6391, 65.9913, 2.6470, 0.0000, 0.0000, -25.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -1.2783, 84.8824, 2.6470, 0.0000, 0.0000, 5.9000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 143.7212, -267.5974, 6.5419, 0.0000, 0.0000, 0.1999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -2.3896, 73.6147, 7.8371, -36.8997, 0.0000, 142.6997, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -1.6418, 75.8124, 7.9928, 38.7000, -1.2999, 175.3997, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 132.0281, -229.4734, 1.5111, 0.0000, 0.0000, -92.9000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -6.8179, 65.1856, 3.6519, 0.0000, 0.0000, 159.1997, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 143.0941, -230.0339, 1.5111, 0.0000, 0.0000, -113.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 156.4718, -227.7295, 1.0812, 0.0000, 0.0000, 83.8999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -8.3465, 61.1613, 4.7877, 24.2999, 0.0000, 159.1997, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -13.0052, 48.8964, 4.6406, -25.4999, 0.0000, 159.1997, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -24.2341, 71.6557, 3.2976, 0.0000, 0.0000, -22.5000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -22.7458, 75.5625, 4.7213, 25.8999, 0.0000, -22.5000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -22.0102, 80.3917, 7.8003, 32.5000, 0.0000, -4.2999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(1457, 169.8186, -224.8928, 2.2318, 0.0000, 0.0000, -105.3000, -1, -1, -1, 500.0000, 500.0000); //DYN_OUTHOUSE_2
    tempobjid = CreateDynamicObject(639, -21.0592, 83.1311, 8.0024, -38.0998, 0.0000, -36.9999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -25.7677, 67.9151, 4.6434, -23.2000, -1.0000, -20.2999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(1793, 171.8854, -225.8721, 0.2942, 0.0000, 0.0000, 78.7994, -1, -1, -1, 500.0000, 500.0000); //LOW_BED_2
    tempobjid = CreateDynamicObject(639, -18.3041, 87.6854, 4.8164, -25.2999, 0.0000, -24.1998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -28.5053, 63.3106, 7.8263, -35.5998, -2.6998, -38.4000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -20.5771, 88.3765, 3.0257, 0.0000, 0.0000, -35.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19632, 167.1665, -227.0980, 0.5669, 0.0000, 0.0000, 39.9999, -1, -1, -1, 500.0000, 500.0000); //FireWood1
    tempobjid = CreateDynamicObject(639, -29.3987, 60.5844, 7.7705, 34.2999, -2.6998, -2.3998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -27.8316, 75.1166, 3.0257, 0.0000, 0.0000, 139.6999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1810, 167.8896, -227.2980, 0.5695, 0.0000, 0.0000, -105.6996, -1, -1, -1, 500.0000, 500.0000); //CJ_FOLDCHAIR
    //CreateDynamicObject(874, -31.0186, 61.6777, 3.0257, 0.0000, 0.0000, 157.9998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1764, 165.7075, -223.1799, 0.5328, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //LOW_COUCH_2
    //CreateDynamicObject(874, -39.8590, 85.3162, 3.0257, 0.0000, 0.0000, 139.6999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -44.0909, 71.8942, 3.0257, 0.0000, 0.0000, 164.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -30.3201, 55.4798, 4.6644, 23.8999, -2.6998, -18.2999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -46.6884, 62.5278, 3.0257, 0.0000, 0.0000, 164.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 242.5210, -294.6864, 1.2281, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(639, 164.2483, -222.5973, 2.1071, 0.0000, 1.7999, 90.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(703, -43.9883, 79.7543, 1.4182, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(2672, 166.7975, -224.6257, 0.8481, 0.0000, 0.0000, -38.6999, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_4
    tempobjid = CreateDynamicObject(16444, 163.6394, -224.1795, 0.7620, 0.0000, 0.0000, -101.3999, -1, -1, -1, 500.0000, 500.0000); //des_blackbags
    tempobjid = CreateDynamicObject(639, 150.2781, -222.6636, 2.1047, 0.0000, 1.7999, 90.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(12911, -78.4355, 95.7005, -3.5002, -24.0998, -13.3000, -19.4999, -1, -1, -1, 500.0000, 500.0000); //sw_Silo02
    tempobjid = CreateDynamicObject(10984, 147.6719, -226.8244, 0.2193, -1.5999, -5.1999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(10984, -81.7014, 87.0755, 2.7256, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(10984, -77.4719, 100.7052, 2.7256, 0.0000, 0.0000, -21.5000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    tempobjid = CreateDynamicObject(10984, -74.8656, 107.3208, 2.0555, 0.0000, 0.0000, -21.5000, -1, -1, -1, 500.0000, 500.0000); //rubbled01_SFS
    //CreateDynamicObject(874, -78.0979, 86.3375, 3.0257, 0.0000, 0.0000, 164.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 126.0604, -240.1571, 1.1167, 0.0000, 0.0000, 68.7994, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    //CreateDynamicObject(874, -75.8700, 99.9468, 3.0257, 0.0000, 0.0000, 164.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -73.1442, 109.7761, 3.0257, 0.0000, 0.0000, 164.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 125.0270, -242.6649, 1.5864, -10.5000, 0.0000, 143.1999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(639, -42.6693, 56.9034, 4.9081, 32.5000, 0.0000, -108.2994, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(826, 124.8973, -241.8665, 2.0016, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    tempobjid = CreateDynamicObject(639, -34.8983, 54.1649, 4.8585, -35.2999, 0.0000, -108.2994, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, 131.3309, -248.3439, 1.2065, 0.0000, 0.0000, -122.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 119.1166, -242.8105, 1.4931, 0.0000, 0.0000, -14.1997, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -60.5013, 62.6427, 4.9723, 32.9000, -0.4999, -108.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -53.0231, 60.0746, 4.8291, -34.7999, -0.4999, -108.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -72.6100, 57.1417, 3.0257, 0.0000, 0.0000, 156.5997, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -82.9812, 55.9902, 2.6459, 0.0000, 0.0000, 119.9000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 129.6533, -257.6965, 1.3659, 0.0000, 0.0000, -110.0998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 168.4472, -291.2402, 1.7013, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, -32.4696, 166.3195, 6.1451, 0.0000, 0.0000, -119.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -27.3551, 163.3784, 6.1451, 0.0000, 0.0000, -119.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, -23.5841, 161.2100, 6.1451, 0.0000, 0.0000, -119.9000, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -20.0023, 146.7384, 2.7302, 0.0000, 0.0000, -28.0998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -39.8246, 157.7872, 2.7302, 0.0000, 0.0000, -28.0998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -26.9752, 128.6000, 2.7302, 0.0000, 0.0000, 30.6000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -51.2541, 142.2377, 2.7302, 0.0000, 0.0000, 39.2000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(703, -18.2614, 143.1750, 1.0540, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree7_big
    //CreateDynamicObject(874, -51.5508, 112.3871, 2.7170, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -62.9709, 112.3871, 2.7170, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3037, 86.0130, -293.1390, 2.5992, 0.0000, 21.5000, -126.2994, -1, -1, -1, 500.0000, 500.0000); //warehouse_door2b
    //CreateDynamicObject(874, -77.7188, 31.5209, 3.1171, 0.0000, 0.0000, 68.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -59.9514, 26.2112, 3.1171, 0.0000, 0.0000, 68.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(13591, 90.3358, -310.8240, 0.9480, 0.0000, 0.0000, -12.8000, -1, -1, -1, 500.0000, 500.0000); //kickcar28
    //CreateDynamicObject(874, -41.6347, 19.1800, 3.1171, 0.0000, 0.0000, 68.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -47.2215, 4.6255, 3.1171, 0.0000, 0.0000, 68.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(13591, 90.1986, -302.7438, 0.8780, 0.0000, 0.0000, -164.0000, -1, -1, -1, 500.0000, 500.0000); //kickcar28
    //CreateDynamicObject(874, -53.5326, -11.8147, 2.4769, 0.0000, 0.0000, 95.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(19087, 89.0485, -314.0697, 8.4594, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //Rope1
    tempobjid = CreateDynamicObject(639, -82.4944, -25.6755, 4.9159, -35.4999, 0.0000, -109.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(3092, 89.0214, -313.8901, 5.8326, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //dead_tied_cop
    tempobjid = CreateDynamicObject(639, -90.0734, -23.1019, 4.9113, 35.5998, 0.0000, -109.3999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(16444, 93.2266, -313.8601, 0.7781, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //des_blackbags
    tempobjid = CreateDynamicObject(3171, -81.8936, 6.8667, 1.9744, 0.0000, 0.0000, -179.1000, -1, -1, -1, 500.0000, 500.0000); //trailer5_01
    tempobjid = CreateDynamicObject(849, 90.6964, -314.5285, 0.8402, 0.0000, 0.0000, -58.2000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(2670, 88.9290, -314.2789, 0.6521, 0.0000, 0.0000, 66.1996, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_1
    tempobjid = CreateDynamicObject(3171, -80.8572, 15.0754, 1.9744, 0.0000, 0.0000, 164.8999, -1, -1, -1, 500.0000, 500.0000); //trailer5_01
    tempobjid = CreateDynamicObject(1760, -80.2742, 10.0677, 2.1401, 0.0000, 0.0000, 76.5998, -1, -1, -1, 500.0000, 500.0000); //MED_COUCH_2
    tempobjid = CreateDynamicObject(3172, -69.1604, 6.1841, 1.9788, 0.0000, 0.0000, -31.2999, -1, -1, -1, 500.0000, 500.0000); //trailer6_01
    tempobjid = CreateDynamicObject(1437, 84.2238, -313.9591, 0.6219, -80.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //DYN_LADDER_2
    tempobjid = CreateDynamicObject(1442, -80.1397, 4.6269, 2.6637, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(1442, -72.5297, 4.6269, 2.6637, 0.0000, 0.0000, -49.4999, -1, -1, -1, 500.0000, 500.0000); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(1442, -78.2974, 16.5998, 2.6637, 0.0000, 0.0000, -49.4999, -1, -1, -1, 500.0000, 500.0000); //DYN_FIREBIN0
    tempobjid = CreateDynamicObject(18693, -80.1688, 4.6563, 1.0971, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //Flame99
    tempobjid = CreateDynamicObject(1810, 86.2891, -314.2502, 0.5569, 0.0000, 0.0000, 148.6999, -1, -1, -1, 500.0000, 500.0000); //CJ_FOLDCHAIR
    tempobjid = CreateDynamicObject(1440, -70.1455, 8.6597, 2.5573, 0.0000, 0.0000, -123.5998, -1, -1, -1, 500.0000, 500.0000); //DYN_BOX_PILE_3
    tempobjid = CreateDynamicObject(1265, -79.8003, 12.9511, 2.4537, 0.0000, 0.0000, -24.3999, -1, -1, -1, 500.0000, 500.0000); //BlackBag2
    tempobjid = CreateDynamicObject(1265, -79.6884, 13.7791, 2.4537, 0.0000, 0.0000, -24.3999, -1, -1, -1, 500.0000, 500.0000); //BlackBag2
    tempobjid = CreateDynamicObject(1265, -79.9393, 13.5635, 2.7537, 0.0000, 0.0000, -24.3999, -1, -1, -1, 500.0000, 500.0000); //BlackBag2
    tempobjid = CreateDynamicObject(1450, -68.2733, 11.4160, 2.6833, 0.0000, 0.0000, -117.5998, -1, -1, -1, 500.0000, 500.0000); //DYN_CRATE_3
    tempobjid = CreateDynamicObject(1328, -80.1902, 8.9630, 2.3187, 93.3999, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //BinNt10_LA
    tempobjid = CreateDynamicObject(1362, 85.5615, -314.4176, 1.1426, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_FIREBIN_(L0)
    tempobjid = CreateDynamicObject(2673, -79.6007, 10.0158, 2.2070, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_5
    tempobjid = CreateDynamicObject(18693, 85.5651, -314.3952, -0.4744, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //Flame99
    //CreateDynamicObject(874, -62.6753, 5.9734, 2.7070, 0.0000, 0.0000, -20.2000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 90.5167, -288.6076, 1.6892, 0.0000, 0.0000, 36.4000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 90.6144, -301.5332, 0.8094, 0.0000, 0.0000, -7.9998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(691, -82.9813, 27.0510, 0.5659, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree4_big
    tempobjid = CreateDynamicObject(826, 87.2602, -296.3771, 1.7862, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    tempobjid = CreateDynamicObject(2675, 86.3861, -314.1318, 0.6603, 0.0000, 0.0000, -84.8000, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_6
    //CreateDynamicObject(874, 42.2257, -226.9924, 1.9723, 0.0000, 0.0000, -58.2000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(7025, 156.6855, -313.6994, 3.9867, 0.0000, 0.0000, -74.9000, -1, -1, -1, 500.0000, 500.0000); //plantbox1
    //CreateDynamicObject(874, 154.8069, -323.2944, 1.7726, 0.0000, 0.0000, 46.1999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3276, -93.0923, -76.5923, 2.2053, 86.0998, 0.0000, 17.0000, -1, -1, -1, 500.0000, 500.0000); //cxreffencesld
    tempobjid = CreateDynamicObject(3171, -341.9472, 12.4889, 7.6272, 3.1998, 0.0000, 159.7998, -1, -1, -1, 500.0000, 500.0000); //trailer5_01
    tempobjid = CreateDynamicObject(3276, -39.5494, 115.4278, 2.1923, 92.3999, 0.0000, -55.5998, -1, -1, -1, 500.0000, 500.0000); //cxreffencesld
    tempobjid = CreateDynamicObject(3276, -63.1632, 131.9884, 2.1932, 94.1996, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //cxreffencesld
    //CreateDynamicObject(874, -106.9698, 62.6623, 2.8392, 0.0000, 0.0000, -10.8999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -103.6303, 80.0037, 2.8392, 0.0000, 0.0000, 67.9000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(800, -7.9913, -198.6667, 1.5966, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bush07
    tempobjid = CreateDynamicObject(3593, -35.1212, -200.3925, 0.9652, 0.0000, 0.0000, 89.2994, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -35.3053, -202.9373, 1.4709, 8.5000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    //CreateDynamicObject(874, -34.8628, -197.4929, 1.4744, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3172, 15.7040, -202.9559, 1.6670, 0.0000, -84.4000, -94.5998, -1, -1, -1, 500.0000, 500.0000); //trailer6_01
    tempobjid = CreateDynamicObject(3594, 14.7627, -206.2509, 1.0253, 0.0000, 0.0000, 46.7000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 19.2392, -206.3305, 1.3861, -9.0999, 0.0000, -75.5998, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    //CreateDynamicObject(874, 18.4328, -200.5229, 1.4709, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(849, 18.6140, -207.7449, 0.7710, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3
    //CreateDynamicObject(874, -127.5214, -196.6475, 2.0968, 0.0000, 0.0000, 66.1996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(12957, -141.9886, -187.5068, 1.5592, 0.0000, 0.0000, 106.3999, -1, -1, -1, 500.0000, 500.0000); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(826, -139.7277, -179.2431, 2.0311, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    tempobjid = CreateDynamicObject(800, -260.8941, -151.6768, 2.3803, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bush07
    //CreateDynamicObject(874, -259.4703, -152.1853, 1.9793, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -220.3477, -162.0892, 1.9793, 0.0000, 0.0000, -99.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(1447, -325.9707, 5.0953, 6.9724, 0.0000, 8.9996, 68.0000, -1, -1, -1, 500.0000, 500.0000); //DYN_MESH_4
    tempobjid = CreateDynamicObject(1761, -339.8004, 13.3465, 7.3569, 0.0000, 4.0998, 69.3999, -1, -1, -1, 500.0000, 500.0000); //SWANK_COUCH_2
    tempobjid = CreateDynamicObject(19869, -326.6741, 9.6211, 5.5822, 0.0000, 3.9999, -47.2999, -1, -1, -1, 500.0000, 500.0000); //MeshFence2
    tempobjid = CreateDynamicObject(639, 292.9254, -371.0787, 7.3800, 0.0000, 0.0000, -103.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 287.9017, -369.9005, 7.3800, 0.0000, 0.0000, -104.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 283.3261, -368.7427, 7.3800, 0.0000, 0.0000, -104.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 277.8869, -367.5728, 7.3199, 0.0000, 0.0000, -103.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(672, -323.9801, 5.0440, 5.7382, 0.0000, 0.0000, 78.6996, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree5
    tempobjid = CreateDynamicObject(639, 272.5061, -366.2528, 7.2599, 0.0000, 0.0000, -104.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 266.9877, -364.8663, 7.3800, 0.0000, 0.0000, -104.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 262.1647, -363.7080, 7.2800, 0.0000, 0.0000, -104.1996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 251.1793, -382.2290, 6.8172, 0.0000, 0.0000, 76.4999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 256.3912, -383.4801, 6.8172, 0.0000, 0.0000, 76.4999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 261.7066, -384.9006, 6.8172, 0.0000, 0.0000, 76.4999, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 266.1823, -386.0057, 6.8242, 0.0000, 5.6999, 76.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    //CreateDynamicObject(874, -320.0038, 8.3198, 5.4762, 0.0000, 7.7999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(639, 270.7669, -387.1286, 6.8273, 0.0000, 5.6999, 76.5998, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(639, 276.0397, -388.4258, 6.8312, 0.0000, 5.6999, 75.6996, -1, -1, -1, 500.0000, 500.0000); //veg_ivy_balcny_kb3
    tempobjid = CreateDynamicObject(671, -314.2355, 10.4160, 3.9430, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_bushytree
    //CreateDynamicObject(874, 303.0166, -396.2359, 9.0094, 0.0000, 0.0000, 79.1996, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -329.8908, 8.2853, 6.8800, 0.0000, 3.1998, -29.7999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 307.4537, -372.9754, 8.9398, 0.0000, 0.0000, 75.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(703, 294.4093, -400.4779, 6.7375, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_veg_tree7_big
    tempobjid = CreateDynamicObject(826, -328.9356, 7.4867, 7.4871, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    tempobjid = CreateDynamicObject(3593, -302.6799, -67.5158, 0.3822, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -305.8546, -73.4057, 0.4767, 0.0000, 0.0000, 161.1999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(1299, -340.5504, 9.9256, 8.2503, -9.1997, 11.6000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //smashboxpile
    tempobjid = CreateDynamicObject(3593, -305.6575, -78.3721, 0.7989, 7.2999, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(1362, -338.5816, 16.2075, 7.7335, 0.0000, 7.1999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_FIREBIN_(L0)
    tempobjid = CreateDynamicObject(3593, -314.2502, -118.8544, 0.4683, 0.0000, 0.0000, 41.5998, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -317.4230, -119.5436, 1.0506, 0.0000, -10.5999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(18693, -338.5491, 16.2094, 6.1497, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //Flame99
    //CreateDynamicObject(874, -318.1502, -117.3404, 0.8528, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(2672, -338.2513, 13.8239, 7.3758, -0.5999, 8.3999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_4
    //CreateDynamicObject(874, -303.0177, -76.2412, 0.9394, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3172, -305.6184, -106.4412, 1.3075, 0.0000, -87.0998, -177.6999, -1, -1, -1, 500.0000, 500.0000); //trailer6_01
    tempobjid = CreateDynamicObject(2675, -340.1217, 8.6379, 8.0052, -14.6997, -4.2999, -67.0998, -1, -1, -1, 500.0000, 500.0000); //PROC_RUBBISH_6
    tempobjid = CreateDynamicObject(12957, -295.3150, -159.4434, 1.1382, 0.0000, 6.9998, 138.4998, -1, -1, -1, 500.0000, 500.0000); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(826, -295.1315, -158.5684, 1.8844, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_tallgrass10
    //CreateDynamicObject(874, -286.6145, -20.9827, 1.0779, 0.0000, 0.0000, -15.1997, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -283.5993, -9.8851, 1.0779, 0.0000, 0.0000, -15.1997, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -275.2301, 28.8631, 1.0779, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -260.3561, 63.4588, 0.8579, 0.0000, 0.0000, -27.6000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -306.9081, -14.1921, 1.8751, 0.0000, 16.1998, -20.2000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -301.6730, 10.8743, 2.3355, 0.0000, 22.1998, -16.2999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -278.1492, 75.9878, 1.6741, 0.0000, 18.8999, -19.7000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -264.9118, 115.1214, 1.7087, 0.0000, 10.0999, -21.9999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -255.4313, 139.1264, 2.5353, 0.0000, 12.3999, -31.6998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -241.6065, 115.0708, 1.4982, 0.0000, 0.0000, -21.6000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -226.3309, 153.4875, 3.7355, 8.0999, 0.0000, -25.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -222.4010, 164.4898, 5.2680, 8.0999, 0.0000, -25.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -242.4084, 174.6555, 5.8705, 10.6997, 4.0998, -30.2999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3593, -289.7908, 2.9820, 0.5083, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -288.4530, 9.9378, 0.6567, 0.0000, 0.0000, 162.0997, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, -280.1907, 47.5413, 0.6485, 0.0000, 0.0000, -55.2999, -1, -1, -1, 500.0000, 500.0000); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, -262.1817, 86.1417, 0.4083, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -260.5173, 92.5380, 0.6266, 0.0000, 0.0000, -20.7999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -264.6632, 92.6063, 0.9520, -7.9998, 0.0000, 55.0998, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3172, -246.4358, 148.3188, 1.3854, -3.9000, 0.0000, 157.8999, -1, -1, -1, 500.0000, 500.0000); //trailer6_01
    tempobjid = CreateDynamicObject(3594, -227.2113, 187.9470, 8.0390, 10.5000, 0.6998, -21.9999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, -226.5433, 196.8161, 9.4182, 4.1999, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    //CreateDynamicObject(874, -211.9463, 186.2044, 9.3940, 8.9996, 0.0000, -30.3999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, -236.5933, 199.2057, 10.3343, 2.5999, -4.3997, 73.1998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, -212.2292, 195.2933, 9.9723, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(3594, -245.1315, 157.3076, 2.9126, -7.8997, 0.0000, -175.1999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(825, -258.1473, 131.2510, 1.7345, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -247.6031, 108.9188, 1.0779, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -278.6451, 22.5023, 1.0779, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -307.7929, -22.0307, 1.4222, 7.6999, 14.8999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -293.7680, -57.7625, 1.4296, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, -318.6976, -112.9216, 1.0779, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    //CreateDynamicObject(874, -183.8798, -166.7503, 2.0529, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(849, -288.1329, 6.0886, 0.3276, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, -263.7077, 90.3143, 0.3368, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(3594, -198.7171, -173.8816, 1.6466, 0.0000, 0.0000, -76.6997, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -210.3065, -174.5164, 1.5784, 0.0000, 0.0000, 58.4000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, -265.2896, -157.3984, 1.9522, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, -260.8774, -159.4284, 1.7639, 0.0000, 0.0000, 70.5000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    //CreateDynamicObject(874, 342.5812, -379.8810, 15.0363, -15.8999, -0.5000, 78.4000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 349.4963, -381.3005, 17.0473, -15.8999, -0.5000, 78.4000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 369.5797, -406.4190, 22.7751, -5.6999, -4.9998, 76.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 379.5262, -408.8591, 24.3780, -5.6999, -4.9998, 76.4999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 391.3027, -390.5921, 26.4020, -5.2999, -2.1998, 83.1998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 415.0989, -414.3814, 26.7539, -5.0000, 0.0000, 81.7997, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 428.8255, -394.9205, 28.8075, 0.0000, -8.6000, 83.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 437.9782, -395.9472, 28.8075, 0.0000, -8.6000, 83.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 439.1954, -417.6953, 27.6417, 0.0000, -5.4000, 82.7997, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(3594, 408.3898, -405.8663, 25.6944, 1.5000, 6.0998, -101.0998, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 401.6643, -404.8370, 25.3637, 1.2999, 2.9999, -93.6997, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 340.7221, -386.3630, 14.1701, 14.9997, 0.0000, -96.8999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 333.7485, -385.3677, 12.4798, 12.7999, 1.1000, -96.8999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 301.2568, -386.0093, 8.4905, 0.0000, 0.0000, -109.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(12957, 295.2749, -384.0841, 8.5818, 0.7997, 0.0000, 71.8000, -1, -1, -1, 500.0000, 500.0000); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(3593, 276.0187, -374.2868, 8.3519, 0.0000, 0.0000, 88.0998, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 269.0000, -372.4815, 8.3971, 0.0000, 0.0000, -107.4000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 229.7324, -365.1152, 6.6668, -5.9998, -1.0999, 61.9999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    //CreateDynamicObject(874, 227.6392, -376.1325, 7.2912, 0.0000, -3.7999, 43.5998, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 215.3889, -367.0093, 5.6391, -4.9998, 0.0000, 29.1000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 204.3486, -354.6578, 3.8159, -4.5998, 0.0000, 24.5000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 222.9335, -372.9598, 6.4579, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 226.3000, -381.1954, 7.0068, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 206.9582, -364.5068, 5.3537, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(849, 337.1311, -386.8008, 12.9146, 0.0000, -13.5999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(849, 264.2166, -372.3070, 8.0495, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //CJ_urb_rub_3
    tempobjid = CreateDynamicObject(759, 258.0771, -265.5520, 0.1681, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sm_bush_large_1
    tempobjid = CreateDynamicObject(865, 258.2640, -295.1170, 0.5781, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sand_combush02
    tempobjid = CreateDynamicObject(866, 246.9251, -310.0071, 0.5781, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sand_combush03
    tempobjid = CreateDynamicObject(864, 249.7297, -299.9763, 0.5281, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sand_combush1
    tempobjid = CreateDynamicObject(865, 246.3201, -274.8821, 0.6781, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sand_combush02
    tempobjid = CreateDynamicObject(800, 267.5823, -276.2266, 0.7781, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bush07
    tempobjid = CreateDynamicObject(635, 259.7322, -300.4454, 2.4781, 0.7999, -90.8000, -41.9999, -1, -1, -1, 500.0000, 500.0000); //veg_fern_balcny_kb1
    //CreateDynamicObject(874, 223.9309, -300.0861, 0.8362, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 527.8034, 193.5391, 18.5813, -8.4999, -6.5999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 529.6157, 182.7337, 20.6322, -8.4999, -6.5999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 537.9799, 142.6244, 23.7954, 0.0000, 0.0000, -54.5999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 514.5066, 90.4727, 22.6615, 4.4000, 2.9999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 513.8999, 99.8280, 23.0818, 4.4000, 2.9999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 517.8426, 40.7621, 21.6645, 0.0000, -1.0000, -10.8000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 518.9707, -6.8661, 26.2794, -4.4000, -3.7999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 541.8551, -113.4311, 36.8828, 0.0000, 4.8999, -5.6999, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    //CreateDynamicObject(874, 515.9893, -119.3505, 37.6531, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //veg_procgrasspatch
    tempobjid = CreateDynamicObject(825, 538.5927, -120.3233, 37.0744, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 517.7076, -115.2307, 37.4503, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 520.3027, -5.3708, 26.1075, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 517.5366, 35.0598, 22.4139, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 515.8915, 92.3228, 22.2797, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(825, 532.3965, 135.6723, 23.7018, 0.0000, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //genVEG_bushy
    tempobjid = CreateDynamicObject(3594, 515.3758, 161.4729, 22.8368, -3.9000, 7.2000, 39.9999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 518.2098, 150.8273, 23.5003, 0.0000, 0.0000, 7.7999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3594, 528.6666, 96.6055, 21.5993, -4.5000, 0.0000, -142.6999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 526.8675, 103.3300, 21.7884, 2.8000, 2.9999, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 521.7744, 53.0597, 20.3642, 1.0999, 6.9999, 6.7000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(12957, 522.3692, 47.3296, 20.4524, -5.2999, 9.2000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //sw_pickupwreck01
    tempobjid = CreateDynamicObject(19420, 521.8601, 53.2186, 20.9724, 0.0000, 6.3999, 4.4999, -1, -1, -1, 500.0000, 500.0000); //police_lights02
    tempobjid = CreateDynamicObject(3594, 527.6044, -34.0498, 29.6119, -6.7999, 4.9000, 25.5999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 527.5318, -40.9705, 30.4389, -7.1999, 0.0000, 0.0000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2
    tempobjid = CreateDynamicObject(3594, 534.9965, -88.5694, 35.3613, 3.5000, -1.0000, -164.1000, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar1
    tempobjid = CreateDynamicObject(3593, 530.9440, -117.9127, 36.8156, -1.4000, 0.0000, -3.4999, -1, -1, -1, 500.0000, 500.0000); //la_fuckcar2

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 13052, -69.0469, 86.8359, 2.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 13054, -61.4531, -36.9922, 1.9766, 0.25);
    RemoveBuildingForPlayer(playerid, 13057, -120.0234, -77.9063, 14.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 3376, -96.0859, 3.1953, 6.6953, 0.25);
    RemoveBuildingForPlayer(playerid, 13367, -120.0234, -77.9063, 14.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 12911, -61.4531, -36.9922, 1.9766, 0.25);
    RemoveBuildingForPlayer(playerid, 3375, -96.0859, 3.1953, 6.6953, 0.25);
    RemoveBuildingForPlayer(playerid, 12914, -75.1797, 12.1719, 3.7188, 0.25);
    RemoveBuildingForPlayer(playerid, 12918, -72.0391, 18.4453, 1.9531, 0.25);
    RemoveBuildingForPlayer(playerid, 12915, -69.0469, 86.8359, 2.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 1308, 9.0234, 15.1563, -5.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 1428, -116.0000, -77.2500, 15.6797, 0.25);
    RemoveBuildingForPlayer(playerid, 1428, -118.5000, -75.9375, 5.2578, 0.25);
    RemoveBuildingForPlayer(playerid, 1428, -116.7578, -76.3516, 3.5391, 0.25);
    RemoveBuildingForPlayer(playerid, 672, -149.3359, -160.5078, 3.4688, 0.25);

    return Y_HOOKS_CONTINUE_RETURN_1;

}
