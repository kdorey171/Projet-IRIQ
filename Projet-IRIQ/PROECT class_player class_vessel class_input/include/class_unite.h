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
    Clock circleActionClock;
    int num_player;
    bool spawn_unit;
    int attaque;
    int PV;
    float vitesse;
    int Butin;  // C'est la quantité de ressources apportée au joueur adverse quand il tue une unité
    int range; //portée de détection des enemis
    CircleShape position;
    int taille;

public :

//void attaque_recu(); /// A modifier type de sortie !!

    Unites(sf::Vector2f newposition, sf::Color color, int player, int lvl);
    ~Unites();

    CircleShape afficher();

    int get_player();

    void deplacement();
    float get_vitesse();
    Vector2f get_position();
    void set_position(Vector2f);

    int get_PV();
    void loose_PV(int);

    int get_attaque();

    int get_range();

    int get_taille();

    bool get_spawn_unit();
    void set_spawn_unit(bool);

    float get_clock();
    void reset_clock();

};

#endif
