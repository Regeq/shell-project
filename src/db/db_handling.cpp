#include "../../include/db/db_handling.h"

using namespace std;

class Database {
    public:
    void open(string db_name) {
        sqlite3* DB;
        int exit = 0;

        exit = sqlite3_open(db_name.c_str(), &DB);

        sqlite3_close(DB);
    }
    void save() {
        sqlite3_exec();
    }
};