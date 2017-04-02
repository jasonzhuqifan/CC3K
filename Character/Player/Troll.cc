#include "Troll.h"
#include "Halfling.h"
#include "Merchant.h"

using namespace std;


Troll::Troll(){
    HP = 120;
    Atk = 25;
    Def = 15;
    MaxHP = 120;
    autoheal = true;
    playerRace = "Troll";
}

void Troll::attackIt(std::shared_ptr<Halfling> e){
    int miss = rand()%2+1;
    if(miss == 1){
        double d = e->getDefence();
        double damage = ceil((100/(100+d)) * getAttack());
        update_message("PC deals ");
        update_message(std::to_string(static_cast<int>(damage)));
        update_message(" damage to Halfling");
        e->updateDamage(damage);
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(e->getMaxHP()));
        update_message(")");

    }else{
        update_message("PC misses attack to Halfing. ");
    }
    check_dead(e);
}
void Troll::attackIt(std::shared_ptr<Merchant> e){
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    e->updateDamage(damage);
    update_message("PC deals ");
    update_message(std::to_string(static_cast<int>(damage)));
    update_message(" damage to Merchant");
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(e->getMaxHP()));
    update_message(")");
    e->setNeutral();
    check_dead(e);
}


Troll::~Troll(){
    
}
