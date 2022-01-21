#include <YSI_Coding\y_hooks>

YCMD:shop(playerid, params[], help) {
    if(Bit_Get(dead, playerid)) return SCM(playerid, HEX_RED, "[Desolation]: You cannot do that now.");
    if(!IsHuman(playerid)) return SCM(playerid, HEX_RED, "[Desolation]: Zombies cannot do that.");

    if(GetPlayerVirtualWorld(playerid) == 0) return SCM(playerid, HEX_RED, "[Desolation]: You must be inside a store.");

    new bool:findshop = false;

    foreach(new i:Entrances) 
    {
        if(IntInfo[i][storeId] >= 2  && IntInfo[i][storeId] <= 10) //weapon store blackmarket 2, pharmacy 3
        { 
            if(IntInfo[i][intint] == GetPlayerInterior(playerid) && IntInfo[i][intvw] == GetPlayerVirtualWorld(playerid)) 
            {
                findshop = true;
                OpenShop(playerid, IntInfo[i][storeId], i);
            }
        }
    }

    if(!findshop) return SCM(playerid, HEX_YELLOW, "They are not doing business here.");

    return 1;
}


OpenShop(playerid, storeid, entrance) {

    new string[2048] = "Item\tPrice\tAmount\n";
    new shopdata[MAX_SHOPLINES][3];
    mysql_format(g_SQL, sql, sizeof sql, "SELECT id, name, price, amount FROM `itemlist` WHERE storetype = %d AND state > 0", storeid);
	inline LoadShopData() 
    {
		if(!cache_num_rows()) 
        {
			SCM(playerid, HEX_YELLOW, "This store has nothing to sell.");
			@return 1;
		}

		new i = -1;
		for(;++i<cache_num_rows();) 
        {
			new it_name[64], tmp_string[128];

            cache_get_value_int(i, "id", shopdata[i][0]);
            cache_get_value(i, "name", it_name, 64);
            cache_get_value_int(i, "price", shopdata[i][1]);
			cache_get_value_int(i, "amount", shopdata[i][2]);


            format(tmp_string, sizeof tmp_string, "%s\t$%d\tx%d\n", it_name, shopdata[i][1]*shopdata[i][2], shopdata[i][2]);
			
			strcat(string,tmp_string);
		}

		if(!IsPlayerConnected(playerid)) @return 1;
        if(Bit_Get(dead, playerid)) @return 1;
        if(!IsHuman(playerid)) @return 1;

        inline Dialog_shop_purchase(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) 
        {
            #pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext
            if(Open_response) 
            {
                ItemPurchaseDialog(playerid, entrance, shopdata[Open_listitem][0], shopdata[Open_listitem][1], shopdata[Open_listitem][2]);                
            }
        }	
        Dialog_ShowCallback(playerid, using inline Dialog_shop_purchase, DIALOG_STYLE_TABLIST_HEADERS, "Blackmarket", string, "Buy", "Close");
		@return 1;
	}

	MySQL_TQueryInline(g_SQL, using inline LoadShopData, sql);

    return 1;
}

ItemPurchaseDialog(playerid, entrance, it_id, it_price, it_amount) {

    new string[256];
    format(string, sizeof string, "Are you sure you want to purchase %s (x%d) for $%d overall?", GetItemName(it_id), it_amount, it_amount*it_price);
    inline Dialog_shop_purchase(Open_pid, Open_dialogid, Open_response, Open_listitem, string:Open_inputtext[]) 
    {
        #pragma unused Open_pid, Open_dialogid, Open_response, Open_listitem, Open_inputtext

        if(Open_response) 
        {

            if(!IsPlayerConnected(playerid)) @return 1;
            if(Bit_Get(dead, playerid)) @return 1;
            if(!IsHuman(playerid)) @return 1;

            if(cash[playerid] >= it_amount*it_price) 
            {

                if(GivePlayerItem(playerid, it_id, it_amount) == 0) 
                {
                    SCM(playerid, HEX_FADE2, "Your inventory is full.");
                    PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
                }
                else 
                {
                    cash[playerid] -= it_amount*it_price;
                    format(string, sizeof string, "~y~%s ~w~purchased!", GetItemName(it_id));
                    GameTextForPlayer(playerid, string, 2000, 3);
                    PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
                    GivePlayerMoney(playerid, -1*it_amount*it_price);
                    if(IntInfo[entrance][factionId] > 0) 
                    {
                        mysql_format(g_SQL, sql, sizeof sql, "UPDATE `faction` SET `bank` = `bank`+'%d' WHERE id = '%d' LIMIT 1", it_amount*it_price/2, IntInfo[entrance][factionId]);
			            mysql_tquery(g_SQL, sql, "", "");
                    }
                    ++TradeSkill[playerid];
                    
                }
            }
            else 
            {
                SCM(playerid, HEX_SAMP, "[STORE]: Sorry, you don't have enough to purchase this.");
                PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
            }
        }
        else 
        {
            OpenShop(playerid, IntInfo[entrance][storeId], entrance);
        }
    }	
    Dialog_ShowCallback(playerid, using inline Dialog_shop_purchase, DIALOG_STYLE_MSGBOX, "Confirm purchase", string, "Buy", "Back");

    return 1;
}
