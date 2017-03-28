#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "Player.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class Potion : public Item, public virtual Player{
protected:
    Player* pc;
public:
    Potion(Player* pc);
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
    virtual int getAttack() override;
    virtual int getDefence() override;
    virtual int getHP() override;
    virtual ~Potion() = 0;
};

#endif
