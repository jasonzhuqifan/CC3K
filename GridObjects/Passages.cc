//
//  Passages.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//


#include "Passages.h"


ObstacleType Passages::GridObjects::getObsType(){
    return ObstacleType::BlockEnemy;
}

GridObjectType Passages::GridObjects::getObjType(){
    return GridObjectType::Others;
}
