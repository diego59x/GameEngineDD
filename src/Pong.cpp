#include "Pong.h"
#include <C:\Users\diego\OneDrive\Escritorio\Trabajos\U\DecimoSemestre\MMake\src\include\SDL2\SDL.h>

SDL_Rect ball;
SDL_Rect paddle;

Pong::Pong(const char* name, int width, int height) :
 Game(name, width, height) {

}
Pong::~Pong() {
    ball.x = 20;
    ball.y = 20;
    ball.w = 20;
    ball.h = 20;

    paddle.x = (screen_width / 2) - 50;
    paddle.y = screen_height - 20;
    paddle.w = 100;
    paddle.h = 20;

    ball_speed_x = 2;
    ball_speed_y = 2;
}

void Pong::setup(){

}
bool Pong::running(){
    return true;
}

void Pong::update(){

    ball.x += ball_speed_x;
    ball.y += ball_speed_y;
}
void Pong::render(){

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
