#include "textDisplay.h"
#include "Info.h"
#include "iostream"
#include "fstream"

using namespace std;

TextDisplay::TextDisplay(){
    ifstream file("cc3kfloor.txt");
    string line;
    while(getline(file, line)){
        vector<char> c_arr;
        for(int i = 0; i < line.length(); ++i){
            c_arr.emplace_back(line[i]);
        }
        theDisplay.emplace_back(c_arr);
    }
    
}

TextDisplay::~TextDisplay(){
    
}

SubscriptionType TextDisplay::getSubType() const{
    return SubscriptionType::displayOnly;
}

void TextDisplay::notify(Subject &notifier){
    struct Info f = notifier.getInfo();
    if(notifier.getObjType() == GridObjectType::Player){
        
    } else if(notifier.getObjType() == GridObjectType::Enemy){
        
    } else if(notifier.getObjType() == GridObjectType::Potion){
        
    } else if(notifier.getObjType() == GridObjectType::StairWay){
        
    } else if(notifier.getObjType() == GridObjectType::Gold){
        
    }
}

