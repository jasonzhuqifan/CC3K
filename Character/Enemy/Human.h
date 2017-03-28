#ifndef Human_hpp
#define Human_hpp

#include "Enemy.h"

class Human : public Enemy{
    void attack(Player* pc) override;
};

#endif /* Human_hpp */
