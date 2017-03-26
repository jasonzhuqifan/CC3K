#include "BA.h"

BA::BA(Player* pc) : Item(pc) {};

int BA::getAttack() {
    return pc->getAttack() + 5;
}

int BA::getDefence() {
    return pc->getDefence();
}
