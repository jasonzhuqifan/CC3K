#ifndef Player_hpp
#define Player_hpp

#include "Character.h"

class Player : public Character{
public:
    virtual void attack(string dir) = 0;
    void move(string dir);
    void use(string dir);
    bool reachStairs();
};

#endif
