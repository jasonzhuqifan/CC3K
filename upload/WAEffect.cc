#include "WAEffect.h"

WAEffect::WAEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {};

double WAEffect::getAttack() {
    return (pc->getAttack() > ((pc->ismagnify()) ? 7.5 : 5)) ? pc->getAttack()-((pc->ismagnify()) ? 7.5 : 5) : 0;
}
