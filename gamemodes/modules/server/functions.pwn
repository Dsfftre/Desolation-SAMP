new HumansSkins [] =
{
	1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 19, 20, 21, 21, 22, 23, 24,
	25, 26, 27, 27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 42, 43, 44, 45, 46, 47,
 	48, 49, 51, 52, 57, 58, 59, 60, 61, 62, 66, 67, 68, 70, 71, 72, 73, 78, 79,
 	80, 81, 82, 83, 84, 86, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
 	106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
    122, 123, 124, 125, 126, 127, 128, 132, 133, 134, 135, 136, 137, 142, 143, 144,
	146, 147, 152, 153, 154, 155, 156, 158, 159, 160, 161, 163, 164, 165, 166, 167,
	168, 170, 171, 173, 174, 175, 176, 177, 179, 180, 181, 182, 183, 184, 185, 186,
	187, 188, 189, 200, 202, 203, 204, 206, 208, 209, 210, 212, 213, 217, 220, 221,
	222, 223, 227, 228, 229, 230, 234, 235, 236, 239, 240, 241, 242, 247, 248, 249,
	250, 252, 253, 254, 255, 258, 259, 260, 261, 262, 264, 265, 266, 267, 268, 269,
	270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285,
	286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 299, 300, 301, 302,
	303, 304, 305, 310, 311
};
enum fInfoEnum {
	sqlid,
	name[128],
	brand,
	bank
}
new fInfo[MAX_FACTIONS][fInfoEnum];

enum ServerTimeEnum {
    weather,
    hour,
	minute
}
new ServerTime[ServerTimeEnum];

new
    AccountSQL[MAX_PLAYERS],
    CharacterSQL[MAX_PLAYERS],
    adminlevel[MAX_PLAYERS],
	accountname[MAX_PLAYERS][MAX_PLAYER_NAME],
	p_skin[MAX_PLAYERS],
	faction[MAX_PLAYERS],
	city[MAX_PLAYERS],
	factionrank[MAX_PLAYERS][32],
	race[MAX_PLAYERS],
	zombierace[MAX_PLAYERS],
	cash[MAX_PLAYERS],
	count_infest[MAX_PLAYERS],
	p_weapon[MAX_PLAYERS][4],
	p_ammos[MAX_PLAYERS][4],
	p_shots[MAX_PLAYERS][4],
	SpawnFreezeTimer[MAX_PLAYERS],
	minutes[MAX_PLAYERS],
	experience[MAX_PLAYERS],
	level[MAX_PLAYERS],
	PlayerBar:hungerbar[MAX_PLAYERS],
	PlayerBar:thirstbar[MAX_PLAYERS],
	Float:hunger[MAX_PLAYERS],
	Float:thirst[MAX_PLAYERS],

	Athlete[MAX_PLAYERS],
	Pilot[MAX_PLAYERS],
	Miner[MAX_PLAYERS],
	Craftsmen[MAX_PLAYERS],
	Merchant[MAX_PLAYERS],

	MechSkill[MAX_PLAYERS],
	LuckSkill[MAX_PLAYERS],
	CraftSkill[MAX_PLAYERS],
	TradeSkill[MAX_PLAYERS],

	talkstyle[MAX_PLAYERS],
	inventory_itemid[MAX_PLAYERS][MAX_INVENTORY_SLOTS],
	inventory_amount[MAX_PLAYERS][MAX_INVENTORY_SLOTS],
	dropped_itemid[MAX_PLAYERS][MAX_INVENTORY_SLOTS*3],
	dropped_amount[MAX_PLAYERS][MAX_INVENTORY_SLOTS*3],
	Float:dropped_posx[MAX_PLAYERS][MAX_INVENTORY_SLOTS*3],
	Float:dropped_posy[MAX_PLAYERS][MAX_INVENTORY_SLOTS*3],
	Float:dropped_posz[MAX_PLAYERS][MAX_INVENTORY_SLOTS*3],
	dropped_virtualworld[MAX_PLAYERS][MAX_INVENTORY_SLOTS*3],
	dropped_interior[MAX_PLAYERS][MAX_INVENTORY_SLOTS*3],
	dropped_object[MAX_PLAYERS][MAX_INVENTORY_SLOTS*3],
	bool:inventory_used[MAX_PLAYERS][MAX_INVENTORY_SLOTS]; //Devnote: should be using bits (but lazy)


/////Crafting shit, no touchie faggot

new 
	Craft[MAX_PLAYERS],
	CraftXP[MAX_PLAYERS],
	Materials[MAX_PLAYERS];

new 	
	Text3D:MaskText[MAX_PLAYERS];
new
	PlayerText:racetd[MAX_PLAYERS];
//////////////////////////
new BitArray:Spam<MAX_PLAYERS>;
new BitArray:frozen<MAX_PLAYERS>;
new BitArray:togfam<MAX_PLAYERS>;
new BitArray:togsnpchp<MAX_PLAYERS>;
new BitArray:dead<MAX_PLAYERS>;
new BitArray:inanim<MAX_PLAYERS>;
new BitArray:ContestedArea<MAX_PLAYERS>;
new BitArray:tutorial<MAX_PLAYERS>;
new BitArray:togsjoin<MAX_PLAYERS>;
new BitArray:togszones<MAX_PLAYERS>;
new BitArray:togshud<MAX_PLAYERS>;
new BitArray:infected<MAX_PLAYERS>;
new BitArray:pzombie<MAX_PLAYERS>;
new BitArray:togzchat<MAX_PLAYERS>;
new BitArray:factionowner<MAX_PLAYERS>;
new BitArray:factionleader<MAX_PLAYERS>;
new BitArray:radiation<MAX_PLAYERS>;
new BitArray:character<MAX_PLAYERS>;
new BitArray:loggedin<MAX_PLAYERS>;
new BitArray:newbiechat<MAX_PLAYERS>;
new BitArray:cityruler<MAX_PLAYERS>;
new BitArray:citycommissioner<MAX_PLAYERS>;
new BitArray:crashed<MAX_PLAYERS>;
new BitArray:blindfolded<MAX_PLAYERS>;
new BitArray:spellcooldown<MAX_PLAYERS>;
new BitArray:openinventory<MAX_PLAYERS>;
new BitArray:openstorage<MAX_PLAYERS>;
new BitArray:masked<MAX_PLAYERS>;
new BitArray:spectating<MAX_PLAYERS>;
new BitArray:deathspawn<MAX_PLAYERS>;

new Text3D:DamageLabel[MAX_PLAYERS];

new Group:g_Faction[MAX_FACTIONS+1],
	Group:g_Factiontype[MAX_FACTION_TYPES],
	Group:g_City[MAX_CITIES+1];



enum LootInfoEnum {
	sqlid,
	Name,
	object,
	itemlistId,
	Float:lootpos[3],
	l_virtualworld,
	interior,
	l_category,
	Text3D:LabelID
}
new LootInfo[MAX_LOOT][LootInfoEnum];

new BitArray:lootable<MAX_LOOT>;


enum vehicleInfoEnum {
	sqlid,
	Float:vpos[4],
	model,
	Float:vhealth,
	access,
	playersId,
	factionId,
	vcolor[2],
	interior,
	v_virtualworld,
	plates[32],
	siren,
	engine,
	locked,
	vid
}
new VehicleInfo[MAX_VEHICLES][vehicleInfoEnum];
new Iterator:Cars<MAX_VEHICLES>;

new Iterator:Entrances<MAX_INTERIORS>;

enum IntInfoEnum {//id	playerId	factionId	storeId	intx	inty	intz	intf	intvw	intint	outx	outy	outz	outf	outvw	outint locked	state
	sqlid,
	intname[64],
	player,
	cityId,
	factionId,
	storeId,
	Float:intx,
	Float:inty,
	Float:intz,
	Float:intf,
	intvw,
	intint,
	Float:outx,
	Float:outy,
	Float:outz,
	Float:outf,
	outvw,
	outint,
	checkpoint_out,
	pickup_out,
	locked
}
new IntInfo[MAX_INTERIORS][IntInfoEnum];

new
	Group:g_HiddenAdmin,
	Group:g_Admin,
	Group:g_AdminDuty,
	Group:g_Zombie,
	Group:npc_Zombie,
	Group:npc_a51;


new Soldier[MAX_GUARDS],
	SoldierType[MAX_PLAYERS],
	Float:SoldierPatrol[MAX_PLAYERS][4],
	Float:SoldierPositions[MAX_PLAYERS][4],
	SoldierSkin[MAX_PLAYERS];


new Iterator:Storages<MAX_STORAGE_POINTS>;

enum storageInfoEnum {
	safe_sqlid,
	safe_object,
	safe_object2,
	safe_objid,
	bool:safe_locked,
	safe_playerid,
	safe_factionid,
	safe_cityid,
	safe_interior,
	Float:safe_pos[3],
	Float:safe_rot[3],
	safe_virtualworld
}
new storageInfo[MAX_STORAGE_POINTS][storageInfoEnum];

SpamPrevent(playerid, duration = SPAM_PREVENT_TIME) {
	if(Bit_Get(Spam, playerid)) {
		SCM(playerid, HEX_FADE2, "You were too fast, please try again!");
		return 0;
	}
	Bit_Let(Spam, playerid);
	SetTimerEx("EndAntiSpam", duration, 0, "%i", playerid);
	return 1;
}

forward EndAntiSpam(playerid);
public EndAntiSpam(playerid) {
	if(Bit_Get(Spam, playerid)) {
		Bit_Vet(Spam, playerid);
	}
	return 1;
}

IsInLOS(Float:point1[3], Float:point2[3], bool:fixz = true) {
	
	if(fixz) { //calculte from player's head, not feet
		point1[2] += 1.0;
		point2[2] += 1.0;
	}

	new Float:dump;
	new result = CA_RayCastLine(point1[0], point1[1], point1[2], point2[0],point2[1], point2[2], dump, dump, dump);
	if(result == 0)
		return 1;
	return 0;
}

timer KickTimer[1000](playerid)
{
    Kick(playerid);
}

KickPlayer(playerid) {
	defer KickTimer(playerid);
	return 1;
}

PlayerName(playerid, bool:underscore = true) {
	new returnval[MAX_PLAYER_NAME];
	GetPlayerName(playerid, returnval, MAX_PLAYER_NAME);
	if(!underscore) 
	{
		if(Bit_Get(masked, playerid)) 
		{
			format(returnval, sizeof returnval, "Stranger %d", CharacterSQL[playerid]+14950);
		}
		else {
			new i = -1;
			for(;++i < MAX_PLAYER_NAME;) 
			{
				if(returnval[i] == '_') returnval[i] = ' ';
			}
		}
	}
	return returnval;
}

RemoveNameSpace(string[]) {
	new returnVal[MAX_PLAYER_NAME];
	format(returnVal, sizeof returnVal, "%s", string);
	new i = -1;
	for(;++i < MAX_PLAYER_NAME;) 
	{
		if(returnVal[i] == '_') returnVal[i] = ' ';
	}
	return returnVal;
}

ChangeMaskVW(playerid) {
	if(Bit_Get(masked, playerid)) {
		MaskPlayer(playerid, false, false);
		MaskPlayer(playerid, true, false);
	}
	return 1;
}

PlayerAction(playerid, action[], autofill = true) {
	if(Bit_Get(spectating, playerid)) return 0;
	if(autofill) {
		new string[256];
		format(string, sizeof(string), "* %s %s",PlayerName(playerid,false),action);
		SetPlayerChatBubble(playerid, string, COLOR_PURPLE, 30.0, 7000);
		format(string, sizeof(string), "> %s %s ",PlayerName(playerid,false),action);
		SCM(playerid, HEX_PURPLE, string);
	}
	else {
		SetPlayerChatBubble(playerid, action, COLOR_PURPLE, 30.0, 7000);
		SCM(playerid, HEX_PURPLE, action);
	}
	return 1;
}

PlayerHiddenAction(playerid, action[]) {
	if(Bit_Get(spectating, playerid)) return 0;
	new string[256];
	format(string, sizeof(string), "* %s %s",PlayerName(playerid,false),action);
	SetPlayerChatBubble(playerid, string, COLOR_PURPLE, 30.0, 5000);
	return 1;
}

forward Float:frandom(Float:max, Float:min = 0.0, dp = 4);
Float:frandom(Float:max, Float:min = 0.0, dp = 4) {
    new
        // Get the multiplication for storing fractional parts.
        Float:mul = floatpower(10.0, dp),
        // Get the max and min as integers, with extra dp.
        imin = floatround(min * mul),
        imax = floatround(max * mul);
    // Get a random int between two bounds and convert it to a float.
    return float(random(imax - imin) + imin) / mul;
}

stock WhiteProxMSG(Float:radi, playerid, string[], bool:skipplayerid=false) {
	new Float:posx, Float:posy, Float:posz;
	new Float:oldposx, Float:oldposy, Float:oldposz;
	new Float:tempposx, Float:tempposy, Float:tempposz;
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i)/*&&pInfo[i][pLoggedIn]==true*/)
		{
			//if(pInfo[i][pTog][3] && isooc == true) continue;
			if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(i)) continue;
			if(skipplayerid && i == playerid) continue;
			
			GetPlayerPos(i, posx, posy, posz);
			tempposx = (oldposx -posx);
			tempposy = (oldposy -posy);
			tempposz = (oldposz -posz);

			if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
			{ 
				SCM(i, HEX_FADE1, string);
			}
			else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
			{
				SCM(i, HEX_FADE2, string);
			}
			else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
			{ 
				SCM(i, HEX_FADE3, string);
			}
			else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
			{ 
				SCM(i, HEX_FADE4, string);
			}
			else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
			{ 
				SCM(i, HEX_FADE5, string);
			}
		}
	}
	return 1;
}

stock ProxMSG(color[], Float:radi, playerid, string[], bool:skipplayerid=false) {
	new Float:posx, Float:posy, Float:posz;
	GetPlayerPos(playerid, posx, posy, posz);
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i)/*&&pInfo[i][pLoggedIn]==true*/)
		{
			//if(pInfo[i][pTog][3] && isooc == true) continue;
			if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(i)) continue;
			if(skipplayerid && i == playerid) continue;

			if(IsPlayerInRangeOfPoint(i, radi, posx, Float:posy, Float:posz))
				SCM(i, color, string);
			
		}
	}
	return 1;
}
/*
stock ProxDetector(Float:radi, playerid, string[],col1,col2,col3,col4,col5, bool:playertne=false) {
	new Float:posx, Float:posy, Float:posz;
	new Float:oldposx, Float:oldposy, Float:oldposz;
	new Float:tempposx, Float:tempposy, Float:tempposz;
	GetPlayerPos(playerid, oldposx, oldposy, oldposz);
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			//if(pInfo[i][pTog][3] && isooc == true) continue;
			if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(i)) continue;
			if(playertne && i == playerid) continue;
			
			new Chat_Split1[128];
			new Chat_Split2[128];
			new countdots = strlen(PlayerName(playerid, false));
			
			GetPlayerPos(i, posx, posy, posz);
			tempposx = (oldposx -posx);
			tempposy = (oldposy -posy);
			tempposz = (oldposz -posz);
			
			if(strlen(string) >= 133-countdots)
			{
				strmid(Chat_Split1, string, 0, 83, 83);
				strmid(Chat_Split2, string, 82, 256, 256);
				strins(Chat_Split2, "... ", 0);
			}
			
			if (((tempposx < radi/16) && (tempposx > -radi/16)) && ((tempposy < radi/16) && (tempposy > -radi/16)) && ((tempposz < radi/16) && (tempposz > -radi/16)))
			{ 
				SCM(i, col1, string);
			}
			else if (((tempposx < radi/8) && (tempposx > -radi/8)) && ((tempposy < radi/8) && (tempposy > -radi/8)) && ((tempposz < radi/8) && (tempposz > -radi/8)))
			{
				SCM(i, col2, string);
			}
			else if (((tempposx < radi/4) && (tempposx > -radi/4)) && ((tempposy < radi/4) && (tempposy > -radi/4)) && ((tempposz < radi/4) && (tempposz > -radi/4)))
			{ 
				SCM(i, col3, string);
			}
			else if (((tempposx < radi/2) && (tempposx > -radi/2)) && ((tempposy < radi/2) && (tempposy > -radi/2)) && ((tempposz < radi/2) && (tempposz > -radi/2)))
			{ 
				SCM(i, col4, string);
			}
			else if (((tempposx < radi) && (tempposx > -radi)) && ((tempposy < radi) && (tempposy > -radi)) && ((tempposz < radi) && (tempposz > -radi)))
			{ 
				SCM(i, col5, string);
			}
		}
	}
	return 1;
}
*/
stock SFM(const iPlayer, iColor[], const szFormat[], {Float, _}: ...) {
	static hex,asd[32],Chat_Split1[128],Chat_Split2[128];
    new iArgs = (numargs() - 3) << 2;
	
	strreplace2(iColor, "{","");
	strreplace2(iColor, "}","");
	format(asd,sizeof(asd),"0x%sAA", iColor);
	sscanf(asd, "x", hex);
	
    if(iArgs)
        {
        static s_szBuf[256],s_iAddr1,s_iAddr2;
        
        #emit ADDR.PRI szFormat
        #emit STOR.PRI s_iAddr1
 
        for(s_iAddr2 = s_iAddr1 + iArgs, iArgs += 12; s_iAddr2 != s_iAddr1; s_iAddr2 -= 4) {
            #emit LOAD.PRI s_iAddr2
            #emit LOAD.I
            #emit PUSH.PRI
        }
        #emit CONST.PRI s_szBuf
 
        #emit PUSH.S szFormat
        #emit PUSH.C 256
        #emit PUSH.PRI
        #emit PUSH.S iArgs
        #emit SYSREQ.C format
 
        #emit LCTRL 4
        #emit LOAD.S.ALT iArgs
        #emit ADD.C 4
        #emit ADD
        #emit SCTRL 4
	
		if(strlen(s_szBuf) >= 129) {
			strmid(Chat_Split1, s_szBuf, 0, 128, 128);
			strmid(Chat_Split2, s_szBuf, 127, 256, 256);
			strins(Chat_Split2, "... ", 0);
		}
	
        if(strlen(s_szBuf) <= 128)
			SendClientMessage(iPlayer, hex, s_szBuf);

		else if(strlen(s_szBuf) >= 129) {
			SendClientMessage(iPlayer, hex, Chat_Split1);
			SendClientMessage(iPlayer, hex, Chat_Split2);
		}
		return true;
    }
    return (iPlayer != -1) ? SendClientMessage(iPlayer, hex, szFormat) : SendClientMessageToAll(hex, szFormat);
}

stock SPCM(playerid, color, text[], minlen = 110, maxlen = 120)//SendSplitClientMessage
{
    new str[256];
    if(strlen(text) > maxlen) {
        new pos = maxlen;
        while(text[--pos] > ' ') {}
        if(pos < minlen) pos = maxlen;
        format(str, sizeof(str), "%.*s ...", pos, text);
        SendClientMessage(playerid,color,str);
        format(str, sizeof(str), "... %s", text[pos+1]);
        SendClientMessage(playerid,color,str);
    }
    else format(str, sizeof(str), "%s", text), SendClientMessage(playerid,color,str);
    return true;
}

stock SCM(pid,color[],text[]) {
	new hex,asd[32];
	strreplace2(color, "{","");
	strreplace2(color, "}","");
	format(asd,32,"0x%sAA", color);
	sscanf(asd, "x", hex);
	
	new Chat_Split1[128];
	new Chat_Split2[128];
	
	if(strlen(text) >= 129) {
		strmid(Chat_Split1, text, 0, 128, 128);
		strmid(Chat_Split2, text, 127, 256, 256);
		strins(Chat_Split2, "... ", 0);
	}
	if(strlen(text) <= 128)
		SendClientMessage(pid, hex, text);

	else if(strlen(text) >= 129)
	{
		SendClientMessage(pid, hex, Chat_Split1);
		SendClientMessage(pid, hex, Chat_Split2);
	}
	return true;
}

strreplace2(string[], const search[], const replacement[], bool:ignorecase = true, pos = 0, limit = -1, maxlength = 128) {
    if (limit == 0) return 0;
    new
             sublen = strlen(search),
             replen = strlen(replacement),
        bool:packed = ispacked(string),
             maxlen = maxlength,
             len = strlen(string),
             count = 0
    ;
    if (packed) maxlen *= 4;
    if (!sublen) return 0;
    while (-1 != (pos = strfind(string, search, ignorecase, pos))) {
        strdel(string, pos, pos + sublen);
        len -= sublen;
        if (replen && len + replen < maxlen) {
            strins(string, replacement, pos, maxlength);
            pos += replen;
            len += replen;
        }
        if (limit != -1 && ++count >= limit)
            break;
    }
    return count;
}

stock GetTickDiff(newtick, oldtick) {
    if (oldtick > newtick) {
        return (cellmax - oldtick + 1) - (cellmin - newtick);
    }
    return newtick - oldtick;
} 

ReturnGPCI(playerid) {
    new 
        szSerial[41]; // 40 + \0
 
    gpci(playerid, szSerial, sizeof(szSerial));
    return szSerial;
}


stock IsRPName(const CharName[], max_underscores = 1) {
    new underscores = 0;
	new capitals = 0;
    if (CharName[0] < 'A' || CharName[0] > 'Z') return false;
    for(new i = 1; i < strlen(CharName); ++i) {
        if(CharName[i] != '_' && (CharName[i] < 'A' || CharName[i] > 'Z') && (CharName[i] < 'a' || CharName[i] > 'z')) return false;
        if( (CharName[i] >= 'A' && CharName[i] <= 'Z') && (CharName[i - 1] != '_') ) {
			++capitals;
			if(capitals > 3)
				return false;
		} 
        if(CharName[i] == '_') {
            ++underscores;
            if(underscores > max_underscores || i == strlen(CharName)) return false;
            if(CharName[i + 1] < 'A' || CharName[i + 1] > 'Z') return false;
        }
    }
    if (underscores == 0) return false;
    return true;
}

ReturnTime() {
    new get[6],time[32];
    getdate(get[0],get[1],get[2]);
    gettime(get[3],get[4],get[5]);
    format(time,sizeof(time),"%d-%02d-%02d %02d:%02d:%02d",get[0],get[1],get[2],get[3],get[4],get[5]);
    return time;
}

YCMD:servertime(playerid, params[], help) {
	SFM(playerid, HEX_FADE2, "Current server date and time: %s", ReturnTime());
	return 1;
}

DeathReason(reason) {
    new string[32];
	switch(reason) {
		case 0: format(string, sizeof(string), "Fist");
		case 1: format(string, sizeof(string), "Boxer");
		case 2: format(string, sizeof(string), "Golf");
		case 3: format(string, sizeof(string), "Nightstick");
		case 4: format(string, sizeof(string), "Knife");
	    case 5: format(string, sizeof(string), "Baseball bat");
	    case 6: format(string, sizeof(string), "Shovel");
	    case 7: format(string, sizeof(string), "Pool cue");
	    case 8: format(string, sizeof(string), "Katana");
	    case 9: format(string, sizeof(string), "Chainsaw");
	    case 10: format(string, sizeof(string), "Purple vibrator");
	    case 11: format(string, sizeof(string), "Dildo");
	    case 12: format(string, sizeof(string), "Vibrator");
	    case 13: format(string, sizeof(string), "Vibrator");
	    case 14: format(string, sizeof(string), "Flowers");
	    case 15: format(string, sizeof(string), "Cane");
	    case 16: format(string, sizeof(string), "Grenade");
	    case 17: format(string, sizeof(string), "Smoke grenade");
	    case 18: format(string, sizeof(string), "Molotov cocktail");
	    case 19: format(string, sizeof(string), "Vehicle weapon");
	    case 20: format(string, sizeof(string), "Hydra Flare");
	    case 21: format(string, sizeof(string), "Jetpack");
	    case 22: format(string, sizeof(string), "9mm");
	    case 23: format(string, sizeof(string), "Silenced Pistol");
	    case 24: format(string, sizeof(string), "Desert Eagle");
	    case 25: format(string, sizeof(string), "Shotgun");
	    case 26: format(string, sizeof(string), "Sawn-off Shotgun");
	    case 27: format(string, sizeof(string), "Combat Shotgun");
	    case 28: format(string, sizeof(string), "Uzi");
	    case 29: format(string, sizeof(string), "MP5");
	    case 30: format(string, sizeof(string), "AK47");
	    case 31: format(string, sizeof(string), "M4");
	    case 32: format(string, sizeof(string), "Tec-9");
	    case 33: format(string, sizeof(string), "Rifle");
	    case 34: format(string, sizeof(string), "Sniper");
	    case 35: format(string, sizeof(string), "Rocket Launcher");
	    case 36: format(string, sizeof(string), "HS Rocket Launcher");
	    case 37: format(string, sizeof(string), "Flamethrower");
	    case 38: format(string, sizeof(string), "Minigun");
	    case 39: format(string, sizeof(string), "Explosive");
	    case 40: format(string, sizeof(string), "Deton�tor");
	    case 41: format(string, sizeof(string), "Pepper sray");
	    case 42: format(string, sizeof(string), "Fire Extinguisher");
	    case 43: format(string, sizeof(string), "Camera");
		case 44: format(string, sizeof(string), "Nightvision");
		case 45: format(string, sizeof(string), "Thermal vision");
		case 46: format(string, sizeof(string), "Parachute");
		case 47: format(string, sizeof(string), "Fake pistol");
		case 48: format(string, sizeof(string), "INCORRECT ID (48)");
		case 49: format(string, sizeof(string), "Vehicle");
		case 50: format(string, sizeof(string), "Heliblade");
		case 51: format(string, sizeof(string), "Explosion");
		case 52: format(string, sizeof(string), "INCORRECT ID (52)");
		case 53: format(string, sizeof(string), "Drowned");
		case 54: format(string, sizeof(string), "Splat");
		case 255: format(string, sizeof(string), "Suicide");
		default: format(string, sizeof(string), "INCORRED ID (%i)",reason);
 	}
	return string;
}

ApplyDeathAnimation(playerid) {
	TogglePlayerControllable(playerid, false);
	ApplyAnimation(playerid, "ped", "KO_shot_front", 4.0, 0, 1, 1, 1, -1);
	ApplyAnimation(playerid, "ped", "KO_shot_front", 4.0, 0, 1, 1, 1, -1);
	/*switch(random(5)) 
	{
		case 0: ApplyAnimation(playerid, "ped", "FLOOR_hit", 4.0, 0, 1, 1, 1, -1), ApplyAnimation(playerid, "ped", "FLOOR_hit", 4.0, 0, 1, 1, 1, -1);
		case 1: ApplyAnimation(playerid, "ped", "FLOOR_hit_f", 4.0, 0, 1, 1, 1, -1), ApplyAnimation(playerid, "ped", "FLOOR_hit_f", 4.0, 0, 1, 1, 1, -1);
		case 2: ApplyAnimation(playerid, "ped", "KO_shot_front", 4.0, 0, 1, 1, 1, -1), ApplyAnimation(playerid, "ped", "KO_shot_front", 4.0, 0, 1, 1, 1, -1);
		case 3: ApplyAnimation(playerid, "ped", "KO_shot_stom", 4.0, 0, 1, 1, 1, -1), ApplyAnimation(playerid, "ped", "KO_shot_stom", 4.0, 0, 1, 1, 1, -1);
		case 4: ApplyAnimation(playerid, "ped", "BIKE_fall_off", 4.0, 0, 1, 1, 1, -1), ApplyAnimation(playerid, "ped", "BIKE_fall_off", 4.0, 0, 1, 1, 1, -1);
		case 5: ApplyAnimation(playerid, "FINALE", "FIN_Land_Die", 4.0, 0, 1, 1, 1, -1), ApplyAnimation(playerid, "FINALE", "FIN_Land_Die", 4.0, 0, 1, 1, 1, -1);
	}*/
	return 1;
}

ActorDeathAnimation(actorid) {
	switch(random(5)) {
		case 0: ApplyActorAnimation(actorid, "ped", "FLOOR_hit", 4.0, 0, 1, 1, 1, -1);
		case 1: ApplyActorAnimation(actorid, "ped", "FLOOR_hit_f", 4.0, 0, 1, 1, 1, -1);
		case 2: ApplyActorAnimation(actorid, "ped", "KO_shot_front", 4.0, 0, 1, 1, 1, -1);
		case 3: ApplyActorAnimation(actorid, "ped", "KO_shot_stom", 4.0, 0, 1, 1, 1, -1);
		case 4: ApplyActorAnimation(actorid, "ped", "BIKE_fall_off", 4.0, 0, 1, 1, 1, -1);
		case 5:ApplyActorAnimation(actorid, "FINALE", "FIN_Land_Die", 4.0, 0, 1, 1, 1, -1);
	}
	return 1;
}

/*IsTruck(vehicleid) {
	if(!IsValidVehicle(vehicleid)) return 0;

	switch(GetVehicleModel(vehicleid)) {
		case 403: return 1;
		case 514: return 1;
		case 515: return 1;
	}
	return 0;
}

IsTrailerModel(vehiclemodel) {
	switch(vehiclemodel) {
		case 435: return 1;
		case 450: return 1;
		case 584: return 1;
		case 591: return 1;
	}
	return 0;
}*/

IsNameTaken(playername[]) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT id FROM `player` WHERE name = '%e' LIMIT 1", playername);
	new Cache:result = mysql_query(g_SQL, sql);
	if(cache_num_rows()) {
		cache_delete(result);
		return 1;
	}
	cache_delete(result);
	return 0;
}


HidePlayerMarkers(playerid) {
	foreach(new i:Player) {
		if(Group_GetPlayer(g_AdminDuty, i))
			SetPlayerMarkerForPlayer(playerid, i, COLOR_ADMIN);	
		if (!IsZombie(i))
			SetPlayerMarkerForPlayer(playerid, i, COLOR_PLAYER);
		else
			SetPlayerMarkerForPlayer(playerid, i, COLOR_ZOMBIE);
	}
	foreach(new j:GroupMember[npc_Zombie]) {
		SetPlayerMarkerForPlayer(playerid, j, COLOR_ZOMBIE);		
	}
	foreach(new k:GroupMember[npc_a51]) {
		SetPlayerMarkerForPlayer(playerid, k, COLOR_NPC);		
	}
	return 1;
}

hook FCNPC_OnStreamIn(npcid, forplayerid) {
	if(Group_GetPlayer(npc_a51, npcid))
		SetPlayerMarkerForPlayer(forplayerid, npcid, COLOR_NPC);
	if(Group_GetPlayer(npc_Zombie, npcid))
		SetPlayerMarkerForPlayer(forplayerid, npcid, COLOR_ZOMBIE);
	return Y_HOOKS_CONTINUE_RETURN_1;
}


new VehicleNames[212][] = { 
   "Landstalker",  "Bravura",  "Buffalo", "Linerunner", "Perennial", "Sentinel", 
   "Dumper",  "Firetruck" ,  "Trashmaster" ,  "Stretch",  "Manana",  "Infernus", 
   "Voodoo", "Pony",  "Mule", "Cheetah", "Ambulance",  "Leviathan",  "Moonbeam", 
   "Esperanto", "Taxi",  "Washington",  "Bobcat",  "Mr Whoopee", "BF Injection", 
   "Hunter", "Premier",  "Enforcer",  "Securicar", "Banshee", "Predator", "Bus", 
   "Rhino",  "Barracks",  "Hotknife",  "Trailer",  "Previon", "Coach", "Cabbie", 
   "Stallion", "Rumpo", "RC Bandit",  "Romero", "Packer", "Monster",  "Admiral", 
   "Squalo", "Seasparrow", "Pizzaboy", "Tram", "Trailer",  "Turismo", "Speeder", 
   "Reefer", "Tropic", "Flatbed","Yankee", "Caddy", "Solair","Berkley's RC Van", 
   "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron","RC Raider","Glendale", 
   "Oceanic", "Sanchez", "Sparrow",  "Patriot", "Quad",  "Coastguard", "Dinghy", 
   "Hermes", "Sabre", "Rustler", "ZR-350", "Walton",  "Regina",  "Comet", "BMX", 
   "Burrito", "Camper", "Marquis", "Baggage", "Dozer","Maverick","News Chopper", 
   "Rancher", "FBI Rancher", "Virgo", "Greenwood","Jetmax","Hotring","Sandking", 
   "Blista Compact", "Police Maverick", "Boxville", "Benson","Mesa","RC Goblin", 
   "Hotring Racer", "Hotring Racer", "Bloodring Banger", "Rancher",  "Super GT", 
   "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropdust", "Stunt", 
   "Tanker", "RoadTrain", "Nebula", "Majestic", "Buccaneer", "Shamal",  "Hydra", 
   "FCR-900","NRG-500","HPV1000","Cement Truck","Tow Truck","Fortune","Cadrona", 
   "FBI Truck", "Willard", "Forklift","Tractor","Combine","Feltzer","Remington", 
   "Slamvan", "Blade", "Freight", "Streak","Vortex","Vincent","Bullet","Clover", 
   "Sadler",  "Firetruck", "Hustler", "Intruder", "Primo", "Cargobob",  "Tampa", 
   "Sunrise", "Merit",  "Utility Truck",  "Nevada", "Yosemite", "Windsor",  "Monster", 
   "Monster","Uranus","Jester","Sultan","Stratum","Elegy","Raindance","RCTiger", 
   "Flash","Tahoma","Savanna", "Bandito", "Freight", "Trailer", "Kart", "Mower", 
   "Dune", "Sweeper", "Broadway", "Tornado", "AT-400",  "DFT-30", "Huntley", 
   "Stafford", "BF-400", "Newsvan","Tug","Trailer","Emperor","Wayfarer","Euros", 
   "Hotdog", "Club", "Trailer", "Trailer","Andromada","Dodo","RC Cam", "Launch", 
   "Police Car (LSPD)", "Police Car (SFPD)","Police Car (LVPD)","Police Ranger", 
   "Picador",   "S.W.A.T. Van",  "Alpha",   "Phoenix",   "Glendale",   "Sadler", 
   "Luggage Trailer","Luggage Trailer","Stair Trailer", "Boxville", "Farm Plow", 
   "Utility Trailer" 
};  


stock RemovePlayerWeapon(playerid, weaponid) {
    new plyWeapons[12];
    new plyAmmo[12];
 
    for(new slot = 0; slot != 12; slot++)
    {
        new wep, ammo;
        GetPlayerWeaponData(playerid, slot, wep, ammo);
 
        if(wep != weaponid)
        {
            GetPlayerWeaponData(playerid, slot, plyWeapons[slot], plyAmmo[slot]);
        }
    }
 
    ResetPlayerWeapons(playerid);
    for(new slot = 0; slot != 12; slot++)
    {
        GivePlayerWeapon(playerid, plyWeapons[slot], plyAmmo[slot]);
    }
}

stock SendErrorMessage(playerid, str[])
{
    new astr[128];
    format(astr, sizeof(astr), "> [ERROR] %s", str);
    SCM(playerid, HEX_SAMP, astr);
    return 1;
}

GetItemObject(itemdid) {
    mysql_format(g_SQL, sql, sizeof sql, "SELECT object FROM `itemlist` WHERE id = %d LIMIT 1", itemdid);
    new Cache:result = mysql_query(g_SQL, sql);
    new returnval;
    if(cache_num_rows()) {
        cache_get_value_int(0, "object", returnval);
    }
    cache_delete(result);
    //printf("GetItemObject returnval %d", returnval); // used for debug
    return returnval;    
}

LeaveReason(lcase) {
	new retval[16] = "Unknown";

	switch(lcase) {
		case 0: retval = "Timeout/Crash";
		case 1: retval = "Quit";
		case 2: retval = "Kick/Ban";
	}

	return retval;
}

LogConnection(playerid) {
	new ip[18];
    GetPlayerIp(playerid, ip, sizeof(ip));
    mysql_format(g_SQL, sql, sizeof sql, "INSERT INTO `logins` (`accountId`, `playerId`, `hardwareid`, `ip`) VALUES ('%d', '%d', '%e', '%e')", AccountSQL[playerid], CharacterSQL[playerid], ReturnGPCI(playerid), ip);
	mysql_tquery(g_SQL, sql, "", "");	
    mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `loginDate` = CURRENT_TIMESTAMP WHERE id = '%d' LIMIT 1",  CharacterSQL[playerid]);
	mysql_tquery(g_SQL, sql, "", "");
    printf("%s", sql);
    return 1;
}

MYSQL_Update_Character(playerid, option1[], option2)
{
    mysql_format(g_SQL, sql, sizeof(sql), "UPDATE `player` SET `%e` = %d WHERE id = %d LIMIT 1", option1, option2, CharacterSQL[playerid]);
    mysql_tquery(g_SQL, sql);
    printf("DEBUG: ---MYSQL_Update_Character Character [%s] [ID:%d] [ACCOUNT ID:%d] [CHARACTER ID:%d]", PlayerName(playerid), playerid, AccountSQL[playerid], CharacterSQL[playerid]);
    printf("DEBUG: ---MYSQL_Update_Character query: %s", sql);
    return 1;
}

stock GetConnectedPlayers() { 
    new count = 0;
	foreach(new i:Player) {
		++count;
	}
    return count; 
}
/*
forward PublicLog(string[]);
public PublicLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\r\n",string);
	new File:hFile;
	hFile = fopen("Logs/public.log", io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

forward ReportLog(string[]);
public ReportLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\r\n",string);
	new File:hFile;
	hFile = fopen("Logs/reports.log", io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}

forward AdminLog(string[]);
public AdminLog(string[])
{
	new entry[256];
	format(entry, sizeof(entry), "%s\r\n",string);
	new File:hFile;
	hFile = fopen("Logs/admin.log", io_append);
	fwrite(hFile, entry);
	fclose(hFile);
}
*/

onezero(number) {
	if(number > 0) return 1;
	return 0;
}