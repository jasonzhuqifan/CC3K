#ifndef RH_hpp
#define RH_hpp


#include "Potion.h"
#include "Player.h"

class RH : public Potion{
    RH(Player* pc);
    void use();
    GridObjectType getObjType() override;
};

#endif
