#ifndef Potion_hpp
#define Potion_hpp

#include "Item.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class Potion : public Item{
    bool tried;
public:
    ObstacleType getObsType() override;
    virtual ~Potion() = 0;
    bool hasTried();
    void setTried();
};

#endif
