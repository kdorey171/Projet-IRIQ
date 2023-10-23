#ifndef VESSEL_UNITE
#define VESSEL_UNITE

#include "class_vessel.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


//// class_vessel_unite

class vessel_unite : public vessel

{
protected :
bool spawn_possible;

public:

// timer
sf::Clock circleDispawnClock;
sf::Clock circleSpawnClock;

// createur
vessel_unite();

//methode
Unites create_unite();
void set_spawn(bool);


};


#endif // VESSEL_UNITE
