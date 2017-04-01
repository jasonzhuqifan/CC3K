//
//  FloorTile.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#include "FloorTile.h"

ObstacleType FloorTile::getObsType(){
    return ObstacleType::BlockNone;
}

GridObjectType FloorTile::getObjType(){
    return GridObjectType::FloorTiles;
}
