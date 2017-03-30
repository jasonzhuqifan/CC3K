#include "DragonHoard.h"

DragonHoard::DragonHoard(int count) : Gold(6, count) {}

GridObjectType DragonHoard::getObjType() {
    return GridObjectType::dragonHoard;
}
