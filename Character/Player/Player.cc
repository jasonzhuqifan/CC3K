#include "Player.h"
#include "Potion.h" //待定
#include <string>

using namespace std;

//class Potion; //待定


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

void Player::use(string dir){
    int y = currentRow;
    int x = currentCol;
    if(dir == "no"){
        y++;
    }else if(dir == "so"){
        y--;
    }else if(dir == "ea"){
        x++;
    }else if(dir == "we"){
        x--;
    }else if(dir == "ne"){
        y++;
        x++;
    }else if(dir == "nw"){
        y++;
        x--;
    }else if(dir == "se"){
        y--;
        x++;
    }else if(dir == "sw"){
        y--;
        x--;
    }
    if(gO[y][x]->getObjType == GridObjectType::Potion){
        
        gO[y][x]->notifyObserver(SubscriptionType::All);
    }
}
