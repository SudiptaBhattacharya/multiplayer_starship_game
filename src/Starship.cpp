#include "../include/Starship.h"
using namespace sf;

/**
 * @brief Constructs a Starship object with specified parameters.
 * 
 * @param name The name of the starship.
 * @param speed The movement speed of the starship.
 * @param healthPoints The health points of the starship.
 * @param radius The radius of the starship's circular shape.
 * @param color The color of the starship.
 * @param position The initial position of the starship.
 * @param specialAbilityCount The number of special abilities available.
 */
Starship::Starship(string name, float speed, float healthPoints, float radius, Color color, Vector2f position, int specialAbilityCount)
    : Player(name), name(name), speed(speed), healthPoints(healthPoints), radius(radius), color(color), position(position), specialAbilityCount(specialAbilityCount) {
    
    // Initialize the starship appearance
    ship = new CircleShape(radius);
    ship->setFillColor(color);
    ship->setPosition(position);
    ship->setRadius(radius);
    ship->setOrigin(radius, radius);
    
    std::cout << "Health Points Initialized: " << this->healthPoints << std::endl; // Debugging line
}

/**
 * @brief Default constructor for the Starship object.
 */
Starship::Starship() {}

/**
 * @brief Moves the starship to the left based on speed and deltaTime.
 * 
 * @param speed The speed of the starship.
 * @param deltaTime The time step for movement.
 * @return true if the move is successful.
 */
bool Starship::moveLeft(float speed, float deltaTime) {
    ship->move(-(speed) * deltaTime, 0);
    return true;
}

/**
 * @brief Moves the starship to the right based on speed and deltaTime.
 * 
 * @param speed The speed of the starship.
 * @param deltaTime The time step for movement.
 * @return true if the move is successful.
 */
bool Starship::moveRight(float speed, float deltaTime) {
    ship->move(speed * deltaTime, 0);
    return true;
}

/**
 * @brief Moves the starship upwards based on speed and deltaTime.
 * 
 * @param speed The speed of the starship.
 * @param deltaTime The time step for movement.
 * @return true if the move is successful.
 */
bool Starship::moveUp(float speed, float deltaTime) {
    ship->move(0, -speed * deltaTime);
    return true;
}

/**
 * @brief Moves the starship downwards based on speed and deltaTime.
 * 
 * @param speed The speed of the starship.
 * @param deltaTime The time step for movement.
 * @return true if the move is successful.
 */
bool Starship::moveDown(float speed, float deltaTime) {
    ship->move(0, speed * deltaTime);
    return true;
}

/**
 * @brief Handles input for starship movement based on keyboard input and window focus.
 * 
 * @param speed The speed of the starship.
 * @param deltaTime The time step for movement.
 * @param isWindowFocused Whether the game window is currently focused.
 * @param windowHeight The height of the game window.
 * @param windowWidth The width of the game window.
 */
void Starship::inputHandle(float speed, float deltaTime, bool isWindowFocused, float windowHeight, float windowWidth) {
    // Get starship's current position
    float posX = this->get_position().x;
    float posY = this->get_position().y;
    
    // Define boundaries based on the starship's size
    float leftBoundary = this->get_radius() + 0;
    float rightBoundary = windowWidth - this->get_radius();
    float topBoundary = this->get_radius() + 0;
    float bottomBoundary = windowHeight - this->get_radius();

    // Check if the window is focused before processing input
    if (isWindowFocused) {
        if (Keyboard::isKeyPressed(Keyboard::A) && posX > leftBoundary) {
            moveLeft(speed, deltaTime);
        }
        if (Keyboard::isKeyPressed(Keyboard::D) && posX < rightBoundary) {
            moveRight(speed, deltaTime);
        }
        if (Keyboard::isKeyPressed(Keyboard::W) && posY > topBoundary) {
            moveUp(speed, deltaTime);
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && posY < bottomBoundary) {
            moveDown(speed, deltaTime);
        }
    }
}

/**
 * @brief Gets the current position of the starship.
 * 
 * @return The current position as a Vector2f.
 */
Vector2f Starship::get_position() const {
    return ship->getPosition();
}

/**
 * @brief Sets the position of the starship.
 * 
 * @param position The new position of the starship.
 * @return true if the position is set successfully.
 */
bool Starship::set_position(Vector2f position) {
    ship->setPosition(position);
    // Add further checks if needed in the future
    return true;
}

/**
 * @brief Gets the health points of the starship.
 * 
 * @return The current health points of the starship.
 */
float Starship::get_healthPoints() const {
    return healthPoints;
}

/**
 * @brief Sets the health points of the starship.
 * 
 * @param HP The new health points value.
 */
void Starship::set_healthPoints(float HP) {
    this->healthPoints = HP;
}

/**
 * @brief Gets the radius of the starship.
 * 
 * @return The radius of the starship.
 */
float Starship::get_radius() const {
    return radius;
}

/**
 * @brief Destructor for the Starship object. Cleans up allocated memory.
 */
Starship::~Starship() {
    delete ship;
}

/**
 * @brief Reduces the health of the starship by a specified amount.
 * 
 * @param amount The amount to reduce the health by.
 */
void Starship::reduceHealth(float amount) {
    healthPoints -= amount;
    if (healthPoints < 0) {
        healthPoints = 0;
    }
}

/**
 * @brief Gets the bounding box of the starship for collision detection.
 * 
 * @return A FloatRect representing the starship's bounding box.
 */
FloatRect Starship::getBoundingBox() {
    return ship->getGlobalBounds(); // SFML provides this method to get the bounding box of a shape
}

/**
 * @brief Renders the starship in the given window.
 * 
 * @param window The RenderWindow where the starship will be drawn.
 */
void Starship::draw(sf::RenderWindow &window) {
    window.draw(*ship);
}

/**
 * @brief Detects if the starship collides with the star's bounding box.
 * 
 * @param starBounds The bounding box of the star.
 * @return true if a collision is detected.
 */
/*bool Starship::detectCollisionWithStar(const FloatRect& starBounds) {
    return ship->getGlobalBounds().intersects(starBounds);
}*/

/**
 * @brief Checks if the special ability of the starship has been used.
 * 
 * @return true if the special ability has been used, false otherwise.
 */
/*bool Starship::isSpecialAbilityUsed() const {
    return specialAbilityCount == 0;
}

/**
 * @brief Sets the status of the starship's special ability.
 * 
 * @param used Set to true if the special ability has been used, false otherwise.
 */
/*void Starship::setSpecialAbilityUsed(bool used) {
    specialAbilityCount = used ? 0 : 1;
}*/



