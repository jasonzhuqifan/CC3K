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


class Player : public Character, public std::enable_shared_from_this<Player> {
    bool reachStairs = false;
    bool onDoor = false;
    bool onPassage = false;
protected:
    std::string ActionMessage;
    int floorNum = 1;
    std::string playerRace;
    bool magnify = false;
    bool steal = false;
    bool autoheal = false;
public:
    virtual void attack(std::string dir, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Enemy> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Dwarf> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Dragon> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Elf> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Human> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Orc> e, std::shared_ptr<Player>pc);
    
    virtual void update_message(std::string s);
    void update_enemy(Enemy *e);
    bool ismagnify();
    bool isautoheal();
    virtual void setHealth(double h);
    virtual void getDamage(double damage);
    virtual void move(std::string dir);
    virtual std::string getRace();
    virtual std::string getActionMessage();
    void check_dead(std::shared_ptr<Enemy> e);
    void PrintMessages();
    void emptyMessage();
    GridObjectType getObjType() override;
    virtual std::shared_ptr<Player> getTrue();
};

#endif
