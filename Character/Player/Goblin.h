#ifndef Goblin_hpp
#define Goblin_hpp

#include "Player.h"
#include "string"

class Goblin : public Player{
public:
    Goblin();
    void attack(std::string dir) override;
    ~Goblin();
};

#endif /* Goblin_hpp */
