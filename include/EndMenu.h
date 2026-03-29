#ifndef ENDMENU_H
#define ENDMENU_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Menu.h"
#include "Starship.h"

class EndMenu {
    public:
        EndMenu(float width, float height, Starship &player1, Starship &player2, std::string userName);
        ~EndMenu();
        void createWindow();
        void moveUp();
        void moveDown();
        void recordLeader();
        void renderMenu();
    private:
        int selectItemIndex;
        float width;
        float height;
        sf::RenderWindow* endMenuWindow;
        sf::Font font;
        sf::Text endMenu[2];
        sf::Text displayText[1];
        Starship *player1;
        Starship *player2;
        Menu *menu;
        std::string userName;
};

#endif