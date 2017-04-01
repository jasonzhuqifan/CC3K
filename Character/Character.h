#ifndef Character_hpp
#define Character_hpp


#include "GridObjectType.h"
#include "ObstacleType.h"
#include "GridObjects.h"

class Character : public GridObjects{
protected:
    std::shared_ptr<std::vector<std::vector<std::shared_ptr<GridObjects>>>> gO;
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
    void setMap(std::shared_ptr<std::vector<std::vector<std::shared_ptr<GridObjects>>>> &g);
    ObstacleType getObsType() override;
};

#endif
