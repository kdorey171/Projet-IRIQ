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
    int nb_unite;

public:

    // timer
    Clock circleSpawnClock;

    // constructeur
    vessel_unite(int);
    //destructeur
    ~vessel_unite();

    //methode
    int get_nbunite();
    void set_nbunite(int);
    void create_unite();
    void delete_unite();
    void set_spawn(bool);
    bool get_spawn_possible();
    float get_clockspawn();
    void reset_clockspawn();


};


#endif
