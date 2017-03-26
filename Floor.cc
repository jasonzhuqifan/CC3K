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



void Floor::placePotion(){
    srand(time(NULL));
    vector<vector<pair<int, int>>>* chamLst = c->getChamberList();
    int potionInCham[5] = {0};
    
    for(int i =0; i < potionNum ;i++){
        int x =0;
        int y =0;
        while (true) {
            int chamberNum = rand()%5+1;//random number from 1 to 5
            int randomPair = rand()%(*chamLst)[chamberNum].size();
            
            x = (*chamLst)[chamberNum][randomPair].first;
            y = (*chamLst)[chamberNum][randomPair].second;
            
            if(potionInCham[chamberNum] < 3 &&
               gO[x][y]->getObjType() == GridObjectType::Others){
                potionInCham[chamberNum]++;
                break;
            }
            
        }
        
        GridObjects *temp = gO[x][y];
        gO[x][y] = createPotion();
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
    else{//small
        spawnGold = new Small();
    }
    return spawnGold;
}


void Floor::placeGold(){
    srand(time(NULL));
    vector<vector<pair<int, int>>>* chamLst = c->getChamberList();
    int goldInCham[5] = {0};
    
    
    for(int i =0;i < goldNum ; i++){
        int x =0;
        int y = 0
        ;
        while (true)) {
            int chamberNum = rand()% 5+1;//random number from 1 to 5
            int randomPair = rand()%(*chamLst)[chamberNum].size();
            //randomly choose a pair in chamLst
            x = (*chamLst)[chamberNum][randomPair].first;
            y = (*chamLst)[chamberNum][randomPair].second;
            
            
            if(goldInCham[chamberNum] < 3 &&
               gO[x][y]->getObjType() == GridObjectType::Others){
                goldInCham[chamberNum]++;
                break;
            }
        }
        
        GridObjectType *temp = gO[x][y];
        gO[x][y] = createGold();
        delete temp;
        
    }
    
    
    
}

void Floor::placeStair(){
    srand(time(NULL));
    vector<vector<pair<int, int>>>* chamLst = c->getChamberList();
    int chamNUm = rand()%5+1;
    int randomPair = rand()%(*chamLst)[chamNUm].size();
    int x =0;
    int y =0;
    
    while(true){
        x = (*chamLst)[chamNUm][randomPair].first;
        y = (*chamLst)[chamNUm][randomPair].second;
    }
    
    if(gO[x][y]->getObjType() == GridObjectType::Others){
        break;
    }
    
    GridObjects *temp = gO[x][y];
    gO[x][y] = new StairWay;
    delete temp;
    
    
}

void Floor::placePlayer(){
    
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






