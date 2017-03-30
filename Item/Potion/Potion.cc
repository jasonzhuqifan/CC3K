#include "Potion.h"

ObstacleType Potion::getObsType() {
    return ObstacleType::BolckAll;
}

bool Potion::hasTried() {
    return tried;
}

void Potion::setTried() {
    tried = true;
}

Potion::~Potion() {}
