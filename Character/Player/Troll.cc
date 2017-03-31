#include "Troll.h"
#include "Halfling.h"
#include "Merchant.h"

using namespace std;


Troll::Troll(){
    HP = 120;
    Atk = 25;
    Def = 15;
    MaxHP = 120;
    autoheal = true;
    playerRace = "Troll";
}

void Troll::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
    }
    check_dead(e);
}
void Troll::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    e->setNeutral();
    check_dead(e);
}


Troll::~Troll(){
    
}
