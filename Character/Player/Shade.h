#ifndef Shade_hpp
#define Shade_hpp

#include "Player.h"
#include "string"

class Shade : public Player{
public:
    Shade();
    void attack(string dir) override;
    ~Shade();
};


#endif /* Shade_hpp */
