#ifndef CLASS_VESSEL_H
#define CLASS_VESSEL_H

#include "player.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <SFML/Graphics.hpp>

using namespace sf;

class vessel {
protected :
    int PV;
    int lvl;
    int prix;
    int type;
    sf::RectangleShape position_vessel;

public :
    //Affichage
    sf::RectangleShape afficher();

    //constructor
    vessel();
    // Desturctor
    virtual ~vessel();

    //methods
    void set_PV(int pv);
    int get_PV();

    void set_lvl(int new_level);
    int get_lvl();

    int get_type();


    sf::Vector2f get_position();
    void set_position(sf::Vector2f);
    void set_size(sf::Vector2f);
    void set_color(sf::Color);

    bool allow_build(player);


    /// fonction classe fille en virtual


    virtual bool get_spawn_possible(){return false;}
    virtual void set_spawn(bool){int a;}
    virtual float get_clockspawn(){return 0.f;}
    virtual float get_clockdispawn(){return 0.f;}
    virtual void reset_clockspawn(){int a;}
    virtual void reset_clockdispawn(){int a;}


    /*
    build(); // construire un bâtiment, class bank allow?
    create_unit() // class unit
    */

};

#endif
