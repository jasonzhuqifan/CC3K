#include "Floor.h"
#include <cstdlib>
#include <ctime>

Floor::Floor(){}

Floor::~Floor(){}

Enemy Floor::makeEnemy(){
    srand(time(NULL));
    int spawnRate = rand()%18+1;
    if(spawnRate >= 1 && spawnRate <= 4){//human
        
    }else if(spawnRate )
    
}

Potion Floor::makePotion(){
    
}

Gold Floor::makeGold(){
}


void Floor::place(GridObjects &gO){
    
}

void Floor::placePlayer(){
    
}

void Floor::placeStair(){
    
}

void Floor::init(){
    
}

void Floor::clearFloor(){
    
}

void Floor::setFrozen(){
    
}






