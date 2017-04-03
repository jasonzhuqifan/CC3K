#include "BDEffect.h"

BDEffect::BDEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {};

double BDEffect::getDefence() {
    return pc->getDefence() + ((pc->ismagnify()) ? 7.5 : 5);
}

