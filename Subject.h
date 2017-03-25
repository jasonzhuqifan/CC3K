//
//  Subject.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef Subject_hpp
#define Subject_hpp
#include <vector>
using namespace std;

class Info;
class observer;

class subject{
    std::vector<observer *> observers;
public:
    subject();
    void attatch(observer *o);
    void detach(observer *o);
    void notifyObservers();
    virtual Info getInfo() = 0;
    virtual ~subject() = 0;
};

#endif /* Subject_hpp */
