#ifndef VESSEL_UNITE_H
#define VESSEL_UNITE_H

#include "class_unite.h"
#include "class_vessel.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

using namespace std;
using namespace sf;

class vessel_unite : public vessel {
protected :

    bool spawn_possible;
    vector<Unites> unite;
    int nb_unite;

public:

    // timer
    Clock circleDispawnClock;
    Clock circleSpawnClock;

    // constructeur
    vessel_unite();
    //destructeur
    ~vessel_unite();

    //methode
    Unites create_unite();
    void set_spawn(bool);
    bool get_spawn_possible();
    float get_clockspawn();
    float get_clockdispawn();
    void reset_clockspawn();
    void reset_clockdispawn();


};


#endif
