//
//  WAEffect.hpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#ifndef WAEffect_hpp
#define WAEffect_hpp

class WA : public Potion{
    WA(Player* pc);
    double getAttack() override;
    GridObjectType getObjType() override;
};

#endif /* WAEffect_hpp */
