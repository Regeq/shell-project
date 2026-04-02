cmake_minimum_required(VERSION 3.20)

project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MyProject
    src/main.cpp
    src/map_commands.cpp
    src/shell_dispatcher.cpp
        src/command_methods.h
        src/command_methods.cpp
)

target_include_directories(MyProject PRIVATE src)