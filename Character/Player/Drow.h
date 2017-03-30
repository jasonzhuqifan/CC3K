#ifndef Drow_hpp
#define Drow_hpp

#include "Player.h"
#include "string"

class Drow : public Player{
public:
    Drow();
    void attackIt(std::shared_ptr<Halfling> e) override;
    void attackIt(std::shared_ptr<Merchant> e) override;
    ~Drow();
};


#endif /* Drow_hpp */
