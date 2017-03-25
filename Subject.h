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
class Observer;

class Subject{
    std::vector<observer *> Observers;
public:
    Subject();
    void attatch(Observer *o);
    void detach(Observer *o);
    void notifyObservers();
    virtual Info getInfo() = 0;
    virtual ~Subject() = 0;
};

#endif /* Subject_hpp */
