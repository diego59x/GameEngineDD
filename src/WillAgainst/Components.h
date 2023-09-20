#pragma once
#include "../ECS/Components.h"

enum PlayerType { PLAYER_1, PLAYER_2, BALL};

struct SizeComponent {
  int w;
  int h;
};

struct PlayerComponent {
  int moveSpeed;
};