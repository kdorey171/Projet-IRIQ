#include <random>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "class_input.h"
#include "class_vessel.h"
#include "class_vessel_ressource.h"
#include "class_vessel_unite.h"
#include "class_unite.h"
#include "player.h"

using namespace std;
using namespace sf;

int main()
{
    cout << "start" << endl;
    RenderWindow window(VideoMode(1000, 500), "Tower Defense");

    // Menu

    /// start_button

    Texture start_button_texture;
    if (!start_button_texture.loadFromFile("start.png")) // Découpage : sf::IntRect(0,0,348,150), pb use this function
    {
        cout << "no texture named start.png" << endl;
    }

    int start_xsize = 661;
    int start_ysize = 261;
    int start_xpos = 500;
    int start_ypos = 250;
    Sprite sprite_start_button;
    sprite_start_button.setTexture(start_button_texture);
    sprite_start_button.setPosition(Vector2f(start_xpos-start_xsize/2,start_ypos-start_ysize/2)); // position de sprite_start_button

    /// Initialisation des comptes des players.
    player player_1(1);
    int account_player_1 = player_1.get_account();
    player player_IA(-1);

    cout << "num_player = " << player_IA.get_player() << endl;

    Vector2f size_base = Vector2f(300.f,450.f);
    Vector2f size_ligne_fight = Vector2f(1000.f,5.f);
    Vector2f size_vessel = Vector2f(25.f,25.f);

    Clock clock_init;
    window.setFramerateLimit(60);

                    /// Initialisation MAP

        /// MAP BACKGROUND (STATIC)

    // CAMPS PLAYERS
    RectangleShape bloc_base_player(size_base);
    RectangleShape bloc_base_AI(size_base);

    // CHAMP DE BATAILLE
    RectangleShape bloc_ligne_fight_1(size_ligne_fight);
    RectangleShape bloc_ligne_fight_2(size_ligne_fight);
    RectangleShape bloc_ligne_fight_3(size_ligne_fight);
    RectangleShape bloc_ligne_fight_4(size_ligne_fight);
    RectangleShape bloc_ligne_fight_5(size_ligne_fight);

    // MISE EN FORME
    bloc_base_player.setPosition(Vector2f(0.f,50.f));
    bloc_base_AI.setPosition(Vector2f(700.f,50.f));
    bloc_ligne_fight_1.setPosition(Vector2f(0.f,120.f));
    bloc_ligne_fight_2.setPosition(Vector2f(0.f,200.f));
    bloc_ligne_fight_3.setPosition(Vector2f(0.f,280.f));
    bloc_ligne_fight_4.setPosition(Vector2f(0.f,360.f));
    bloc_ligne_fight_5.setPosition(Vector2f(0.f,440.f));

    bloc_base_player.setFillColor(sf::Color::White);
    bloc_ligne_fight_1.setFillColor(sf::Color::Red);
    bloc_ligne_fight_2.setFillColor(sf::Color::Red);
    bloc_ligne_fight_3.setFillColor(sf::Color::Red);
    bloc_ligne_fight_4.setFillColor(sf::Color::Red);
    bloc_ligne_fight_5.setFillColor(sf::Color::Red);


            /// CARTES à JOUER

    // Tableau des carrées
    std::vector<vessel*> bat;
    vector<Unites> vect_unite;

    // Tableau des carrées initiaux
    std::vector<RectangleShape> initsquares;

    // Initilisation des carrées
    RectangleShape redSquare(size_vessel);
    redSquare.setFillColor(Color::Red);
    redSquare.setPosition(20, 10);
    initsquares.push_back(redSquare);

    sf::RectangleShape greenSquare(size_vessel);
    greenSquare.setFillColor(sf::Color::Green);
    greenSquare.setPosition(80, 10);
    initsquares.push_back(greenSquare);

    sf::RectangleShape blueSquare(size_vessel);
    blueSquare.setFillColor(sf::Color::Blue);
    blueSquare.setPosition(140, 10);
    initsquares.push_back(blueSquare);


    RectangleShape followingSquare(size_vessel);
    followingSquare.setFillColor(sf::Color::Red);



    /// Création des premier batiments


    vessel* vessel_player_1 = new vessel_unite(player_1.get_player());
    vessel_player_1->set_color(sf::Color::Blue);
    vessel_player_1->set_size(size_vessel);
    vessel_player_1->set_position(Vector2f(230.f,190.f));
    bat.push_back(vessel_player_1);

    vessel* vessel_player_IA = new vessel_unite(player_IA.get_player());
    vessel_player_IA->set_color(sf::Color::Red);
    vessel_player_IA->set_size(size_vessel);
    vessel_player_IA->set_position(Vector2f(770.f,190.f));
    bat.push_back(vessel_player_IA);


            /// BANQUE

    sf::Text text_banque;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
        return 1;
    }
    text_banque.setFont(font);
    text_banque.setCharacterSize(30);
    text_banque.setFillColor(sf::Color::White);
    text_banque.setPosition(400.0f, 10.0f);

                /// FIN INITIALISATION MAP



    Input input; // Initialisation Touches


    bool vessel_select = false;
    int indice_bat = 2;
    int indice_unit = 0;


    int statut = 0; // 0 pour menu & 1 pour jeu


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window); // Quelles touches sont appuyées ? ou relachées ?
            Input::Button touche;
            touche = input.GetButton(); // prendre touches

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (abs(mousePosition.x - start_xpos) < start_xsize/2 && abs(mousePosition.y - start_ypos) < start_ysize/2 && touche.left == true)
            {
                statut = 1; // JEU
                cout << "click validé" << endl;
            }
            else if (touche.echap == true) statut = 0; // MENU

            if (statut == 1) {
///----------------------------------------------------------------------------------- JEU
            if (touche.left == true)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect redSquareBounds = redSquare.getGlobalBounds();
                sf::FloatRect blueSquareBounds = blueSquare.getGlobalBounds();
                sf::FloatRect greenSquareBounds = greenSquare.getGlobalBounds();


                if (!vessel_select)
                {
                    if (redSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        if (vessel_select == false) {vessel_select=true;}

                        vessel* newbat = new vessel;
                        newbat->set_size(size_vessel);
                        newbat->set_color(sf::Color::Red);
                        newbat->set_position(size_vessel);
                        bat.push_back(newbat);
                        indice_bat += 1;


                    }

                    else if (blueSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        if (vessel_select == false) {vessel_select=true;}

                        vessel* newbat = new vessel_unite(player_1.get_player());
                        newbat->set_size(size_vessel);
                        newbat->set_color(sf::Color::Blue);
                        newbat->set_position(Vector2f(80.f, 20.f));

                        //cout << "bat du player " << newbat->get_player() << endl;

                        bat.push_back(newbat);
                        indice_bat += 1;
                    }

                    else if (greenSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        if (vessel_select == false) {vessel_select=true;}

                        vessel* newbat = new vessel_ressource;
                        newbat->set_size(size_vessel);
                        newbat->set_color(sf::Color::Green);
                        newbat->set_position(Vector2f(140.f, 20.f));
                        bat.push_back(newbat);
                        indice_bat += 1;
                    }
                }

                else if (vessel_select)
                {
                    std::vector<sf::FloatRect> shapeBounds;

                    FloatRect rect_vessel = bat[indice_bat-1]->afficher().getGlobalBounds();

                    for (vessel* bats : bat) {
                        if (bats != bat[indice_bat - 1]) {
                            shapeBounds.push_back(bats->afficher().getGlobalBounds());
                        }
                    }

                    bool intersectsWithShapeBounds = false;
                    for (const sf::FloatRect& shapeBound : shapeBounds) {
                        if (rect_vessel.intersects(shapeBound)) {
                            intersectsWithShapeBounds = true;
                            break;
                        }
                    }

                    if (rect_vessel.intersects(bloc_ligne_fight_1.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()) && !intersectsWithShapeBounds)
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_1.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));



                        #ifdef __DEBUG
                        cout << "bien placé !" << endl;
                        #endif // __DEBUG
                    }
                    if (rect_vessel.intersects(bloc_ligne_fight_2.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()) && !intersectsWithShapeBounds)
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_2.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));

                        #ifdef __DEBUG
                        cout << bat[indice_bat-1]->get_position().x << " " << true_position_y << endl;
                        #endif // __DEBUG
                    }
                    if (rect_vessel.intersects(bloc_ligne_fight_3.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()) && !intersectsWithShapeBounds)
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_3.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));


                        #ifdef __DEBUG
                        cout << "bien placé !" << endl;
                        #endif // __DEBUG
                    }
                    if (rect_vessel.intersects(bloc_ligne_fight_4.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()) && !intersectsWithShapeBounds)
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_4.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));

                        #ifdef __DEBUG
                        cout << "bien placé !" << endl;
                        #endif // __DEBUG
                    }
                    if (rect_vessel.intersects(bloc_ligne_fight_5.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()) && !intersectsWithShapeBounds)
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_5.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));

                        #ifdef __DEBUG
                        cout << "bien placé !" << endl;
                        #endif // __DEBUG
                    }
                }
            }


            if (touche.left == false)
            {

            }
///----------------------------------------------------------------------------------- FIN JEU
        } // FIN statut == 1


        } /// FIN POLL EVENT

///----------------------------------------------------------------------------------- JEU

        if (statut == 1) {

        window.clear(sf::Color::Black);
        /// BACKGROUND STATIC
        window.draw(bloc_base_player);
        window.draw(bloc_base_AI);

        if (vessel_select)
        {
            window.draw(bloc_ligne_fight_1);
            window.draw(bloc_ligne_fight_2);
            window.draw(bloc_ligne_fight_3);
            window.draw(bloc_ligne_fight_4);
            window.draw(bloc_ligne_fight_5);
        }

        /// BACKGROUND VESSEL
        for (vessel* bats : bat)
        {


                /// VESSEL_RESSOURCE

            if (bats->get_type()==0 && !vessel_select )
            {
                #ifdef __DEBUG
                cout << "bat ressource regardé" << endl;
                #endif // __DEBUG

                //Regarde si le batiment ressource doit donner la thune (si sa clock a atteint le temps de spawn de l'argent)
                if(bats->get_clock() >= bats->get_gain_time())
                {
                    std::cout << "Le compte du joueur 1 est a : " << player_1.get_account() << std::endl;
                    account_player_1 += bats->get_gain();
                    bats->reset_clock();
                }

                player_1.set_account(account_player_1);
                text_banque.setString(std::to_string(account_player_1));
            }

                /// VESSEL_UNITE

            if (bats->get_type()==1 && !vessel_select )
            {
                #ifdef __DEBUG
                cout << "bat unite regardé" << endl;
                #endif // __DEBUG

                // Pose du batiment
                if (!bats->get_spawn_possible())
                {
                    #ifdef __DEBUG
                    cout << "bats activer" << endl;
                    #endif // __DEBUG
                    bats->set_spawn(true);
                    bats->reset_clockspawn();
                    clock_init.restart();
                }

                // Create Unite
                if (bats->get_spawn_possible())
                {
                    if (bats->get_clockspawn() >= 1)
                    {

                        bats->reset_clockspawn();
                        Vector2f newposition_unite=bats->get_position();
                        if (bats->get_player()>0)
                        {
                            newposition_unite.x+= 30;
                            newposition_unite.y+= 5;
                        }
                        if (bats->get_player()<0)
                        {
                            newposition_unite.x-= 10;
                            newposition_unite.y+= 5;
                        }

                        Unites newunite(newposition_unite,bats->get_color(),bats->get_player());

                        #ifdef __DEBUG
                        cout << "unite du player " << newunite.get_player() << endl;
                        #endif // __DEBUG

                        vect_unite.push_back(newunite);
                        bats->set_nbunite(1);
                        indice_unit+=1;

                        #ifdef __DEBUG
                        cout << "unite :" << indice_unit << endl;
                        #endif // __DEBUG

                        #ifdef __DEBUG
                        cout << vect_unite.size() << endl;
                        #endif // __DEBUG

                    }

                }

            }

            window.draw(bats->afficher());


        } // FIN BACKGROUND VESSEL


        /// BACKGROUND UNITE

        for (int i=0;i<vect_unite.size();i++)
        {

            Unites& unit = vect_unite[i];
            // Initialisation
            if(!unit.get_spawn_unit())
            {
                unit.reset_clockdispawn();
                unit.set_spawn_unit(true);
            }

            //Deplacement
            if (unit.get_spawn_unit() && unit.get_clockdispawn()>=0.5)
            {

                #ifdef __DEBUG
                cout << "unite" << unit.get_position().x << " / " << unit.get_position().y << endl;
                #endif // __DEBUG

                unit.deplacement();
                unit.loose_PV(10);
                unit.reset_clockdispawn();

            }

            // Destruction
            if (unit.get_spawn_unit() && unit.get_PV()<=0 )
            {
                #ifdef __DEBUG
                cout << "destuction" << endl;
                #endif // __DEBUG


                //Unites& unit_transfer=vect_unite.back();

                unit=vect_unite.back();
                //unit=unit_transfer;
                vect_unite.pop_back();

            }

            window.draw(unit.afficher());

        } // FIN BACKGROUND UNITE




        for (size_t i = 0; i < initsquares.size(); i++) {
            window.draw(initsquares[i]);
        }


            if (vessel_select)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                bat[indice_bat-1]->set_position(Vector2f(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)));
                window.draw(bat[indice_bat-1]->afficher());
             }

        } // FIN IF JEU

///----------------------------------------------------------------------------------- FIN JEU
///---------------------------------------------------------------------------------------------- MENU
        if (statut == 0)
        {
        window.clear(sf::Color::Black);
        // DRAW SPRITE START
        window.draw(sprite_start_button);
        }
///---------------------------------------------------------------------------------------------- FIN MENU

        window.draw(text_banque);
        window.display();


    } /// END WINDOWS IS OPEN

    return 0;
} /// END MAIN
