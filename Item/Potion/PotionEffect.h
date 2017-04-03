#ifndef PotionEffect_hpp
#define PotionEffect_hpp

#include "Player.h"

class PotionEffect : public Player{
protected:
    std::shared_ptr<Player> pc;
public:
    PotionEffect(std::shared_ptr<Player> pc);
    virtual double getAttack() override;
    virtual double getDefence() override;
    virtual double getHP() override;
    virtual ~PotionEffect() = 0;
    void move(std::string dir) override;
    std::string getRace() override;
    int getGold() override;
    Info getInfo() override;
    void getDamage(double damage) override;
    void attack(std::string dir, std::shared_ptr<Player>pc) override;
    void setHealth(double h) override;
    void update_message(std::string s) override;
    std::string getActionMessage() override;
    void emptyMessage() override;
    std::shared_ptr<Player> getTrue() override;
    bool hasReachedShairs() override;
    bool hasDead() override;
    int goUpstairs() override;
    void memorizePotion(std::string s) override;
    bool knowPotion(std::string s) override;
    int getFloorNum() override;
};


#endif
