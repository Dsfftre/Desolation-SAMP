
#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnGameModeInit() {

    Streamer_SetMaxItems(STREAMER_TYPE_OBJECT, -1);
    Streamer_SetTickRate(50);
    Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT, 900);
    Streamer_SetRadiusMultiplier(STREAMER_TYPE_OBJECT, 1.6);

    //terminal heliport (int 41 and int 42) door to make a stairway from caligulas roof interior
    CreateDynamicObject(11714, 2269.32031, 1627.06592, 1084.47839,   90.00000, 0.00000, 90.00000, 41); //only created in vw 41

    return Y_HOOKS_CONTINUE_RETURN_1;
}

#include "..\..\gamemodes\modules\maps\milk\dillimore"

#include "..\..\gamemodes\modules\maps\milk\bb_compound_acres"
#include "..\..\gamemodes\modules\maps\milk\blueberry"
#include "..\..\gamemodes\modules\maps\milk\broken_bridge1"
#include "..\..\gamemodes\modules\maps\milk\broken_bridge2"
#include "..\..\gamemodes\modules\maps\milk\bunker_1"
#include "..\..\gamemodes\modules\maps\milk\coastal"
#include "..\..\gamemodes\modules\maps\milk\connectors"
#include "..\..\gamemodes\modules\maps\milk\connectors2"
#include "..\..\gamemodes\modules\maps\milk\flintgate"
#include "..\..\gamemodes\modules\maps\milk\hilltop"
#include "..\..\gamemodes\modules\maps\milk\montgomery"
#include "..\..\gamemodes\modules\maps\milk\northrock"
#include "..\..\gamemodes\modules\maps\milk\palomino"
#include "..\..\gamemodes\modules\maps\milk\mine"
#include "..\..\gamemodes\modules\maps\milk\panopticon"
#include "..\..\gamemodes\modules\maps\milk\pc_farm"
#include "..\..\gamemodes\modules\maps\milk\pc_tunnel"
#include "..\..\gamemodes\modules\maps\milk\project_z_flint"
#include "..\..\gamemodes\modules\maps\milk\red_warehouse"
#include "..\..\gamemodes\modules\maps\milk\sewers"
#include "..\..\gamemodes\modules\maps\milk\shit_sewer"
#include "..\..\gamemodes\modules\maps\milk\smth"
#include "..\..\gamemodes\modules\maps\milk\stars_ext"
#include "..\..\gamemodes\modules\maps\milk\submarine"

#include "..\..\gamemodes\modules\maps\milk\LS\east-stadium"
#include "..\..\gamemodes\modules\maps\milk\LS\eastls-lf"
#include "..\..\gamemodes\modules\maps\milk\LS\ganton_wall"
#include "..\..\gamemodes\modules\maps\milk\LS\north-stadium"
//#include "..\..\gamemodes\modules\maps\milk\LS\outpost22"
#include "..\..\gamemodes\modules\maps\milk\LS\part1"
#include "..\..\gamemodes\modules\maps\milk\LS\part2"
#include "..\..\gamemodes\modules\maps\milk\LS\part3"
#include "..\..\gamemodes\modules\maps\milk\LS\part4"
#include "..\..\gamemodes\modules\maps\milk\LS\part5"
#include "..\..\gamemodes\modules\maps\milk\LS\part6"
#include "..\..\gamemodes\modules\maps\milk\LS\part7"
#include "..\..\gamemodes\modules\maps\milk\LS\part8"
#include "..\..\gamemodes\modules\maps\milk\LS\part9"
#include "..\..\gamemodes\modules\maps\milk\LS\part10"
#include "..\..\gamemodes\modules\maps\milk\LS\part11"
#include "..\..\gamemodes\modules\maps\milk\LS\part12"
#include "..\..\gamemodes\modules\maps\milk\LS\part13"
#include "..\..\gamemodes\modules\maps\milk\LS\part14"
#include "..\..\gamemodes\modules\maps\milk\LS\part15"
#include "..\..\gamemodes\modules\maps\milk\LS\part16"
#include "..\..\gamemodes\modules\maps\milk\LS\part17"
#include "..\..\gamemodes\modules\maps\milk\LS\part18"
#include "..\..\gamemodes\modules\maps\milk\LS\refugee"
#include "..\..\gamemodes\modules\maps\milk\LS\refugee2"

#include "..\..\gamemodes\modules\maps\milk\ints\alt_admin_jail"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_ammunation_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_ammunation_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_apartment_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_apartment_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_apartment_3"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_bar_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_bar_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_bar_3"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_bunker_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_bunker_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_city_hall"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_clothing"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_complex_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_complex_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_complex_3"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_complex_4"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_dillimore_hq"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_faction_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_furn_shop_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_general_shop_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_general_shop_3"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_general_shop_4"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_hospital_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_house_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_house_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_house_3"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_house_4"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_house_5"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_medic_rv"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_mine"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_neoumbrella_garage"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_nightclub_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_nightclub_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_pizzashop_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_pizzashop_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_police_station_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_sewers_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_shafts_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_strip_bar"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_trailer_1"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_trailer_2"
#include "..\..\gamemodes\modules\maps\milk\ints\alt_warehouse_1"



