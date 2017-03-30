#ifndef Enemies_hpp
#define Enemies_hpp
#include "Character.h"
#include "Observer.h"
#include "math.h"
#include <cstdlib>

class Drow;
class Goblin;
class Shade;
class Troll;
class Vampire;

class Enemy : public Character, public Observer{
private:
    void general_attack(std::shared_ptr<Player> pc);
    void move(int r, int c);
protected:
    bool Dead = false;
    bool isneutral = false;
    bool stationary = false;
public:
    virtual void attack(std::shared_ptr<Drow> pc);
    virtual void attack(std::shared_ptr<Goblin> pc);
    virtual void attack(std::shared_ptr<Shade> pc);
    virtual void attack(std::shared_ptr<Troll> pc);
    virtual void attack(std::shared_ptr<Vampire> pc);
    void setNeutral();
    bool isDead();
    int dropgold();
    void updateDamage(double damage);
    void notify(Subject &notifier) override;
    SubscriptionType getSubType() const override;
    GridObjectType getObjType() override;
};

#endif
