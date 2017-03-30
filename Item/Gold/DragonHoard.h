#ifndef DragonHoard_hpp
#define DragonHoard_hpp

#include "Gold.h"

class DragonHoard : public Gold{
public:
    DragonHoard(int count = 1);
    GridObjectType getObjType() override;
};

#endif
