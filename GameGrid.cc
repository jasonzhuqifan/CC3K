#include "GameGrid.h"
using namespace std;

GameGrid::GameGrid() {}

GameGrid::~GameGrid(){
    delete pc;
}

void GameGrid::init(){
    l = new Floor();
}

void GameGrid::move(string dir){
    pc->move(dir);
}

void GameGrid::attack(string dir){
    pc->attack(dir);
}

void GameGrid::setRace(char race){
    switch (race) {
        case 's': pc = new Shade(); break;
        case 'd': pc = new Drow(); break;
        case 'v': pc = new Vampire(); break;
        case 'b': pc = new Goblin(); break;
        case 't': pc = new Troll(); break;
        default: throw "unknown race"; break;
    }
}

void GameGrid::freeze(){
    l->setFrozen();
}

void GameGrid::clearGrid(){
    delete l;
}

