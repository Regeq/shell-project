#include "../../include/db/db_handling.h"

using namespace std;

void Database::open(string db_name) {
    sqlite3* DB;
    int exit = 0;

    exit = sqlite3_open(db_name.c_str(), &DB);

    sqlite3_close(DB);
}

void Database::save(string db_name) {
    //sqlite3_exec();
}
