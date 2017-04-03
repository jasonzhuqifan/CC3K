#include "Gold.h"

Gold::Gold(int amount, int count) : amount(amount), count(count) {}

int Gold::getGold() {
    return amount * count;
}

int Gold::getGoldCount() {
    return count;
}

ObstacleType Gold::getObsType(){
    return ObstacleType::BlockEnemy;
}

bool Gold::canPickUp(){
    return isGuarded;
}

void Gold::setGuarded(){
    isGuarded = false;
}
