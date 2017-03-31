#include "DragonHoard.h"

DragonHoard::DragonHoard(int count) : Gold(6, count) {
    isGuarded = true;
}

GridObjectType DragonHoard::getObjType() {
    return GridObjectType::dragonHoard;
}
