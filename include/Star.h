#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>
#include "Radiation.h"
#include "Starship.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace sf;

class Star{
  private:
    CircleShape* body;            // representation of the Star in the window
    Vector2f position;            // position of Star
    Radiation** radiation;        // radiation spawned from Star
    int radiation_counter;        // number of radiation spawned
    int phase;                    // current phase of Star
    float time_passed_radiation;  // time in seconds between radiation spawns
    float time_passed_phase;      // total game time in seconds 

  public:
    Star();
    Star(float radius, Color color, Vector2f position);
    ~Star();

    // renders the Star in the window
    bool draw(RenderWindow &window);
    // spawn radiation
    bool radiate(float delta_time, RenderWindow &window);
    // create pattern of radiation
    bool radialRadiation(Color color, float damage);
    bool wallRadiation(Color color, float damage);
    bool randomRadiation(Color color, float damage);
    // check collisions with Starship
    bool checkCollisions(Starship* starship);

    // getters
    CircleShape* get_body();
    Vector2f get_position();
    int get_radiationCounter();
    int get_phase();
    float get_timePassedRadiation();
    float get_timePassedPhase();
};

#endif



