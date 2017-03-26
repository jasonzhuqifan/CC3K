#ifndef BD_hpp
#define BD_hpp

#include "Potion.h"

class BD : public Potion{
    BD(Player* pc);
    int getAttack() override;
    int getDefence() override;
};

#endif
