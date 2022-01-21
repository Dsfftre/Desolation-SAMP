#define KEY_AIM KEY_HANDBRAKE
#define CGEN_MEMORY 32000
#define FIX_OnDialogResponse 0 
#define FIX_BypassDialog 0 
#define YSI_NO_OPTIMISATION_MESSAGE
#define YSI_NO_VERSION_CHECK
#define YSI_NO_HEAP_MALLOC
#define YSI_NO_MODE_CACHE 
#define YSI_NO_HEAP_MALLOC
#define MAX_Y_HOOKS (256)

#include <a_samp>
//#include <file>

//#define FIX_GameText
//#define FIX_GameTextStyles
#include <fixes> 
#include <a_mysql>
#include <sscanf2>
#include <YSI_Coding\y_timers>

ptask _opsu_update[100](playerid) {
    CallLocalFunction("OnPlayerSlowUpdate", "d", playerid);
}

#include <YSI_Coding\y_inline>

#include <YSI_Data\y_foreach>
#include <YSI_Data\y_bit>

#include <YSI_Players\y_groups>

#include <YSI_Visual\y_commands>
//#include <YSI_Core\y_master>
#include <YSI_Visual\y_dialog>
#include <YSI_Visual\y_areas>
#include <FCNPC>
#include <..\..\dependencies\FCNPC\sampsvr_files\colandreas.inc>
//#include <Pawn.RakNet>
#include <streamer>
#include <bcrypt>
//#include <uuid>

#include <env>

#define DISABLE_EASYDIALOG
#define DISABLE_CHATSPAM
#define DISABLE_MONEYCHEATS
#define DISABLE_FAKEKILL

#include <Rogue-AC>
#include <progress2>

#define DEBUGMSG 0		// 1 show debug messages to all admins, 0 don't show

#define UPDATES_DIALOG "Last updated: 2021.12.29. 02:05 servertime\n\nWe have introduced a trucload of updates with 2.0. Please check the january newsletter for more info!"

#define VISIBLE_ITEMS 840
#define BCRYPT_COST 13
#define NAMETAG_DISTANCE 20.0
#define CHECKPOINT_RANGE 2.0
#define CHECKPOINT_SIZE 1.0
#define CHECK_RANGE 2.5

#define STORE_PICKUP 1239       //actual stores entrance (1239 information pickup)
#define LOOTSTORE_PICKUP 1272   //looting places entrance (1272 blue house pickup)

#define MAX_CHARACTERS 4    // max characters per master account
#define MAX_FACTIONS 5      // loaded from sql
#define MAX_CITIES 5       // loaded from sql
#define MAX_TERRITORIES 32  // loaded from sql
#define MAX_INTERIORS 512   // loaded from sql
#define MAX_FACTION_TYPES 5
#define MAX_PRIVATE_SKINS 16 //loaded from sql (amount / faction)
#define MAX_LOOT 1000       // loaded from sql
#define MAX_ZOMBIES 420     // loaded from sql � zombies are unarmed NPCs who are hostile against all players
#define MAX_ZOMBIES_SPAWNING 280 //maximum number of zombies spawning
#define INFECTION_CHANCE 5 //1 against X chance to get infected per hit: if(!random(INFECTION_CHANCE))
#define ZOMBIE_BASE_HP 60.0
#define MAX_GUARDS 420       // loaded from sql � guards are armed NPCs who can be hostile too
#define MAX_GATHERABLES 1000 // loaded from sql
#define MAX_GATES 32 // loaded from sql
#define MAX_SHOPLINES 64 // loaded from sql
#define MAX_STORAGE_POINTS 2048 // loaded from sql
#define MAX_STORAGE_ITEMS 30 // loaded from sql
#define MAX_PLAYER_SAFES 4 // loaded from sql

#define MAX_ADMIN_PARTICLES 256 // deleted every restart

#define SAFE_COST 500 // price of a 30 slot storage safe when players use /createsafe

#define SPAM_PREVENT_TIME 1000       // in miliseconds (default value)
#define LOOT_RESPAWNTIME 600000     // in miliseconds (random(LOOT_RESPAWNTIME)+random(LOOT_RESPAWNTIME))
#define BW_TIME 60000               // in miliseconds
#define RADIATION_EFFECT_TIME 10000 // in miliseconds
#define ZOMBIE_SPELL_COOLDOWN 60000 // in miliseconds (zombie screamer cd)
#define START_CAMERA_IDLE 100       // in miliseconds
#define SNIFF_DURATION 10000         // in miliseconds
#define AI_CHECK_TIME 2000          // in miliseconds

#define ZOMBIE_TEAM 1

#define MAX_INVENTORY_SLOTS 15

DEFINE_HOOK_REPLACEMENT(Destination, Dest);
DEFINE_HOOK_REPLACEMENT(Weapon, Wpn);
DEFINE_HOOK_REPLACEMENT(Download, DL);

#define DOWNLOAD_REQUEST_EMPTY        (0)
#define DOWNLOAD_REQUEST_MODEL_FILE   (1)
#define DOWNLOAD_REQUEST_TEXTURE_FILE (2)

new SERVER_DOWNLOAD[] = "http://staff.ds-rp.com/models";

#define HEX_LORANGE		"{d5522b}"
#define HEX_LRED 		"{F72222}"
#define HEX_LGREEN		"{86FA8B}"
#define HEX_GREEN 		"{008000}"
#define HEX_WHITE 		"{FFFFFF}"
#define HEX_BLUE 		"{4F87DA}"
#define HEX_DARKBLUE	"{2b2bff}"
#define HEX_GRAY		"{AEAEAF}"
#define HEX_YELLOW		"{FFFF00}"
#define HEX_ORANGE		"{FF8000}"
#define HEX_PURPLE 		"{C2A2DA}"
#define HEX_SAMP 		"{A9C4E4}"
#define HEX_CYAN 		"{33AAFF}"
#define HEX_LYELLOW		"{ffec8b}"
#define HEX_DYELLOW		"{b2a565}"

#define HEX_ZOMBIE "{930000}"
#define HEX_TESTER "{a52A2A}"
#define HEX_ADMIN "{577993}"

#define COLOR_WHITE 		0xFFFFFFFF
#define COLOR_PURPLE 		0xC2A2DAAA
#define COLOR_BLUE	 		0x1E90FFAA
#define COLOR_GREEN 	    0x006400AA
#define COLOR_LGREEN 	    0x86FA8BAA
#define COLOR_RED			0xAA3333AA
#define COLOR_PINK 	    	0xF08080FF
#define COLOR_FADE1 	    0xE6E6E6E6
#define COLOR_FADE2 	    0xC8C8C8C8
#define COLOR_FADE3 	    0xAAAAAAAA
#define COLOR_FADE4		    0x8C8C8C8C
#define COLOR_FADE5 	    0x6E6E6E6E
#define COLOR_DYELLOW 		0xb2a565AA

#define COLOR_ADMIN 	    0x57799300
#define COLOR_TESTER 	    0xa52A2A00
#define COLOR_PLAYER 	    0xFFFFFF00
#define COLOR_COP	 	    0x8C8CFF00
#define COLOR_EMT	 	    0xFF808000
#define COLOR_ZOMBIE 		0x93000000
#define COLOR_NPC 	    	0x77AAFF00

#define COLOR_ZOMBIE_SNIFF 		0x930000FF
#define COLOR_HUMAN_SNIFF 		0xFFFFFFFF

#define COLOR_NOTLOGGED 0x57575700

#define HEX_FADE1 	    "{E6E6E6}"
#define HEX_FADE2 	    "{C8C8C8}"
#define HEX_FADE3 	    "{AAAAAA}"
#define HEX_FADE4		"{8C8C8C}"
#define HEX_FADE5 	    "{6E6E6E}"
#define HEX_RED			"{FF0000}"

#define TOTAL_ITEMS         317
#define SELECTION_ITEMS 	21
#define ITEMS_PER_LINE  	7

#define HEADER_TEXT "Skins"
#define NEXT_TEXT   "Next"
#define PREV_TEXT   "Prev"

#define DIALOG_BASE_X   	75.0
#define DIALOG_BASE_Y   	130.0
#define DIALOG_WIDTH    	550.0
#define DIALOG_HEIGHT   	180.0
#define SPRITE_DIM_X    	60.0
#define SPRITE_DIM_Y    	70.0


#include "..\..\gamemodes\modules\core\server.pwn"
#include "..\..\gamemodes\modules\core\admin.pwn"
#include "..\..\gamemodes\modules\core\player.pwn"
#include "..\..\gamemodes\modules\core\events.pwn"

#include "..\..\gamemodes\modules\core\maps.pwn"


/*==============================================================================

	FACTION FUNCTIONS & COMMANDS

==============================================================================*/
#include "..\..\gamemodes\modules\player\initialize.pwn"

#include "..\..\script\ai"
#include "..\..\script\factions"
#include "..\..\script\refunctions"
//#include "..\..\script\raknet-fixes"
#include "..\..\script\server"
#include "..\..\script\notify"
#include "..\..\script\damagesystem"
#include "..\..\script\area51guards"
#include "..\..\script\zombies"
#include "..\..\script\anims"
#include "..\..\script\actors"
//#include "..\..\script\testcmds"
#include "..\..\script\startcolandreas"
//#include "..\..\script\supplies"
#include "..\..\script\skinchanger.inc"
#include "..\..\script\inventory"
#include "..\..\script\vehicles"
#include "..\..\script\interiors"
#include "..\..\script\gates"
#include "..\..\script\useitem"
#include "..\..\script\holdingweapons"
#include "..\..\script\cities"
#include "..\..\script\territories"
//#include "..\..\script\invmenu.inc"
#include "..\..\script\pvehicle"
//#include "..\..\script\gathering"
#include "..\..\script\storage"
#include "..\..\gamemodes\modules\invmenu.pwn"

#include "..\..\gamemodes\modules\player\crafting\crafting_main.pwn"

#include "..\..\script\radio"
#include "..\..\script\fix"
#include "..\..\script\reload"


#include "..\..\gamemodes\modules\player\mining\mine.pwn"
//#include "..\..\gamemodes\modules\player\searches\search.pwn"
/*==============================================================================

	ALWAYS CALLED LAST

==============================================================================*/
#include "..\..\script\anticheat"
#include "..\..\gamemodes\modules\pw.pwn"
#include "..\..\gamemodes\modules\server\resetvalues.pwn"

main() {

}


public OnGameModeInit()
{
	print("bcrypt_debug(BCRYPT_LOG_TRACE)");
    bcrypt_debug(BCRYPT_LOG_TRACE);
    bcrypt_set_thread_limit(2);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

public OnPlayerRequestClass(playerid, classid) {
    if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
    if(Bit_Get(character, playerid)) 
	{
        SpawnPlayer(playerid);
        return Y_HOOKS_CONTINUE_RETURN_0;
    }
    TogglePlayerSpectating(playerid, true);
    SetSpawnInfo(playerid, NO_TEAM, 28, 2537.7395,-1663.2736,15.1546, 180.0995, 0, 0, 0, 0, 0, 0); 

    defer SpawnCamera(playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}
/*
forward OnPlayerCheatDetected(playerid, code);
public OnPlayerCheatDetected(playerid, code)
{
    new cheatname[30], string[128];
    switch (code)
    {
        case 0: cheatname = "Silent Aimbot";
        case 1: cheatname = "Vehicle Repair Hack";
        case 2: cheatname = "Screen Flickering";
        case 3: cheatname = "Car Troller";
        case 4: cheatname = "Surfing Invisible";
        case 5: cheatname = "Airbreak";
        case 6: cheatname = "Seat Crasher";
        case 7: cheatname = "Speed Hack";
        case 8: cheatname = "Troll Animation";
        case 9: cheatname = "Animation Invisible";
        case 10: cheatname = "Fly Hack";
        case 11: cheatname = "Rage Shot";
        case 12: cheatname = "Trailer Crasher";
        case 13: cheatname = "Weapon Hack";
    }
    format(string, sizeof(string), "~w~%s detected by DSRP Anti-Cheat", cheatname);
    GameTextForAll(string, 1000, 3);
    printf("%s", string);
    //Kick(playerid);
    return 1;
}*/