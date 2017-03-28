#ifndef Enemies_hpp
#define Enemies_hpp

#include "Character.h"
#include "Observer.h"

class Enemy : public Character, Observer{
    void attack(Character* pc);
    void move();
public:
    void updateDamage(int damage);
    void notify(Subject &notifier) override;
    SubscriptionType getSubType() const override;
    GridObjectType getObjType() override;
    bool isDead();
};

#endif
