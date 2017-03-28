#ifndef Player_hpp
#define Player_hpp

#include "Character.h"
#include "string"


class Player : public Character{
     bool reachStairs = false;
public:
    virtual double getHP();
    virtual double getAttack();
    virtual double getDefence();
    double getMaxHP();
    double getGold();
    virtual void attack(std::string dir);
    void setHealth(double h);
    void move(std::string dir);
    void use(std::string dir);
    GridObjectType getObjType() override;
};

#endif
