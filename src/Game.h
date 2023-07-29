#pragma once
#include <string>
#include <C:\Users\diego\OneDrive\Escritorio\Trabajos\U\DecimoSemestre\MMake\src\include\SDL2\SDL.h>

class Game {
    public:
        Game(const char* name, int width, int height);
        ~Game();

        void setup();
        void frameStart();
        void handleEvents();
        void frameEnd();
        void update();
        void render();
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
