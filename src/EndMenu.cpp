#include "../include/EndMenu.h"

EndMenu::EndMenu(float width, float height, Starship &player1, Starship &player2, std::string userName) : width(width), height(height), userName(userName) {
    selectItemIndex = 0;
    
    // Set Player pointer
    this->player1 = &player1;
    this->player2 = &player2;

    if (!font.loadFromFile("./assets/Roboto-Bold.ttf")) {
        // handle errors
    }

    // Display text initialising
    displayText[0].setFont(this->font);
    displayText[0].setFillColor(sf::Color::Blue);
    displayText[0].setPosition(sf::Vector2f(width/3, height/4*1));
    displayText[0].setCharacterSize(40);

    // End menu initialising
    endMenu[0].setFont(this->font);
    endMenu[0].setFillColor(sf::Color::Red);
    // endMenu[0].setString("Restart");
    endMenu[0].setString("Quit");
    endMenu[0].setPosition(sf::Vector2f(width/2, height/4*2));

    endMenu[1].setFont(this->font);
    endMenu[1].setFillColor(sf::Color::White);
    endMenu[1].setString("Exit");
    endMenu[1].setPosition(sf::Vector2f(width/2, height/4*3));

}

EndMenu::~EndMenu() {
}

void EndMenu::createWindow() {
    endMenuWindow = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "End Menu");

    // Initialising display text
    sf::String string1;

    // Check which player wins
    if (player1->get_healthPoints() == 0 && player2->get_healthPoints() != 0) {
        string1 = "Player 2 wins!";
        if (userName == player2->get_Playername()){
            recordLeader();
        }
    } else if (player2->get_healthPoints() == 0 && player1->get_healthPoints() != 0) {
        string1 = "Player 1 wins!";
        if (userName == player1->get_Playername()){
            recordLeader();
        }
    } else if (player1->get_healthPoints() == 0 && player2->get_healthPoints() == 0) {
        string1 = "Draw!";
    }
    // Set text on display text
    displayText[0].setString(string1);
}

void EndMenu::moveUp() {
    if (selectItemIndex - 1 >= 0) {
        endMenu[selectItemIndex].setFillColor(sf::Color::White);
        selectItemIndex--;
        endMenu[selectItemIndex].setFillColor(sf::Color::Red);
    }
}

void EndMenu::moveDown() {
    if (selectItemIndex + 1 < 3) {
        endMenu[selectItemIndex].setFillColor(sf::Color::White);
        selectItemIndex++;
        endMenu[selectItemIndex].setFillColor(sf::Color::Red);
    }
}

void EndMenu::recordLeader() {

    bool returningPlayer = false;
    std::vector<std::string> players;
    std::vector<std::string> newPlayers;
    // read file
    ifstream leaderboardFile("./assets/leaderboard.txt");
    // copy into player vector
    std::string text;
    while (getline(leaderboardFile, text)) {
        players.push_back(text);
    }

    for (int i = 0; i < players.size(); i++) {
        // get player info
        std::string name = players[i].substr(0, players[i].find(":"));
        int score = std::stoi(players[i].substr(players[i].find(":") + 1));
        // add score if same player
        if (name == userName) {
            score++;
            returningPlayer = true;
          }

        // add players to newPlayers
        newPlayers.push_back(name + ":" + std::to_string(score));
    }

    // add new players to newPlayers
    if (!returningPlayer) {
        newPlayers.push_back(userName + ":1");
    }
    
    // open text file
    ofstream leaderFile("./assets/leaderboard.txt");

    // copy names into file
    for (int i = 0; i < newPlayers.size(); i++) {
        leaderFile << newPlayers[i];
        leaderFile << "\r\n";
    }

    // close the file
    leaderFile.close();
}

void EndMenu::renderMenu() {
    while (endMenuWindow->isOpen()) {
        sf::Event event;
        while (endMenuWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                endMenuWindow->close();
            }

            // Handle keypresses
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    moveUp();
                } else if (event.key.code == sf::Keyboard::Down) {
                    moveDown();
                } else if (event.key.code == sf::Keyboard::Enter) {
                    switch (selectItemIndex) {
                        case 0:
                            endMenuWindow->close();
                            // menu = new Menu(500,500,userName);
                            // menu->renderMenu();
                            break;
                        case 1:
                            endMenuWindow->close();
                            break;
                    }
                }
            }
        }

        // Clear the window
        endMenuWindow->clear();

        // Draw the display text for survival times
        endMenuWindow->draw(displayText[0]);

        // Draw the menu items
        for (int i = 0; i < 2; ++i) {
            endMenuWindow->draw(endMenu[i]);
        }

        // Display the window
        endMenuWindow->display();
    }
}