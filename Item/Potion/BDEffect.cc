//
//  BDEffect.cpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#include "BDEffect.hpp"

BD::BD(Player* pc) : Potion(pc) {};

double BD::getDefence() {
    return pc->getDefence() + 5;
}

GridObjectType BD::getObjType() {
    return GridObjectType::BD;
}
