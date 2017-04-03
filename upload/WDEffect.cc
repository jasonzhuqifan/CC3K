#include "WDEffect.h"

WDEffect::WDEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {};

double WDEffect::getDefence() {
    return (pc->getDefence() > ((pc->ismagnify()) ? 7.5 : 5)) ? pc->getDefence()-((pc->ismagnify()) ? 7.5 : 5) : 0;
}
