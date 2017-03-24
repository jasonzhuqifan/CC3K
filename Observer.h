//
//  Observer.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include "Subject.h"

class observer {
public:
    virtual void notify() = 0;
    virtual ~observer()= default;
};


#endif /* Observer_hpp */
