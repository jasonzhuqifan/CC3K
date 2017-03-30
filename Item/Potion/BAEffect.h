//
//  BAEffect.hpp
//  CC3K
//
//  Created by Yinong Wang on 2017-03-29.
//  Copyright © 2017 Yinong Wang. All rights reserved.
//

#ifndef BAEffect_hpp
#define BAEffect_hpp

class BA : public Potion{
public:
    BA(Player* pc);
    double getAttack() override;
    GridObjectType getObjType() override;
};


#endif /* BAEffect_hpp */
