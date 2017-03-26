//
//  Goblin.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Goblin_hpp
#define Goblin_hpp

#include "Player.h"
#include "string"

class Goblin : public Player{
    Goblin();
    void attack(std::string dir) override;
    ~Goblin();
};

#endif /* Goblin_hpp */
