/*#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Starship.h"
#include "WarpShip.h"
#include"SpyShip.h"

class SaveData {
public:
    static void saveGame(const std::vector<Starship*>& starships, const std::string& filename) {
        std::ofstream outFile(filename);
        if (outFile) {
            for (const auto& ship : starships) {
                outFile << ship->get_name() << " " 
                        << ship->get_healthPoints() << " "
                        << ship->get_position().x << " "
                        << ship->get_position().y << "\n";
            }
            outFile.close();
        } else {
            std::cerr << "Error saving game data!" << std::endl;
        }
    }

    static void loadGame(std::vector<Starship*>& starships, const std::string& filename) {
        std::ifstream inFile(filename);
        if (inFile) {
            std::string name;
            float health;
            float posX, posY;
            float speed;
            int r,g,b;
            int specialAbilityCount;
            float radius;
            while (inFile >> name >> health >> posX >> posY>> speed>>radius>>r>>g>>b>>specialAbilityCount) {

                Color color(r,g,b);
                // Assuming you can create starships based on the name
                Starship* player = new WarpShip(name, speed, health, radius, color, Vector2f(posX, posY), specialAbilityCount);
                player->set_healthPoints(health);
                player->set_position(Vector2f(posX, posY));
                starships.push_back(player);
            }
            inFile.close();
        } else {
            std::cerr << "Error loading game data!" << std::endl;
        }
    }
};

#endif // SAVEDATA_H
*/