#ifndef WARPSHIP_H
#define WARPSHIP_H

#include "Starship.h"

class WarpShip : public Starship {
public:
    WarpShip(string name,float speed, float healthPoints, float radius, Color color, Vector2f position, int specialAbilityCount);
    ~WarpShip();

    void useSpecialAbility(Starship& otherShip)  ; // Generalized parameter
};

#endif // WARPSHIP_H

