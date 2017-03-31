#include "Floor.h"
#include "Info.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <utility>

#include "textDisplay.h"
#include "ObstacleType.h"
#include "GridObjectType.h"
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

#include "BAEffect.h"
#include "BDEffect.h"
#include "WDEffect.h"
#include "WAEffect.h"

#include "Door.h"
#include "StairWay.h"
#include "Wall.h"
#include "Passages.h"
#include "FloorTile.h"

using namespace std;

Floor::Floor(){

}

Floor::~Floor(){}


void Floor::setItem(shared_ptr<GridObjects> itemType, int x, int y){
    gO[y][x] = itemType;
}

template <typename T>
pair<int, int> Floor::spawnItem(T itemType,char type){
    int x =0;
    int y = 0;
    while (true) {
        int chamberNum = rand()%5;//random number from 1 to 5
        int randomPair = rand()%((*chamLst)[chamberNum].size());
        //randomly choose a pair in chamLst
        y = (*chamLst)[chamberNum][randomPair].first;
        x = (*chamLst)[chamberNum][randomPair].second;
        
        if(gO[y][x]->getObjType() == GridObjectType::Others){
            break;
        }
    }
    
    setItem(itemType, x, y);
    td->spawn(x, y, type);
    pair<int,int> pos;
    pos.first=y;
    pos.second=x;
    return pos;
}


shared_ptr<Enemy> Floor::createEnemy(char *type){
    int spawnRate = rand()%18+1; //random number from 1 to 18
    shared_ptr<Enemy> spawnEnemy = NULL;
    if(spawnRate >=1 && spawnRate <= 4){//Human
        spawnEnemy = make_shared<Human>();
        *type = 'H';
    }
    else if(spawnRate >= 5 && spawnRate <= 7){//Dwarf
        spawnEnemy = make_shared<Dwarf>();
        *type = 'D';
    }
    else if(spawnRate >= 8 && spawnRate <= 13){//Halfling
        spawnEnemy = make_shared<Halfling>();
        *type = 'L';
    }
    else if (spawnRate >= 14 && spawnRate <= 15){//Elf
        spawnEnemy = make_shared<Elf>();
        *type = 'E';
    }
    else if(spawnRate >= 16 && spawnRate <= 17){//Orc
        spawnEnemy = make_shared<Orc>();
        *type = 'O';
    }
    else{//Merchant
        spawnEnemy = make_shared<Merchant>();
        *type = 'M';
    }
    
    return spawnEnemy;
    
}

void Floor::placeEnemy(shared_ptr<Character> pc){
    char type;
    
    for(int i =0;i < enemyNum; i++){
        int x =0;
        int y =0;
        while(true){
            int chamberNum = rand()%5; //random number from 1 to 5
            int randomPair = rand()%(*chamLst)[chamberNum].size();
            //randomly choose a pair in chamList
            y = (*chamLst)[chamberNum][randomPair].first;
            x = (*chamLst)[chamberNum][randomPair].second;
            
            if(gO[y][x]->getObsType() == ObstacleType::BlockNone){
                //if number of enemies in chamber no more than 5
                //and grid object type is other
                break;
            }
            
        }
        
        shared_ptr<Enemy> newEnemy = createEnemy(&type);
        gO[y][x] = newEnemy;
        td->spawn(x, y, type);
    }
}

shared_ptr<Potion> Floor::createPotion(){
    int spwanRate =  rand()%6+1;//random numberfrom 1 to 6
    shared_ptr<Potion> spawnPotion = NULL;
    
    if(spwanRate == 1){//RH
        spawnPotion = make_shared<RH>();
    }
    else if(spwanRate == 2){//BA
        spawnPotion = make_shared<BA>();
    }
    else if(spwanRate == 3){//BD
        spawnPotion = make_shared<BD>();
    }
    else if(spwanRate == 4){//PH
        spawnPotion = make_shared<PH>();
    }
    else if (spwanRate == 5){//WD
        spawnPotion = make_shared<WD>();
    }
    else{//WA
        spawnPotion = make_shared<WA>();
    }
    
    return spawnPotion;
}

void Floor::placePotion(){
    for (int i =0; i < potionNum; i++) {
        shared_ptr<Potion> newPotion = createPotion();
        spawnItem(newPotion,'P');
    }
}

void Floor::placeGold(){
    pair<int,int> pos;
    shared_ptr<Gold> spawnGold = NULL;
    shared_ptr<Dragon> spawnDragon = NULL;
    for (int i =0;i < goldNum;i++){

        int spawnRate = rand()%8+1;
        if (spawnRate == 1){//Dragon Hoard
            spawnGold = make_shared<DragonHoard>();
            spawnDragon = make_shared<Dragon>();
            pos = spawnItem(spawnGold,'G');
            int y = pos.first;
            int x = pos.second;
            //0 1 2
            //3 G 4
            //5 6 7
            for(int i =0; i < 8 ;i++){
                int spawnPos = rand()%8;
                switch (i){
                    case 0:
                        if (gO[y+1][x-1]->getObjType() == GridObjectType::Others){
                            gO[y+1][x-1] = spawnDragon;
                            td->spawn(x-1, y+1, 'D');
                        }
                        break;
                    case 1:
                        if(gO[y+1][x]->getObjType() == GridObjectType::Others){
                            gO[y+1][x] = spawnDragon;
                            td->spawn(x, y+1, 'D');
                        }
                        break;
                    case 2:
                        if(gO[y+1][x+1]->getObjType() == GridObjectType::Others){
                            gO[y+1][x+1] = spawnDragon;
                            td->spawn(x+1, y+1, 'D');
                        }
                        break;
                    case 3:
                        if(gO[y-1][x]->getObjType() == GridObjectType::Others){
                            gO[y-1][x] = spawnDragon;
                            td->spawn(x-1, y, 'D');
                        }
                        break;
                    case 4:
                        if(gO[y+1][x]->getObjType() == GridObjectType::Others){
                            gO[y+1][x] = spawnDragon;
                            td->spawn(x+1, y+1, 'D');
                        }
                        break;
                    case 5:
                        if(gO[y][x-1]->getObjType() == GridObjectType::Others){
                            gO[y][x-1] = spawnDragon;
                            td->spawn(x-1, y+1, 'D');
                        }
                        break;
                    case 6:
                        if(gO[y-1][x]->getObjType() == GridObjectType::Others){
                            gO[y-1][x] = spawnDragon;
                            td->spawn(x, y+1, 'D');
                        }
                        break;
                    case 7:
                        if(gO[y-1][x+1]->getObjType() == GridObjectType::Others){
                            gO[y-1][x+1] = spawnDragon;
                            td->spawn(x+1, y-1, 'D');
                        }
                        break;
                }
            }
        }
        else if (spawnRate == 2){//Small
            spawnGold = make_shared<Small>();
            pos = spawnItem(spawnGold,'G');
        }
        else{//Normal
            spawnGold = make_shared<Normal>();
            pos = spawnItem(spawnGold,'G');
        }
    }
    
}

void Floor::placeStair(){

    int x =0;
    int y =0;
    
    while(true){
        int chamNUm = rand()%5;
        int randomPair = rand()%((*chamLst)[chamNUm].size());
        y = (*chamLst)[chamNUm][randomPair].first;
        x = (*chamLst)[chamNUm][randomPair].second;
        if(gO[y][x]->getObjType() == GridObjectType::Others){
            break;
        }
    }
    
    gO[y][x] = make_shared<StairWay>();
    td->spawn(x, y, '\\');
    
}

void Floor::placePlayer(shared_ptr<Character> pc){
   
    int x =0;
    int y =0;
    
    while(true){
        int chamNUm = rand()%5;
        int randomPair = rand()%((*chamLst)[chamNUm].size());
        y = (*chamLst)[chamNUm][randomPair].first;
        x = (*chamLst)[chamNUm][randomPair].second;
        if(gO[y][x]->getObjType() == GridObjectType::Others){
            break;
        }
    }
    gO[y][x] = pc;
    td->spawn(x, y, '@');
}

shared_ptr<Cell> Floor::createCell(char c){
    shared_ptr<Cell> cell;
    if(c == '|' || c == '-' || c == ' '){
        cell = make_shared<Wall>();
    }
    else if (c == '#'){
        cell = make_shared<Passages>();
    }
    else if (c == '+'){
        cell = make_shared<Door>();
    }
    else{
        cell =make_shared<FloorTile>();
    }
    return cell;
}

void Floor::init(shared_ptr<Character> pc){
    srand(time(NULL));
    td = make_shared<TextDisplay>();
    
    //Read file floor.txt
    ifstream file("cc3kfloor.txt");
    string line;
    
    //construct the basic map store it in GridObjects
        for(int i =0;i < height ;i++){
            if(!(getline(file, line))){
                break;
            }
            vector<shared_ptr<GridObjects>> col;
            for(int j = 0; j < width; j++){
                col.emplace_back(createCell(line[j]));
            }
            gO.emplace_back(col);
        }
    
    c = make_shared<Chamber>();
    chamLst = c->getChamberList();
    
    //Spawning order:
    placePlayer(pc);
    placeStair();
    placePotion();
    placeGold();
    placeEnemy(pc);
    pc->attatch(td);
}

void Floor::clearFloor(){
    gO.clear();
}

void Floor::setFrozen(){
    enemyFrozen = true;
}

shared_ptr<Player> Floor::use(shared_ptr<Player> pc, std::string dir){
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
    shared_ptr<Player> tempPc = pc;
    switch (gO[potionRow][potionCol]->getObjType()) {
        case GridObjectType::BA:
            pc = make_shared<BAEffect>(tempPc);
            break;
        case GridObjectType::BD:
            pc = make_shared<BDEffect>(tempPc);
            break;
        case GridObjectType::WA:
            pc = make_shared<WAEffect>(tempPc);
            break;
        case GridObjectType::WD:
            pc = make_shared<WDEffect>(tempPc);
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
    gO[potionRow][potionCol]->notifyObservers(SubscriptionType::displayOnly);
    shared_ptr<FloorTile> g = make_shared<FloorTile>();
    gO[potionRow][potionCol] = g;
    return pc;
}

