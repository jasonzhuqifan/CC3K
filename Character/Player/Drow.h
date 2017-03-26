//
//  Drow.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Drow_hpp
#define Drow_hpp

#include "Player.h"
#include "string"

class Drow : public Player{
    Drow();
    void attack(std::string dir) override;
    ~Drow();
};


#endif /* Drow_hpp */
