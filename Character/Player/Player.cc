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
#include "Potion.h"

#include "Human.h"
#include "Halfling.h"
#include "Elf.h"
#include "Orc.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Dwarf.h"
#include "DragonHoard.h"

using namespace std;

GridObjectType Player::getObjType(){
    return GridObjectType::Player;
}

void Player::move(string dir){
    ActionMessage = "";
    if(autoheal){
        if(HP + 5 >= 120){
            HP = 120;
            update_message("Already reach MaxHP. ");
        }else{
            HP = HP + 5;
            update_message("Gain HP by 5. ");
        }
    }
    int r = currentRow;
    int c = currentCol;
    if(dir == "no"){
        r--;
        update_message("Player moves North ");
    }else if(dir == "so"){
        r++;
        update_message("Player moves South ");
    }else if(dir == "ea"){
        c++;
        update_message("Player moves East ");
    }else if(dir == "we"){
        c--;
        update_message("Player moves West ");
    }else if(dir == "ne"){
        r--;
        c++;
        update_message("Player moves NorthEast ");
    }else if(dir == "nw"){
        r--;
        c--;
        update_message("Player moves NorthWest ");
    }else if(dir == "se"){
        r++;
        c++;
        update_message("Player moves SouthEast ");
    }else if(dir == "sw"){
        r++;
        c--;
        update_message("Player moves SouthWest ");
    }
    
    
    if((*gO)[r][c]->getObjType() == GridObjectType::StairWay){
        reachStairs = true;
        emptyMessage();
        clearObservers();
        return;
    }
    
    cout << endl << r << " " << c << endl;
    
    //*********************************************************************************************************************************
    //detect POTION
    if((*gO)[r+1][c]->getObjType() == GridObjectType::BA ||
       (*gO)[r+1][c]->getObjType() == GridObjectType::BD ||
       (*gO)[r+1][c]->getObjType() == GridObjectType::PH ||
       (*gO)[r+1][c]->getObjType() == GridObjectType::WD ||
       (*gO)[r+1][c]->getObjType() == GridObjectType::WA ||
       (*gO)[r+1][c]->getObjType() == GridObjectType::RH){
        shared_ptr<Potion> p = dynamic_pointer_cast<Potion>((*gO)[r+1][c]);
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(knowPotion(potionType)){
            update_message("and see a ");
            switch(p->getObjType()){
                case GridObjectType::BA:
                    update_message("BA, a potion that will increase attack. ");
                    break;
                case GridObjectType::BD:
                    update_message("BD, a potion that will increase defence. ");
                    break;
                case GridObjectType::PH:
                    update_message("PH, a potion that will decrease health. ");
                    break;
                case GridObjectType::RH:
                    update_message("RH, a potion that will increase health. ");
                    break;
                case GridObjectType::WA:
                    update_message("WA, a potion that will decrease attack. ");
                    break;
                case GridObjectType::WD:
                    update_message("WD, a potion that will decrease defence. ");
                    break;
                default:
                    break;
            }
        }else{
            update_message("and see an unknown potion. ");
        }
    }
    if((*gO)[r-1][c]->getObjType() == GridObjectType::BA ||
        (*gO)[r-1][c]->getObjType() == GridObjectType::BD ||
        (*gO)[r-1][c]->getObjType() == GridObjectType::PH ||
        (*gO)[r-1][c]->getObjType() == GridObjectType::WD ||
        (*gO)[r-1][c]->getObjType() == GridObjectType::WA ||
        (*gO)[r-1][c]->getObjType() == GridObjectType::RH){
        shared_ptr<Potion> p = dynamic_pointer_cast<Potion>((*gO)[r-1][c]);
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(knowPotion(potionType)){
            update_message("and see a ");
            switch(p->getObjType()){
                case GridObjectType::BA:
                    update_message("BA, a potion that will increase attack. ");
                    break;
                case GridObjectType::BD:
                    update_message("BD, a potion that will increase defence. ");
                    break;
                case GridObjectType::PH:
                    update_message("PH, a potion that will decrease health. ");
                    break;
                case GridObjectType::RH:
                    update_message("RH, a potion that will increase health. ");
                    break;
                case GridObjectType::WA:
                    update_message("WA, a potion that will decrease attack. ");
                    break;
                case GridObjectType::WD:
                    update_message("WD, a potion that will decrease defence. ");
                    break;
                default:
                    break;
            }
        }else{
            update_message("and see an unknown potion. ");
        }
    }
    if((*gO)[r][c+1]->getObjType() == GridObjectType::BA ||
        (*gO)[r][c+1]->getObjType() == GridObjectType::BD ||
        (*gO)[r][c+1]->getObjType() == GridObjectType::PH ||
        (*gO)[r][c+1]->getObjType() == GridObjectType::WD ||
        (*gO)[r][c+1]->getObjType() == GridObjectType::WA ||
        (*gO)[r][c+1]->getObjType() == GridObjectType::RH){
        shared_ptr<Potion> p = dynamic_pointer_cast<Potion>((*gO)[r][c+1]);
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(knowPotion(potionType)){
            update_message("and see a ");
            switch(p->getObjType()){
                case GridObjectType::BA:
                    update_message("BA, a potion that will increase attack. ");
                    break;
                case GridObjectType::BD:
                    update_message("BD, a potion that will increase defence. ");
                    break;
                case GridObjectType::PH:
                    update_message("PH, a potion that will decrease health. ");
                    break;
                case GridObjectType::RH:
                    update_message("RH, a potion that will increase health. ");
                    break;
                case GridObjectType::WA:
                    update_message("WA, a potion that will decrease attack. ");
                    break;
                case GridObjectType::WD:
                    update_message("WD, a potion that will decrease defence. ");
                    break;
                default:
                    break;
            }
        }else{
            update_message("and see an unknown potion. ");
        }
    }
    if((*gO)[r][c-1]->getObjType() == GridObjectType::BA ||
        (*gO)[r][c-1]->getObjType() == GridObjectType::BD ||
        (*gO)[r][c-1]->getObjType() == GridObjectType::PH ||
        (*gO)[r][c-1]->getObjType() == GridObjectType::WD ||
        (*gO)[r][c-1]->getObjType() == GridObjectType::WA ||
        (*gO)[r][c-1]->getObjType() == GridObjectType::RH){
        shared_ptr<Potion> p = dynamic_pointer_cast<Potion>((*gO)[r][c-1]);
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(knowPotion(potionType)){
            update_message("and see a ");
            switch(p->getObjType()){
                case GridObjectType::BA:
                    update_message("BA, a potion that will increase attack. ");
                    break;
                case GridObjectType::BD:
                    update_message("BD, a potion that will increase defence. ");
                    break;
                case GridObjectType::PH:
                    update_message("PH, a potion that will decrease health. ");
                    break;
                case GridObjectType::RH:
                    update_message("RH, a potion that will increase health. ");
                    break;
                case GridObjectType::WA:
                    update_message("WA, a potion that will decrease attack. ");
                    break;
                case GridObjectType::WD:
                    update_message("WD, a potion that will decrease defence. ");
                    break;
                default:
                    break;
            }
        }else{
            update_message("and see an unknown potion. ");
        }
    }
    if((*gO)[r+1][c+1]->getObjType() == GridObjectType::BA ||
       (*gO)[r+1][c+1]->getObjType() == GridObjectType::BD ||
       (*gO)[r+1][c+1]->getObjType() == GridObjectType::PH ||
       (*gO)[r+1][c+1]->getObjType() == GridObjectType::WD ||
       (*gO)[r+1][c+1]->getObjType() == GridObjectType::WA ||
       (*gO)[r+1][c+1]->getObjType() == GridObjectType::RH){
        shared_ptr<Potion> p = dynamic_pointer_cast<Potion>((*gO)[r+1][c+1]);
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(knowPotion(potionType)){
            update_message("and see a ");
            switch(p->getObjType()){
                case GridObjectType::BA:
                    update_message("BA, a potion that will increase attack. ");
                    break;
                case GridObjectType::BD:
                    update_message("BD, a potion that will increase defence. ");
                    break;
                case GridObjectType::PH:
                    update_message("PH, a potion that will decrease health. ");
                    break;
                case GridObjectType::RH:
                    update_message("RH, a potion that will increase health. ");
                    break;
                case GridObjectType::WA:
                    update_message("WA, a potion that will decrease attack. ");
                    break;
                case GridObjectType::WD:
                    update_message("WD, a potion that will decrease defence. ");
                    break;
                default:
                    break;
            }
        }else{
            update_message("and see an unknown potion. ");
        }
    }
    if((*gO)[r-1][c+1]->getObjType() == GridObjectType::BA ||
       (*gO)[r-1][c+1]->getObjType() == GridObjectType::BD ||
       (*gO)[r-1][c+1]->getObjType() == GridObjectType::PH ||
       (*gO)[r-1][c+1]->getObjType() == GridObjectType::WD ||
       (*gO)[r-1][c+1]->getObjType() == GridObjectType::WA ||
       (*gO)[r-1][c+1]->getObjType() == GridObjectType::RH){
        shared_ptr<Potion> p = dynamic_pointer_cast<Potion>((*gO)[r-1][c+1]);
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(knowPotion(potionType)){
            update_message("and see a ");
            switch(p->getObjType()){
                case GridObjectType::BA:
                    update_message("BA, a potion that will increase attack. ");
                    break;
                case GridObjectType::BD:
                    update_message("BD, a potion that will increase defence. ");
                    break;
                case GridObjectType::PH:
                    update_message("PH, a potion that will decrease health. ");
                    break;
                case GridObjectType::RH:
                    update_message("RH, a potion that will increase health. ");
                    break;
                case GridObjectType::WA:
                    update_message("WA, a potion that will decrease attack. ");
                    break;
                case GridObjectType::WD:
                    update_message("WD, a potion that will decrease defence. ");
                    break;
                default:
                    break;
            }
            update_message(" potion");
        }else{
            update_message("and see an unknown potion. ");
        }
    }
    if((*gO)[r-1][c-1]->getObjType() == GridObjectType::BA ||
       (*gO)[r-1][c-1]->getObjType() == GridObjectType::BD ||
       (*gO)[r-1][c-1]->getObjType() == GridObjectType::PH ||
       (*gO)[r-1][c-1]->getObjType() == GridObjectType::WD ||
       (*gO)[r-1][c-1]->getObjType() == GridObjectType::WA ||
       (*gO)[r-1][c-1]->getObjType() == GridObjectType::RH){
        shared_ptr<Potion> p = dynamic_pointer_cast<Potion>((*gO)[r-1][c-1]);
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(knowPotion(potionType)){
            update_message("and see a ");
            switch(p->getObjType()){
                case GridObjectType::BA:
                    update_message("BA, a potion that will increase attack. ");
                    break;
                case GridObjectType::BD:
                    update_message("BD, a potion that will increase defence. ");
                    break;
                case GridObjectType::PH:
                    update_message("PH, a potion that will decrease health. ");
                    break;
                case GridObjectType::RH:
                    update_message("RH, a potion that will increase health. ");
                    break;
                case GridObjectType::WA:
                    update_message("WA, a potion that will decrease attack. ");
                    break;
                case GridObjectType::WD:
                    update_message("WD, a potion that will decrease defence. ");
                    break;
                default:
                    break;
            }
        }else{
            update_message("and see an unknown potion. ");
        }
    }
    if((*gO)[r+1][c-1]->getObjType() == GridObjectType::BA ||
       (*gO)[r+1][c-1]->getObjType() == GridObjectType::BD ||
       (*gO)[r+1][c-1]->getObjType() == GridObjectType::PH ||
       (*gO)[r+1][c-1]->getObjType() == GridObjectType::WD ||
       (*gO)[r+1][c-1]->getObjType() == GridObjectType::WA ||
       (*gO)[r+1][c-1]->getObjType() == GridObjectType::RH){
        shared_ptr<Potion> p = dynamic_pointer_cast<Potion>((*gO)[r+1][c-1]);
        string potionType;
        switch (p->getObjType()) {
            case GridObjectType::BA:
                potionType = "BA";
                break;
            case GridObjectType::BD:
                potionType = "BD";
                break;
            case GridObjectType::WA:
                potionType = "WA";
                break;
            case GridObjectType::WD:
                potionType = "WD";
                break;
            case GridObjectType::RH:
                potionType = "RH";
                break;
            case GridObjectType::PH:
                potionType = "PH";
                break;
            default:
                break;
        }
        if(knowPotion(potionType)){
            update_message("and see a ");
            switch(p->getObjType()){
                case GridObjectType::BA:
                    update_message("BA, a potion that will increase attack. ");
                    break;
                case GridObjectType::BD:
                    update_message("BD, a potion that will increase defence. ");
                    break;
                case GridObjectType::PH:
                    update_message("PH, a potion that will decrease health. ");
                    break;
                case GridObjectType::RH:
                    update_message("RH, a potion that will increase health. ");
                    break;
                case GridObjectType::WA:
                    update_message("WA, a potion that will decrease attack. ");
                    break;
                case GridObjectType::WD:
                    update_message("WD, a potion that will decrease defence. ");
                    break;
                default:
                    break;
            }
            update_message(" potion");
        }else{
            update_message("and see an unknown potion. ");
        }
    }
    
//*********************************************************************************************************************************
//gold pick up
   
    if((*gO)[r][c]->getObjType() == GridObjectType::smallGold ||
       (*gO)[r][c]->getObjType() == GridObjectType::normalGold ||
       (*gO)[r][c]->getObjType() == GridObjectType::merchantHoard ||
       (*gO)[r][c]->getObjType() == GridObjectType::dragonHoard ||
       (onDragonHoard == true && (*gO)[r][c]->getObsType() != ObstacleType::BolckAll)){
        if(dynamic_pointer_cast<Gold>((*gO)[r][c])){
            shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r][c]);
            g->setPos(r, c);
            g->notifyObservers(SubscriptionType::displayOnly);
            if(g->canPickUp()){
                onDragonHoard = true;
                shared_ptr<FloorTile> f = make_shared<FloorTile>();
                (*gO)[r][c] = f;
                f->setPos(r, c);
                f->attatch(TD);
            }else{
                if(!onDragonHoard){
                gold += g->getGold();
                shared_ptr<FloorTile> f = make_shared<FloorTile>();
                (*gO)[r][c] = f;
                f->setPos(r, c);
                ActionMessage.append("and picks up ");
                ActionMessage.append(to_string(g->getGoldCount()));
                if(g->getObjType() == GridObjectType::smallGold){
                    ActionMessage.append(" small Gold. ");
                } else if(g->getObjType() == GridObjectType::normalGold){
                    ActionMessage.append(" normal Gold. ");
                }else if(g->getObjType() == GridObjectType::merchantHoard){
                    ActionMessage.append(" merchant Hoard. ");
                }else if(g->getObjType() == GridObjectType::dragonHoard){
                    ActionMessage.append(" dragon Hoard. s");
                }
                }else{
                   gold += g->getGold();
                    shared_ptr<DragonHoard> g = make_shared<DragonHoard>();
                    (*gO)[r][c] = g;
                    g->setPos(r, c);
                    g->attatch(dynamic_pointer_cast<Observer>(TD));
                    g->notifyObservers(SubscriptionType::displayOnly);
                    onDragonHoard = false;
                }
            }
        }else{
            shared_ptr<DragonHoard> g = make_shared<DragonHoard>();
            (*gO)[r][c] = g;
            g->setPos(r, c);
            g->attatch(dynamic_pointer_cast<Observer>(TD));
            g->notifyObservers(SubscriptionType::displayOnly);
            onDragonHoard = false;
        }
       
    }

//*********************************************************************************************************************************
// gold pickup done
    
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
        
        shared_ptr<GridObjects> go = (*gO)[r][c];
        (*gO)[r][c] = (*gO)[previousRow][previousCol];
        (*gO)[previousRow][previousCol] = go;
        currentRow = r;
        currentCol = c;
    }else{
        emptyMessage();
        update_message("Invalid move! ");
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
        if (h > HP) {
            ActionMessage.append("Player uses potion. Heal "+to_string(10)+" HP");
        }
        else {
            ActionMessage.append("Player uses potion. Poison -"+to_string(10)+" HP");
        }
        HP = h;
        
    }else if(h >= MaxHP){
        HP = MaxHP;
        ActionMessage.append("Player uses potion. HP restored to max");
    }else{
        if (h > HP) {
            ActionMessage.append("Player uses potion. Heal "+to_string(10)+" HP");
        }
        else {
            ActionMessage.append("Player uses potion. Poison -"+to_string(10)+" HP");
        }
        HP = h;
    }
    if(HP <= 0){
        isDead = true;
    }
}

void Player::getDamage(double damage){
    HP = HP - damage;
    if(damage !=0){
        update_message(" deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" to PC. ");
    } else{
        update_message(" Miss an attack. ");
    }
    if(HP <= 0){
        isDead = true;
    }
}

bool Player::hasDead() {
    return isDead;
}

void Player::attack(std::string dir, std::shared_ptr<Player>pc){
    ActionMessage = "";
    int r = currentRow;
    int c = currentCol;
    if(autoheal){
        if(HP + 5 >= 120){
            HP = 120;
            update_message("Already reach MaxHP. ");
        }else{
            HP = HP + 5;
            update_message("Gain HP by 5. ");
        }
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
        attackIt(e, pc);
    }else{
         this->notifyObservers(SubscriptionType::All);
        update_message("There does not exist an enemy. ");
    }
}

void Player::attackIt(std::shared_ptr<Enemy> e, std::shared_ptr<Player>pc){
    if(dynamic_pointer_cast<Elf>(e)){
        attackIt(dynamic_pointer_cast<Elf>(e), pc);
    }else if(dynamic_pointer_cast<Dwarf>(e)){
        attackIt(dynamic_pointer_cast<Dwarf>(e),pc);
    }else if(dynamic_pointer_cast<Dragon>(e)){
        attackIt(dynamic_pointer_cast<Dragon>(e),pc);
    }else if(dynamic_pointer_cast<Halfling>(e)){
        attackIt(dynamic_pointer_cast<Halfling>(e),pc);
    }else if(dynamic_pointer_cast<Human>(e)){
        attackIt(dynamic_pointer_cast<Human>(e),pc);
    }else if(dynamic_pointer_cast<Merchant>(e)){
        attackIt(dynamic_pointer_cast<Merchant>(e), pc);
    }else if(dynamic_pointer_cast<Orc>(e)){
        attackIt(dynamic_pointer_cast<Orc>(e), pc);
    }
     this->notifyObservers(SubscriptionType::All);
}

void Player::attackIt(std::shared_ptr<Dwarf> e, std::shared_ptr<Player>pc) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(static_cast<int>(damage));
    if (!e->isDead()) {
        update_message("PC deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" damage to Dwarf ");
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

void Player::attackIt(std::shared_ptr<Dragon> e, std::shared_ptr<Player>pc) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(static_cast<int>(damage));
    if (!e->isDead()) {
        update_message("PC deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" damage to Dragon ");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }
    else {
        update_message("Dragon has been slain by PC. ");
    }
    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Elf> e, std::shared_ptr<Player>pc) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(static_cast<int>(damage));
    if (!e->isDead()) {
        update_message("PC deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" damage to Elf ");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }
    else {
        update_message("Elf has been slain by PC. ");
    }

    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Halfling> e, std::shared_ptr<Player>pc) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(static_cast<int>(damage));
    if (!e->isDead()) {
        update_message("PC deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" damage to Halfling ");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }
    else {
        update_message("Halfling has been slain by PC. ");
    }

    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Human> e, std::shared_ptr<Player>pc) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(static_cast<int>(damage));
    if (!e->isDead()) {
        update_message("PC deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" damage to Human ");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }
    else {
        update_message("Human has been slain by PC. ");
    }

    check_dead(e);
}

void Player::attackIt(std::shared_ptr<Merchant> e, std::shared_ptr<Player>pc) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(static_cast<int>(damage));
    if (!e->isDead()) {
        update_message("PC deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" damage to Merchant ");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }
    else {
        update_message("Merchant has been slain by PC. ");
    }

    check_dead(e);
    if(e->isDead()){
        
    }
}

void Player::attackIt(std::shared_ptr<Orc> e, std::shared_ptr<Player>pc) {
    double d = e->getDefence();
    double damage = ceil((100/(100+d)) * pc->getAttack());
    e->updateDamage(static_cast<int>(damage));
    if (!e->isDead()) {
        update_message("PC deals ");
        update_message(to_string(static_cast<int>(damage)));
        update_message(" damage to Orc ");
        update_message("(");
        update_message(std::to_string(static_cast<int>(e->getHP())));
        update_message("/");
        update_message(std::to_string(static_cast<int>(e->getMaxHP())));
        update_message(")");
    }
    else {
        update_message("Orc has been slain by PC. ");
    }

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
            update_message("Merchant drops two piles of Normal Gold. ");
            n->notifyObservers(SubscriptionType::displayOnly);
        }else if(e->dropgold() == 4){
            shared_ptr<MerchantHoard> m = make_shared<MerchantHoard>();
            m->attatch(TD);
            m->setPos(r, c);
            (*gO)[r][c] = m;
            update_message("Merchant drops a pile of Merchant Hoard. ");
            m->notifyObservers(SubscriptionType::displayOnly);
        }else{
            shared_ptr<FloorTile> f = make_shared<FloorTile>();
            f->attatch(TD);
             f->setPos(r, c);
            (*gO)[r][c] = f;
            f->notifyObservers(SubscriptionType::displayOnly);
            if(!dynamic_pointer_cast<Dragon>(e)){
            int x = rand()%2+1;
            if(x == 1){
                gold = gold + 1;
                update_message("PC gets a small pile of gold. ");
            }else{
                gold = gold +2;
                update_message("PC gets a normal pile of gold. ");
            }
            }
        }
        if(steal){
            gold = gold + 5;
        }
        if(dynamic_pointer_cast<Dragon>(e)){
            if((*gO)[r+1][c]->getObjType() == GridObjectType::dragonHoard){
                shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r+1][c]);
                g->setGuarded();
            }else if((*gO)[r-1][c]->getObjType() == GridObjectType::dragonHoard){
                shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r-1][c]);
                g->setGuarded();
            }else if((*gO)[r+1][c+1]->getObjType() == GridObjectType::dragonHoard){
                shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r+1][c+1]);
                g->setGuarded();
            }else if((*gO)[r-1][c+1]->getObjType() == GridObjectType::dragonHoard){
                shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r-1][c+1]);
                g->setGuarded();
            }else if((*gO)[r][c+1]->getObjType() == GridObjectType::dragonHoard){
                shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r][c+1]);
                g->setGuarded();
            }else if((*gO)[r][c-1]->getObjType() == GridObjectType::dragonHoard){
                shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r][c-1]);
                g->setGuarded();
            }else if((*gO)[r+1][c-1]->getObjType() == GridObjectType::dragonHoard){
                shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r+1][c-1]);
                g->setGuarded();
            }else if((*gO)[r-1][c-1]->getObjType() == GridObjectType::dragonHoard){
                shared_ptr<Gold> g = dynamic_pointer_cast<Gold>((*gO)[r-1][c-1]);
                g->setGuarded();
            }else{
                onDragonHoard = false;
                gold = gold + 6;
                update_message("PC gets a Dragon Hoard. ");
            }
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

void Player::emptyMessage(){
    ActionMessage = "";
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
    cout << "Floor: " << getFloorNum() << endl;
    cout << "HP: " << getHP() << endl;
    cout << "Atk: " << getAttack() << endl;
    cout << "Def: " << getDefence() << endl;
    cout << "Action: " << getActionMessage() <<endl;
}

std::shared_ptr<Player> Player::getTrue() {
    return shared_from_this();
}

bool Player::hasReachedShairs() {
    return reachStairs;
}

int Player::goUpstairs() {
    reachStairs = false;
    floorNum++;
    update_message("Player Enters Floor " + to_string(floorNum) + ". ");
    return floorNum;
}

void Player::memorizePotion(std::string s) {
    if (s == "BA") usedBA = true;
    else if (s == "BD") usedBD = true;
    else if (s == "WA") usedWA = true;
    else if (s == "WD") usedWD = true;
    else if (s == "RH") usedRH = true;
    else if (s == "PH") usedPH = true;
}

bool Player::knowPotion(std::string s) {
    if (s == "BA") return usedBA;
    else if (s == "BD") return usedBD;
    else if (s == "WA") return usedWA;
    else if (s == "WD") return usedWD;
    else if (s == "RH") return usedRH;
    else return usedPH;
}

int Player::getFloorNum() {
    return floorNum;
}
