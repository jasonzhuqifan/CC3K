//
//  Orc.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Orc_hpp
#define Orc_hpp

#include "Enemy.h"

class Orc : public Enemy{
    void attack(Drow* pc) override;
    void attack(Goblin* pc) override;
    void attack(Shade* pc) override;
    void attack(Troll* pc) override;
    void attack(Vampire* pc) override;
};

#endif /* Orc_hpp */
