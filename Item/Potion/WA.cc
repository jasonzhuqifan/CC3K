#include "WA.h"

WA::WA(Player* pc) : Potion(pc) {};

double WA::getAttack() {
    return (pc->getAttack() > 5) ? pc->getAttack()-5 : 0;
}

GridObjectType WA::getObjType() {
    return GridObjectType::WA;
}
