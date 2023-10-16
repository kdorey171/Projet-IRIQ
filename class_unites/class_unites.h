#include <iostream>
using namespace std;

#include <vector>


///// Class unités /////

class Unites

{
protected :
int attaque;
int PV;
int vitesse;
int Butin;  // Qu'est qu'on voulait dire ??
int position_x;
int position_y;

public :
//void attaque_recu(); /// A modifier type de sortie !!
void deplacement();
int get_pos_x();
int get_pos_y();
void set_pos_x(int);
void set_pos_y(int);
int get_PV();
int get_vitesse();
void set_PV(int);
void affiche_pos();
Unites();



};

