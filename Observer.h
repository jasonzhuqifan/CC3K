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

class Observer {
public:
    virtual void notify(Subject &notifier) = 0;
    virtual ~Observer()= default;
};


#endif /* Observer_hpp */
