#ifndef Gold_hpp
#define Gold_hpp

#include "Item.h"

class Gold : public Item{
    int amount;
    int count;
protected:
    bool isGuarded = false;
public:
    bool canPickUp();
    Gold(int amount, int count);
    ObstacleType getObsType() override;
    int getGold();
    int getGoldCount();
    void setGuarded();
};

#endif 
