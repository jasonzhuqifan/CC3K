#ifndef Drow_hpp
#define Drow_hpp

#include "Player.h"
#include "string"

class Drow : public Player{
public:
    Drow();
    void attack(std::string dir) override;
    ~Drow();
};


#endif /* Drow_hpp */
