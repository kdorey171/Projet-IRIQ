#ifndef CLASS_VESSEL_H
#define CLASS_VESSEL_H

#include <SFML/Graphics.hpp>
#include "player.h"

class vessel {
protected :
    int PV;
    int type;
    int lvl;
    int prix;
    int x_position;
    int y_position;

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

    int get_type();

    void set_lvl(int new_level);
    int get_lvl();

    bool allow_build(player);

    /*
    build(); // construire un bâtiment, class bank allow?
    create_unit() // class unit
    */

};

#endif
