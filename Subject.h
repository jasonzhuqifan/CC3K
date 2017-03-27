#ifndef Subject_hpp
#define Subject_hpp
#include <vector>
#include "SubscriptionType.h"

using namespace std;

class Info;
class Observer;

class Subject{
    std::vector<Observer *> Observers;
public:
    Subject();
    void attatch(Observer *o);
    void detach(Observer *o);
    void notifyObservers(SubscriptionType t);
    virtual Info getInfo() = 0;;
    virtual ~Subject() = 0;
    
};

#endif 
