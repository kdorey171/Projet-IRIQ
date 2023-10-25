#include "class_vessel_unite.h"

using namespace std;
using namespace sf;


vessel_unite::vessel_unite()
{
#ifdef __DEBUG
cerr << "Constructeur Bâtiment unite" << endl;
#endif // __DEBUG
    spawn_possible = false;
    PV = 1000;
    type = 1;
    prix = 20;
    nb_unite=0;
}

vessel_unite::~vessel_unite()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment ressource (vessel_ressource)" << endl;
#endif // __DEBUG
}


// METHODS


void vessel_unite::set_spawn(bool a)
{
    spawn_possible=a;
}

bool vessel_unite::get_spawn_possible()
{
    return spawn_possible;
}

Unites vessel_unite::create_unite()
{
    Unites unite;
    return unite;
}

float vessel_unite::get_clockspawn()
{
    return circleSpawnClock.getElapsedTime().asSeconds();
}


float vessel_unite::get_clockdispawn()
{
    return circleDispawnClock.getElapsedTime().asSeconds();
}


void vessel_unite::reset_clockspawn()
{
    circleSpawnClock.restart();
}

void vessel_unite::reset_clockdispawn()
{
    circleDispawnClock.restart();
}









