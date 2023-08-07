#include <iostream>
#include "Pong/Pong.h"
#include "Game/Game.h"

int main(int argc, char* argv[]) {
    Pong pong = Pong("pong", 800, 600, 2);
    
    pong.setup();
    while(pong.running()) {
        pong.frameStart();
        pong.handleEvents();
        pong.update();
        pong.render();
        pong.frameEnd();
    }
    return 0;
};