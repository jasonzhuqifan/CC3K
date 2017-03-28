#ifndef Player_hpp
#define Player_hpp

#include "Character.h"
#include "string"


class Player : public Character{

public:
    virtual int getHP();
    virtual int getAttack();
    virtual int getDefence();
    int getMaxHP();
    int getGold();
    virtual void attack(std::string dir) = 0;
    void move(std::string dir);
    void use(std::string dir);
    bool reachStairs();
    GridObjectType getObjType() override;
};

#endif
