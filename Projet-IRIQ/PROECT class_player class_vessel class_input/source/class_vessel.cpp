#include "class_vessel.h"
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
    position_vessel.setSize(Vector2f(65.f,65.f));
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

void vessel::set_texture(const std::string& textureKey)
{
    position_vessel.setTexture(&textureLoader.getTexture(textureKey));
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


void vessel::upgrade()
{
    lvl=lvl+1;
    PV = PV * 2;
    switch (type)
    {
        case 0: // Bâtiment ressources

            switch (lvl)
            {
                case 2:
                    position_vessel.setTexture(&textureLoader.getTexture("bat_prod2"));
                    break;
                case 3:
                    position_vessel.setTexture(&textureLoader.getTexture("bat_prod3"));
                    break;

                default:
                    break;
            }
            break;
        case 1: // Batiment unités

            switch (lvl)
            {
                case 2:
                    position_vessel.setTexture(&textureLoader.getTexture("bat_unit2"));
                    break;
                case 3:
                    position_vessel.setTexture(&textureLoader.getTexture("bat_unit3"));
                    break;

                default:
                    break;
            }
            break;
        case 2 : // Batiment tower

            switch(lvl)
            {
                case 2 :
                    position_vessel.setTexture(&textureLoader.getTexture("bat_tower2"));
                    break;
                case 3 :
                    position_vessel.setTexture(&textureLoader.getTexture("bat_unit3"));
                    break;
                default :
                    break;
            }
        default:
            break;
    }

}

