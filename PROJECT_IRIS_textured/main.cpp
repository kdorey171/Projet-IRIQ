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

#include "load_textures.h"

using namespace std;
using namespace sf;

int main()
{
    cout << "start" << endl;
    RenderWindow window(VideoMode(1000, 500), "Tower Defense");
    window.setFramerateLimit(60);

    /// TEXTURAGE
/*
    // MENU
    // start_button

    Texture start_button_texture;
    if (!start_button_texture.loadFromFile("textures/start.png")) // Découpage : sf::IntRect(0,0,348,150), pb use this function
    {
        cout << "no texture named start.png" << endl;
    }

    Sprite sprite_start_button;
    sprite_start_button.setTexture(start_button_texture);

    sprite_start_button.setScale(0.5f, 0.5f);
    sprite_start_button.setPosition(Vector2f(window.getSize().x / 2.0f - sprite_start_button.getGlobalBounds().width / 2.0f,
                                              window.getSize().y / 2.0f - sprite_start_button.getGlobalBounds().height / 2.0f));

    // Background MENU
    Texture background_menu_texture;
    if (!background_menu_texture.loadFromFile("textures/background_menu.png"))
    {
        cout << "no texture named background_menu.png" << endl;
    }

    Sprite sprite_background_menu;
    sprite_background_menu.setTexture(background_menu_texture);

    // Ajustement de la taille du sprite pour correspondre à la taille de la fenêtre
        sprite_background_menu.setScale(
            static_cast<float>(window.getSize().x) / sprite_background_menu.getLocalBounds().width,
            static_cast<float>(window.getSize().y) / sprite_background_menu.getLocalBounds().height
        );

    // JEU
    Texture background_map_texture;
    if (!background_map_texture.loadFromFile("textures/background_map.png"))
    {
        cout << "no texture named background_map.png" << endl;
    }

    Sprite sprite_background_map;
    sprite_background_map.setTexture(background_map_texture);

    sprite_background_map.setScale(
        static_cast<float>(window.getSize().x) / sprite_background_map.getLocalBounds().width,
        static_cast<float>(window.getSize().y) / sprite_background_map.getLocalBounds().height
    );

    Texture bat_prod1_texture;
    if (!bat_prod1_texture.loadFromFile("textures/bat_prod1.png"))
    {
        cout << "no texture named bat_prod1.png" << endl;
    }

    Texture bat_archer1_texture;
    if (!bat_archer1_texture.loadFromFile("textures/bat_archer1.png"))
    {
        cout << "no texture named bat_archer1.png" << endl;
    }

    Texture bat_unit1_texture;
    if (!bat_unit1_texture.loadFromFile("textures/bat_unit1.png"))
    {
        cout << "no texture named bat_unit1.png" << endl;
    }
    */

    /// SPRITES

    Sprite sprite_start_button;
    sprite_start_button.setTexture(textureLoader.getTexture("start_button"));
    sprite_start_button.setScale(0.5f, 0.5f);
    sprite_start_button.setPosition(Vector2f(window.getSize().x / 2.0f - sprite_start_button.getGlobalBounds().width / 2.0f,
                                              window.getSize().y / 2.0f - sprite_start_button.getGlobalBounds().height / 2.0f));



    Sprite sprite_background_menu;
    sprite_background_menu.setTexture(textureLoader.getTexture("background_menu"));
    sprite_background_menu.setScale(
        static_cast<float>(window.getSize().x) / sprite_background_menu.getLocalBounds().width,
        static_cast<float>(window.getSize().y) / sprite_background_menu.getLocalBounds().height
    );


    Sprite sprite_background_map;
    sprite_background_map.setTexture(textureLoader.getTexture("background_map"));
    sprite_background_map.setScale(
        static_cast<float>(window.getSize().x) / sprite_background_map.getLocalBounds().width,
        static_cast<float>(window.getSize().y) / sprite_background_map.getLocalBounds().height
    );






    /// AUDIO FILES

    // MUSIC MENU
    sf::Music main_theme;
    if (!main_theme.openFromFile("audio/super_meat_boy.ogg"))
    {
        cout << "no audio named super_meat_boy.ogg" << endl;
    }

    main_theme.setLoop(true);
    main_theme.setVolume(25);

    // MUSIC GAME

    sf::Music map_theme;
    if (!map_theme.openFromFile("audio/pvz_watery_graves.ogg"))
    {
        cout << "no audio named pvz_watery_graves.ogg" << endl;
    }

    map_theme.setLoop(true);
    map_theme.setVolume(50);




    /// PLAYERS

    // Initialisation des comptes des players.
    player player_1(1);
    int account_player_1 = player_1.get_account();
    player player_IA(-1);

    cout << "num_player = " << player_IA.get_player() << endl;

    Clock clock_init;
    window.setFramerateLimit(60);

                    /// Initialisation MAP

        /// MAP BACKGROUND (STATIC)

    Vector2f size_base = Vector2f(300.f,450.f);
    Vector2f size_ligne_fight = Vector2f(1000.f,5.f);
    Vector2f size_vessel = Vector2f(65.f,65.f);



    /// LIGNES DE BATAILLE
	std::vector<RectangleShape> ligne_fight;

	for(int i=0;i<5;i++){
        RectangleShape block_ligne(size_ligne_fight);
        block_ligne.setPosition(Vector2f(0.f,120.f+i*80.f));
        block_ligne.setFillColor(sf::Color::Red);
		ligne_fight.push_back(block_ligne);
	}

    /// CAMPS PLAYERS // RECTANGLE BLANCS POUR DELIMITATIONS.
    RectangleShape bloc_base_player(size_base);
    RectangleShape bloc_base_AI(size_base);

    bloc_base_player.setPosition(Vector2f(0.f,50.f));
    bloc_base_AI.setPosition(Vector2f(700.f,50.f));

    bloc_base_player.setFillColor(sf::Color::White);

    /// Création des premier batiments de départ

    // Tableau des batiments
    std::vector<vessel*> bat;
    vector<Unites> vect_unite;
    vector<FloatRect> VesselBounds;

    vessel* vessel_player_1 = new vessel_unite(player_1.get_player());
    //vessel_player_1->set_color(sf::Color::Blue);
    vessel_player_1->set_position(Vector2f(230.f,190.f));
    //vessel_player_1->set_texture(textureLoader.getTexture("bat_unit1")); // LOOK AT THAT
    VesselBounds.push_back(vessel_player_1->afficher().getGlobalBounds());
    bat.push_back(vessel_player_1);

    vessel* vessel_player_IA = new vessel_unite(player_IA.get_player());
    //vessel_player_IA->set_color(sf::Color::Red);
    //vessel_player_IA->set_texture(textureLoader.getTexture("bat_unit1")); // LOOK AT THAT
    vessel_player_IA->set_position(Vector2f(770.f,190.f));
    VesselBounds.push_back(vessel_player_1->afficher().getGlobalBounds());
    bat.push_back(vessel_player_IA);


            /// CARTES à JOUER

    // Tableau des cartes en haut à gauche.
    std::vector<RectangleShape> initsquares;

    // Initilisation des cartes

    RectangleShape redSquare(Vector2f(30.f,30.f));
    //redSquare.setFillColor(Color::Red);
    redSquare.setPosition(20, 10);
    //redSquare.setTexture(&bat_archer1_texture);
    redSquare.setTexture(&textureLoader.getTexture("bat_tower1"));
    initsquares.push_back(redSquare);


    sf::RectangleShape greenSquare(Vector2f(30.f,30.f));
    //greenSquare.setFillColor(sf::Color::Green);
    greenSquare.setPosition(80, 10);
    greenSquare.setTexture(&textureLoader.getTexture("bat_prod1"));
    //greenSquare.setTexture(&bat_prod1_texture);
    initsquares.push_back(greenSquare);


    sf::RectangleShape blueSquare(Vector2f(30.f,30.f));
    //blueSquare.setFillColor(sf::Color::Blue);
    blueSquare.setPosition(140, 10);
    blueSquare.setTexture(&textureLoader.getTexture("bat_unit1"));
    //blueSquare.setTexture(&bat_unit1_texture);
    initsquares.push_back(blueSquare);


    RectangleShape followingSquare(size_vessel);
    followingSquare.setFillColor(sf::Color::Red);


            /// INITIALISATION BANQUE

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
    bool vessel_upgrade = false;
    bool vessel_upgrade_check = false;
    int indice_bat = bat.size();
    int indice_unit = 0;
    vessel* bat_a_poser;

    // Variable de test de fin de jeu
    int bat_player_1 = 1;
    int bat_IA = 1;

    int statut = 0; // 0 pour menu & 1 pour jeu

///------------------------- DEBUT DE PROGRAMME ---------------------------------------------
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
                map_theme.pause();
                // annuler pause
                main_theme.pause(); // securite premier lancement (important)
                main_theme.play();

                if (touche.down == true) main_theme.setVolume(main_theme.getVolume() - 10);
                if (touche.up == true) main_theme.setVolume(main_theme.getVolume() + 10);


                /// BASCULEMENT JEU

                FloatRect start_button_Bounds = sprite_start_button.getGlobalBounds();

                if (mousePosition.x >= start_button_Bounds.left &&
    mousePosition.x <= start_button_Bounds.left + start_button_Bounds.width &&
    mousePosition.y >= start_button_Bounds.top &&
    mousePosition.y <= start_button_Bounds.top + start_button_Bounds.height &&
    touche.left)
                {
                statut = 1; // JEU
                }

            } // FIN STATUT = 0

///----------------------------------------------------------------------------------- FIN MENU POLL EVENT

///----------------------------------------------------------------------------------- JEU POLL EVENT
        if (statut == 1) {
            /// Gestion Audio
            main_theme.pause();

            map_theme.pause();
            map_theme.play();

            /// Gestion Saisie des batiments
            if (touche.left == true)
            {

                    /// UPRADE VESSEL


                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::FloatRect redSquareBounds = redSquare.getGlobalBounds();
                sf::FloatRect blueSquareBounds = blueSquare.getGlobalBounds();
                sf::FloatRect greenSquareBounds = greenSquare.getGlobalBounds();

                if (!vessel_select) // si j'attrape un carré et donc que j'en ai déjà pas un dans les mains...
                {
				//Creation des batiments après séléctions dans le coin supérieur gauche de l'écran

                    if (vessel_upgrade)
                    {
                        vessel_upgrade_check = true;
                    }
                    vessel_upgrade = false;


                    if (redSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) // si c'est le rouge
                    {

                        vessel_select=true; // et que j'en a pas déjà selectionné un...

                        vessel* new_bat = new vessel;
                        new_bat->set_size(size_vessel);
                        new_bat->set_color(sf::Color::Red);
                        new_bat->set_position(Vector2f(20.f, 20.f));
                        bat_a_poser = new_bat;
                        /// A FAIRE
                        /*
                        vessel* new_bat = new vessel_tower;
                        bat_a_poser = new_bat;
                        */
                    }

                    else if (blueSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) // Le bleu
                    {
                        vessel_select=true;

                        vessel* new_bat = new vessel_unite(player_1.get_player());
                        bat_a_poser = new_bat;
                    }

                    else if (greenSquareBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) // Le vert
                    {
                        vessel_select=true;

                        vessel* new_bat = new vessel_ressource;
                        bat_a_poser = new_bat;
                    }
                }

                else if (vessel_select)
                {
				//Empêche de placer des batiments les uns au dessus des autres


                    FloatRect rect_vessel = bat_a_poser->afficher().getGlobalBounds();

                    bool intersectsWithShapeBounds = false;
                    for (const sf::FloatRect& shapeBound : VesselBounds) {
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
                            VesselBounds.push_back(bat_a_poser->afficher().getGlobalBounds());
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



		if (touche.right == true)
		{
		    vessel_select = false;
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
        window.draw(sprite_background_map);
        //window.draw(bloc_base_player);
        //window.draw(bloc_base_AI);



        if (vessel_select) // Dessine le lignes rouge sur lesquelles on va forcer la pose d'un batiment.
        {
            for(int i=0;i<ligne_fight.size();i++)
            {
                window.draw(ligne_fight[i]);
            }
        }

        /// BACKGROUND VESSEL

        int nb_vessel_p1=0;
        int nb_vessel_IA=0;

        for (int i=0;i<bat.size();i++)
        {

                /// VESSEL_COMPTEUR

            vessel* bats = bat[i];

            if(bats->get_player()>=0)
            {
                nb_vessel_p1+=1;
            }

            if(bats->get_player()<0)
            {
                nb_vessel_IA+=1;
            }


                /// UPGRADE_VESSEL

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            FloatRect vesselbounds = bats->afficher().getGlobalBounds();

            if(vesselbounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
            {
                cout << "amelioration en cour " << endl;
                vessel_upgrade = true;
                if (vessel_upgrade_check)
                {
                    bats->upgrade();
                    vessel_upgrade_check = false;

                    cout << "Batiment ameliorer : " << bats->get_lvl() << endl;

                }
            }


                /// VESSEL_RESSOURCE

            if (bats->get_type()==0)
            {
                #ifdef __DEBUG
                cout << "bat ressource regardé" << endl;
                #endif // __DEBUG

                //Regarde si le batiment ressource doit donner la thune (si sa clock a atteint le temps de spawn de l'argent)
                if(bats->get_clock() >= bats->get_gain_time())
                {
                    //std::cout << "Le compte du joueur 1 est a : " << player_1.get_account() << std::endl;
                    account_player_1 += bats->get_gain();
                    bats->reset_clock();
                }

                player_1.set_account(account_player_1);
                text_banque.setString(std::to_string(account_player_1));
            }

                /// VESSEL_UNITE

            if (bats->get_type()==1)
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

                // test de mettre une seule unité en combat //

                /*
                if (indice_unit>7)
                {
                    bats->set_spawn(false);
                }
                */



                // Create Unite
                if (bats->get_spawn_possible())
                {
                    if (bats->get_clockspawn() >= 2)
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

                        Unites newunite(newposition_unite,bats->get_color(),bats->get_player(),bats->get_lvl());

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

        bat_player_1 = nb_vessel_p1;
        bat_IA = nb_vessel_IA;

        /// BACKGROUND END

        if (bat_player_1<=0)
        {
            cout << "The END !! You loose" << endl;
            return 0;
        }

        if (bat_IA<=0)
        {
            cout << "The END !! You win !!" << endl;
            return 0;
        }


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
        window.draw(sprite_background_menu);
        window.draw(sprite_start_button);
        }
///---------------------------------------------------------------------------------------------- FIN MENU HORS POLL EVENT


        window.display();


    } /// END WINDOWS IS OPEN

    return 0;
} /// END MAIN
