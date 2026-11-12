cmake_minimum_required(VERSION 4.1)
project(MyProject LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(MyProject
        src/main.cpp
        src/map_commands.cpp
        src/shell_dispatcher.cpp
        src/command_methods.cpp
        src/db/db_handling.cpp
        src/db/db_support.cpp
        ${CMAKE_SOURCE_DIR}/include/sqlite/sqlite3.c
)

target_include_directories(MyProject PRIVATE
        src
        ${CMAKE_SOURCE_DIR}/include/sqlite
        ${CMAKE_SOURCE_DIR}/include
)