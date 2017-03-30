#include "Vampire.h"
#include "Halfling.h"
#include "Dwarf.h"
#include "Dragon.h"
#include "Elf.h"
#include "Human.h"
#include "Merchant.h"
#include "Orc.h"

using namespace std;

Vampire::Vampire(){
    HP = 120;
    Atk = 25;
    Def = 25;
    MaxHP = -1;
}

void Vampire::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
        HP += 5;
    }
    check_dead(e);
}

void Vampire::attackIt(std::shared_ptr<Dwarf> e){
        double d = e->getDefence();
        double damage = ceil((100/100+d) * this->Atk);
        e->updateDamage(damage);
        HP += 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Dragon> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    HP += 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Elf> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    HP += 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Human> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    HP += 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    e->setNeutral();
    HP += 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Orc> e){
    double d = e->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    e->updateDamage(damage);
    HP += 5;
    check_dead(e);
}


Vampire::~Vampire(){}
