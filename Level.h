//
//  Level.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp

#include "Enemy.h"
#include "Potion.h"
#include "Gold.h"

struct level{
    level();
    virtual enemy makeEnemy() = 0;
    virtual potion makePotion() = 0;
    virtual  gold makeGold() = 0;
    virtual void placeStair() = 0;
    virtual void placePlayer() = 0;
    ~level();
};

#endif /* Level_hpp */
