#pragma once
#include <glm/glm.hpp>
#include <string>
#include "../Game/Graphics/PixelShader.h"

struct NameComponent {
    std::string name;
};

struct TransformComponent {
    glm::vec2 position;
};

struct SpeedComponent {
    int x;
    int y;
};

struct ColorComponent {
    int r;
    int g;
    int b;
    int c;
};

struct SimpleSpriteComponent {
    std::string filename;
    PixelShader shader = { nullptr, ""};
};