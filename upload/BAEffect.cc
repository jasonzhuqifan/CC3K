#include "BAEffect.h"

BAEffect::BAEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {}

double BAEffect::getAttack() {
    return pc->getAttack() + ((pc->ismagnify()) ? 7.5 : 5);
}
