#ifndef Gold_hpp
#define Gold_hpp


#include "Item.h"

class Gold : public Item{
public:
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
  
};

#endif /* Gold_hpp */
