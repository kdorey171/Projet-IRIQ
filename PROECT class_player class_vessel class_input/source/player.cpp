#include "player.h"

player::player(int player)
{
    cash = 500;
    num_player = player;
}

void player::set_account(int prix)
{
    cash = prix;
};

int player::get_account()
{
    return(cash);
};

int player::get_player()
{
    return num_player;
}

// Affiche compte method
