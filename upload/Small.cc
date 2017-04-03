#include "Small.h"

Small::Small(int count) : Gold(1,count) {}

GridObjectType Small::getObjType() {
    return GridObjectType::smallGold;
}
