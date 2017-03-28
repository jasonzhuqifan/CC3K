#ifndef Enemies_hpp
#define Enemies_hpp

#include "Character.h"
#include "Observer.h"
#include "math.h"

class Drow;
class Goblin;
class Shade;
class Troll;
class Vampire;

<<<<<<< HEAD
class Enemy : public Character, public Observer{
    void attack(Character* pc);
=======
class Enemy : public Character, Observer{
>>>>>>> origin/master
    void move(int r, int c);
public:
    virtual void attack(Player* pc);
    virtual void attack(Drow* pc) = 0;
    virtual void attack(Goblin* pc) = 0;
    virtual void attack(Shade* pc) = 0;
    virtual void attack(Troll* pc) = 0;
    virtual void attack(Vampire* pc) = 0;
    void updateDamage(double damage);
    void notify(Subject &notifier) override;
    SubscriptionType getSubType() const override;
    GridObjectType getObjType() override;
    bool isDead();
};

#endif
