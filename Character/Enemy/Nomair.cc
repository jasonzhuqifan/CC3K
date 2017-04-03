#include "Nomair.h"
#include "Student.h"

Nomair::Nomair(){
    HP = 60;
    Atk = 30;
    Def = 30;
    MaxHP = 60;
}

void Nomair::attack(std::shared_ptr<Student> pc, double true_def){
    double damage = 0;
    int miss = rand()%2+1;
    if (miss == 1){
        int strike = rand()%10+1;
        if(strike == 1){  //strike! 4 times damage
            damage = ceil((100/(100+true_def)) * this->Atk * 4);
        }else if(strike == 2 || strike == 3){  //strike! 3 times damage
            damage = ceil((100/(100+true_def)) * this->Atk * 3);
        }else if(strike == 4 || strike == 5 || strike == 6){  //strike! 2 times damage
            damage = ceil((100/(100+true_def)) * this->Atk * 2);
        }else{  //normal damage
            damage = ceil((100/(100+true_def)) * this->Atk * 1);
        }
    }
    pc->getDamage(damage);
}
Nomair::~Nomair(){};
