#ifndef Troll_hpp
#define Troll_hpp

#include "Player.h"
#include "string"

class Troll: public Player{
    Troll();
    void attack(string dir) override;
    ~Troll();
};

#endif /* Troll_hpp */
