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

struct SpriteComponent {
  std::string filename;
  int xIndex = 0;
  int yIndex = 0;
  int size = 32;
  int animationFrames = 0;
  int animationDuration = 0;
  PixelShader shader = { nullptr, "" };

  Uint32 lastUpdate = 0;
};