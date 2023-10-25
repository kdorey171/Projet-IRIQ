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
    type = 0;
    prix = 20;
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

Unites vessel_unite::create_unite()
{
    Unites unite;
    return unite;
}


