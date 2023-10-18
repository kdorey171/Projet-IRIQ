#include <stdio.h>
#include <iostream>
#include <random>
#include <math.h>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "class_input.h"
#include "player.h"
#include "class_vessel.h"

using namespace std;
using namespace sf;

int main()
{
    cout << "start" << endl;
    RenderWindow window(VideoMode(1000, 500), "Tower Defense");

    /// Initialisation des comptes des players.
    player player_1(1);
    player player_2(2);


                    /// Initialisation MAP

        /// MAP BACKGROUND (STATIC)

    // CAMPS PLAYERS
    RectangleShape bloc_base_player(Vector2f(300.f,450.f));
    RectangleShape bloc_base_AI(Vector2f(300.f,450.f));

    // CHAMP DE BATAILLE
    RectangleShape bloc_ligne_fight_1(Vector2f(1000.f,2.f));
    RectangleShape bloc_ligne_fight_2(Vector2f(1000.f,2.f));
    RectangleShape bloc_ligne_fight_3(Vector2f(1000.f,2.f));
    RectangleShape bloc_ligne_fight_4(Vector2f(1000.f,2.f));
    RectangleShape bloc_ligne_fight_5(Vector2f(1000.f,2.f));

    // MISE EN FORME
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


            /// CARTES à JOUER

    // Tableau des carrées
    std::vector<RectangleShape> squares;

    // Tableau des carrées initiaux
    std::vector<RectangleShape> initsquares;

    // Initilisation des carrées
    RectangleShape redSquare(Vector2f(30, 30));
    redSquare.setFillColor(Color::Red);
    redSquare.setPosition(20, 20);
    initsquares.push_back(redSquare);

    sf::RectangleShape greenSquare(sf::Vector2f(30, 30));
    greenSquare.setFillColor(sf::Color::Green);
    greenSquare.setPosition(80, 20);
    initsquares.push_back(greenSquare);

    sf::RectangleShape blueSquare(sf::Vector2f(30, 30));
    blueSquare.setFillColor(sf::Color::Blue);
    blueSquare.setPosition(140, 20);
    initsquares.push_back(blueSquare);


    sf::RectangleShape followingSquare(sf::Vector2f(30, 30));
    followingSquare.setFillColor(sf::Color::Red);

                /// FIN INITIALISATION MAP



    Input input; // Initialisation Touches

    bool isFollowing = false;
    int squaresi = -1;




     while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window); // Quelles touches sont appuyées ? ou relachées ?
            Input::Button souris;
            souris = input.GetButton(); // prendre touches
//-----------------------------------------------------------------------------------
            if (souris.left == true)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect redSquareBounds = redSquare.getGlobalBounds();
                sf::FloatRect blueSquareBounds = blueSquare.getGlobalBounds();
                sf::FloatRect greenSquareBounds = greenSquare.getGlobalBounds();
                    if (redSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {

                        sf::RectangleShape newSquare;
                        newSquare.setSize(sf::Vector2f(30, 30));
                        newSquare.setFillColor(sf::Color::Red);
                        newSquare.setPosition(30, 30);
                        squares.push_back(newSquare);
                        squaresi += 1;
                        isFollowing = true;
                    }

                    else if (blueSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {

                        sf::RectangleShape newSquare;
                        newSquare.setSize(sf::Vector2f(30, 30));
                        newSquare.setFillColor(sf::Color::Blue);
                        newSquare.setPosition(80, 20);
                        squares.push_back(newSquare);
                        squaresi += 1;
                        isFollowing = true;
                    }

                    else if (greenSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {

                        sf::RectangleShape newSquare;
                        newSquare.setSize(sf::Vector2f(30, 30));
                        newSquare.setFillColor(sf::Color::Green);
                        newSquare.setPosition(140, 20);
                        squares.push_back(newSquare);
                        squaresi += 1;
                        isFollowing = true;
                    }
            }
//-----------------------------------------------------------------------------------
            if (souris.left == false)
            {
                    if (isFollowing)
                    {
                        isFollowing = false;
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        squares[squaresi].setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
                    }
            }

        } // FIN POLL_EVENT

        window.clear(sf::Color::Black);

        /// BACKGROUND STATIC

        window.draw(bloc_base_player);
        window.draw(bloc_base_AI);
        window.draw(bloc_ligne_fight_1);
        window.draw(bloc_ligne_fight_2);
        window.draw(bloc_ligne_fight_3);
        window.draw(bloc_ligne_fight_4);
        window.draw(bloc_ligne_fight_5);

        /// BACKGROUND

        for (const sf::RectangleShape& square : squares)
        {
            window.draw(square);
        }


        for (size_t i = 0; i < initsquares.size(); i++) {
            window.draw(initsquares[i]);
        }


        if (isFollowing)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            squares[squaresi].setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            window.draw(squares[squaresi]);
        }


        window.display();

    } /// END WINDOWS IS OPEN

    return 0;
} /// END MAIN
