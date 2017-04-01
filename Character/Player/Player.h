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
    bool onDoor = false;
    bool onPassage = false;
    TextDisplay *TD;
protected:
    std::string ActionMessage;
    int floorNum = 1;
    std::string playerRace;
    bool magnify = false;
    bool steal = false;
    bool autoheal = false;
public:
    virtual void attack(std::string dir, std::shared_ptr<Player>pc);
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
    virtual void move(std::string dir);
    virtual std::string getRace();
    virtual std::string getActionMessage();
    void check_dead(std::shared_ptr<Enemy> e);
    void PrintMessages();
    GridObjectType getObjType() override;
};

#endif
