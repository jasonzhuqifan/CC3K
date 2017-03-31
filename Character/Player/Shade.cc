#include "Shade.h"
#include "Halfling.h"
#include "Merchant.h"

Shade::Shade(){
    HP = 125;
    Atk = 25;
    Def = 25;
    MaxHP = 125;
    playerRace = "Shade";
}

void Shade::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
    check_dead(e);
}

void Shade::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    e->setNeutral();
    check_dead(e);
}
Shade::~Shade(){}
