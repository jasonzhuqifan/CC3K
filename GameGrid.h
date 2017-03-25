//
//  GameGrid.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef GameGrid_hpp
#define GameGrid_hpp
#include <iostream>
using namespace std;

class GameGrid {
    friend std::ostream & operator<<(std::ostream &out, GameGrid &g);
};

#endif /* GameGrid_hpp */
