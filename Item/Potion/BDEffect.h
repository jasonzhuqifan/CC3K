//
//  BDEffect.hpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#ifndef BDEffect_hpp
#define BDEffect_hpp

class BD : public Potion{
    BD(Player* pc);
    double getDefence() override;
    GridObjectType getObjType() override;
};

#endif /* BDEffect_hpp */
