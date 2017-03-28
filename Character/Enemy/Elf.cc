#include "Elf.h"

#include "Drow.h"
#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"
#include "Goblin.h"
void Elf::attack(Drow* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    pc->setHealth(damage);
}
void Elf::attack(Goblin* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk * 2);
    pc->setHealth(damage);
}
void Elf::attack(Shade* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk * 2);
    pc->setHealth(damage);
}
void Elf::attack(Troll* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk * 2);
    pc->setHealth(damage);
}
void Elf::attack(Vampire* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk * 2);
    pc->setHealth(damage);
}
