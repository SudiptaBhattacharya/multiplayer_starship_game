#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>

class Button {
    private:
        sf::RectangleShape button;
        sf::Text text;
    public:
        Button();
        Button(std::string text, sf::Vector2f size, int charSize, sf::Color backgroundColor, sf::Color textColor);
        ~Button();
        void setFont(sf::Font &font);
        void setBackgroundColor(sf::Color color);
        void setTextColor(sf::Color color);
        void setPosition(sf::Vector2f position);
        void draw(sf::RenderWindow &window);
        bool isMouseOver(sf::RenderWindow &window);
};


#endif