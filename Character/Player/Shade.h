#ifndef Shade_hpp
#define Shade_hpp

#include "Player.h"
#include "string"

class Shade : public Player{
public:
    Shade();
    void attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc) override;
     void attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc) override;
    ~Shade();
};


#endif /* Shade_hpp */
