#include "../../include/db/db_support.h"

using namespace std;

string getSavePath() {
    char path[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path);
    return string(path) + "/DnDTool/saves/";
}

string getCharacterPath(const string& characterName) {
    return getSavePath() + characterName + "/";
}

vector<string> getCharacters() {
    vector<string> characters;
    string savePath = getSavePath();

    for (auto& entry : filesystem::directory_iterator(savePath)) {
        if (entry.is_directory()) {
            characters.push_back(entry.path().filename().string());
        }
    }
    return characters;
}