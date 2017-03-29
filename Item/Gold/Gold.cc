//
//  Gold.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#include "Gold.h"


ObstacleType Gold::getObsType(){
    return ObstacleType::BlockEnemy;
}

GridObjectType Gold::getObjType(){
    return GridObjectType::Gold;
}
