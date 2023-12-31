#include <random>
#include <math.h>
#include <cmath>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


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
    window.setFramerateLimit(60);

    /// start_button - TEXTURAGE

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



    /// AUDIO FILES

    // MUSIC MENU
    sf::Music main_theme;
    if (!main_theme.openFromFile("audio/super_meat_boy.ogg"))
    {
        cout << "no audio named super_meat_boy.ogg" << endl;
    }

    main_theme.setVolume(50);
    main_theme.play();









    // Initialisation des comptes des players.
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

    // LIGNES DE BATAILLE
	std::vector<RectangleShape> ligne_fight;

	for(int i=0;i<5;i++){
        RectangleShape block_ligne(size_ligne_fight);
        block_ligne.setPosition(Vector2f(0.f,120.f+i*80.f));
        block_ligne.setFillColor(sf::Color::Red);
		ligne_fight.push_back(block_ligne);
	}

    // MISE EN FORME
    bloc_base_player.setPosition(Vector2f(0.f,50.f));
    bloc_base_AI.setPosition(Vector2f(700.f,50.f));

    bloc_base_player.setFillColor(sf::Color::White);





            /// CARTES à JOUER

    // Tableau des batiments
    std::vector<vessel*> bat;
    vector<Unites> vect_unite;

    // Tableau des batiments en haut à gauche
    std::vector<RectangleShape> initsquares;

    // Initilisation de ces batiements
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



    /// Création des premier batiments de départ


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


            /// AFFICHAGE BANQUE

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
    text_banque.setString(std::to_string(account_player_1));


                /// FIN INITIALISATION MAP



    Input input; // Initialisation Touches


    //Variables de manipulation d'entitées
    bool vessel_select = false;
    int indice_bat = bat.size();
    int indice_unit = 0;
    vessel* bat_a_poser;


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



///----------------------------------------------------------------------------------- MENU POLL EVENT
            if (statut == 0)
            {
                // annuler pause
                main_theme.pause(); // securite premier lancement (important)
                main_theme.play();

                if (touche.down == true) main_theme.setVolume(main_theme.getVolume() - 10);
                if (touche.up == true) main_theme.setVolume(main_theme.getVolume() + 10);


                /// BASCULEMENT JEU
                if (abs(mousePosition.x - start_xpos) < start_xsize/2 && abs(mousePosition.y - start_ypos) < start_ysize/2 && touche.left == true)
                {
                statut = 1; // JEU
                }

            }



///----------------------------------------------------------------------------------- JEU POLL EVENT
        if (statut == 1) {
            // Gestion Audio
            main_theme.pause();



            if (touche.left == true)
            {

                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect redSquareBounds = redSquare.getGlobalBounds();
                sf::FloatRect blueSquareBounds = blueSquare.getGlobalBounds();
                sf::FloatRect greenSquareBounds = greenSquare.getGlobalBounds();





                if (!vessel_select)
                {
				//Creation des batiments après séléctions dans le coin supérieur gauche de l'écran

                    if (redSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        if (vessel_select == false) {vessel_select=true;}

                        vessel* new_bat = new vessel;
                        new_bat->set_size(size_vessel);
                        new_bat->set_color(sf::Color::Red);
                        new_bat->set_position(Vector2f(20.f, 20.f));
                        bat_a_poser = new_bat;


                    }

                    else if (blueSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        if (vessel_select == false) {vessel_select=true;}

                        vessel* new_bat = new vessel_unite(player_1.get_player());
                        bat_a_poser = new_bat;

                        //cout << "bat du player " << newbat->get_player() << endl;


                    }

                    else if (greenSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        if (vessel_select == false) {vessel_select=true;}

                        vessel* new_bat = new vessel_ressource;
                        bat_a_poser = new_bat;

                    }
                }

                else if (vessel_select)
                {
				//Empêche de placer des batiments les uns au dessus des autres


                    std::vector<sf::FloatRect> shapeBounds;

                    FloatRect rect_vessel = bat_a_poser->afficher().getGlobalBounds();

                    ///pas optimisé car on recalcule les bounds de tous les batiments à chauqe fois alors qu'il suffirait de récuperer le vecteur précédent et d'y ajouter les bounds du dernier batiment créé
                    for (vessel* bats : bat) {
                        if (bats != bat_a_poser) {
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

					//Permet de poser les batiments sur les lignes prédéfinies
					for(int i=0;i<ligne_fight.size();i++){
                        if (rect_vessel.intersects(ligne_fight[i].getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()) && !intersectsWithShapeBounds && account_player_1>=bat_a_poser->get_prix())
                        {
                            vessel_select = false;
                            bat.push_back(bat_a_poser);
                            indice_bat += 1;
                            float true_position_y=ligne_fight[i].getPosition().y-10;
                            bat[indice_bat-1]->set_position(Vector2f(bat[indice_bat-1]->get_position().x,true_position_y));

                            account_player_1 -= bat[indice_bat-1]->get_prix();
                            player_1.set_account(account_player_1);
                            text_banque.setString(std::to_string(account_player_1));
                            #ifdef __DEBUG
                            cout << "bien placé !" << endl;
                            #endif // __DEBUG
                        }
                        /// Si pas assez d'argent, mais clic quand même, le batiment ne se pose pas et le joueur perd la selection
                        else if (rect_vessel.intersects(ligne_fight[i].getGlobalBounds()) && rect_vessel.intersects(bloc_base_player.getGlobalBounds()) && !intersectsWithShapeBounds && account_player_1<bat_a_poser->get_prix())
                        {
                            vessel_select = false;
                        }
                    }
                }
            }


            if (touche.left == false)
            {

            }


                    /// BASCULEMENT MENU
            if (touche.echap == true && vessel_select == false) statut = 0; // MENU


        } // FIN statut == 1
///----------------------------------------------------------------------------------- FIN JEU POLL EVENT



        } /// FIN POLL EVENT

///----------------------------------------------------------------------------------- JEU HORS POLL EVENT

        if (statut == 1) {

        window.clear(sf::Color::Black);
        /// BACKGROUND STATIC
        window.draw(bloc_base_player);
        window.draw(bloc_base_AI);


        if (vessel_select)
        {
            for(int i=0;i<ligne_fight.size();i++)
            {
                window.draw(ligne_fight[i]);
            }
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



                /// test de mettre une seule unité en combat ///



                if (indice_unit>5)
                {
                    bats->set_spawn(false);
                }



                // Create Unite
                if (bats->get_spawn_possible())
                {

                    if (bats->get_clockspawn() >= 1)
                    {

                        if (bats->get_lvl()<3)
                        {
                            bats->set_lvl(bats->get_lvl()+1);
                        }

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


            std::vector<sf::FloatRect> unites_bounds;

            CircleShape pos_unit = unit.afficher();
            pos_unit.setPosition(unit.get_position().x+unit.get_vitesse(),unit.get_position().y);
            FloatRect rect_unit = pos_unit.getGlobalBounds();


            for (int j=0;j<vect_unite.size();j++ ) {

                if (j!=i && vect_unite[j].get_player() != unit.get_player()) {

                    unites_bounds.push_back(vect_unite[j].afficher().getGlobalBounds());

                }
            }


            bool intersectsWithunitesBounds = false;
            for (const sf::FloatRect& shapeBound : unites_bounds) {
                if (rect_unit.intersects(shapeBound)) {
                    intersectsWithunitesBounds = true;
                    break;
                }
            }

            //Deplacement
            if (unit.get_spawn_unit() && unit.get_clockdispawn()>=0.5)
            {

                #ifdef __DEBUG
                cout << "unite" << unit.get_position().x << " / " << unit.get_position().y << endl;
                #endif // __DEBUG
                if (!intersectsWithunitesBounds)
                {
                    unit.deplacement();
                    unit.loose_PV(5);
                }

                unit.reset_clockdispawn();

            }

            // Destruction
            if (unit.get_spawn_unit() && unit.get_PV()<=0 )
            {
                #ifdef __DEBUG
                cout << "destuction" << endl;
                #endif // __DEBUG

                unit=vect_unite.back();
                vect_unite.pop_back();

            }

            cout << unit.get_attaque() << " / " << unit.get_PV() << endl;
            window.draw(unit.afficher());

        } // FIN BACKGROUND UNITE


        for (size_t i = 0; i < initsquares.size(); i++) {
            window.draw(initsquares[i]);
        }


            if (vessel_select)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                bat_a_poser->set_position(Vector2f(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)));
                window.draw(bat_a_poser->afficher());
             }

        window.draw(text_banque);

        } // FIN IF JEU

///----------------------------------------------------------------------------------- FIN JEU HORS POLL EVENT
///---------------------------------------------------------------------------------------------- MENU HORS POLL EVENT
        if (statut == 0)
        {
        window.clear(sf::Color::Black);
        window.draw(sprite_start_button);
        }
///---------------------------------------------------------------------------------------------- FIN MENU HORS POLL EVENT


        window.display();


    } /// END WINDOWS IS OPEN

    return 0;
} /// END MAIN
