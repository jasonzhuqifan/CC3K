#include "WD.h"

WD::WD(Player* pc) : Potion(pc) {};

double WD::getDefence() {
    return (pc->getDefence() > 5) ? pc->getDefence()-5 : 0;
}

GridObjectType WD::getObjType() {
    return GridObjectType::WD;
}
