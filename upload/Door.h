//
//  Door.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Door_hpp
#define Door_hpp

#include "Cell.h"

class Door : public Cell{
public:
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
};

#endif /* Door_hpp */
