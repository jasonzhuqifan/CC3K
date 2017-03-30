#ifndef RH_hpp
#define RH_hpp


#include "Potion.h"
#include "Player.h"

class RH : public Potion{
public:
    GridObjectType getObjType() override;
};

#endif
