#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <random>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Carrés Rouges");

    std::vector<sf::RectangleShape> squares;

    std::vector<sf::RectangleShape> initsquares;

    sf::RectangleShape redSquare(sf::Vector2f(50, 50));
    redSquare.setFillColor(sf::Color::Red);
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

    bool isFollowing = false;
    int squaresi = -1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed){

                if (event.mouseButton.button == sf::Mouse::Left)
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
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (isFollowing)
                    {

                        isFollowing = false;
                        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                        squares[squaresi].setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
                    }
                }
            }
        }

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
    }

    return 0;
}
