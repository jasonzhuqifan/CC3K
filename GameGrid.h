#ifndef GameGrid_hpp
#define GameGrid_hpp
#include <iostream>
#include "Level.h"
#include "Player.h"
#include "textDisplay.h"
using namespace std;

class Floor;

class GameGrid {
    TextDisplay *td;
    Level *l;
    Player *pc;
    
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

#endif
