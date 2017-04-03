#include "Orc.h"
#include "Goblin.h"

using namespace std;

Orc::Orc(){
    HP = 180;
    Atk = 30;
    Def = 25;
    MaxHP = 180;
}

void Orc::attack(shared_ptr<Goblin> pc, double true_def){
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+true_def)) * this->Atk * 1.5);
    }
    pc->getDamage(damage);
}

Orc::~Orc(){}
