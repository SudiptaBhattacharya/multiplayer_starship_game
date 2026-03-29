#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
    public:
        Textbox();
        Textbox(int size, sf::Color color, bool isSelected);
        ~Textbox();
        void setFont(sf::Font &font);
        void setPosition(sf::Vector2f position);
        void setLimit(bool hasLimit);
        void setLimit(bool hasLimit, int limit);
        void setSelected(bool isSelected);
        void draw(sf::RenderWindow &window);
        std::string getText();
        void typeOn(sf::Event input);
    private:
        sf::Text textbox;
        std::ostringstream text;
        bool isSelected = false;
        bool hasLimit = false;
        int limit;
        void inputLogic(int charTyped);
        void deleteLastChar();
};


#endif