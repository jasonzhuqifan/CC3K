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
    void attack(Character* pc);
    void move(int r, int c);
protected:
     bool isneutral = false;
   
public:
    virtual void attack(Player* pc);
    virtual void attack(Drow* pc);
    virtual void attack(Goblin* pc);
    virtual void attack(Shade* pc);
    virtual void attack(Troll* pc);
    virtual void attack(Vampire* pc);
    void setNeutral();
    void updateDamage(double damage);
    void notify(Subject &notifier) override;
    SubscriptionType getSubType() const override;
    GridObjectType getObjType() override;
};

#endif
