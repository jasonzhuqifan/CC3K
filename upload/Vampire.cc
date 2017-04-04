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
    HP = 50;
    Atk = 25;
    Def = 25;
    MaxHP = -1;
    playerRace = "Vampire";
}

void Vampire::attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/(100+d)) * pc->getAttack());
         e->updateDamage(damage);
        if(!e->isDead()) {
        update_message("PC deals ");
        update_message(std::to_string(damage));
        update_message(" damage to Dragon and gains 5 HP");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
        HP = HP + 5;
        }else{
            update_message("Halfling has been slain by PC. ");
        }
    }else{
        update_message("PC misses attack to Halfing. ");
    }
    check_dead(e);
}

void Vampire::attackIt(std::shared_ptr<Dwarf> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
     e->updateDamage(damage);
    if(!e->isDead()){
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Dwarf and gains 5 HP");
    update_message("(");
    update_message(std::to_string(e->getHP()));
    update_message(")");
    HP = HP - 5;
    }else{
        update_message("Dwarf has been slain by PC. ");
    }
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Dragon> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
     e->updateDamage(damage);
    if(!e->isDead()){
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Dragon and gains 5 HP");
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
     HP = HP + 5;
    }else{
        update_message("Dragon has been slain by PC. ");
    }
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Elf> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
     e->updateDamage(damage);
    if(!e->isDead()){
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Elf and gains 5 HP");
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    HP = HP + 5;
    }else{
        update_message("Elf has been slain by PC. ");
    }
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Human> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
     e->updateDamage(damage);
    if(!e->isDead()){
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Human and gains 5 HP");
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
     HP = HP + 5;
    }else{
        update_message("Human has been slain by PC. ");
    }
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(damage);
    if(!e->isDead()){
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Merchant and gains 5 HP");
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
     HP = HP + 5;
    }else{
        update_message("Merchant has been slain by PC. ");
    }
    e->setNeutral();
    check_dead(e);
}
void Vampire::attackIt(std::shared_ptr<Orc> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(damage);
    if(!e->isDead()){
    update_message("PC deals ");
    update_message(std::to_string(damage));
    update_message(" damage to Dragon and gains 5 HP");
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    HP = HP + 5;
    }else{
        update_message("Orc has been slain by PC. ");
    }
    check_dead(e);
}


Vampire::~Vampire(){}
