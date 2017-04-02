#ifndef WAEffect_hpp
#define WAEffect_hpp

#include "PotionEffect.h"

class WAEffect : public PotionEffect{
public:
    WAEffect(std::shared_ptr<Player> pc);
    double getAttack() override;
};

#endif
