#ifndef CLASS_VESSEL_H
#define CLASS_VESSEL_H

#include "player.h"
#include "load_textures.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class vessel {
protected :
    int num_player;

    // "Valeurs" attribuées dans la classe mère car caractéristique génériques.
    int lvl; // tous les bâtiment sont lvl 1 au départ.
    sf::RectangleShape position_vessel; // tous les bat ont la même taille.

    // Valeurs attribuées dans les classes filles car dépend du type de batiment
    int prix;
    int type;
    int PV;

public :
    //Affichage
    sf::RectangleShape afficher();

    //constructor
    vessel();
    // Desturctor
    virtual ~vessel();

    vessel& operator=(const vessel&);

    //methods
    void set_PV(int pv);
    int get_PV();

    void set_lvl(int new_level);
    int get_lvl();

    int get_type();
    int get_player(){return num_player;}

    int get_prix();


    sf::Vector2f get_position();
    void set_position(sf::Vector2f);
    void set_size(sf::Vector2f);
    void set_color(sf::Color);
    void set_texture(const std::string& textureKey);
    Color get_color();

    bool allow_build(player);
    void upgrade();


    /// fonction classe fille en virtual


    virtual bool get_spawn_possible(){return false;}
    virtual void set_spawn(bool){}
    virtual float get_clockspawn(){return 0.f;}
    virtual void reset_clockspawn(){}
    virtual int get_nbunite(){return 0;}
    virtual void set_nbunite(int){}


    virtual void set_gain(int){}
    virtual int get_gain(){return 0;}
    virtual float get_clock(){return 0.f;}
    virtual void reset_clock(){}
    virtual void set_gain_time(int){}
    virtual int get_gain_time(){return 0;}

};

#endif
