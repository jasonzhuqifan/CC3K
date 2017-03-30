#ifndef Vampire_hpp
#define Vampire_hpp

#include "Player.h"
#include "string"

class Vampire:public Player{
public:
    Vampire();
    void attackIt(Halfling* e) override;
    void attackIt(Dwarf *e) override;
    void attackIt(Dragon *e) override;
    void attackIt(Elf *e) override;
    void attackIt(Human *e) override;
    void attackIt(Merchant *e) override;
    void attackIt(Orc *e) override;
    ~Vampire();
};

#endif
