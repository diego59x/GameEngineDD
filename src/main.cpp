#include <iostream>
#include "Pong/Pong.h"

int main(int argc, char* argv[]) {
    Pong pong = Pong("pong", 800, 600);
    pong.run();
};