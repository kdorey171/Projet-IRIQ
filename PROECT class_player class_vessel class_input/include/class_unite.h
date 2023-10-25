#ifndef CLASS_UNITE_H
#define CLASS_UNITE_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
using namespace std;
using namespace sf;

#include <vector>


class Unites{
protected :
    int attaque;
    int PV;
    float vitesse;
    int Butin;  // C'est la quantité de ressources apportée au joueur adverse quand il tue une unité
    RectangleShape position;

public :
//void attaque_recu(); /// A modifier type de sortie !!
    Unites();
    void deplacement();
    RectangleShape get_position();
    void set_position(Vector2f);
    int get_PV();
    float get_vitesse();
    void set_PV(int);

};

#endif
