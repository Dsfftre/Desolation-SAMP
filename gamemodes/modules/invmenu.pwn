#if defined _inc_hooks
	#undef _inc_hooks
#endif

#define TYPE_PRIMARY 0
#define TYPE_SECONDARY 1
#define TYPE_PISTOL 2
#define TYPE_MELEE 3

#include <YSI_Coding\y_hooks>

new Text:invtd[5];
new Text:inv_user;
new Text:inv_split[2];
new Text:inv_remove;
new Text:inv_drop[2];
new Text:invmenu_td[2];

new PlayerText:inv_index[MAX_PLAYERS][MAX_INVENTORY_SLOTS];
new PlayerText:inv_skin[MAX_PLAYERS];
new PlayerText:inv_text[MAX_PLAYERS][11];
new PlayerText:inv_description[MAX_PLAYERS][4];
new PlayerText:inv_personindex[MAX_PLAYERS][7];
new PlayerText:inv_message[MAX_PLAYERS];

new selectitem[MAX_PLAYERS];

new BitArray:slot_head<MAX_PLAYERS>;
new BitArray:slot_body<MAX_PLAYERS>;
new BitArray:slot_backpack<MAX_PLAYERS>;
new BitArray:slot_primary<MAX_PLAYERS>;
new BitArray:slot_secondary<MAX_PLAYERS>;
new BitArray:slot_pistol<MAX_PLAYERS>;
new BitArray:slot_melee<MAX_PLAYERS>;

EquipItem(playerid, itemid, slotid, bool:equip = true) {

    if(!SpamPrevent(playerid)) return 1;

    if(itemid == 0)
        return 0;

    if(equip) {
        PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][slotid], 0x29aa2977);
        if(Bit_Get(tutorial, playerid))	
            SCM(playerid, HEX_FADE2, "Hint: You can reload your weapon by pressing KEY_YES (Default: Y).");
    }
    else
        PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][slotid], 0x2c578d77);

    //Itemid is for setting inventory textdraws on the left side panels
    CloseInventory(playerid);
    OpenInventory(playerid);
    return 1;
}

DropItem(playerid, islot) {
    if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");
    if(!SpamPrevent(playerid)) return 1;

    if(inventory_itemid[playerid][islot] == 0) return SCM(playerid, HEX_RED, "Error: You must select an item (or invalid item id).");

    /*new i = -1;
    for(;++i<MAX_INVENTORY_SLOTS;) {
        if(inventory_used[playerid][i]) return SCM(playerid, HEX_RED, "Error: You must unequip all used items.");
    }*/

    if(inventory_used[playerid][islot]) return SCM(playerid, HEX_RED, "Error: You cannot delete a used item.");

    /*new i = -1;
    new bool:slotfound = false;
    for(;++i<MAX_INVENTORY_SLOTS*3;) {
        if(dropped_itemid[playerid][i] == 0) {
            slotfound = true;
            break;
        }
    }
    if(!slotfound) return SCM(playerid, HEX_RED, "Error: You have dropped too many items. Some must be picked up!");

    dropped_itemid[playerid][i] = inventory_itemid[playerid][islot];
    dropped_amount[playerid][i] = inventory_amount[playerid][islot];*/

    new string[256];
    format(string, sizeof string, "{FFFFFF}Are you sure you want to delete all of your {FFFF00}%s {FFFFFF}?", GetItemName(inventory_itemid[playerid][islot]));
    

    inline deleteConfirmation(pid, dialogid, response, listitem, string:inputtext[]) {
        #pragma unused pid, dialogid, response, listitem, inputtext

        if(response) {
            format(string, sizeof string, "deletes their %s (x%d) item.", GetItemName(inventory_itemid[playerid][islot]), inventory_amount[playerid][islot]);
            PlayerAction(playerid, string);
            RemovePlayerItem(playerid, inventory_itemid[playerid][islot], inventory_amount[playerid][islot]);
        }

        CloseInventory(playerid);
        OpenInventory(playerid);

        @return 1;
    }
    Dialog_ShowCallback(playerid, using inline deleteConfirmation, DIALOG_STYLE_MSGBOX, "Deleting item", string, "Delete", "Back");

    return 1;
}


SplitDropItem(playerid, islot) {
    if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");
    if(!SpamPrevent(playerid)) return 1;

    if(inventory_itemid[playerid][islot] == 0) return SCM(playerid, HEX_RED, "Error: You must select an item (or invalid item id).");

    /*new i = -1;
    for(;++i<MAX_INVENTORY_SLOTS;) {
        if(inventory_used[playerid][i]) return SCM(playerid, HEX_RED, "Error: You must unequip all used items.");
    }*/

    if(inventory_used[playerid][islot]) return SCM(playerid, HEX_RED, "Error: You cannot drop a used item.");

    new i = -1;
    new bool:slotfound = false;
    for(;++i<MAX_INVENTORY_SLOTS*3;) {
        if(dropped_itemid[playerid][i] == 0) {
            slotfound = true;
            break;
        }
    }
    if(!slotfound) return SCM(playerid, HEX_RED, "Error: You have dropped too many items. Some must be picked up!");

    new string[256];
    format(string, sizeof string, "{FFFFFF}Enter how many {FFFF00}%s {FFFFFF}items you want to drop.", GetItemName(inventory_itemid[playerid][islot]));
    

    inline selectSplitDrop(pid, dialogid, response, listitem, string:inputtext[]) {
        #pragma unused pid, dialogid, response, listitem, inputtext

        if(!response) {
            CloseInventory(playerid);
            OpenInventory(playerid);
        }
        else {
            
            new dropam = strval(inputtext);

            if(!HasPlayerItem(playerid, inventory_itemid[playerid][islot], dropam) || dropam < 1) {
                SCM(playerid, HEX_RED, "Invalid amount.");
                CloseInventory(playerid);
                @return 1;
            }

            dropped_itemid[playerid][i] = inventory_itemid[playerid][islot];
            dropped_amount[playerid][i] = dropam;

            RemovePlayerItem(playerid, inventory_itemid[playerid][islot], dropam);

            CloseInventory(playerid);
            OpenInventory(playerid);

            GetPlayerPos(playerid, dropped_posx[playerid][i], dropped_posy[playerid][i], dropped_posz[playerid][i]);
            dropped_interior[playerid][i] = GetPlayerInterior(playerid);
            dropped_virtualworld[playerid][i] = GetPlayerVirtualWorld(playerid);

            mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `itemlist` WHERE id = %d LIMIT 1", dropped_itemid[playerid][i]);
            inline LoadLootData() {
                new	Float:o_pos[3],
                    Float:o_rot[3];
                if(!cache_num_rows())
                    printf("DEBUG !cache_num_rows @ Droploot by player %s", PlayerName(playerid));
                
                cache_get_value_int(0, "object", dropped_object[playerid][i]);
                cache_get_value_float(0, "posx", o_pos[0]);
                cache_get_value_float(0, "posy", o_pos[1]);
                cache_get_value_float(0, "posz", o_pos[2]);
                cache_get_value_float(0, "rotx", o_rot[0]);
                cache_get_value_float(0, "roty", o_rot[1]);
                cache_get_value_float(0, "rotz", o_rot[2]);

                dropped_object[playerid][i] = CreateDynamicObject(dropped_object[playerid][i], dropped_posx[playerid][i]+o_pos[0], dropped_posy[playerid][i]+o_pos[1], dropped_posz[playerid][i]+o_pos[2], o_rot[0], o_rot[1], o_rot[2], dropped_virtualworld[playerid][i], dropped_interior[playerid][i]);
            }
            MySQL_TQueryInline(g_SQL, using inline LoadLootData, sql);
        }
        @return 1;
    }
    Dialog_ShowCallback(playerid, using inline selectSplitDrop, DIALOG_STYLE_INPUT, "Dropping a splitted item", string, "Select", "Back");
    return 1;
}


UseItem(playerid, islot) {

    if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");
    if(!SpamPrevent(playerid)) return 1;

    if(Group_GetPlayer(g_AdminDuty, playerid))
        SFM(playerid, HEX_FADE2, "Debug: You use item slot %d, itemid %d, amount %d.", islot, inventory_itemid[playerid][islot], inventory_amount[playerid][islot]);

    switch(inventory_itemid[playerid][islot]) {
        case 1: UseBoxers(playerid, islot);
        case 2: UseGolfclub(playerid, islot);
        case 3: UseNightstick(playerid, islot);
        case 4: UseKnife(playerid, islot);
        case 5: UseBat(playerid, islot);
        case 6: UseShovel(playerid, islot);
        case 7: UsePoolcue(playerid, islot);
        case 8: UseKatana(playerid, islot);
        case 9: UseChainsaw(playerid, islot);
        case 10: UsePurpledildo(playerid, islot);
        case 11: UseDildo(playerid, islot);
        case 12: UseVibrator(playerid, islot);
        case 13: UseSilvervibrator(playerid, islot);
        case 14: UseFlowers(playerid, islot);
        case 15: UseCane(playerid, islot);
        case 16: UseGrenade(playerid);
        case 17: UseTeargas(playerid);
        case 18: UseMolotov(playerid);
        case 19: UsePistol(playerid, islot);
        case 20: UseSilencedpistol(playerid, islot);
        case 21: UseDeagle(playerid, islot);
        case 22: UseShotgun(playerid, islot);
        case 23: UseSawnoffShotgun(playerid, islot);
        case 24: Usespaz(playerid, islot);
        case 25: Usemicrouzi(playerid, islot);
        case 26: Usemp5(playerid, islot);
        case 27: UseAK47(playerid, islot);
        case 28: UseM4(playerid, islot);
        case 29: Usetec9(playerid, islot);
        case 30: Userifle(playerid, islot);
        case 31: Usesniper(playerid, islot);
        case 32: Userpg(playerid, islot);
        case 33: Usehsrpg(playerid, islot);
        case 34: Useflamethrower(playerid, islot);
        case 35: UseCamera(playerid, islot);
        case 36: UseNightvision(playerid, islot);
        case 37: UseThermal(playerid, islot);
        case 38: UseParachute(playerid);
        case 39: UseAmmo(playerid);
        case 40: UseAmmo(playerid);
        case 41: UseAmmo(playerid);
        case 42: UseAmmo(playerid);
        case 43: UseAmmo(playerid);
        case 44: UseAmmo(playerid);
        case 45: UseAmmo(playerid);
        case 46: UseJerrycan(playerid);
        case 47: UseMediccase(playerid);
        case 48: UseFirstaid(playerid);
        case 52: UseVirussample(playerid);
        case 53: UseAntidote(playerid);
        case 54: UseRadio(playerid);
        case 55: UseFlakes(playerid, islot);
        case 56: UseCereal(playerid, islot);
        case 57: UseJuice(playerid, islot);
        case 58: UseFishfingers(playerid, islot);
        case 59: UseMilk(playerid, islot);
        case 60: UseWater(playerid, islot);
        case 63: UseArmor(playerid);
        case 64: UseToolbox(playerid);
        default: SFM(playerid, HEX_RED, "Error: Unknown item at slot %d, itemid %d, amount %d. (Feature under development!)", islot, inventory_itemid[playerid][islot], inventory_amount[playerid][islot]);
    }
    return 1;
}

UseNightvision(playerid, islot) {
    if(!HasPlayerItem(playerid, 36, 1)) return SCM(playerid, HEX_RED, "Error: You need a nightvision in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_head, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your head item.");
        Bit_Let(slot_head, playerid);
        EquipItem(playerid, 36, islot, true);
        GivePlayerWeapon(playerid, 44, 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][0], GetItemObject(36));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 36 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_head, playerid);
        EquipItem(playerid, 36, islot, false);
        RemovePlayerWeapon(playerid, 44);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][0], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 36 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    return 1;
}

UseThermal(playerid, islot) {
    if(!HasPlayerItem(playerid, 37, 1)) return SCM(playerid, HEX_RED, "Error: You need thermal goggles in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_head, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your head item.");
        Bit_Let(slot_head, playerid);
        EquipItem(playerid, 37, islot, true);
        GivePlayerWeapon(playerid, 45, 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][0], GetItemObject(37));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 37 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_head, playerid);
        EquipItem(playerid, 37, islot, false);
        RemovePlayerWeapon(playerid, 45);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][0], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 37 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    return 1;
}


UseArmor(playerid) {
	if(!HasPlayerItem(playerid, 63, 1)) return SCM(playerid, HEX_RED, "Error: You need an armor in your inventory.");

    new Float:temparmour;
    GetPlayerArmour(playerid, temparmour);

    if(temparmour > 95.0) return SCM(playerid, HEX_RED, "Error: You have more than 95.0 armor.");

	RemovePlayerItem(playerid, 63, 1);

	SetPlayerArmour(playerid, 100.0);
    PlayerAction(playerid, "equips an armor.");

    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][1], GetItemObject(63));
    PlayerTextDrawShow(playerid, inv_personindex[playerid][1]);

    ApplyAnimation(playerid, "BD_FIRE", "wash_up", 4.0, 0, 0, 0, 0, 0, 1);
    CloseInventory(playerid);
    OpenInventory(playerid);

	return 1;
}

UseWater(playerid, islot) {
    RemovePlayerItem(playerid, inventory_itemid[playerid][islot], 1);
    Consume(playerid, 0.00, 20.00);
    PlayerAction(playerid, "drinks some water.");
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 1.2, 0, 0, 0, 0, 0, 1);
    GameTextForPlayer(playerid, "~b~+20.00 drink", 2000, 1);
    CloseInventory(playerid);
    OpenInventory(playerid);
    return 1;
}

UseMilk(playerid, islot) {
    RemovePlayerItem(playerid, inventory_itemid[playerid][islot], 1);
    Consume(playerid, 3.00, 10.00);
    PlayerAction(playerid, "drinks some milk.");
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 1.2, 0, 0, 0, 0, 0, 1);
    GameTextForPlayer(playerid, "~y~+3.00 food~n~~b~+10.00 drink", 2000, 1);
    CloseInventory(playerid);
    OpenInventory(playerid);
    return 1;
}

UseFishfingers(playerid, islot) {
    RemovePlayerItem(playerid, inventory_itemid[playerid][islot], 1);
    Consume(playerid, 25.00);
    PlayerAction(playerid, "eats some fish fingers.");
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 1.2, 0, 0, 0, 0, 0, 1);
    GameTextForPlayer(playerid, "~y~+25.00 food", 2000, 1);
    CloseInventory(playerid);
    OpenInventory(playerid);
    return 1;
}

UseJuice(playerid, islot) {
    RemovePlayerItem(playerid, inventory_itemid[playerid][islot], 1);
    Consume(playerid, 5.00, 20.00);
    PlayerAction(playerid, "drinks some juice.");
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 1.2, 0, 0, 0, 0, 0, 1);
    GameTextForPlayer(playerid, "~y~+5.00 food~n~~b~+20.00 drink", 2000, 1);
    CloseInventory(playerid);
    OpenInventory(playerid);
    return 1;
}

UseCereal(playerid, islot) {
    RemovePlayerItem(playerid, inventory_itemid[playerid][islot], 1);
    Consume(playerid, 5.5);
    PlayerAction(playerid, "eats some cereal.");
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 1.2, 0, 0, 0, 0, 0, 1);
    GameTextForPlayer(playerid, "~y~+5.50 food", 2000, 1);
    CloseInventory(playerid);
    OpenInventory(playerid);
    return 1;
}

UseFlakes(playerid, islot) {
    RemovePlayerItem(playerid, inventory_itemid[playerid][islot], 1);
    Consume(playerid, 7.2);
    PlayerAction(playerid, "eats some crispy flakes.");
    ApplyAnimation(playerid, "FOOD", "EAT_Burger", 1.2, 0, 0, 0, 0, 0, 1);
    GameTextForPlayer(playerid, "~y~+7.20 food", 2000, 1);
    CloseInventory(playerid);
    OpenInventory(playerid);
    return 1;
}

Consume(playerid, Float:addfood = 0.0, Float:addthirst = 0.0) {

	hunger[playerid] += addfood;
	thirst[playerid] += addthirst;

	RefreshBars(playerid);
	return 1;
}

UseAmmo(playerid) {
    SCM(playerid, HEX_FADE2, "Your ammunition loads automatically whenever you equip a weapon.");
    return 1;
}

UseJerrycan(playerid) {
    SCM(playerid, HEX_FADE2, "Your Jerrycan is used to fill a flamethrower and refuel a car with /fill.");
    return 1;
}

UseToolbox(playerid) {
    SCM(playerid, HEX_FADE2, "You can fix your vehicle with /repair.");
    return 1;
}

Useflamethrower(playerid, islot) {
	if(!HasPlayerItem(playerid, 34, 1)) return SCM(playerid, HEX_RED, "Error: You need a flamethrower in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 46, 1)) return SCM(playerid, HEX_RED, "Error: You do not have a filled Jerrycan.");
        if(Bit_Get(slot_primary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your primary weapon.");
        SetPVarInt(playerid, "ammo0", 46);
        Bit_Let(slot_primary, playerid);

        p_weapon[playerid][TYPE_PRIMARY] = 37;
        p_ammos[playerid][TYPE_PRIMARY] = CountPlayerItem(playerid, 46, false);

        new maxam = WeaponAmmo(37);
        if(p_ammos[playerid][TYPE_PRIMARY] > maxam) {
            p_ammos[playerid][TYPE_PRIMARY] = maxam;
        }
        RemovePlayerItem(playerid, 46, p_ammos[playerid][TYPE_PRIMARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PRIMARY], p_ammos[playerid][TYPE_PRIMARY]);
        ApplyAnimation(playerid, "rifle", "rifle_load", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a flamethrower.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], GetItemObject(34));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 34 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 34, islot, true);
    }
    else {
        
        Bit_Vet(slot_primary, playerid);
        
        SaveAmmo(playerid, TYPE_PRIMARY);
        p_weapon[playerid][TYPE_PRIMARY] = 0;
        p_ammos[playerid][TYPE_PRIMARY] = 0;
        RemovePlayerWeapon(playerid, 37);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        PlayerAction(playerid, "unequips a flamethrower.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 34 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo0", 0);
        EquipItem(playerid, 34, islot, false);
    }
	return 1;
}

Usehsrpg(playerid, islot) {
	if(!HasPlayerItem(playerid, 33, 1)) return SCM(playerid, HEX_RED, "Error: You need an HS Rocket in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 45, 1)) return SCM(playerid, HEX_RED, "Error: You do not have Rocket ammunition.");
        if(Bit_Get(slot_primary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your primary weapon.");
        SetPVarInt(playerid, "ammo0", 45);
        Bit_Let(slot_primary, playerid);
        
        p_weapon[playerid][TYPE_PRIMARY] = 36;
        p_ammos[playerid][TYPE_PRIMARY] = CountPlayerItem(playerid, 45, false);

        new maxam = WeaponAmmo(36);
        if(p_ammos[playerid][TYPE_PRIMARY] > maxam) {
            p_ammos[playerid][TYPE_PRIMARY] = maxam;
        }
        RemovePlayerItem(playerid, 45, p_ammos[playerid][TYPE_PRIMARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PRIMARY], p_ammos[playerid][TYPE_PRIMARY]);
        ApplyAnimation(playerid, "rocket", "idle_rocket", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips an HS Rocket.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], GetItemObject(33));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 33 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 33, islot, true);
    }
    else {
        
        Bit_Vet(slot_primary, playerid);
        
        SaveAmmo(playerid, TYPE_PRIMARY);
        p_weapon[playerid][TYPE_PRIMARY] = 0;
        p_ammos[playerid][TYPE_PRIMARY] = 0;
        RemovePlayerWeapon(playerid, 36);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        PlayerAction(playerid, "unequips an HS Rocket.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 33 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo0", 0);
        EquipItem(playerid, 33, islot, false);
    }
	return 1;
}

Userpg(playerid, islot) {
	if(!HasPlayerItem(playerid, 32, 1)) return SCM(playerid, HEX_RED, "Error: You need an RPG in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 45, 1)) return SCM(playerid, HEX_RED, "Error: You do not have Rocket ammunition.");
        if(Bit_Get(slot_primary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your primary weapon.");
        SetPVarInt(playerid, "ammo0", 45);
        Bit_Let(slot_primary, playerid);
        
        p_weapon[playerid][TYPE_PRIMARY] = 35;
        p_ammos[playerid][TYPE_PRIMARY] = CountPlayerItem(playerid, 45, false);
        
        new maxam = WeaponAmmo(35);
        if(p_ammos[playerid][TYPE_PRIMARY] > maxam) {
            p_ammos[playerid][TYPE_PRIMARY] = maxam;
        }
        RemovePlayerItem(playerid, 45, p_ammos[playerid][TYPE_PRIMARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PRIMARY], p_ammos[playerid][TYPE_PRIMARY]);
        ApplyAnimation(playerid, "rocket", "idle_rocket", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips an RPG.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], GetItemObject(32));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 32 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 32, islot, true);
    }
    else {
        
        Bit_Vet(slot_primary, playerid);
        
        SaveAmmo(playerid, TYPE_PRIMARY);
        p_weapon[playerid][TYPE_PRIMARY] = 0;
        p_ammos[playerid][TYPE_PRIMARY] = 0;
        RemovePlayerWeapon(playerid, 35);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        PlayerAction(playerid, "unequips an RPG.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 32 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo0", 0);
        EquipItem(playerid, 32, islot, false);
    }
	return 1;
}

Usesniper(playerid, islot) {
	if(!HasPlayerItem(playerid, 31, 1)) return SCM(playerid, HEX_RED, "Error: You need a sniper rifle in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 44, 1)) return SCM(playerid, HEX_RED, "Error: You do not have .338 Lapua Magnum ammunition.");
        if(Bit_Get(slot_primary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your primary weapon.");
        SetPVarInt(playerid, "ammo0", 44);
        Bit_Let(slot_primary, playerid);
        
        p_weapon[playerid][TYPE_PRIMARY] = 34;
        p_ammos[playerid][TYPE_PRIMARY] = CountPlayerItem(playerid, 44, false);
        
        new maxam = WeaponAmmo(34);
        if(p_ammos[playerid][TYPE_PRIMARY] > maxam) {
            p_ammos[playerid][TYPE_PRIMARY] = maxam;
        }
        RemovePlayerItem(playerid, 44, p_ammos[playerid][TYPE_PRIMARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PRIMARY], p_ammos[playerid][TYPE_PRIMARY]);
        ApplyAnimation(playerid, "rifle", "rifle_load", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a sniper rifle.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], GetItemObject(31));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 31 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 31, islot, true);
    }
    else {
        
        Bit_Vet(slot_primary, playerid);
            
        SaveAmmo(playerid, TYPE_PRIMARY);
        p_weapon[playerid][TYPE_PRIMARY] = 0;
        p_ammos[playerid][TYPE_PRIMARY] = 0;
        RemovePlayerWeapon(playerid, 34);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        PlayerAction(playerid, "unequips a sniper rifle.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 31 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo0", 0);
        EquipItem(playerid, 31, islot, false);    
    }
	return 1;
}

Userifle(playerid, islot) {
	if(!HasPlayerItem(playerid, 30, 1)) return SCM(playerid, HEX_RED, "Error: You need a county rifle in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 44, 1)) return SCM(playerid, HEX_RED, "Error: You do not have .338 Lapua Magnum ammunition.");
        if(Bit_Get(slot_primary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your primary weapon.");
        SetPVarInt(playerid, "ammo0", 44);
        Bit_Let(slot_primary, playerid);
        
        p_weapon[playerid][TYPE_PRIMARY] = 33;
        p_ammos[playerid][TYPE_PRIMARY] = CountPlayerItem(playerid, 44, false);
        
        new maxam = WeaponAmmo(33);
        if(p_ammos[playerid][TYPE_PRIMARY] > maxam) {
            p_ammos[playerid][TYPE_PRIMARY] = maxam;
        }
        RemovePlayerItem(playerid, 44, p_ammos[playerid][TYPE_PRIMARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PRIMARY], p_ammos[playerid][TYPE_PRIMARY]);
        ApplyAnimation(playerid, "rifle", "rifle_load", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a county rifle.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], GetItemObject(30));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 30 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 30, islot, true);
    }
    else {
        
        Bit_Vet(slot_primary, playerid);
        
        SaveAmmo(playerid, TYPE_PRIMARY);
        p_weapon[playerid][TYPE_PRIMARY] = 0;
        p_ammos[playerid][TYPE_PRIMARY] = 0;
        RemovePlayerWeapon(playerid, 33);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        PlayerAction(playerid, "unequips a county rifle.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 30 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo0", 0);
        EquipItem(playerid, 30, islot, false);
    }
	return 1;
}

UseM4(playerid, islot) {
	if(!HasPlayerItem(playerid, 28, 1)) return SCM(playerid, HEX_RED, "Error: You need an M4 in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 43, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 5.56mm ammunition.");
        if(Bit_Get(slot_primary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your primary weapon.");
        SetPVarInt(playerid, "ammo0", 43);
        Bit_Let(slot_primary, playerid);
        
        p_weapon[playerid][TYPE_PRIMARY] = 31;
        p_ammos[playerid][TYPE_PRIMARY] = CountPlayerItem(playerid, 43, false);
        
        new maxam = WeaponAmmo(31);
        if(p_ammos[playerid][TYPE_PRIMARY] > maxam) {
            p_ammos[playerid][TYPE_PRIMARY] = maxam;
        }
        RemovePlayerItem(playerid, 43, p_ammos[playerid][TYPE_PRIMARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PRIMARY], p_ammos[playerid][TYPE_PRIMARY]);
        ApplyAnimation(playerid, "rifle", "rifle_load", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips an M4.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], GetItemObject(28));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 28 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 28, islot, true);
    }
    else {
        
        Bit_Vet(slot_primary, playerid);
        
        SaveAmmo(playerid, TYPE_PRIMARY);
        p_weapon[playerid][TYPE_PRIMARY] = 0;
        p_ammos[playerid][TYPE_PRIMARY] = 0;
        RemovePlayerWeapon(playerid, 31);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        PlayerAction(playerid, "unequips an M4.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 28 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo0", 0);
        EquipItem(playerid, 28, islot, false);
    }
	return 1;
}

UseAK47(playerid, islot) {
	if(!HasPlayerItem(playerid, 27, 1)) return SCM(playerid, HEX_RED, "Error: You need an AK47 in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 42, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 7.62mm ammunition.");
        if(Bit_Get(slot_primary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your primary weapon.");
        SetPVarInt(playerid, "ammo0", 42);
        Bit_Let(slot_primary, playerid);
        
        p_weapon[playerid][TYPE_PRIMARY] = 30;
        p_ammos[playerid][TYPE_PRIMARY] = CountPlayerItem(playerid, 42, false);
        
        new maxam = WeaponAmmo(30);
        if(p_ammos[playerid][TYPE_PRIMARY] > maxam) {
            p_ammos[playerid][TYPE_PRIMARY] = maxam;
        }
        RemovePlayerItem(playerid, 42, p_ammos[playerid][TYPE_PRIMARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PRIMARY], p_ammos[playerid][TYPE_PRIMARY]);
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], GetItemObject(27));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        ApplyAnimation(playerid, "rifle", "rifle_load", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips an AK47.");
        inventory_used[playerid][islot] = true;
        
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 27 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 27, islot, true);
    }
    else {
        
        Bit_Vet(slot_primary, playerid);
        
        SaveAmmo(playerid, TYPE_PRIMARY);
        p_weapon[playerid][TYPE_PRIMARY] = 0;
        p_ammos[playerid][TYPE_PRIMARY] = 0;
        RemovePlayerWeapon(playerid, 30);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
        PlayerAction(playerid, "unequips an AK47.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 27 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo0", 0);
        EquipItem(playerid, 27, islot, false);
    }
	return 1;
}

Usetec9(playerid, islot) {
	if(!HasPlayerItem(playerid, 29, 1)) return SCM(playerid, HEX_RED, "Error: You need a TEC-9 in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 39, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 9mm ammunition.");
        if(Bit_Get(slot_secondary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your secondary weapon.");
        SetPVarInt(playerid, "ammo1", 39);
        Bit_Let(slot_secondary, playerid);
        
        p_weapon[playerid][TYPE_SECONDARY] = 32;
        p_ammos[playerid][TYPE_SECONDARY] = CountPlayerItem(playerid, 39, false);
        
        new maxam = WeaponAmmo(32);
        if(p_ammos[playerid][TYPE_SECONDARY] > maxam) {
            p_ammos[playerid][TYPE_SECONDARY] = maxam;
        }
        RemovePlayerItem(playerid, 39, p_ammos[playerid][TYPE_SECONDARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_SECONDARY], p_ammos[playerid][TYPE_SECONDARY]);
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], GetItemObject(29));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        ApplyAnimation(playerid, "uzi", "uzi_reload", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a TEC-9.");
        inventory_used[playerid][islot] = true;
        
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 29 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);

        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_ENTER_VEHICLE_DRIVER)
            SetPlayerArmedWeapon(playerid, 0);
        EquipItem(playerid, 29, islot, true);
    }
    else {
        
        Bit_Vet(slot_secondary, playerid);
        
        SaveAmmo(playerid, TYPE_SECONDARY);
        p_weapon[playerid][TYPE_SECONDARY] = 0;
        p_ammos[playerid][TYPE_SECONDARY] = 0;
        RemovePlayerWeapon(playerid, 32);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        PlayerAction(playerid, "unequips a TEC-9.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 29 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo1", 0);
        EquipItem(playerid, 29, islot, false);
    }
	return 1;
}

Usemp5(playerid, islot) {
	if(!HasPlayerItem(playerid, 26, 1)) return SCM(playerid, HEX_RED, "Error: You need an MP5 in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 39, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 9mm ammunition.");
        if(Bit_Get(slot_secondary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your secondary weapon.");
        SetPVarInt(playerid, "ammo1", 39);
        Bit_Let(slot_secondary, playerid);
        
        p_weapon[playerid][TYPE_SECONDARY] = 29;
        p_ammos[playerid][TYPE_SECONDARY] = CountPlayerItem(playerid, 39, false);
        
        new maxam = WeaponAmmo(29);
        if(p_ammos[playerid][TYPE_SECONDARY] > maxam) {
            p_ammos[playerid][TYPE_SECONDARY] = maxam;
        }
        RemovePlayerItem(playerid, 39, p_ammos[playerid][TYPE_SECONDARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_SECONDARY], p_ammos[playerid][TYPE_SECONDARY]);
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], GetItemObject(26));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        ApplyAnimation(playerid, "uzi", "uzi_reload", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips an MP5.");
        inventory_used[playerid][islot] = true;
        
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 26 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);

        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_ENTER_VEHICLE_DRIVER)
            SetPlayerArmedWeapon(playerid, 0);
        EquipItem(playerid, 26, islot, true);
    }
    else {
        
        Bit_Vet(slot_secondary, playerid);
        
        SaveAmmo(playerid, TYPE_SECONDARY);
        p_weapon[playerid][TYPE_SECONDARY] = 0;
        p_ammos[playerid][TYPE_SECONDARY] = 0;
        RemovePlayerWeapon(playerid, 29);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        PlayerAction(playerid, "unequips an MP5.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 26 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo1", 0);
        EquipItem(playerid, 26, islot, false);
    }
	return 1;
}

Usemicrouzi(playerid, islot) {
	if(!HasPlayerItem(playerid, 25, 1)) return SCM(playerid, HEX_RED, "Error: You need a micro uzi in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 39, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 9mm ammunition.");
        if(Bit_Get(slot_secondary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your secondary weapon.");
        SetPVarInt(playerid, "ammo1", 39);
        Bit_Let(slot_secondary, playerid);
        
        p_weapon[playerid][TYPE_SECONDARY] = 28;
        p_ammos[playerid][TYPE_SECONDARY] = CountPlayerItem(playerid, 39, false);
        
        new maxam = WeaponAmmo(28);
        if(p_ammos[playerid][TYPE_SECONDARY] > maxam) {
            p_ammos[playerid][TYPE_SECONDARY] = maxam;
        }
        RemovePlayerItem(playerid, 39, p_ammos[playerid][TYPE_SECONDARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_SECONDARY], p_ammos[playerid][TYPE_SECONDARY]);
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], GetItemObject(25));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        ApplyAnimation(playerid, "uzi", "uzi_reload", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a micro uzi.");
        inventory_used[playerid][islot] = true;
        if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_ENTER_VEHICLE_DRIVER)
            SetPlayerArmedWeapon(playerid, 0);
        
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 25 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 25, islot, true);
    }
    else {
        
        Bit_Vet(slot_secondary, playerid);
        
        SaveAmmo(playerid, TYPE_SECONDARY);
        p_weapon[playerid][TYPE_SECONDARY] = 0;
        p_ammos[playerid][TYPE_SECONDARY] = 0;
        RemovePlayerWeapon(playerid, 28);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        PlayerAction(playerid, "unequips a micro uzi.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 25 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo1", 0);
        EquipItem(playerid, 25, islot, false);
    }
	return 1;
}

Usespaz(playerid, islot) {
	if(!HasPlayerItem(playerid, 24, 1)) return SCM(playerid, HEX_RED, "Error: You need a combat shotgun in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 40, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 12 gauge ammunition.");
        if(Bit_Get(slot_secondary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your secondary weapon.");
        SetPVarInt(playerid, "ammo1", 40);
        Bit_Let(slot_secondary, playerid);
        
        p_weapon[playerid][TYPE_SECONDARY] = 27;
        p_ammos[playerid][TYPE_SECONDARY] = CountPlayerItem(playerid, 40, false);
        
        new maxam = WeaponAmmo(27);
        if(p_ammos[playerid][TYPE_SECONDARY] > maxam) {
            p_ammos[playerid][TYPE_SECONDARY] = maxam;
        }
        RemovePlayerItem(playerid, 40, p_ammos[playerid][TYPE_SECONDARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_SECONDARY], p_ammos[playerid][TYPE_SECONDARY]);
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], GetItemObject(24));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        ApplyAnimation(playerid, "BUDDY", "BUDDY_RELOAD", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a combat shotgun.");
        inventory_used[playerid][islot] = true;
        
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 24 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);

        if(IsPlayerInAnyVehicle(playerid))
            SetPlayerArmedWeapon(playerid, 0);
        EquipItem(playerid, 24, islot, true);
    }
    else {
        
        Bit_Vet(slot_secondary, playerid);
        
        SaveAmmo(playerid, TYPE_SECONDARY);
        p_weapon[playerid][TYPE_SECONDARY] = 0;
        p_ammos[playerid][TYPE_SECONDARY] = 0;
        RemovePlayerWeapon(playerid, 27);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        PlayerAction(playerid, "unequips a combat shotgun.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 24 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo1", 0);
        EquipItem(playerid, 24, islot, false);
    }
	return 1;
}

UseSawnoffShotgun(playerid, islot) {
	if(!HasPlayerItem(playerid, 23, 1)) return SCM(playerid, HEX_RED, "Error: You need a sawnoff shotgun in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 40, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 12 gauge ammunition.");
        if(Bit_Get(slot_secondary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your secondary weapon.");
        SetPVarInt(playerid, "ammo1", 40);
        Bit_Let(slot_secondary, playerid);
        
        p_weapon[playerid][TYPE_SECONDARY] = 26;
        p_ammos[playerid][TYPE_SECONDARY] = CountPlayerItem(playerid, 40, false);
        
        new maxam = WeaponAmmo(26);
        if(p_ammos[playerid][TYPE_SECONDARY] > maxam) {
            p_ammos[playerid][TYPE_SECONDARY] = maxam;
        }
        RemovePlayerItem(playerid, 40, p_ammos[playerid][TYPE_SECONDARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_SECONDARY], p_ammos[playerid][TYPE_SECONDARY]);
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], GetItemObject(23));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        ApplyAnimation(playerid, "BUDDY", "BUDDY_RELOAD", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a sawnoff shotgun.");
        inventory_used[playerid][islot] = true;
        
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 23 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 23, islot, true);
    }
    else {
        
        Bit_Vet(slot_secondary, playerid);
        
        SaveAmmo(playerid, TYPE_SECONDARY);
        p_weapon[playerid][TYPE_SECONDARY] = 0;
        p_ammos[playerid][TYPE_SECONDARY] = 0;
        RemovePlayerWeapon(playerid, 26);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        PlayerAction(playerid, "unequips a sawnoff shotgun.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 23 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo1", 0);
        EquipItem(playerid, 23, islot, false);
    }
	return 1;
}

UseSilencedpistol(playerid, islot) {
	if(!HasPlayerItem(playerid, 20, 1)) return SCM(playerid, HEX_RED, "Error: You need a silenced pistol in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 39, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 9mm ammunition.");
        if(Bit_Get(slot_pistol, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your pistol.");
        SetPVarInt(playerid, "ammo2", 39);
        Bit_Let(slot_pistol, playerid);
        
        p_weapon[playerid][TYPE_PISTOL] = 23;
        p_ammos[playerid][TYPE_PISTOL] = CountPlayerItem(playerid, 39, false);
        
        new maxam = WeaponAmmo(23);
        if(p_ammos[playerid][TYPE_PISTOL] > maxam) {
            p_ammos[playerid][TYPE_PISTOL] = maxam;
        }
        RemovePlayerItem(playerid, 39, p_ammos[playerid][TYPE_PISTOL]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PISTOL], p_ammos[playerid][TYPE_PISTOL]);
        ApplyAnimation(playerid, "SILENCED", "Silence_reload", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a silenced pistol.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][6], GetItemObject(20));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][6]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 20 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 20, islot, true);
    }
    else {
        
        Bit_Vet(slot_pistol, playerid);
        
        SaveAmmo(playerid, TYPE_PISTOL);
        p_weapon[playerid][TYPE_PISTOL] = 0;
        p_ammos[playerid][TYPE_PISTOL] = 0;
        RemovePlayerWeapon(playerid, 23);
        inventory_used[playerid][islot] = false;
        PlayerAction(playerid, "unequips a silenced pistol.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][6], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][6]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 20 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo2", 0);
        EquipItem(playerid, 20, islot, false);
    }
	return 1;
}

UseShotgun(playerid, islot) {
	if(!HasPlayerItem(playerid, 22, 1)) return SCM(playerid, HEX_RED, "Error: You need a shotgun in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 40, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 12 gauge ammunition.");
        if(Bit_Get(slot_secondary, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your secondary weapon.");
        SetPVarInt(playerid, "ammo1", 40);
        Bit_Let(slot_secondary, playerid);
        
        p_weapon[playerid][TYPE_SECONDARY] = 25;
        p_ammos[playerid][TYPE_SECONDARY] = CountPlayerItem(playerid, 40, false);
        
        new maxam = WeaponAmmo(25);
        if(p_ammos[playerid][TYPE_SECONDARY] > maxam) {
            p_ammos[playerid][TYPE_SECONDARY] = maxam;
        }
        RemovePlayerItem(playerid, 40, p_ammos[playerid][TYPE_SECONDARY]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_SECONDARY], p_ammos[playerid][TYPE_SECONDARY]);
        ApplyAnimation(playerid, "BUDDY", "BUDDY_RELOAD", 4.0, 0, 0, 0, 0, 0);
        PlayerAction(playerid, "equips a shotgun.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], GetItemObject(22));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 22 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 22, islot, true);
    }
    else {
        
        Bit_Vet(slot_secondary, playerid);
        
        SaveAmmo(playerid, TYPE_SECONDARY);
        p_weapon[playerid][TYPE_SECONDARY] = 0;
        p_ammos[playerid][TYPE_SECONDARY] = 0;
        RemovePlayerWeapon(playerid, 25);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
        PlayerAction(playerid, "unequips a shotgun.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 22 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo1", 0);
        EquipItem(playerid, 22, islot, false);
    }
	return 1;
}

UseDeagle(playerid, islot) {
	if(!HasPlayerItem(playerid, 21, 1)) return SCM(playerid, HEX_RED, "Error: You need a heavy pistol in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 41, 1)) return SCM(playerid, HEX_RED, "Error: You do not have .45 ACP ammunition.");
        if(Bit_Get(slot_pistol, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your pistol.");
        SetPVarInt(playerid, "ammo2", 41);
        Bit_Let(slot_pistol, playerid);
        
        p_weapon[playerid][TYPE_PISTOL] = 24;
        p_ammos[playerid][TYPE_PISTOL] = CountPlayerItem(playerid, 41, false);
        
        new maxam = WeaponAmmo(24);
        if(p_ammos[playerid][TYPE_PISTOL] > maxam) {
            p_ammos[playerid][TYPE_PISTOL] = maxam;
        }
        RemovePlayerItem(playerid, 41, p_ammos[playerid][TYPE_PISTOL]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PISTOL], p_ammos[playerid][TYPE_PISTOL]);
        ApplyAnimation(playerid, "PYTHON", "python_reload", 4.0, 0, 0, 0, 0, 0);
	    PlayerAction(playerid, "equips a heavy pistol.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][6], GetItemObject(19));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][6]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 21 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        if(IsPlayerInAnyVehicle(playerid))
            SetPlayerArmedWeapon(playerid, 0);
        EquipItem(playerid, 21, islot, true);
    }
    else {
        
        Bit_Vet(slot_pistol, playerid);
        
        SaveAmmo(playerid, TYPE_PISTOL);
        p_weapon[playerid][TYPE_PISTOL] = 0;
        p_ammos[playerid][TYPE_PISTOL] = 0;
        RemovePlayerWeapon(playerid, 24);
        inventory_used[playerid][islot] = false;
        PlayerAction(playerid, "unequips a heavy pistol.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][6], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][6]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 21 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo2", 0);
        EquipItem(playerid, 21, islot, false);
    }
	return 1;
}

UsePistol(playerid, islot) {
	if(!HasPlayerItem(playerid, 19, 1)) return SCM(playerid, HEX_RED, "Error: You need a pistol in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(!HasPlayerItem(playerid, 39, 1)) return SCM(playerid, HEX_RED, "Error: You do not have 9mm ammunition.");
        if(Bit_Get(slot_pistol, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your pistol.");
        SetPVarInt(playerid, "ammo2", 39);
        Bit_Let(slot_pistol, playerid);
        
        p_weapon[playerid][TYPE_PISTOL] = 22;
        p_ammos[playerid][TYPE_PISTOL] = CountPlayerItem(playerid, 39, false);
        
        new maxam = WeaponAmmo(22);
        if(p_ammos[playerid][TYPE_PISTOL] > maxam) {
            p_ammos[playerid][TYPE_PISTOL] = maxam;
        }
        RemovePlayerItem(playerid, 39, p_ammos[playerid][TYPE_PISTOL]);
        

        GivePlayerWeapon(playerid, p_weapon[playerid][TYPE_PISTOL], p_ammos[playerid][TYPE_PISTOL]);
        ApplyAnimation(playerid, "PYTHON", "python_reload", 4.0, 0, 0, 0, 0, 0);
	    PlayerAction(playerid, "equips a pistol.");
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][6], GetItemObject(19));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][6]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 19 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
        mysql_query(g_SQL, sql);
        EquipItem(playerid, 19, islot, true);
    }
    else {
        
        Bit_Vet(slot_pistol, playerid);
        
        SaveAmmo(playerid, TYPE_PISTOL);
        p_weapon[playerid][TYPE_PISTOL] = 0;
        p_ammos[playerid][TYPE_PISTOL] = 0;
        RemovePlayerWeapon(playerid, 22);
        inventory_used[playerid][islot] = false;
        PlayerAction(playerid, "unequips a pistol.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][6], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][6]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 19 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
        SetPVarInt(playerid, "ammo2", 0);
        EquipItem(playerid, 19, islot, false);
    }
	return 1;
}

UseVirussample(playerid) {
	SCM(playerid, HEX_FADE2, "Usage: /cure");
	return 1;
}

UseAntidote(playerid) {
	SCM(playerid, HEX_FADE2, "Usage: /cure");
	return 1;
}


UseRadio(playerid) {
	SCM(playerid, HEX_FADE2, "Usage: /radiohelp");
	return 1;
}

UseFirstaid(playerid) {
	SCM(playerid, HEX_FADE2, "Usage: /heal [id]");
	return 1;
}

UseMediccase(playerid) {
	SCM(playerid, HEX_FADE2, "Usage: /revive [id]");
	return 1;
}

UseParachute(playerid) {
	if(!HasPlayerItem(playerid, 38, 1)) return SCM(playerid, HEX_RED, "Error: You need a parachute in your inventory.");
	RemovePlayerItem(playerid, 38, 1);

	GivePlayerWeapon(playerid, 46, 1);
    PlayerAction(playerid, "equips a parachute.");

    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][2], GetItemObject(38));
    PlayerTextDrawShow(playerid, inv_personindex[playerid][2]);

    CloseInventory(playerid);
    OpenInventory(playerid);

    if(Bit_Get(tutorial, playerid))
	    SCM(playerid, HEX_FADE2, "Hint: Your parachute will be lost upon relogging.");
	return 1;
}

UseCamera(playerid, islot) {
	if(!HasPlayerItem(playerid, 35, 1)) return SCM(playerid, HEX_RED, "Error: You need a camera in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 35, islot, true);
        p_weapon[playerid][3] = 43;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 700);
        inventory_used[playerid][islot] = true;
	    PlayerAction(playerid, "equips a camera.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(35));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 35 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 35, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 43);
        inventory_used[playerid][islot] = false;
        PlayerAction(playerid, "puts away a camera.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 35 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseMolotov(playerid) {
	if(!HasPlayerItem(playerid, 18, 1)) return SCM(playerid, HEX_RED, "Error: You need a molotov cocktail in your inventory.");
	RemovePlayerItem(playerid, 18, 1);

	GivePlayerWeapon(playerid, 18, 1);

    if(Bit_Get(tutorial, playerid))
	    SCM(playerid, HEX_FADE2, "Hint: Your hand-held molotov cocktail will be lost upon relogging.");
	

	ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	PlayerAction(playerid, "lights a molotov cocktail.");
    CloseInventory(playerid);
    OpenInventory(playerid);
	return 1;
}

UseTeargas(playerid) {
	if(!HasPlayerItem(playerid, 17, 1)) return SCM(playerid, HEX_RED, "Error: You need a tear gas in your inventory.");
	RemovePlayerItem(playerid, 17, 1);

	GivePlayerWeapon(playerid, 17, 1);
	
    if(Bit_Get(tutorial, playerid))
	    SCM(playerid, HEX_FADE2, "Hint: Your hand-held tear gas will be lost upon relogging.");

	PlayerAction(playerid, "prepares a teargas.");
    CloseInventory(playerid);
    OpenInventory(playerid);
	return 1;
}

UseGrenade(playerid) {
	if(!HasPlayerItem(playerid, 16, 1)) return SCM(playerid, HEX_RED, "Error: You need a grenade in your inventory.");
	RemovePlayerItem(playerid, 16, 1);

	GivePlayerWeapon(playerid, 16, 1);

    if(Bit_Get(tutorial, playerid))
	    SCM(playerid, HEX_FADE2, "Hint: Your hand-held grenade will be lost upon relogging.");

	PlayerAction(playerid, "takes hold of a grenade.");
    CloseInventory(playerid);
    OpenInventory(playerid);
	return 1;
}

UseCane(playerid, islot) {
	if(!HasPlayerItem(playerid, 15, 1)) return SCM(playerid, HEX_RED, "Error: You need a cane in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 15, islot, true);
        p_weapon[playerid][3] = 15;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
	    PlayerAction(playerid, "holds a cane.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(15));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 15 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 15, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 15);
        inventory_used[playerid][islot] = false;
        PlayerAction(playerid, "puts away a cane.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 15 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseFlowers(playerid, islot) {
	if(!HasPlayerItem(playerid, 14, 1)) return SCM(playerid, HEX_RED, "Error: You need flowers in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 14, islot, true);
        p_weapon[playerid][3] = 14;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerAction(playerid, "holds a bouquet of flowers.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(14));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = %d AND state = 1 LIMIT 1",  CharacterSQL[playerid], 14);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 14, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 14);
        inventory_used[playerid][islot] = false;
        PlayerAction(playerid, "puts away a bouquet of flowers.");
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = %d AND state = 1 LIMIT 1",  CharacterSQL[playerid], 14);
		mysql_query(g_SQL, sql);
    }

	return 1;
}

UseSilvervibrator(playerid, islot) {
	if(!HasPlayerItem(playerid, 13, 1)) return SCM(playerid, HEX_RED, "Error: You need a silver vibrator in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 13, islot, true);
        p_weapon[playerid][3] = 13;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(13));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
	    PlayerAction(playerid, "equips a silver vibrator.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 13 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 13, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 13);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a silver vibrator.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 13 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseVibrator(playerid, islot) {
	if(!HasPlayerItem(playerid, 12, 1)) return SCM(playerid, HEX_RED, "Error: You need a vibrator in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 12, islot, true);
        p_weapon[playerid][3] = 12;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(12));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
	    PlayerAction(playerid, "equips a vibrator.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 12 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 12, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 12);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a vibrator.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 12 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseDildo(playerid, islot) {
	if(!HasPlayerItem(playerid, 11, 1)) return SCM(playerid, HEX_RED, "Error: You need a dildo in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 11, islot, true);
        p_weapon[playerid][3] = 11;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(11));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
	    PlayerAction(playerid, "equips a dildo.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 11 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 11, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 11);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a dildo.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 11 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UsePurpledildo(playerid, islot) {
	if(!HasPlayerItem(playerid, 10, 1)) return SCM(playerid, HEX_RED, "Error: You need a purple dildo in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 10, islot, true);
        p_weapon[playerid][3] = 10;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(10));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
	    PlayerAction(playerid, "equips a purple dildo.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 10 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 10, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 10);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a purple dildo.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 10 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseChainsaw(playerid, islot) {
	if(!HasPlayerItem(playerid, 9, 1)) return SCM(playerid, HEX_RED, "Error: You need a chainsaw in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 9, islot, true);
        p_weapon[playerid][3] = 9;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(9));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "equips a chainsaw.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 9 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 9, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 9);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a chainsaw.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 9 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseKatana(playerid, islot) {
	if(!HasPlayerItem(playerid, 8, 1)) return SCM(playerid, HEX_RED, "Error: You need a katana in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 8, islot, true);
        p_weapon[playerid][3] = 8;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(8));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
	    PlayerAction(playerid, "equips a katana.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 8 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 8, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 8);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a katana.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 8 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UsePoolcue(playerid, islot) {
	if(!HasPlayerItem(playerid, 7, 1)) return SCM(playerid, HEX_RED, "Error: You need a pool cue in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 7, islot, true);
        p_weapon[playerid][3] = 7;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(7));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "holds a pool cue.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 7 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 7, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 7);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a pool cue.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 7 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseShovel(playerid, islot) {
	if(!HasPlayerItem(playerid, 6, 1)) return SCM(playerid, HEX_RED, "Error: You need a shoved in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 6, islot, true);
        p_weapon[playerid][3] = 6;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(6));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "takes hold of a shovel.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 6 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 6, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 6);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a shovel.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 6 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseBat(playerid, islot) {
	if(!HasPlayerItem(playerid, 5, 1)) return SCM(playerid, HEX_RED, "Error: You need a basebal bat in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 5, islot, true);
        p_weapon[playerid][3] = 5;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(5));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "takes hold of a baseball bat.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 5 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 5, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 5);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a baseball bat.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 5 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseKnife(playerid, islot) {
	if(!HasPlayerItem(playerid, 4, 1)) return SCM(playerid, HEX_RED, "Error: You need a knife in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 4, islot, true);
        p_weapon[playerid][3] = 4;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(4));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "unsheathes a knife.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 4 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 4, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 4);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "sheats a knife.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 4 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseNightstick(playerid, islot) {
	if(!HasPlayerItem(playerid, 3, 1)) return SCM(playerid, HEX_RED, "Error: You need a nightstick in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 3, islot, true);
        p_weapon[playerid][3] = 3;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(3));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "takes hold of a nightstick.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 3 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 3, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 3);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a nightstick.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 3 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
	return 1;
}

UseGolfclub(playerid, islot) {
	if(!HasPlayerItem(playerid, 2, 1)) return SCM(playerid, HEX_RED, "Error: You need a golf club in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 2, islot, true);
        p_weapon[playerid][3] = 2;
        GivePlayerWeapon(playerid, p_weapon[playerid][3], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(2));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "takes hold of a golf club.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 2 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 2, islot, false);
        p_weapon[playerid][3] = 0;
        RemovePlayerWeapon(playerid, 2);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a golf club.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 2 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }

	return 1;
}

UseBoxers(playerid, islot) {
	if(!HasPlayerItem(playerid, 1, 1)) return SCM(playerid, HEX_RED, "Error: You need a boxer in your inventory.");

    if(!inventory_used[playerid][islot]) {
        if(Bit_Get(slot_melee, playerid)) return SCM(playerid, HEX_RED, "Error: You need to unequip your melee item.");
        Bit_Let(slot_melee, playerid);
        EquipItem(playerid, 1, islot, true);
        p_weapon[playerid][2] = 1;
        GivePlayerWeapon(playerid, p_weapon[playerid][2], 1);
        inventory_used[playerid][islot] = true;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], GetItemObject(1));
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "prepares a pair of boxers.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 1 WHERE playerId = %d AND itemId = 1 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }
    else {
        Bit_Vet(slot_melee, playerid);
        EquipItem(playerid, 1, islot, false);
        p_weapon[playerid][2] = 0;
        RemovePlayerWeapon(playerid, 1);
        inventory_used[playerid][islot] = false;
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);
        PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
        PlayerAction(playerid, "puts away a pair of boxers.");
        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND itemId = 1 AND state = 1 LIMIT 1",  CharacterSQL[playerid]);
		mysql_query(g_SQL, sql);
    }

	return 1;
}


ShowItemInfo(playerid, itemid, amount) {

    mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `itemlist` WHERE id = %d", itemid);
	inline LoadItemInfo() {
		if(!cache_num_rows()) {
			SCM(playerid, HEX_RED, "Error: No item found.");
			@return 0;
		}
		
        new in_object, in_description[256], in_name[64];
        
		cache_get_value_int(0, "object", in_object);
        cache_get_value(0, "description", in_description, 256);
        cache_get_value(0, "name", in_name, 64);

        PlayerTextDrawSetString(playerid, inv_description[playerid][1], in_name);
        PlayerTextDrawShow(playerid, inv_description[playerid][1]);
        /* Note: just use ~n~ in the item description in the database!


        if(strlen(in_description) > 29) strins(in_description, "~n~", 30);//new lines if item info is too long
        if(strlen(in_description) > 62) strins(in_description, "~n~", 63);//new lines if item info is too long
        if(strlen(in_description) > 95) strins(in_description, "~n~", 96);//new lines if item info is too long
        */
        PlayerTextDrawSetString(playerid, inv_description[playerid][2], in_description);
        PlayerTextDrawShow(playerid, inv_description[playerid][2]);

        format(in_name, sizeof in_name, "amount:_%d", amount);
        PlayerTextDrawSetString(playerid, inv_description[playerid][3], in_name);
        PlayerTextDrawShow(playerid, inv_description[playerid][3]);

        PlayerTextDrawSetPreviewModel(playerid, inv_description[playerid][0], in_object);
        PlayerTextDrawShow(playerid, inv_description[playerid][0]);


		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadItemInfo, sql);

    return 1;
}

ReloadPlayerInventory(playerid, bool:lootingdata = false) {
    mysql_format(g_SQL, sql, sizeof sql, "DELETE FROM `player_items` WHERE `playerId` = %d AND `amount` = 0",  CharacterSQL[playerid]);
    mysql_query(g_SQL, sql);
    mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_items` WHERE playerId = '%d' AND amount > '0' AND state = '1' ORDER BY slotId ASC, modDate ASC LIMIT %d", CharacterSQL[playerid], MAX_INVENTORY_SLOTS);
	new Cache:result = mysql_query(g_SQL, sql);
	new i = -1;
    for(;++i<cache_num_rows();) {
        cache_get_value_int(i, "itemId", inventory_itemid[playerid][i]);
        cache_get_value_int(i, "amount", inventory_amount[playerid][i]);
        cache_get_value_int(i, "used", inventory_used[playerid][i]);
        if(!lootingdata)
            PlayerTextDrawSetSelectable(playerid, inv_index[playerid][i], true);
        PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][i], 96);
        if(inventory_used[playerid][i])
            PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][i], 0x29aa2977);
        //printf("inventory_itemid[%d][%d] = %d, inventory_amount[%d][%d] = %d", playerid, i, inventory_itemid[playerid][i], playerid, i, inventory_amount[playerid][i]); // used for debugging inventory
        //SFM(playerid, HEX_FADE2, "Debug: reloading slot %d, itenid = %d", i, inventory_itemid[playerid][i]);
    }
    --i;
    for(;++i<MAX_INVENTORY_SLOTS;) {
        inventory_itemid[playerid][i] = 0;
        inventory_amount[playerid][i] = 0;
        inventory_used[playerid][i] = false;
        PlayerTextDrawSetSelectable(playerid, inv_index[playerid][i], false);
        PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][i], 96);
        //SFM(playerid, HEX_FADE2, "Debug: reloading slot %d, itenid = %d", i, inventory_itemid[playerid][i]);
    }
    new Float:temparmour;
    GetPlayerArmour(playerid, temparmour);
    if(temparmour > 0.0) {
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][1], GetItemObject(63));//kevlar
    }
    else
        PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][1], 19382);//empty

    cache_delete(result);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(newkeys & KEY_CTRL_BACK && !IsPlayerInAnyVehicle(playerid)) { // H Key

        if(!SpamPrevent(playerid)) return Y_HOOKS_BREAK_RETURN_1;

        if(Bit_Get(dead, playerid) || IsZombie(playerid)) {
            SCM(playerid, HEX_RED, "Error: You cannot do that now.");
            return Y_HOOKS_BREAK_RETURN_1;
        }

        if(!Bit_Get(openinventory, playerid))
            OpenInventory(playerid);
        else
            CloseInventory(playerid);

    }

    else if(GetPlayerWeapon(playerid) == 35 || GetPlayerWeapon(playerid) == 36) {
        if (newkeys & KEY_FIRE) {

            p_ammos[playerid][TYPE_PRIMARY] = 0;
            ++p_shots[playerid][TYPE_PRIMARY];

        }

    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}


CloseInventory(playerid) {
    Bit_Vet(openinventory, playerid);
    HideInvmenuBasic(playerid);
    HideInvMenuPlayer(playerid);
    CancelSelectTextDraw(playerid);
    return 1;
}

OpenInventory(playerid) {
    Bit_Let(openinventory, playerid);
    //SaveAmmo(playerid);
    ReloadPlayerInventory(playerid);
    RefreshInventoryTextdraws(playerid);            
    ShowInvmenuBasic(playerid);
    ShowInvMenuPlayer(playerid);
    SelectTextDraw(playerid, 0x2c578dFF);
    return 1;
}

 
hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid) {

    new i = -1;
    for(;++i<MAX_INVENTORY_SLOTS;) {
        if(inv_index[playerid][i] == playertextid) {

            //PlayerTextDrawHide(playerid, inv_index[playerid][selectitem[playerid]]);

            PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][selectitem[playerid]], 96);
            if(inventory_used[playerid][selectitem[playerid]])
                PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][selectitem[playerid]], 0x29aa2977);
            PlayerTextDrawShow(playerid, inv_index[playerid][selectitem[playerid]]);

            selectitem[playerid] = i;
            //SFM(playerid, HEX_FADE2, "Debug: You selected item %d!", i);
            PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][i], 0x2c578d77);
            //PlayerTextDrawHide(playerid, inv_index[playerid][i]);
            PlayerTextDrawShow(playerid, inv_index[playerid][i]);

            ShowItemInfo(playerid, inventory_itemid[playerid][i], inventory_amount[playerid][i]);

            return Y_HOOKS_BREAK_RETURN_1;
        }
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickTextDraw(playerid, Text:clickedid) {
    
    if(clickedid == invmenu_td[0] || clickedid == invmenu_td[1])
        CloseInventory(playerid);

    if(clickedid == inv_split[0]) {
        SplitDropItem(playerid, selectitem[playerid]);
        return Y_HOOKS_BREAK_RETURN_1;   
    }

    if(clickedid == inv_drop[0]) {
        //SFM(playerid, HEX_RED, "Error: This item cannot be dropped. (Feature under development!)");
        DropItem(playerid, selectitem[playerid]);
        return Y_HOOKS_BREAK_RETURN_1;   
    }

    if(clickedid == inv_user) {
        UseItem(playerid, selectitem[playerid]);
        return Y_HOOKS_BREAK_RETURN_1;  
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}


hook OnGameModeInit() {
    Invmenu_LoadTextDraws();
    mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE state = 1");
    mysql_tquery(g_SQL, sql, "", "");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerConnect(playerid) {
    Invmenu_LoadPlayerTextDraws(playerid);

    p_weapon[playerid][0] = 0;
    p_weapon[playerid][1] = 0;
    p_weapon[playerid][2] = 0;
    p_weapon[playerid][3] = 0;

    p_ammos[playerid][0] = 0;
    p_ammos[playerid][1] = 0;
    p_ammos[playerid][2] = 0;
    p_ammos[playerid][3] = 0;

    p_shots[playerid][0] = 0;
    p_shots[playerid][1] = 0;
    p_shots[playerid][2] = 0;
    p_shots[playerid][3] = 0;

    return Y_HOOKS_CONTINUE_RETURN_1;
}

RefreshInventoryTextdraws(playerid) {

    selectitem[playerid] = 0;

    PlayerTextDrawSetString(playerid, inv_text[playerid][0], PlayerName(playerid));
    PlayerTextDrawSetPreviewModel(playerid, inv_skin[playerid], GetPlayerSkin(playerid));

    new i = -1;
    for(;++i<MAX_INVENTORY_SLOTS;) {
        if(inventory_itemid[playerid][i] == 0) {
            PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][i], 19382);
        }
        else {
            PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][i], GetItemObject(inventory_itemid[playerid][i]));
            if(i == selectitem[playerid]) {
                PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][i], 0x2c578d77);
                ShowItemInfo(playerid, inventory_itemid[playerid][i], inventory_amount[playerid][i]);
            }
        }
    }

    return 1;
}

/*YCMD:invmenu(playerid, params[], help) {
    ReloadPlayerInventory(playerid);
    ShowInvmenuBasic(playerid);
    ShowInvMenuPlayer(playerid);
    return 1;
}

YCMD:closeinvmenu(playerid, params[], help) {
    HideInvmenuBasic(playerid);
    HideInvMenuPlayer(playerid);
    return 1;
}*/

/*stock ConvertToGameText(in[]) {
    new string[256];
    for(new i = 0; in[i]; ++i)
    {
        string[i] = in[i];
        switch(string[i])
        {
            case 0xC0 .. 0xC3: string[i] -= 0x40;
            case 0xC7 .. 0xC9: string[i] -= 0x42;
            case 0xD2 .. 0xD5: string[i] -= 0x44;
            case 0xD9 .. 0xDC: string[i] -= 0x47;
            case 0xE0 .. 0xE3: string[i] -= 0x49;
            case 0xE7 .. 0xEF: string[i] -= 0x4B;
            case 0xF2 .. 0xF5: string[i] -= 0x4D;
            case 0xF9 .. 0xFC: string[i] -= 0x50;
            case 0xC4, 0xE4: string[i] = 0x83;
            case 0xC6, 0xE6: string[i] = 0x84;
            case 0xD6, 0xF6: string[i] = 0x91;
            case 0xD1, 0xF1: string[i] = 0xEC;
            case 0xDF: string[i] = 0x96;
            case 0xBF: string[i] = 0xAF;
        }
    }
    return string;
}*/

ShowInvMenuPlayer(playerid) {

    PlayerTextDrawShow(playerid, inv_index[playerid][0]);
    PlayerTextDrawShow(playerid, inv_index[playerid][1]);
    PlayerTextDrawShow(playerid, inv_index[playerid][2]);
    PlayerTextDrawShow(playerid, inv_index[playerid][3]);
    PlayerTextDrawShow(playerid, inv_index[playerid][4]);
    PlayerTextDrawShow(playerid, inv_index[playerid][5]);
    PlayerTextDrawShow(playerid, inv_index[playerid][6]);
    PlayerTextDrawShow(playerid, inv_index[playerid][7]);
    PlayerTextDrawShow(playerid, inv_index[playerid][8]);
    PlayerTextDrawShow(playerid, inv_index[playerid][9]);
    PlayerTextDrawShow(playerid, inv_index[playerid][10]);
    PlayerTextDrawShow(playerid, inv_index[playerid][11]);
    PlayerTextDrawShow(playerid, inv_index[playerid][12]);
    PlayerTextDrawShow(playerid, inv_index[playerid][13]);
    PlayerTextDrawShow(playerid, inv_index[playerid][14]);

    PlayerTextDrawShow(playerid, inv_skin[playerid]);

    PlayerTextDrawShow(playerid, inv_text[playerid][0]);
    PlayerTextDrawShow(playerid, inv_text[playerid][1]);
    PlayerTextDrawShow(playerid, inv_text[playerid][2]);
    PlayerTextDrawShow(playerid, inv_text[playerid][3]);
    PlayerTextDrawShow(playerid, inv_text[playerid][4]);
    PlayerTextDrawShow(playerid, inv_text[playerid][5]);
    PlayerTextDrawShow(playerid, inv_text[playerid][6]);
    PlayerTextDrawShow(playerid, inv_text[playerid][7]);
    PlayerTextDrawShow(playerid, inv_text[playerid][8]);
    PlayerTextDrawShow(playerid, inv_text[playerid][9]);
    PlayerTextDrawShow(playerid, inv_text[playerid][10]);

    PlayerTextDrawShow(playerid, inv_description[playerid][0]);
    PlayerTextDrawShow(playerid, inv_description[playerid][1]);
    PlayerTextDrawShow(playerid, inv_description[playerid][2]);
    PlayerTextDrawShow(playerid, inv_description[playerid][3]);

    PlayerTextDrawShow(playerid, inv_personindex[playerid][0]);
    PlayerTextDrawShow(playerid, inv_personindex[playerid][1]);
    PlayerTextDrawShow(playerid, inv_personindex[playerid][2]);
    PlayerTextDrawShow(playerid, inv_personindex[playerid][3]);
    PlayerTextDrawShow(playerid, inv_personindex[playerid][4]);
    PlayerTextDrawShow(playerid, inv_personindex[playerid][5]);
    PlayerTextDrawShow(playerid, inv_personindex[playerid][6]);

    PlayerTextDrawShow(playerid, inv_message[playerid]);
    return 1;
}

HideInvMenuPlayer(playerid) {

    PlayerTextDrawHide(playerid, inv_index[playerid][0]);
    PlayerTextDrawHide(playerid, inv_index[playerid][1]);
    PlayerTextDrawHide(playerid, inv_index[playerid][2]);
    PlayerTextDrawHide(playerid, inv_index[playerid][3]);
    PlayerTextDrawHide(playerid, inv_index[playerid][4]);
    PlayerTextDrawHide(playerid, inv_index[playerid][5]);
    PlayerTextDrawHide(playerid, inv_index[playerid][6]);
    PlayerTextDrawHide(playerid, inv_index[playerid][7]);
    PlayerTextDrawHide(playerid, inv_index[playerid][8]);
    PlayerTextDrawHide(playerid, inv_index[playerid][9]);
    PlayerTextDrawHide(playerid, inv_index[playerid][10]);
    PlayerTextDrawHide(playerid, inv_index[playerid][11]);
    PlayerTextDrawHide(playerid, inv_index[playerid][12]);
    PlayerTextDrawHide(playerid, inv_index[playerid][13]);
    PlayerTextDrawHide(playerid, inv_index[playerid][14]);

    PlayerTextDrawHide(playerid, inv_skin[playerid]);

    PlayerTextDrawHide(playerid, inv_text[playerid][0]);
    PlayerTextDrawHide(playerid, inv_text[playerid][1]);
    PlayerTextDrawHide(playerid, inv_text[playerid][2]);
    PlayerTextDrawHide(playerid, inv_text[playerid][3]);
    PlayerTextDrawHide(playerid, inv_text[playerid][4]);
    PlayerTextDrawHide(playerid, inv_text[playerid][5]);
    PlayerTextDrawHide(playerid, inv_text[playerid][6]);
    PlayerTextDrawHide(playerid, inv_text[playerid][7]);
    PlayerTextDrawHide(playerid, inv_text[playerid][8]);
    PlayerTextDrawHide(playerid, inv_text[playerid][9]);
    PlayerTextDrawHide(playerid, inv_text[playerid][10]);

    PlayerTextDrawHide(playerid, inv_description[playerid][0]);
    PlayerTextDrawHide(playerid, inv_description[playerid][1]);
    PlayerTextDrawHide(playerid, inv_description[playerid][2]);
    PlayerTextDrawHide(playerid, inv_description[playerid][3]);

    PlayerTextDrawHide(playerid, inv_personindex[playerid][0]);
    PlayerTextDrawHide(playerid, inv_personindex[playerid][1]);
    PlayerTextDrawHide(playerid, inv_personindex[playerid][2]);
    PlayerTextDrawHide(playerid, inv_personindex[playerid][3]);
    PlayerTextDrawHide(playerid, inv_personindex[playerid][4]);
    PlayerTextDrawHide(playerid, inv_personindex[playerid][5]);
    PlayerTextDrawHide(playerid, inv_personindex[playerid][6]);

    PlayerTextDrawHide(playerid, inv_message[playerid]);

    return 1;
}

ShowInvmenuBasic(playerid) {
    TextDrawShowForPlayer(playerid, invtd[0]);
    TextDrawShowForPlayer(playerid, invtd[1]);
    TextDrawShowForPlayer(playerid, invtd[2]);
    TextDrawShowForPlayer(playerid, invtd[3]);
    TextDrawShowForPlayer(playerid, invtd[4]);

    TextDrawShowForPlayer(playerid, inv_user);

    TextDrawShowForPlayer(playerid, inv_split[0]);
    TextDrawShowForPlayer(playerid, inv_split[1]);

    TextDrawShowForPlayer(playerid, inv_remove);

    TextDrawShowForPlayer(playerid, inv_drop[0]);
    TextDrawShowForPlayer(playerid, inv_drop[1]);

    TextDrawShowForPlayer(playerid, invmenu_td[0]);
    TextDrawShowForPlayer(playerid, invmenu_td[1]);
    return 1;
}

HideInvmenuBasic(playerid) {

    TextDrawHideForPlayer(playerid, invtd[0]);
    TextDrawHideForPlayer(playerid, invtd[1]);
    TextDrawHideForPlayer(playerid, invtd[2]);
    TextDrawHideForPlayer(playerid, invtd[3]);
    TextDrawHideForPlayer(playerid, invtd[4]);

    TextDrawHideForPlayer(playerid, inv_user);

    TextDrawHideForPlayer(playerid, inv_split[0]);
    TextDrawHideForPlayer(playerid, inv_split[1]);

    TextDrawHideForPlayer(playerid, inv_remove);

    TextDrawHideForPlayer(playerid, inv_drop[0]);
    TextDrawHideForPlayer(playerid, inv_drop[1]);

    TextDrawHideForPlayer(playerid, invmenu_td[0]);
    TextDrawHideForPlayer(playerid, invmenu_td[1]);
    return 1;
}


Invmenu_LoadTextDraws() {

    invtd[0] = TextDrawCreate(63.900207, 120.000030, "box");
    TextDrawLetterSize(invtd[0], 0.000000, 28.450004);
    TextDrawTextSize(invtd[0], 308.250335, 0.000000);
    TextDrawAlignment(invtd[0], 1);
    TextDrawColor(invtd[0], -1);
    TextDrawUseBox(invtd[0], 1);
    TextDrawBoxColor(invtd[0], 128);
    TextDrawSetShadow(invtd[0], 0);
    TextDrawSetOutline(invtd[0], 0);
    TextDrawBackgroundColor(invtd[0], 255);
    TextDrawFont(invtd[0], 2);
    TextDrawSetProportional(invtd[0], 1);
    TextDrawSetShadow(invtd[0], 0);
 
    invtd[1] = TextDrawCreate(313.099792, 120.000030, "box");
    TextDrawLetterSize(invtd[1], 0.000000, 28.450004);
    TextDrawTextSize(invtd[1], 578.247741, 0.000000);
    TextDrawAlignment(invtd[1], 1);
    TextDrawColor(invtd[1], -1);
    TextDrawUseBox(invtd[1], 1);
    TextDrawBoxColor(invtd[1], 128);
    TextDrawSetShadow(invtd[1], 0);
    TextDrawSetOutline(invtd[1], 0);
    TextDrawBackgroundColor(invtd[1], 255);
    TextDrawFont(invtd[1], 1);
    TextDrawSetProportional(invtd[1], 1);
    TextDrawSetShadow(invtd[1], 0);
 
    invtd[2] = TextDrawCreate(66.100158, 122.233367, "box");
    TextDrawLetterSize(invtd[2], 0.000000, 1.200001);
    TextDrawTextSize(invtd[2], 306.499542, 0.000000);
    TextDrawAlignment(invtd[2], 1);
    TextDrawColor(invtd[2], -1);
    TextDrawUseBox(invtd[2], 1);
    TextDrawBoxColor(invtd[2], 128);
    TextDrawSetShadow(invtd[2], 0);
    TextDrawSetOutline(invtd[2], 0);
    TextDrawBackgroundColor(invtd[2], 255);
    TextDrawFont(invtd[2], 1);
    TextDrawSetProportional(invtd[2], 1);
    TextDrawSetShadow(invtd[2], 0);
 
    invtd[3] = TextDrawCreate(314.599426, 122.233375, "box");
    TextDrawLetterSize(invtd[3], 0.000000, 1.200001);
    TextDrawTextSize(invtd[3], 576.602294, 0.000000);
    TextDrawAlignment(invtd[3], 1);
    TextDrawColor(invtd[3], -1);
    TextDrawUseBox(invtd[3], 1);
    TextDrawBoxColor(invtd[3], 128);
    TextDrawSetShadow(invtd[3], 0);
    TextDrawSetOutline(invtd[3], 0);
    TextDrawBackgroundColor(invtd[3], 255);
    TextDrawFont(invtd[3], 1);
    TextDrawSetProportional(invtd[3], 1);
    TextDrawSetShadow(invtd[3], 0);
 
    invtd[4] = TextDrawCreate(317.000000, 314.434112, "box");
    TextDrawLetterSize(invtd[4], 0.000000, 6.285005);
    TextDrawTextSize(invtd[4], 499.247772, 0.000000);
    TextDrawAlignment(invtd[4], 1);
    TextDrawColor(invtd[4], -1);
    TextDrawUseBox(invtd[4], 1);
    TextDrawBoxColor(invtd[4], 128);
    TextDrawSetShadow(invtd[4], 0);
    TextDrawSetOutline(invtd[4], 0);
    TextDrawBackgroundColor(invtd[4], 255);
    TextDrawFont(invtd[4], 1);
    TextDrawSetProportional(invtd[4], 1);
    TextDrawSetShadow(invtd[4], 0);
 
    inv_user = TextDrawCreate(504.388427, 312.249938, "use");
    TextDrawLetterSize(inv_user, 0.000000, 0.000000);
    TextDrawTextSize(inv_user, 71.019790, 18.579967);
    TextDrawAlignment(inv_user, 1);
    TextDrawColor(inv_user, -1);
    TextDrawSetShadow(inv_user, 0);
    TextDrawSetOutline(inv_user, 0);
    TextDrawBackgroundColor(inv_user, 866792304);
    TextDrawFont(inv_user, 5);
    TextDrawSetProportional(inv_user, 0);
    TextDrawSetShadow(inv_user, 0);
    TextDrawSetPreviewModel(inv_user, 19382);
    TextDrawSetPreviewRot(inv_user, 0.000000, 0.000000, 0.000000, 1.000000);
    TextDrawSetSelectable(inv_user, true);
 
    inv_split[0] = TextDrawCreate(504.593688, 333.316314, "");
    TextDrawLetterSize(inv_split[0], 0.000000, 0.000000);
    TextDrawTextSize(inv_split[0], 71.019790, 18.579967);
    TextDrawAlignment(inv_split[0], 1);
    TextDrawColor(inv_split[0], -1);
    TextDrawSetShadow(inv_split[0], 0);
    TextDrawSetOutline(inv_split[0], 0);
    TextDrawBackgroundColor(inv_split[0], -65472);
    TextDrawFont(inv_split[0], 5);
    TextDrawSetProportional(inv_split[0], 0);
    TextDrawSetShadow(inv_split[0], 0);
    TextDrawSetSelectable(inv_split[0], true);
    TextDrawSetPreviewModel(inv_split[0], 19382);
    TextDrawSetPreviewRot(inv_split[0], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_drop[0] = TextDrawCreate(504.793701, 354.617614, "");
    TextDrawLetterSize(inv_drop[0], 0.000000, 0.000000);
    TextDrawTextSize(inv_drop[0], 71.019790, 18.579967);
    TextDrawAlignment(inv_drop[0], 1);
    TextDrawColor(inv_drop[0], -1);
    TextDrawSetShadow(inv_drop[0], 0);
    TextDrawSetOutline(inv_drop[0], 0);
    TextDrawBackgroundColor(inv_drop[0], 0xAA333370);
    TextDrawFont(inv_drop[0], 5);
    TextDrawSetProportional(inv_drop[0], 0);
    TextDrawSetShadow(inv_drop[0], 0);
    TextDrawSetSelectable(inv_drop[0], true);
    TextDrawSetPreviewModel(inv_drop[0], 19382);
    TextDrawSetPreviewRot(inv_drop[0], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_remove = TextDrawCreate(149.847900, 344.867553, "");
    TextDrawLetterSize(inv_remove, 0.000000, 0.000000);
    TextDrawTextSize(inv_remove, 76.040008, 19.899997);
    TextDrawAlignment(inv_remove, 1);
    TextDrawColor(inv_remove, -1);
    TextDrawSetShadow(inv_remove, 0);
    TextDrawSetOutline(inv_remove, 0);
    TextDrawBackgroundColor(inv_remove, 0xAA333370);
    TextDrawFont(inv_remove, 5);
    TextDrawSetProportional(inv_remove, 0);
    TextDrawSetShadow(inv_remove, 0);
    TextDrawSetSelectable(inv_remove, true);
    TextDrawSetPreviewModel(inv_remove, 19382);
    TextDrawSetPreviewRot(inv_remove, 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_split[1] = TextDrawCreate(540.294372, 334.449981, "drop");
    TextDrawLetterSize(inv_split[1], 0.400000, 1.600000);
    TextDrawAlignment(inv_split[1], 2);
    TextDrawColor(inv_split[1], -1);
    TextDrawSetShadow(inv_split[1], 0);
    TextDrawSetOutline(inv_split[1], 0);
    TextDrawBackgroundColor(inv_split[1], 255);
    TextDrawFont(inv_split[1], 2);
    TextDrawSetProportional(inv_split[1], 1);
    TextDrawSetShadow(inv_split[1], 0);
    TextDrawSetSelectable(inv_split[1], false);
 
    inv_drop[1] = TextDrawCreate(540.762878, 355.451263, "delete");
    TextDrawLetterSize(inv_drop[1], 0.400000, 1.600000);
    TextDrawAlignment(inv_drop[1], 2);
    TextDrawColor(inv_drop[1], -1);
    TextDrawSetShadow(inv_drop[1], 0);
    TextDrawSetOutline(inv_drop[1], 0);
    TextDrawBackgroundColor(inv_drop[1], 255);
    TextDrawFont(inv_drop[1], 2);
    TextDrawSetProportional(inv_drop[1], 1);
    TextDrawSetShadow(inv_drop[1], 0);
    TextDrawSetSelectable(inv_drop[1], false);
 
    invmenu_td[1] = TextDrawCreate(565.100341, 119.433311, "X");
    //TextDrawTextSize(invmenu_td[1], 574.999511, 0.000000);
    //TextDrawTextSize(invmenu_td[1], 1000.0, 100.0);
    TextDrawTextSize(invmenu_td[1], 574.999511, 13.7);
    TextDrawLetterSize(invmenu_td[1], 0.400000, 1.600000);
    TextDrawAlignment(invmenu_td[1], 1);
    TextDrawColor(invmenu_td[1], -1);
    TextDrawSetShadow(invmenu_td[1], 0);
    TextDrawSetOutline(invmenu_td[1], 0);
    TextDrawBackgroundColor(invmenu_td[1], 255);
    TextDrawFont(invmenu_td[1], 2);
    TextDrawSetProportional(invmenu_td[1], 1);
    TextDrawSetShadow(invmenu_td[1], 0);
    TextDrawSetSelectable(invmenu_td[1], true);
   
    invmenu_td[0] = TextDrawCreate(564.079284, 120.583320, "");
    TextDrawLetterSize(invmenu_td[0], 0.000000, 0.000000);
    TextDrawTextSize(invmenu_td[0], 14.000000, 14.000000);
    TextDrawAlignment(invmenu_td[0], 1);
    TextDrawColor(invmenu_td[0], -1);
    TextDrawSetShadow(invmenu_td[0], 0);
    TextDrawSetOutline(invmenu_td[0], 0);
    TextDrawBackgroundColor(invmenu_td[0], 80);
    TextDrawFont(invmenu_td[0], 5);
    TextDrawSetProportional(invmenu_td[0], 0);
    TextDrawSetShadow(invmenu_td[0], 0);
    TextDrawSetSelectable(invmenu_td[0], true);
    TextDrawSetPreviewModel(invmenu_td[0], 19382);
    TextDrawSetPreviewRot(invmenu_td[0], 0.000000, 0.000000, 0.000000, 1.000000);
   
}
 
Invmenu_LoadPlayerTextDraws(playerid) {
    inv_index[playerid][0] = CreatePlayerTextDraw(playerid, 315.500152, 150.692352, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][0], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][0], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][0], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][0], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][0], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][0], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][0], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][0], 0.000000, -30, 0.000000, 2.2);
 
    inv_index[playerid][1] = CreatePlayerTextDraw(playerid, 368.803405, 150.692352, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][1], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][1], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][1], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][1], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][1], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][1], 0.000000, -30, 0.000000, 2.2);
 
    inv_index[playerid][10] = CreatePlayerTextDraw(playerid, 315.500152, 253.698638, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][10], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][10], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][10], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][10], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][10], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][10], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][10], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][10], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][10], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][10], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][5] = CreatePlayerTextDraw(playerid, 315.500152, 201.795471, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][5], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][5], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][5], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][5], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][5], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][5], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][5], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][5], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][2] = CreatePlayerTextDraw(playerid, 422.506683, 150.692352, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][2], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][2], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][2], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][2], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][2], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][2], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][3] = CreatePlayerTextDraw(playerid, 475.509918, 150.692352, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][3], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][3], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][3], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][3], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][3], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][3], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][3], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][4] = CreatePlayerTextDraw(playerid, 528.508117, 150.692352, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][4], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][4], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][4], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][4], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][4], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][4], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][6] = CreatePlayerTextDraw(playerid, 368.903411, 201.795471, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][6], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][6], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][6], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][6], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][6], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][6], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][7] = CreatePlayerTextDraw(playerid, 422.406677, 201.795471, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][7], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][7], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][7], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][7], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][7], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][7], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][7], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][7], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][7], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][7], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][8] = CreatePlayerTextDraw(playerid, 476.009948, 201.795471, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][8], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][8], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][8], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][8], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][8], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][8], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][8], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][8], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][8], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][8], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][9] = CreatePlayerTextDraw(playerid, 528.908020, 201.795471, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][9], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][9], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][9], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][9], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][9], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][9], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][9], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][9], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][9], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][11] = CreatePlayerTextDraw(playerid, 369.203430, 253.698638, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][11], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][11], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][11], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][11], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][11], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][11], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][11], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][11], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][11], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][11], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][12] = CreatePlayerTextDraw(playerid, 422.806701, 253.698638, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][12] , 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][12] , 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][12] , 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][12] , -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][12] , 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][12] , 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][12], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][12], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][12], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][12], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][12], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][12], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][12], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][13] = CreatePlayerTextDraw(playerid, 476.209960, 253.698638, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][13], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][13], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][13], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][13], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][13], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][13], 0);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][13], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][13], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][13], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][13], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_index[playerid][14] = CreatePlayerTextDraw(playerid, 529.507873, 253.698638, "");
    PlayerTextDrawLetterSize(playerid, inv_index[playerid][14], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_index[playerid][14], 46.000000, 45.000000);
    PlayerTextDrawAlignment(playerid, inv_index[playerid][14], 1);
    PlayerTextDrawColor(playerid, inv_index[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, inv_index[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, inv_index[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_index[playerid][14], 96);
    PlayerTextDrawFont(playerid, inv_index[playerid][14], 5);
    PlayerTextDrawSetProportional(playerid, inv_index[playerid][14], 0);
    PlayerTextDrawSetShadow(playerid,inv_index[playerid][14], 0);
    PlayerTextDrawSetSelectable(playerid, inv_index[playerid][14], true);
    PlayerTextDrawSetPreviewModel(playerid, inv_index[playerid][14], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_index[playerid][14], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_skin[playerid] = CreatePlayerTextDraw(playerid, 73.300109, 138.366668, "");
    PlayerTextDrawLetterSize(playerid, inv_skin[playerid], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_skin[playerid], 227.000000, 202.000000);
    PlayerTextDrawAlignment(playerid, inv_skin[playerid], 1);
    PlayerTextDrawColor(playerid, inv_skin[playerid], -1);
    PlayerTextDrawSetShadow(playerid, inv_skin[playerid], 0);
    PlayerTextDrawSetOutline(playerid, inv_skin[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_skin[playerid], 43520);
    PlayerTextDrawFont(playerid, inv_skin[playerid], 5);
    PlayerTextDrawSetProportional(playerid, inv_skin[playerid], 0);
    PlayerTextDrawSetShadow(playerid, inv_skin[playerid], 0);
    PlayerTextDrawSetPreviewModel(playerid, inv_skin[playerid], 0);
    PlayerTextDrawSetPreviewRot(playerid, inv_skin[playerid], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_text[playerid][0] = CreatePlayerTextDraw(playerid, 68.199996, 120.716636, "character");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][0], 0.326999, 1.284999);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][0], 1);
    PlayerTextDrawColor(playerid, inv_text[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][0], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][0], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][0], 0);
 
    inv_text[playerid][1] = CreatePlayerTextDraw(playerid, 315.710540, 120.716636, "inventory");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][1], 0.326999, 1.284999);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][1], 1);
    PlayerTextDrawColor(playerid, inv_text[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][1], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][1], 0);
 
    inv_text[playerid][2] = CreatePlayerTextDraw(playerid, 248.200164, 144.800033, "head");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][2], 0.172995, 0.870832);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][2], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][2], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][2], 0);
 
    inv_text[playerid][3] = CreatePlayerTextDraw(playerid, 247.399932, 189.833389, "backpack");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][3], 0.172995, 0.870832);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][3], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][3], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][3], 0);
 
    inv_text[playerid][4] = CreatePlayerTextDraw(playerid, 128.199707, 180.250152, "body");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][4], 0.172995, 0.870832);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][4], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][4], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][4], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][4], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][4], 0);
 
    inv_text[playerid][5] = CreatePlayerTextDraw(playerid, 127.499824, 232.683532, "Primary");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][5], 0.172995, 0.870832);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][5], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][5], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][5], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][5], 0);
 
    inv_text[playerid][6] = CreatePlayerTextDraw(playerid, 247.099945, 236.100448, "Secondary");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][6], 0.172995, 0.870832);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][6], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][6], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][6], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][6], 0);
 
    inv_text[playerid][7] = CreatePlayerTextDraw(playerid, 246.600036, 285.667083, "Melee");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][7], 0.172995, 0.870832);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][7], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][7], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][7], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][7], 0);
 
    inv_text[playerid][8] = CreatePlayerTextDraw(playerid, 127.800155, 284.950317, "Pistol");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][8], 0.172995, 0.870832);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][8], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][8], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][8], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][8], 0);
 
    inv_description[playerid][0] = CreatePlayerTextDraw(playerid, 317.699981, 314.833312, "");
    PlayerTextDrawLetterSize(playerid, inv_description[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_description[playerid][0], 65.000000, 56.000000);
    PlayerTextDrawAlignment(playerid, inv_description[playerid][0], 1);
    PlayerTextDrawColor(playerid, inv_description[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, inv_description[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, inv_description[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_description[playerid][0], -208);
    PlayerTextDrawFont(playerid, inv_description[playerid][0], 5);
    PlayerTextDrawSetProportional(playerid, inv_description[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, inv_description[playerid][0], 0);
    PlayerTextDrawSetPreviewModel(playerid, inv_description[playerid][0], 19382);
    PlayerTextDrawSetPreviewRot(playerid, inv_description[playerid][0], 0.000000, 0.000000, 0.000000, 1.000000);
    PlayerTextDrawSetSelectable(playerid, inv_description[playerid][0], false);
 
    inv_description[playerid][1] = CreatePlayerTextDraw(playerid, 388.099884, 314.099884, "");
    PlayerTextDrawLetterSize(playerid, inv_description[playerid][1], 0.290499, 1.226665);
    PlayerTextDrawAlignment(playerid, inv_description[playerid][1], 1);
    PlayerTextDrawColor(playerid, inv_description[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, inv_description[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, inv_description[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_description[playerid][1], 255);
    PlayerTextDrawFont(playerid, inv_description[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, inv_description[playerid][1], 1);
    PlayerTextDrawSetShadow(playerid, inv_description[playerid][1], 0);
 
    inv_description[playerid][2] = CreatePlayerTextDraw(playerid, 388.699920, 330.400878, "");
    PlayerTextDrawLetterSize(playerid, inv_description[playerid][2], 0.157499, 0.882498);
    PlayerTextDrawAlignment(playerid, inv_description[playerid][2], 1);
    PlayerTextDrawColor(playerid, inv_description[playerid][2], -168430192);
    PlayerTextDrawSetShadow(playerid, inv_description[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, inv_description[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_description[playerid][2], 255);
    PlayerTextDrawFont(playerid, inv_description[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, inv_description[playerid][2], 1);
    PlayerTextDrawSetShadow(playerid, inv_description[playerid][2], 0);
 
    inv_description[playerid][3] = CreatePlayerTextDraw(playerid, 499.401489, 363.984985, "");
    PlayerTextDrawLetterSize(playerid, inv_description[playerid][3], 0.157499, 0.882498);
    PlayerTextDrawAlignment(playerid, inv_description[playerid][3], 3);
    PlayerTextDrawColor(playerid, inv_description[playerid][3], -168430208);
    PlayerTextDrawSetShadow(playerid, inv_description[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, inv_description[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_description[playerid][3], 255);
    PlayerTextDrawFont(playerid, inv_description[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, inv_description[playerid][3], 1);
    PlayerTextDrawSetShadow(playerid, inv_description[playerid][3], 0);
 
    inv_text[playerid][9] = CreatePlayerTextDraw(playerid, 540.294372, 313.548706, "use");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][9], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][9], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][9], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][9], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][9], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][9], 0);
    PlayerTextDrawSetSelectable(playerid, inv_text[playerid][9], false);
 
    inv_personindex[playerid][0] = CreatePlayerTextDraw(playerid, 231.000305, 153.250015, "");//very top head
    PlayerTextDrawLetterSize(playerid, inv_personindex[playerid][0], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_personindex[playerid][0], 33.000000, 32.000000);
    PlayerTextDrawAlignment(playerid, inv_personindex[playerid][0], 1);
    PlayerTextDrawColor(playerid, inv_personindex[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, inv_personindex[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_personindex[playerid][0], 112);
    PlayerTextDrawFont(playerid, inv_personindex[playerid][0], 5);
    PlayerTextDrawSetProportional(playerid, inv_personindex[playerid][0], 0);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][0], 0);
    //PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][0], 18641);//flashlight
    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][0], 19382);//empty   
    PlayerTextDrawSetPreviewRot(playerid, inv_personindex[playerid][0], 0.000000, 0.000000, 0.000000, 1.000000);
    PlayerTextDrawSetSelectable(playerid, inv_personindex[playerid][0], true);
 
    inv_personindex[playerid][1] = CreatePlayerTextDraw(playerid, 110.600074, 189.283264, "");//top left
    PlayerTextDrawLetterSize(playerid, inv_personindex[playerid][1], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_personindex[playerid][1], 33.000000, 32.000000);
    PlayerTextDrawAlignment(playerid, inv_personindex[playerid][1], 1);
    PlayerTextDrawColor(playerid, inv_personindex[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, inv_personindex[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_personindex[playerid][1], 112);
    PlayerTextDrawFont(playerid, inv_personindex[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, inv_personindex[playerid][1], 0);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][1], 0);
    PlayerTextDrawSetSelectable(playerid, inv_personindex[playerid][1], true);
    //PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][1], 18640);//helmet
    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][1], 19382);//empty   
    PlayerTextDrawSetPreviewRot(playerid, inv_personindex[playerid][1], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_personindex[playerid][2] = CreatePlayerTextDraw(playerid, 230.500000, 198.749984, "");//top right backpack
    PlayerTextDrawLetterSize(playerid, inv_personindex[playerid][2], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_personindex[playerid][2], 33.000000, 36.000000);
    PlayerTextDrawAlignment(playerid, inv_personindex[playerid][2], 1);
    PlayerTextDrawColor(playerid, inv_personindex[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, inv_personindex[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_personindex[playerid][2], 112);
    PlayerTextDrawFont(playerid, inv_personindex[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, inv_personindex[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, inv_personindex[playerid][2], true);
    //PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][2], 18634);//crowbar
    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][2], 19382);//empty    
    PlayerTextDrawSetPreviewRot(playerid, inv_personindex[playerid][2], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_personindex[playerid][3] = CreatePlayerTextDraw(playerid, 110.400032, 242.366851, "");//center left
    PlayerTextDrawLetterSize(playerid, inv_personindex[playerid][3], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_personindex[playerid][3], 33.000000, 36.000000);
    PlayerTextDrawAlignment(playerid, inv_personindex[playerid][3], 1);
    PlayerTextDrawColor(playerid, inv_personindex[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, inv_personindex[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_personindex[playerid][3], 112);
    PlayerTextDrawFont(playerid, inv_personindex[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, inv_personindex[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, inv_personindex[playerid][3], true);
    //PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 18635);//hammer
    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][3], 19382);//empty   
    PlayerTextDrawSetPreviewRot(playerid, inv_personindex[playerid][3], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_personindex[playerid][4] = CreatePlayerTextDraw(playerid, 230.405273, 244.750305, "");//center right
    PlayerTextDrawLetterSize(playerid, inv_personindex[playerid][4], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_personindex[playerid][4], 33.000000, 36.000000);
    PlayerTextDrawAlignment(playerid, inv_personindex[playerid][4], 1);
    PlayerTextDrawColor(playerid, inv_personindex[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, inv_personindex[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_personindex[playerid][4], 112);
    PlayerTextDrawFont(playerid, inv_personindex[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, inv_personindex[playerid][4], 0);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][4], 0);
    PlayerTextDrawSetSelectable(playerid, inv_personindex[playerid][4], true);
    //PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], 11684);//couch
    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][4], 19382);//empty   
    PlayerTextDrawSetPreviewRot(playerid, inv_personindex[playerid][4], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_personindex[playerid][5] = CreatePlayerTextDraw(playerid, 230.505279, 294.150360, "");//right bottom
    PlayerTextDrawLetterSize(playerid, inv_personindex[playerid][5], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_personindex[playerid][5], 33.000000, 36.000000);
    PlayerTextDrawAlignment(playerid, inv_personindex[playerid][5], 1);
    PlayerTextDrawColor(playerid, inv_personindex[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, inv_personindex[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_personindex[playerid][5], 112);
    PlayerTextDrawFont(playerid, inv_personindex[playerid][5], 5);
    PlayerTextDrawSetProportional(playerid, inv_personindex[playerid][5], 0);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][5], 0);
    PlayerTextDrawSetSelectable(playerid, inv_personindex[playerid][5], true);
    //PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 11704);//devil mask
    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][5], 19382);//empty   
    PlayerTextDrawSetPreviewRot(playerid, inv_personindex[playerid][5], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_personindex[playerid][6] = CreatePlayerTextDraw(playerid, 110.400032, 294.070007, "");//left bottom
    PlayerTextDrawLetterSize(playerid, inv_personindex[playerid][6], 0.000000, 0.000000);
    PlayerTextDrawTextSize(playerid, inv_personindex[playerid][6], 33.000000, 36.000000);
    PlayerTextDrawAlignment(playerid, inv_personindex[playerid][6], 1);
    PlayerTextDrawColor(playerid, inv_personindex[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, inv_personindex[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_personindex[playerid][6], 112);
    PlayerTextDrawFont(playerid, inv_personindex[playerid][6], 5);
    PlayerTextDrawSetProportional(playerid, inv_personindex[playerid][6], 0);
    PlayerTextDrawSetShadow(playerid, inv_personindex[playerid][6], 0);
    PlayerTextDrawSetSelectable(playerid, inv_personindex[playerid][6], true);
    //PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][6], 19382);//fire exit - pistol slot td
    PlayerTextDrawSetPreviewModel(playerid, inv_personindex[playerid][6], 19382);//empty   
    PlayerTextDrawSetPreviewRot(playerid, inv_personindex[playerid][6], 0.000000, 0.000000, 0.000000, 1.000000);
 
    inv_text[playerid][10] = CreatePlayerTextDraw(playerid, 187.721237, 347.616729, "remove");
    PlayerTextDrawLetterSize(playerid, inv_text[playerid][10], 0.325504, 1.407498);
    PlayerTextDrawAlignment(playerid, inv_text[playerid][10], 2);
    PlayerTextDrawColor(playerid, inv_text[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, inv_text[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, inv_text[playerid][10], 255);
    PlayerTextDrawFont(playerid, inv_text[playerid][10], 2);
    PlayerTextDrawSetProportional(playerid, inv_text[playerid][10], 1);
    PlayerTextDrawSetShadow(playerid, inv_text[playerid][10], 0);
   
    inv_message[playerid] = CreatePlayerTextDraw(playerid, 321.224029, 381.983398, "");//error_msg
    PlayerTextDrawLetterSize(playerid, inv_message[playerid], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, inv_message[playerid], 2);
    PlayerTextDrawColor(playerid, inv_message[playerid], -2147483393);
    PlayerTextDrawSetShadow(playerid, inv_message[playerid], 0);
    PlayerTextDrawSetOutline(playerid, inv_message[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, inv_message[playerid], 255);
    PlayerTextDrawFont(playerid, inv_message[playerid], 2);
    PlayerTextDrawSetProportional(playerid, inv_message[playerid], 1);
    PlayerTextDrawSetShadow(playerid, inv_message[playerid], 0);
   
}
 
hook OnPlayerDisconnect(playerid, reason) {

    if(Bit_Get(loggedin, playerid) && Bit_Get(character, playerid) && !IsPlayerNPC(playerid)) {

        Bit_Vet(openinventory, playerid);

        Bit_Vet(slot_head, playerid);
        Bit_Vet(slot_body, playerid);
        Bit_Vet(slot_backpack, playerid);
        Bit_Vet(slot_primary, playerid);
        Bit_Vet(slot_secondary, playerid);
        Bit_Vet(slot_pistol, playerid);
        Bit_Vet(slot_melee, playerid);

        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `used` = 0 WHERE playerId = %d AND state = 1",  CharacterSQL[playerid]);//Devnote: should develop saving equipped items and loading them upon connecting
        mysql_tquery(g_SQL, sql, "", "");

        SaveAmmo(playerid);

    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ) {
    if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
    if(weaponid > 0) {
        if(weaponid == p_weapon[playerid][0]) {
            --p_ammos[playerid][0];
            ++p_shots[playerid][0];
            if(!random(10))
                AmmoCheck(playerid, 0);
        }
        else if(weaponid == p_weapon[playerid][1]) {
            --p_ammos[playerid][1];
            ++p_shots[playerid][1];
            if(!random(7))
                AmmoCheck(playerid, 1);
        }
        else if(weaponid == p_weapon[playerid][2]) {
            --p_ammos[playerid][2];
            ++p_shots[playerid][2];
            if(!random(5))
                AmmoCheck(playerid, 2);
        }
    }
    //SFM(playerid, HEX_FADE2, "Debug: Shot weapon id %d, p_shots0 %d, p_shots1 %d, p_shots2 %d", weaponid, p_shots[playerid][0], p_shots[playerid][1], p_shots[playerid][2]);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

AmmoCheck(playerid, wslot) {
    if(GetPlayerWeapon(playerid) == p_weapon[playerid][wslot]) {
        new checksum = GetPlayerAmmo(playerid);
        if(p_ammos[playerid][wslot] == checksum) return 1;

        if(p_ammos[playerid][wslot] > checksum) {

            if(p_ammos[playerid][wslot] - checksum > 3) {
                new sendText[256];
                format(sendText, sizeof sendText, "AdmWarn: %s[%d] has %d ammo with weapon %s, while the ammo should be about %d, fixing!", PlayerName(playerid), playerid, checksum, DeathReason(p_weapon[playerid][wslot]), p_ammos[playerid][wslot]);
                SendAdminMessage(HEX_LRED, sendText, true);
            }

            p_shots[playerid][wslot] += p_ammos[playerid][wslot] - checksum;
            p_ammos[playerid][wslot] = checksum;

            printf("Warning: %s[%d] has %d ammo with weapon %s, while the ammo should be about %d, fixing!", PlayerName(playerid), playerid, checksum, DeathReason(p_weapon[playerid][wslot]), p_ammos[playerid][wslot]);
        }
    }
    return 1;
}

stock SaveAmmo(playerid, type = -1) {

    if(type == -1) {

        if(GetPVarInt(playerid, "ammo0") > 0) {
            /*mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount` + %d WHERE playerId = %d AND itemId = %d AND state = 1 LIMIT 1", p_ammos[playerid][0], CharacterSQL[playerid], GetPVarInt(playerid, "ammo0"));
            mysql_query(g_SQL, sql);
            p_shots[playerid][0] = 0;*/
            GivePlayerItem(playerid, GetPVarInt(playerid, "ammo0"), p_ammos[playerid][0]);
            p_shots[playerid][0] = 0;
        }

        if(GetPVarInt(playerid, "ammo1") > 0) {
            /*mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount` + %d WHERE playerId = %d AND itemId = %d AND state = 1 LIMIT 1", p_ammos[playerid][1], CharacterSQL[playerid], GetPVarInt(playerid, "ammo1"));
            mysql_query(g_SQL, sql);
            p_shots[playerid][1] = 0;*/
            GivePlayerItem(playerid, GetPVarInt(playerid, "ammo1"), p_ammos[playerid][1]);
            p_shots[playerid][1] = 0;   
        }

        if(GetPVarInt(playerid, "ammo2") > 0) {
            /*mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount` + %d WHERE playerId = %d AND itemId = %d AND state = 1 LIMIT 1", p_ammos[playerid][2], CharacterSQL[playerid], GetPVarInt(playerid, "ammo2"));
            mysql_query(g_SQL, sql);
            p_shots[playerid][2] = 0;*/
            GivePlayerItem(playerid, GetPVarInt(playerid, "ammo2"), p_ammos[playerid][2]);
            p_shots[playerid][2] = 0;
        }

    }
    else {
        if(GetPVarInt(playerid, "ammo0") > 0 && type == TYPE_PRIMARY) {
            //mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount` + %d WHERE playerId = %d AND itemId = %d AND state = 1 LIMIT 1", p_ammos[playerid][0], CharacterSQL[playerid], GetPVarInt(playerid, "ammo0"));
            //mysql_query(g_SQL, sql);
            GivePlayerItem(playerid, GetPVarInt(playerid, "ammo0"), p_ammos[playerid][0]);
            p_shots[playerid][0] = 0;
            
        }

        else if(GetPVarInt(playerid, "ammo1") > 0 && type == TYPE_SECONDARY) {
            //mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount` + %d WHERE playerId = %d AND itemId = %d AND state = 1 LIMIT 1", p_ammos[playerid][1], CharacterSQL[playerid], GetPVarInt(playerid, "ammo1"));
            //mysql_query(g_SQL, sql);
            GivePlayerItem(playerid, GetPVarInt(playerid, "ammo1"), p_ammos[playerid][1]);
            p_shots[playerid][1] = 0;
            
        }

        else if(GetPVarInt(playerid, "ammo2") > 0 && type == TYPE_PISTOL) {
            //mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player_items` SET `amount` = `amount` + %d WHERE playerId = %d AND itemId = %d AND state = 1 LIMIT 1", p_ammos[playerid][2], CharacterSQL[playerid], GetPVarInt(playerid, "ammo2"));
            //mysql_query(g_SQL, sql);
            GivePlayerItem(playerid, GetPVarInt(playerid, "ammo2"), p_ammos[playerid][2]);
            p_shots[playerid][2] = 0;
            
        }

    }
    //printf("[debug] ammo save query: %s", sql);

    return 1;
}
