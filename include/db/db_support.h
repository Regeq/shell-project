#pragma once

#include <string>
#include <windows.h>
#include <shlobj.h>
#include <filesystem>
#include <vector>

std::string getSavePath();
std::string getCharacterPath(const std::string& characterName);
