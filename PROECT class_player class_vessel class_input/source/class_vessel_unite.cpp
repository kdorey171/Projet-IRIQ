#include "class_vessel_unite.h"
#include "class_unites"
// dev class vessel_unite


vessel_unite::vessel_unite()
{
#ifdef __DEBUG
cerr << "Constructeur Bâtiment unite" << endl;
#endif // __DEBUG
spawn_possible=false;
PV = 1000;
type = 0;
lvl = 1;
prix = 10;
position_vessel=RectangleShape(Vector2f(0.f,0.f));
}

void vessel_unite::set_spawn(bool a)
{
    spawn_possible=a;
}

Unites vessel_unite::create_unite()
{
    Unites unite;
    return unite;
}


