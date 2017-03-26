//
//  Shade.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Shade_hpp
#define Shade_hpp

#include "Player.h"
#include "string"

class Shade : public Player{
public:
    Shade();
    void attack(string dir) override;
    ~Shade();
};


#endif /* Shade_hpp */
