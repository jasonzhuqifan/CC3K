#include "BAEffect.h"

BAEffect::BAEffect(shared_ptr<Player> pc) : PotionEffect(pc) {}

double BAEffect::getAttack() {
    return pc->getAttack() + ((pc) ? 7.5 : 5);
}
