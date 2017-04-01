#ifndef BDEffect_hpp
#define BDEffect_hpp

#include "PotionEffect.h"

class BDEffect : public PotionEffect{
public:
    BDEffect(std::shared_ptr<Player> pc);
    double getDefence() override;
    std::string getActionMessage() override;
};

#endif
