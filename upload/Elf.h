

#ifndef Elf_hpp
#define Elf_hpp

#include "Enemy.h"

class Elf : public Enemy{
public:
    Elf();
    void attack(std::shared_ptr<Goblin> pc, double true_def) override;
    void attack(std::shared_ptr<Shade> pc, double true_def) override;
    void attack(std::shared_ptr<Troll> pc, double true_def) override;
    void attack(std::shared_ptr<Vampire> pc, double true_def) override;
    ~Elf();
};

#endif /* Elf_hpp */
