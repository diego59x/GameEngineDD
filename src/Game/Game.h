#pragma once
#include <string>
#include <SDL2/SDL.h>
#include "../Scene/Scene.h"
class Game {
    public:
        Game(const char* name, int width, int height);
        ~Game();

        void frameStart();
        void frameEnd();
        void handleEvents();
        void update();
        void render();
        bool running();

        void run();

        void setScene(Scene* newScene);
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

        Scene* currentScene;
};
