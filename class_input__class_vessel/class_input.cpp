#include "class_input.h"
#include <iostream>

using namespace sf;
using namespace std;

Input::Input()
{
     button.left=button.right=false;
}

Input::Button Input::GetButton(void) const // return private
{
    return button;
}

void Input::InputHandler(Event event, RenderWindow& window)
{
    if (event.type == Event::Closed)
    {
        window.close();
    }

    // case button pressed

    if (event.type == Event::MouseButtonPressed)
    {
        switch (event.mouseButton.button)
        {
        case Mouse::Right:
            button.right = true;
            break;
        case Mouse::Left:
            button.left = true;
            break;
        default :
            break;

        }
    }

    // case button released

    if (event.type == Event::MouseButtonReleased)
    {
        switch (event.mouseButton.button)
        {
        case Mouse::Right:
            button.right = false;
            cout << "click droit" << endl;
            break;
        case Mouse::Left:
            button.left = false;
            cout << "click gauche" << endl;
            break;
        default :
            break;
        }
    }
}
