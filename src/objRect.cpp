#include "objRect.h"
#include <C:\Users\diego\OneDrive\Escritorio\Trabajos\U\DecimoSemestre\MMake\src\include\SDL2\SDL.h>

objRect::objRect(const char* name, int pos_x, int pos_y, int width, int height) 
    : pos_x(pos_x), pos_y(pos_y), width(width), height(height) {
    rect.x = pos_x;
    rect.y = pos_y;
    rect.w = width;
    rect.h = height;
}
objRect::objRect() {}
objRect::~objRect() {}

void objRect::moveX(int pos_x) {rect.x += pos_x; this->pos_x += pos_x;}
void objRect::moveY(int pos_y) {rect.y += pos_y; this->pos_y += pos_y;}
