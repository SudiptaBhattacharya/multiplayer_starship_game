#include "../include/WarpShip.h"

WarpShip::WarpShip(string name, float speed, float healthPoints, float radius, Color color, Vector2f position, int specialAbilityCount)
    : Starship(name, speed, healthPoints, radius, color, position, specialAbilityCount){}

WarpShip::~WarpShip() {}

void WarpShip::useSpecialAbility(Starship& otherShip) {
    // Check if there are any remaining special ability uses
    /*if (this->specialAbilityCount > 0) {
        // Store the current position of this WarpShip
        Vector2f currentPosition = this->get_position();
        
        // Set this WarpShip's position to the other ship's position
        this->set_position(otherShip.get_position());
        
        // Set the other ship's position to the saved position of this WarpShip
        otherShip.set_position(currentPosition);
        
        // Decrement the special ability count
        this->specialAbilityCount--;

        std::cout << "Switched positions! Special ability count remaining: " << this->specialAbilityCount << std::endl;
    } else {
        std::cout << "No more special ability uses left!" << std::endl;
    }*/

        cout << "Player1: WarpShip: Keep Going!!" << endl;
}


