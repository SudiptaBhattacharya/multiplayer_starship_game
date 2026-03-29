#include "../include/Game.h"
#include <iostream>
#include <string>
#include "EndMenu.h"


Game::Game() : Game("Server", "John Doe") {}

Game::Game(std::string connectionType, std::string userName) {
    // initialize windows size in pixels
    windowHeight = 500;
    windowWidth = 500;

    // Player initialization
    // Adjusting positions to place players at opposite corners

    // WarpShip for Player1, SpyShip for Player2
    if (connectionType == "Server") {
        // Top-left corner (adjusted)
        player1 = new WarpShip(userName, 10.f, 100.f, 10.f, Color::Green, Vector2f(20.f, 20.f), 1);
        // Bottom-right corner (adjusted)
        player2 = new SpyShip("Enemy", 10.f, 100.f, 10.f, Color::Red, Vector2f(480.f, 480.f), 1);
    } else if (connectionType == "Client") {
        // Top-left corner (adjusted)
        player1 = new WarpShip("Enemy", 10.f, 100.f, 10.f, Color::Green, Vector2f(20.f, 20.f), 1);
        // Bottom-right corner (adjusted)
        player2 = new SpyShip(userName, 10.f, 100.f, 10.f, Color::Red, Vector2f(480.f, 480.f), 1);
    }
    
    // Star initialisation
    star = new Star();
    // Network initialization
    network = new Network();
    std::string Title;
    if (connectionType == "Server") {
        Title = "Server Game";
    } else if (connectionType == "Client") {
        Title = "Client Game";
    }
    this->connectionType = connectionType;
    int port;
    IpAddress ip;
    if (connectionType == "Server") {
        // std::cout << "Please enter the port you want to use: " << std::endl;
        // std::cin >> port;
        network->setServer(2000);
    } else if (connectionType == "Client") {
        // std::cout << "Please enter server IP address: " << std::endl;
        // std::cin >> ip;
        //network->setClient(2000, IpAddress("10.13.70.93"));
        network->setClient(2000, IpAddress("127.0.0.1"));
    }

    // Window initialization
    window = new RenderWindow(VideoMode(windowWidth, windowHeight), Title); // Window size and title based on the connection type
    window->setFramerateLimit(60);
    isWindowFocused = true;
  
    // Map initialisation
    if (!texture1.loadFromFile("./assets/black.png")) {
        std::cerr << "Error loading texture1" << std::endl;
    } else {
        std::cout << "Texture1 loaded successfully" << std::endl;
    }
    sf::Vector2u textureSize = texture1.getSize();
    std::cout << "Texture1 size: " << textureSize.x << "x" << textureSize.y << std::endl;

    if (!texture2.loadFromFile("./assets/star.png")) {
        std::cerr << "Error loading texture2" << std::endl;
    }else {
        cout<< "Texture2 loaded succesfully" << endl;
    }
    Vector2u textureSize2 = texture2.getSize();
    cout << "Texture2 size: " << textureSize2.x << "x" << textureSize2.y << endl;

    gameMap = new Map(10, 10, 50, texture1, texture2);
    gameMap->setTile(2, 3, 2);
    gameMap->setTile(7, 6, 2);
    gameMap->setTile(5, 2, 2);
    gameMap->setTile(2, 7, 2);
    
    // Font loading
    if (!font.loadFromFile("./assets/Roboto-Bold.ttf")) {
        std::cerr << "Failed loading font" << std::endl;
    }

    // Stats Display Initialising 
    player1Text.setFont(font);
    player1Text.setCharacterSize(9);
    player1Text.setFillColor(sf::Color::White);
    player1Text.setPosition(0, 10); // Positioning text for player 1

    player2Text.setFont(font);
    player2Text.setCharacterSize(9);
    player2Text.setFillColor(sf::Color::White);
    player2Text.setPosition(0, 25); // Positioning text for player 2

    // End Menu Initialisation
    endMenu = new EndMenu(500,500, *player1, *player2, userName);

}

Game::~Game() {
    delete window;
    delete network;
    delete player1;
    delete player2;
}

void Game::winCheck() {
    // check if players are dead or not
    if (player1->get_healthPoints() == 0 || player2->get_healthPoints() == 0) {
        // if either one player dead
        // delete network
        network->disconnect();
        // stop the game
        window->close();
        // create end menu
        endMenu->createWindow();
        // call end menu
        endMenu->renderMenu();
        
    }
    // } else if (player1->get_healthPoints() == 0 && player2->get_healthPoints() != 0) {
    //     // if only player 1 dead
    //     p1EndTime = std::clock();
    // } else if (player1->get_healthPoints() != 0 && player2->get_healthPoints() == 0) {
    //     // if only player 2 is dead
    // }
    
    
}

void Game::run() {
    Clock clock;
    while (window->isOpen()) {
        handleEvents();
        deltaTime = clock.restart().asSeconds(); // debugging delta time
        updateLocation();
        render();
        winCheck();
    }
    network->disconnect();
}

void Game::handleEvents() {
    Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::GainedFocus) {
            isWindowFocused = true;
        } else if (event.type == sf::Event::LostFocus) {
            isWindowFocused = false;
        }

    }
}

void Game::updateLocation() {
    if (connectionType == "Server") {
        Vector2f prevPosition = player1->get_position();
        player1->inputHandle(50.0, deltaTime, isWindowFocused, windowHeight, windowWidth);

        // send changes
        if (prevPosition != player1->get_position()) {
            network->sendPosition(player1->get_position());
        }
      
        //Receive positon
        Vector2f otherPosition;
        if (network->receivePosition(otherPosition)) {
            player2->set_position(otherPosition);
        }
 
        
    } else if (connectionType == "Client") {

        // send location
        //record current position to check position changes later
        Vector2f prevPosition = player2->get_position();
        // Get input
        player2->inputHandle(50.0, deltaTime, isWindowFocused, windowHeight, windowWidth);
        // Send changes
        if (prevPosition != player2->get_position()) {
            network->sendPosition(player2->get_position());
        }

        // Recieve location
        Vector2f otherPosition;
        if (network->receivePosition(otherPosition)) {
            player1->set_position(otherPosition);
        }

    } 
    
    
}

void Game::render() {
    window->clear(Color::Black); // clear with black to differentiate from white
    gameMap->draw(*window); // draw the Map

    //Draw players
    player1->draw(*window);
    player2->draw(*window);

    // Draw star and radiation
    spawnEnemy();

    //Update and draw text
    updateText();
    window->draw(player1Text);
    window->draw(player2Text);

    window->display();
    
}

// emit radiation and check collisions between radiation and player
void Game::spawnEnemy(){
    star->draw(*window);
    star->radiate(deltaTime, *window);
    star->checkCollisions(player1);
    star->checkCollisions(player2);
}
//Update Text Method
void Game::updateText(){
    // Update text
    player1Text.setString("Player 1: " + player1->get_Playername() + " | HP: " + std::to_string(static_cast<int>(player1->get_healthPoints())));
    player2Text.setString("Player 2: " + player2->get_Playername() + " | HP: " + std::to_string(static_cast<int>(player2->get_healthPoints())));
}