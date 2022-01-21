YCMD:gotoxyz(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);
	new Float:gt_pos[4], gt_int, gt_vw;

	if(sscanf(params, "fffdd", gt_pos[1], gt_pos[2], gt_pos[3], gt_int, gt_vw)) return SCM(playerid, HEX_FADE2, "Usage: /gotoxyz [x] [y] [z] [interior] [virtual world]");

	SetPlayerPos(playerid, gt_pos[1], gt_pos[2], gt_pos[3]);
	SetPlayerInterior(playerid, gt_int);
	SetPlayerVirtualWorld(playerid, gt_vw);

	return 1;
}

YCMD:movex(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid, gt_pos;
	if(sscanf(params, "rd", targetid, gt_pos)) return SCM(playerid, HEX_FADE2, "Usage: /movex [id] [amount] (movement on x axis)");

	new Float:cur_pos[3];
	GetPlayerPos(targetid, cur_pos[0], cur_pos[1], cur_pos[2]);
	cur_pos[0] += float(gt_pos);
	
	SetPlayerPos(targetid, cur_pos[0], cur_pos[1], cur_pos[2]);

	return 1;
}

YCMD:movey(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid, gt_pos;
	if(sscanf(params, "rd", targetid, gt_pos)) return SCM(playerid, HEX_FADE2, "Usage: /movey [id] [amount] (movement on y axis)");

	new Float:cur_pos[3];
	GetPlayerPos(targetid, cur_pos[0], cur_pos[1], cur_pos[2]);
	cur_pos[1] += float(gt_pos);
	
	SetPlayerPos(targetid, cur_pos[0], cur_pos[1], cur_pos[2]);

	return 1;
}

YCMD:movez(playerid, params[], help) {
	if(adminlevel[playerid] == 0) return SendErrorMessage(playerid, ERROR_ADMIN);
	if(!Group_GetPlayer(g_AdminDuty, playerid)) return SendErrorMessage(playerid, ERROR_DUTY);

	new targetid, gt_pos;
	if(sscanf(params, "rd", targetid, gt_pos)) return SCM(playerid, HEX_FADE2, "Usage: /movez [id] [amount] (movement on z axis)");

	new Float:cur_pos[3];
	GetPlayerPos(targetid, cur_pos[0], cur_pos[1], cur_pos[2]);
	cur_pos[2] += float(gt_pos);
	
	SetPlayerPos(targetid, cur_pos[0], cur_pos[1], cur_pos[2]);

	return 1;//
}