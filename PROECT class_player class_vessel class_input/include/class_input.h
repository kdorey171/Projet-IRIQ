#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Input{
public :
    struct Button {bool left; bool right;bool echap;bool up;bool down;};
    Input();

    Button GetButton(void) const; // return private
    void InputHandler(Event event, RenderWindow& window);

private :
    Button button;

};

#endif
