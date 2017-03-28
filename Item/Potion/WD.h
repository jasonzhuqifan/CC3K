#ifndef WD_hpp
#define WD_hpp

#include "Potion.h"

class WD : public Potion{
    WD(Player* pc);
    double getDefence() override;
    GridObjectType getObjType() override;
};

#endif
