#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"

class Potion : public Item{
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
};

#endif
