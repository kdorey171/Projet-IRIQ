#ifndef CLASS_UNITE_H
#define CLASS_UNITE_H

#include <iostream>
using namespace std;

#include <vector>


class Unites{
protected :
    int attaque;
    int PV;
    int vitesse;
    int Butin;  // C'est la quantité de ressources apportée au joueur adverse quand il tue une unité
    int position_x;
    int position_y;

public :
//void attaque_recu(); /// A modifier type de sortie !!
    Unites();
    void deplacement();
    int get_pos_x();
    int get_pos_y();
    void set_pos_x(int);
    void set_pos_y(int);
    int get_PV();
    int get_vitesse();
    void set_PV(int);
    void affiche_pos();

};

#endif
