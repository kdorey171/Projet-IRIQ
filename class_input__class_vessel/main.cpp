#include <stdio.h>
#include <iostream>
#include "class_input.h"


using namespace std;

int main()
{
    cout << "start" << endl;
    RenderWindow window(VideoMode(1000, 500), "SFML works!");


    RectangleShape bloc_base_player(Vector2f(300.f,450.f));
    RectangleShape bloc_base_AI(Vector2f(300.f,450.f));


    RectangleShape bloc_ligne_fight_1(Vector2f(1000.f,2.f));
    RectangleShape bloc_ligne_fight_2(Vector2f(1000.f,2.f));
    RectangleShape bloc_ligne_fight_3(Vector2f(1000.f,2.f));
    RectangleShape bloc_ligne_fight_4(Vector2f(1000.f,2.f));
    RectangleShape bloc_ligne_fight_5(Vector2f(1000.f,2.f));


    bloc_base_player.setPosition(Vector2f(0.f,50.f));
    bloc_base_AI.setPosition(Vector2f(700.f,50.f));
    bloc_ligne_fight_1.setPosition(Vector2f(0.f,120.f));
    bloc_ligne_fight_2.setPosition(Vector2f(0.f,200.f));
    bloc_ligne_fight_3.setPosition(Vector2f(0.f,280.f));
    bloc_ligne_fight_4.setPosition(Vector2f(0.f,360.f));
    bloc_ligne_fight_5.setPosition(Vector2f(0.f,440.f));

    bloc_base_player.setFillColor(sf::Color::White);
    bloc_ligne_fight_1.setFillColor(sf::Color::Red);
    bloc_ligne_fight_2.setFillColor(sf::Color::Red);
    bloc_ligne_fight_3.setFillColor(sf::Color::Red);
    bloc_ligne_fight_4.setFillColor(sf::Color::Red);
    bloc_ligne_fight_5.setFillColor(sf::Color::Red);

    Input input;
     while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }
        window.clear();
        window.draw(bloc_base_player);
        window.draw(bloc_base_AI);
        window.draw(bloc_ligne_fight_1);
        window.draw(bloc_ligne_fight_2);
        window.draw(bloc_ligne_fight_3);
        window.draw(bloc_ligne_fight_4);
        window.draw(bloc_ligne_fight_5);
        window.display();
    }

    return 0;
}
