#include <YSI_Coding\y_hooks>

forward OnPasswordHashed(playerid);//bcrypt
forward OnPasswordChecked(playerid);//bcrypt

hook OnPasswordHashed(playerid) {
    if(GetPVarInt(playerid, "registering") == 1) 
    {
        DeletePVar(playerid, "registering");
        new hash[BCRYPT_HASH_LENGTH];
        bcrypt_get_hash(hash);
        format(accountname[playerid], MAX_PLAYER_NAME, "%s", PlayerName(playerid));
        mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `account` (`name`, `password`) VALUES ('%e', '%e')", PlayerName(playerid), hash);
        mysql_tquery(g_SQL, sql, "", "");

        mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `account` WHERE name = '%e' LIMIT 1", PlayerName(playerid));
        inline loadNewAccountID() 
        {
            if(!cache_num_rows()) 
            {
                printf("Error on loadNewAccountID(), no match on name %s, unable to load AccountSQL!", PlayerName(playerid));
                Kick(playerid);
                @return 1;
            }
            cache_get_value_int(0, "id", AccountSQL[playerid]);
            @return 1;
        }
        MySQL_TQueryInline(g_SQL, using inline loadNewAccountID, sql);


        new sendText[256];
        format(sendText, sizeof sendText, "[Desolation]: %s[%d] has registered.", PlayerName(playerid), playerid);
	    SendAdminMessage(HEX_LRED, sendText, true);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    printf("OnPasswordHashed called for unknown reason by (ID:%d) %s.", playerid, PlayerName(playerid));
    return Y_HOOKS_CONTINUE_RETURN_1;
}

StartCharacterCreation(playerid) {
    inline Dialog_character_name(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) 
    {
        #pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
        if(Open_response) {
            SetPVarString(Open_pid, "charactername", Open_inputtext);
            if(IsRPName(Open_inputtext)) 
            {
                CharacterCreation_skin(Open_pid);
            }
            else {
                NonEnglishZombie(Open_pid);
            }
        }
        else 
            CharacterSelection(playerid);
    }	
    Dialog_ShowCallback(playerid, using inline Dialog_character_name, DIALOG_STYLE_INPUT, "Create a new character", "Enter your new name using the Firstname_Lastname format:","Next","Back");
    return 1;
}

CharacterCreation_skin(playerid) {
    new newname[MAX_PLAYER_NAME];
    GetPVarString(playerid, "charactername", newname, MAX_PLAYER_NAME);
    new namecheck = SetPlayerName(playerid, newname);
    if(namecheck == -1) return Kick(playerid);
    if(IsNameTaken(newname)) {
        SCM(playerid, HEX_RED, "Error: This name is already taken! Please choose another one.");
        StartCharacterCreation(playerid);
        return 1;
    }
    mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `player` (`name`, `accountid`) VALUES ('%e', '%d')", PlayerName(playerid), AccountSQL[playerid]);
    //printf("DEBUG: --- %d", AccountSQL[playerid]);
    mysql_query(g_SQL, sql);

    AddPlayerCharacterSQL(playerid);

    PerkSelection(playerid);
    return 1;
}

First_Spawn(playerid)
{
    LoadCharacterData(playerid);
    SetPlayerScore(playerid, 1);
    level[playerid] = 1;
    race[playerid] = 0;
    Bit_Vet(pzombie, playerid);
    Bit_Let(tutorial, playerid);
    Bit_Let(togshud, playerid);
    ResetHuds(playerid);
    SetPlayerColor(playerid, COLOR_PLAYER);
    new sendText[256];
    format(sendText, sizeof sendText, "~W~Welcome~n~~g~%s", PlayerName(playerid, false));
    GameTextForPlayer(playerid, sendText, 5000, 1);
    
    p_skin[playerid] = HumansSkins[random(sizeof(HumansSkins))];
    if(p_skin[playerid] <= 0) p_skin[playerid] = 177;
    SetPlayerSkin(playerid, p_skin[playerid]);
    RandomHumanSpawn(playerid);

    thirst[playerid] = 70.0;
    hunger[playerid] = 70.0;

    Bit_Let(newbiechat, playerid);

    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    Bit_Let(loggedin, playerid);
    Bit_Let(character, playerid);

    TogglePlayerSpectating(playerid, false);
    CreateBars(playerid);

    if(Bit_Get(tutorial, playerid))
        SCM(playerid, HEX_FADE2, "Hint messages are enabled. Type /toghints to turn them off.");

    SCM(playerid, HEX_FADE2, "");
    SCM(playerid, HEX_FADE2, "");
    SFM(playerid, HEX_FADE2, "Hello %s! We are excited to welcome you in our community!", accountname[playerid]);
    SCM(playerid, HEX_FADE2, "If you are new to this server, you should read about various activites in the /help menu.");
    SCM(playerid, HEX_FADE2, "For now, just note that your character is facing a zombie apocalypse.");
    SCM(playerid, HEX_FADE2, "You can loot buildings, dead zombies, and you can rob players.");
    SCM(playerid, HEX_FADE2, "Good luck and have fun!");
    SCM(playerid, HEX_FADE2, "");
    SCM(playerid, HEX_FADE2, "Hint: Type /skin to change your character model.");
    SCM(playerid, HEX_FADE2, "Hint: Press H to open your inventory. We gave you some basic items!");
    SCM(playerid, HEX_FADE2, "Hint: Go inside places, crouch over items and press N to loot them.");
    SCM(playerid, HEX_FADE2, "Hint: Use /help to get a full list of commands");

    GivePlayerItem(playerid, 19, 1);
    GivePlayerItem(playerid, 39, 36);
    GivePlayerItem(playerid, 48, 1);
    GivePlayerItem(playerid, 54, 1);
    cash[playerid] +=1000;
    
    format(sendText, sizeof sendText, "DSRP: %s[%d] is a new character.", PlayerName(playerid), playerid);
    SendAdminMessage(HEX_LRED, sendText, true);
    StopAudioStreamForPlayer(playerid);
    LogConnection(playerid);
    return 1;
}

showRegisterDialog(playerid) {
    inline Dialog_bcrypt_register(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
        #pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
        if(Open_response) 
        {
            bcrypt_hash(Open_inputtext, BCRYPT_COST, "OnPasswordHashed", "d", playerid);
            CharacterSelection(Open_pid);
        }
        else 
            Kick(Open_pid);
    }	
    Dialog_ShowCallback(playerid, using inline Dialog_bcrypt_register, DIALOG_STYLE_INPUT, "Create a new account", "Enter your new password below.\nDo not use a password that you use anywhere else!","Register","Quit");
    return 1;
}

NonEnglishZombie(playerid) {
    SCM(playerid, HEX_FADE2, "Hint: Please read the instructions carefully! Go back if you intend to roleplay. If you continue you can only play as a zombie.");
    inline Dialog_character_nonenglish(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
        #pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
        if(Open_response) 
        {
            makePermanentZombie(Open_pid);
        }
        else 
            StartCharacterCreation(Open_pid);
    }	
    Dialog_ShowCallback(playerid, using inline Dialog_character_nonenglish, DIALOG_STYLE_MSGBOX, "Create a new character", "Incorrect roleplay name! Please use the Firstname_Lastname format.\n\nNote that - mainly for foreign players - it is possible to play with an invalid name.\nYou can only continue with this name as a permanent zombie!\nIf you intend to roleplay a human character click 'back'.","Continue","Back");
    return 1; 
}

makePermanentZombie(playerid) {
    new newname[MAX_PLAYER_NAME];
    GetPVarString(playerid, "charactername", newname, MAX_PLAYER_NAME);
    new namecheck = SetPlayerName(playerid, newname);
    if(namecheck == -1) return Kick(playerid);
    if(IsNameTaken(newname)) {
        SCM(playerid, HEX_RED, "Error: This name is already taken! Please choose another one.");
        StartCharacterCreation(playerid);
        return 1;
    }

    mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `player` (`name`, `accountid`) VALUES ('%e', '%d')", PlayerName(playerid), AccountSQL[playerid]);
    mysql_query(g_SQL, sql);

    AddPlayerCharacterSQL(playerid);

    Bit_Let(pzombie, playerid);
    Group_SetPlayer(g_Zombie, playerid, true);
    SetPlayerColor(playerid, COLOR_ZOMBIE);
    GameTextForPlayer(playerid, "~r~You turned into a zombie!", 1700, 0);
    SetSpawnInfo(playerid, ZOMBIE_TEAM, RandomZombieSkin(), 1433.9108, 190.9240, 21.7224, 90.0, 0, 0, 0, 0, 0, 0);//at Montgomery
    SCM(playerid, HEX_FADE2, "You are a zombie now! Attack other players to infect them.");
    if(Bit_Get(tutorial, playerid))	
    {		
        SCM(playerid, HEX_FADE2, "Hint: Use /mutation to change your zombie class. You are a runner now! Press 'Y' to sprint.");
    }
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid, 0);
    Bit_Let(loggedin, playerid);
    Bit_Let(character, playerid);
    TogglePlayerSpectating(playerid, false);

    new sendText[256];
    format(sendText, sizeof sendText, "DSRP: %s[%d] is a new permanent zombie character.", PlayerName(playerid), playerid);
    SendAdminMessage(HEX_LRED, sendText, true);
    return 1;
}

timer SpawnCamera[START_CAMERA_IDLE](playerid) {
    InterpolateCameraPos(playerid, 682.3288, -704.5004, 36.5238, 682.3288, -704.5004, 36.5238, 60000, CAMERA_MOVE);  	    
    InterpolateCameraLookAt(playerid, 681.7302, -586.7748, 29.1387, 681.7302, -586.7748, 29.1387, 60000, CAMERA_MOVE);
}

AddPlayerCharacterSQL(playerid) {
    mysql_format(g_SQL, sql, sizeof sql, "SELECT id FROM `player` WHERE name = '%e' LIMIT 1", PlayerName(playerid));
	new Cache:result = mysql_query(g_SQL, sql);
	if(cache_num_rows()) {
		cache_get_value_int(0, "id", CharacterSQL[playerid]);
	}
	else {
        new sendText[256];
        format(sendText, sizeof sendText, "Error: BIG F because %s could not get a CharacterSQL[playerid] while registering a character.", PlayerName(playerid));
        SendAdminMessage(HEX_LRED, sendText, true);
        printf(sendText);
    }
    cache_delete(result);

    return 1;
}

YCMD:email(playerid, params[], help) {

	if(!SpamPrevent(playerid)) return 1;
	new string[128];
	if(sscanf(params, "s[128]", string)) return SCM(playerid, HEX_FADE2, "Usage: /email [address]");

	if(strlen(string) < 9 || strlen(string) > 128) return SCM(playerid, HEX_RED, "Your email address must be at least 9 characters long. (Maximum 128 characters.)");
    if(!IsEmail(string)) return SCM(playerid, HEX_LRED, "Incorrect email format.");

    new oldemail[128];
    format(oldemail, sizeof oldemail, "%s", GetSQLEmail(playerid));
    mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `account_log` (`accountid`, `email`, `email_new`) VALUES ('%d', '%s', '%s')", AccountSQL[playerid], oldemail, string);
	mysql_tquery(g_SQL, sql, "", "");

    mysql_format(g_SQL, sql, sizeof sql, "UPDATE `account` SET `email` = '%e' WHERE id = %d", string, AccountSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");

    SFM(playerid, HEX_YELLOW, "You set your account's email address to '%s'.", string);

	new sendText[256];
	format(sendText, sizeof sendText, "AdmWarn: %s[%d] has set their account's email address to '%s'.", PlayerName(playerid), playerid, string);
	SendAdminMessage(HEX_LRED, sendText, true);

	return 1;
}

GetSQLEmail(playerid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT email FROM `account`  WHERE id = '%d' LIMIT 1", AccountSQL[playerid]);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnval[128];
	if(cache_num_rows()) {
		cache_get_value(0, "email", returnval, sizeof(returnval));
	}
	else
		returnval = "empty";
	cache_delete(result);
	return returnval;
}

stock IsEmail(const CharName[], max_underscores = 1) {
    new underscores = 0;
	new dots = 0;

    for(new i = 1; i < strlen(CharName); ++i) {
        if(CharName[i] == '@') {
            ++underscores;
            if(underscores > max_underscores || i == strlen(CharName)) return false;
        }
        if(CharName[i] == '.') {
            ++dots;
        }
        if(CharName[i] == ' ') {
            return false;
        }
    }
    if (underscores == 0) return false;
    if (dots == 0) return false;
    return true;
}