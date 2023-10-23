#ifndef CLASS_VESSEL_H
#define CLASS_VESSEL_H

#include <SFML/Graphics.hpp>
#include "player.h"

class vessel {
protected :
    int PV;
    int lvl;
    int prix;
    sf::RectangleShape position_vessel;

public :
    //Affichage
    void afficher(void);

    //constructor
    vessel();
    // Desturctor
    virtual ~vessel();

    //methods
    void set_PV(int pv);
    int get_PV();

    void set_lvl(int new_level);
    int get_lvl();

    sf::Vector2f get_position();
    void set_position(sf::Vector2f);
    void set_size(sf::Vector2f);
    void set_color(sf::Color);

    bool allow_build(player);

    /*
    build(); // construire un bâtiment, class bank allow?
    create_unit() // class unit
    */



};

#endif
