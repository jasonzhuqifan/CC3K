#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "Player.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class Potion : public Item, public virtual Player{
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
};

#endif
