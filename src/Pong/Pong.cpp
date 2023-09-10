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

  Entity will = scene->createEntity("will", 100, 100);
  will.addComponent<SpriteComponent>(
    "sprites/characterWill/WillLittleCeasarIdle.png",
    0, 0,
    32,
    4,
    1000
  );

  scene->addSetupSystem(new SpriteSetupSystem(renderer));
  scene->addRenderSystem(new SpriteRenderSystem());
  scene->addUpdateSystem(new SpriteUpdateSystem());

  return scene;
}
