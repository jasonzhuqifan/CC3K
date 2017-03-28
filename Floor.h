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

using namespace std;

class Floor : public Level{
protected:
    TextDisplay *td;
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
    
    template <typename T>
    void Item(T itemType) {
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
                   //gO[x][y]->getObjType() ==
                    potionInCham[chamberNum]++;
                    break;
                }
                
            }
            GridObjects *temp = gO[x][y];
            gO[x][y] = createPotion();
        }
    }

    
public:
    Player* use(Player* pc, string dir) override;
    Floor();
    void init(Character *pc);
    void clearFloor();
    void setFrozen() override;
    ~Floor();
    
};


#endif /* Floor_hpp */
