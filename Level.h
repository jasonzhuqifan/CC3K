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
    std::shared_ptr<TextDisplay> td;
public:
    virtual std::shared_ptr<Enemy> createEnemy(char *type) = 0;
    virtual std::shared_ptr<Potion> createPotion()=0;
    virtual std::shared_ptr<Cell> createCell(char type) =0;
    virtual void placeEnemy(std::shared_ptr<Character> pc) = 0;
    virtual void placePotion() = 0;
    virtual void placeGold() = 0;
    virtual void placeStair() = 0;
    virtual void placePlayer(std::shared_ptr<Character> pc) = 0;
    virtual void setFrozen() = 0;
    virtual std::shared_ptr<Player> use(std::shared_ptr<Player> pc, std::string dir) = 0;
    virtual ~Level() = default;
   friend std::ostream &operator<<(std::ostream &out, const Level &l);
};

#endif
