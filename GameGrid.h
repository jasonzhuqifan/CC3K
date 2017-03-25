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
#include "Level.h"
#include "Player.h"
#include "textDisplay.h"
using namespace std;

class GameGrid {
    textDisplay *td;
    level *l;
    player *pc;
    
public:
    GameGrid();
    void init();
    void isWon();
    void move(string dir);
    void use(string dir);
    void attack(string dir);
    void setRace(string race);
    void freeze();
    void clearGrid();
    
    ~GameGrid();
    
    friend ostream & operator<<(std::ostream &out, GameGrid &g);
};

#endif /* GameGrid_hpp */
