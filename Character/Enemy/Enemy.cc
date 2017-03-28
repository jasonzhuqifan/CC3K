#include "Enemy.h"
#include <cstdlib>
#include "Info.h"
#include "Player.h"


void Enemy::updateDamage(double damage){
    HP = HP - damage;
    if(HP <= 0){
        notifyObservers(SubscriptionType::displayOnly);
    }
}

void Enemy::notify(Subject &notifier){
    Info f = getInfo();
    int r = f.currentRow;
    int c = f.currentCol;
    if(gO[r-1][c]->getObjType() == GridObjectType::Player){
        Player *p = (Player*) gO[r-1][c];
        attack(p);
    }else if(gO[r+1][c]->getObjType() == GridObjectType::Player){
        Player *p = (Player*) gO[r+1][c];
        attack(p);
    }else if(gO[r-1][c+1]->getObjType() == GridObjectType::Player){
        Player *p = (Player*) gO[r-1][c+1];
        attack(p);
    }else if(gO[r-1][c-1]->getObjType() == GridObjectType::Player){
        Player *p = (Player*) gO[r-1][c-1];
        attack(p);
    }else if(gO[r+1][c+1]->getObjType() == GridObjectType::Player){
        Player *p = (Player*) gO[r+1][c+1];
        attack(p);
    }else if(gO[r+1][c-1]->getObjType() == GridObjectType::Player){
        Player *p = (Player*) gO[r+1][c-1];
        attack(p);
    }else if(gO[r][c+1]->getObjType() == GridObjectType::Player){
        Player *p = (Player*) gO[r][c+1];
        attack(p);
    }else if(gO[r][c-1]->getObjType() == GridObjectType::Player){
        Player *p = (Player*) gO[r][c-1];
        attack(p);
    }else{
        move(r, c);
        }
    }


void Enemy::move(int r, int c){
    int direction;
    while(true){
        srand(time(NULL));
        direction = rand()%8+1;
        if(direction == 1 && gO[r-1][c]->getObsType() == ObstacleType::BlockNone){ // north
            GridObjects *g = gO[r][c];
            gO[r][c] = gO[r-1][c];
            gO[r-1][c] = g;
            currentRow -= 1;
            break;
        } else if(direction == 2 && gO[r+1][c]->getObsType() == ObstacleType::BlockNone){ //south
            GridObjects *g = gO[r][c];
            gO[r][c] = gO[r+1][c];
            gO[r+1][c] = g;
            currentRow += 1;
            break;
        } else if(direction == 3 && gO[r-1][c+1]->getObsType() == ObstacleType::BlockNone){ //northeast
            GridObjects *g = gO[r][c];
            gO[r][c] = gO[r-1][c+1];
            gO[r-1][c+1] = g;
            currentRow -= 1;
            currentCol += 1;
            break;
        } else if(direction == 4 && gO[r-1][c-1]->getObsType() == ObstacleType::BlockNone){ //northwest
            GridObjects *g = gO[r][c];
            gO[r][c] = gO[r-1][c-1];
            gO[r-1][c-1] = g;
            currentRow -= 1;
            currentCol -= 1;
            break;
        } else if(direction == 5 && gO[r+1][c+1]->getObsType() == ObstacleType::BlockNone){//southeast
            GridObjects *g = gO[r][c];
            gO[r][c] = gO[r+1][c+1];
            gO[r+1][c+1] = g;
            currentRow += 1;
            currentCol += 1;
            break;
        } else if(direction == 6 && gO[r+1][c-1]->getObsType() == ObstacleType::BlockNone){//southwest
            GridObjects *g = gO[r][c];
            gO[r][c] = gO[r+1][c-1];
            gO[r+1][c-1] = g;
            currentRow += 1;
            currentCol -= 1;
            break;
        } else if(direction == 7 && gO[r][c+1]->getObsType() == ObstacleType::BlockNone){//east
            GridObjects *g = gO[r][c];
            gO[r][c] = gO[r][c+1];
            gO[r][c+1] = g;
            currentCol += 1;
            break;
        } else if(direction == 8 && gO[r][c-1]->getObsType() == ObstacleType::BlockNone){//west
            GridObjects *g = gO[r][c];
            gO[r][c] = gO[r][c-1];
            gO[r][c-1] = g;
            currentCol -= 1;
            break;
        }
    }
    this->notifyObservers(SubscriptionType::displayOnly);
    previousCol = currentCol;
    previousRow = currentRow;
}

void Enemy::attack(Player* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    pc->setHealth(damage);
}
