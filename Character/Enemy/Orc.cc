#include "Orc.h"

#include "Drow.h"
#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"
#include "Goblin.h"

void Orc::attack(Drow* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    pc->setHealth(damage);
}
void Orc::attack(Goblin* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk * 1.5);
    pc->setHealth(damage);
}
void Orc::attack(Shade* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    pc->setHealth(damage);
}
void Orc::attack(Troll* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    pc->setHealth(damage);
}
void Orc::attack(Vampire* pc){
    double d = pc->getDefence();
    double damage = ceil((100/100+d) * this->Atk);
    pc->setHealth(damage);
}
