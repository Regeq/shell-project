#pragma once

#include <iostream>

#include "sqlite3.h"

class db_handling {
    public:
    void save(std::string db_name);
    void load();
};
