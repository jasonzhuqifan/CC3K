#ifndef Enemies_hpp
#define Enemies_hpp

#include "Character.h"
#include "Subject.h"

class Enemy : public Character, Observer{
    void attack(Character* pc);
    void move();
public:
    void notify(Subject &notifier) override;
    bool isDead();
};

#endif
