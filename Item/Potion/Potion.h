#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class Potion : public Item{
    bool tried;
public:
    Potion();
    ObstacleType getObsType() override;
    virtual ~Potion() = 0;
    bool hasTried();
};

#endif
