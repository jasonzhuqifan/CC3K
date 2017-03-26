#ifndef Item_hpp
#define Item_hpp

#include "GridObjects.h"
#include "Player.h"
#include "Subject.h"

class Item : public GridObjects, Subject, Player{
    Player *pc;
    
protected:
    Item();
    ~Item();
    virtual int getAttack();
    virtual int getDefence();
};

#endif
