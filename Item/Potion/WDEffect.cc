#include "WDEffect.h"

WDEffect::WDEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {};

double WDEffect::getDefence() {
    return (pc->getDefence() > 5) ? pc->getDefence()-5 : 0;
}
