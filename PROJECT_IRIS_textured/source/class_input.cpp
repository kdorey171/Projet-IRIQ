#include "class_input.h"

#include <iostream>

using namespace sf;
using namespace std;

Input::Input()
{
     button.left=button.right=button.echap=false;
     button.down=button.up=false;
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


     /// MUSIC BUTTONs

    // down or up Pressed

    if (event.type == Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case Keyboard::Down:
            button.down = true;
            #ifdef __DEBUG
            cout << "click droit" << endl;
            #endif // __DEBUG
            break;
        case Keyboard::Up:
            button.up = true;
            #ifdef __DEBUG
            cout << "click gauche" << endl;
            #endif // __DEBUG
            break;
        default :
            break;
        }
    }

    // down or up Released

    if (event.type == Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case Keyboard::Down:
            button.down = false;
            #ifdef __DEBUG
            cout << "click droit" << endl;
            #endif // __DEBUG
            break;
        case Keyboard::Up:
            button.up = false;
            #ifdef __DEBUG
            cout << "click gauche" << endl;
            #endif // __DEBUG
            break;
        default :
            break;
        }
    }

}
