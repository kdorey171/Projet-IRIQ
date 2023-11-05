#include "class_vessel_unite.h"

using namespace std;
using namespace sf;

/// Constructeur

vessel_unite::vessel_unite(int player)
{
#ifdef __DEBUG
cerr << "Constructeur Bâtiment unite" << endl;
#endif // __DEBUG
    player_num = player;
    spawn_possible = false;
    PV = 1000;
    type = 1;
    prix = 20;
    nb_unite=0;
}

/// Destructeur

vessel_unite::~vessel_unite()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment ressource (vessel_ressource)" << endl;
#endif // __DEBUG
}


/// METHODS

int vessel_unite::get_player()
{
    return player_num;
}

int vessel_unite::get_nbunite()
{
    return nb_unite;
}


void vessel_unite::set_nbunite(int newnb)
{
    nb_unite+=newnb;
}



void vessel_unite::set_spawn(bool a)
{
    spawn_possible=a;
}

bool vessel_unite::get_spawn_possible()
{
    return spawn_possible;
}


        /// Clock methodes


float vessel_unite::get_clockspawn()
{
    return circleSpawnClock.getElapsedTime().asSeconds();
}

void vessel_unite::reset_clockspawn()
{
    circleSpawnClock.restart();
}







