#ifndef Vampire_hpp
#define Vampire_hpp

#include "Player.h"
#include "string"

class Vampire:public Player{
    Vampire();
    void attack(std::string dir) override;
    ~Vampire();
};

#endif
