#include <SFML/Graphics.hpp>
#include "class_unites.h"

////// Main //////

using namespace sf;

int main()
{


    RenderWindow window(VideoMode(500, 600), "SFML works!");
    window.setFramerateLimit(60);
    Unites unite_1;
    RectangleShape bloc_unite_1(Vector2f(unite_1.get_pos_x(),unite_1.get_pos_y()));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();


        }

        unite_1.deplacement();
        unite_1.affiche_pos();
        bloc_unite_1.setPosition(Vector2f(unite_1.get_pos_x(),unite_1.get_pos_y()));
        window.clear();
        window.draw(bloc_unite_1);
        window.display();
    }

    return 0;

}
