#ifndef Item_hpp
#define Item_hpp

#include "GridObjects.h"
#include "Subject.h"

class Item : public GridObjects, Subject{
protected:
    Item();
    ~Item();
};

#endif
