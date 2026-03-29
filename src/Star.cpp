#include "../include/Star.h"

Star::Star(float radius, Color color, Vector2f position){
  // set the Star's appearance
  this->body = new CircleShape(radius);
  this->body->setFillColor(color);
  this->body->setOrigin(radius,radius);
  this->body->setPosition(position);
  this->position = position;
  // initialize counters and timers
  this->phase = 0;
  this->time_passed_radiation = 0;
  this->time_passed_phase = 0;
  this->radiation_counter = 0;
  // create and initialize array of radiation
  int total_radiation_count = 10000;
  this->radiation = new Radiation*[total_radiation_count];
  std::fill_n(radiation, total_radiation_count, nullptr);
}
Star::Star() : Star(50, Color::Yellow, Vector2f(250, 250)){}
Star::~Star(){
  delete body;
  delete[] radiation;
}

// renders the Star in the provided window
bool Star::draw(RenderWindow &window){
  window.draw(*(body));
  return true;
}

// spawn radiation
bool Star::radiate(float delta_time, RenderWindow &window){
  if (delta_time < 0) {
    std::cout << "Error, delta_time < 0" << std::endl;
    return false;
  }
  // keep track of game time
  this->time_passed_phase += delta_time;
  this->time_passed_radiation += delta_time;
  // Star phase duration in seconds 
  float duration = 30;
  // Star phase rest time (no radiation period) in seconds 
  float rest = 2;
  // Star phase start and end times in seconds
  float p1_start = rest;
  float p1_end = rest + duration;
  float p2_start = p1_end + rest;
  float p2_end = p1_end + rest + duration;
  float p3_start = p2_end + rest;
  float p3_end = p2_end + rest + duration;
  // Star phase colors
  Color p1_color = Color::Yellow;
  Color p2_color = Color::Red;
  Color p3_color = Color::White;
  // Star phase radiation frequency in seconds
  float p1_freq = 0.5;
  float p2_freq = 1;
  float p3_freq = 0.05;
  // Star phase radiation speed
  float p1_speed = 50;
  float p2_speed = 50;
  float p3_speed = 50;
  // Index of the last radiation of each phase
  int p1_end_index = (p2_start - p1_start) / p1_freq;
  int p2_end_index = (p3_start - p2_start) / p2_freq;
  // Star phase radiation damage
  float p1_damage = 10;
  float p2_damage = 25;
  float p3_damage = 50;
  // change phases of the Star based on elapsed game time
  if (p3_start <= this->time_passed_phase && this->time_passed_phase <= p3_end) { 
    this->phase = 3;
    this->body->setFillColor(p3_color);
    if (this->time_passed_radiation >= p3_freq){ 
      radialRadiation(p3_color, p3_damage);
      this->time_passed_radiation = 0; 
    }
  }
  if (p2_start <= this->time_passed_phase && this->time_passed_phase <= p2_end) {
    this->phase = 2;
    this->body->setFillColor(p2_color);
    if (this->time_passed_radiation >= p2_freq){
      wallRadiation(p2_color, p2_damage); 
      this->time_passed_radiation = 0;
    }
  }
  if (p1_start <= this->time_passed_phase && this->time_passed_phase <= p1_end) {
    this->phase = 1;
    this->body->setFillColor(p1_color);
    if (this->time_passed_radiation >= p1_freq){ 
      randomRadiation(p1_color, p1_damage); 
      this->time_passed_radiation = 0;
    }
  }
  // render radiation with different speeds
  for (int i = 0; i < p1_end_index; i++){
    if (radiation[i] != nullptr){
      radiation[i]->move(p1_speed, delta_time);
      radiation[i]->draw(window);
    }
  }
  for (int i = p1_end_index; i < p2_end_index; i++){
    if (radiation[i] != nullptr){
      radiation[i]->move(p2_speed, delta_time);
      radiation[i]->draw(window);
    }
  }
  for (int i = p2_end_index; i < this->radiation_counter; i++){
    if (radiation[i] != nullptr){
      radiation[i]->move(p3_speed, delta_time);
      radiation[i]->draw(window);
    }
  } 

  return true;
}

// create pattern of radiation
bool Star::radialRadiation(Color color, float damage){
    if (damage < 0) {
    std::cout << "Error, damage < 0" << std::endl;
    return false;
  }
  // get radiation index
  int i = this->radiation_counter;
  // calculate angle of radiation path
  float angle = i * (30 * 180 / 3.14159);
  // initialize radiation
  this->radiation[i] = new Radiation(6, color, this->position, angle, damage);
  // increment radiation counter
  this->radiation_counter++;

  return true;
}
bool Star::wallRadiation(Color color, float damage){
    if (damage < 0) {
    std::cout << "Error, damage < 0" << std::endl;
    return false;
  }
  // get radiation index
  int i = this->radiation_counter;
  // initialize radiation
  if (i % 2 == 0){
    for (int j = 0; j < 5; j++){
      this->radiation[i + j] = new Radiation(6, color, this->position, 12 * (j + 1), damage);
      this->radiation[i + j + 5] = new Radiation(6, color, this->position, 12 * (j + 1) + 120, damage);
      this->radiation[i + j + 10] = new Radiation(6, color, this->position, 12 * (j + 1) + 240, damage);
    }
  } else {
    for (int j = 0; j < 5; j++){
      this->radiation[i + j] = new Radiation(6, color, this->position, 12 * (j + 1) + 60, damage);
      this->radiation[i + j + 5] = new Radiation(6, color, this->position, 12 * (j + 1) + 180, damage);
      this->radiation[i + j + 10] = new Radiation(6, color, this->position, 12 * (j + 1) + 300, damage);
    }
  }
  // increment radiation counter
  this->radiation_counter += 15;

  return true;
}
bool Star::randomRadiation(Color color, float damage){
  if (damage < 0) {
    std::cout << "Error, damage < 0" << std::endl;
    return false;
  }
  // get radiation index
  int i = this->radiation_counter;
  // initialize random seed
  srand(this->time_passed_phase);
  // get random radiation size and angles
  int size= rand() % 10 + 1;
  float angle_1 = rand() % 120 + 1;
  float angle_2 = rand() % 120 + 120;
  float angle_3 = rand() % 120 + 240;
  // initialize radiation
  this->radiation[i] = new Radiation(size, color, this->position, angle_1, damage);
  this->radiation[i + 1] = new Radiation(size, color, this->position, angle_2, damage);
  this->radiation[i + 2] = new Radiation(size, color, this->position, angle_3, damage);
  // increment radiation counter
  this->radiation_counter += 3;

  return true;
}

// check collisions with Starship
bool Star::checkCollisions(Starship* starship){
  // // check collisions between Players and the Star
  // if (this->body->getGlobalBounds().intersects(starship->getBoundingBox())){
  //   // deal damage to the player
  //   starship->set_healthPoints(0);
  // }
  // // check collisions between Players and the radiation
  // for (int i = 0; i < this->radiation_counter; i++) {
  //   radiation[i]->checkCollision(starship);
  // }



  // get bounds
  FloatRect starBounds = body->getGlobalBounds();
  FloatRect starshipBounds = starship->getBoundingBox();
  // check if bounds collide
  bool collided = starBounds.intersects(starshipBounds);

  // check collisions with Star
  if (collided) {
    // deal damage to the starship
    starship->set_healthPoints(0);
  }

  // check collisions with Radiation
  for (int i = 0; i < radiation_counter; i++) {
    radiation[i]->checkCollision(starship);
  }

  if (collided) {
    return true;
  }
  return false;
}

// getters
CircleShape* Star::get_body(){
  return body;
}
Vector2f Star::get_position(){
  return position;
}
int Star::get_radiationCounter(){
  return radiation_counter;
}
int Star::get_phase(){
  return phase;
}
float Star::get_timePassedRadiation(){
  return time_passed_radiation;
}
float Star::get_timePassedPhase(){
  return time_passed_phase;
}