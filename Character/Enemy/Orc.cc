#include "Orc.h"
#include "Goblin.h"

using namespace std;

Orc::Orc(){
    HP = 180;
    Atk = 30;
    Def = 25;
    MaxHP = 180;
}

void Orc::attack(shared_ptr<Goblin> pc){
    double d = pc->getDefence();
    double damage = ceil((100/(100+d)) * this->Atk * 1.5);
    int miss = rand()%2+1;
    if (miss == 1){
        pc->getDamage(damage);
    }
    pc->getDamage(damage);
}

Orc::~Orc(){}
