//
//  Floor.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Floor_hpp
#define Floor_hpp

#include "Level.h"
#include "GridObjects.h"
#include "Chamber.h"
#include <vector>
using namespace std;

class Floor : public Level{
protected:
    vector<gridObjects *> gO;
    bool enemyFrozen;
private:
    Chamber *c;
    enemy makeEnemy() override;
    potion makePotion() override;
    gold makeGold() override;
    void placeStair() override;
    void placePlayer() override;
    void place(gridObjects &gO);
public:
    Floor();
    void init();
    void clearFloor();
    void setFrozen();
    ~Floor();
    
};


#endif /* Floor_hpp */
