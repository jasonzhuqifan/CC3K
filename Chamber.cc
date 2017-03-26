#include "Chamber.h"

Chamber::Chamber() {
    readMap();
    scanChamber();
}

void Chamber::readMap() {
    ifstream file("cc3kfloor.txt");
    string line;
    while(getline(file, line)){
        vector<char> c_arr;
        for(int i = 0; i < line.length(); ++i){
            c_arr.emplace_back(line[i]);
        }
        textMap.emplace_back(c_arr);
    }
}

void Chamber::scanChamber() {
    int chamId = 0;
    for (int row = 0; row < 79; row++) {
        for (int col = 0; col < 25; col++) {
            if (textMap[row][col] == '.') {
                recursiveAdd(row, col, chamId++);
            }
        }
    }
}

void Chamber::recursiveAdd(int row, int col, int chamId) {
    chamLst[chamId].emplace_back(pair<int, int>(row,col));
    textMap[row][col] = ' ';
    if(textMap[row][col+1] == '.') {
        recursiveAdd(row, col+1, chamId);
    }
    if(textMap[row+1][col] == '.') {
        recursiveAdd(row, col+1, chamId);
    }
}
