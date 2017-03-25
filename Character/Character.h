#ifndef Character_hpp
#define Character_hpp

#include "GridObjects.h"
#include "Subject.h"
#include "Observer.h"

class Character : public GridObjects, Subject{
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
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
};

#endif
