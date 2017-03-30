

#ifndef Elf_hpp
#define Elf_hpp

#include "Enemy.h"

class Elf : public Enemy{
public:
    Elf();
    void attack(std::shared_ptr<Goblin> pc) override;
    void attack(std::shared_ptr<Shade> pc) override;
    void attack(std::shared_ptr<Troll> pc) override;
    void attack(std::shared_ptr<Vampire> pc) override;
    ~Elf();
};

#endif /* Elf_hpp */
