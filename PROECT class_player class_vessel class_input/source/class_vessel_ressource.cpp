#include "class_vessel_ressource.h"

#include <iostream>

using namespace std;
using namespace sf;


vessel_ressource::vessel_ressource()
{
#ifdef __DEBUG
cerr << "Constructeur par défaut du Bâtiment Ressource (vessel_ressource)" << endl;
#endif // __DEBUG
    PV = 1000;
    prix = 10;
    gain = 10;
    gain_time = 5;
}

vessel_ressource::~vessel_ressource()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment ressource (vessel_ressource)" << endl;
#endif // __DEBUG
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


