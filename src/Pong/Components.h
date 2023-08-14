#include "../ECS/Components.h"

enum PlayerType { PLAYER_1, PLAYER_2, BALL};

struct TypeComponent {
  PlayerType objType;
};

struct SizeComponent {
  int w;
  int h;
};

struct PlayerComponent {
  int moveSpeed;
};

struct ColliderComponent {
  bool triggered;
  int transferSpeed;
};