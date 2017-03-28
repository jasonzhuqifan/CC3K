#include "Player.h"
#include <string>
#include "Enemy.h"
#include "math.h"
using namespace std;


GridObjectType Player::getObjType(){
    return GridObjectType::Player;
}

double Player::getHP(){
    return HP;
}

double Player::getDefence(){
    return Def;
}

double Player::getAttack(){
    return Atk;
}

double Player::getGold(){
    return Gold;
}

double Player::getMaxHP(){
    return MaxHP;
}

void Player::move(string dir){

    if(dir == "no"){
        currentRow--;
    }else if(dir == "so"){
        currentRow++;
    }else if(dir == "ea"){
        currentCol++;
    }else if(dir == "we"){
        currentCol--;
    }else if(dir == "ne"){
        currentRow--;
        currentCol++;
    }else if(dir == "nw"){
        currentRow--;
        currentCol--;
    }else if(dir == "se"){
        currentRow++;
        currentCol++;
    }else if(dir == "sw"){
        currentRow++;
        currentCol--;
    }
    if(gO[currentCol][currentRow]->getObjType() == GridObjectType::StairWay){
        reachStairs = true;
    }
    if(gO[currentCol][currentRow]->getObsType() != ObstacleType::BolckAll){
        GridObjects *g = gO[currentCol][currentRow];
        gO[currentCol][currentRow] = gO[previousRow][previousCol];
        gO[previousRow][previousCol] = g;
        
    }
    this->notifyObservers(SubscriptionType::All);
    previousRow = currentRow;
    previousCol = currentCol;
}

void Player::setHealth(double h){
    if(MaxHP == -1){
        HP = h;
    }else if(h >= MaxHP){
        HP = MaxHP;
    }else{
        HP = h;
    }
}

void Player::use(string dir){
    int y = currentRow;
    int x = currentCol;
    if(dir == "no"){
        y--;
    }else if(dir == "so"){
        y++;
    }else if(dir == "ea"){
        x++;
    }else if(dir == "we"){
        x--;
    }else if(dir == "ne"){
        y--;
        x++;
    }else if(dir == "nw"){
        y--;
        x--;
    }else if(dir == "se"){
        y++;
        x++;
    }else if(dir == "sw"){
        y++;
        x--;
    }
    if(gO[y][x]->getObjType() == GridObjectType::Potion){
        
        gO[y][x]->notifyObservers(SubscriptionType::All);
    }
}

void Player::attack(std::string dir){
    int r = currentRow;
    int c = currentCol;
    if(dir == "no"){
        r--;
    }else if(dir == "so"){
        r++;
    }else if(dir == "ea"){
        c++;
    }else if(dir == "we"){
        c--;
    }else if(dir == "ne"){
        r--;
        c++;
    }else if(dir == "nw"){
        r--;
        c--;
    }else if(dir == "se"){
        r++;
        c++;
    }else if(dir == "sw"){
        r++;
        c--;
    }
    if(gO[r][c]->getObjType() == GridObjectType::Enemy){
        Enemy* e = (Enemy*) gO[r][c];
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
}
