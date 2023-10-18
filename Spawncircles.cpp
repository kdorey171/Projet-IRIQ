#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <random>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 600), "Fenêtre");

    sf::RectangleShape blueSquare(sf::Vector2f(50, 50));
    blueSquare.setFillColor(sf::Color::Blue);
    blueSquare.setPosition(25, window.getSize().y / 2 - 25);

    std::vector<sf::CircleShape> circles;

    float speed = 0.05f;
    int directionX = 1;

    bool movingAutomatically = true;

    sf::Clock clock;
    sf::Clock circleDispawnClock;
    sf::Clock circleSpawnClock;
    bool canSpawnCircle = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (circleSpawnClock.getElapsedTime().asSeconds() >= 1) {
            sf::CircleShape newBlueCircle(10);
            newBlueCircle.setFillColor(sf::Color::Blue);

            newBlueCircle.setPosition(blueSquare.getPosition().x + blueSquare.getSize().x + 10, window.getSize().y / 2 - 10);


            circles.push_back(newBlueCircle);

            circleSpawnClock.restart();
        }

        if (circleDispawnClock.getElapsedTime().asSeconds() >= 1 &&  clock.getElapsedTime().asSeconds() >= 5 && !circles.empty()) {
            circles.erase(circles.begin());
            circleDispawnClock.restart();
        }

        window.clear();

        for (sf::CircleShape& circle : circles)
        {
            circle.move(speed * directionX, 0);
            window.draw(circle);
        }



        window.draw(blueSquare);

        window.display();
    }

    return 0;
}
