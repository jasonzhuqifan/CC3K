#include "Floor.h"
#include "Info.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <utility>

#include "Enemy.h"
#include "Potion.h"
#include "Gold.h"
#include "Player.h"
#include "Cell.h"

#include "Human.h"
#include "Halfling.h"
#include "Elf.h"
#include "Orc.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Dwarf.h"

#include "Small.h"
#include "Normal.h"
#include "DragonHoard.h"

#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WD.h"
#include "WA.h"

#include "Door.h"
#include "StairWay.h"
#include "Wall.h"
#include "Passages.h"
#include "FloorTile.h"

Floor::Floor(){}

Floor::~Floor(){}


void Floor::setItem(GridObjects *itemType, int x, int y){
    GridObjects *temp = gO[x][y];
    gO[x][y] = itemType;
    delete temp;
}

template <typename T>
void Floor::spawnItem(T itemType,int amount){
    srand(time(NULL));
    vector<vector<pair<int, int>>>* chamLst = c->getChamberList();
    int itemInCham[amount];
    
    for(int i =0;i < amount; i++){
        int x =0;
        int y = 0;
        
        while (true) {
            int chamberNum = rand()% 5+1;//random number from 1 to 5
            int randomPair = rand()%(*chamLst)[chamberNum].size();
            //randomly choose a pair in chamLst
            x = (*chamLst)[chamberNum][randomPair].first;
            y = (*chamLst)[chamberNum][randomPair].second;
            
            if(gO[x][y]->getObjType() == GridObjectType::Others){
                break;
            }
        }
        setItem(itemType, x,y);
    }
}


Enemy *Floor::createEnemy(){
    
    srand(time(NULL));
    int spawnRate = rand()%18+1; //random number from 1 to 18
    Enemy *spawnEnemy =  NULL;
    
    if(spawnRate >=1 && spawnRate <= 4){//Human
        spawnEnemy = new Human();
    }
    else if(spawnRate >= 5 && spawnRate <= 7){//Dwarf
        spawnEnemy = new Dwarf();
    }
    else if(spawnRate >= 8 && spawnRate <= 13){//Halfling
        spawnEnemy = new Halfling();
    }
    else if (spawnRate >= 14 && spawnRate <= 15){//Elf
        spawnEnemy = new Elf();
    }
    else if(spawnRate >= 16 && spawnRate <= 17){//Orc
        spawnEnemy = new Orc();
    }
    else{//Merchant
        spawnEnemy = new Merchant();
    }
    
    return spawnEnemy;
    
}

void Floor::placeEnemy(){
    srand(time(NULL));
    vector<vector<pair<int, int>>>* chamLst = c->getChamberList();
    int enemiesInCham[5] = {0};
    
    for(int i =0;i < enemyNum; i++){
        int x =0;
        int y =0;
        while(true){
            int chamberNum = rand()%5+1; //random number from 1 to 5
            int randomPair = rand()%(*chamLst)[chamberNum].size();
            //randomly choose a pair in chamList
            x = (*chamLst)[chamberNum][randomPair].first;
            y = (*chamLst)[chamberNum][randomPair].second;
            
            
            if(enemiesInCham[chamberNum] < 5 &&
               gO[x][y]->getObjType() == GridObjectType::Others){
                //if number of enemies in chamber no more than 5
                //and grid object type is other
                enemiesInCham[chamberNum]++;
                break;
            }
            
            
        }
        GridObjects *temp = gO[x][y];
        gO[x][y] = createEnemy();
        delete temp;
    }
    
}



Potion *Floor::createPotion(){
    srand(time(NULL));
    int spwanRate =  rand()%6+1;//random numberfrom 1 to 6
    Potion *spawnPotion = NULL;
    
    if(spwanRate == 1){//RH
        spawnPotion = new RH();
    }
    else if(spwanRate == 2){//BA
        spawnPotion = new BA();
    }
    else if(spwanRate == 3){//BD
        spawnPotion = new BD();
    }
    else if(spwanRate == 4){//PH
        spawnPotion = new PH();
    }
    else if (spwanRate == 5){//WD
        spawnPotion = new WD();
    }
    else{//WA
        spawnPotion = new WA();
    }
    
    return spawnPotion;
}



Gold *Floor::createGold(){
    srand(time(NULL));
    int spawnRate = rand()%8+1;
    Gold *spawnRate = NULL;
    
    
}


void Floor::placePotion(){
    
}



void Floor::placeGold(){
    
}

void Floor::placeStair(){
    srand(time(NULL));
    vector<vector<pair<int, int>>>* chamLst = c->getChamberList();
    
    int x =0;
    int y =0;
    
    while(true){
        int chamNUm = rand()%5+1;
        int randomPair = rand()%(*chamLst)[chamNUm].size();
        x = (*chamLst)[chamNUm][randomPair].first;
        y = (*chamLst)[chamNUm][randomPair].second;
        if(gO[x][y]->getObjType() == GridObjectType::Others){
            break;
        }
    }
    
    GridObjects *temp = gO[x][y];
    gO[x][y] = new StairWay;
    delete temp;
    
    
}

void Floor::placePlayer(Character *pc){
    srand(time(NULL));
    vector<vector<pair<int, int>>>* chamLst = c->getChamberList();
    
    int x =0;
    int y =0;
    
    while(true){
        int chamNUm = rand()%5+1;
        int randomPair = rand()%(*chamLst)[chamNUm].size();
        x = (*chamLst)[chamNUm][randomPair].first;
        y = (*chamLst)[chamNUm][randomPair].second;
        if(gO[x][y]->getObjType() == GridObjectType::Others){
            break;
        }
    }
    
    GridObjects *temp = gO[x][y];
    gO[x][y] = pc;
    delete temp;
    
    
}


Cell Floor::*createCell(char c){
    Cell cell;
    if(c == '|' || c == '_'){
        cell = new Wall();
    }
    else if (c == '#'){
        cell = new Passages();
    }
    else if (c == '+'){
        cell = new Door;
    }
    else{
        cell = new FloorTile();
    }
    return cell;
}
void Floor::init(Character *pc){
    td = new TextDisplay();
    
    //Read file floor.txt
    ifstream file("cc3kfloor.txt");
    string line;
    
    //construct the basic map store it in GridObjects
    while(getline(file, line)){
        for(int i =0;i < height ;i++){
            vector<GridObjects *> col;
            for(int j = 0; j < width; j++){
                col.emplace_back(createCell(line[j]));
            }
            gO[i].emplace_back(col);
        }
    }
    
    //Spawning order:
    placePlayer(pc);
    placeStair();
    placePotion();
    placeGold();
    placeEnemy();
    
}

void Floor::clearFloor(){
    gO.clear();
    delete  td;
}

void Floor::setFrozen(){
    
}

Player* Floor::use(Player* pc, string dir){
    Info info = pc->getInfo();
    int potionRow = info.currentRow;
    int potionCol = info.currentCol;
    if(dir == "no"){
        potionRow--;
    }else if(dir == "so"){
        potionRow++;
    }else if(dir == "ea"){
        potionCol++;
    }else if(dir == "we"){
        potionCol--;
    }else if(dir == "ne"){
        potionRow--;
        potionCol++;
    }else if(dir == "nw"){
        potionRow--;
        potionCol--;
    }else if(dir == "se"){
        potionRow++;
        potionCol++;
    }else if(dir == "sw"){
        potionRow++;
        potionCol--;
    }
    switch (gO[potionRow][potionCol]->getObjType()) {
        case GridObjectType::BA:
            pc = BA(pc);
            break;
        case GridObjectType::BD:
            pc = BD(pc);
            break;
        case GridObjectType::WA:
            pc = WA(pc);
            break;
        case GridObjectType::WD:
            pc = WD(pc);
            break;
        case GridObjectType::RH:
            pc->setHealth(pc->getHP()+10);
            break;
        case GridObjectType::PH:
            pc->setHealth(pc->getHP()-10);
            break;
        default:
            break;
    }
    //insert notify here
    return pc;
}




