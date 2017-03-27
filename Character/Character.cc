#include "Character.h"
#include "Info.h"

Info Character::getInfo(){
    Info f;
    f.currentCol = currentCol;
    f.currentRow = currentRow;
    f.previousCol = previousCol;
    f.previousRow = previousRow;
    f.GOT = getObjType();
    return f;
}
