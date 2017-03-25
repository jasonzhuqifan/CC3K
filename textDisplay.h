//
//  textDisplay.hpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#ifndef textDisplay_hpp
#define textDisplay_hpp

#include "observer.h"
#include <vector>
using namespace std;


class textDisplay: public observer{
    vector<vector<char>> theDisplay;
public:
    textDisplay();
    void notify() override;
    ~textDisplay();
    
    friend ostream &operator<<(ostream &out, const textDisplay &td);
};

#endif /* textDisplay_hpp */
