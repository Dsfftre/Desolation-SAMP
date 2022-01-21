/*#if defined _inc_cities
	#undef _inc_cities
#endif*/

#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

enum cityInfoEnum {
	sqlid,
	name[128],
	brand,
	bank
}
new cityInfo[MAX_CITIES+1][cityInfoEnum];

new Iterator:Microcities<MAX_CITIES+1>;

hook OnGameModeInit() {
	LoadCities();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadCities() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `city` WHERE state > 0");
	inline LoadCityData() {
		if(!cache_num_rows()) {
			print("No microcities found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", cityInfo[i+1][sqlid]);
			cache_get_value(i, "name", cityInfo[i+1][name], 128);
			g_City[i+1]  = Group_Create(cityInfo[i+1][name]);
			cache_get_value_int(i, "bank", cityInfo[i+1][bank]);
			Iter_Add(Microcities, i+1);
			printf("Microcity '%s' loaded.", cityInfo[i+1][name]);
		}
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadCityData, sql);
	return 1;
}

YCMD:cityhelp(playerid, params[], help) {
	if(city[playerid] == 0)
		return SCM(playerid, HEX_RED, "Error: You are not a microcity citizen.");

	SFM(playerid, HEX_LGREEN, "[City Info] [ID:%d] [Name: %s]", city[playerid], cityInfo[city[playerid]][name]);
	SCM(playerid, HEX_FADE2, "City commands: /cityon, /gates, /quitcity");
	if(Bit_Get(citycommissioner, playerid) || Bit_Get(cityruler, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {
		SCM(playerid, HEX_FADE2, "Commissioner commands: /citizenship, /exile");
	}
	if(Bit_Get(cityruler, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {
		SCM(playerid, HEX_FADE2, "Ruler commands: /mandate, /countermand");
	}
	return 1;
}

YCMD:cities(playerid, params[], help) {
	
	new i = 0,
		string[MAX_CITIES*256],
		string2[256];

	format(string, sizeof string, "Name\tOnline\n");
	for(;++i<MAX_CITIES+1;) {
		if(cityInfo[i][sqlid] != 0) {
			new count = 0;
			foreach(new j:Player) {
				if(city[j] == i)
					++count;
			}
			format(string2, sizeof string2, "%s (%d)\t%i members\n", cityInfo[i][name], cityInfo[i][sqlid], count);
			if(count < 2)
				format(string2, sizeof string2, "%s (%d)\t%i member\n", cityInfo[i][name], cityInfo[i][sqlid], count);
			strcat(string, string2);
		}
	}
	inline Empty(pid, dialogid, response, listitem, string:inputtext[]) {
        #pragma unused pid, dialogid, response, listitem, inputtext
    }
    Dialog_ShowCallback(playerid, using inline Empty, DIALOG_STYLE_TABLIST_HEADERS, "Microcities", string, "Close");
	return 1;
}

YCMD:cityon(playerid, params[], help) {
	
	if(city[playerid] == 0)
		return SCM(playerid, HEX_RED, "Error: You are not a microcity citizen.");
	SFM(playerid, HEX_LGREEN, "%s online citizens:",cityInfo[city[playerid]][name]);
	new count = 0;
	foreach(new i : Player) {
		if(city[playerid] == city[i]) {
			if(Bit_Get(cityruler, i))
				SFM(playerid, HEX_FADE2, "(ID:%i) %s [ruler]",i,PlayerName(i));
			else if(Bit_Get(citycommissioner, i))
				SFM(playerid, HEX_FADE2, "(ID:%i) %s %s [commisioner]",i,PlayerName(i));
			else
				SFM(playerid, HEX_FADE2, "(ID:%i) %s",i,PlayerName(i));
			++count;
		}
	}
	if(count > 9)
		SFM(playerid, HEX_FADE2, "Total: %d", count);
	return 1;
}

ShowCityStats(playerid, targetid = -1) {
	if(targetid == -1)
		SFM(playerid, HEX_FADE2, "Microcity | id:[%d] name:[%s] commissioner:[%d] ruler:[%d]", city[playerid], cityInfo[city[playerid]][name], onezero(Bit_Get(citycommissioner, playerid)),  onezero(Bit_Get(cityruler, playerid)));
	else
		SFM(playerid, HEX_FADE2, "Microcity | id:[%d] name:[%s] commissioner:[%d] ruler:[%d]", city[targetid], cityInfo[city[targetid]][name], onezero(Bit_Get(citycommissioner, targetid)),  onezero(Bit_Get(cityruler, targetid)));
	return 1;
}

YCMD:citizenship(playerid, params[], help) {
	if(city[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You are not a microcity citizen.");
	if(Bit_Get(citycommissioner, playerid) || Bit_Get(cityruler, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {
		new target;
		if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /citizenship [id]");
		if(target == INVALID_PLAYER_ID) {
			unformat(params, "i", target);
			if(!IsPlayerConnected(target) || IsPlayerNPC(target))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}
		if(playerid == target) return SCM(playerid, HEX_RED, "Error: You cannot give citizenship to yourself.");
		if(city[target] > 0) return SFM(playerid, HEX_RED, "Error: %s is already a citizen of a microcity.", PlayerName(target));

		new string[256];
		format(string, sizeof string, "%s has invited you to join microcity %s!", PlayerName(playerid), cityInfo[city[playerid]][name]);

		inline Dialog_city_invite(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
			#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
			if(Open_response) {
				city[Open_pid] = city[playerid];
				new sendText[256];
				format(sendText, sizeof sendText, "** %s has joined the microcity! **", PlayerName(Open_pid));
				foreach(new i : Player)
					if(city[Open_pid] == city[i] && i != Open_pid) {
						SCM(i, HEX_LGREEN, sendText);
					}
				SFM(Open_pid, HEX_YELLOW, "You have joined %s!", cityInfo[city[Open_pid]][name]);
				format(sendText, sizeof sendText, "AdmWarn: %s[%d] has invited %s[%d] into microcity %s.", PlayerName(playerid), playerid, PlayerName(target), target, cityInfo[city[playerid]][name]);
	   			SendAdminMessage(HEX_LRED, sendText, true);

				mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `cityId` = '%d' WHERE id = '%d'  LIMIT 1", city[Open_pid], CharacterSQL[Open_pid]);
				mysql_tquery(g_SQL, sql, "", "");
			}
			else {				
				SFM(playerid, HEX_FADE2, "%s has denied your microcity invitation.", PlayerName(Open_pid));
				SFM(Open_pid, HEX_FADE2, "You denied %s's invitation to microcity %s.", PlayerName(playerid), cityInfo[city[playerid]][name]);
			}
		}	
		Dialog_ShowCallback(target, using inline Dialog_city_invite, DIALOG_STYLE_MSGBOX, "Microcity invite", string, "Accept","Deny");
	}
	else SCM(playerid, HEX_RED, "Error: You need to be a microcity ruler/commissioner to invite players.");
	return 1;
}

YCMD:exile(playerid, params[], help) {
	if(city[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a microcity.");
	if(Bit_Get(cityruler, playerid) || Group_GetPlayer(g_AdminDuty, playerid) || Bit_Get(citycommissioner, playerid)) {

		new target;
		if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /exile [id]");
		if(target == INVALID_PLAYER_ID) {
			unformat(params, "i", target);
			if(!IsPlayerConnected(target) || IsPlayerNPC(target))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}
		if(city[target] != city[playerid]) SFM(playerid, HEX_RED, "Error: %s is not in your microcity.", PlayerName(target));
		if(Bit_Get(citycommissioner, target) && !Bit_Get(cityruler, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: Only microcity rulers can remove commissioners.");

		SFM(target, HEX_FADE2, "%s removed you from %s.", PlayerName(playerid), cityInfo[city[playerid]][name]);
		SFM(playerid, HEX_FADE2, "You removed %s from your microcity.", PlayerName(target));
		
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `citycommissioner` = 0 WHERE id = %d LIMIT 1",  CharacterSQL[target]);
		mysql_tquery(g_SQL, sql, "", "");

		new sendText[256];
        format(sendText, sizeof sendText, "AdmWarn: %s[%d] has removed %s[%d] from microcity %s.", PlayerName(playerid), playerid, PlayerName(target), target, cityInfo[city[playerid]][name]);
	    SendAdminMessage(HEX_LRED, sendText, true);
		city[target] = 0;
		
	}
	else SCM(playerid, HEX_RED, "Error: You need to be a microcity commissioner to exile citizens.");
	return 1;
}

YCMD:mandate(playerid, params[], help) {
	if(city[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a microcity.");
	if(Bit_Get(cityruler, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {

		new target;
		if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /mandate [id] (Hint: Gives microcity commissioner permissions.)");
		if(target == INVALID_PLAYER_ID) {
			unformat(params, "i", target);
			if(!IsPlayerConnected(target) || IsPlayerNPC(target))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}
		if(city[target] != city[playerid]) return SFM(playerid, HEX_RED, "Error: %s is not in your microcity.", PlayerName(target));

		Bit_Let(citycommissioner, target);
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `citycommissioner` = 1 WHERE id = %d LIMIT 1",  CharacterSQL[target]);
		mysql_tquery(g_SQL, sql, "", "");

		SFM(playerid, HEX_FADE2, "You mandated %s to microcity comissioner!", PlayerName(target));
		SFM(target, HEX_FADE2, "%s mandated you to microcity commissioner!", PlayerName(playerid));

		new sendText[256];
        format(sendText, sizeof sendText, "AdmWarn: %s[%d] has mandated %s[%d] to microcity commissioner in %s.", PlayerName(playerid), playerid, PlayerName(target), target, cityInfo[city[playerid]][name]);
	    SendAdminMessage(HEX_LRED, sendText, true);
		
	}
	else SCM(playerid, HEX_RED, "Error: You need to be the microcity ruler to mandate commissioners.");
	return 1;
}

YCMD:countermand(playerid, params[], help) {
	if(city[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a microcity.");
	if(Bit_Get(cityruler, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {

		new target;
		if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /countermand [id] (Hint: Removes microcity commissioner permissions.)");
		if(target == INVALID_PLAYER_ID) {
			unformat(params, "i", target);
			if(!IsPlayerConnected(target) || IsPlayerNPC(target))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}
		if(city[target] != city[playerid]) return SFM(playerid, HEX_RED, "Error: %s is not in your microcity.", PlayerName(target));

		Bit_Vet(citycommissioner, target);
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `citycommissioner` = 0 WHERE id = %d LIMIT 1",  CharacterSQL[target]);
		mysql_tquery(g_SQL, sql, "", "");

		SFM(playerid, HEX_FADE2, "You countermanded %s in your microcity.", PlayerName(target));
		SFM(target, HEX_FADE2, "%s has countermanded you in your microcity.", PlayerName(playerid));

		new sendText[256];
        format(sendText, sizeof sendText, "AdmWarn: %s[%d] has countermanded %s[%d] in %s.", PlayerName(playerid), playerid, PlayerName(target), target, cityInfo[city[playerid]][name]);
	    SendAdminMessage(HEX_LRED, sendText, true);
		
	}
	else SCM(playerid, HEX_RED, "Error: You need to be the microcity ruler to countermand commissioners.");
	return 1;
}

YCMD:quitcity(playerid, params[], help) {
	if(city[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a microcity.");
	inline Dialog_city_quit(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response) {				
			new sendText[256];
			format(sendText, sizeof sendText, "** %s has left the microcity! **", PlayerName(Open_pid));
			foreach(new i : Player)
				if(city[Open_pid] == city[i] && i != Open_pid) {
					SCM(i, HEX_LGREEN, sendText);
				}
			SFM(Open_pid, HEX_YELLOW, "You left %s!", cityInfo[city[Open_pid]][name]);
			Bit_Vet(citycommissioner, Open_pid);
			Bit_Vet(cityruler, Open_pid);
			format(sendText, sizeof sendText, "AdmWarn: %s[%d] has quit microcity %s.", PlayerName(Open_pid), Open_pid, cityInfo[city[Open_pid]][name]);
			SendAdminMessage(HEX_LRED, sendText, true);
			city[Open_pid] = 0;
		}
	}	
	Dialog_ShowCallback(playerid, using inline Dialog_city_quit, DIALOG_STYLE_MSGBOX, "Microcity", "Are you sure you want to leave your microcity?\n\nNote: You will not be able to use microcity related commands.", "Confirm","Cancel");
	return 1;
}


YCMD:setcityruler(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");

	new targetid = INVALID_PLAYER_ID, tarcity;

	if(sscanf(params,"du", tarcity, targetid)) return SCM(playerid, HEX_FADE2,"Usage: /setcityruler [cityid] [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "ii", tarcity, targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	if(!CityExists(tarcity)) return SCM(playerid, HEX_RED, "Error: Invalid microcity.");

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `cityruler` = 0 WHERE cityId = %d", tarcity);
	mysql_tquery(g_SQL, sql, "", "");
	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `cityruler` = 1, `cityId` = %d WHERE id = %d LIMIT 1", tarcity, CharacterSQL[targetid]);
	mysql_tquery(g_SQL, sql, "", "");

	city[targetid] = tarcity;
	Bit_Let(cityruler, targetid);

	new string[256];
	format(string, sizeof string, "%s[%d] has given you city %s's ruling.", PlayerName(playerid), playerid, cityInfo[CityID(tarcity)][name]);
	format(string, sizeof string, "AdmWarn: %s[%d] has changed city %s's ruler to %s[%d].", PlayerName(playerid), playerid, cityInfo[CityID(tarcity)][name], PlayerName(targetid), targetid);
	SendAdminMessage(HEX_YELLOW, string, true);
	format(string, sizeof string, "%s[%d] has given you city %s's ruling.", PlayerName(playerid), playerid, cityInfo[CityID(tarcity)][name]);
	SCM(targetid, HEX_FADE2, string);
	return 1;
}

GetSQLCityname(fsql) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT name FROM `city`  WHERE id = '%d' LIMIT 1", fsql);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnval[128];
	if(cache_num_rows()) {
		cache_get_value(0, "name", returnval, sizeof(returnval));
	}
	else
		returnval = "NO_CITY";
	cache_delete(result);
	return returnval;
}

CityExists(c_sqlid) {
	foreach(new i:Microcities) {
		if(cityInfo[i][sqlid] == c_sqlid) return 1;
	}
	return 0;
}

CityID(c_sqlid) {
	foreach(new i:Microcities) {
		if(cityInfo[i][sqlid] == c_sqlid) return i;
	}

	return -1;
}