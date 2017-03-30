#include "Gold.h"

Gold::Gold(int amount, int count) : amount(amount), count(count) {}

int Gold::getGold() {
    return amount * count;
}

ObstacleType Gold::getObsType(){
    return ObstacleType::BlockEnemy;
}
