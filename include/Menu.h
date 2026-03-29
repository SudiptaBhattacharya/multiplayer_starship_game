#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Menu {
    public:
        Menu(float width, float height, std::string userName);
        ~Menu();
        void moveUp();
        void moveDown();
        void renderMenu();
        void loadLeaderboard();
        // void renderPlayMenu();
        // void renderOptionMenu();
        // bool isMouseOver(const sf::RectangleShape& box, const sf::Vector2i& mousePos);

    private:
        std::string userName;
        int selectItemIndex;
        float width;
        float height;
        sf::RenderWindow* menuWindow;
        Game* game;
        sf::Font font;
        sf::Text menu[3];
        sf::Text welcomeText[1];
        sf::Text leaderboard[5];
        sf::Text leaderTitle[1];

};

#endif