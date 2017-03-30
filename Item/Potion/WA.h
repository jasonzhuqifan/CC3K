#ifndef WA_hpp
#define WA_hpp

#include "Potion.h"

class WA : public Potion{
    GridObjectType getObjType() override;
};

#endif
