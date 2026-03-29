// SpyShip.cpp
#include "../include/SpyShip.h" // Adjust the path based on your structure


SpyShip::SpyShip(string name, float speed, float healthPoints, float radius, sf::Color color, sf::Vector2f position, int specialAbilityCount)
    : Starship(name, speed, healthPoints, radius, color, position, specialAbilityCount) {}

SpyShip::SpyShip() {}

void SpyShip::useSpecialAbility(Starship& warpShip) {
    /*if (specialAbilityCount > 0) {
        float stolenHP = warpShip.get_healthPoints() * 0.3f; // Steals 30% of warpShip's HP
        this->healthPoints += stolenHP;
        warpShip.reduceHealth(stolenHP);
        specialAbilityCount--;
    }*/
    cout<< "Player2 SpyShip: Come on! You can win this!" << endl;
}







