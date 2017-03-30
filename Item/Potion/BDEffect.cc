#include "BDEffect.h"

BDEffect::BDEffect(Player* pc) : PotionEffect(pc) {};

double BDEffect::getDefence() {
    return pc->getDefence() + 5;
}
