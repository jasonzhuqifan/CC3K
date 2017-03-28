#ifndef BD_hpp
#define BD_hpp

#include "Potion.h"

class BD : public Potion{
    BD(Player* pc);
    int getDefence() override;
};

#endif
