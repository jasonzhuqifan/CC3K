#include "Potion.h"

ObstacleType Potion::getObsType() {
    return ObstacleType::BolckAll;
}

GridObjectType Potion::getObjType(){
    return GridObjectType::Potion;
}
