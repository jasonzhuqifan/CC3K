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
    char tempChar;
    if(notifier.getObjType() == GridObjectType::Player){ //if notifier is player
        if(f.currentCol == f.previousCol && f.currentRow == f.previousRow){
            if(theDisplay[f.currentRow][f.currentCol] != '@'){
                theDisplay[f.currentRow][f.currentCol] = '@';
            }
            HP = f.HP;
            Atk = f.Atk;
            Def = f.Def;
            Message = f.Message;  //如何pass action message不确定
        } else {
        tempChar = theDisplay[f.currentRow][f.currentCol];
        theDisplay[f.currentRow][f.currentCol] = theDisplay[f.previousRow][f.previousCol];
        theDisplay[f.previousRow][f.previousCol] = tempChar;
        }
        
    } else if(notifier.getObjType() == GridObjectType::Enemy){ //if notifier is enemy
         if(f.currentCol != f.previousCol || f.currentRow != f.previousRow){
             tempChar = theDisplay[f.currentRow][f.currentCol];
             theDisplay[f.currentRow][f.currentCol] = theDisplay[f.previousRow][f.previousCol];
             theDisplay[f.previousRow][f.previousCol] = tempChar;
         } else if(theDisplay[f.currentRow][f.currentCol] == '.'){ //initiate enemy
             theDisplay[f.currentRow][f.currentCol] = f.EnemyRace;
         }
    } else if(notifier.getObjType() == GridObjectType::Potion){ //if notifier is potion
        if(theDisplay[f.currentRow][f.currentCol] == '.'){
            theDisplay[f.currentRow][f.currentCol] = 'P';
        } else if(theDisplay[f.currentRow][f.currentCol] == 'P'){
            theDisplay[f.currentRow][f.currentCol] = '.';
        }
    } else if(notifier.getObjType() == GridObjectType::Gold){ //Gold not consider Dragon Hoard yet!
        if(theDisplay[f.currentRow][f.currentCol] == '.'){
            theDisplay[f.currentRow][f.currentCol] = 'G';
        } else if(theDisplay[f.currentRow][f.currentCol] == 'G'){
            theDisplay[f.currentRow][f.currentCol] = '.';
        }
    }
}

