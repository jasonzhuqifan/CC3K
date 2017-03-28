#include "WD.h"

WD::WD(Player* pc) : Potion(pc) {};

int WD::getDefence() {
    return (pc->getDefence() > 5) ? pc->getDefence()-5 : 0;
}
