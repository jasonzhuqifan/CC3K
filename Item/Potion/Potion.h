#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "Player.h"

class Potion : public Item, Player{
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
};

#endif
