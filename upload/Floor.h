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
    std::vector<std::vector<std::shared_ptr<GridObjects>>> gO;
    int dargonHoardx;
    int dragonHoardy;
private:
    int playerInRoom;
    std::shared_ptr<Chamber> c;
    std::shared_ptr<std::vector<std::vector<std::pair<int, int>>>>chamLst;
    bool isFirst();//if floor is first floor
    const int enemyNum =20;
    const int potionNum =10;
    const int goldNum = 10;
    const int width = 79;
    const int height = 25;
    
    std::shared_ptr<Enemy> createEnemy(char *type) override;
    std::shared_ptr<Potion> createPotion() override;
    std::shared_ptr<Cell> createCell(char c) override;
    
    void placeEnemy(std::shared_ptr<Character> pc) override;
    void placePotion() override;
    void placeGold(std::shared_ptr<Character> pc) override;
    void placeStair() override;
    void placePlayer(std::shared_ptr<Character> pc) override;
    template <typename T>
    std::pair<int, int> spawnItem(T itemType,char type);
    //returns the position of the item when item spawns.
    
    
    
public:
    std::shared_ptr<Player> use(std::shared_ptr<Player> pc, std::string dir) override;
    Floor();
    void init(std::shared_ptr<Character> pc);
    void clearFloor();
    ~Floor();
};


#endif /* Floor_hpp */
