// RERP TO-DO: OPTIMIZE LOOPS

#if defined _inc_skinchanger
	#undef _inc_skinchanger
#endif

#include <YSI_Coding\y_hooks>

#include <a_samp>

#define PVEH_TOTAL_ITEMS         21

#define PVEH_HEADER_TEXT "Vehicles"

static pveh_gTotalItems = PVEH_TOTAL_ITEMS;
static PlayerText:pveh_gCurrentPageTextDrawId[MAX_PLAYERS];
static PlayerText:pveh_gHeaderTextDrawId[MAX_PLAYERS];
static PlayerText:pveh_gBackgroundTextDrawId[MAX_PLAYERS];
static PlayerText:pveh_gNextButtonTextDrawId[MAX_PLAYERS];
static PlayerText:pveh_gPrevButtonTextDrawId[MAX_PLAYERS];
static PlayerText:pveh_gSelectionItemswId[MAX_PLAYERS][SELECTION_ITEMS];
static pveh_gSelectionItemswIdTag[MAX_PLAYERS][SELECTION_ITEMS];
static pveh_gSelectionItemswIdSQL[MAX_PLAYERS][SELECTION_ITEMS];
static pveh_gItemAt[MAX_PLAYERS];

static PVEH_gItemList[MAX_PLAYERS][PVEH_TOTAL_ITEMS];
static PVEH_gItemList_Model[MAX_PLAYERS][PVEH_TOTAL_ITEMS];
static PVEH_gItemList_color1[MAX_PLAYERS][PVEH_TOTAL_ITEMS];
static PVEH_gItemList_color2[MAX_PLAYERS][PVEH_TOTAL_ITEMS];

PVEH_ReloadgItemList(playerid) {
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_vehicle` WHERE playerId = '%d' LIMIT %d", CharacterSQL[playerid], PVEH_TOTAL_ITEMS);
	new Cache:result = mysql_query(g_SQL, sql);
	if(cache_num_rows()) {
		new i = -1;
		for(;++i<PVEH_TOTAL_ITEMS;) {
			PVEH_gItemList[playerid][i] = 0;
			PVEH_gItemList_Model[playerid][i] = 0;
			pveh_gSelectionItemswIdSQL[playerid][i] = 0;
		}
		i = -1;
		for(;++i<cache_num_rows();) {
			cache_get_value_int(i, "id", PVEH_gItemList[playerid][i]);
			cache_get_value_int(i, "model", PVEH_gItemList_Model[playerid][i]);
			cache_get_value_int(i, "color1", PVEH_gItemList_color1[playerid][i]);
			cache_get_value_int(i, "color2", PVEH_gItemList_color2[playerid][i]);
		}
		cache_delete(result);
		return 1;
	}
	printf("%s", sql);
	return 0;
}



PVEH_GetNumberOfPages()
{
	if((pveh_gTotalItems >= SELECTION_ITEMS) && (pveh_gTotalItems % SELECTION_ITEMS) == 0)
	{
		return (pveh_gTotalItems / SELECTION_ITEMS);
	}
	else return (pveh_gTotalItems / SELECTION_ITEMS) + 1;
}

//------------------------------------------------

PlayerText:PVEH_CreateCurrentPageTD(playerid, Float:Xpos, Float:Ypos) {
	new PlayerText:pveh_txtInit;
   	pveh_txtInit = CreatePlayerTextDraw(playerid, Xpos, Ypos, "0/0");
   	PlayerTextDrawUseBox(playerid, pveh_txtInit, 0);
	PlayerTextDrawLetterSize(playerid, pveh_txtInit, 0.4, 1.1);
	PlayerTextDrawFont(playerid, pveh_txtInit, 1);
	PlayerTextDrawSetShadow(playerid, pveh_txtInit, 0);
    PlayerTextDrawSetOutline(playerid, pveh_txtInit, 1);
    PlayerTextDrawColor(playerid, pveh_txtInit, 0xACCBF1FF);
    PlayerTextDrawShow(playerid, pveh_txtInit);
    return pveh_txtInit;
}

//------------------------------------------------
// Creates a button textdraw and returns the textdraw ID.

PlayerText:PVEH_CreatePlayerDB(playerid, Float:Xpos, Float:Ypos, Float:Width, Float:Height, button_text[])
{
 	new PlayerText:pveh_txtInit;
   	pveh_txtInit = CreatePlayerTextDraw(playerid, Xpos, Ypos, button_text);
   	PlayerTextDrawUseBox(playerid, pveh_txtInit, 1);
   	PlayerTextDrawBoxColor(playerid, pveh_txtInit, 0x000000FF);
   	PlayerTextDrawBackgroundColor(playerid, pveh_txtInit, 0x000000FF);
	PlayerTextDrawLetterSize(playerid, pveh_txtInit, 0.4, 1.1);
	PlayerTextDrawFont(playerid, pveh_txtInit, 1);
	PlayerTextDrawSetShadow(playerid, pveh_txtInit, 0); // no shadow
    PlayerTextDrawSetOutline(playerid, pveh_txtInit, 0);
    PlayerTextDrawColor(playerid, pveh_txtInit, 0x4A5A6BFF);
    PlayerTextDrawSetSelectable(playerid, pveh_txtInit, 1);
    PlayerTextDrawAlignment(playerid, pveh_txtInit, 2);
    PlayerTextDrawTextSize(playerid, pveh_txtInit, Height, Width); // The width and height are reversed for centering.. something the game does <g>
    PlayerTextDrawShow(playerid, pveh_txtInit);
    return pveh_txtInit;
}
 
//------------------------------------------------

PlayerText:PVEH_CreatePlayerHeaderTD(playerid, Float:Xpos, Float:Ypos, td_text[])
{
	new PlayerText:pveh_txtInit;
   	pveh_txtInit = CreatePlayerTextDraw(playerid, Xpos, Ypos, td_text);
   	PlayerTextDrawUseBox(playerid, pveh_txtInit, 0);
	PlayerTextDrawLetterSize(playerid, pveh_txtInit, 1.25, 3.0);
	PlayerTextDrawFont(playerid, pveh_txtInit, 0);
	PlayerTextDrawSetShadow(playerid, pveh_txtInit, 0);
    PlayerTextDrawSetOutline(playerid, pveh_txtInit, 1);
    PlayerTextDrawColor(playerid, pveh_txtInit, 0xACCBF1FF);
    PlayerTextDrawShow(playerid, pveh_txtInit);
    return pveh_txtInit;
}

//------------------------------------------------

PlayerText:PVEH_CreatePlayerBackgroundTD(playerid, Float:Xpos, Float:Ypos, Float:Width, Float:Height)
{
	new PlayerText:txtBackground = CreatePlayerTextDraw(playerid, Xpos, Ypos,
	"                                            ~n~"); // enough space for everyone
    PlayerTextDrawUseBox(playerid, txtBackground, 1);
    PlayerTextDrawBoxColor(playerid, txtBackground, 0x4A5A6BBB);
	PlayerTextDrawLetterSize(playerid, txtBackground, 5.0, 5.0);
	PlayerTextDrawFont(playerid, txtBackground, 0);
	PlayerTextDrawSetShadow(playerid, txtBackground, 0);
    PlayerTextDrawSetOutline(playerid, txtBackground, 0);
    PlayerTextDrawColor(playerid, txtBackground,0x000000FF);
    PlayerTextDrawTextSize(playerid, txtBackground, Width, Height);
   	PlayerTextDrawBackgroundColor(playerid, txtBackground, 0x4A5A6BBB);
    PlayerTextDrawShow(playerid, txtBackground);
    return txtBackground;
}

//------------------------------------------------
// Creates a model preview sprite

PlayerText:PVEH_CreateModelPreviewTextDraw(playerid, modelindex, Float:Xpos, Float:Ypos, Float:width, Float:height, itemat = 0)
{
    new PlayerText:txtPlayerSprite = CreatePlayerTextDraw(playerid, Xpos, Ypos, ""); // it has to be set with SetText later
    PlayerTextDrawFont(playerid, txtPlayerSprite, TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawColor(playerid, txtPlayerSprite, 0xFFFFFFFF);
    PlayerTextDrawBackgroundColor(playerid, txtPlayerSprite, 0x88888899);
    PlayerTextDrawTextSize(playerid, txtPlayerSprite, width, height); // Text size is the Width:Height
    PlayerTextDrawSetPreviewModel(playerid, txtPlayerSprite, modelindex);
    PlayerTextDrawSetSelectable(playerid, txtPlayerSprite, 1);
	PlayerTextDrawSetPreviewRot(playerid, txtPlayerSprite, -5.0, 0.0, 20.0, 0.75);
	PlayerTextDrawSetPreviewVehCol(playerid, txtPlayerSprite, PVEH_gItemList_color1[playerid][itemat], PVEH_gItemList_color2[playerid][itemat]);
    PlayerTextDrawShow(playerid,txtPlayerSprite);	
    return txtPlayerSprite;
}

//------------------------------------------------

PVEH_DestroyPlayerModelPreviews(playerid)
{
	new x=0;
	while(x != SELECTION_ITEMS) {
	    if(pveh_gSelectionItemswId[playerid][x] != PlayerText:INVALID_TEXT_DRAW) {
			PlayerTextDrawDestroy(playerid, pveh_gSelectionItemswId[playerid][x]);
			pveh_gSelectionItemswId[playerid][x] = PlayerText:INVALID_TEXT_DRAW;
		}
		x++;
	}
}

//------------------------------------------------

PVEH_ShowPlayerModelPreviews(playerid)
{
    new x=0;
	new Float:BaseX = DIALOG_BASE_X;
	new Float:BaseY = DIALOG_BASE_Y - (SPRITE_DIM_Y * 0.33); // down a bit
	new linetracker = 0;
	
	new itemat = GetPVarInt(playerid, "pveh_page") * SELECTION_ITEMS;
	
	// Destroy any previous ones created
	PVEH_DestroyPlayerModelPreviews(playerid);

	while(x != SELECTION_ITEMS && itemat < pveh_gTotalItems) {
	    if(linetracker == 0) {
	        BaseX = DIALOG_BASE_X + 25.0; // in a bit from the box
	        BaseY += SPRITE_DIM_Y + 1.0; // move on the Y for the next line
		}
		if(PVEH_gItemList_Model[playerid][itemat] > 0) {
  			pveh_gSelectionItemswId[playerid][x] = PVEH_CreateModelPreviewTextDraw(playerid, PVEH_gItemList_Model[playerid][itemat], BaseX, BaseY, SPRITE_DIM_X, SPRITE_DIM_Y, itemat);
			pveh_gSelectionItemswIdTag[playerid][x] = PVEH_gItemList_Model[playerid][itemat];
			pveh_gSelectionItemswIdSQL[playerid][x] = PVEH_gItemList[playerid][itemat];
			BaseX += SPRITE_DIM_X + 1.0; // move on the X for the next sprite
			linetracker++;
			if(linetracker == ITEMS_PER_LINE) linetracker = 0;
		}
		itemat++;
		x++;
	}
}

//------------------------------------------------

PVEH_UpdatePageTextDraw(playerid)
{
	new PageText[64+1];
	format(PageText, 64, "%d/%d", GetPVarInt(playerid,"pveh_page") + 1, PVEH_GetNumberOfPages());
	PlayerTextDrawSetString(playerid, pveh_gCurrentPageTextDrawId[playerid], PageText);
}

//------------------------------------------------

PVEH_CreateSelectionMenu(playerid)
{
    pveh_gBackgroundTextDrawId[playerid] = PVEH_CreatePlayerBackgroundTD(playerid, DIALOG_BASE_X, DIALOG_BASE_Y + 20.0, DIALOG_WIDTH, DIALOG_HEIGHT);
    pveh_gHeaderTextDrawId[playerid] = PVEH_CreatePlayerHeaderTD(playerid, DIALOG_BASE_X, DIALOG_BASE_Y, PVEH_HEADER_TEXT);
    pveh_gCurrentPageTextDrawId[playerid] = PVEH_CreateCurrentPageTD(playerid, DIALOG_WIDTH - 30.0, DIALOG_BASE_Y + 15.0);
    pveh_gNextButtonTextDrawId[playerid] = PVEH_CreatePlayerDB(playerid, DIALOG_WIDTH - 30.0, DIALOG_BASE_Y+DIALOG_HEIGHT+100.0, 50.0, 16.0, NEXT_TEXT);
    pveh_gPrevButtonTextDrawId[playerid] = PVEH_CreatePlayerDB(playerid, DIALOG_WIDTH - 90.0, DIALOG_BASE_Y+DIALOG_HEIGHT+100.0, 50.0, 16.0, PREV_TEXT);

    PVEH_ShowPlayerModelPreviews(playerid);
    PVEH_UpdatePageTextDraw(playerid);
}

//------------------------------------------------

PVEH_DestroySelectionMenu(playerid)
{
	PVEH_DestroyPlayerModelPreviews(playerid);

	PlayerTextDrawDestroy(playerid, pveh_gHeaderTextDrawId[playerid]);
	PlayerTextDrawDestroy(playerid, pveh_gBackgroundTextDrawId[playerid]);
	PlayerTextDrawDestroy(playerid, pveh_gCurrentPageTextDrawId[playerid]);
	PlayerTextDrawDestroy(playerid, pveh_gNextButtonTextDrawId[playerid]);
	PlayerTextDrawDestroy(playerid, pveh_gPrevButtonTextDrawId[playerid]);

	pveh_gHeaderTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    pveh_gBackgroundTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    pveh_gCurrentPageTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    pveh_gNextButtonTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    pveh_gPrevButtonTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
}

//------------------------------------------------

PVEH_HandlePlayerItemSelection(playerid, selecteditem) {
	if(Bit_Get(dead, playerid)) {
		SCM(playerid, HEX_RED, "Error: You cannot do that now.");
		return 0;
	}

	//devnote spawn players selected vehicle

	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `player_vehicle` WHERE id = %d", pveh_gSelectionItemswIdSQL[playerid][selecteditem]);
	inline LoadPlayerVehicle() {
		if(!cache_num_rows()) {
			SCM(playerid, HEX_RED, "Error: The selected vehicle was not found in the database.");
			@return 0;
		}

		new i = -1;
		for(;++i<MAX_VEHICLES;) {
			if(VehicleInfo[i][sqlid] == 0)
				break;
		}
		
		new v_engine, lights, alarm, doors, bonnet, boot, objective;

		cache_get_value_int(0, "id", VehicleInfo[i][sqlid]);
		cache_get_value_float(0, "posx", VehicleInfo[i][vpos][0]);
		cache_get_value_float(0, "posy", VehicleInfo[i][vpos][1]);
		cache_get_value_float(0, "posz", VehicleInfo[i][vpos][2]);
		cache_get_value_float(0, "posf", VehicleInfo[i][vpos][3]);
		cache_get_value_int(0, "model", VehicleInfo[i][model]);
		cache_get_value_float(0, "vhealth", VehicleInfo[i][vhealth]);
		cache_get_value_int(0, "access", VehicleInfo[i][access]);
		cache_get_value_int(0, "locked", VehicleInfo[i][locked]);
		cache_get_value_int(0, "factionId", VehicleInfo[i][factionId]);
		cache_get_value_int(0, "playerId", VehicleInfo[i][playersId]);
		cache_get_value_int(0, "color1", VehicleInfo[i][vcolor][0]);
		cache_get_value_int(0, "color2", VehicleInfo[i][vcolor][1]);
		cache_get_value_int(0, "interior", VehicleInfo[i][interior]);
		cache_get_value_int(0, "virtualworld", VehicleInfo[i][v_virtualworld]);
		cache_get_value_int(0, "siren", VehicleInfo[i][siren]);
		cache_get_value(0, "plates", VehicleInfo[i][plates], 32);

		VehicleInfo[i][vid] = CreateVehicle(VehicleInfo[i][model], VehicleInfo[i][vpos][0], VehicleInfo[i][vpos][1], VehicleInfo[i][vpos][2], VehicleInfo[i][vpos][3], VehicleInfo[i][vcolor][0], VehicleInfo[i][vcolor][1], 3600, VehicleInfo[i][siren]);
		GetVehicleParamsEx(VehicleInfo[i][vid], v_engine, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx(VehicleInfo[i][vid], v_engine, lights, alarm, VehicleInfo[i][locked], bonnet, boot, objective);
		SetVehicleHealth(VehicleInfo[i][vid], VehicleInfo[i][vhealth]);
		SetVehicleNumberPlate(VehicleInfo[i][vid], VehicleInfo[i][plates]);
		SetPlayerCheckpoint(playerid, VehicleInfo[i][vpos][0], VehicleInfo[i][vpos][1], VehicleInfo[i][vpos][2], 4.0);
		SFM(playerid, HEX_GREEN, "%s spawned!", VehicleNames[GetVehicleModel(VehicleInfo[i][vid])-400]);

		SetPVarInt(playerid, "pveh", i);

		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadPlayerVehicle, sql);
	return 1;
}

//------------------------------------------------

hook OnPlayerConnect(playerid)
{
	// Init all of the textdraw related globals
    pveh_gHeaderTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    pveh_gBackgroundTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    pveh_gCurrentPageTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    pveh_gNextButtonTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    pveh_gPrevButtonTextDrawId[playerid] = PlayerText:INVALID_TEXT_DRAW;
    
    for(new x=0; x < SELECTION_ITEMS; x++) {
        pveh_gSelectionItemswId[playerid][x] = PlayerText:INVALID_TEXT_DRAW;
	}
	
	pveh_gItemAt[playerid] = 0;

	SetPVarInt(playerid, "pveh_active", 0);
	
	return Y_HOOKS_CONTINUE_RETURN_1;
}

//-------------------------------------------
// Even though only Player* textdraws are used in this script,
// OnPlayerClickTextDraw is still required to handle ESC

hook OnPlayerClickTD(playerid, Text:clickedid)
{
   	if(GetPVarInt(playerid, "pveh_active") == 0) return Y_HOOKS_CONTINUE_RETURN_0;

	// Handle: They cancelled (with ESC)
	if(clickedid == Text:INVALID_TEXT_DRAW) {
        PVEH_DestroySelectionMenu(playerid);
        SetPVarInt(playerid, "pveh_active", 0);
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        return Y_HOOKS_BREAK_RETURN_1;
	}
	
	return Y_HOOKS_BREAK_RETURN_0;
}

//------------------------------------------------

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
	if(GetPVarInt(playerid, "pveh_active") == 0) return Y_HOOKS_CONTINUE_RETURN_0;

	new curpage = GetPVarInt(playerid, "pveh_page");
	
	// Handle: next button
	if(playertextid == pveh_gNextButtonTextDrawId[playerid]) 
	{
	    if(curpage < (PVEH_GetNumberOfPages() - 1)) 
		{
	        SetPVarInt(playerid, "pveh_page", curpage + 1);
	        PVEH_ShowPlayerModelPreviews(playerid);
         	PVEH_UpdatePageTextDraw(playerid);
         	PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
		} else 
		{
		    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		}
		return 1;
	}
	
	// Handle: previous button
	if(playertextid == pveh_gPrevButtonTextDrawId[playerid]) 
	{
	    if(curpage > 0) 
		{
	    	SetPVarInt(playerid, "pveh_page", curpage - 1);
	    	PVEH_ShowPlayerModelPreviews(playerid);
	    	PVEH_UpdatePageTextDraw(playerid);
	    	PlayerPlaySound(playerid, 1084, 0.0, 0.0, 0.0);
		} else 
		{

		    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		}
		return Y_HOOKS_BREAK_RETURN_1;
	}
	
	// Search in the array of textdraws used for the items
	new x=0;
	while(x != SELECTION_ITEMS) {
	    if(playertextid == pveh_gSelectionItemswId[playerid][x]) {
	        PVEH_HandlePlayerItemSelection(playerid, x);
	        PlayerPlaySound(playerid, 1083, 0.0, 0.0, 0.0);
	        PVEH_DestroySelectionMenu(playerid);
	        CancelSelectTextDraw(playerid);
        	SetPVarInt(playerid, "pveh_active", 0);
        	return Y_HOOKS_BREAK_RETURN_1;
		}
		++x;
	}
	
	return Y_HOOKS_BREAK_RETURN_0;
}

VehicleSelector(playerid) {
	SetPVarInt(playerid, "pveh_active", 1);
	SetPVarInt(playerid, "pveh_page", 0); // will reset the page back to the first
	PVEH_CreateSelectionMenu(playerid);
	SelectTextDraw(playerid, 0xACCBF1FF);
	return 1;
}

YCMD:vehicles(playerid, params[], help) {
	if(!IsHuman(playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: Zombies cannot do that.");
	if(Bit_Get(dead, playerid) && !Group_GetPlayer(g_AdminDuty, playerid)) return SCM(playerid, HEX_RED, "Error: You cannot do that now.");
	if(PVEH_ReloadgItemList(playerid) == 0) return SCM(playerid, HEX_RED, "Error: You do not have any personal vehicles.");
	if(GetPVarInt(playerid, "pveh") > 0) return SCM(playerid, HEX_RED, "Error: You already spawned a vehicle.");
	VehicleSelector(playerid);
	return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
	if(GetPVarInt(playerid, "pveh") > 0 && IsValidVehicle(VehicleInfo[GetPVarInt(playerid, "pveh")][vid])) {
		DestroyVehicle(VehicleInfo[GetPVarInt(playerid, "pveh")][vid]);
		VehicleInfo[GetPVarInt(playerid, "pveh")][sqlid] = 0;
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

