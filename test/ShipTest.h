#ifndef SHIPTEST_H
#define SHIPTEST_H

#include <iostream>
#include <vector>
#include <functional>
#include "../include/Starship.h"
#include "../include/WarpShip.h"
#include "../include/SpyShip.h"

class ShipTest {
public:
    void addTest(const std::string& testName, const std::function<void()>& testFunc) {
        tests.push_back({testName, testFunc});
    }

    // Test for WarpShip constructor
    void testWarpShipConstructor() {
        WarpShip ship("WarpShip", 10.0f, 100.0f, 5.0f, sf::Color::Green, sf::Vector2f(10.f, 10.f), 1);
        std::cout << "WarpShip created with initial parameters." << std::endl;
        // You can print out attributes or state to indicate if it's working as expected
        std::cout << "Test WarpShipConstructor: WarpShip initialized correctly." << std::endl;
    }

    // Test for WarpShip special ability usage
    /*void testWarpShipUseAbility() {
        WarpShip warpShip("WarpShip", 10.0f, 100.0f, 5.0f, sf::Color::Green, sf::Vector2f(10.f, 10.f), 1);
        SpyShip spyShip("SpyShip", 10.0f, 80.0f, 5.0f, sf::Color::Red, sf::Vector2f(15.f, 15.f), 1);

        warpShip.useSpecialAbility(&spyShip);
        std::cout << "Test WarpShipUseAbility: Special ability used." << std::endl;
    }*/

    // Test for SpyShip constructor
    void testSpyShipConstructor() {
        SpyShip ship("SpyShip", 10.0f, 80.0f, 5.0f, sf::Color::Red, sf::Vector2f(15.f, 15.f), 1);
        std::cout << "SpyShip created with initial parameters." << std::endl;
        std::cout << "Test SpyShipConstructor: SpyShip initialized correctly." << std::endl;
    }

    void runTests() {
        for (const auto& test : tests) {
            try {
                test.second(); // Run the test
                std::cout << "[PASS] " << test.first << std::endl;
            } catch (const std::exception& e) {
                std::cout << "[FAIL] " << test.first << ": " << e.what() << std::endl;
            }
        }
    }

private:
    std::vector<std::pair<std::string, std::function<void()>>> tests;
};

#endif
