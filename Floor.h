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
#include "Level.h"
#include "Chamber.h"


class GridObjects;
class Player;
class Enemy;
class Potion;
class Gold;
class Cell;
class Character;
class TextDisplay;


class Floor : public Level{
protected:
    TextDisplay *td;
    std::vector<std::vector<GridObjects *>> gO ;
    bool enemyFrozen;
private:
    bool isFirst();//if floor is first floor
    const int enemyNum =20;
    const int potionNum =10;
    const int goldNum = 10;
    const int width = 79;
    const int height = 25;
    
    Chamber *c;
    Enemy *createEnemy(char *type) override;
    Potion *createPotion() override;
    Cell *createCell(char c) override;
    
    void placeEnemy(Character *pc) override;
    void placePotion() override;
    void placeGold() override;
    void placeStair() override;
    void placePlayer(Character *pc) override;
    template <typename T>
    pair<int, int> spawnItem(T itemType,vector<vector<pair<int, int>>> *chamLst,char type);
    //returns the position of the item when item spawns.
    void setItem(GridObjects *itemType, int x, int y);
    
    
public:
    Player* use(Player* pc, string dir) override;
    Floor();
    void init(Character *pc);
    void clearFloor();
    void setFrozen() override;
    ~Floor();
    
};


#endif /* Floor_hpp */
