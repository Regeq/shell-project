cmake_minimum_required(VERSION 4.1)

add_executable(MyProject
        src/main.cpp
        src/map_commands.cpp
        src/shell_dispatcher.cpp
        include/command_methods.h
        src/command_methods.cpp
        src/db/db_handling.cpp
        include/db/db_handling.h
        ${CMAKE_SOURCE_DIR}/include/sqlite/sqlite3.c
        src/db/db_handling.cpp
        include/db/db_support.h
        src/db/db_support.cpp
)

target_include_directories(MyProject PRIVATE
        src
        ${CMAKE_SOURCE_DIR}/include/sqlite
        ${CMAKE_SOURCE_DIR}/include
)