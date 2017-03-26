//
//  Vampire.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Vampire_hpp
#define Vampire_hpp

#include "Player.h"
#include "string"

class Vampire:public Player{
    Vampire();
    void attack(std::string dir) override;
    ~Vampire();
};

#endif /* Vampire_hpp */
