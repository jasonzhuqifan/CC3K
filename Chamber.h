#ifndef Chamber_hpp
#define Chamber_hpp

#include <vector>
#include <fstream>

using namespace std;

class Chamber{
    vector<vector<pair<int, int>>> chamLst;
    vector<vector<char>> textMap;
    void readMap();
    void scanChamber();
    void recursiveAdd(int row, int col, int chamId);
    
public:
    Chamber(); //read Text map and scan chamLst
    vector<vector<pair<int, int>>> getChamberList(); //return vector of Chambers
};

#endif
