//
//  Troll.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Troll_hpp
#define Troll_hpp

#include "Player.h"
#include "string"

class Troll: public Player{
    Troll();
    void attack(string dir) override;
    ~Troll();
};

#endif /* Troll_hpp */
