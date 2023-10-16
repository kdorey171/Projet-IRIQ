#include "class_vessel.h"
//#include <stdio.h>
#include <iostream>

using namespace std;

// CONSSTRUCTORS

vessel::vessel()
{
#ifdef __DEBUG
cerr << "Constructeur par défaut du Bâtiment (vessel)" << endl;
#endif // __DEBUG
    PV = 1000;
    type = 0;
    lvl = 1;
    prix = -1;
}


vessel::~vessel()
{
#ifdef __DEBUG
cerr << "Destruction du Bâtiment (vessel)" << endl;
#endif // __DEBUG
}

// AFFICHEURS

void vessel::afficher(void)
{
cout << "PV : " << PV << " type : " << type << " lvl : " << lvl << " prix : " << prix << endl;
}

// METHODS

int vessel::get_PV()
{
    return PV;
}


void vessel::set_PV(int pv)
{
    PV = pv;
}


int vessel::get_type(void)
{
    return type;
}


int vessel::get_lvl()
{
    return lvl;
}


void vessel::set_lvl(int new_lvl)
{
    lvl = new_lvl;
}


