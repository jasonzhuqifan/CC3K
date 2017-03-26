#ifndef Item_hpp
#define Item_hpp

#include "GridObjects.h"
#include "Player.h"
#include "Subject.h"

class Item : public GridObjects, Subject, Player{
protected:
    Player *pc;
    
protected:
    Item(Player* pc);
    ~Item();
    virtual int getAttack();
    virtual int getDefence();
};

#endif
