#include "Info.h"
#include "GridObjects.h"


Info GridObjects::getInfo(){
    Info f;
    f.currentCol = currentCol;
    f.currentRow = currentRow;
    f.previousCol = previousCol;
    f.previousRow = previousRow;
    f.GOT = getObjType();
    return f;
}

void GridObjects::setPos(int r, int c){
    currentRow = r;
    currentCol = c;
    previousCol = c;
    previousRow = r;
}
