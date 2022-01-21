#include <YSI_Coding\y_hooks>

YCMD:edititem(playerid, params[], help) {
	if(adminlevel[playerid] < 6) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new itemid;
	if(sscanf(params,"i",itemid)) return SCM(playerid, HEX_FADE2,"Usage: /edititem [itemid]");
	mysql_format(g_SQL, sql, sizeof sql, "SELECT * FROM `itemlist` WHERE id = %d LIMIT 1", itemid);
	inline LoadItemEdits() {
		if(!cache_num_rows()) {
			SCM(playerid, HEX_FADE2, "No item found.");
			@return 0;
		}
		new objectid;
		cache_get_value_int(0, "object", objectid);
			
		SetPVarInt(playerid, "itemedit_id", itemid);
		
		new Float:pos[3];
		GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
		objectid = CreateObject(objectid, pos[0], pos[1], pos[2], 0.0, 0.0, 0.0);
		EditObject(playerid, objectid);
		SetPVarInt(playerid, "itemedit_object", objectid);

		@return 1;
	}
	MySQL_TQueryInline(g_SQL, using inline LoadItemEdits, sql);

	return 1;
}

hook OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ ) {
	if(adminlevel[playerid] < 6) return Y_HOOKS_CONTINUE_RETURN_1;
	new edito = GetPVarInt(playerid, "itemedit_object");
	if(objectid != edito) return Y_HOOKS_CONTINUE_RETURN_1;

	if(response == EDIT_RESPONSE_FINAL) 
	{
		new Float:pos[3],
			Float:itempos[3];
		GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
		itempos[0] = fX - pos[0];
		itempos[1] = fY - pos[1];
		itempos[2] = fZ - pos[2];

		mysql_format(g_SQL, sql, sizeof sql, "UPDATE `itemlist` set `posx` = %f, `posy` = %f, `posz` = %f, `rotx` = %f, `roty` = %f, `rotz` = %f WHERE id = %d LIMIT 1", itempos[0], itempos[1], itempos[2], fRotX, fRotY, fRotZ, GetPVarInt(playerid, "itemedit_id"));
        mysql_tquery(g_SQL, sql, "", "");

		SFM(playerid, HEX_FADE2, "Item %d edited: [x %f y %f z %f] [rX %f rY %f rZ %f]", GetPVarInt(playerid, "itemedit_id"), itempos[0], itempos[1], itempos[2], fRotX, fRotY, fRotZ);
		DestroyObject(edito);
		DeletePVar(playerid, "itemedit_id");
		DeletePVar(playerid, "itemedit_object");
	}
	if(response == EDIT_RESPONSE_CANCEL) 
	{
		DestroyObject(edito);
		DeletePVar(playerid, "itemedit_id");
		DeletePVar(playerid, "itemedit_object");

	}


	return Y_HOOKS_BREAK_RETURN_1;
}