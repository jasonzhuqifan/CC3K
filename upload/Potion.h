#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class Potion : public Item{
public:
    ObstacleType getObsType() override;
    virtual ~Potion() = 0;
};

#endif
