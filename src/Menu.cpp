#include "../include/Menu.h"

Menu::Menu(float width, float height, std::string userName) : width(width), height(height), userName(userName) {
    selectItemIndex = 0;
    menuWindow = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Menu");
    if (!font.loadFromFile("./assets/Roboto-Bold.ttf")) {
        // handle errors
        std::cerr << "Failed to load font" << std::endl;
    }

    // Welcome Text initialising
    sf::String welcomeString = "Welcome! Pilot " + this->userName;
    welcomeText[0].setFont(this->font);
    welcomeText[0].setFillColor(sf::Color::White);
    welcomeText[0].setString(welcomeString);
    welcomeText[0].setPosition(sf::Vector2f(20, 20));

    // Start menu initialising
    menu[0].setFont(this->font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("> Start a server");
    menu[0].setPosition(sf::Vector2f(20, height/5*2));

    menu[1].setFont(this->font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("> Connect to server");
    menu[1].setPosition(sf::Vector2f(20, height/5*3));

    menu[2].setFont(this->font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("> Exit");
    menu[2].setPosition(sf::Vector2f(20, height/5*4));

    // Leaderboard Initialising
    for (int i = 0; i < 5; i++) {
        leaderboard[i].setFont(this->font);
        leaderboard[i].setFillColor(sf::Color::White);
        leaderboard[i].setPosition(sf::Vector2f(400, 20+(i+1)*20));
        leaderboard[i].setCharacterSize(10);
    }
    leaderTitle[0].setFont(this->font);
    leaderTitle[0].setFillColor(sf::Color::Yellow);
    leaderTitle[0].setPosition(sf::Vector2f(405, 10));
    leaderTitle[0].setCharacterSize(15);
    leaderTitle[0].setString("Top 5 Pilots");
    loadLeaderboard();

}

Menu::~Menu() {};

void Menu::moveUp() {
    if (selectItemIndex - 1 >= 0) {
        menu[selectItemIndex].setFillColor(sf::Color::White);
        selectItemIndex--;
        menu[selectItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown() {
    if (selectItemIndex + 1 < 3) {
        menu[selectItemIndex].setFillColor(sf::Color::White);
        selectItemIndex++;
        menu[selectItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::loadLeaderboard() {
    // initialize player count and players vector
    int playerCount = 0;
    vector<std::string> players;
    // read from the text file
    ifstream leaderboardFile("./assets/leaderboard.txt");
    // copy into player vector
    std::string text;
    while (getline(leaderboardFile, text)) {
        playerCount++;
        players.push_back(text);
    }
    // initiliase top players vector
    std::vector<std::string> topPlayers;
    topPlayers.push_back(players[0]);
    for (int i = 1; i < playerCount; i++) {
        // initialize player rank
        int rank = topPlayers.size();
        // get player score
        int score = std::stoi(players[i].substr(players[i].find(":") + 1));
        // compare scores
        for (int j = rank - 1; j > -1; j--){
        // get current score
        int currentScore = std::stoi(topPlayers[j].substr(topPlayers[j].find(":") + 1));
        if (score > currentScore) {rank --;}
        }
        // add score into leaderboard
        topPlayers.insert(topPlayers.begin() + rank, players[i]);
    }
    // add players to leaderboard
    for (int i = 0; i < 5; i++){
        leaderboard[i].setString(topPlayers[i]);
    }
}

void Menu::renderMenu() {
    while (menuWindow->isOpen()) {
        sf::Event event;
        while (menuWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                menuWindow->close();
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
                            menuWindow->close();
                            game = new Game("Server", userName);
                            game->run();
                            break;
                        case 1:
                            menuWindow->close();
                            game = new Game("Client", userName);
                            game->run();
                            break;
                        case 2:
                            menuWindow->close(); // Exit the window
                            break;
                    }
                }
            }
        }

        // Clear the window
        menuWindow->clear();

        // Draw the menu items
        menuWindow->draw(leaderTitle[0]);
        menuWindow->draw(welcomeText[0]);
        for (int i = 0; i < 3; ++i) {
            menuWindow->draw(menu[i]);
        }

        // Draw the leaderboard
        for (int i = 0; i < 5; i++) {
            menuWindow->draw(leaderboard[i]);
        }

        // Display the window
        menuWindow->display();
    }
}

