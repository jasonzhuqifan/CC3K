#ifndef BDEffect_hpp
#define BDEffect_hpp

#include "PotionEffect.h"

class BDEffect : public PotionEffect{
    BDEffect(Player* pc);
    double getDefence() override;
};

#endif
