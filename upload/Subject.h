#ifndef Subject_hpp
#define Subject_hpp
#include <vector>
#include "SubscriptionType.h"
#include <string>


class Info;
class Observer;

class Subject{
    std::vector<std::shared_ptr<Observer>> observers;
protected:
public:
    Subject();
    void attatch(std::shared_ptr<Observer> o);
    void detach(std::shared_ptr<Observer> o);
    void notifyObservers(SubscriptionType t);
    virtual Info getInfo() = 0;
    virtual ~Subject() = default;
    void clearObservers();
};

#endif 
