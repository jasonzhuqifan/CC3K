#include "Elf.h"

#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"
#include "Goblin.h"

using namespace std;

/*void Elf::attack(Drow* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    pc->setHealth(damage);
} */
Elf::Elf(){
    HP = 140;
    Atk = 30;
    Def = 10;
    MaxHP = 140;
}
void Elf::attack(shared_ptr<Goblin> pc, double true_def){
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = damage + ceil((100/(100+true_def)) * this->Atk);
    }
    miss = rand()%2 + 1;
    if (miss == 1){
        damage = damage + ceil((100/(100+true_def)) * this->Atk);
    }
    pc->getDamage(damage);
}
void Elf::attack(shared_ptr<Shade> pc, double true_def){
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+true_def)) * getAttack());
    }
    miss = rand()%2 + 1;
    if (miss == 1){
        damage = damage + ceil((100/(100+true_def)) * getAttack());
    }
    pc->getDamage(damage);

}
void Elf::attack(shared_ptr<Troll> pc, double true_def){
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+true_def)) * this->Atk);
    }
    miss = rand()%2 + 1;
    if (miss == 1){
        damage = damage + ceil((100/(100+true_def)) * this->Atk);
    }
    pc->getDamage(damage);

}
void Elf::attack(shared_ptr<Vampire> pc, double true_def){
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage = ceil((100/(100+true_def)) * this->Atk);
    }
    miss = rand()%2 + 1;
    if (miss == 1){
        damage = damage + ceil((100/(100+true_def)) * this->Atk);
    }
    pc->getDamage(damage);

}
Elf::~Elf(){
}
