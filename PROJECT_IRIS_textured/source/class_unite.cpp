#include "class_unite.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

////// Dev class_unités //////

Unites::Unites(sf::Vector2f newposition, sf::Color color, int player, int lvl)
{

    num_player=player;
    attaque=50;
    PV=200;
    vitesse = 10.f * num_player;
    Butin=100;
    range = 10.f*2.f;
    spawn_unit=false;
    taille = 5.f;
    position.setRadius(taille);
    position.setPosition(newposition);
    position.setFillColor(color);

    switch (lvl)
    {

        case 1:
            attaque=50;
            PV=200;
            vitesse = 10.f * num_player;

        case 2:
            attaque=50 * lvl;
            PV=200 * lvl ;
            vitesse = 10.f * lvl * num_player;
    }

}

Unites::~Unites()
{
    #ifdef __DEBUG
    cout << "destructeur Unites" << endl;
    #endif // __DEBUG



}


int Unites::get_player()
{
    return num_player;
}


CircleShape Unites::afficher()
{
    return position;
}


int Unites::get_PV(){
    return PV;
}

void Unites::loose_PV(int a){
    PV-=a;
}

int Unites::get_attaque(){
    return attaque;
}

int Unites::get_range(){
    return range;
}

bool Unites::get_spawn_unit(){
    return spawn_unit;
}

void Unites::set_spawn_unit(bool a){
    spawn_unit=a;
}



float Unites::get_vitesse(){
    return vitesse;
}

Vector2f Unites::get_position()
{
    return position.getPosition();
}


void Unites::set_position(Vector2f newposition)
{
    position.setPosition(newposition);
}

void Unites::deplacement()
{
    if(position.getPosition().x<900)
        position.move(vitesse,0.f);
}


void Unites::reset_clock()
{
    circleActionClock.restart();
}

float Unites::get_clock()
{
    return circleActionClock.getElapsedTime().asSeconds();
}

int Unites::get_taille()
{
    return taille;
}
