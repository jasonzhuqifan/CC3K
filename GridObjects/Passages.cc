//
//  Passages.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//


#include "Passages.h"

ObstacleType Passages::getObsType(){
    return ObstacleType::BlockEnemy;
}

GridObjectType Passages::getObjType(){
    return GridObjectType::Passage;
}
