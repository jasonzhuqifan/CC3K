#include "BDEffect.h"

BDEffect::BDEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {};

double BDEffect::getDefence() {
    return pc->getDefence() + 5;
}

std::string BDEffect::getActionMessage() {
    return pc->getActionMessage().append("Player uses potion. Def increases.");
}
