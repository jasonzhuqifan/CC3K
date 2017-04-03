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
public:
    Orc();
    void attack(std::shared_ptr<Goblin> pc, double true_def) override;
    ~Orc();
};

#endif /* Orc_hpp */
