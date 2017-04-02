#include "Player.h"
#include <string>
#include <iostream>
#include "Enemy.h"
#include "Gold.h"
#include "math.h"
#include "Normal.h"
#include "MerchantHoard.h"
#include "FloorTile.h"
#include "Door.h"
#include "Passages.h"
#include "Info.h"
#include "TextDisplay.h"

#include "Human.h"
#include "Halfling.h"
#include "Elf.h"
#include "Orc.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Dwarf.h"

using namespace std;

GridObjectType Player::getObjType(){
    return GridObjectType::Player;
}

void Player::move(string dir){
    ActionMessage = "";
    if(autoheal){
        HP += 5;
    }
    int r = currentRow;
    int c = currentCol;
    if(dir == "no"){
        r--;
        update_message("Player moves North");
    }else if(dir == "so"){
        r++;
        update_message("Player moves South");
    }else if(dir == "ea"){
        c++;
        update_message("Player moves East");
    }else if(dir == "we"){
        c--;
        update_message("Player moves West");
    }else if(dir == "ne"){
        r--;
        c++;
        update_message("Player moves NorthEast");
    }else if(dir == "nw"){
        r--;
        c--;
        update_message("Player moves NorthWest");
    }else if(dir == "se"){
        r++;
        c++;
        update_message("Player moves SouthEast");
    }else if(dir == "sw"){
        r++;
        c--;
        update_message("Player moves SouthWest");
    }
    
    
    if((*gO)[r][c]->getObjType() == GridObjectType::StairWay){
        reachStairs = true; //HOW TO REACH NEWXT FLOOR
    }
    cout << endl << r << " " << c << endl;
    if((*gO)[r][c]->getObjType() == GridObjectType::smallGold ||
       (*gO)[r][c]->getObjType() == GridObjectType::normalGold ||
       (*gO)[r][c]->getObjType() == GridObjectType::merchantHoard ||
       (*gO)[r][c]->getObjType() == GridObjectType::dragonHoard){
        shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r][c]);
        gold += g->getGold();
        shared_ptr<FloorTile> f = make_shared<FloorTile>();
        (*gO)[r][c] = f;
        ActionMessage.append(" and picks up ");
        ActionMessage.append(to_string(g->getGoldCount()));
        if(g->getObjType() == GridObjectType::smallGold){
            ActionMessage.append(" small Gold");
        } else if(g->getObjType() == GridObjectType::normalGold){
            ActionMessage.append(" normal Gold");
        }else if(g->getObjType() == GridObjectType::merchantHoard){
            ActionMessage.append(" merchant Hoard");
        }else if(g->getObjType() == GridObjectType::dragonHoard){
            ActionMessage.append(" dragon Hoard");
        }
        g->notifyObservers(SubscriptionType::displayOnly);
    }
    
    
    if((*gO)[r][c]->getObsType() != ObstacleType::BolckAll){
        shared_ptr<GridObjects> origin = (*gO)[r][c];
        if(origin->getObjType() == GridObjectType::Passage){
            if(onDoor){
                shared_ptr<Door> d = make_shared<Door>();
                (*gO)[r][c] = d;
                d->setPos(r, c);
                d->attatch(dynamic_pointer_cast<Observer>(TD));
                d->notifyObservers(SubscriptionType::displayOnly);
            }
            onPassage = true;
            onDoor = false;
        }else if(origin->getObjType() == GridObjectType::Door){
            if(onPassage){
                shared_ptr<Passages> p = make_shared<Passages>();
                (*gO)[r][c] = p;
                p->setPos(r, c);
                p->attatch(dynamic_pointer_cast<Observer>(TD));
                p->notifyObservers(SubscriptionType::displayOnly);
            }else{
                shared_ptr<FloorTile> f = make_shared<FloorTile>();
                (*gO)[r][c] = f;
                f->setPos(r, c);
                f->attatch(dynamic_pointer_cast<Observer>(TD));
                f->notifyObservers(SubscriptionType::displayOnly);
            }
            onDoor = true;
            onPassage = false;
        }else if(onDoor){
            shared_ptr<Door> d = make_shared<Door>();
            (*gO)[r][c] = d;
            d->setPos(r, c);
            d->attatch(dynamic_pointer_cast<Observer>(TD));
            d->notifyObservers(SubscriptionType::displayOnly);
            onPassage = false;
            onDoor = false;
        } else {
            onPassage = false;
            onDoor = false;
        }
        
        shared_ptr<GridObjects> g = (*gO)[r][c];
        (*gO)[r][c] = (*gO)[previousRow][previousCol];
        (*gO)[previousRow][previousCol] = g;
        currentRow = r;
        currentCol = c;
    }else{
        ActionMessage="";
    }
    this->notifyObservers(SubscriptionType::All);
    previousRow = currentRow;
    previousCol = currentCol;
}

string Player::getRace() {
    return playerRace;
}

void Player::setHealth(double h){
    if(MaxHP == -1){
        HP = h;
        ActionMessage.append("Player uses potion. Heal "+to_string(h)+" HP");
    }else if(h >= MaxHP){
        HP = MaxHP;
        ActionMessage.append("Player uses potion. Heal "+to_string(MaxHP-h)+" HP");
    }else{
        HP = h;
        ActionMessage.append("Player uses potion. Heal "+to_string(10)+" HP");
    }
    if(HP <= 0){
        //THROW SOMETHING! YOU FUCKED UP!
    }
}
void Player::getDamage(double damage){
    HP = HP - damage;
    if(damage !=0){
        update_message(" deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" to PC. ");
    } else{
        update_message(" Miss an attack");
    }
    if(HP <= 0){
        // THROW SOMETHING! YOU FUCKED UP!
    }
}


void Player::attack(std::string dir, std::shared_ptr<Player>pc){
    ActionMessage = "";
    int r = currentRow;
    int c = currentCol;
    if(autoheal){
        HP += 5;
    }
    if(dir == "no"){
        r--;
    }else if(dir == "so"){
        r++;
    }else if(dir == "ea"){
        c++;
    }else if(dir == "we"){
        c--;
    }else if(dir == "ne"){
        r--;
        c++;
    }else if(dir == "nw"){
        r--;
        c--;
    }else if(dir == "se"){
        r++;
        c++;
    }else if(dir == "sw"){
        r++;
        c--;
    }
    if((*gO)[r][c]->getObjType() == GridObjectType::Enemy){
        shared_ptr<Enemy> e = dynamic_pointer_cast<Enemy>((*gO)[r][c]);
        attackIt(e);
    }
}

void Player::attackIt(std::shared_ptr<Enemy> e){
    if(dynamic_pointer_cast<Elf>(e)){
        attackIt(dynamic_pointer_cast<Elf>(e));
    }else if(dynamic_pointer_cast<Dwarf>(e)){
        attackIt(dynamic_pointer_cast<Dwarf>(e));
    }else if(dynamic_pointer_cast<Dragon>(e)){
        attackIt(dynamic_pointer_cast<Dragon>(e));
    }else if(dynamic_pointer_cast<Halfling>(e)){
        attackIt(dynamic_pointer_cast<Halfling>(e));
    }else if(dynamic_pointer_cast<Human>(e)){
        attackIt(dynamic_pointer_cast<Human>(e));
    }else if(dynamic_pointer_cast<Merchant>(e)){
        attackIt(dynamic_pointer_cast<Merchant>(e));
    }else if(dynamic_pointer_cast<Orc>(e)){
        attackIt(dynamic_pointer_cast<Orc>(e));
    }
    update_message(". ");
    this->notifyObservers(SubscriptionType::All);
}

void Player::attackIt(std::shared_ptr<Dwarf> e) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(to_string(static_cast<int>(damage)));
    update_message(" damage to Dwarf ");
    e->updateDamage(static_cast<int>(damage));
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Dragon> e) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(to_string(static_cast<int>(damage)));
    update_message(" damage to Dragon");
     e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Elf> e) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(to_string(static_cast<int>(damage)));
    update_message(" damage to Elf");
    e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Halfling> e) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(to_string(static_cast<int>(damage)));
    update_message(" damage to Hafling");
     e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Human> e) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(to_string(static_cast<int>(damage)));
    update_message(" damage to Human");
    e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Merchant> e) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(to_string(static_cast<int>(damage)));
    update_message(" damage to Merchant");
     e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Orc> e) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * getAttack());
    update_message("PC deals ");
    update_message(to_string(static_cast<int>(damage)));
    update_message(" damage to Orc");
     e->updateDamage(damage);
    update_message("(");
    update_message(std::to_string(static_cast<int>(e->getHP())));
    update_message("/");
    update_message(std::to_string(static_cast<int>(e->getMaxHP())));
    update_message(")");
    check_dead(e);
}

void Player::check_dead(shared_ptr<Enemy> e){
    if(e->isDead()){
        Info f = e->getInfo();
        int c = f.currentCol;
        int r = f.currentRow;
        if(e->dropgold() == 2){
            shared_ptr<Normal> n = make_shared<Normal>(2);
            n->attatch(TD);
            n->setPos(r, c);
            (*gO)[r][c] = n;
            n->notifyObservers(SubscriptionType::displayOnly);
        }else if(e->dropgold() == 4){
            shared_ptr<MerchantHoard> m = make_shared<MerchantHoard>();
            m->attatch(TD);
            m->setPos(r, c);
            (*gO)[r][c] = m;
            m->notifyObservers(SubscriptionType::displayOnly);
        }else{
            shared_ptr<FloorTile> f = make_shared<FloorTile>();
            f->attatch(TD);
             f->setPos(r, c);
            (*gO)[r][c] = f;
            f->notifyObservers(SubscriptionType::displayOnly);
        }
        if(steal){
            gold = gold + 5;
        }
        detach(e);
    }

}

bool Player::ismagnify(){
    return magnify;
}


bool Player::isautoheal(){
   
    return autoheal;
}

std::string Player::getActionMessage() {
    return ActionMessage;
}

void Player::update_enemy(Enemy *e){
    if(dynamic_cast<Dwarf*>(e)){
        update_message("Dwarf");
    } else if(dynamic_cast<Dragon*>(e)){
        update_message("Dragon");
    } else if(dynamic_cast<Elf*>(e)){
        update_message("Elf");
    }else if(dynamic_cast<Halfling*>(e)){
        update_message("Halfling");
    }else if(dynamic_cast<Human*>(e)){
        update_message("Human");
    }else if(dynamic_cast<Merchant*>(e)){
        update_message("Merchant");
    }else if(dynamic_cast<Orc*>(e)){
        update_message("Orc");
    }
}

void Player::update_message(string s){
    ActionMessage.append(s);
}
void Player::PrintMessages(){
    cout << "Race: " << getRace() << " ";
    cout << "Gold: " << getGold();
    cout << "                                             ";
    cout << "Floor: " << floorNum << endl;
    cout << "HP: " << getHP() << endl;
    cout << "Atk: " << getAttack() << endl;
    cout << "Def: " << getDefence() << endl;
    cout << "Action: " << getActionMessage() <<endl;
}
