

#ifndef Elf_hpp
#define Elf_hpp

#include "Enemy.h"

class Elf : public Enemy{
    void attack(Drow* pc) override;
    void attack(Goblin* pc) override;
    void attack(Shade* pc) override;
    void attack(Troll* pc) override;
    void attack(Vampire* pc) override;
};

#endif /* Elf_hpp */
