//
//  WDEffect.cpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#include "WDEffect.hpp"

WD::WD(Player* pc) : Potion(pc) {};

double WD::getDefence() {
    return (pc->getDefence() > 5) ? pc->getDefence()-5 : 0;
}

GridObjectType WD::getObjType() {
    return GridObjectType::WD;
}
