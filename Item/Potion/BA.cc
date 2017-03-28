#include "BA.h"

BA::BA(Player* pc) : Potion(pc) {}

double BA::getAttack() {
    return pc->getAttack() + 5;
}

GridObjectType BA::getObjType() {
    return GridObjectType::BA;
}
