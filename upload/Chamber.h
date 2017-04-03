#ifndef Chamber_hpp
#define Chamber_hpp

#include <vector>
#include <fstream>


class Chamber{
    std::vector<std::vector<std::pair<int, int>>> chamLst;
    std::vector<std::vector<char>> textMap;
    void readMap();
    void scanChamber();
    void recursiveAdd(int row, int col, int chamId);
    
public:
    Chamber(); //read Text map and scan chamLst
    std::shared_ptr<std::vector<std::vector<std::pair<int, int>>>> getChamberList();//return vector of Chambers
};

#endif
