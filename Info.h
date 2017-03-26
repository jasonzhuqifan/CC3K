#ifndef Info_hpp
#define Info_hpp
#include <string>

struct Info {
    int previousRow;
    int previousCol;
    int currentRow;
    int currentCol;
    int HP, Atk, Def;
    char EnemyRace;
    std::string Message;
};

#endif
