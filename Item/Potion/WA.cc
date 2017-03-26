#include "WA.h"

WA::WA(Player* pc) : Item(pc) {};

int WA::getAttack() {
    return (pc->getAttack() > 5) ? pc->getAttack()-5 : 0;
}

int WA::getDefence() {
    return pc->getDefence();
}
