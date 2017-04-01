#include "Character.h"

double Character::getHP(){
    return HP;
}

double Character::getDefence(){
    return Def;
}

double Character::getAttack(){
    return Atk;
}

int Character::getGold(){
    return gold;
}

double Character::getMaxHP(){
    return MaxHP;
}

ObstacleType Character::getObsType(){
    return ObstacleType::BolckAll;
}


void Character::setTD(TextDisplay *t){
    TD = t;
}

void Character::setMap(std::vector<std::vector<std::shared_ptr<GridObjects>>> *g){
    gO = g;
}
