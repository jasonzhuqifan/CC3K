#ifndef PH_hpp
#define PH_hpp

#include "Potion.h"

class PH : public Potion {
    GridObjectType getObjType() override;
};

#endif
