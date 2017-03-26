#include "Item.h"

Item::Item(Player* pc) : pc{pc} {}

Item::~Item() {delete pc;}
