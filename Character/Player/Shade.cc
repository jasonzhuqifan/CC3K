#include "Shade.h"
#include "Halfling.h"
#include "Merchant.h"
#include <string>

Shade::Shade(){
    HP = 125;
    Atk = 25;
    Def = 25;
    MaxHP = 125;
    playerRace = "Shade";
}

void Shade::attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/(100+d)) * pc->getAttack());
        update_message("PC deals ");
        update_message(std::to_string(static_cast<int>(damage)));
        update_message(" damage to Halfling");
         e->updateDamage(damage);
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(").");
    }else{
        update_message("PC misses attack to Halfing. ");
    }
    
    check_dead(e);
}

void Shade::attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    update_message("PC deals ");
    update_message(std::to_string(static_cast<int>(damage)));
    update_message(" damage to Merchant. ");
    e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    e->setNeutral();
    check_dead(e);
}
Shade::~Shade(){}
