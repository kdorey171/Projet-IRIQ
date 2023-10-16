#include "class_input.h"
using namespace sf;


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
            break;
        case Mouse::Left:
            button.left = false;
            break;
        default :
            break;
        }
    }
}
