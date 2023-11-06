#include "class_input.h"

#include <iostream>

using namespace sf;
using namespace std;

Input::Input()
{
     button.left=button.right=button.echap=false;
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

    // Touche echap

    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::Escape)
        {
            button.echap = true;
        }

    }

    if (event.type == Event::KeyReleased)
    {
        if (event.key.code == Keyboard::Escape)
        {
            button.echap = false;
        }
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
            #ifdef __DEBUG
            cout << "click droit" << endl;
            #endif // __DEBUG
            break;
        case Mouse::Left:
            button.left = false;
            #ifdef __DEBUG
            cout << "click gauche" << endl;
            #endif // __DEBUG
            break;
        default :
            break;
        }
    }
}
