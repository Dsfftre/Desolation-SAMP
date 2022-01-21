YCMD:giveitem(playerid, params[], help) { //debug cmd
	if(adminlevel[playerid] < 4) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new target,	itemid,	amount;
	if(sscanf(params,"udd", target, itemid, amount)) return SCM(playerid, HEX_FADE2, "Usage: /giveitem [id] [item] [amount]");
	if(target == INVALID_PLAYER_ID)  {
		unformat(params, "i", target);
		if(!IsPlayerConnected(target) || IsPlayerNPC(target))
			return SCM(playerid, HEX_RED, "Error: Invalid playerid. (Using an id might work.)");
	}

	if(IsStackingItem(itemid))
	{
		GivePlayerItem(target, itemid, amount);
	}
	else 
	{
		new i = -1;
		for(;++i<amount;)
		GivePlayerItem(target, itemid, 1);
	}

	new string[128];
	format(string, sizeof string, "[LOG]: %s has given %s %s(x%d).", PlayerName(playerid), PlayerName(target), GetItemName(itemid), amount);
	SendAdminMessage(HEX_YELLOW, string, true);
	SFM(target, HEX_FADE2, "You received %s(x%d) from admin %s.", GetItemName(itemid), amount, PlayerName(playerid));
	//AdminLog(string);
	return 1;
}