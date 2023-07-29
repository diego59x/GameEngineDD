#pragma once
#include "Game.h"

class Pong : public Game {
    public: 
        Pong(const char* name, int width, int height);
        ~Pong();

        void setup();
        void update();
        bool running();
        void render();
    private:         
        SDL_Rect ball;
        SDL_Rect paddle;
        int ball_speed_x;
        int ball_speed_y;
};