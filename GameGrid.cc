#include "GameGrid.h"
#include "Drow.h"
#include "Goblin.h"
#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"

#include "Level.h"
#include "Player.h"
#include "textDisplay.h"
#include "Floor.h"

using namespace std;

GameGrid::GameGrid() {}

//GameGrid::~GameGrid(){
//    delete pc;
//}

void GameGrid::init(){
    l = make_shared<Floor>();
    shared_ptr<Floor> f = dynamic_pointer_cast<Floor>(l);
    pc = make_shared<Shade>();
    f->init(pc);
    l = f;
}

void GameGrid::move(string dir){
    pc->move(dir);
}

void GameGrid::use(string dir) {
    pc = l->use(pc, dir);
}

void GameGrid::attack(string dir){
    pc->attack(dir);
}

void GameGrid::setRace(char race){
    switch (race) {
        case 's': pc = make_shared<Shade>(); break;
        case 'd': pc = make_shared<Drow>(); break;
        case 'v': pc = make_shared<Vampire>(); break;
        case 'b': pc = make_shared<Goblin>(); break;
        case 't': pc = make_shared<Troll>(); break;
        default: throw "unknown race"; break;
    }
}

void GameGrid::freeze(){
    l->setFrozen();
}

//void GameGrid::clearGrid(){
//    delete l;
//}

ostream &operator<<(std::ostream &out, const GameGrid &g){
    out << *g.l;
    return out;
}
