#ifndef STARSHIP_H
#define STARSHIP_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "Player.h"

using namespace sf;

class Starship: public Player {

    protected:
    float speed;
    float healthPoints;
    CircleShape* ship;
    int specialAbilityCount;
    Vector2f position;
    Color color;
    float radius;
    string name;
    
    
    public:
    Starship(string name,float speed, float healthPoints, float radius, Color color, Vector2f position, int specialAbilityCount);

    Starship();
    virtual ~Starship();

    
    void reduceHealth(float amount);
    

    bool moveLeft(float speed,float deltaTime);
    bool moveRight(float speed,float deltaTime);
    bool moveUp(float speed,float deltaTime);
    bool moveDown(float speed,float deltaTime);
    void inputHandle(float speed, float deltaTime, bool isWindowFocused, float windowHeight, float windowWidth);

    Vector2f get_position()const;
    bool set_position(Vector2f position);

    float get_healthPoints() const ;

    float get_radius()const;
    void set_healthPoints(float HP);
    void draw(RenderWindow& window);

    virtual void useSpecialAbility(Starship& otherShip) = 0;

    FloatRect getBoundingBox();

    // In Starship.h, add the following methods
//bool detectCollisionWithStar(const FloatRect& starBounds);
//bool isSpecialAbilityUsed() const;
//void setSpecialAbilityUsed(bool used);


    

};





#endif
