#include "class_vessel_unite.h"
#include "load_textures.h"

using namespace std;
using namespace sf;

/// Constructeur

vessel_unite::vessel_unite(int player)
{
#ifdef __DEBUG
cerr << "Constructeur Bâtiment unite" << endl;
#endif // __DEBUG
    num_player = player;
    spawn_possible = false;
    PV = 1000;
    type = 1;
    prix = 200;
    nb_unite=0;
    //position_vessel.setFillColor(sf::Color::Blue);
    position_vessel.setPosition(Vector2f(80.f,10.f));
    position_vessel.setTexture(textureLoader.getTexture("bat_unit1"));
}

/// Destructeur

vessel_unite::~vessel_unite()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment ressource (vessel_ressource)" << endl;
#endif // __DEBUG
}

vessel_unite& vessel_unite::operator=(const vessel_unite &vu){
if (&vu == this)
    return *this;

vessel::operator=(vu);
nb_unite = vu.nb_unite;
spawn_possible = vu.spawn_possible;
circleSpawnClock = vu.circleSpawnClock;
cerr << "operator=() de Vessel_unites" << endl;
return *this;
}

/// METHODS


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







