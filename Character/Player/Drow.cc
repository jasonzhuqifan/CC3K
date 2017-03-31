#include "Drow.h"
#include "Merchant.h"
#include "Halfling.h"


using namespace std;

Drow::Drow(){
    HP = 150;
    Atk = 25;
    Def = 15;
    MaxHP = 150;
    magnify = true;
    playerRace = "Drow";
}

void Drow::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
    check_dead(e);
}

void Drow::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    e->setNeutral();
    check_dead(e);
}
Drow::~Drow(){}
