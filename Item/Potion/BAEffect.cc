//
//  BAEffect.cpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#include "BAEffect.h"

BA::BA(Player* pc) : Potion(pc) {}

double BA::getAttack() {
    return pc->getAttack() + 5;
}

GridObjectType BA::getObjType() {
    return GridObjectType::BA;
}
