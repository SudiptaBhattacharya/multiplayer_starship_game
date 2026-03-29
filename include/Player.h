#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

class Player {
    public:
        Player();
        Player(string player_name);
        string get_Playername()const;
        // float get_survivalTime()const;
        // void set_survivalTime (float survivalTime);
        
    protected:
        // float survivalTime;
        string player_name;
};

#endif