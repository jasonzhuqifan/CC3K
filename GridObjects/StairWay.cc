//
//  StairWay.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#include "StairWay.h"


ObstacleType StairWay::getObsType(){
    return ObstacleType::BlockEnemy;
}

GridObjectType StairWay::getObjType(){
    return  GridObjectType::StairWay;
}
