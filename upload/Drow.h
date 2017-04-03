#ifndef Drow_hpp
#define Drow_hpp

#include "Player.h"
#include "string"

class Drow : public Player{
public:
    Drow();
    void attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc) override;
    void attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc) override;
    ~Drow();
};


#endif /* Drow_hpp */
