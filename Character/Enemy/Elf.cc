#include "Elf.h"

#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"
#include "Goblin.h"
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
void Elf::attack(Goblin* pc){
    double d = pc->getDefence();
    int damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage += ceil((100/100+d) * this->Atk);
    }
    miss = rand()%2 + 1;
    if (miss == 1){
        damage += ceil((100/100+d) * this->Atk);
    }
    pc->setHealth(damage);
}
void Elf::attack(Shade* pc){
    double d = pc->getDefence();
    int damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage += ceil((100/100+d) * this->Atk);
    }
    miss = rand()%2 + 1;
    if (miss == 1){
        damage += ceil((100/100+d) * this->Atk);
    }
    pc->setHealth(damage);

}
void Elf::attack(Troll* pc){
    double d = pc->getDefence();
    int damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage += ceil((100/100+d) * this->Atk);
    }
    miss = rand()%2 + 1;
    if (miss == 1){
        damage += ceil((100/100+d) * this->Atk);
    }
    pc->setHealth(damage);

}
void Elf::attack(Vampire* pc){
    double d = pc->getDefence();
    int damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        damage += ceil((100/100+d) * this->Atk);
    }
    miss = rand()%2 + 1;
    if (miss == 1){
        damage += ceil((100/100+d) * this->Atk);
    }
    pc->setHealth(damage);

}
Elf::~Elf(){
}
