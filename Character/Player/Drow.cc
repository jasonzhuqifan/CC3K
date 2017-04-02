#include "Drow.h"
#include "Merchant.h"
#include "Halfling.h"


using namespace std;

Drow::Drow(){
    HP = 150;
    Atk = 25;
    Def = 15;
    MaxHP = 150;
    magnify = true;
    playerRace = "Drow";
}

void Drow::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/(100+d)) * getAttack());
        e->updateDamage(damage);
        update_message("PC deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" damage to Halfling");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }
    check_dead(e);
}

void Drow::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    e->updateDamage(damage);
    update_message("PC deals ");
    update_message(to_string(static_cast<int>(damage)));
    update_message(" damage to Merchant");
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    e->setNeutral();
    check_dead(e);
}
Drow::~Drow(){}
