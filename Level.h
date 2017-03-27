#ifndef Level_hpp
#define Level_hpp

#include "Enemy.h"
#include "Potion.h"
#include "Gold.h"
#include "Cell.h"
#include "Character.h"

struct Level{
    Level();
    virtual Enemy *createEnemy() = 0;
    virtual Potion *createPotion()=0;
    virtual Gold *createGold() =0;
    virtual Cell *createCell(char c) =0;
    virtual void placeEnemy() = 0;
    virtual void placePotion() = 0;
    virtual void placeGold() = 0;
    virtual void placeStair() = 0;
    virtual void placePlayer(Character *pc) = 0;
    virtual void setFrozen() = 0;
    virtual ~Level() = 0;
};

#endif /* Level_hpp */
