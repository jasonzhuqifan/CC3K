//
//  Dragon.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Dragon_hpp
#define Dragon_hpp

#include "Enemy.h"

class Dragon : public Enemy{
    int dragonHoardx;
    int dragonHoardy;
public:
    Dragon();
    ~Dragon();
    void setDragonHoard(int x,int y);
};

#endif /* Dragon_hpp */
