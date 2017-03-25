#ifndef Floor_hpp
#define Floor_hpp

#include "Level.h"
#include "Chamber.h"
#include "GridObjects.h"
#include <vector>
using namespace std;

class Floor : public level{
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
    //void place(gridObjects &gO);
public:
    Floor();
    void init();
    void clearFloor();
    void setFrozen();
    ~Floor();
    
};


#endif /* Floor_hpp */
