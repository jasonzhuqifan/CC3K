#ifndef Player_hpp
#define Player_hpp

#include "Character.h"
#include "string"
#include <cstdlib>

class Dwarf;
class Dragon;
class Elf;
class Halfling;
class Human;
class Merchant;
class Orc;


class Player : public Character{
    bool reachStairs = false;
protected:
    bool magnify = false;
    bool steal = false;
    bool autoheal = false;
public:
    virtual double getHP();
    virtual double getAttack();
    virtual double getDefence();
    double getMaxHP();
    double getGold();
    virtual void attack(std::string dir);
    virtual void attackIt(std::shared_ptr<Enemy> e);
    virtual void attackIt(std::shared_ptr<Dwarf> e);
    virtual void attackIt(std::shared_ptr<Dragon> e);
    virtual void attackIt(std::shared_ptr<Elf> e);
    virtual void attackIt(std::shared_ptr<Halfling> e);
    virtual void attackIt(std::shared_ptr<Human> e);
    virtual void attackIt(std::shared_ptr<Merchant> e);
    virtual void attackIt(std::shared_ptr<Orc> e);
    bool ismagnify();
    bool isautoheal();
    void setHealth(double h);
    void getDamage(double damage);
    void move(std::string dir);
    GridObjectType getObjType() override;
};

#endif
