#include "player.h"

player::player(int num_player)
{
    cash = 500;
}

void player::set_account(int prix)
{
    cash = prix;
};

int player::get_account()
{
    return(cash);
};


// Affiche compte method
