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
#include "textDisplay.h"
#include "Level.h"
#include "Chamber.h"

class  GridObjects;
class Enemy;
class Potion;
class Gold;
class Cell;
class Character;

using namespace std;

class Floor : public Level{
protected:
    TextDisplay td;
    vector<vector<GridObjects *>> gO ;
    bool enemyFrozen;
private:
    bool isFirst();//if floor is first floor
    const int enemyNum =20;
    const int potionNum =10;
    const int goldNum = 10;
    const int width = 79;
    const int height = 25;
    
    Chamber *c;
    Enemy *createEnemy() override;
    Potion *createPotion() override;
    Gold *createGold() override;
    Cell *createCell(char c) override;
    
    
    void placeEnemy() override;
    void placePotion() override;
    void placeGold() override;
    void placeStair() override;
    void placePlayer(Character *pc) override;
public:
    Floor();
    void init(Character *pc);
    void clearFloor();
    void setFrozen() override;
    ~Floor();
    
};


#endif /* Floor_hpp */
