#include "Normal.h"

Normal::Normal (int count) : Gold(2,count) {}

GridObjectType Normal::getObjType() {
    return GridObjectType::normalGold;
}
