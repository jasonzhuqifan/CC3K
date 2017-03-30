#ifndef Troll_hpp
#define Troll_hpp

#include "Player.h"
#include "string"

class Troll: public Player{
public:
    Troll();
    void attackIt(Halfling* e) override;
    ~Troll();
};

#endif /* Troll_hpp */
