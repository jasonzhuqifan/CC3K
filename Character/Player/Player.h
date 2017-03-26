#ifndef Player_hpp
#define Player_hpp

#include "Character.h"
#include "string"
#include "Subject.h"

class Player : public Character, Subject{

public:
    int getHP();
    int getAttack();
    int getDefence();
    int getMaxHP();
    int getGold();
    virtual void attack(std::string dir) = 0;
    void move(std::string dir);
    void use(std::string dir);
    bool reachStairs();
    GridObjectType getObjType();
    Info getInfo();
};

#endif
