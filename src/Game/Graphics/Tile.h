#pragma once
#include "./Texture.h"

struct Terrain {
  Texture* texture = nullptr;
  int id = 0;
};

struct Tile {
  Terrain terrain;
  bool needsAutoTiling;
  bool isWalkable = true;
};