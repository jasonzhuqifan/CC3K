#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "Player.h"

class Potion : virtual public Item, public Player{
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
    
};

#endif
