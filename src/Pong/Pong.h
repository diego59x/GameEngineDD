#pragma once
#include "../Game/Game.h"

class Pong : public Game {
    public: 
        Pong(const char* name, int width, int height);
        ~Pong();
        Scene* createGameplayScene();
    private:
};