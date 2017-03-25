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
    vector<GridObjects *> gO;
    bool enemyFrozen;
private:
    Chamber *c;
    Enemy makeEnemy() override;
    Potion makePotion() override;
    Gold makeGold() override;
    void placeStair() override;
    void placePlayer() override;
    void place(GridObjects &gO);
public:
    Floor();
    void init();
    void clearFloor();
    void setFrozen();
    ~Floor();
    
};


#endif /* Floor_hpp */
