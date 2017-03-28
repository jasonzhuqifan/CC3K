#include "WA.h"

WA::WA(Player* pc) : Potion(pc) {};

int WA::getAttack() {
    return (pc->getAttack() > 5) ? pc->getAttack()-5 : 0;
}
