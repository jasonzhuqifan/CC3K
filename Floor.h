//
//  Floor.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Floor_hpp
#define Floor_hpp

#include <vector>

#include "GridObjects.h"
#include "Level.h"
#include "Chamber.h"

#include "Enemy.h"
#include "Human.h"
#include "Halfling.h"
#include "Elf.h"
#include "Orc.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Dwarf.h"

#include "Gold.h"
#include "Small.h"
#include "Normal.h"
#include "DragonHoard.h"

#include "Potion.h"
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WD.h"
#include "WA.h"

#include "Cell.h"
#include "Door.h"
#include "StairWay.h"
#include "Wall.h"
#include "Passages.h"
#include "FloorTile.h"



using namespace std;

class Floor : public Level{
protected:
    vector<vector<GridObjects *>> gO;
    bool enemyFrozen;
private:
    const int enemyNum =20;
    const int potionNum =10;
    const int goldNum = 10;
    const int width = 79;
    const int height = 25;
    const int chamberNum = 5;
    
    Chamber *c;
    Enemy *createEnemy() override;
    Potion *createPotion() override;
    Gold *createGold() override;
    Cell *createCell(char c) override;
    
    bool isChamber(vector<vector<pair<int, int>>>* chamLst,int row,int col);
    void placeEnemy() override;
    void placePotion() override;
    void placeGold() override;
    void placeStair() override;
    void placePlayer() override;
    void place(GridObjects &gO);
public:
    Floor();
    void init();
    void clearFloor();
    void setFrozen() override;
    ~Floor();
    
};


#endif /* Floor_hpp */
