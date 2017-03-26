#ifndef WA_hpp
#define WA_hpp

#include "Potion.h"

class WA : public Potion{
    WA(Player* pc);
    int getAttack() override;
    int getDefence() override;
};

#endif
