#ifndef GameGrid_hpp
#define GameGrid_hpp

#include <iostream>

class Level;
class Player;
class Floor;

class GameGrid {
    std::shared_ptr<Level> l;
    std::shared_ptr<Player> pc;
    
    
public:
    GameGrid();
    void init();
    void isWon();
    void move(std::string dir);
    void use(std::string dir);
    void attack(std::string dir);
    void setRace(char race);
    void freeze();
    friend std::ostream &operator<<(std::ostream &out, const GameGrid &g);
    void win();
    void lose();
    void quit();
    void printStart();
    void printWin();
    void printLose();
    int calcScore();
};

#endif
