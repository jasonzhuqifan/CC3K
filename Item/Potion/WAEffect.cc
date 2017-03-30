//
//  WAEffect.cpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#include "WAEffect.hpp"

WA::WA(Player* pc) : Potion(pc) {};

double WA::getAttack() {
    return (pc->getAttack() > 5) ? pc->getAttack()-5 : 0;
}

GridObjectType WA::getObjType() {
    return GridObjectType::WA;
}
