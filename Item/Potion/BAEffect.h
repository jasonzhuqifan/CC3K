#ifndef BAEffect_hpp
#define BAEffect_hpp

#include "PotionEffect.h"

class BAEffect : public PotionEffect {
public:
    BAEffect(std::shared_ptr<Player> pc);
    double getAttack() override;
    std::string getActionMessage() override;
};


#endif
