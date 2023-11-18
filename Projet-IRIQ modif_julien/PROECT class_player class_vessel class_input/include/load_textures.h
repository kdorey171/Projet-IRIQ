#ifndef LOAD_TEXTURES_H
#define LOAD_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

class TextureLoader {
public:
    TextureLoader(); // Constructeur

    sf::Texture& getTexture(const std::string& textureKey);

private:
    std::unordered_map<std::string, sf::Texture> textures;
};

extern TextureLoader textureLoader;
#endif
