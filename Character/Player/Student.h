
#ifndef Student_hpp
#define Student_hpp
#include "Player.h"

class Student : public Player{
    Student();
    void attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc) override;
    void attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc) override;
    ~Student();
    
};


#endif /* Student_hpp */
