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

class floor : public level{
protected:
    vector<gridObjects *> gO;
    bool enemyFrozen;
private:
    chamber *c;
    enemy makeEnemy() override;
    potion makePotion() override;
    gold makeGold() override;
    void placeStair() override;
    void placePlayer() override;
    void place(gridObjects &gO);
public:
    floor();
    void init();
    void clearFloor();
    void setFrozen();
    ~floor();
    
};


#endif /* Floor_hpp */
