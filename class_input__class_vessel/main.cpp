#include <stdio.h>
#include <iostream>
#include "class_input.h"

using namespace std;

int main()
{
    cout << "start" << endl;
    RenderWindow window(VideoMode(500, 600), "SFML works!");

    Input input;
     while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        window.clear();

        window.display();
    }

    return 0;
}
