#ifndef SPYSHIP_H
#define SPYSHIP_H

#include "Starship.h"

class SpyShip : public Starship {
public:
    SpyShip(string name, float speed, float healthPoints, float radius, Color color, Vector2f position, int specialAbilityCount);
    SpyShip();
    
    void useSpecialAbility(Starship& warpShip) ;  // Generalized parameter

    void reduceHealth(float amount);
};

#endif // SPYSHIP_H
