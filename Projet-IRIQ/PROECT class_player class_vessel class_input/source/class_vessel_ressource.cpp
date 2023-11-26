#include "class_vessel_ressource.h"
#include "load_textures.h"
#include <iostream>

using namespace std;
using namespace sf;
#define __DEBUG


vessel_ressource::vessel_ressource()
{
#ifdef __DEBUG
cerr << "Constructeur par défaut du Bâtiment Ressource (vessel_ressource)" << endl;
#endif // __DEBUG
    PV = 1000;
    type = 0;
    prix = 100;
    gain = 10;
    gain_time = 1;
    //position_vessel.setFillColor(sf::Color::Green);
    //position_vessel.setSize(Vector2f(65.f,65.f));
    //position_vessel.setPosition(Vector2f(80.f,10.f));
    position_vessel.setTexture(&textureLoader.getTexture("bat_prod1")); // comme vessel_ressource pas encore crée, on utilise pas encore la méthode set_texture(string);
}

vessel_ressource::~vessel_ressource()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment ressource (vessel_ressource)" << endl;
#endif // __DEBUG
}

vessel_ressource& vessel_ressource::operator=(const vessel_ressource &vr){
if (&vr == this)
    return *this;

vessel::operator=(vr);
gain = vr.gain;
gain_time = vr.gain_time;
ressourceGainClock = vr.ressourceGainClock;
#ifdef __DEBUG
cerr << "operator=() de Vessel_ressources" << endl;
#endif
return *this;
}


// METHODS


int vessel_ressource::get_gain()
{
    return gain;
}


void vessel_ressource::set_gain(int new_gain)
{
    gain = new_gain;
}


int vessel_ressource::get_gain_time(void)
{
    return gain_time;
}


void vessel_ressource::set_gain_time(int new_gain_time)
{
    gain_time = new_gain_time;
}


float vessel_ressource::get_clock(void)
{
    return ressourceGainClock.getElapsedTime().asSeconds();
}

void vessel_ressource::reset_clock()
{
    ressourceGainClock.restart();
}
