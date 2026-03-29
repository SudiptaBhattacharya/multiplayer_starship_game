#include "Button.h"

Button::Button(std::string text, sf::Vector2f size, int charSize, sf::Color backgroundColor, sf::Color textColor) {
    this->text.setString(text);
    this->text.setColor(textColor);
    this->text.setCharacterSize(charSize);

    this->button.setSize(size);
    this->button.setFillColor(backgroundColor);
}

void Button::setFont(sf::Font &font) {
    text.setFont(font);
}

void Button::setBackgroundColor(sf::Color color) {
    button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
    text.setColor(color);
}

void Button::setPosition(sf::Vector2f position){
    button.setPosition(position);

    float xPosition = (position.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
    float yPosition = (position.y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
    text.setPosition({xPosition,yPosition});
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(button);
    window.draw(text);
}

bool Button::isMouseOver(sf::RenderWindow &window) {
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    float buttonX = button.getPosition().x;
    float buttonY = button.getPosition().y;

    float buttonWidth = button.getPosition().x - button.getLocalBounds().width;
    float buttonHeight = button.getPosition().y - button.getLocalBounds().height;
    
    if (mouseX < buttonWidth && mouseX > buttonX && mouseY < buttonHeight && mouseY > buttonY) {
        return true;
    }
    return false;
}