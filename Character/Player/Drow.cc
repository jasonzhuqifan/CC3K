#include "Drow.h"
#include "string"
#include "Halfling.h"

using namespace std;

Drow::Drow(){
    HP = 150;
    Atk = 25;
    Def = 15;
    MaxHP = 150;
}

void Drow::attackIt(Halfling* e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
}

Drow::~Drow(){}
