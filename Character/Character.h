#ifndef Character_hpp
#define Character_hpp

#include "GridObjects.h"

class Character : public GridObjects{
    int maxHP;
    int HP;
    int atk;
    int def;
    int gold;
    
public:
    int getMaxHP();
    int getHP();
    int getAttack();
    int getDefence();
    int getGold();
    ObstacleType getObsType();
    GridObjectType getObjType();
};

#endif
