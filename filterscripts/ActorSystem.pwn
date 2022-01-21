/*
||| ACTOR system made by Pizza. |||
Commands are:
/spawnactor [skin id] [Vulnerability (0: invulnerable / 1: vulnerable)] > spawns the actor where the player is facing
/removeactor [actor id] (id can be viewed if went near him or /allactors) > removes specified actor
/removeallactors > clears all actors
/gotoactor [actor id] > TP you to the actor's POS (position)
/setactoranim [animation name] > Set an anim on actor
/cancelactoranim [actor id] > cancels the anim that has been excuted on the actor
/actorstext > shows/hides all actors text
/updateactor [actor id] [skin id] [vulnerability] > updates specified actor's skin and vulnerability (Also updates rotation, view where you want and apply command!)

NOTE: Make sure you are logged in as RCON admin else it will return 0 (unknown command)
*/

#include <a_samp>
#include <zcmd>
#include <sscanf2>
#include <a_actor>

///////////////////////////////////////////////////
public OnFilterScriptInit()
{
	print("\n____________________________________________________");
	print("___________Actor system by Pizza__________");
	print("____________________________________________________\n");
	return 1;
}

///////////////////////////////////////////////////
//COLORS
#define COLOR_GREEN 0x33AA33AA
#define COLOR_RED 0xFF0000AA
#define COLOR_PURPLE 0x800080FF
#define COLOR_YELLOW 0xFFFF00AA
#define COLOR_GREEN 0x33AA33AA
///////////////////////////////////////////////////
#define FILTERSCRIPT
#define DIALOG_ACTORHELP 666
#define MAX_LABELS 1000
///////////////////////////////////////////////////
/*
If your actor's vulnrability is off(0), when you shoot him in the knees or his health is <= 30 he will do animation "injured"
and when you shoot him in the head or his health is 0 he will do death animation.
*/
enum ActorSt
{
	Dead,
	Injured
}
new ActorState[MAX_ACTORS][ActorSt];
public OnPlayerGiveDamageActor(playerid, damaged_actorid, Float: amount, weaponid, bodypart)
{
	new Float:ahealth;
	GetActorHealth(damaged_actorid,ahealth);
 	SetActorHealth(damaged_actorid,ahealth-amount);
 	if(ActorState[damaged_actorid][Injured] == 0)
 	{
    	if(ahealth <= 30 && ahealth > 0 || bodypart == 7 || bodypart == 8)
    	{
        	ApplyActorAnimation(damaged_actorid, "SWEET", "Sweet_injuredloop", 4.1, 1, 0, 0, 0, 0);
			ApplyActorAnimation(damaged_actorid, "SWEET", "Sweet_injuredloop", 4.1, 1, 0, 0, 0, 0);
			ActorState[damaged_actorid][Injured] = 1;
			if(ahealth == 0) return ClearActorAnimations(damaged_actorid);
		}
	}
	if(ActorState[damaged_actorid][Dead] == 0)
	{
		if(bodypart == 9 || ahealth <= 0)
		{
	    	SetActorHealth(damaged_actorid,0);
	    	ApplyActorAnimation(damaged_actorid,"KNIFE","KILL_Knife_Ped_Die",4.1, 0, 0, 0, 1, 0);
	    	ActorState[damaged_actorid][Dead] = 1;
		}
	}
    return 1;
}
///////////////////////////////////////////////////
enum _labels
{
	Text3D: label_ID,
	label_text[128],
	Float: label_pos[3]
}
new
	aLabels[MAX_LABELS][_labels];

stock ClearLabel(labelid)
{
	if(labelid == INVALID_3DTEXT_ID)
		return 0;

	Delete3DTextLabel(aLabels[labelid][label_ID]);

	aLabels[labelid][label_ID] = Text3D: INVALID_3DTEXT_ID;

	aLabels[labelid][label_pos][0] = 0.0;
	aLabels[labelid][label_pos][1] = 0.0;
	aLabels[labelid][label_pos][2] = 0.0;

	aLabels[labelid][label_text][0] = EOS;
	return 1;
}

new ActorText[MAX_ACTORS];
/////////////////////////////////////////////////////////////
//                        COMMANDS
/////////////////////////////////////////////////////////////
CMD:spawnactor(playerid, params[])
{
	if(IsPlayerAdmin(playerid)){
	new Float:Pos[3],skinid,str[256],invulnerability,Float:Angle;
    if(sscanf(params,"il",skinid,invulnerability)) return SendClientMessage(playerid,COLOR_PURPLE,"USAGE: /spawnactor [skinid] [Vulnerability (0: invulnerable / 1: vulnerable)]");
    if(skinid > 311 || skinid < 0) return SendClientMessage(playerid,COLOR_RED,"Invalid skin id!");
    if(invulnerability != 1 && invulnerability != 0) return SendClientMessage(playerid,COLOR_RED,"Vulnerability (0: invulnerable / 1: vulnerable)");
    GetPlayerPos(playerid,Pos[0],Pos[1],Pos[2]);
    GetPlayerFacingAngle(playerid, Angle);
	new Actor = CreateActor(skinid, Pos[0], Pos[1], Pos[2], 0);
	SetPlayerPos(playerid,Pos[0]+1,Pos[1]+1,Pos[2]);
    SetActorFacingAngle(Actor, Angle);
	format(str,sizeof(str),"Actor %d was created! Pos: x[%f], y[%f], z[%f]",Actor,Pos[0],Pos[1],Pos[2]);
	SendClientMessage(playerid,COLOR_GREEN,str);
 	new str2[256];
	format(str2,sizeof(str2),"Actor ID: %d",Actor);
	aLabels[Actor][label_ID] = Create3DTextLabel(str2, COLOR_YELLOW, Pos[0], Pos[1], Pos[2], 10, 0, 0);
	aLabels[Actor][label_pos][0] = Pos[0];
	aLabels[Actor][label_pos][1] = Pos[1];
	aLabels[Actor][label_pos][2] = Pos[2];
 	if(invulnerability == 0)
    {
        SetActorInvulnerable(Actor, 1);
        SendClientMessage(playerid,COLOR_GREEN,"This actor is invulnerable!");
	}
	else if(invulnerability == 1)
	{
	    SetActorHealth(Actor, 100);
	    SetActorInvulnerable(Actor,0);
	    SendClientMessage(playerid,COLOR_GREEN,"This actor is vulnerable!");
	}
	for(new i = 0, j = GetActorPoolSize(); i <= j; i++)
    {
        if(ActorText[i] == 1)
        {
			ActorText[Actor] = 1;
		}
		else if(ActorText[i] == 0)
		{
			ActorText[Actor] = 0;
			ClearLabel(Actor);
		}
    }
    ActorState[Actor][Dead] = 0;
    ActorState[Actor][Injured] = 0;
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:removeactor(playerid, params[])
{
	if(IsPlayerAdmin(playerid)){
	new actorid,str[256];
    if(sscanf(params,"i",actorid)) return SendClientMessage(playerid,COLOR_PURPLE,"USAGE: /removeactor [actor id]");
    format(str,sizeof(str),"Actor %d was removed!",actorid);
    if(IsValidActor(actorid))
    {
        SendClientMessage(playerid,COLOR_GREEN,str);
        DestroyActor(actorid);
        ClearLabel(actorid);
	}
	else return SendClientMessage(playerid,COLOR_RED,"Invalid actor id!");
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:removeallactors(playerid, params[])
{
	if(IsPlayerAdmin(playerid)){
    for(new i = 0, j = GetActorPoolSize(); i <= j; i++)
    {
        if(IsValidActor(i))
        {
            DestroyActor(i);
            ClearLabel(i);
        }
    }
    }
    else return 0;
    return 1;
}
///////////////////////////////////////////////////
CMD:gotoactor(playerid, params[])
{
	if(IsPlayerAdmin(playerid)){
    new Float:Pos[3],actorid,str[256];
    if(sscanf(params,"i",actorid)) return SendClientMessage(playerid,COLOR_PURPLE,"USAGE: /gotoactor [actor id]");
    if(IsValidActor(actorid))
	{
		GetActorPos(actorid,Pos[0],Pos[1],Pos[2]);
		SetPlayerPos(playerid,Pos[0]+1,Pos[1],Pos[2]);
		format(str,sizeof(str),"You have been teleported to actor %d!",actorid);
		SendClientMessage(playerid,COLOR_GREEN,str);
	}
	else return SendClientMessage(playerid,COLOR_RED,"Invalid actor id!");
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:allactors(playerid, params[])
{
	if(IsPlayerAdmin(playerid)){
	new str[400];
	SendClientMessage(playerid,COLOR_RED,"_______________________________________________");
    for(new i = 0, j = GetActorPoolSize(); i <= j; i++)
    {
        if(IsValidActor(i))
        {
            format(str,sizeof(str),"Actor: %d | vulnerability: %d",i,!IsActorInvulnerable(i));
            SendClientMessage(playerid,COLOR_GREEN,str);
        }
        else
		{
		    SendClientMessage(playerid,COLOR_RED,"-");
		    continue;
		}
    }
    SendClientMessage(playerid,COLOR_RED,"_______________________________________________");
    }
    else return 0;
    return 1;
}
///////////////////////////////////////////////////
CMD:setactoranim(playerid, params[])
{
	if(IsPlayerAdmin(playerid)){
	new animation[256],actorid,str[256];
	if(sscanf(params,"is[100]",actorid,animation)) return SendClientMessage(playerid,COLOR_PURPLE,"USAGE: /setactoranim [actor id] [animation]");
	if(IsValidActor(actorid))
	{
		if(!strcmp(animation, "injured"))
		{
			ApplyActorAnimation(actorid, "SWEET", "Sweet_injuredloop", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "handsup"))
		{
			ApplyActorAnimation(actorid, "SHOP", "SHP_Rob_HandsUp", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
  		}
		if(!strcmp(animation, "sit"))
		{
			ApplyActorAnimation(actorid, "BEACH", "ParkSit_M_loop", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "lean"))
		{
			ApplyActorAnimation(actorid, "GANGS", "leanIDLE", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "dance"))
		{
			ApplyActorAnimation(actorid, "DANCING", "dance_loop", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "dealstance"))
		{
			ApplyActorAnimation(actorid, "DEALER", "DEALER_IDLE", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "riotchant"))
		{
			ApplyActorAnimation(actorid, "RIOT", "RIOT_CHANT", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "wave"))
		{
			ApplyActorAnimation(actorid, "ON_LOOKERS", "wave_loop", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "hide"))
		{
			ApplyActorAnimation(actorid, "ped", "cower", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "crossarms"))
		{
			ApplyActorAnimation(actorid, "COP_AMBIENT", "Coplook_loop", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "laugh"))
		{
			ApplyActorAnimation(actorid, "RAPPING", "Laugh_01", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "talk"))
		{
			ApplyActorAnimation(actorid, "PED", "IDLE_CHAT", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "fucku"))
		{
			ApplyActorAnimation(actorid, "PED", "fucku", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "tired"))
		{
			ApplyActorAnimation(actorid, "PED", "IDLE_tired", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
		if(!strcmp(animation, "chairsit"))
		{
			ApplyActorAnimation(actorid, "PED", "SEAT_idle", 4.1, 1, 0, 0, 0, 0);
			format(str,sizeof(str),"Applied animation '%s' on Actor %d",animation,actorid);
			SendClientMessage(playerid,COLOR_GREEN,str);
		}
	}
	else return SendClientMessage(playerid,COLOR_RED,"Invalid actor id!");
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:cancelactoranim(playerid, params[])
{
	if(IsPlayerAdmin(playerid)){
	new actorid;
	if(sscanf(params,"i",actorid)) return SendClientMessage(playerid,COLOR_PURPLE,"USAGE: /cancelactoranim [actor id]");
	if(IsValidActor(actorid))
	{
		ClearActorAnimations(actorid);
		SendClientMessage(playerid,COLOR_GREEN,"Animation canceled!");
	}
	else return SendClientMessage(playerid,COLOR_RED,"Invalid actor id!");
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:cancelallactorsanim(playerid, params[])
{
    if(IsPlayerAdmin(playerid)){
    for(new i = 0, j = GetActorPoolSize(); i <= j; i++)
    {
    	ClearActorAnimations(i);
	}
	SendClientMessage(playerid,COLOR_GREEN,"You have canceled all actors' animations!");
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:getactor(playerid, params[])
{
	if(IsPlayerAdmin(playerid)){
	new actorid,str[256],Float:pPos[3],Float:aPos[3],Float:newPos[3];
	if(sscanf(params,"i",actorid)) return SendClientMessage(playerid,COLOR_PURPLE,"USAGE: /getactor [actor id]");
	if(IsValidActor(actorid))
	{
	    ClearLabel(actorid);
	    GetActorPos(actorid,aPos[0],aPos[1],aPos[2]);
	    GetPlayerPos(playerid,pPos[0],pPos[1],pPos[2]);
	    SetActorPos(actorid,pPos[0],pPos[1],pPos[2]);
	    GetActorPos(actorid,newPos[0],newPos[1],newPos[2]);
	    SetPlayerPos(playerid,pPos[0]+1,pPos[1]+1,pPos[2]);
	    format(str,sizeof(str),"Actor ID: %d",actorid);
	    aLabels[actorid][label_ID]  = Create3DTextLabel(str, COLOR_YELLOW, newPos[0], newPos[1], newPos[2], 10, 0, 0);
		for(new i = 0, j = GetActorPoolSize(); i <= j; i++)
    	{
        	if(ActorText[i] == 1)
        	{
				ActorText[actorid] = 1;
			}
			else if(ActorText[i] == 0)
			{
				ActorText[actorid] = 0;
				ClearLabel(actorid);
			}
    	}
	}
	else return SendClientMessage(playerid,COLOR_RED,"Invalid actor id!");
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:actorstext(playerid,params[])
{
    if(IsPlayerAdmin(playerid))
    {
    	for(new i = 0, j = GetActorPoolSize(); i <= j; i++)
    	{
    		if(ActorText[i] == 0)
	    	{
  				ActorText[i] = 1;
				new Float:Pos[3],str2[256];
				format(str2,sizeof(str2),"Actor ID: %d",i);
				GetActorPos(i,Pos[0],Pos[1],Pos[2]);
    			aLabels[i][label_ID] = Create3DTextLabel(str2, COLOR_YELLOW, Pos[0], Pos[1], Pos[2], 10, 0, 0);
			}
			else if(ActorText[i] == 1)
			{
				ActorText[i] = 0;
				ClearLabel(i);
			}
		}
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:actorhelp(playerid,params[])
{
    if(IsPlayerAdmin(playerid))
    {
        new text[500],text2[500],text3[500],everything[1000];
        format(text,sizeof(text),"{A9A9A9}** {ff0000}/spawnactor [skin id] [Vulnerability (0: invulnerable / 1: vulnerable)] > {8B0000}spawns the actor where the player is facing\n{A9A9A9}** {ff0000}/removeactor [actor id] > {8B0000}removes specified actor\n{A9A9A9}** {ff0000}/removeallactors > {8B0000}clears all actors");
        format(text2,sizeof(text2),"\n{A9A9A9}** {ff0000}/gotoactor [actor id] > {8B0000}TP you to the actor's POS (position)\n{A9A9A9}** {ff0000}/setactoranim [animation name] > {8B0000}Set an anim on actor\n{ff0000}    ANIMATIONS: {8B0000}handsup / lean / sit / injured / dance / laugh / hide / dealstance / crossarms / riotchant / wave / talk / fucku / tired");
        format(text3,sizeof(text3),"\n{A9A9A9}** {ff0000}/cancelactoranim [actor id] > {8B0000}cancels the anim that has been excuted on the actor\n{A9A9A9}** {ff0000}/actorstext > {8B0000}shows/hides all actors text\n{A9A9A9}** {ff0000}/updateactor [actor id] [skin id] [vulnerability] > {8B0000}updates specified actor's skin and vulnerability (Also updates rotation, view where you want and apply command!)");
        format(everything,sizeof(everything),"%s %s %s",text,text2,text3);
        ShowPlayerDialog(playerid, DIALOG_ACTORHELP, DIALOG_STYLE_MSGBOX, "Actor system commands",everything,"OK","");
	}
	else return 0;
	return 1;
}
///////////////////////////////////////////////////
CMD:updateactor(playerid,params[])
{
    if(IsPlayerAdmin(playerid))
    {
        new actorid,skinid,invulnerability,Float:Pos[3],Float:Angle,str[256],str2[256];
        if(sscanf(params,"iil",actorid,skinid,invulnerability)) return SendClientMessage(playerid,COLOR_PURPLE,"USAGE: /updateactor [actor id] [skin id] [vulnerability]");
        if(!IsValidActor(actorid)) return SendClientMessage(playerid,COLOR_RED,"Invalid actor id!");
        if(skinid > 311 || skinid < 0) return SendClientMessage(playerid,COLOR_RED,"Invalid skin id!");
        if(invulnerability > 1 || invulnerability < 0) return SendClientMessage(playerid,COLOR_RED,"Vulnerability (0: invulnerable / 1: vulnerable)");
        GetPlayerFacingAngle(playerid, Angle);
        GetActorPos(actorid,Pos[0],Pos[1],Pos[2]);
        DestroyActor(actorid);
        new actorid2 = CreateActor(skinid, Pos[0], Pos[1], Pos[2], 0);
        SetActorFacingAngle(actorid2, Angle);
        format(str2,sizeof(str2),"Actor ID: %d",actorid2);
        ClearLabel(actorid);
        aLabels[actorid2][label_ID] = Create3DTextLabel(str2, COLOR_YELLOW, Pos[0], Pos[1], Pos[2], 10, 0, 0);
        format(str,sizeof(str),"You have updated actor %i. (new info: skin: %i, Vul: %i, ID: %i)",actorid,skinid,invulnerability,actorid2);
        SendClientMessage(playerid,COLOR_GREEN,str);
  		for(new i = 0, j = GetActorPoolSize(); i <= j; i++)
    	{
        	if(ActorText[i] == 1)
        	{
				ActorText[actorid2] = 1;
			}
			else if(ActorText[i] == 0)
			{
				ActorText[actorid2] = 0;
				ClearLabel(actorid2);
			}
    	}
  	 	if(invulnerability == 0)
    	{
        	SetActorInvulnerable(actorid2, 1);
        	SendClientMessage(playerid,COLOR_GREEN,"This actor is invulnerable!");
		}
		else if(invulnerability == 1)
		{
		    SetActorHealth(actorid2, 100);
	    	SetActorInvulnerable(actorid2,0);
	    	SendClientMessage(playerid,COLOR_GREEN,"This actor is vulnerable!");
		}
	}
	else return 0;
	return 1;
}
