#ifndef Shade_hpp
#define Shade_hpp

#include "Player.h"
#include "string"

class Shade : public Player{
public:
    Shade();
    void attackIt(std::shared_ptr<Halfling> e) override;
     void attackIt(std::shared_ptr<Merchant> e) override;
    ~Shade();
};


#endif /* Shade_hpp */
