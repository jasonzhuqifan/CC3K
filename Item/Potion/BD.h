#ifndef BD_hpp
#define BD_hpp

#include "Potion.h"

class BD : public Potion{
public:
    GridObjectType getObjType() override;
};

#endif
