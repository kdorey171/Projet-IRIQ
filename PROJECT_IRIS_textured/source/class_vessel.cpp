#include "class_vessel.h"
#include "load_textures.h"
#include <iostream>

using namespace std;
using namespace sf;

// CONSTRUCTORS

vessel::vessel()
{
#ifdef __DEBUG
cerr << "Constructeur par défaut du Bâtiment (vessel)" << endl;
#endif // __DEBUG
    lvl = 1;
    position_vessel = RectangleShape(Vector2f(0.f,0.f));
}

vessel::~vessel()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment (vessel)" << endl;
#endif // __DEBUG
}


vessel& vessel::operator=(const vessel &v){
if (&v == this)
    return *this;

num_player = v.num_player;
PV = v.PV;
lvl = v.lvl;
prix = v.prix;
type = v.type;
position_vessel = v.position_vessel;
return *this;
}



// AFFICHEURS

RectangleShape vessel::afficher()
{
return position_vessel;
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


int vessel::get_type()
{
    return type;
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

Color vessel::get_color()
{
    return position_vessel.getFillColor();
}

void vessel::set_texture(sf::Texture& texture) /// NE MARCHE PAS, à utiliser si on veut faire passer le bat au niveau suivant.
{
    Texture vessel_texture = texture;
    position_vessel.setTexture(&vessel_texture);
}

int vessel::get_prix()
{
    return prix;
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
