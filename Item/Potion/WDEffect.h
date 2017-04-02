//
//  WDEffect.hpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#ifndef WDEffect_hpp
#define WDEffect_hpp

#include "PotionEffect.h"

class WDEffect : public PotionEffect{
public:
    WDEffect(std::shared_ptr<Player> pc);
    double getDefence() override;
};

#endif /* WDEffect_hpp */
