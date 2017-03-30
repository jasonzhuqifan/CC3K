#ifndef Goblin_hpp
#define Goblin_hpp

#include "Player.h"
#include "string"

class Goblin : public Player{
public:
    Goblin();
    void attackIt(std::shared_ptr<Halfling> e) override;
     void attackIt(std::shared_ptr<Merchant> e) override;
    ~Goblin();
};

#endif /* Goblin_hpp */
