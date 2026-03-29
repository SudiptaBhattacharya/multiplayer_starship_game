
#include "../include/Radiation.h"
#include "../include/WarpShip.h"

#ifndef RADIATIONTEST_H
#define RADIATIONTEST_H
class RadiationTest{
  public:
    //void runTest() {
      //initialiseRadiation();
      //setterAndGetterTest();
      //moveTest();
      // Test the default constructor
    static bool testDefaultConstructor();

    // Test the parameterized constructor
    static bool testParameterizedConstructor(float radius, sf::Color color, sf::Vector2f position, float angle, float damage);
      
    };

  bool RadiationTest::testDefaultConstructor(){
    Radiation radiation;
    // Check if default values match expectations
    if (radiation.get_damage() != 20 || radiation.get_angle() != 0) {
        std::cout << "Error: Default constructor failed. Expected damage: 20, angle: 0. "
                  << "Got damage: " << radiation.get_damage() 
                  << ", angle: " << radiation.get_angle() << std::endl;
        return false;
    }

    // Check if body is correctly initialized
    if (radiation.get_body() == nullptr) {
        std::cout << "Error: Default constructor failed. CircleShape body is not initialized." << std::endl;
        return false;
    }

    std::cout << "Default constructor test passed." << std::endl;
    return true;
}
  
  bool RadiationTest::testParameterizedConstructor(float radius, sf::Color color, sf::Vector2f position, float angle, float damage) {
    Radiation radiation(radius, color, position, angle, damage);
    
    // Check if the values are set correctly
    if (radiation.get_damage() != damage || radiation.get_angle() != (angle * 3.14159 / 180)) {
        std::cout << "Error: Parameterized constructor failed. Expected damage: " << damage 
                  << ", angle: " << (angle * 3.14159 / 180) 
                  << ". Got damage: " << radiation.get_damage() 
                  << ", angle: " << radiation.get_angle() << std::endl;
        return false;
    }

    // Check if body is correctly initialized
    if (radiation.get_body() == nullptr) {
        std::cout << "Error: Parameterized constructor failed. CircleShape body is not initialized." << std::endl;
        return false;
    }

    std::cout << "Parameterized constructor test passed." << std::endl;
    return true;
}
  /*private:
    Radiation* radiation;

    // Test initialisation of radiation
    void initialiseRadiation() {
      radiation = new Radiation();
      if (radiation != new Radiation()) {
        std::cout << "Radiation initialisation failed" << std::endl;
      }
    } */

    /* Test angle and damage setters and getters
    void setterAndGetterTest() {
      float angles[3] = {90, -40, 360};
      float damages[3] = {10, -20, 0};

      for (int i = 0; i < 3; i++) {
        radiation->set_angle(angles[i]);
        radiation->set_damage(damages[i]);

        std::cout << "Expected angle: " << angles[i] << " Received angle: " << radiation->get_angle() << std::endl;
        std::cout << "Expected damage: " << damages[i] << " Received damage: " << radiation->get_damage() << std::endl;
      }
    }

    // Test the radiation move
    void moveTest() {
      float speeds[3] = {10, -20, 0};
      float delta_times[3] = {10, -20, 0};
      for (int i = 0; i < 3; i++) {
          // Reset position
          radiation->get_body()->setPosition(Vector2f(0,0));
          float x = speeds[i] * delta_times[i] * std::cos(radiation->get_angle());
          float y = speeds[i] * delta_times[i] * std::sin(radiation->get_angle());
          radiation->move(speeds[i], delta_times[i]);
          std::cout << "Expected position: (" << x << ", " << y << ") Received position: (" << radiation->get_body()->getPosition().x << ", " << radiation->get_body()->getPosition().y << ")" << std::endl; 
      }
    }

    // Test collisions with the player
    void collisionTest() {
      Starship* starship1 = new WarpShip("test", 10, 10, 10, Color::Red, Vector2f(25, 25), 10);
      Starship* starship2 = new WarpShip("test", 10, 10, 10, Color::Red, Vector2f(50, 50), 10);
      radiation->get_body()->setPosition(Vector2f(50, 50));
      if (radiation->checkCollision(starship1)) {
        std::cout << "Collided with starship1" << std::endl;
      }
      if (radiation->checkCollision(starship2)) {
        std::cout << "Collided with starship2" << std::endl;
      }
    }*/ 


#endif