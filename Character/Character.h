#ifndef Character_hpp
#define Character_hpp

#include "GridObjects.h"
#include "Subject.h"

class Character : public GridObjects, public Subject{
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
    Info getInfo() override;
    ObstacleType getObsType() override; //这里override还是到player和enemy？
};

#endif
