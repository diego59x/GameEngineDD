#include "TextureManager.h"

std::map<std::string, Texture*> TextureManager::textures;

Texture* TextureManager::LoadTexture(const std::string& filename, SDL_Renderer* renderer, SDL_Window* window)
{
    if (textures.count(filename) > 0) {
        return textures[filename];
    }

    Texture* texture = new Texture(renderer, window);
    texture->load("assets/" + filename);

    textures[filename] = texture;
    return texture;
};

void TextureManager::UnLoadTexture(const std::string& filename)
{
    if (textures.count(filename) > 0) {
        delete textures[filename];
        textures.erase(filename);
    }
};
Texture* TextureManager::GetTexture(const std::string& filename)
{
    if (textures.count(filename) > 0) {
        return textures[filename];
    }
    return nullptr;
};
