#ifndef Character_hpp
#define Character_hpp



#include "GridObjectType.h"
#include "ObstacleType.h"
#include "Observer.h"
#include "GridObjects.h"

class Character : public GridObjects{
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
    ObstacleType getObsType() override;
};

#endif
