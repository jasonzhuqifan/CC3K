#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "Player.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class Potion : virtual public Item, public Player{
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
    
    GridObjectType  getObjType() override;
};

#endif
