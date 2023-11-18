#include "load_textures.h"
#include <iostream>

TextureLoader::TextureLoader() {
    // Chargement des textures ici
    if (!textures["start_button"].loadFromFile("textures/start.png")) {
        std::cout << "no texture named start.png" << std::endl;
    }

    if (!textures["background_menu"].loadFromFile("textures/background_menu.png")) {
        std::cout << "no texture named background_menu.png" << std::endl;
    }

    if (!textures["background_map"].loadFromFile("textures/background_map.png")) {
        std::cout << "no texture named background_map.png" << std::endl;
    }

    if (!textures["bat_prod1"].loadFromFile("textures/bat_prod1.png")) {
        std::cout << "no texture named bat_prod1.png" << std::endl;
    }

    if (!textures["bat_tower1"].loadFromFile("textures/bat_tower1.png")) {
        std::cout << "no texture named bat_tower1.png" << std::endl;
    }

    if (!textures["bat_unit1"].loadFromFile("textures/bat_unit1.png")) {
        std::cout << "no texture named bat_unit1.png" << std::endl;
    }

    if (!textures["bat_prod2"].loadFromFile("textures/bat_prod2.png")) {
        std::cout << "no texture named bat_prod2.png" << std::endl;
    }

    if (!textures["bat_tower2"].loadFromFile("textures/bat_tower2.png")) {
        std::cout << "no texture named bat_tower2.png" << std::endl;
    }

    if (!textures["bat_unit2"].loadFromFile("textures/bat_unit2.png")) {
        std::cout << "no texture named bat_unit2.png" << std::endl;
    }

    if (!textures["bat_prod3"].loadFromFile("textures/bat_prod3.png")) {
        std::cout << "no texture named bat_prod3.png" << std::endl;
    }

    if (!textures["bat_tower3"].loadFromFile("textures/bat_tower3.png")) {
        std::cout << "no texture named bat_tower3.png" << std::endl;
    }

    if (!textures["bat_unit3"].loadFromFile("textures/bat_unit3.png")) {
        std::cout << "no texture named bat_unit3.png" << std::endl;
    }

    // Charger d'autres textures...

}

sf::Texture& TextureLoader::getTexture(const std::string& textureKey) {
    return textures.at(textureKey);
}

TextureLoader textureLoader; // Absolument le laisser, extern (dans le .h) sert à exporter
// la variable. Mais il on l'initialise ici en fait...
