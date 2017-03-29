//
//  Wall.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Wall_hpp
#define Wall_hpp


#include "Cell.h"

class Wall : public Cell{
public:
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
};

#endif /* Wall_hpp */
