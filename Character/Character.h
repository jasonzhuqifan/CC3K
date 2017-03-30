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
    int gold;
    
public:
    virtual double getMaxHP();
    virtual double getHP();
    virtual double getAttack();
    virtual double getDefence();
    virtual double getGold();
    ObstacleType getObsType() override;
};

#endif
