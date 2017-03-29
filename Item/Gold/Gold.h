//
//  Gold.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Gold_hpp
#define Gold_hpp


#include "Item.h"

class Gold : public Item{
public:
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
  
};

#endif /* Gold_hpp */
