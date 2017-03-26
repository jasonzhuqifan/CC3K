#ifndef GridObjects_hpp
#define GridObjects_hpp

#include "Floor.h"
#include "ObstacleType.h"
#include "GridObjectType.h"

class GridObjects : public Floor{
protected:
    int previousRow;
    int previousCol;
    int currentRow;
    int currentCol;
    virtual ObstacleType getObsType() = 0;
    virtual GridObjectType getObjType() = 0;
};

#endif
