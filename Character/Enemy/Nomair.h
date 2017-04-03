
#ifndef Nomair_hpp
#define Nomair_hpp
#include "Enemy.h"

class Nomair : public Enemy{
    Nomair();
    ~Nomair();
    void attack(std::shared_ptr<Student> pc, double true_def) override;
};



#endif /* nomair_hpp */
