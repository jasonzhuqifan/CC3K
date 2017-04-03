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

void PotionEffect::getDamage(double damage) {
    pc->getDamage(damage);
}

void PotionEffect::attack(std::string dir, std::shared_ptr<Player>npc) {
    pc->attack(dir, npc);
}

void PotionEffect::setHealth(double h) {
    pc->setHealth(h);
}

void PotionEffect::update_message(std::string s) {
    pc->update_message(s);
}

std::string PotionEffect::getActionMessage() {
    return pc->getActionMessage();
}

void PotionEffect::emptyMessage() {
    pc->emptyMessage();
}

std::shared_ptr<Player> PotionEffect::getTrue() {
    return pc->getTrue();
}

bool PotionEffect::hasReachedShairs() {
    return pc->hasReachedShairs();
}

bool PotionEffect::hasDead() {
    return pc->hasDead();
}

int PotionEffect::goUpstairs() {
    return pc->goUpstairs();
}

void PotionEffect::memorizePotion(std::string s) {
    pc->memorizePotion(s);
}

bool PotionEffect::knowPotion(std::string s) {
    return pc->knowPotion(s);
}

int PotionEffect::getFloorNum() {
    return pc->getFloorNum();
}

bool PotionEffect::ismagnify() {
    return pc->ismagnify();
}

bool PotionEffect::setFrozen() {
    return pc->setFrozen();
}
