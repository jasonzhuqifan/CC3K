//
//  PotionEffect.hpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#ifndef PotionEffect_hpp
#define PotionEffect_hpp

class Potion : public Item, public virtual Player{
    bool tried;
protected:
    Player* pc;
public:
    Potion(Player* pc);
    ObstacleType getObsType() override;
    virtual double getAttack() override;
    virtual double getDefence() override;
    virtual double getHP() override;
    virtual ~Potion() = 0;
    bool hasTried();
};


#endif /* PotionEffect_hpp */
