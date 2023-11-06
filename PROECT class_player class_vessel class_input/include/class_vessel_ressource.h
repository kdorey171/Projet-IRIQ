#ifndef VESSEL_RESSOURCE_H
#define VESSEL_RESSOURCE_H

#include "class_vessel.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>



class vessel_ressource : public vessel {
protected :

    int gain; //nombre de ressources apportées par le batiment
    int gain_time;



public :

    sf::Clock ressourceGainClock;

    //Affichage
    void afficher(void);

    //constructeur
    vessel_ressource();
    //destructeur
    ~vessel_ressource();

    //methodes
    void set_gain(int);
    int get_gain();

    void set_gain_time(int);
    int get_gain_time();

    float get_clock();
    void reset_clock();


};

#endif
