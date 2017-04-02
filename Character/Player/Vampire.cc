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
    playerRace = "Vampire";
}

void Vampire::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/(100+d)) * getAttack());
        update_message("PC deals ");
        update_message(std::to_string(damage));
        update_message(" damage to Halfling and gains 5 HP");
        update_message("(");
        update_message(std::to_string(e->getHP()));
        update_message(")");
        e->updateDamage(damage);
        HP = HP + 5;
    }
    check_dead(e);
}

void Vampire::attackIt(std::shared_ptr<Dwarf> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Dwarf and gains 5 HP");
    update_message("(");
    update_message(std::to_string(e->getHP()));
    update_message(")");
    e->updateDamage(damage);
    HP = HP - 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Dragon> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Dragon and gains 5 HP");
    update_message("(");
    update_message(std::to_string(e->getHP()));
    update_message(")");
    e->updateDamage(damage);
     HP = HP + 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Elf> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Elf and gains 5 HP");
    update_message("(");
    update_message(std::to_string(e->getHP()));
    update_message(")");
    e->updateDamage(damage);
    HP = HP + 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Human> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Human and gains 5 HP");
    update_message("(");
    update_message(std::to_string(e->getHP()));
    update_message(")");
    e->updateDamage(damage);
     HP = HP + 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Merchant and gains 5 HP");
    e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(e->getHP()));
    update_message("/");
    update_message(std::to_string(e->getMaxHP()));
    update_message(")");
    e->setNeutral();
     HP = HP + 5;
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Orc> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Orc and gains 5 HP");
    e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(e->getHP()));
    update_message("/");
    update_message(std::to_string(e->getMaxHP()));
    update_message(")");
    HP = HP + 5;
    check_dead(e);
}


Vampire::~Vampire(){}
