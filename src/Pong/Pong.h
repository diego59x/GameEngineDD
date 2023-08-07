#pragma once
#include "../Game/Game.h"
#include "../CustomObj/objRect.h"

class Pong : public Game {
    public: 
        Pong(const char* name, int width, int height, int ball_speed);
        ~Pong();

        void setup() override;
        void update() override;
        void handleEvents() override;
        void render() override;
    private:
        objRect ball;
        objRect division;
        objRect paddle_playerOne;
        objRect paddle_playerTwo;
        SDL_bool collision_paddle_playerOne;
        SDL_bool collision_paddle_playerTwo;
        int ball_speed_x;
        int ball_speed_y;
        int player_one_score;
        int player_two_score;
};