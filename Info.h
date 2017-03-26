#ifndef Info_hpp
#define Info_hpp
#include <string>
#include "GridObjectType.h"
struct Info {
    int previousRow;
    int previousCol;
    int currentRow;
    int currentCol;
    int HP, Atk, Def;
    char EnemyRace;
    std::string Message;
    GridObjectType GOT;
};

#endif
