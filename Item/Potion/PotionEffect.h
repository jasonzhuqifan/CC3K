#ifndef PotionEffect_hpp
#define PotionEffect_hpp

#include "Player.h"

class PotionEffect : public Player{
protected:
    std::shared_ptr<Player> pc;
public:
    PotionEffect(std::shared_ptr<Player> pc);
    virtual double getAttack() override;
    virtual double getDefence() override;
    virtual double getHP() override;
    virtual ~PotionEffect() = 0;
};


#endif
