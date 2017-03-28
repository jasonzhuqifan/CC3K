#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "Player.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class Potion : public Item, public virtual Player{
    Player* pc;
public:
    Potion(Player* pc);
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
    virtual ~Potion() = 0;
};

#endif
