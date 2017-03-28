#include "Enemy.h"

void Enemy::updateDamage(double damage){
    HP = HP - damage;
    if(HP <= 0){
        notifyObservers(SubscriptionType::displayOnly);
    }
}

void Enemy::notify(Subject &notifier){
    
}
