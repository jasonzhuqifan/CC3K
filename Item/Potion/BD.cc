#include "BD.h"

BD::BD(Player* pc) : Potion(pc) {};

double BD::getDefence() {
    return pc->getDefence() + 5;
}

GridObjectType BD::getObjType() {
    return GridObjectType::BD;
}
