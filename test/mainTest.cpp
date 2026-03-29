#include"../test/PlayerTest.h"
#include"../test/ShipTest.h"

#include "../test/StarTest.h"
#include "../test/RadiationTest.h"

#include"../test/MapTest.h"




    /*Since Starship is an abstract class, we cannot instantiate objects from that class, hence we tested the constructor 
    initialization of Health Points and Printed a Text message saying which indicates the success of implementation of 
    usespecialAbility( ) function in both WarpShip and SpyShip
    As WarpShip and SpyShip both inherit from Starship , if we can write unit tests for those, then we can say the test for Starship works as expected */
   int main() {
    /*std::cout << "Running Network Tests..." << std::endl;
    NetworkTest networkTest;
    networkTest.runTest();*/
    printf("\n");

    std::cout << "Running Map Tests..." << std::endl;
    MapTest mapTest;
    mapTest.runTest();
    printf("\n");

    std::cout << "Running Player Tests..." << std::endl;
    PlayerTest playerTest;
    playerTest.runTest();
  printf("\n");
    std::cout << "Running Radiation Tests..." << std::endl;
    // Run the default constructor test
    if (!RadiationTest::testDefaultConstructor()) {
        std::cout << "Default constructor test failed." << std::endl;
    }

    // Run the parameterized constructor test with some sample values
    if (!RadiationTest::testParameterizedConstructor(10, sf::Color::Red, sf::Vector2f(100, 100), 45, 50)) {
        std::cout << "Parameterized constructor test failed." << std::endl;
    }

  printf("\n");
  // Create the test suite
    ShipTest shipTest;

    // Add tests for WarpShip and SpyShip constructors
    shipTest.addTest("WarpShip Constructor Test", [&]() {
        shipTest.testWarpShipConstructor();
        
    });
    
  printf("\n");
    shipTest.addTest("SpyShip Constructor Test", [&]() {
        shipTest.testSpyShipConstructor();
    });

    // Run all the tests
    std::cout << "Running Ship Tests:" << std::endl;
    shipTest.runTests();

    printf("\n");
    std::cout << "Running Star Tests..." << std::endl;
    
    
    
    
    StarTest starTest;

    // Test constructor behavior
    starTest.testConstructor();
  printf("\n");
    // Test destructor behavior
    starTest.testDestructor();
  printf("\n");
    std::cout << "All tests completed.\n";

   

    return 0;
}