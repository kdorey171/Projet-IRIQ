#ifndef VESSEL_UNITE_H
#define VESSEL_UNITE_H

#include "class_unite.h"
#include "class_vessel.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class vessel_unite : public vessel {
protected :

    bool spawn_possible;



public:

    // timer
    sf::Clock circleDispawnClock;
    sf::Clock circleSpawnClock;

    // constructeur
    vessel_unite();
    //destructeur
    ~vessel_unite();

    //methode
    Unites create_unite();
    void set_spawn(bool);
    bool get_spawn_possible();


};


#endif
