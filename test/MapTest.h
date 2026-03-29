#include "../include/Map.h"
#include <iostream>
#ifndef MAPTEST_H
#define MAPTEST_H

class MapTest {
public:
    void runTest() {
        loadTexture();
        initialisingMap();
        setTileTest();
    }

    // Destructor to clean up allocated memory
    ~MapTest() {
        delete map; // Free the allocated Map object
    }

private:
    Map* map; // Pointer to dynamically allocated Map
    sf::Texture texture1;
    sf::Texture texture2;

    void loadTexture() {
        if (!texture1.loadFromFile("./assets/black.png")) {
            std::cerr << "Failed loading texture 1" << std::endl;
        }
        if (!texture2.loadFromFile("./assets/star.png")) {
            std::cerr << "Failed loading texture 2" << std::endl;
        }
    }

    void initialisingMap() {
        map = new Map(10, 10, 50, texture1, texture2);
        if (map != new Map(10, 10, 50, texture1, texture2)) {
            std::cerr << "Failed initialising map" << std::endl;
        }
    }

    void setTileTest() {
        map->setTile(1, 1, 2);
    }
};

#endif