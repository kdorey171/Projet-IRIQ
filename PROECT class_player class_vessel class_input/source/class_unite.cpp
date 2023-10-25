#include "class_unite.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

////// Dev class_unités //////

Unites::Unites(){
    attaque=50;
    PV=200;
    vitesse=5.f;
    Butin=100;
    position = RectangleShape(Vector2f(10.f,10.f));
}

int Unites::get_PV(){
    return PV;
}

float Unites::get_vitesse(){
    return vitesse;
}

RectangleShape Unites::get_position()
{
    return position;
}


void Unites::set_PV(int a){
    PV=a;
}

void Unites::set_position(Vector2f newposition)
{
    position.setPosition(newposition);
}

void Unites::deplacement(){
    if (position.getPosition().x<490 && position.getPosition().y<590)
        position.setPosition(Vector2f(vitesse,vitesse));
}



