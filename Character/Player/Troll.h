#ifndef Troll_hpp
#define Troll_hpp

#include "Player.h"
#include "string"

class Troll: public Player{
public:
    Troll();
    void attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc) override;
     void attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc) override;
    ~Troll();
};

#endif /* Troll_hpp */
