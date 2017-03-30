#include "Potion.h"

Potion::Potion() {}

ObstacleType Potion::getObsType() {
    return ObstacleType::BolckAll;
}

bool Potion::hasTried() {
    return tried;
}

void Potion::setTried() {
    tried = true;
}
