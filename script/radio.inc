/*#if defined _inc_useitem
	#undef _inc_useitem
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

new playerRadio[MAX_PLAYERS][9];
new defaultChannel[MAX_PLAYERS];
new BitArray:toggleradio<MAX_PLAYERS>;

ReloadPlayerRadio(playerid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `radio` WHERE playerid = '%d' LIMIT 1", CharacterSQL[playerid]);
	inline LoadRadioChannels() {
		if(!cache_num_rows()) {
			UnloadPlayerRadio(playerid);
			if(Bit_Get(character, playerid))
				CreateRadioRow(playerid);
			@return 0;
		}

		new tmp;
		cache_get_value_int(0, "togradio", tmp);
		if(tmp) {
			Bit_Let(toggleradio, playerid);
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: Your radio has been loaded. (ON)");
		}
		else {
			Bit_Vet(toggleradio, playerid);
			if(DEBUGMSG && adminlevel[playerid] != 0) SCM(playerid, HEX_FADE2, "Debug: Your radio has been loaded. (OFF)");
		}

		cache_get_value_int(0, "defaultchan", defaultChannel[playerid]);
		cache_get_value_int(0, "channel1", playerRadio[playerid][1]);
		cache_get_value_int(0, "channel2", playerRadio[playerid][2]);
		cache_get_value_int(0, "channel3", playerRadio[playerid][3]);
		cache_get_value_int(0, "channel4", playerRadio[playerid][4]);
		cache_get_value_int(0, "channel5", playerRadio[playerid][5]);
		cache_get_value_int(0, "channel6", playerRadio[playerid][6]);
		cache_get_value_int(0, "channel7", playerRadio[playerid][7]);
		cache_get_value_int(0, "channel8", playerRadio[playerid][8]);

		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadRadioChannels, sql);
	return 1;
}

hook OnPlayerSpawn(playerid) {
	if(Bit_Get(loggedin, playerid) && Bit_Get(character, playerid))
		ReloadPlayerRadio(playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

UnloadPlayerRadio(playerid) {
	new i = -1;
	for(;++i<9;) playerRadio[playerid][i] = 0;
	Bit_Vet(toggleradio, playerid);
	defaultChannel[playerid] = 1;
	return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
	UnloadPlayerRadio(playerid);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:setchannel(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new newchan;
	if(sscanf(params, "d", newchan)) return SCM(playerid, HEX_FADE2, "Usage: /setchannel [channel 1-8]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(newchan < 1 || newchan > 8) return SCM(playerid, HEX_RED, "[Desolation]: The default channel slot must be between 1 and 8.");

	defaultChannel[playerid] = newchan;

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `radio` SET defaultchan = %d WHERE id = %d LIMIT 1", newchan, CharacterSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");

	SFM(playerid, HEX_YELLOW, "Your default radio slot has been set to %d, which is on frequency %d.0.", newchan, playerRadio[playerid][newchan]);
	if(Bit_Get(tutorial, playerid)) {
		SCM(playerid, HEX_FADE2, "Hint: You will use this channel with /r, but you can access other channels with /r(slot) like /r3.");
		SCM(playerid, HEX_FADE2, "Hint: Use /setfreq to set your radio frequency.");
	}
	
	return 1;
}

YCMD:setfreq(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new newchan, newfreq;
	if(sscanf(params, "dd", newchan, newfreq)) return SCM(playerid, HEX_FADE2, "Usage: /setfreq [channel 1-8] [frequency 1-10000]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(newchan < 1 || newchan > 8) return SCM(playerid, HEX_RED, "[Desolation]: The channel number you edit must be between 1 and 8.");
	if(newfreq < 1 || newfreq > 10000) return SCM(playerid, HEX_RED, "[Desolation]: The frequency you choose must be between 1 and 10000.");

	playerRadio[playerid][newchan] = newfreq;

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `radio` SET channel%d = %d WHERE playerid = %d LIMIT 1", newchan, newfreq, CharacterSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");

	SFM(playerid, HEX_YELLOW, "You changed your radio slot %d to frequency %d.0.", newchan, newfreq);

	return 1;
}

YCMD:togradio(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(Bit_Get(toggleradio, playerid)) {
		Bit_Vet(toggleradio, playerid);
		PlayerAction(playerid, "turns off the radio.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `radio` SET togradio = 0 WHERE id = %d LIMIT 1", CharacterSQL[playerid]);
	}
	else {
		Bit_Let(toggleradio, playerid);
		PlayerAction(playerid, "turns on the radio.");
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `radio` SET togradio = 1 WHERE id = %d LIMIT 1", CharacterSQL[playerid]);
	}
	mysql_tquery(g_SQL, sql, "", "");

	return 1;
}

YCMD:r(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You're dead.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][defaultChannel[playerid]] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on your default slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][defaultChannel[playerid]], message);
	//AdminLog(message);

	return 1;
}

SendRadioMessage(playerid, frequency, rmessage[]) {

	new string[256];
	new bool:getmsg[MAX_PLAYERS];

	foreach(new i:Player) 
	{
		if(Bit_Get(toggleradio, i) && HasPlayerItem(playerid, 54, 1)) 
		{
			new j = 0;
			for(;++j<9;) 
			{
				if(playerRadio[i][j] == frequency) 
				{
					getmsg[i] = true;
					format(string, sizeof string, "** [CH %d at %d.0] %s: %s", j, frequency, RemoveNameSpace(PlayerName(playerid, true)), rmessage);
					if(defaultChannel[i] == j) 
					{
						SCM(i, HEX_LYELLOW, string);
					}
					else
						SCM(i, HEX_DYELLOW, string);
				}
			}
		}
	}

	new Float:currpos[3];
	GetPlayerPos(playerid, currpos[0], currpos[1], currpos[2]);

	foreach(new k:Player) {
		if(getmsg[k] == false) {
			if(GetPlayerVirtualWorld(k) == GetPlayerVirtualWorld(playerid)) {
				if(IsPlayerInRangeOfPoint(k, NAMETAG_DISTANCE, currpos[0], currpos[1], currpos[2])) {
					SFM(k, HEX_FADE2, "%s says [radio]: %s", PlayerName(playerid, false), rmessage);
				}
			}
		}
	}

	return 1;
}

CreateRadioRow(playerid) {

	mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `radio` (`playerid`) VALUES ('%d')", CharacterSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");

	UnloadPlayerRadio(playerid);

	return 1;
}

YCMD:r1(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r1 [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][1] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on this slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][1], message);

	return 1;
}

YCMD:r2(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r2 [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][2] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on this slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][2], message);

	return 1;
}

YCMD:r3(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r3 [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][3] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on this slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][3], message);

	return 1;
}

YCMD:r4(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r4 [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][4] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on this slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][4], message);

	return 1;
}

YCMD:r5(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r5 [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][5] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on this slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][5], message);

	return 1;
}

YCMD:r6(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r6 [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][6] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on this slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][6], message);

	return 1;
}

YCMD:r7(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r7 [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][7] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on this slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][7], message);

	return 1;
}

YCMD:r8(playerid, params[], help) {
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	new message[256];
	if(sscanf(params, "s[256]", message)) return SCM(playerid, HEX_FADE2, "Usage: /r8 [message]");
	if(!Bit_Get(toggleradio, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You must turn on your radio. /togradio");
	if(!HasPlayerItem(playerid, 54, 1)) return SCM(playerid, HEX_RED, "[Desolation]: You must have a radio in your inventory.");

	if(playerRadio[playerid][8] == 0) return SCM(playerid, HEX_RED, "[Desolation]: You are not connected to any frequency on this slot. Use /setfreq or /setslot.");

	SendRadioMessage(playerid, playerRadio[playerid][8], message);

	return 1;
}

YCMD:radiohelp(playerid, params[], help) {
	SCM(playerid, HEX_FADE2, "Radio commands: /togradio, /setchannel, /setfreq, /frequencies, /showradio, /r -  /r(channel) like /r5 or /r8");
	return 1;
}

YCMD:frequencies(playerid, params[], help) {
	SCM(playerid, HEX_FADE2, "Your currently set frequencies:");
	new i = 0;
	for(;++i<9;)
		SFM(playerid, HEX_FADE2, " > [Channel: %d Frequency: %d.0]", i, playerRadio[playerid][i]);
	return 1;
}

YCMD:showradio(playerid, params[], help) {
	new targetid = INVALID_PLAYER_ID;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /showradio [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(playerid == targetid) return SCM(playerid, HEX_RED, "[Desolation]: You cannot message yourself.");
	new Float:pos[3];
	GetPlayerPos(targetid, pos[0],pos[1],pos[2]);
	if(!IsPlayerInRangeOfPoint(playerid, 3.0, pos[0],pos[1],pos[2]) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");
	if(Bit_Get(spectating, targetid)) return SCM(playerid, HEX_RED, "[Desolation]: That player is too far away.");

	SFM(targetid, HEX_FADE2, "%s's currently set frequencies:", PlayerName(playerid, false));
	new i = 0;
	for(;++i<9;)
		SFM(targetid, HEX_FADE2, " > [Channel: %d Frequency: %d.0]", i, playerRadio[playerid][i]);
	return 1;
}

YCMD:checkradio(playerid, params[], help) {

	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid) && adminlevel[playerid] != -1) return SendErrorMessage(playerid, ERROR_DUTY);
	new targetid = INVALID_PLAYER_ID;
	if(sscanf(params, "r", targetid)) return SCM(playerid, HEX_FADE2, "Usage: /checkradio [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "i", targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	SFM(targetid, HEX_FADE2, "%s's currently set frequencies:", PlayerName(targetid, false));
	new i = 0;
	for(;++i<9;)
		SFM(playerid, HEX_FADE2, " > [Channel: %d Frequency: %d.0]", i, playerRadio[targetid][i]);
	return 1;
}

