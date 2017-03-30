#include "Player.h"
#include <string>
#include "Enemy.h"
#include "Gold.h"
#include "math.h"
#include "Normal.h"
#include "MerchantHoard.h"
#include "FloorTile.h"
#include "Info.h"

#include "Human.h"
#include "Halfling.h"
#include "Elf.h"
#include "Orc.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Dwarf.h"

using namespace std;


GridObjectType Player::getObjType(){
    return GridObjectType::Player;
}

void Player::move(string dir){
    if(autoheal){
        HP += 5;
    }
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
    int r = currentRow;
    int c = currentCol;
    if(gO[r][c]->getObjType() == GridObjectType::StairWay){
        reachStairs = true; //HOW TO REACH NEWXT FLOOR
    }
    if(gO[r][c]->getObjType() == GridObjectType::smallGold ||
       gO[r][c]->getObjType() == GridObjectType::normalGold ||
       gO[r][c]->getObjType() == GridObjectType::merchantHoard ||
       gO[r][c]->getObjType() == GridObjectType::dragonHoard){
        shared_ptr<Gold> g = dynamic_pointer_cast<Gold>(gO[r][c]);
        gold += g->getGold();
        shared_ptr<FloorTile> f = make_shared<FloorTile>();
        gO[r][c] = f;
        g->notifyObservers(SubscriptionType::displayOnly);
    }
    if(gO[r][c]->getObsType() != ObstacleType::BolckAll){
        shared_ptr<GridObjects> g = gO[r][c];
        gO[r][c] = gO[previousRow][previousCol];
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
    if(autoheal){
        HP += 5;
    }
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
        
        shared_ptr<Enemy> e = dynamic_pointer_cast<Enemy>(gO[r][c]);
        attackIt(e);
    }
}

void Player::attackIt(std::shared_ptr<Enemy> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Dwarf> e) {
    attackIt(dynamic_pointer_cast<Enemy>(e));
}

void Player::attackIt(std::shared_ptr<Dragon> e) {
    attackIt(dynamic_pointer_cast<Enemy>(e));
}

void Player::attackIt(std::shared_ptr<Elf> e) {
    attackIt(dynamic_pointer_cast<Enemy>(e));
}

void Player::attackIt(std::shared_ptr<Halfling> e) {
    attackIt(dynamic_pointer_cast<Enemy>(e));
}

void Player::attackIt(std::shared_ptr<Human> e) {
    attackIt(dynamic_pointer_cast<Enemy>(e));
}

void Player::attackIt(std::shared_ptr<Merchant> e) {
    attackIt(dynamic_pointer_cast<Enemy>(e));
}

void Player::attackIt(std::shared_ptr<Orc> e) {
    attackIt(dynamic_pointer_cast<Enemy>(e));
}

void Player::check_dead(shared_ptr<Enemy> e){
    if(e->isDead()){
        Info f = e->getInfo();
        int c = f.currentCol;
        int r = f.currentRow;
        if(e->dropgold() == 2){
            shared_ptr<Normal> g = make_shared<Normal>(2);
            gO[r][c] = g;
        }else if(e->dropgold() == 4){
            shared_ptr<MerchantHoard> g = make_shared<MerchantHoard>();
            gO[r][c] = g;
        }else{
            shared_ptr<FloorTile> g = make_shared<FloorTile>();
            gO[r][c] = g;
        }
        if(steal){
            gold += 5;
        }
    }

}

bool Player::ismagnify(){
    return magnify;
}


bool Player::isautoheal(){
    return autoheal;
}
