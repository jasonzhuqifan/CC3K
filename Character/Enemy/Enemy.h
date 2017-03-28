#ifndef Enemies_hpp
#define Enemies_hpp

#include "Character.h"
#include "Observer.h"

class Enemy : public Character, public Observer{
    void attack(Character* pc);
    void move(int r, int c);
public:
    void updateDamage(double damage);
    void notify(Subject &notifier) override;
    SubscriptionType getSubType() const override;
    GridObjectType getObjType() override;
    bool isDead();
};

#endif
