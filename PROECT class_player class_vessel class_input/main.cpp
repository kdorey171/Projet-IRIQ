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

    // Initialisation des comptes des players.
    player player_1(1);
    player player_2(2);


                    // Initialisation MAP

    // Tableau des carrées
    std::vector<RectangleShape> squares;

    // Tableau des carrées initiaux
    std::vector<RectangleShape> initsquares;

    // Initilisation des carrées
    RectangleShape redSquare(Vector2f(50, 50));
    redSquare.setFillColor(Color::Red);
    redSquare.setPosition(20, 20);
    initsquares.push_back(redSquare);

    sf::RectangleShape greenSquare(sf::Vector2f(50, 50));
    greenSquare.setFillColor(sf::Color::Green);
    greenSquare.setPosition(20, 80);
    initsquares.push_back(greenSquare);

    sf::RectangleShape blueSquare(sf::Vector2f(50, 50));
    blueSquare.setFillColor(sf::Color::Blue);
    blueSquare.setPosition(20, 140);
    initsquares.push_back(blueSquare);


    sf::RectangleShape followingSquare(sf::Vector2f(50, 50));
    followingSquare.setFillColor(sf::Color::Red);

                // FIN INITIALISATION MAP



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
                        newSquare.setSize(sf::Vector2f(50, 50));
                        newSquare.setFillColor(sf::Color::Red);
                        newSquare.setPosition(50, 50);
                        squares.push_back(newSquare);
                        squaresi += 1;
                        isFollowing = true;
                    }

                    else if (blueSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {

                        sf::RectangleShape newSquare;
                        newSquare.setSize(sf::Vector2f(50, 50));
                        newSquare.setFillColor(sf::Color::Blue);
                        newSquare.setPosition(20, 80);
                        squares.push_back(newSquare);
                        squaresi += 1;
                        isFollowing = true;
                    }

                    else if (greenSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {

                        sf::RectangleShape newSquare;
                        newSquare.setSize(sf::Vector2f(50, 50));
                        newSquare.setFillColor(sf::Color::Green);
                        newSquare.setPosition(20, 140);
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

    } // FIN WINDOWS IS OPEN

    return 0;
} // FIN MAIN
