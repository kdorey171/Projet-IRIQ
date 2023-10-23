#include "class_vessel.h"
//#include <stdio.h>
#include <iostream>

using namespace std;
using namespace sf;

// CONSSTRUCTORS

vessel::vessel()
{
#ifdef __DEBUG
cerr << "Constructeur par défaut du Bâtiment (vessel)" << endl;
#endif // __DEBUG
    PV = 1000;
    lvl = 1;
    prix = 10;
    position_vessel=RectangleShape(Vector2f(0.f,0.f));
}


vessel::~vessel()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment (vessel)" << endl;
#endif // __DEBUG
}

// AFFICHEURS

void vessel::afficher(void)
{
cout << "PV : " << PV << " lvl : " << lvl << " prix : " << prix << endl;
}

// METHODS

int vessel::get_PV()
{
    return PV;
}


void vessel::set_PV(int pv)
{
    PV = pv;
}


int vessel::get_lvl()
{
    return lvl;
}


void vessel::set_lvl(int new_lvl)
{
    lvl = new_lvl;
}

Vector2f vessel::get_position()
{
    return position_vessel.getPosition();
}


void vessel::set_position(Vector2f newposition)
{
    position_vessel.setPosition(newposition);
}

void vessel::set_size(sf::Vector2f newsize)
{
    position_vessel.setSize(newsize);
}

void vessel::set_color(sf::Color color)
{
    position_vessel.setFillColor(color);
}

//-------------------------------------------------------------------------

bool vessel::allow_build(player Player) // player_1 or player_2
{
    return(prix <= Player.get_account());
}

/*
void vessel::build(Player)
{
    // Mise à jour du prix
    Player.set_account(Player.get_account(Player.num_player)-prix);


    // Actualisation de la position
    vessel tower;
    tower = *this;
    // resultat grab (x_mouse,y_mouse,number_type)
    tower.x_position = x_mouse; // definit par l'endroit où l'on dépose la carte
    tower.y_position = y_mouse; // same
    tower.type = number_type; // definit par l'endroit où l'on "attrape la carte" (fonction grab)

    // GET TYPE (fonction grab), GET POSITION (fonction grab) DU batiment selectionné
    // switch case player1 ou player2
    // case Player1 : grab + go to position
    // case Player2 (IA) : no grab + go to position
}
*/
