#include "Dragon.h"

using namespace std;

Dragon::Dragon(){
    HP = 150;
    Atk = 20;
    Def = 20;
    MaxHP = 150;
    stationary = true;
}

Dragon::~Dragon(){}

void Dragon::setDragonHoard(int x, int y){ //x = col  y = row
    dragonHoardy = y;
    dragonHoardx = x;
}

int Dragon::getDragonHoardC(){
    return dragonHoardx;
}

int Dragon::getDragonHoardR(){
    return dragonHoardy;
}
