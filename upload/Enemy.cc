#include "Enemy.h"
#include "Info.h"
#include "Player.h"
#include "Drow.h"
#include "Vampire.h"
#include "Shade.h"
#include "Student.h"
#include "Goblin.h"
#include "Troll.h"
#include "Dragon.h"
using namespace std;

void Enemy::updateDamage(double damage){
    HP = HP - damage;
    if(HP <= 0){
        Dead = true;
        
    }
}

void Enemy::notify(Subject &notifier){
//    Info f = getInfo();
    int r = currentRow;
    int c = currentCol;
    if(isneutral){
        move();
    }else if((*gO)[r-1][c]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r-1][c]);
        attack(p);
    }else if((*gO)[r+1][c]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r+1][c]);
        attack(p);
    }else if((*gO)[r-1][c+1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r-1][c+1]);
        attack(p);
    }else if((*gO)[r-1][c-1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r-1][c-1]);
        attack(p);
    }else if((*gO)[r+1][c+1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r+1][c+1]);
        attack(p);
    }else if((*gO)[r+1][c-1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r+1][c-1]);
        attack(p);
    }else if((*gO)[r][c+1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r][c+1]);
        attack(p);
    }else if((*gO)[r][c-1]->getObjType() == GridObjectType::Player){
        shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[r][c-1]);
        attack(p);
    }else if(stationary){
        
        shared_ptr<Enemy> e = shared_from_this();
        shared_ptr<Dragon> d = dynamic_pointer_cast<Dragon>(e);
        int hoardC = d->getDragonHoardC();
        int hoardR = d->getDragonHoardR();
        if((*gO)[hoardR-1][hoardC]->getObjType() == GridObjectType::Player){
            shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[hoardR-1][hoardC]);
            attack(p);
        }else if((*gO)[hoardR+1][hoardC]->getObjType() == GridObjectType::Player){
            shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[hoardR+1][hoardC]);
            attack(p);
        }else if((*gO)[hoardR-1][hoardC+1]->getObjType() == GridObjectType::Player){
            shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[hoardR-1][hoardC+1]);
            attack(p);
        }else if((*gO)[hoardR-1][hoardC-1]->getObjType() == GridObjectType::Player){
            shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[hoardR-1][hoardC-1]);
            attack(p);
        }else if((*gO)[hoardR+1][hoardC+1]->getObjType() == GridObjectType::Player){
            shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[hoardR+1][hoardC+1]);
            attack(p);
        }else if((*gO)[hoardR+1][hoardC-1]->getObjType() == GridObjectType::Player){
            shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[hoardR+1][hoardC-1]);
            attack(p);
        }else if((*gO)[hoardR][hoardC+1]->getObjType() == GridObjectType::Player){
            shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[hoardR][hoardC+1]);
            attack(p);
        }else if((*gO)[hoardR][hoardC-1]->getObjType() == GridObjectType::Player){
            shared_ptr<Player> p = dynamic_pointer_cast<Player>((*gO)[hoardR][hoardC-1]);
            attack(p);
        }
    }else if(!stationary){
        move();
    }
}

void Enemy::move(){
    int r = currentRow;
    int c = currentCol;
    int direction;
    int tries = 0;
    while(tries++ < 100){
        direction = rand()%8+1;
        if(direction == 1 && (*gO)[r-1][c]->getObsType() == ObstacleType::BlockNone){ // north
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r-1][c];
            (*gO)[r-1][c] = g;
            currentRow -= 1;
            break;
        } else if(direction == 2 && (*gO)[r+1][c]->getObsType() == ObstacleType::BlockNone){ //south
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r+1][c];
            (*gO)[r+1][c] = g;
            currentRow += 1;
            break;
        } else if(direction == 3 && (*gO)[r-1][c+1]->getObsType() == ObstacleType::BlockNone){ //northeast
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r-1][c+1];
            (*gO)[r-1][c+1] = g;
            currentRow -= 1;
            currentCol += 1;
            break;
        } else if(direction == 4 && (*gO)[r-1][c-1]->getObsType() == ObstacleType::BlockNone){ //northwest
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r-1][c-1];
            (*gO)[r-1][c-1] = g;
            currentRow -= 1;
            currentCol -= 1;
            break;
        } else if(direction == 5 && (*gO)[r+1][c+1]->getObsType() == ObstacleType::BlockNone){//southeast
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r+1][c+1];
            (*gO)[r+1][c+1] = g;
            currentRow += 1;
            currentCol += 1;
            break;
        } else if(direction == 6 && (*gO)[r+1][c-1]->getObsType() == ObstacleType::BlockNone){//southwest
            shared_ptr<GridObjects> g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r+1][c-1];
            (*gO)[r+1][c-1] = g;
            currentRow += 1;
            currentCol -= 1;
            break;
        } else if(direction == 7 && (*gO)[r][c+1]->getObsType() == ObstacleType::BlockNone){//east
            shared_ptr<GridObjects>g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r][c+1];
            (*gO)[r][c+1] = g;
            currentCol += 1;
            break;
        } else if(direction == 8 && (*gO)[r][c-1]->getObsType() == ObstacleType::BlockNone){//west
            shared_ptr<GridObjects>g = (*gO)[r][c];
            (*gO)[r][c] = (*gO)[r][c-1];
            (*gO)[r][c-1] = g;
            currentCol -= 1;
            break;
        }
    }
    this->notifyObservers(SubscriptionType::displayOnly);
    previousCol = currentCol;
    previousRow = currentRow;
}

void Enemy::attack(shared_ptr<Player> pc){
    pc->update_enemy(this);
    double def = pc->getDefence();
    if(dynamic_pointer_cast<Drow>(pc->getTrue())){
        attack(dynamic_pointer_cast<Drow>(pc->getTrue()),def);
    }
    else if(dynamic_pointer_cast<Goblin>(pc->getTrue())){
        attack(dynamic_pointer_cast<Goblin>(pc->getTrue()),def);
    }
    else if(dynamic_pointer_cast<Shade>(pc->getTrue())){
        attack(dynamic_pointer_cast<Shade>(pc->getTrue()),def);
    }
    else if(dynamic_pointer_cast<Troll>(pc->getTrue())){
        attack(dynamic_pointer_cast<Troll>(pc->getTrue()),def);
    }
    else if(dynamic_pointer_cast<Vampire>(pc->getTrue())){
        attack(dynamic_pointer_cast<Vampire>(pc->getTrue()),def);
    }else if(dynamic_pointer_cast<Student>(pc->getTrue())){
        attack(dynamic_pointer_cast<Student>(pc->getTrue()),def);
    }
}
void Enemy::attack(std::shared_ptr<Drow> pc, double def){
    double d = def;
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+d)) * this->Atk);
    }
    pc->getDamage(damage);
}
void Enemy::attack(std::shared_ptr<Goblin> pc, double def){
    double d = def;
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+d)) * this->Atk);
    }
    pc->getDamage(damage);

}
void Enemy::attack(std::shared_ptr<Shade> pc, double def){
    double d = def;
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+d)) * this->Atk);
    }
    pc->getDamage(damage);

}
void Enemy::attack(std::shared_ptr<Troll> pc, double def){
    double d = def;
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+d)) * this->Atk);
    }
    pc->getDamage(damage);
}
void Enemy::attack(std::shared_ptr<Vampire> pc, double def){
    double d = def;
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+d)) * this->Atk);
    }
    pc->getDamage(damage);

}
void Enemy::attack(std::shared_ptr<Student> pc, double def){
    double d = def;
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+d)) * this->Atk);
    }
    pc->getDamage(damage);
    
}
void Enemy::setNeutral(){
    isneutral = false;
}

bool Enemy::isDead(){
    return Dead;
}

int Enemy::dropgold(){
    return gold;
}

GridObjectType Enemy::getObjType(){
    return GridObjectType::Enemy;
}

SubscriptionType Enemy::getSubType() const{
    return SubscriptionType::All;
}
