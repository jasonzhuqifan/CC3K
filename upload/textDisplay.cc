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

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::getSubType() const{
    return SubscriptionType::displayOnly;
}

void TextDisplay::notify(Subject &notifier){
    struct Info f = notifier.getInfo();
    GridObjectType type = f.GOT;
    int cc = f.currentCol;
    int cr = f.currentRow;
    int pc = f.previousCol;
    int pr = f.previousRow;
    char tempChar;
    if(type == GridObjectType::Player){ //if notifier is player
        if(cc != pc || cr != pr){
        tempChar = theDisplay[cr][cc];
        theDisplay[cr][cc] = theDisplay[pr][pc];
        theDisplay[pr][pc] = tempChar;
        }
    } else if(type == GridObjectType::Enemy){ //if notifier is enemy
         if(cc != pc || cr != pr){ 
             tempChar = theDisplay[cr][cc];
             theDisplay[cr][cc] = theDisplay[pr][pc];
             theDisplay[pr][pc] = tempChar;
         } else {
             theDisplay[cr][pr] = '.';       //enemy is dead
         }
    } else if(type == GridObjectType::BA ||
              type == GridObjectType::BD ||
              type == GridObjectType::PH ||
              type == GridObjectType::WD ||
              type == GridObjectType::WA ||
              type == GridObjectType::RH){ //if notifier is potion
        theDisplay[cr][cc] = '.';
    } else if(type == GridObjectType::smallGold ||
              type == GridObjectType::normalGold ||
              type == GridObjectType::merchantHoard ||
              type == GridObjectType::dragonHoard){ //Gold not consider Dragon Hoard yet!
        if(theDisplay[cr][cc] == 'G'){
            theDisplay[cr][cc] = '.';
        } else{
            theDisplay[cr][cc] = 'G';
        }
    } else if(type == GridObjectType::Door){
        theDisplay[cr][cc] = '+';
    } else if(type == GridObjectType::Passage){
        theDisplay[cr][cc] = '#';
    } else if(type == GridObjectType::FloorTiles){
        theDisplay[cr][cc] = '.';
    }
}

void TextDisplay::spawn(int x, int y, char type){
    theDisplay[y][x] = type;
}

ostream &operator<<(ostream &out, const TextDisplay &td){
    for(int i = 0; i < 25; ++i){
        for(int j = 0; j < 79; ++j){
            out << td.theDisplay[i][j];
        }
        out << endl;
    }
    return out;
}
