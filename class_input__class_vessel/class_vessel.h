#ifndef __VESSEL
#define __VESSEL

class vessel {
protected :
    int PV;
    int type;
    int lvl;
    int prix;
    int x_position;
    int y_position;
    int player;

public :
    //Affichage
    void afficher(void);

    //constructor
    vessel();
    // desturctor
    virtual ~vessel();

    //methods
    void set_PV(int pv);
    int get_PV();

    int get_type();

    void set_lvl(int new_level);
    int get_lvl();

    int get_x_position();
    int get_y_position();
    void set_x_position(int);
    void set_y_position(int);


    /*
    build(); // construire un bâtiment, clas bank allow?
    create_unit() // class unit
    */

};

#endif