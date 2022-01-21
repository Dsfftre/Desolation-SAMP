#include <YSI_Coding\y_hooks>

new AdminNames[][] =
{
	"None",
	"Trial Moderator",
	"Moderator",
	"Trial Administrator",
	"Administrator",
	"Senior Administrator",
	"Developer"
};

hook OnGameModeInit() {
	g_Admin = Group_Create("admins");
	g_HiddenAdmin = Group_Create("hiddenadmins");
	g_AdminDuty = Group_Create("adminduty");


	new cmd = Command_GetID("a");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("slap");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("goto");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("listitems");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("respawn");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("debug");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("gotocar");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("getcar");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("gotobot");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("getbot");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("at");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("z");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("testerduty");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);

	cmd = Command_GetID("adminduty");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("addactor");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("giveitem");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("edititem");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("createcar");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("savecar");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("createinterior");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("addloot");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("addmine");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("addsearch");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("checkweapons");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("checkinventory");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("newterritory");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("setcorner");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
	
	cmd = Command_GetID("territorycp");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
	
	cmd = Command_GetID("setfactionowner");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
	
	cmd = Command_GetID("ooc");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("zombierace");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("addzombie");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("addguard");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("feed");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("turnzombie");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("freeze");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("unfreeze");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
	
	cmd = Command_GetID("gotoxyz");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
	
	cmd = Command_GetID("movex");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("movey");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("movez");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("ah");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("checkstats");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("ban");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("unban");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("setadmin");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("afly");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("gotointerior");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	
	cmd = Command_GetID("gotoint");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("gotosafe");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("saveintint");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("saveintstore");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("saveintfaction");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
	
	cmd = Command_GetID("saveintowner");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("patricle");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
		
	cmd = Command_GetID("saveintvw");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);
			
	cmd = Command_GetID("saveintoutvw");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("spec");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("specoff");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("changeweather");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("weatherlist");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("namechange");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("mine");
	Group_SetGlobalCommand(cmd, true);
	Group_SetCommand(g_Admin, cmd, false);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("craft");
	Group_SetGlobalCommand(cmd, true);
	Group_SetCommand(g_Admin, cmd, false);
	Group_SetCommand(g_HiddenAdmin, cmd, false);

	cmd = Command_GetID("setvw");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	cmd = Command_GetID("setinterior");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);

	
	cmd = Command_GetID("givepackage");
	Group_SetGlobalCommand(cmd, false);
	Group_SetCommand(g_Admin, cmd, true);
	Group_SetCommand(g_HiddenAdmin, cmd, true);


	Command_AddAltNamed("checkinventory", "checkinv");

	Command_AddAltNamed("spec", "awp");

	Command_AddAltNamed("setinterior", "setint");

	Command_AddAltNamed("adminduty", "aduty");

	Command_AddAltNamed("changeweather", "setweather");
	
	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:ah(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(adminlevel[playerid] >= 1)
	{
		SCM(playerid, HEX_GREEN,"Trial Moderator: >> /cmdlist << /a /adminduty /goto /gotoxyz /gethere /gotobot /getbot /slap /checkweapons /z /freeze /unfreeze /checkstats /revive /debug /respawn /notify /reportwarn /whois /particle /factionhelp /checkradio");
		//printf("opened dialog");
	}
	if(adminlevel[playerid] >= 2)
	{
		SCM(playerid, HEX_LGREEN ,"Moderator: /makehuman /makezombie /fixcar /spec /specoff /changeweather /towallcars /gotoint /gotosafe");
	}
	if(adminlevel[playerid] >= 3)
	{
		SCM(playerid, HEX_RED,"Trial Administrator: /namechange /feed /saveintint, /saveintout, /saveintfaction, /saveintcity, /saveintowner, /saveintstore, /saveintvw, /saveintoutvw");
	}
	if(adminlevel[playerid] >= 4)
	{
		SCM(playerid, HEX_ORANGE,"Administrator: /createinterior /giveitem /listitems /zombierace");
	}
	if(adminlevel[playerid] >= 5)
	{
		SCM(playerid, HEX_CYAN,"Senior Administrator: /setfaction /setfactionowner /factionname /addzombie /addguard (dont use these on live server) /aterritoryhelp");
	}
	if(adminlevel[playerid] >= 6)
	{
		SCM(playerid, HEX_FADE2,"Developer: /edititem /additem /addloot");
	}
	if(adminlevel[playerid] == -1)
	{
		SCM(playerid, HEX_LGREEN ,"Hidden Admin: >> /cmdlist << /a /kick /ban /slap /goto /checkstats /checkweapons /checkinventory /changeweather /debug /respawn");
	}
	return 1;
}

SendAdminMessage(iColor[], message[], bool:adminduty = false) {
	new msg_anyone = false;
	if(adminduty) 
	{
		foreach(new j : GroupMember[g_AdminDuty]) 
		{
			SCM(j, iColor, message);
			msg_anyone = true;
		}
	}
	else 
	{
		foreach(new j : GroupMember[g_Admin]) 
		{
			SCM(j, iColor, message);
			msg_anyone = true;
		}
		foreach(new k : GroupMember[g_HiddenAdmin]) 
		{
			SCM(k, iColor, message);
			msg_anyone = true;
		}
	}
	return msg_anyone;
}

hook OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart)
{
	if(Group_GetPlayer(g_AdminDuty, playerid)) 
	{
		new Float:c_hp;
		GetPlayerHealth(playerid, c_hp);
		SetPlayerHealth(playerid, c_hp+amount+25.0);

        if(FCNPC_IsValid(issuerid))
		FCNPC_StopAim(issuerid);

        else if(playerid != issuerid)
        GameTextForPlayer(issuerid, "~g~~b~Admin on duty", 1500, 5);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason) {
	if(adminlevel[playerid] > 0) 
	{
		new countadmins = 0;
		foreach(new i : GroupMember[g_Admin]) 
		{
			++countadmins;
		}
		if(countadmins == 1) 
		{
	    	SendAdminMessage(HEX_LRED, "AdmWarn: You are the only admin online.");
		}
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ) {
	if(Group_GetPlayer(g_AdminDuty, playerid)) 
	{
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerInterior(playerid, 0);
		new Float:mapZ;
		CA_FindZ_For2DCoord(fX, fY, mapZ);
		if(!IsPlayerInAnyVehicle(playerid)) 
		{
			SetPlayerPos(playerid, fX, fY, mapZ+0.5);
		}
		else {
			SetVehiclePos(GetPlayerVehicleID(playerid), fX, fY, mapZ+1.0);
			SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), 0);
			LinkVehicleToInterior(GetPlayerVehicleID(playerid), 0);
		}
		SetCameraBehindPlayer(playerid);
		ChangeMaskVW(playerid);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDeath(playerid, killerid, reason) {
	if(IsPlayerNPC(playerid)) return Y_HOOKS_CONTINUE_RETURN_1;
	if(!Bit_Get(dead, playerid))
		SetPlayerHealth(playerid, 0.0);
	new sendText[256];
	if(GetPVarInt(playerid, "killedby") != -1 && IsPlayerConnected(GetPVarInt(playerid, "killedby"))) format(sendText, sizeof sendText, "AdmWarn: %s[%d] has been killed by %s[%d], weapon: %s.", PlayerName(playerid), playerid, PlayerName(GetPVarInt(playerid, "killedby")), GetPVarInt(playerid, "killedby"), DeathReason(GetPVarInt(playerid, "weaponby")));
	else if(killerid != INVALID_PLAYER_ID) format(sendText, sizeof sendText, "AdmWarn: %s[%d] has been killed by %s[%d], weapon: %s.", PlayerName(playerid), playerid, PlayerName(killerid), killerid, DeathReason(reason));
	else format(sendText, sizeof sendText, "AdmWarn: %s[%d] has died. Reason: %s.", PlayerName(playerid), playerid, DeathReason(reason));
	SendAdminMessage(HEX_LRED, sendText, true);
	if(adminlevel[playerid] == -1)
		SCM(playerid, HEX_LRED, sendText);
	if(IsHuman(playerid)) 
	{
		DeletePVar(playerid, "killedby");
		DeletePVar(playerid, "weaponby");
	}
	//AdminLog(sendText);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnVehicleDeath(vehicleid, killerid) {
	printf("debug OnVehicleDeath(vehicleid %d killerid %d)", vehicleid, killerid);
	new sendText[256];
	if(killerid == INVALID_PLAYER_ID) format(sendText, sizeof sendText, "AdmWarn: Vehicle %d has been destroyed.", vehicleid);
	else format(sendText, sizeof sendText, "AdmWarn: Vehicle [%d] has been destroyed, synced by: %s[%d].", vehicleid, PlayerName(killerid), killerid);
	SendAdminMessage(HEX_LRED, sendText, true);
	return Y_HOOKS_CONTINUE_RETURN_1;
}

YCMD:admins(playerid, params[], help) {
	new bool:onlineadmins = false;
	foreach(new j : GroupMember[g_Admin]) 
	{
		if(onlineadmins == false) 
		{
			SCM(playerid, HEX_FADE2, "Admins Online:");
			onlineadmins = true;
		}
		if(Group_GetPlayer(g_AdminDuty, j))
		{
			SFM(playerid, HEX_GREEN, "(%s) %s (%s) - ON DUTY", AdminNames[adminlevel[j]], PlayerName(j), accountname[j]);
		}
		else
		{
			SFM(playerid, HEX_FADE2, "(%s) %s (%s) - OFF DUTY", AdminNames[adminlevel[j]], PlayerName(j), accountname[j]);
		}
	}
	if(onlineadmins == false)
	{
		SCM(playerid, HEX_FADE2, "There are no administrators online.");
	}
	if(adminlevel[playerid] != 0) 
	{
		onlineadmins = false;
		foreach(new j : GroupMember[g_HiddenAdmin]) 
		{
			if(onlineadmins == false) 
			{
				SCM(playerid, HEX_FADE2, "Hidden Admins:");
				onlineadmins = true;
			}
			SFM(playerid, HEX_FADE2, "(Level:%i) %s (%s) (ID:%i)", adminlevel[j], PlayerName(j), accountname[j], j);
		}
	}
	return 1;
}

YCMD:ooc(playerid, params[], help) {
	new text[256],string[256];
	if(sscanf(params, "s[256]",text)) return SCM(playerid, HEX_FADE2, "Usage: /ooc [message]");
	format(string, sizeof string, "[OOC] [%i]%s: %s", playerid, PlayerName(playerid), text);
	foreach(new i: Player) {
		SCM(i, HEX_SAMP, string);
	}
	return 1;
}