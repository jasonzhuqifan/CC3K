#include "BAEffect.h"

BAEffect::BAEffect(Player* pc) : PotionEffect(pc) {}

double BAEffect::getAttack() {
    return pc->getAttack() + 5;
}
