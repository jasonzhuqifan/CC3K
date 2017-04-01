#include "WAEffect.h"

WAEffect::WAEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {};

double WAEffect::getAttack() {
    return (pc->getAttack() > 5) ? pc->getAttack()-5 : 0;
}

std::string WAEffect::getActionMessage() {
    return pc->getActionMessage().append("Player uses potion. Atk decreases.");
}
