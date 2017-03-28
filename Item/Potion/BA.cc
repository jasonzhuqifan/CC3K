#include "BA.h"

BA::BA(Player* pc) : Potion(pc) {}

int BA::getAttack() {
    return pc->getAttack() + 5;
}
