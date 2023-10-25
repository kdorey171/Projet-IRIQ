#include "class_unite.h"

////// Dev class_unités //////

Unites::Unites(){
    attaque=50;
    PV=200;
    vitesse=5;
    Butin=100;
    position_x=10;
    position_y=10;
}

int Unites::get_PV(){
    return PV;
}

int Unites::get_vitesse(){
    return vitesse;
}

int Unites::get_pos_x(){
    return position_x;
}

int Unites::get_pos_y(){
    return position_y;
}

void Unites::set_PV(int a){
    PV=a;
}

void Unites::set_pos_x(int x){
    position_x=x;
}

void Unites::set_pos_y(int y){
    position_y=y;
}

void Unites::affiche_pos(){
    cout << position_x <<"\n";
}

void Unites::deplacement(){
    if (position_x<490)
        position_x=position_x+vitesse;
    if (position_y<590)
        position_y=position_y+vitesse;
}



