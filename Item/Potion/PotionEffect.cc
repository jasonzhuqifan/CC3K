#include "PotionEffect.h"

PotionEffect::PotionEffect(Player* pc) : pc{pc} {}

double PotionEffect::getAttack() {
    return pc->getAttack();
}

double PotionEffect::getDefence() {
    return pc->getDefence();
}

double PotionEffect::getHP() {
    return pc->getHP();
}
