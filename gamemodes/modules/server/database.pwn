#include <YSI_Coding\y_hooks>

new MySQL:g_SQL;
new sql[1024];

hook OnGameModeInit() {
    //Audio_SetPack("Desolation");
    new connectiontest[32];
    new ret = GetEnv("MYSQL_HOST", connectiontest);
    if(ret)
        connectDB();
    else
        print("Failed to read .env file.");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    shutdownDB();
    return Y_HOOKS_CONTINUE_RETURN_1;
}

connectDB() {
    new MySQLOpt: option_id = mysql_init_options();
    mysql_set_option(option_id, AUTO_RECONNECT, true);

    new 
        mysqlHost[32],
        mysqlUser[32],
        mysqlDatabase[32],
        mysqlPassword[128];

    GetEnv("MYSQL_HOST", mysqlHost);
    GetEnv("MYSQL_USER", mysqlUser);
    GetEnv("MYSQL_DATABASE", mysqlDatabase);
    GetEnv("MYSQL_PASSWORD", mysqlPassword);
    
    g_SQL = mysql_connect(mysqlHost, mysqlUser, mysqlPassword, mysqlDatabase);

    if(g_SQL==MYSQL_INVALID_HANDLE) 
    {
        print("Database connection was unsuccessful.");
        SendRconCommand("exit");
        return 1;
    }
    print("Database connection established.");
    //mysql_log( WARNING );
    mysql_log( WARNING );
    return 1;
}

shutdownDB() {
	mysql_close(g_SQL);
	return 1;
}

public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle) {
	printf("________________");
	switch(errorid) {
		case ER_UNKNOWN_TABLE: printf("[sql error] ER_UNKNOWN_TABLE");
		case ER_SYNTAX_ERROR: printf("[sql error] ER_SYNTAX_ERROR");
		case CR_COMMAND_OUT_OF_SYNC: printf("[sql error] CR_COMMAND_OUT_OF_SYNC");
		case CR_SERVER_LOST_EXTENDED: printf("[sql error] CR_SERVER_LOST_EXTENDED");
	}
	printf("Error: %s", error);
	printf("Callback: %s", callback);
	printf("Query: %s", query);
	printf("________________");
    new string[200];
    format(string, sizeof string, "[LOG]: Error:%s Query:%s", error, query);
	SendAdminMessage(HEX_YELLOW, string, true);
	return 1;
}