#ifndef WD_hpp
#define WD_hpp

#include "Potion.h"

class WD : public Potion{
public:
    GridObjectType getObjType() override;
};

#endif
