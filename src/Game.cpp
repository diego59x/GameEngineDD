#include "Game.h"
#include <iostream>
#include <C:\Users\diego\OneDrive\Escritorio\Trabajos\U\DecimoSemestre\MMake\src\include\SDL2\SDL.h>

Game::Game(const char* name, int width, int height)
    : screen_width(width), screen_height(height) 
    {

    SDL_Init(SDL_INIT_EVERYTHING);
    lastFPSUpdate = 0;
    frameStartTimestamp = 0;
    frameEndTimestamp = 0;
    FPS = 0;
    frameCount = 0;

    int maxFPS = 60;
    frameDuration = (1.0f/maxFPS) * 1000.0f;

    window = SDL_CreateWindow(name, 0, 0, width, height, 0);
    renderer = SDL_CreateRenderer(window, 0, 0);
}

Game::~Game() {
    SDL_DestroyWindow(window);
}

void Game::setup() {}

void Game::update() {}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}
void Game::frameStart() {
    frameStartTimestamp = SDL_GetTicks();

    if (frameEndTimestamp) {
        dT = (frameStartTimestamp - frameEndTimestamp) / 1000.0f;
    } else {
        dT = 0;
    }
}

void Game::frameEnd() {
    frameEndTimestamp = SDL_GetTicks();

    // Delay
    float actualFrameDuration = frameEndTimestamp - frameStartTimestamp;
    if (actualFrameDuration < frameDuration) {
        SDL_Delay(frameDuration - actualFrameDuration);
    }
    frameCount++;
    framesCountPerSecond++;
    uint32_t currentTime = SDL_GetTicks();
    uint32_t timeElapsed = currentTime - lastFPSUpdate;
    if (timeElapsed > 1000) {
        FPS = framesCountPerSecond / (timeElapsed / 1000);
        lastFPSUpdate = currentTime;
        framesCountPerSecond = 0;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool Game::running() {
    return isRunning;
}