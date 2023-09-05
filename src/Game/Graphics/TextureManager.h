#pragma once
#include <map>
#include <string>
#include "Texture.h"

class TextureManager {
    public:
        static Texture* LoadTexture(const std::string& filename, SDL_Renderer* renderer, SDL_Window* window);
        static void UnLoadTexture(const std::string& filename);
        static Texture* GetTexture(const std::string& filename);

    private:
       static std::map<std::string, Texture*> textures;
};