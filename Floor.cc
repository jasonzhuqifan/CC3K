#include "Floor.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <utility>
Floor::Floor(){}

Floor::~Floor(){}


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
    int chamNumber = rand()*5+1; //random number from 1 to 5
    int row = 0;
    int col = 0;
    for(int i =0;i < enemyNum ;i++){
        gO[row][col] = createEnemy();
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



bool Floor::isChamber(vector<vector<pair<int, int>>>* chamLst,int row,int col,int chamNUm){
    for(int i =0; i < chamLst[chamberNum].size() ; i++){
        if(row == (*chamLst)[chamberNum][i].first &&
           col == (*chamLst)[chamberNum][i].second){
            return true;
        }
    }
    return false;
    
}

void Floor::placePotion(){
    srand(time(NULL));
    vector<vector<pair<int, int>>>* chamLst = c->getChamberList();
    int num=0;
    
    
    for(int i =0;i < enemyNum; i++){
        while(true){
            int row = rand()%width+1; //random number from 1 to width
            int col = rand()%height+1; //random number from 1 to height
            
        }
    }
    
    
}

Gold Floor::createGold(){
    srand(time(NULL));
    int spawnRate = rand()%8+1;
    Gold *spawnGold = NULL;
    if (spawnRate >= 1 && spawnRate <= 5){//normal
        spawnGold = new Normal();
    }
    else if (spawnRate >= 6 && spawnRate <= 7){//dragonHaord
        spawnGold = new DragonHoard();
    }
    else{
        spawnGold = new Small();
    }
    return spawnGold;
}


void Floor::placeGold(){
    srand(time(NULL));
}




void Floor::placePlayer(){
    
}

void Floor::placeStair(){
    
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
void Floor::init(){
    
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
    placePlayer();
    placeStair();
    placePotion();
    placeGold();
    placeEnemy();
    
}

void Floor::clearFloor(){
    gO.clear();
    
}

void Floor::setFrozen(){
    
}

void Floor::place(GridObjects &gO){
    
}






