#ifndef Item_hpp
#define Item_hpp

#include "GridObjects.h"

class Item : public GridObjects{
public:
    virtual int getAttack() = 0;
    virtual int getDefence() = 0 ;
};

#endif
