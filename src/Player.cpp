#include "../include/Player.h"
#include <iostream>


// Default constructor
Player::Player() : player_name("") {}

// Parameterized constructor
Player::Player(string player_name) : player_name(player_name) {}

// Getter for name
string Player::get_Playername() const {
    return player_name;
}

// Getter for survival time
// float Player::get_survivalTime() const {
//     return survivalTime;
// }



// void Player::set_survivalTime(float survivalTime){
//     this->survivalTime = survivalTime;
// }

// Setter for survival time

