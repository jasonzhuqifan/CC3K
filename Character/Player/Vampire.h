#ifndef Vampire_hpp
#define Vampire_hpp

#include "Player.h"
#include "string"

class Vampire:public Player{
public:
    Vampire();
    void attackIt(std::shared_ptr<Halfling> e) override;
    void attackIt(std::shared_ptr<Dwarf> e) override;
    void attackIt(std::shared_ptr<Dragon> e) override;
    void attackIt(std::shared_ptr<Elf> e) override;
    void attackIt(std::shared_ptr<Human> e) override;
    void attackIt(std::shared_ptr<Merchant> e) override;
    void attackIt(std::shared_ptr<Orc> e) override;
    ~Vampire();
};

#endif
