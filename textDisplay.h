#ifndef textDisplay_hpp
#define textDisplay_hpp

#include "observer.h"
#include <vector>
#include <string>

class GridObjects;

class TextDisplay: public Observer{
    std::vector<std::vector<char>> theDisplay;
    std::string Race;
    int Floor;
    int HP;
    int Atk;
    int Def;
    std::string Message;
public:
    TextDisplay();
    void notify(Subject &notifier) override;
    SubscriptionType getSubType() const override;
    ~TextDisplay();
    
    friend ostream &operator<<(ostream &out, const TextDisplay &td);
};

#endif /* textDisplay_hpp */
