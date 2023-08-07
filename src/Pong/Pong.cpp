#include "../Pong/Pong.h"
#include "../CustomObj/objRect.h"
#include "../Scene/Scene.h"
#include "../ECS/Entity.h"
#include "../ECS/Components.h"

#include <iostream>
#include <C:\Users\diego\OneDrive\Escritorio\Trabajos\U\DecimoSemestre\MMake\src\include\SDL2\SDL.h>

int step;
Pong::Pong(const char* name, int width, int height, int ball_speed) :
 Game(name, width, height) {
    ball_speed_x = ball_speed;
    ball_speed_y = ball_speed;
    player_one_score = 0;
    player_two_score = 0;
    step = 20;
    division = objRect("division", (screen_width/2), 0, 10, screen_height);

    Scene* scene = new Scene("Scene1");
}
Pong::~Pong() {
    std::cout << "Player Left Score: " << player_two_score << " Player Right Score: " << player_one_score;
}

void Pong::setup() {
    ball = objRect("ball", (screen_width/2), (screen_height/2), 20, 20);
    paddle_playerOne = objRect("playerOne", screen_width - 20, (screen_height/2), 20, 100);
    paddle_playerTwo = objRect("playerTwo", 0, (screen_height/2), 20, 100);
}

void Pong::update() {

    if (ball.pos_x <= 0) {player_one_score++; setup();}
    if (ball.pos_x >= screen_width - ball.width) {player_two_score++; setup();}

    if (ball.pos_y <= 0) {ball_speed_y *= -1.3;};
    if (ball.pos_y >= screen_height - ball.height) {ball_speed_y *= -1.3;};

    ball.moveX(ball_speed_x);
    ball.moveY(ball_speed_y);

    // Collisions
    collision_paddle_playerOne = SDL_HasIntersection(&ball.rect, &paddle_playerOne.rect);
    collision_paddle_playerTwo = SDL_HasIntersection(&ball.rect, &paddle_playerTwo.rect);
    if (collision_paddle_playerOne || collision_paddle_playerTwo) ball_speed_x *= -1.1;
}

void Pong::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                if (paddle_playerOne.pos_y - step >= 0)
                    paddle_playerOne.moveY(-step);
                break;
            case SDLK_DOWN:
                if (paddle_playerOne.pos_y + paddle_playerOne.height + step <= screen_height)
                    paddle_playerOne.moveY(step);
                break;
            case SDLK_w:
                if (paddle_playerTwo.pos_y - step >= 0)
                    paddle_playerTwo.moveY(-step);
                break;
            case SDLK_s:
                if (paddle_playerTwo.pos_y + paddle_playerTwo.height + step <= screen_height)
                    paddle_playerTwo.moveY(step);
                break;
            default:
                break;
            }
        }
    }
}

void Pong::render(){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderClear(renderer);

    // draw game
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);

    SDL_RenderFillRect(renderer, &ball.rect);
    SDL_RenderFillRect(renderer, &paddle_playerOne.rect);
    SDL_RenderFillRect(renderer, &paddle_playerTwo.rect);

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0.5);
    SDL_RenderFillRect(renderer, &division.rect);

    SDL_RenderPresent(renderer);
}
