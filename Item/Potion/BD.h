#ifndef BD_hpp
#define BD_hpp

#include "Potion.h"

class BD : public Potion{
    BD(Player* pc);
    double getDefence() override;
    GridObjectType getObjType() override;
};

#endif
