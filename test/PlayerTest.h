#ifndef PLAYERTEST_H
#define PLAYERTEST_H



#include <iostream>
#include "../include/Player.h"

class PlayerTest {
public:
    void runTest() {
        testDefaultConstructor();
        testParameterizedConstructor();
    }

private:
    void testDefaultConstructor() {
        Player player;
        if (player.get_Playername().empty()) {
            std::cout << "[PASS] Default constructor works as expected." << std::endl;
        } else {
            std::cout << "[FAIL] Default constructor does not initialize correctly." << std::endl;
        }
    }

    void testParameterizedConstructor() {
        Player player("TestPlayer");
        if (player.get_Playername() == "TestPlayer") {
            std::cout << "[PASS] Parameterized constructor works as expected." << std::endl;
        } else {
            std::cout << "[FAIL] Parameterized constructor does not initialize correctly." << std::endl;
        }
    }
};

#endif // PLAYERTEST_H