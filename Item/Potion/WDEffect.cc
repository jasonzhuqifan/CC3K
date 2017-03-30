#include "WDEffect.h"

WDEffect::WDEffect(Player* pc) : PotionEffect(pc) {};

double WDEffect::getDefence() {
    return (pc->getDefence() > 5) ? pc->getDefence()-5 : 0;
}
