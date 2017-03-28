#include "BD.h"

BD::BD(Player* pc) : Potion(pc) {};

int BD::getDefence() {
    return pc->getDefence() + 5;
}
