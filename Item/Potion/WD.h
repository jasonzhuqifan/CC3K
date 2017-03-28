#ifndef WD_hpp
#define WD_hpp

#include "Potion.h"


class WD : public Potion{
    WD(Player* pc);
    int getDefence() override;
};

#endif
