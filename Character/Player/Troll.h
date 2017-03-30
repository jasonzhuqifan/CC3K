#ifndef Troll_hpp
#define Troll_hpp

#include "Player.h"
#include "string"

class Troll: public Player{
public:
    Troll();
    void attackIt(std::shared_ptr<Halfling> e) override;
     void attackIt(std::shared_ptr<Merchant> e) override;
    ~Troll();
};

#endif /* Troll_hpp */
