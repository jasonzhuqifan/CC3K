#include "WDEffect.h"

WDEffect::WDEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {};

double WDEffect::getDefence() {
    return (pc->getDefence() > 5) ? pc->getDefence()-5 : 0;
}

std::string WDEffect::getActionMessage() {
    return pc->getActionMessage().append("Player uses potion. Def decreases.");
}
