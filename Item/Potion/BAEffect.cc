#include "BAEffect.h"

BAEffect::BAEffect(std::shared_ptr<Player> pc) : PotionEffect(pc) {}

double BAEffect::getAttack() {
    return pc->getAttack() + ((pc->ismagnify()) ? 7.5 : 5);
}

std::string BAEffect::getActionMessage() {
    std::string message = "Player uses potion. Atk increases.";
    return pc->update_message(message);
}
