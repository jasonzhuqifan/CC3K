//
//  Wall.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#include "Wall.h"


ObstacleType Wall::getObsType(){
    return ObstacleType::BolckAll;
}

GridObjectType Wall::getObjType(){
    return GridObjectType::Wall;
}
