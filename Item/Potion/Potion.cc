#include "Potion.h"

Potion::Potion(Player* pc) : pc{pc} {}

ObstacleType Potion::getObsType() {
    return ObstacleType::BolckAll;
}

GridObjectType Potion::getObjType(){
    return GridObjectType::Potion;
}
