#pragma once
#include <C:\Users\diego\OneDrive\Escritorio\Trabajos\U\DecimoSemestre\MMake\src\include\SDL2\SDL.h>

class objRect {
    public: 
        objRect(const char* name, int pos_x, int pos_y, int width, int height);
        objRect();
        ~objRect();

        int speed_x, speed_y, pos_x, pos_y, width, height;
        SDL_Rect rect;
        void moveX(int pos_x);
        void moveY(int pos_y);
    private:
};
