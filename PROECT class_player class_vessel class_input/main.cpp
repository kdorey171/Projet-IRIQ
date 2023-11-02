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

    /// Initialisation des comptes des players.
    player player_1(1);
    player player_2(2);
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

                /// FIN INITIALISATION MAP



    Input input; // Initialisation Touches


    bool vessel_select = false;
    int indice_bat = 0;
    int indice_unit = 0;



     while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window); // Quelles touches sont appuyées ? ou relachées ?
            Input::Button souris;
            souris = input.GetButton(); // prendre touches
//-----------------------------------------------------------------------------------
            if (souris.left == true)
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

                        vessel* newbat = new vessel_unite;
                        newbat->set_size(size_vessel);
                        newbat->set_color(sf::Color::Blue);
                        newbat->set_position(Vector2f(80.f, 20.f));
                        bat.push_back(newbat);
                        indice_bat += 1;
                    }

                    else if (greenSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        if (vessel_select == false) {vessel_select=true;}

                        vessel* newbat = new vessel;
                        newbat->set_size(size_vessel);
                        newbat->set_color(sf::Color::Green);
                        newbat->set_position(Vector2f(140.f, 20.f));
                        bat.push_back(newbat);
                        indice_bat += 1;
                    }
                }

                else if (vessel_select)
                {
                    FloatRect rect_vessel = bat[indice_bat-1]->afficher().getGlobalBounds();
                    if (rect_vessel.intersects(bloc_ligne_fight_1.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()))
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_1.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));



                        #ifdef __DEBUG
                        cout << "bien placé !" << endl;
                        #endif // __DEBUG
                    }
                    if (rect_vessel.intersects(bloc_ligne_fight_2.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()))
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_2.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));

                        #ifdef __DEBUG
                        cout << "bien placé !" << endl;
                        #endif // __DEBUG
                    }
                    if (rect_vessel.intersects(bloc_ligne_fight_3.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()))
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_3.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));


                        #ifdef __DEBUG
                        cout << "bien placé !" << endl;
                        #endif // __DEBUG
                    }
                    if (rect_vessel.intersects(bloc_ligne_fight_4.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()))
                    {
                        vessel_select = false;
                        float true_position_y=bloc_ligne_fight_4.getPosition().y-10;
                        bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));

                        #ifdef __DEBUG
                        cout << "bien placé !" << endl;
                        #endif // __DEBUG
                    }
                    if (rect_vessel.intersects(bloc_ligne_fight_5.getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()))
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
//-----------------------------------------------------------------------------------
            if (souris.left == false)
            {

            }

            if (souris.right == true)
            {
                if (vessel_select)
                {
                    indice_bat-=1;
                    bat.pop_back();
                    vessel_select=false;
                }
            }




        } // FIN POLL_EVENT

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
                        newposition_unite.x+= 20;
                        Unites newunite(newposition_unite,bats->get_color());

                        #ifdef __DEBUG
                        cout << "bat" << bats->get_position().x << " / " << bats->get_position().y << endl;
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
                unit.loose_PV(20);
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


        window.display();

    } /// END WINDOWS IS OPEN

    return 0;
} /// END MAIN
