#include "BDEffect.h"

BDEffect::BDEffect(shared_ptr<Player> pc) : PotionEffect(pc) {};

double BDEffect::getDefence() {
    return pc->getDefence() + 5;
}
