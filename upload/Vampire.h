#ifndef Vampire_hpp
#define Vampire_hpp

#include "Player.h"
#include "string"

class Vampire:public Player{
public:
    Vampire();
    void attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc) override;
    void attackIt(std::shared_ptr<Dwarf> e, std::shared_ptr<Player>pc) override;
    void attackIt(std::shared_ptr<Dragon> e, std::shared_ptr<Player>pc) override;
    void attackIt(std::shared_ptr<Elf> e, std::shared_ptr<Player>pc) override;
    void attackIt(std::shared_ptr<Human> e, std::shared_ptr<Player>pc) override;
    void attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc) override;
    void attackIt(std::shared_ptr<Orc> e, std::shared_ptr<Player>pc) override;
    ~Vampire();
};

#endif
