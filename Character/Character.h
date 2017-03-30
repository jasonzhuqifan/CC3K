#ifndef Character_hpp
#define Character_hpp


#include "GridObjectType.h"
#include "ObstacleType.h"
#include "GridObjects.h"

class Character : public GridObjects{
protected:
    double MaxHP;
    double HP;
    double Atk;
    double Def;
    double Gold;
    bool isDead = false;
    
public:
    double getMaxHP();
    double getHP();
    double getAttack();
    double getDefence();
    double getGold();
    ObstacleType getObsType() override;
};

#endif
