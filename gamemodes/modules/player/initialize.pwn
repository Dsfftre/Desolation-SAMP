#if defined _inc_hooks
	#undef _inc_hooks
#endif

#include <YSI_Coding\y_hooks>

hook OnPlayerRequestDL(playerid, type, crc)
{
	/*new dlfilename[64+1];
	if (type == DOWNLOAD_REQUEST_TEXTURE_FILE) {
        FindTextureFileNameFromCRC(crc,dlfilename,64);
		printf("OnPlayerRequestDL FindTextureFileNameFromCRC %s", dlfilename);
    }
	else if (type == DOWNLOAD_REQUEST_MODEL_FILE) {
        FindModelFileNameFromCRC(crc,dlfilename,64);
		printf("OnPlayerRequestDL FindModelFileNameFromCRC %s", dlfilename);
	}*/
	
	if(IsPlayerNPC(playerid))
		return Y_HOOKS_BREAK_RETURN_0;

	if(!IsPlayerConnected(playerid))
		return Y_HOOKS_CONTINUE_RETURN_0;

	if(Bit_Get(character, playerid))
		return Y_HOOKS_CONTINUE_RETURN_0;

	if(gettime() > GetPVarInt(playerid, "p_reqtime"))
	{
		//TogglePlayerSpectating(playerid, true);

	    if (GetPVarInt(playerid, "p_reqtime") == 0) {
			SetPlayerWeather(playerid, ServerTime[weather]);
			SetPlayerTime(playerid, ServerTime[hour], 30);
		}

	    if (GetPVarInt(playerid, "p_requests") == 0)
	    {
			InterpolateCameraPos(playerid, 682.3288, -704.5004, 36.5238, 682.3288, -704.5004, 36.5238, 60000, CAMERA_MOVE);  	    
    		InterpolateCameraLookAt(playerid, 681.7302, -586.7748, 29.1387, 681.7302, -586.7748, 29.1387, 60000, CAMERA_MOVE);
			SetPlayerPos(playerid, 237.112899, -283.291381, 4.823380 - 10.0);
			SetPVarInt(playerid, "p_requests", 1);
			SetPlayerWeather(playerid, ServerTime[weather]);
			SetPlayerTime(playerid, ServerTime[hour], 30);
		}
	    else if (GetPVarInt(playerid, "p_requests") == 1)
	    {
			InterpolateCameraPos(playerid, 682.3288, -704.5004, 36.5238, 682.3288, -704.5004, 36.5238, 60000, CAMERA_MOVE);  	    
    		InterpolateCameraLookAt(playerid, 681.7302, -586.7748, 29.1387, 681.7302, -586.7748, 29.1387, 60000, CAMERA_MOVE);
			SetPlayerPos(playerid, -856.914855, -2166.850830, 121.383178 - 10.0);
			SetPlayerWeather(playerid, ServerTime[weather]);
			SetPlayerTime(playerid, ServerTime[hour], 30);
			SetPVarInt(playerid, "p_requests", 0);
		}
		SetPlayerVirtualWorld(playerid, playerid + MAX_PLAYERS);

		SetPVarInt(playerid, "p_reqtime", gettime() + 400);
	}

	new filename[64], filefound, url_final[356];

	if(type == DOWNLOAD_REQUEST_TEXTURE_FILE){
		filefound = FindTextureFileNameFromCRC(crc, filename, sizeof(filename));
		//printf("DEBUG 1 %s", filename);
	}
	else if(type == DOWNLOAD_REQUEST_MODEL_FILE){
		filefound = FindModelFileNameFromCRC(crc, filename, sizeof(filename));
		//printf("DEBUG 2 %s", filename);
	}
	if(filefound)
	{
		format(url_final, sizeof(url_final), "%s/%s", SERVER_DOWNLOAD, filename);
		RedirectDownload(playerid, url_final);


		//printf("DEBUG 3 %s %s", filename, SERVER_DOWNLOAD);

		//printf("Redirect: %s - %s/%s", url_final, SERVER_DOWNLOAD, filename);
	}
	return Y_HOOKS_CONTINUE_RETURN_1;
}

/*hook OnPlayerFinishedDLing(playerid)
{
    //printf("%s OnPlayerFinishedDownloading", playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}*/

public OnPlayerFinishedDownloading(playerid, virtualworld)
{
    return 1;
}