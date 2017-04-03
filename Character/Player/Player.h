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
#ifdef Bonus
class Nomair;
#endif

class Player : public Character, public std::enable_shared_from_this<Player> {
    bool reachStairs = false;
    bool isDead = false;
    bool onDoor = false;
    bool onPassage = false;
    bool onDragonHoard = false;
    bool usedBA = false;
    bool usedBD = false;
    bool usedWA = false;
    bool usedWD = false;
    bool usedRH = false;
    bool usedPH = false;
protected:
    bool enemyFrozen = false;
    std::string ActionMessage;
    int floorNum = 1;
    std::string playerRace;
    bool magnify = false;
    bool steal = false;
    bool autoheal = false;
public:
    virtual void setFrozen();
    virtual void attack(std::string dir, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Enemy> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Dwarf> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Dragon> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Elf> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Human> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc);
    virtual void attackIt(std::shared_ptr<Orc> e, std::shared_ptr<Player>pc);
#ifdef Bonus
    virtual void attackIt(std::shared_ptr<Nomair> e, std::shared_ptr<Player>pc);
#endif
    virtual void update_message(std::string s);
    void update_enemy(Enemy *e);
    virtual bool ismagnify();
    bool isautoheal();
    virtual void setHealth(double h);
    virtual void getDamage(double damage);
    virtual void move(std::string dir);
    virtual std::string getRace();
    virtual std::string getActionMessage();
    void check_dead(std::shared_ptr<Enemy> e);
    void PrintMessages();
    virtual void emptyMessage();
    GridObjectType getObjType() override;
    virtual std::shared_ptr<Player> getTrue();
    virtual bool hasReachedShairs();
    virtual bool hasDead();
    virtual int goUpstairs();
    virtual void memorizePotion(std::string s);
    virtual bool knowPotion(std::string s);
    virtual int getFloorNum();
};

#endif
