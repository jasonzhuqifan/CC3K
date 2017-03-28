#ifndef BA_hpp
#define BA_hpp

#include <stdio.h>
#include "Potion.h"


class BA : public Potion{
public:
    BA(Player* pc);
    double getAttack() override;
    GridObjectType getObjType() override;
};

#endif
