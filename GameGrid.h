#ifndef GameGrid_hpp
#define GameGrid_hpp

#include <iostream>
using namespace std;

class Level;
class Player;
class Floor;

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
    
};

#endif
