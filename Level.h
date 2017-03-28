#ifndef Level_hpp
#define Level_hpp


class Character;
class Player;
class Enemy;
class Cell;
class Potion;
class Cell;
class Gold;


struct Level{
    Level();
    virtual Enemy *createEnemy() = 0;
    virtual Potion *createPotion()=0;
    virtual Gold *createGold() =0;
    virtual Cell *createCell(char c) =0;
    virtual void placeEnemy() = 0;
    virtual void placePotion() = 0;
    virtual void placeGold() = 0;
    virtual void placeStair() = 0;
    virtual void placePlayer(Character *pc) = 0;
    virtual void setFrozen() = 0;
    virtual Player* use(Player* pc, std::string dir) = 0;
    virtual ~Level() = 0;
};

#endif
