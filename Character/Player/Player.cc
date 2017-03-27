#include "Player.h"
#include "Info.h"


Info Player::getInfo(){
    Info f;
    f.currentCol = currentCol;
    f.currentRow = currentRow;
    f.previousCol = previousCol;
    f.previousRow = previousRow;
    f.GOT = getObjType();
    return f;
}


GridObjectType Player::getObjType(){
    return GridObjectType::Player;
}

int Player::getHP(){
    return HP;
}

int Player::getDefence(){
    return Def;
}

int Player::getAttack(){
    return Atk;
}

int Player::getGold(){
    return Gold;
}

int Player::getMaxHP(){
    return MaxHP;
}

void Player::move(string dir){
    previousRow = currentRow;
    previousCol = currentCol;
    if(dir == "no"){
        currentRow++;
    }else if(dir == "so"){
        currentRow--;
    }else if(dir == "ea"){
        currentCol++;
    }else if(dir == "we"){
        currentCol--;
    }else if(dir == "ne"){
        currentRow++;
        currentCol++;
    }else if(dir == "nw"){
        currentRow++;
        currentCol--;
    }else if(dir == "se"){
        currentRow--;
        currentCol++;
    }else if(dir == "sw"){
        currentRow--;
        currentCol--;
    }
    
    if(gO[currentCol][currentRow]->getObsType() != ObstacleType::BolckAll){
        GridObjects *g = gO[currentCol][currentRow];
        gO[currentCol][currentRow] = gO[previousRow][previousCol];
        gO[previousRow][previousCol] = g;
        
    }
    this->notifyObservers(SubscriptionType::All);
}
