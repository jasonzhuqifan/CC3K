#include "WAEffect.h"

WAEffect::WAEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {};

double WAEffect::getAttack() {
    return (pc->getAttack() > 5) ? pc->getAttack()-5 : 0;
}
