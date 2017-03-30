#include "Goblin.h"
#include "string"
#include "Halfling.h"

using namespace std;

Goblin::Goblin(){
    HP = 110;
    Atk = 15;
    Def = 20;
    MaxHP = 110;
}

void Goblin::attackIt(Halfling* e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
}

Goblin::~Goblin(){}
