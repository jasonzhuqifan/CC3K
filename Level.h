#ifndef Level_hpp
#define Level_hpp

#include <iostream>
class Character;
class Player;
class Enemy;
class Cell;
class Potion;
class Cell;
class Gold;
class Floor;
class TextDisplay;

class Level{
protected:
    TextDisplay *td;
public:
    Level();
    virtual Enemy *createEnemy(char *type) = 0;
    virtual Potion *createPotion()=0;
    virtual Cell *createCell(char c) =0;
    virtual void placeEnemy(Character *pc) = 0;
    virtual void placePotion() = 0;
    virtual void placeGold() = 0;
    virtual void placeStair() = 0;
    virtual void placePlayer(Character *pc) = 0;
    virtual void setFrozen() = 0;
    virtual Player* use(Player* pc, std::string dir) = 0;
    virtual ~Level() = 0;
    friend std::ostream &operator<<(std::ostream &out, const Level &l);
};

#endif
