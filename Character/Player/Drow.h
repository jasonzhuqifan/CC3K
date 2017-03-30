#ifndef Drow_hpp
#define Drow_hpp

#include "Player.h"
#include "string"

class Drow : public Player{
public:
    Drow();
    void attackIt(Halfling* e) override;
    void attackIt(Merchant *e) override;
    ~Drow();
};


#endif /* Drow_hpp */
