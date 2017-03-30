//
//  WDEffect.hpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#ifndef WDEffect_hpp
#define WDEffect_hpp

class WD : public Potion{
    WD(Player* pc);
    double getDefence() override;
    GridObjectType getObjType() override;
};

#endif /* WDEffect_hpp */
