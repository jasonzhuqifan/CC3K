#ifndef textDisplay_hpp
#define textDisplay_hpp

#include <iostream>
#include "observer.h"
#include <vector>
#include <string>

class GridObjects;

class TextDisplay: public Observer{
    std::vector<std::vector<char>> theDisplay;
    std::string Race;
    double Floor;
    double HP;
    double Atk;
    double Def;
    std::string Message;
public:
    void spawn(int x, int y, char type);
    TextDisplay();
    void notify(Subject &notifier) override;
    SubscriptionType getSubType() const override;
    ~TextDisplay();
    
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif /* textDisplay_hpp */
