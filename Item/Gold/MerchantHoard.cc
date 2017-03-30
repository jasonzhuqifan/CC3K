#include "MerchantHoard.h"

MerchantHoard::MerchantHoard (int count) : Gold(4, count) {}

GridObjectType MerchantHoard::getObjType() {
    return GridObjectType::merchantHoard;
}
