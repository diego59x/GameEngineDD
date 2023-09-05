#pragma once
#include <map>
#include <string>
#include "./Texture.h"
#include "./PixelShader.h"

class TextureManager {
    public:
        static Texture* LoadTexture(
            const std::string& filename,
            SDL_Renderer* renderer,
            SDL_Window* window,
            PixelShader shader = { nullptr, ""}
            );
        static void UnLoadTexture(const std::string& filename, const std::string& shadername);
        static Texture* GetTexture(const std::string& filename, const std::string& shadername);

    private:
       static std::map<std::string, Texture*> textures;
};