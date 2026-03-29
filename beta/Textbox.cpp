#include "Textbox.h"

Textbox::Textbox(int size, sf::Color color, bool isSelected) {
    textbox.setCharacterSize(size);
    textbox.setFillColor(color);
    this->isSelected = isSelected;
    if (isSelected) {
        textbox.setString("_");
    } else {
        textbox.setString("");
    }
}
void Textbox::setFont(sf::Font &font) {
    textbox.setFont(font);
}

void Textbox::setPosition(sf::Vector2f position) {
    textbox.setPosition(position);
}

void Textbox::setLimit(bool hasLimit) {
    this->hasLimit = hasLimit;
}

void Textbox::setLimit(bool hasLimit, int limit) {
    this->hasLimit = hasLimit;
    this->limit = limit - 1;
}

void Textbox::setSelected(bool isSelected) {
    this->isSelected  = isSelected;
    if (!isSelected) {
        std::string oldText = text.str();
        std::string newText = "";
        for (int i = 0; i < oldText.length(); i++) {
            newText += oldText[i];
        }
        textbox.setString(newText);
    }
}

void Textbox::draw(sf::RenderWindow &window) {
    window.draw(textbox);
}

std::string Textbox::getText() {
    return text.str();
}

void Textbox::typeOn(sf::Event input) {
    if (isSelected) {
        int charTyped = input.text.unicode;
        if (charTyped < 128) {
            if (hasLimit) {
                if (text.str().length() <= limit) {
                    inputLogic(charTyped);
                } else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                    deleteLastChar();
                }
            } else {
                inputLogic(charTyped);
            }
        }
    }
}

void Textbox::inputLogic(int charTyped) {
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        text << static_cast<char>(charTyped);
    } else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }
    textbox.setString(text.str() + "_");
}

void Textbox::deleteLastChar() {
    std::string oldText = text.str();
    std::string newText = "";
    for (int i = 0; i < oldText.length() - 1; i++) {
        newText += oldText[i];
    }
    text.str("");
    text << newText;
    textbox.setString(text.str());
}