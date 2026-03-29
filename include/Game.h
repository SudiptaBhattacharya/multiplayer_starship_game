#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include "Player.h"
#include "Network.h"
#include "Map.h"
#include "WarpShip.h"
#include "SpyShip.h"
#include "Starship.h"
#include "Radiation.h"
#include "Star.h"

// #include "EndMenu.h"
using namespace sf;

// Forward declaration of EndMenu
class EndMenu;

class Game {
    public:
        Game();
        Game(std::string connectionType, std::string userName);
        ~Game();
        void winCheck();
        void run();
        void handleEvents();
        void updateLocation();
        void render();
        void spawnEnemy();
        

    private:
        RenderWindow* window;
        Map* gameMap;
        Network* network;
        Starship* player1; // polymorphic pointers to handle different starship types
        Starship* player2;
        Star* star;
        EndMenu* endMenu;
        Texture texture1;
        Texture texture2;
        bool isWindowFocused;
        std::string connectionType;
        float secondPassed;
        float deltaTime;
        Clock clock;
        Font font;
        Text player1Text;
        Text player2Text;
        void updateText();
        // window size in pixels for window initialization and boundary checking
        float windowHeight;
        float windowWidth;
};

#endif