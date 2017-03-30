#include "Player.h"
#include <string>
#include "Enemy.h"
#include "Gold.h"
#include "math.h"
#include "Normal.h"
#include "MerchantHoard.h"
#include "Info.h"
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
    if(gO[currentRow][currentCol]->getObjType() == GridObjectType::StairWay){
        reachStairs = true;
    }
    if(gO[currentRow][currentCol]->getObjType() == GridObjectType::Gold){
        Gold* g = (Gold*) gO[currentRow][currentCol];
        
    }
    if(gO[currentRow][currentCol]->getObsType() != ObstacleType::BolckAll){
        GridObjects *g = gO[currentRow][currentCol];
        gO[currentRow][currentCol] = gO[previousRow][previousCol];
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
    if(HP <= 0){
        //THROW SOMETHING! YOU FUCKED UP!
    }
}
void Player::getDamage(double damage){
    HP -= damage;
    if(HP <= 0){
        // THROW SOMETHING! YOU FUCKED UP!
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
        attackIt(e);
    }
}

void Player::attackIt(Enemy *e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    if(e->isDead()){
        Info f = e->getInfo();
        int c = f.currentCol;
        int r = f.currentRow;
        if(e->dropgold() == 2){
            shared_ptr<Normal> g = make_shared<Normal>(2);
            gO[r][c] = g;
        }else if(e->dropgold() == 4){
            shared_ptr<MerchantHoard> g = make_shared<MerchantHoard>(2);
            
        }
    }
}

bool Player::ismagnify(){
    return magnify;
}

bool Player::issteal(){
    return steal;
}

bool Player::isautoheal(){
    return autoheal;
}
