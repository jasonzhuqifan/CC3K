//
//  StairWay.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef StairWay_hpp
#define StairWay_hpp

#include "Cell.h"

class StairWay : public Cell{
public:
    ObstacleType getObsType() override;
    GridObjectType getObjType() override;
};

#endif /* StairWay_hpp */
