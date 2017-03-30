#ifndef PH_hpp
#define PH_hpp

#include "Potion.h"

class PH : public Potion {
public:
    GridObjectType getObjType() override;
};

#endif
