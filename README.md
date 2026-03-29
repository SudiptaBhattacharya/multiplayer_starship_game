# oop_project
Project for Object Oriented Programming

# 🚀 Multiplayer Starship Game

## 👥 Contributors
This project was originally developed as a group project at the University of Adelaide.

Team members:
- Sudipta(ME)
- Martin
- Nesh

This repository represents my personal version for portfolio purposes.

## 📌 Overview
A real-time multiplayer starship game built using C++ and SFML, featuring client-server networking and interactive gameplay mechanics.

## 🎮 Features
- Real-time multiplayer gameplay (server-client architecture)
- Cross-device connection via IP address
- Interactive controls (W/A/S/D movement)
- Dynamic radiation attack patterns (vertical, radial, random)
- Health system with collision detection
- Leaderboard and end-game result display

## 🛠️ Tech Stack
- Language: C++
- Graphics: SFML
- Concepts: OOP, Networking, Event-driven programming

## 🧠 Architecture
- Modular class design:
  - `Game` – core game loop and logic
  - `Starship` – abstract base class (WarpShip, SpyShip)
  - `Radiation` – attack system
  - `Network` – server-client communication
  - `Menu / UI` – interaction and navigation

**#Instructions after compiling on the terminal with "./build/game"**:

**Input and Control**
The user primarily interacts with the program through an intuitive menu system. Users 
navigate the menu using the up and down arrow keys and the ENTER key to select.
The first screen will have ‘Start Server, ‘Connect to Server’, and ‘Exit’ buttons.  It will also Show a text displayed "Pilot: PlayerName". The Player is asked to input their name on the server, and the client player will be automatically named to "Enemy". Also at the top right corner of the Start Menu, there will be a
leaderboard consisting of top 5 Player Highscores, where scores are taken as the number of wins. 

If they choose "Start server", they will be assigned as player1. Once the game starts, radiation will start emitting from the star, the player has to try dodging the radiation streams. 

If they choose "Connect to server",they will play as client and connect to the server as player2. Some test messages will be displayed, showing the game window is correctly rendered, like "Texture_ loaded successfully" or generate an error message if it fails to load any file. 

The game will start once connection is established and if both players are on the same server. The players can play on different PCs as long as they enter the correct address.

The same Game Logistics apply for both the Server and Client Game. The players will use the "W A S D" Keyboard Keys to move their repective players and the players' data will be displayed at the top left of the window screen, including Starship type(WarpShip/ SpyShip), healthPoints:  .
The health Points is initialized to 100 for both players at the start. The healthPoints will reduce by different amounts according to the different types of radiation attacks(like vertical, radial, random). If the players collide with the radiation , their healthPoints will reduce by 10 for the 1st type of attack,  but it will not go negative for all the different types of radiation attacks. Once healthPoints goes to 0 or even negative, Game will End. 


**Note** 
If either player collides with the star, thei Hp will immediately go down to 0, and the endMenu screen will be displayed, ultimately that player will lose the game. Nothing happens if both players collide with each other.

**Result** 
The moment a player's HP reduces to 0, they will lose the game. The End Menu Screen will show both player's data and whoever dies first will lose the game. 
The end screen will Also have an "Quit " and "Exit" option for players to quit the game. 
When one player dies,i.e their healthPoints become 0 or goes below 0, the game ends. .
If a player collides with the star, then Game also ends, with the opposition player getting the Win. 
