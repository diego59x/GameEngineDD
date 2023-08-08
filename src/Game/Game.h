#pragma once
#include <string>
#include <SDL2/SDL.h>

class Game {
    public:
        Game(const char* name, int width, int height);
        ~Game();

        virtual void setup() = 0;
        void frameStart();
        virtual void handleEvents() = 0;
        void frameEnd();
        virtual void update() = 0;
        virtual void render() = 0;
        bool running();

    protected:
        bool isRunning;

        SDL_Window* window;
        SDL_Renderer* renderer;

        int screen_width;
        int screen_height;

        //FPS
        int FPS;
        int frameCount;
        int framesCountPerSecond;
        uint32_t frameStartTimestamp;
        uint32_t frameEndTimestamp;
        uint32_t lastFPSUpdate;
        float frameDuration;
        float dT; 
};
