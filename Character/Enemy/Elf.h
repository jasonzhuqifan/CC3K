

#ifndef Elf_hpp
#define Elf_hpp

#include "Enemy.h"

class Elf : public Enemy{
public:
    Elf();
    void attack(Goblin* pc) override;
    void attack(Shade* pc) override;
    void attack(Troll* pc) override;
    void attack(Vampire* pc) override;
    ~Elf();
};

#endif /* Elf_hpp */
