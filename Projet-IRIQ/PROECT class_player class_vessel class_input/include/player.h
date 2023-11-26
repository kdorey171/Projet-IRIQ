#ifndef PLAYER_H
#define PLAYER_H

class player {
protected :
    int num_player;
    int cash;

public :
    player(int num_player);

    void set_account(int prix);
    int get_account();
    int get_player();
    // Methode Affiche compte sur ecran cast en string.
    // si actuallisation du compte activation : modification du cash à l'écran
};

#endif
