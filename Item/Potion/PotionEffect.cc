//
//  PotionEffect.cpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#include "PotionEffect.hpp"

Potion::Potion(Player* pc) : pc{pc} {}

ObstacleType Potion::getObsType() {
    return ObstacleType::BolckAll;
}

double Potion::getAttack() {
    return pc->getAttack();
}

double Potion::getDefence() {
    return pc->getDefence();
}

double Potion::getHP() {
    return pc->getHP();
}

bool Potion::hasTried() {
    return tried;
}
