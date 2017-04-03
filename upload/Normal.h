#ifndef Normal_hpp
#define Normal_hpp
#include "Gold.h"


class Normal : public Gold{
public:
    Normal(int count = 1);
    GridObjectType getObjType() override;
};

#endif 
