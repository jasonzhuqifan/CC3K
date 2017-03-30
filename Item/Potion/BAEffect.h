#ifndef BAEffect_hpp
#define BAEffect_hpp

#include "PotionEffect.h"

class BAEffect : public PotionEffect {
public:
    BAEffect(Player* pc);
    double getAttack() override;
};


#endif
