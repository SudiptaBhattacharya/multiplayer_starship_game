#ifndef RADIATION_H
#define RADIATION_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "Starship.h"

using namespace sf;

class Radiation{
  private:
    CircleShape* body; // representation of radiation in the window
    float angle;       // angle of projection of the radiation
    float damage;      // damage of the radiation on the player

  public:
    Radiation();
    Radiation(float radius, Color color, Vector2f position, float angle, float damage);
    ~Radiation();

    // render in window
    bool draw(RenderWindow &window);
    // set movement path 
    bool move(float speed, float delta_time);
    // check collisions with starships
    bool checkCollision(Starship* starship);

    // getters and setters
    float get_angle();
    float get_damage();
    CircleShape* get_body();
    bool set_angle(float angle);
    bool set_damage(float damage);
};

#endif