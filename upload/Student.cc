#include "Student.h"
#include "Nomair.h"
#include "Halfling.h"
#include "Merchant.h"
#include <string>

Student::Student(){
    HP = 200;
    Atk = 40;
    Def = 20;
    MaxHP = 200;
    playerRace = "Student";
}

Student::~Student(){
    
}

void Student::attackIt(std::shared_ptr<Nomair> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack() * 0.5);
    e->updateDamage(static_cast<int>(damage));
    if (!e->isDead()) {
        update_message("PC deals ");
        update_message(std::to_string(static_cast<int>(damage)));
        update_message(" damage to Nomair ");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }
    else {
        update_message("Dwarf has been slain by PC. ");
    }
    check_dead(e);
}
void Student::attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/(100+d)) * pc->getAttack());
        e->updateDamage(damage);
        if(!e->isDead()){
            update_message("PC deals ");
            update_message(std::to_string(static_cast<int>(damage)));
            update_message(" damage to Halfling");
            update_message("(");
            update_message(std::to_string(static_cast<int>(e->getHP())));
            update_message("/");
            update_message(std::to_string(static_cast<int>(e->getMaxHP())));
            update_message(")");
        }else{
            update_message("Halfling has been slain by PC. ");        }
    }
    check_dead(e);
}

void Student::attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(damage);
    if(!e->isDead()){
        update_message("PC deals ");
        update_message(std::to_string(static_cast<int>(damage)));
        update_message(" damage to Merchant");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }else{
        update_message("Merchant has been slain by PC. ");
    }
    e->setNeutral();
    check_dead(e);
}

