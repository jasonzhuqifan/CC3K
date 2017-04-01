#include "PotionEffect.h"
#include "Info.h"

PotionEffect::PotionEffect(std::shared_ptr<Player> pc) : pc{pc} {
    Info f = getInfo();
    setPos(f.currentRow, f.currentCol);
}

double PotionEffect::getAttack() {
    return pc->getAttack();
}

double PotionEffect::getDefence() {
    return pc->getDefence();
}

double PotionEffect::getHP() {
    return pc->getHP();
}

PotionEffect::~PotionEffect() {}

void PotionEffect::move(std::string dir) {
    pc->move(dir);
}

std::string PotionEffect::getRace() {
    return pc->getRace();
}

int PotionEffect::getGold() {
    return pc->getGold();
}

Info PotionEffect::getInfo() {
    return pc->getInfo();
}

std::string PotionEffect::getActionMessage() {
    return pc->getActionMessage();
}
