#pragma once

#include <iostream>

#include "sqlite3.h"

class Database {
public:
    void open(std::string db_name);
    void save(std::string db_name);
    void load();

private:
    sqlite3 *DB;
    int exit = 0;
};
