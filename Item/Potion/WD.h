#ifndef WD_hpp
#define WD_hpp

#include "Potion.h"

class WD : public Potion{
    GridObjectType getObjType() override;
};

#endif
