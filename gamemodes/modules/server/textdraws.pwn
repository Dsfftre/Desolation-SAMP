#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
	racetd[playerid] = CreatePlayerTextDraw(playerid, 491.000000, 101.000000, "Infected");
	PlayerTextDrawBackgroundColor(playerid, racetd[playerid], 255);
	PlayerTextDrawFont(playerid, racetd[playerid], 2);
	PlayerTextDrawLetterSize(playerid, racetd[playerid], 0.500000, 1.899999);
	PlayerTextDrawColor(playerid, racetd[playerid], -1);
	PlayerTextDrawSetOutline(playerid, racetd[playerid], 0);
	PlayerTextDrawSetProportional(playerid, racetd[playerid], 1);
	PlayerTextDrawSetShadow(playerid, racetd[playerid], 1);
	PlayerTextDrawHide(playerid, racetd[playerid]);

    return Y_HOOKS_CONTINUE_RETURN_1;
}


//ptask RactdTask[5000](playerid) {
ptask RactdTask[1000](playerid) {

	if(Bit_Get(togshud, playerid) && Bit_Get(character, playerid))
	{
		if(IsZombie(playerid))  
		{
			PlayerTextDrawHide(playerid, racetd[playerid]);
			PlayerTextDrawSetString(playerid, racetd[playerid], "~r~Zombie");
			if(Bit_Get(dead, playerid))
				PlayerTextDrawSetString(playerid, racetd[playerid], "~r~Zombie (Dead)");
			PlayerTextDrawShow(playerid, racetd[playerid]);
			
		}
		else if(Bit_Get(infected, playerid) && IsHuman(playerid))
		{
			PlayerTextDrawHide(playerid, racetd[playerid]);
			PlayerTextDrawSetString(playerid, racetd[playerid], "~y~Infected");
			if(Bit_Get(dead, playerid))
				PlayerTextDrawSetString(playerid, racetd[playerid], "~r~Infected (Dead)");
			PlayerTextDrawShow(playerid, racetd[playerid]);
		}
		else if(IsHuman(playerid))
		{
			PlayerTextDrawHide(playerid, racetd[playerid]);
			PlayerTextDrawSetString(playerid, racetd[playerid], "~w~Human");
			if(Bit_Get(dead, playerid))
				PlayerTextDrawSetString(playerid, racetd[playerid], "~r~Human (Dead)");
			PlayerTextDrawShow(playerid, racetd[playerid]);
		}
	}
}


/*

ptask TextdrawHudRefresh[2000](playerid)
{

	if(PlayerInfo[playerid][pInfected] == 0 && gTeam[playerid] == HUMAN)
	{
		PlayerTextDrawSetString(playerid, racetd[playerid], "Human");
	}
	else if(PlayerInfo[playerid][pInfected] >= 1 && gTeam[playerid] == HUMAN)
	{
		PlayerTextDrawSetString(playerid, racetd[playerid], "Infected");
	}
	else if(gTeam[playerid] == ZOMBIE)
	{
		PlayerTextDrawSetString(playerid, racetd[playerid], "Zombie");
	}

}
    

*/