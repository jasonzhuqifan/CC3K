#ifndef Small_hpp
#define Small_hpp

#include "Gold.h"

class Small : public Gold{
public:
    Small(int count = 1);
    GridObjectType getObjType() override;
};

#endif 
