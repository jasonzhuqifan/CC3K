#ifndef WA_hpp
#define WA_hpp

#include "Potion.h"

class WA : public Potion{
public:
    GridObjectType getObjType() override;
};

#endif
