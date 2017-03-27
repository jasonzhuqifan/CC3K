#ifndef GameGrid_hpp
#define GameGrid_hpp

#include <iostream>
#include "Level.h"
#include "Player.h"
#include "textDisplay.h"
#include "Floor.h"
#include "Drow.h"
#include "Goblin.h"
#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"

class GameGrid {
    Level *l;
    Player *pc;
    
public:
    GameGrid();
    void init();
    void isWon();
    void move(string dir);
    void use(string dir);
    void attack(string dir);
    void setRace(char race);
    void freeze();
    void clearGrid();
    
    ~GameGrid();
    
    friend ostream & operator<<(std::ostream &out, GameGrid &g);
};

#endif
