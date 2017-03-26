#ifndef Player_hpp
#define Player_hpp

#include "Character.h"
<<<<<<< Updated upstream
#include "string"
=======
#include "Subject.h"
>>>>>>> Stashed changes

class Player : public Character, Subject{
protected:
    int HP;
    int Atk;
    int Def;
    int MaxHP;
    int Gold;
    //player 要不要加x y坐标？ 怎么update info
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
