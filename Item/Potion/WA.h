#ifndef WA_hpp
#define WA_hpp

#include "Potion.h"

class WA : public Potion{
    WA(Player* pc);
    double getAttack() override;
    GridObjectType getObjType() override;
};

#endif
