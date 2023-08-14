#include <iostream>
#include <SDL2/SDL.h>

#include "./Pong.h"
#include "./Systems.h"

#include "../ECS/Entity.h"

int player_one_score = 0;
int player_two_score = 0;
Pong::Pong(const char* name, int width, int height)
  : Game(name, width, height)
{
  Scene* gameplayScene = createGameplayScene();
  setScene(gameplayScene);
}

Pong::~Pong() {
  std::cout << "Player Left Score: " << player_two_score << " Player Right Score: " << player_one_score << std::endl;
}

Scene* Pong::createGameplayScene() {
  Scene* scene = new Scene("GAMEPLAY SCENE");
  int ballSpeed = 200;

  Entity ball = scene->createEntity("BALL", (screen_width/2), (screen_height/2));
  ball.addComponent<SizeComponent>(20, 20);
  ball.addComponent<SpeedComponent>(ballSpeed, ballSpeed);
  ball.addComponent<TypeComponent>(BALL);
  ball.addComponent<ColorComponent>(255, 255, 255, 1);
  ball.addComponent<ColliderComponent>(false, 0);

  Entity playerRight = scene->createEntity("PLAYER 1", screen_width - 20, (screen_height/2));
  playerRight.addComponent<SizeComponent>(20, 100);
  playerRight.addComponent<SpeedComponent>(0, 0);
  playerRight.addComponent<TypeComponent>(PLAYER_1);
  playerRight.addComponent<ColorComponent>(255, 255, 255, 1);
  playerRight.addComponent<PlayerComponent>(200);

  Entity playerLeft = scene->createEntity("PLAYER 2", 0, (screen_height/2));
  playerLeft.addComponent<SizeComponent>(20, 100);
  playerLeft.addComponent<SpeedComponent>(0, 0);
  playerLeft.addComponent<TypeComponent>(PLAYER_2);
  playerLeft.addComponent<ColorComponent>(255, 255, 255, 1);
  playerLeft.addComponent<PlayerComponent>(200);

  Entity division = scene->createEntity("Division", (screen_width/2), 0);
  division.addComponent<SizeComponent>(20, screen_height);
  division.addComponent<ColorComponent>(255, 0, 255, 0.5);

  scene->addSetupSystem(new HelloWorldSystem(screen_width, screen_height, ballSpeed));
  scene->addRenderSystem(new RectRenderSystem());
  scene->addUpdateSystem(new BounceUpdateSystem());
  scene->addUpdateSystem(new MovementUpdateSystem(screen_width, screen_height, &player_one_score, &player_two_score));
  scene->addEventSystem(new PlayerInputSystem());

  scene->addUpdateSystem(new CollisionDetectionUpdateSystem());

  return scene;
}
