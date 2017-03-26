#include "BD.h"

BD::BD(Player* pc) : Item(pc) {};

int BD::getAttack() {
    return pc->getAttack();
}

int BD::getDefence() {
    return pc->getDefence() + 5;
}
