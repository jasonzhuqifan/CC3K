//
//  GameGrid.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#include "GameGrid.h"
using namespace std;

GameGrid::GameGrid() {}

GameGrid::~GameGrid(){
    delete td;
    delete l;
    delete pc;
}

void GameGrid::init(){
    td = new textDisplay();
    l = new Floor();
    
}

void GameGrid::move(string dir){
    
}

void GameGrid::attack(string dir){
    
}

void GameGrid::setRace(string race){
    
}

void GameGrid::freeze(){
    
}

void GameGrid::clearGrid(){
    
}

