
#include "../include/Star.h"
#include "../include/Radiation.h"
#include "../include/WarpShip.h"

#ifndef STARTEST_H
#define STARTEST_H
class StarTest{
  public:
    // Test constructor and default values
    void testConstructor() {
        std::cout << "Testing default constructor...\n";
        Star defaultStar;
        printStarInfo(defaultStar);
        
        std::cout << "Testing parameterized constructor...\n";
        Star customStar(75, Color::Red, Vector2f(100, 100));
        printStarInfo(customStar);
    }

    // Test destructor to ensure cleanup is done
    void testDestructor() {
        std::cout << "Testing destruction...\n";
        Star* starToDelete = new Star(80, Color::Blue, Vector2f(200, 200));
        printStarInfo(*starToDelete);
        delete starToDelete;
        std::cout << "Star object deleted.\n";
    }

private:
    // Utility function to print the information of the Star object
    void printStarInfo( Star& star) {
        std::cout << "Star Info:\n";
        std::cout << "  Position: (" << star.get_position().x << ", " << star.get_position().y << ")\n";
        std::cout << "  Phase: " << star.get_phase() << "\n";
        std::cout << "  Time Passed (Radiation): " << star.get_timePassedRadiation() << "\n";
        std::cout << "  Time Passed (Phase): " << star.get_timePassedPhase() << "\n";
        std::cout << "  Radiation Counter: " << star.get_radiationCounter() << "\n";
    }
};

    // Test initialisation of the Star
    /*void initialiseStar() {
      star = new Star();
      if (star != new Star()) {
        std::cout << "Star initialisation failed" << std::endl;
      }
    } 

    // Test getters
    void getterTest() {
      std::cout << "Expected x position: 10 Received x position: " << star->get_position().x << std::endl;
      std::cout << "Expected y position: 20 Received x position: " << star->get_position().y << std::endl;
      std::cout << "Expected radiation count: 0 Received radiation count: " << star->get_radiationCounter() << std::endl;
      std::cout << "Expected phase: 1 Received phase: " << star->get_phase() << std::endl;
      std::cout << "Expected time passed: 0 Received time passed: " << star->get_timePassedPhase() << std::endl;
      std::cout << "Expected radiation time passed: 0 Received radiation time passed: " << star->get_timePassedRadiation() << std::endl;
    }

    // Test error messaged
    void errorMessageTest() {
      star->radialRadiation(Color::Yellow, -1);
      star->wallRadiation(Color::Yellow, -1);
      star->randomRadiation(Color::Yellow, -1);
    }
};*/

#endif