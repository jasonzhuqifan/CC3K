#include "WD.h"

WD::WD(Player* pc) : Item(pc) {};

int WD::getAttack() {
    return pc->getAttack();
}

int WD::getDefence() {
    return (pc->getDefence() > 5) ? pc->getDefence()-5 : 0;
}
