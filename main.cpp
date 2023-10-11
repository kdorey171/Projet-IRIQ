
#include <stdio.h>
#include <SFML/Graphics.hpp>




int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
    rectangle.setFillColor(sf::Color::Blue);
    bool deplacement=false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){  // le bouton gauche est enfoncé : on tire

                //printf("click trouvé !\n");

                if (deplacement==false){
                    deplacement = true;
                }
                else
                    deplacement=false;
            }
            if (deplacement==true){
                sf::Vector2i pos_souris = sf::Mouse::getPosition(window);
                rectangle.setPosition(pos_souris.x,pos_souris.y);
            }
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
