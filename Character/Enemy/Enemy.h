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
class Student;

class Enemy : public Character, public Observer, public std::enable_shared_from_this<Enemy>{
private:
    void move(int pc_r, int pc_c);
protected:
    bool Dead = false;
    bool isneutral = false;
    bool stationary = false;
public:
    virtual void attack(std::shared_ptr<Player> pc);
    virtual void attack(std::shared_ptr<Drow> pc, double true_def);
    virtual void attack(std::shared_ptr<Goblin> pc, double true_def);
    virtual void attack(std::shared_ptr<Shade> pc, double true_def);
    virtual void attack(std::shared_ptr<Troll> pc, double true_def);
    virtual void attack(std::shared_ptr<Vampire> pc, double true_def);
#ifdef Bonus
    virtual void attack(std::shared_ptr<Student> pc, double true_def);
#endif
    void setNeutral();
    bool isDead();
    int dropgold();
    void updateDamage(double damage);
    void notify(Subject &notifier) override;
    SubscriptionType getSubType() const override;
    GridObjectType getObjType() override;
};

#endif
