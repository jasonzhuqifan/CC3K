#ifndef Level_hpp
#define Level_hpp

#include "Enemy.h"
#include "Potion.h"
#include "Gold.h"

struct Level{
    Level();
    virtual Enemy makeEnemy() = 0;
    virtual Potion makePotion() = 0;
    virtual Gold makeGold() = 0;
    virtual void placeStair() = 0;
    virtual void placePlayer() = 0;
    virtual ~Level() = 0;
};

#endif /* Level_hpp */
