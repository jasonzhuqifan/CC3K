#include "Troll.h"
#include "Halfling.h"


using namespace std;


Troll::Troll(){
    HP = 120;
    Atk = 25;
    Def = 15;
    MaxHP = 120;
}

void Troll::attackIt(Halfling* e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
}


Troll::~Troll(){
    
}
