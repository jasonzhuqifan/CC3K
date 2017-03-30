#ifndef WAEffect_hpp
#define WAEffect_hpp

#include "PotionEffect.h"

class WAEffect : public PotionEffect{
    WAEffect(Player* pc);
    double getAttack() override;
};

#endif
