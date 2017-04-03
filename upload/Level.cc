#include "Level.h"

#include <iostream>
#include "textDisplay.h"
using namespace std;


ostream &operator<<(std::ostream &out, const Level &l){
    out << *(l.td);
    return out;
}
