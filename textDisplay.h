#ifndef textDisplay_hpp
#define textDisplay_hpp

#include "observer.h"
#include <vector>
using namespace std;


class TextDisplay: public Observer{
    vector<vector<char>> theDisplay;
public:
    TextDisplay();
    void notify(Subject &notifier) override;
    ~TextDisplay();
    
    friend ostream &operator<<(ostream &out, const TextDisplay &td);
};

#endif /* textDisplay_hpp */
