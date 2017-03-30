//
//  Subject.cpp
//  CC3KFInalProject
//
//  Created by Raymond Tan on 2017-03-23.
//  Copyright © 2017 Raymond Tan. All rights reserved.
//

#include "Subject.h"
#include "Observer.h"
#include "Info.h"
using namespace std;

Subject::Subject(){
    
}


void Subject::attatch(shared_ptr<Observer> o){
    observers.emplace_back(o);
}

void Subject::detach(shared_ptr<Observer> o){
    int pos =0;
    //find the postion of o and then erase o
    for(int i =0;i< observers.size();i++){
        if(observers[i] == o){
            break;
        }
        pos++;
    }
    observers.erase(observers.begin()+pos);
}

void Subject::notifyObservers(SubscriptionType t){
    if(t == SubscriptionType::All){
        for(int i =0; i < observers.size();i++){
            observers[i]->notify(*this);
        }
    }
    else{
        for(int i =0; i < observers.size();i++){
            if (observers[i]->getSubType() == SubscriptionType::displayOnly) {
                observers[i]->notify(*this);
            }
        }
    }
}


