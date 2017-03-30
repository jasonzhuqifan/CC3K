#include "Shade.h"
#include "Halfling.h"

Shade::Shade(){
    HP = 125;
    Atk = 25;
    Def = 25;
    MaxHP = 125;
}

void Shade::attackIt(Halfling* e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
}

Shade::~Shade(){}
