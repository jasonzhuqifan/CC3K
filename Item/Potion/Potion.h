#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "Player.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class Potion : public Item, public virtual Player{
    bool tried;
protected:
    Player* pc;
public:
    Potion(Player* pc);
    ObstacleType getObsType() override;
    virtual double getAttack() override;
    virtual double getDefence() override;
    virtual double getHP() override;
    virtual ~Potion() = 0;
    bool hasTried();
};

#endif
