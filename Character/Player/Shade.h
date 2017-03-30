#ifndef Shade_hpp
#define Shade_hpp

#include "Player.h"
#include "string"

class Shade : public Player{
public:
    Shade();
    void attackIt(Halfling* e) override;
    ~Shade();
};


#endif /* Shade_hpp */
