#include "class_vessel_tower.h"
#include "load_textures.h"

using namespace std;
using namespace sf;

/// Constructeur

vessel_tower::vessel_tower()
{
#ifdef __DEBUG
cerr << "Constructeur Bâtiment unite" << endl;
#endif // __DEBUG
    PV = 5000;
    zone = 50; // Rayon de 50 blocks couvert par la tour ? ou un truc comme ça
    attack = 100;
    type = 2;
    prix = 400;

    //position_vessel.setFillColor(sf::Color::Red);
    position_vessel.setSize(Vector2f(65.f,65.f));
    position_vessel.setPosition(Vector2f(80.f,10.f));
    position_vessel.setTexture(&textureLoader.getTexture("bat_tower1"));
}

/// Destructeur

vessel_tower::~vessel_tower()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment ressource (vessel_ressource)" << endl;
#endif // __DEBUG
}


vessel_tower& vessel_tower::operator=(const vessel_tower &vu){
if (&vu == this)
    return *this;

vessel::operator=(vu);
zone = vu.zone;
attack = vu.attack;
cerr << "operator=() de Vessel_unites" << endl;
return *this;
}
