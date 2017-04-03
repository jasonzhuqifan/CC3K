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
    c = make_shared<Chamber>();
    playerInRoom = -1;
}

Floor::~Floor(){}


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
        
        if(gO[y][x]->getObjType() == GridObjectType::FloorTiles){
            break;
        }
    }
    
    gO[y][x] = itemType;
    gO[y][x]->setPos(y, x);
    gO[y][x]->attatch(td);
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
        *type = 'W';
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
    //shared_ptr<vector<vector<shared_ptr<GridObjects>>>> map = make_shared<vector<vector<shared_ptr<GridObjects>>>>(gO);
    spawnEnemy->setMap(&gO);
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
        pc->attatch(newEnemy);
        newEnemy->attatch(td);
        td->spawn(x, y, type);
        newEnemy->setPos(y, x);
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

void Floor::placeGold(shared_ptr<Character> pc){
    pair<int,int> pos;
    shared_ptr<Gold> spawnGold = NULL;
    shared_ptr<Dragon> spawnDragon = NULL;
    for (int i =0;i < goldNum;i++){
        
        int spawnRate = rand()%8+1;
        if (spawnRate == 1){//Dragon Hoard
            spawnGold = make_shared<DragonHoard>();
            spawnDragon = make_shared<Dragon>();
            pc->attatch(spawnDragon);
            pos = spawnItem(spawnGold,'G');
            spawnDragon->setMap(&gO);
            int y = pos.first;
            int x = pos.second;
            //0 1 2
            //3 G 4
            //5 6 7
            for(int i =0; i < 8 ;i++){
                int spawnPos = rand()%8;
                
                if (gO[y-1][x-1]->getObsType() == ObstacleType::BlockNone &&
                    spawnPos == 0){//0
                    gO[y-1][x-1] = spawnDragon;
                    td->spawn(x-1, y-1, 'D');
                    spawnDragon->setPos(y-1, x-1);
                    break;
                }
                else if (gO[y-1][x]->getObsType() == ObstacleType::BlockNone &&
                         spawnPos == 1){//1
                    gO[y-1][x] = spawnDragon;
                    td->spawn(x, y-1, 'D');
                    spawnDragon->setPos(y-1, x);
                    break;
                }
                else if(gO[y-1][x+1]->getObsType() == ObstacleType::BlockNone &&
                        spawnPos == 2){//2
                    gO[y-1][x+1] = spawnDragon;
                    td->spawn(x+1, y-1, 'D');
                    spawnDragon->setPos(y-1, x+1);
                    break;
                }
                else if (gO[y][x-1]->getObsType() == ObstacleType::BlockNone &&
                         spawnPos == 3){//3
                    gO[y][x-1] = spawnDragon;
                    td->spawn(x-1, y, 'D');
                    spawnDragon->setPos(y, x-1);
                    break;
                }
                else if (gO[y][x+1]->getObsType() == ObstacleType::BlockNone &&
                         spawnPos == 4){//4
                    gO[y][x+1] = spawnDragon;
                    td->spawn(x+1, y, 'D');
                    spawnDragon->setPos(y, x+1);
                    break;
                }
                else if(gO[y+1][x-1]->getObsType() == ObstacleType::BlockNone &&
                        spawnPos == 5){//5
                    gO[y+1][x-1] = spawnDragon;
                    td->spawn(x-1, y+1, 'D');
                    spawnDragon->setPos(y+1, x-1);
                    break;
                }
                else if(gO[y+1][x]->getObsType() == ObstacleType::BlockNone  &&
                        spawnPos == 6){//6
                    gO[y+1][x] = spawnDragon;
                    td->spawn(x, y+1, 'D');
                    spawnDragon->setPos(y+1, x);
                    break;
                }
                else if (gO[y+1][x+1]->getObsType() == ObstacleType::BlockNone &&
                         spawnPos == 7){//7
                    gO[y+1][x+1] = spawnDragon;
                    td->spawn(x+1, y+1, 'D');
                    spawnDragon->setPos(y+1, x+1);
                    break;
                }
                spawnGold->setPos(y, x);
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
    
    int chamNum =0;
    while(true){
        chamNum = rand()%5;
        int randomPair = rand()%((*chamLst)[chamNum].size());
        y = (*chamLst)[chamNum][randomPair].first;
        x = (*chamLst)[chamNum][randomPair].second;
        if(gO[y][x]->getObjType() == GridObjectType::FloorTiles && playerInRoom != chamNum){
            break;
        }
    }
    
    gO[y][x] = make_shared<StairWay>();
    td->spawn(x, y, '\\');
    gO[y][x]->setPos(y, x);
}

void Floor::placePlayer(shared_ptr<Character> pc){
    
    int x =0;
    int y =0;
    
    int chamNum = 0;
    while(true){
        chamNum = rand()%5;
        int randomPair = rand()%((*chamLst)[chamNum].size());
        y = (*chamLst)[chamNum][randomPair].first;
        x = (*chamLst)[chamNum][randomPair].second;
        if(gO[y][x]->getObjType() == GridObjectType::FloorTiles){
            break;
        }
    }
    playerInRoom = chamNum;
    gO[y][x] = pc;
    pc->setPos(y, x);
    td->spawn(x, y, '@');
    pc->attatch(td);
    dynamic_pointer_cast<Player>(pc)->update_message("Player Character has spawned!");
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
    cell->attatch(td);
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
    
    //get chamber coordinates list for each chamber
    chamLst = c->getChamberList();
    
    //Spawning order:
    placePlayer(pc);
    placeStair();
    placePotion();
    placeGold(pc);
    placeEnemy(pc);
       //shared_ptr<vector<vector<shared_ptr<GridObjects>>>> map = make_shared<vector<vector<shared_ptr<GridObjects>>>>(gO);
    pc->setMap(&gO);
    pc->setTD(td);
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
    pc->emptyMessage();
    switch (gO[potionRow][potionCol]->getObjType()) {
        case GridObjectType::BA:
            pc = make_shared<BAEffect>(tempPc);
            pc->update_message("Player uses potion. Atk increases.");
            break;
        case GridObjectType::BD:
            pc = make_shared<BDEffect>(tempPc);
            pc->update_message("Player uses potion. Def increases.");
            break;
        case GridObjectType::WA:
            pc = make_shared<WAEffect>(tempPc);
            pc->update_message("Player uses potion. Atk decreases.");
            break;
        case GridObjectType::WD:
            pc = make_shared<WDEffect>(tempPc);
            pc->update_message("Player uses potion. Def decreases.");
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
    shared_ptr<Potion> p = dynamic_pointer_cast<Potion>(gO[potionRow][potionCol]);
    if (p) {
        gO[info.currentRow][info.currentCol] = pc;
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(!pc->knowPotion(potionType)) pc->memorizePotion(potionType);
        if(pc->hasDead()) return pc;
        p->notifyObservers(SubscriptionType::displayOnly);
        shared_ptr<FloorTile> g = make_shared<FloorTile>();
        gO[potionRow][potionCol] = g;
    }
    pc->notifyObservers(SubscriptionType::All);
    return pc;
}


