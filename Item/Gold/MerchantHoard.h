#ifndef MerchantHoard_hpp
#define MerchantHoard_hpp

#include "Gold.h"

class MerchantHoard : public Gold{
public:
    MerchantHoard(int count = 1);
    GridObjectType getObjType() override;
};

#endif 
