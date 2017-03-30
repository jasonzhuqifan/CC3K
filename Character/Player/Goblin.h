#ifndef Goblin_hpp
#define Goblin_hpp

#include "Player.h"
#include "string"

class Goblin : public Player{
public:
    Goblin();
    void attackIt(Halfling* e) override;
     void attackIt(Merchant *e) override;
    ~Goblin();
};

#endif /* Goblin_hpp */
