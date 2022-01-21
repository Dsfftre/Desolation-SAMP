#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

new Iterator:Factions<MAX_FACTIONS+1>;
new BitArray:factionchat<MAX_FACTIONS+1>;

hook OnGameModeInit() {
	g_Factiontype[0] = Group_Create("Survivor");
	g_Factiontype[1] = Group_Create("Republic");
	g_Factiontype[2] = Group_Create("Bandit");
	g_Factiontype[3] = Group_Create("Merchant/Trader");
	LoadFactions();
	return Y_HOOKS_CONTINUE_RETURN_1;
}

LoadFactions() {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `faction` WHERE state > 0");
	inline LoadFactionData() {
		if(!cache_num_rows()) {
			print("No factions found.");
			@return 0;
		}
		new i = -1;
		for(;++i<cache_num_rows();) 
		{
			cache_get_value_int(i, "id", fInfo[i][sqlid]);
			cache_get_value(i, "name", fInfo[i][name], 128);
			g_Faction[i]  = Group_Create(fInfo[i][name]);
			cache_get_value_int(i, "type", fInfo[i][brand]);
			cache_get_value_int(i, "bank", fInfo[i][bank]);
			Bit_Let(factionchat, i);
			Iter_Add(Factions, i);
			printf("Faction %s (%d) loaded.", fInfo[i][name], fInfo[i][sqlid]);
		}
		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadFactionData, sql);
	return 1;
}

FactionID(f_sqlid) {
	foreach(new i:Factions) {
		if(fInfo[i][sqlid] == f_sqlid) return i;
	}

	return -1;
}

FactionExists(f_sqlid) {
	foreach(new i:Factions) {
		if(fInfo[i][sqlid] == f_sqlid) return 1;
	}
	return 0;
}

YCMD:factionhelp(playerid, params[], help) {
	if(faction[playerid] == 0)
		return SCM(playerid, HEX_RED, "Error: You do not have a faction.");

	SFM(playerid, HEX_BLUE, "[Faction Info] [SQLID:%d] [Name: %s] [Type: %s]", faction[playerid], fInfo[FactionID(faction[playerid])][name], Group_GetName(g_Factiontype[fInfo[FactionID(faction[playerid])][brand]]) );
	SCM(playerid, HEX_FADE2, "Faction commands: /f, /factionon, /togfam, /gates, /factionskin, /quitfaction");
	if(Bit_Get(factionleader, playerid) || Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {
		SCM(playerid, HEX_FADE2, "Leader commands: /invite, /remove, /togf, /setrank, /towcars");
	}
	if(Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {
		SCM(playerid, HEX_FADE2, "Owner commands: /promote, /demote");
	}
	if(Group_GetPlayer(g_AdminDuty, playerid)) {
		SCM(playerid, HEX_FADE2, "Admin commands: /factionname /setfactionowner /setfaction");
	}
	return 1;
}

YCMD:factions(playerid, params[], help) {
	
	new i = -1,
		string[MAX_FACTIONS*256],
		string2[256];

	format(string, sizeof string, "Name\tType\tOnline\n");
	for(;++i<MAX_FACTIONS;) {
		if(fInfo[i][sqlid] != 0) {
			new count = 0;
			foreach(new j:Player) {
				if(faction[j] == fInfo[i][sqlid])
					++count;
			}
			format(string2, sizeof string2, "%s (%d)\t%s\t%i members\n", fInfo[i][name], fInfo[i][sqlid], Group_GetName(g_Factiontype[fInfo[i][brand]]), count);
			if(count < 2)
				format(string2, sizeof string2, "%s (%d)\t%s\t%i member\n", fInfo[i][name], fInfo[i][sqlid], Group_GetName(g_Factiontype[fInfo[i][brand]]), count);
			strcat(string, string2);
		}
	}
	inline Empty(pid, dialogid, response, listitem, string:inputtext[]) {
        #pragma unused pid, dialogid, response, listitem, inputtext
    }
    Dialog_ShowCallback(playerid, using inline Empty, DIALOG_STYLE_TABLIST_HEADERS, "Official Factions", string, "Close");
	return 1;
}

YCMD:factionon(playerid, params[], help) {
	
	if(faction[playerid] == 0)
		return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	SFM(playerid, HEX_BLUE, "%s online members:",fInfo[FactionID(faction[playerid])][name]);
	new count = 0;
	foreach(new i : Player) {
		if(faction[playerid] == faction[i]) {
			if(Bit_Get(factionowner, i))
				SFM(playerid, HEX_FADE2, "(ID:%i) %s %s [owner]",i,factionrank[i],PlayerName(i));
			else if(Bit_Get(factionleader, i))
				SFM(playerid, HEX_FADE2, "(ID:%i) %s %s [leader]",i,factionrank[i],PlayerName(i));
			else
				SFM(playerid, HEX_FADE2, "(ID:%i) %s %s",i,factionrank[i],PlayerName(i));
			++count;
		}
	}
	if(count > 9)
		SFM(playerid, HEX_FADE2, "Total: %d", count);
	return 1;
}

YCMD:f(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	if(!Bit_Get(togfam, playerid))  return SCM(playerid, HEX_RED, "Error: Use /togfam to turn on your faction chat.");
	if(!Bit_Get(factionchat, FactionID(faction[playerid])))  return SCM(playerid, HEX_RED, "Error: The faction chat is currently disabled by the leadership.");

	new sendText[256];
	if(sscanf(params, "s[256]", sendText)) {
		SCM(playerid, HEX_FADE2, "Usage: /f [faction chat]");
		return 1;
	}
	
	format(sendText, sizeof sendText, "**(( %s %s: %s ))**", factionrank[playerid],PlayerName(playerid), sendText);
	foreach(new i : Player) 
	{
		if(faction[playerid] == faction[i] && Bit_Get(togfam, i)) 
		{
			SCM(i, HEX_BLUE, sendText);
		}
	}
	return 1;
}
/*
YCMD:fr(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	if(!Bit_Get(togfam, playerid))  return SCM(playerid, HEX_RED, "Error: Use /togfam to turn on your faction chat.");
	if(!Bit_Get(factionchat, faction[playerid]))  return SCM(playerid, HEX_RED, "Error: The faction chat is currently disabled by the leadership.");

	new sendText[256];
	if(sscanf(params, "s[256]", sendText)) {
		SCM(playerid, HEX_FADE2, "Usage: /fr [faction chat]");
		return 1;
	}
	
	format(sendText, sizeof(sendText), "** [R] %s %s: %s", factionrank[playerid], PlayerName(playerid), sendText);
	foreach(new i : Player) 
	{
		if(faction[playerid] == faction[i]) 
		{
			SCM(i, HEX_BLUE, sendText);
		}
	}
	return 1;
}*/

YCMD:togf(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	if(Bit_Get(factionleader, playerid) || Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {
		new sendText[256];
		if(Bit_Get(factionchat, FactionID(faction[playerid]))) {
			Bit_Vet(factionchat, FactionID(faction[playerid]));
			format(sendText, sizeof sendText, "** %s %s has turned off faction messages. **", factionrank[playerid],PlayerName(playerid));
			foreach(new i : Player) {
				if(faction[playerid] == faction[i] && Bit_Get(togfam, i)) {
					SCM(i, HEX_BLUE, sendText);
				}
			}
		}
		else {
			Bit_Let(factionchat, FactionID(faction[playerid]));
			format(sendText, sizeof sendText, "** %s %s has turned on faction messages. **", factionrank[playerid],PlayerName(playerid));
			foreach(new i : Player) {
				if(faction[playerid] == faction[i] && Bit_Get(togfam, i)) {
					SCM(i, HEX_BLUE, sendText);
				}
			}
		}
	}
	else SCM(playerid, HEX_RED, "Error: You need to be a faction leader/owner to toggle the faction chat.");
	return 1;
}

YCMD:togfam(playerid, params[], help) {
	if(Bit_Get(togfam, playerid)) {
		Bit_Vet(togfam, playerid);
		SCM(playerid, HEX_FADE2, "You turned off faction messages.");
	}
	else {
		Bit_Let(togfam, playerid);
		SCM(playerid, HEX_FADE2, "You turned on faction messages.");
	}
	return 1;
}


ShowFactionStats(playerid, targetid = -1) {
	if(targetid == -1)
		SFM(playerid, HEX_FADE2, "Faction | sqlid:[%d] name:[%s] rank:[%s] leader:[%d] owner:[%d]", faction[playerid], fInfo[FactionID(faction[playerid])][name], factionrank[playerid], onezero(Bit_Get(factionleader, playerid)), onezero(Bit_Get(factionowner, playerid)));
	else
		SFM(playerid, HEX_FADE2, "Faction | sqlid:[%d] name:[%s] rank:[%s] leader:[%d] owner:[%d]", faction[targetid], fInfo[FactionID(faction[targetid])][name], factionrank[targetid], onezero(Bit_Get(factionleader, targetid)), onezero(Bit_Get(factionowner, targetid)));
	return 1;
}

YCMD:invite(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	if(Bit_Get(factionleader, playerid) || Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) 
	{
		new target;
		if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /invite [id]");
		if(target == INVALID_PLAYER_ID) 
		{
			unformat(params, "i", target);
			if(!IsPlayerConnected(target) || IsPlayerNPC(target))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}
		if(playerid == target) return SCM(playerid, HEX_RED, "Error: You cannot invite yourself.");
		if(faction[target] == faction[playerid]) return SFM(playerid, HEX_RED, "Error: %s is already a member of your faction.", PlayerName(target));
		if(faction[target] > 0) {
			SFM(playerid, HEX_RED, "Error: %s is already a member of a faction.", PlayerName(target));
			SFM(target, HEX_FADE2, "%s[%d] could not faction-invite you, because you are already a faction member. Use /quitfaction if you want to quit your faction.", PlayerName(playerid), playerid);
			return 1;
		}
		new string[256];
		format(string, sizeof string, "%s has invited you to join %s!", PlayerName(playerid), fInfo[FactionID(faction[playerid])][name]);

		inline Dialog_faction_invite(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
			#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
			if(Open_response) {
				faction[Open_pid] = faction[playerid];
				new sendText[256];
				format(sendText, sizeof sendText, "** %s has joined the faction! **", PlayerName(Open_pid));
				foreach(new i : Player)
					if(faction[Open_pid] == faction[i] && i != Open_pid) {
						SCM(i, HEX_BLUE, sendText);
					}
				SFM(Open_pid, HEX_YELLOW, "You have joined %s!", fInfo[FactionID(faction[Open_pid])][name]);
				format(sendText, sizeof sendText, "AdmWarn: %s[%d] has invited %s[%d] into %s.", PlayerName(playerid), playerid, PlayerName(target), target, fInfo[FactionID(faction[playerid])][name]);
	   			SendAdminMessage(HEX_LRED, sendText, true);
				SCM(playerid, HEX_SAMP, "[Desolation] Use /factionhelp to see your faction commands!");

				mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `factionId` = '%d' WHERE id = '%d'  LIMIT 1", faction[Open_pid], CharacterSQL[Open_pid]);
				mysql_tquery(g_SQL, sql, "", "");
			}
			else {				
				SFM(playerid, HEX_FADE2, "%s has denied your faction invitation.", PlayerName(Open_pid));
				SFM(Open_pid, HEX_FADE2, "You denied %s's invitation to faction %s.", PlayerName(playerid), fInfo[FactionID(faction[playerid])][name]);
			}
		}	
		Dialog_ShowCallback(target, using inline Dialog_faction_invite, DIALOG_STYLE_MSGBOX, "Faction invite", string, "Accept","Deny");
	}
	else SCM(playerid, HEX_RED, "Error: You need to be a faction leader/owner to invite players.");
	return 1;
}

YCMD:remove(playerid, params[], help) {
	if(Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid) || Bit_Get(factionleader, playerid)) {
		if(faction[playerid] == 0 && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
		new target;
		if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /remove [id]");
		if(target == INVALID_PLAYER_ID) {
			unformat(params, "i", target);
			if(!IsPlayerConnected(target) || IsPlayerNPC(target))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}
		if(faction[target] != faction[playerid]) SFM(playerid, HEX_RED, "Error: %s is not in your faction.", PlayerName(target));
		if(Bit_Get(factionleader, target) && !Bit_Get(factionowner, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: Only faction owners can remove leaders.");

		faction[target] = 0;

		SFM(target, HEX_YELLOW, "%s removed you from %s.", PlayerName(playerid), fInfo[FactionID(faction[playerid])][name]);
		SFM(playerid, HEX_YELLOW, "You removed %s from your faction.", PlayerName(target));
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `factionLeader` = 0 WHERE id = %d LIMIT 1",  CharacterSQL[target]);
		mysql_tquery(g_SQL, sql, "", "");

		new sendText[256];
        format(sendText, sizeof sendText, "AdmWarn: %s[%d] has removed %s[%d] from %s.", PlayerName(playerid), playerid, PlayerName(target), target, fInfo[FactionID(faction[playerid])][name]);
	    SendAdminMessage(HEX_LRED, sendText, true);
		
	}
	else SCM(playerid, HEX_RED, "Error: You need to be a faction leader to remove members.");
	return 1;
}

YCMD:promote(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	if(Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {

		new target;
		if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /promote [id] (Hint: Gives faction leader permissions.)");
		if(target == INVALID_PLAYER_ID) {
			unformat(params, "i", target);
			if(!IsPlayerConnected(target) || IsPlayerNPC(target))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}
		if(faction[target] != faction[playerid]) return SFM(playerid, HEX_RED, "Error: %s is not in your faction.", PlayerName(target));

		Bit_Let(factionleader, target);
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `factionLeader` = 1 WHERE id = %d LIMIT 1",  CharacterSQL[target]);
		mysql_tquery(g_SQL, sql, "", "");

		SFM(playerid, HEX_FADE2, "You promoted %s to faction leader!", PlayerName(target));
		SFM(target, HEX_FADE2, "%s promoted you to faction leader!", PlayerName(playerid));

		new sendText[256];
        format(sendText, sizeof sendText, "AdmWarn: %s[%d] has promoted %s[%d] to faction leader in %s.", PlayerName(playerid), playerid, PlayerName(target), target, fInfo[FactionID(faction[playerid])][name]);
	    SendAdminMessage(HEX_LRED, sendText, true);
		
	}
	else SCM(playerid, HEX_RED, "Error: You need to be the faction owner to promote leaders.");
	return 1;
}

YCMD:demote(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	if(Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {

		new target;
		if(sscanf(params, "r", target)) return SCM(playerid, HEX_FADE2, "Usage: /demote [id] (Hint: Removes faction leader permissions.)");
		if(target == INVALID_PLAYER_ID) {
			unformat(params, "i", target);
			if(!IsPlayerConnected(target) || IsPlayerNPC(target))
				return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
		}
		if(faction[target] != faction[playerid]) return SFM(playerid, HEX_RED, "Error: %s is not in your faction.", PlayerName(target));

		Bit_Vet(factionleader, target);
		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `factionLeader` = 0 WHERE id = %d LIMIT 1",  CharacterSQL[target]);
		mysql_tquery(g_SQL, sql, "", "");

		SFM(playerid, HEX_YELLOW, "You demoted %s in your faction.", PlayerName(target));
		SFM(target, HEX_YELLOW, "%s has demoted you in your faction.", PlayerName(playerid));

		new sendText[256];
        format(sendText, sizeof sendText, "AdmWarn: %s[%d] has demoted %s[%d] in %s.", PlayerName(playerid), playerid, PlayerName(target), target, fInfo[FactionID(faction[playerid])][name]);
	    SendAdminMessage(HEX_LRED, sendText, true);
		
	}
	else SCM(playerid, HEX_RED, "Error: You need to be the faction owner to demote leaders.");
	return 1;
}

YCMD:quitfaction(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	inline Dialog_faction_quit(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) {
		#pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
		if(Open_response) {				
			new sendText[256];
			format(sendText, sizeof sendText, "** %s has left the faction! **", PlayerName(Open_pid));
			foreach(new i : Player)
				if(faction[Open_pid] == faction[i] && i != Open_pid) {
					SCM(i, HEX_BLUE, sendText);
				}
			Bit_Vet(factionleader, Open_pid);
			Bit_Vet(factionowner, Open_pid);
			SFM(Open_pid, HEX_YELLOW, "You left %s!", fInfo[FactionID(faction[Open_pid])][name]);
			format(sendText, sizeof sendText, "AdmWarn: %s[%d] has quit faction %s.", PlayerName(Open_pid), Open_pid, fInfo[FactionID(faction[Open_pid])][name]);
			SendAdminMessage(HEX_LRED, sendText, true);
			faction[Open_pid] = 0;
		}
	}	
	Dialog_ShowCallback(playerid, using inline Dialog_faction_quit, DIALOG_STYLE_MSGBOX, "Faction", "Are you sure you want to leave your faction?\n\nNote: You will not be able to use faction related commands.", "Confirm","Cancel");
	return 1;
}

YCMD:setfactionowner(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");

	new targetid = INVALID_PLAYER_ID, tarfaction;

	if(sscanf(params,"dr", tarfaction, targetid)) return SCM(playerid, HEX_FADE2,"Usage: /setfactionowner [factionid] [id]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "dd", tarfaction, targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}


	if(!FactionExists(tarfaction)) return SCM(playerid, HEX_RED, "Error: Invalid faction.");

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `factionOwner` = 0 WHERE factionId = %d", tarfaction);
	mysql_tquery(g_SQL, sql, "", "");

	foreach(new i:Player) {
		if(faction[i] == tarfaction)
			Bit_Vet(factionowner, i);
	}

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `factionOwner` = 1, `factionId` = %d WHERE id = %d LIMIT 1", tarfaction, CharacterSQL[targetid]);
	mysql_tquery(g_SQL, sql, "", "");

	faction[targetid] = tarfaction;
	Bit_Let(factionowner, targetid);

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has changed faction %s's owner to %s[%d].", PlayerName(playerid), playerid, fInfo[FactionID(tarfaction)][name], PlayerName(targetid), targetid);
	SendAdminMessage(HEX_YELLOW, string, true);
	format(string, sizeof string, "%s[%d] has given you faction %s's ownership.", PlayerName(playerid), playerid, fInfo[FactionID(tarfaction)][name]);
	SCM(targetid, HEX_FADE2, string);
	
	return 1;
}

YCMD:setrank(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	new target = INVALID_PLAYER_ID, rank[32];
	if(sscanf(params,"us[32]", target, rank)) return SCM(playerid, HEX_FADE2,"Usage: /setrank [playerid] [faction rank] (Hint: Max 32 characters.)");
	if(target == INVALID_PLAYER_ID) {
		unformat(params, "is[32]", target, rank);
		if(!IsPlayerConnected(target) || IsPlayerNPC(target))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}
	
	
	if(Bit_Get(factionleader, playerid) || Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {

		if(faction[target] != faction[playerid]) return SFM(playerid, HEX_RED, "Error: %s is not in your faction.", PlayerName(target));

		factionrank[target] = rank;

		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `player` SET `rank` = '%e' WHERE id = %d", rank, CharacterSQL[target]);
		mysql_tquery(g_SQL, sql, "", "");

		SFM(playerid, HEX_YELLOW, "You set %s's rank to %s.", PlayerName(target), rank);
		SFM(target, HEX_YELLOW, "%s has set your rank to %s.", PlayerName(playerid), rank);

		new sendText[256];
        format(sendText, sizeof sendText, "AdmWarn: %s[%d] has set %s[%d]'s rank to %s.", PlayerName(playerid), playerid, PlayerName(target), target, rank);
	    SendAdminMessage(HEX_LRED, sendText, true);
		
	}
	else SCM(playerid, HEX_RED, "Error: You need to be a faction leader/owner to set ranks.");
	return 1;
}


GetSQLFactionname(fsql) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT name FROM `faction`  WHERE id = '%d' LIMIT 1", fsql);
	new Cache:result = mysql_query(g_SQL, sql);
	new returnval[128];
	if(cache_num_rows()) {
		cache_get_value(0, "name", returnval, sizeof(returnval));
	}
	else
		returnval = "NO_FACTION";
	cache_delete(result);
	return returnval;
}

YCMD:factionskin(playerid, params[], help) {
	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");
	if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");
	OpenFactionSkin(playerid, faction[playerid]);
	return 1;
}

OpenFactionSkin(playerid, factionid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `privateskins` WHERE factionId = '%d' AND state = 1", factionid);
	inline LoadPrivateSkins() 
	{
		if(!cache_num_rows()) 
		{
			SCM(playerid, HEX_FADE2, "This faction has no private skins.");
			@return 0;
		}

		new pskin[MAX_PRIVATE_SKINS];
		new pskinname[MAX_PRIVATE_SKINS][64];
		new string[64*MAX_PRIVATE_SKINS] = "Name\tid\n";
		
        new i = -1;
		for(;++i<cache_num_rows();) 
		{
			if(i >= MAX_PRIVATE_SKINS) 
			{
				printf("Faction %d has more private skins (%d) than the current maximum %d. Increase MAX_PRIVATE_SKINS defined value!", factionid, cache_num_rows(), MAX_PRIVATE_SKINS);
				break;
			}
			cache_get_value(i, "name", pskinname[i], 64);
			cache_get_value_int(i, "skinid", pskin[i]);
			new tmpstr[128];
			format(tmpstr, sizeof tmpstr, "%s\t%d\n", pskinname[i], pskin[i]);
			strcat(string, tmpstr);
		}
		
		inline selectFactionSkin(pid, dialogid, response, listitem, string:inputtext[]) 
		{
			#pragma unused pid, dialogid, response, listitem, inputtext
			if(response) {
				if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    			if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");

				SetPlayerSkin(playerid, pskin[listitem]);
				p_skin[playerid] = pskin[listitem];

			}
		}
		Dialog_ShowCallback(playerid, using inline selectFactionSkin, DIALOG_STYLE_TABLIST_HEADERS, "Faction skin selector", string, "Select", "Close");


		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadPrivateSkins, sql);

	return 1;
}


YCMD:towcars(playerid, params[], help) {

	if(faction[playerid] == 0) return SCM(playerid, HEX_RED, "Error: You do not have a faction.");

	if(Bit_Get(factionleader, playerid) || Bit_Get(factionowner, playerid) || Group_GetPlayer(g_AdminDuty, playerid)) {

		new i;
		foreach(i : Cars) {
			if(!IsValidVehicle(i)) continue;
			new j = FindVehicle(i);
			if(VehicleInfo[j][factionId] == faction[playerid]) {
				if(!IsVehicleOccupied(i)) {
					SetVehicleToRespawn(i);
					RepairVehicle(i);
					SetVehicleHealth(i, VehicleInfo[j][vhealth]);
				}
			}
		}

		new sendText[256];
		format(sendText, sizeof sendText, "** %s has towed all faction vehicles! **", PlayerName(playerid));
		foreach(i : Player)
			if(faction[playerid] == faction[i]) {
				SCM(i, HEX_BLUE, sendText);
			}


	}
	else SCM(playerid, HEX_RED, "Error: You need to be a faction leader/owner to tow faction vehicles.");

	return 1;
}


YCMD:factionname(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");

	new tarfaction, facname[128];

	if(sscanf(params,"ds[128]", tarfaction, facname)) return SCM(playerid, HEX_FADE2,"Usage: /factionname [factionid] [name] (Hint: Name can contain maximum 128 characters.)");


	if(!FactionExists(tarfaction)) return SCM(playerid, HEX_RED, "Error: Invalid faction.");

	mysql_format(g_SQL, sql, sizeof sql, "UPDATE `faction` SET `name` = '%e' WHERE id = %d", facname, tarfaction);
	mysql_tquery(g_SQL, sql, "", "");

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has changed faction %s's name to %s", PlayerName(playerid), playerid, fInfo[FactionID(tarfaction)][name], facname);
	SendAdminMessage(HEX_YELLOW, string, true);

	new fid = FactionID(tarfaction);

	format(fInfo[fid][name], 128, "%s", facname);

	format(string, sizeof string, "** %s %s has changed the faction's name to %s. **", AdminNames[adminlevel[playerid]], PlayerName(playerid), facname);
	foreach(new i : Player) {
		if(tarfaction == faction[i] && Bit_Get(togfam, i)) {
			SCM(i, HEX_BLUE, string);
		}
	}
	
	return 1;
}

YCMD:setfaction(playerid, params[], help) {
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You must be on admin duty.");
	if(adminlevel[playerid] < 5) return SCM(playerid, HEX_RED, "Error: This command is restricted to level 5 admins.");

	new targetid = INVALID_PLAYER_ID, tarfaction;

	if(sscanf(params,"rd", targetid, tarfaction)) return SCM(playerid, HEX_FADE2,"Usage: /setfaction [id] [factionid]");
	if(targetid == INVALID_PLAYER_ID) {
		unformat(params, "dd", tarfaction, targetid);
		if(!IsPlayerConnected(targetid) || IsPlayerNPC(targetid))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(!FactionExists(tarfaction)) return SCM(playerid, HEX_RED, "Error: Invalid faction.");

	faction[targetid] = tarfaction;
	Bit_Let(togfam, targetid);

	new string[256];
	format(string, sizeof string, "AdmWarn: %s[%d] has set %s[%d]'s faction to %s", PlayerName(playerid), playerid, PlayerName(targetid), targetid, fInfo[FactionID(tarfaction)][name]);
	SendAdminMessage(HEX_YELLOW, string, true);

	format(string, sizeof string, "** %s %s has invited %s[%d] to the faction. **", AdminNames[adminlevel[playerid]], PlayerName(playerid), PlayerName(targetid), targetid);
	foreach(new i : Player) {
		if(tarfaction == faction[i] && Bit_Get(togfam, i)) {
			SCM(i, HEX_BLUE, string);
		}
	}



	return 1;
}
