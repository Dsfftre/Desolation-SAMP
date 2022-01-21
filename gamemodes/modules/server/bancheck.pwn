#include <YSI_Coding\y_hooks>

new g_MysqlRaceCheck[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    g_MysqlRaceCheck[playerid]++;

    if(!IsPlayerNPC(playerid))
    {
        TogglePlayerSpectating(playerid, true);
        defer SpawnCamera(playerid);
        IP_Lookup(playerid);
	    Account_Lookup(playerid);
        if(IsRPName(PlayerName(playerid))) 
        {
            SCM(playerid, HEX_FADE2, "Please rejoin with a master account name, since you can have multiple characters. (Have no underscore like _ in your name as you connect!)");
            KickPlayer(playerid);
            return Y_HOOKS_BREAK_RETURN_1;
        }
        HidePlayerMarkers(playerid);
        SetPlayerColor(playerid, COLOR_FADE2);	
    }
    PlayAudioStreamForPlayer(playerid, "https://ds-rp.com/ambience.mp3");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

IP_Lookup(playerid)
{
    new ip[18];
    GetPlayerIp(playerid, ip, sizeof(ip));
	mysql_format(g_SQL, sql, sizeof(sql), "SELECT * FROM bans WHERE IP = '%e' LIMIT 1", ip);
	mysql_tquery(g_SQL, sql, "Lookup_Result", "d", playerid);
	return 1;
}

Account_Lookup(playerid)
{
	mysql_format(g_SQL, sql, sizeof(sql), "SELECT * FROM bans WHERE A_ID = %d LIMIT 1", AccountSQL[playerid]);
	mysql_tquery(g_SQL, sql, "Lookup_Result", "d", playerid);
	return 1;
}

forward Lookup_Result(playerid);
public Lookup_Result(playerid)
{
    if(cache_num_rows())
    {
        SCM(playerid, HEX_SAMP, "You are banned from the server.");
        SCM(playerid, HEX_SAMP, "Make a ban appeal on forums.ds-rp.com");
	    KickPlayer(playerid);
	    return 0;
	}
    else
    {
        AccountLogin(playerid);
    }
	return 1;
}