#include "Potion.h"

Potion::Potion(Player* pc) : pc{pc} {}

ObstacleType Potion::getObsType() {
    return ObstacleType::BolckAll;
}

GridObjectType Potion::getObjType(){
    return GridObjectType::Potion;
}

int Potion::getAttack() {
    return pc->getAttack();
}

int Potion::getDefence() {
    return pc->getDefence();
}

int Potion::getHP() {
    return pc->getHP();
}
