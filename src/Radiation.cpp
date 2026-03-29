#include "../include/Radiation.h"

/**
 * @brief Constructs a Radiation object with specified parameters.
 * 
 * @param radius The radius of the radiation's circular shape.
 * @param color The color of the radiation.
 * @param position The initial position of the radiation.
 * @param angle The angle of radiation movement in degrees.
 * @param damage The damage value the radiation deals upon collision.
 */
Radiation::Radiation(float radius, Color color, Vector2f position, float angle, float damage) {
  // Set the radiation appearance
  this->body = new CircleShape(radius);
  this->body->setFillColor(color);
  this->body->setOrigin(radius, radius);
  this->body->setPosition(position);
  
  // Convert angle to radians
  this->angle = angle * 3.14159 / 180;
  
  // Set radiation damage
  this->damage = damage;
}

/**
 * @brief Default constructor for the Radiation object.
 * Initializes the object with default values.
 */
Radiation::Radiation() : Radiation(5, Color::Yellow, Vector2f(250, 250), 0, 20) {}

/**
 * @brief Destructor for the Radiation object. Cleans up allocated memory.
 */
Radiation::~Radiation() {
  delete this->body;
}

/**
 * @brief Renders the radiation object in the given window.
 * 
 * @param window The RenderWindow where the radiation will be drawn.
 * @return true Always returns true after drawing.
 */
bool Radiation::draw(RenderWindow &window) {
  window.draw(*(body));
  return true;
}

/**
 * @brief Moves the radiation object based on the specified speed and time step.
 * 
 * @param speed The speed at which the radiation moves.
 * @param delta_time The time step for the movement.
 * @return true if the movement is successful, false if invalid parameters are provided.
 */
bool Radiation::move(float speed, float delta_time) {
  if (speed < 0 || delta_time < 0) {
    std::cout << "Error, speed or delta_time < 0" << std::endl;
    return false;
  } 

  // Calculate distance moved
  float x = delta_time * speed * std::cos(angle);
  float y = delta_time * speed * std::sin(angle);

  body->move(x, y);

  return true;
}

/**
 * @brief Checks if the radiation collides with a given starship.
 * 
 * @param starship Pointer to the Starship object to check for collisions.
 * @return true if a collision is detected and damage is applied, false otherwise.
 */
bool Radiation::checkCollision(Starship* starship) {
  // Check if the starship pointer is not null
  if (starship == nullptr) {
    std::cerr << "Error: Starship pointer is null!" << std::endl;
    return false;
  }
  
  // Get bounds
  FloatRect radiationBounds = body->getGlobalBounds();
  FloatRect starshipBounds = starship->getBoundingBox();
  
  // Check if bounds collide
  bool collided = radiationBounds.intersects(starshipBounds);
  
  if (collided && damage > 0) {
    // Deal damage to starship
    float healthPoints = starship->get_healthPoints() - damage;
    if (healthPoints < 0) {
      starship->set_healthPoints(0);
    } else {
      starship->set_healthPoints(healthPoints);
    }
    
    // Remove radiation's damage and color
    body->setFillColor(Color::Transparent);
    damage = 0;

    return true;
  }

  return false;
}

/**
 * @brief Getter for the angle of the radiation.
 * 
 * @return The current angle of the radiation in radians.
 */
float Radiation::get_angle() {
  return angle;
}

/**
 * @brief Getter for the damage value of the radiation.
 * 
 * @return The current damage value of the radiation.
 */
float Radiation::get_damage() {
  return damage;
}

/**
 * @brief Getter for the body of the radiation as a CircleShape pointer.
 * 
 * @return Pointer to the CircleShape object representing the radiation's body.
 */
CircleShape* Radiation::get_body() {
  return body;
}

/**
 * @brief Setter for the damage value of the radiation.
 * 
 * @param damage The new damage value for the radiation.
 * @return true if the damage is set successfully, false if the value is invalid.
 */
bool Radiation::set_damage(float damage) {
  if (damage < 0) {
    std::cout << "Error setting radiation damage, value < 0" << std::endl;
    return false;
  }
  this->damage = damage;
  return true;
}

/**
 * @brief Setter for the angle of the radiation.
 * 
 * @param angle The new angle for the radiation (in degrees, must be between 0 and 360).
 * @return true if the angle is set successfully, false if the value is invalid.
 */
bool Radiation::set_angle(float angle) {
  if (angle < 0 || angle > 360) {
    std::cout << "Error setting radiation angle, value < 0 or > 360" << std::endl;
    return false;
  }
  this->angle = angle;
  return true;
}
