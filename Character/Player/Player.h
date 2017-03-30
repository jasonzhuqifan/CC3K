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
public:
    virtual double getHP();
    virtual double getAttack();
    virtual double getDefence();
    double getMaxHP();
    double getGold();
    virtual void attack(std::string dir);
    virtual void attackIt(Enemy *e);
    virtual void attackIt(Dwarf *e);
    virtual void attackIt(Dragon *e);
    virtual void attackIt(Elf *e);
    virtual void attackIt(Halfling *e);
    virtual void attackIt(Human *e);
    virtual void attackIt(Merchant *e);
    virtual void attackIt(Orc *e);
    void setHealth(double h);
    void getDamage(double damage);
    void move(std::string dir);
    GridObjectType getObjType() override;
};

#endif
