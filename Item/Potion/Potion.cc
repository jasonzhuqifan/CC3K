#include "Potion.h"

Potion::Potion(Player* pc) : pc{pc} {}

ObstacleType Potion::getObsType() {
    return ObstacleType::BolckAll;
}

double Potion::getAttack() {
    return pc->getAttack();
}

double Potion::getDefence() {
    return pc->getDefence();
}

double Potion::getHP() {
    return pc->getHP();
}

bool Potion::hasTried() {
    return tried;
}
