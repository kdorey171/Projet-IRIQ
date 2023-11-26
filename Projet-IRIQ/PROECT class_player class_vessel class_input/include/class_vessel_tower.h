#ifndef VESSEL_TOWER_H
#define VESSEL_TOWER_H

#include "class_unite.h"
#include "class_vessel.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

using namespace std;
using namespace sf;

class vessel_tower : public vessel {
protected :
    int zone; // zone d'attaque du batimentent tour de défense.
    int attack;

public:

    // constructeur
    vessel_tower();
    //destructeur
    ~vessel_tower();

    vessel_tower& operator=(const vessel_tower&);

};


#endif
