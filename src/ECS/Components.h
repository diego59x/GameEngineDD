#pragma once
#include <glm/glm.hpp>
#include <string>
#include "../Game/Graphics/PixelShader.h"
#include "../Game/Graphics/Tile.h"

struct NameComponent {
    std::string name;
};

struct MovementStateComponent {
    std::string state;
    std::string direction;
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
  std::vector<std::string> filenames;
  int xIndex = 0;
  int yIndex = 0;
  int size = 32;
  int animationFrames = 0;
  int animationDuration = 0;
  PixelShader shader = { nullptr, "" };

  Uint32 lastUpdate = 0;
};

struct TilemapComponent {
  int width;
  int height;
  int tileSize;
  std::vector<Tile> map;
};

struct WorldComponent {
  int width;
  int height;
};

struct BackgroundComponent {
  int width;
  int height;
  std::string name;
  Texture* backgroundTexture = nullptr;
};

struct ColliderComponent {
  int xo;
  int yo;
  int w;
  int h;
  SDL_Color color = {255, 255, 255};
};