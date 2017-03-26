#include "Player.h"
#include "Info.h"


Info Player::getInfo(){
    Info f;
    f.currentCol = currentCol;
    f.currentRow = currentRow;
    f.previousCol = previousCol;
    f.previousRow = previousRow;
    return f;
}


GridObjectType Player::getObjType(){
    return GridObjectType::Player;
}

int Player::getHP(){
    return HP;
}

int Player::getDefence(){
    return Def;
}

int Player::getAttack(){
    return Atk;
}

int Player::getGold(){
    return Gold;
}

int Player::getMaxHP(){
    return MaxHP;
}

