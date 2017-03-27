#ifndef Character_hpp
#define Character_hpp

#include "GridObjects.h"
#include "Subject.h"
#include "Observer.h"


class Character : public GridObjects, Subject{
protected:
    int MaxHP;
    int HP;
    int Atk;
    int Def;
    int Gold;
    
public:
    int getMaxHP();
    int getHP();
    int getAttack();
    int getDefence();
    int getGold();
    ObstacleType getObsType() override; //这里override还是到player和enemy？
};

#endif
