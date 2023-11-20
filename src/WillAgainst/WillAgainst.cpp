#include <iostream>
#include <SDL2/SDL.h>

#include "./WillAgainst.h"
#include "./Systems.h"
#include "./Components.h"
#include "../ECS/Entity.h"

Pong::Pong(const char* name, int width, int height)
  : Game(name, width, height)
{
  Scene* gameplayScene = createGameplayScene();
  setScene(gameplayScene);
}

Pong::~Pong() {}

Scene* Pong::createGameplayScene() {
  Scene* scene = new Scene("GAMEPLAY SCENE");

  scene->addSetupSystem(new WorldSetupSystem());
  scene->addSetupSystem(new PlayerSetupSystem());

  scene->addSetupSystem(new LionsSetupSystem());

  scene->addSetupSystem(new BackgroundSetupSystem(renderer));
  scene->addRenderSystem(new BackgroundRenderSystem());

  scene->addSetupSystem(new TilemapSetupSystem(renderer));
  scene->addRenderSystem(new TilemapRenderSystem());

  scene->addSetupSystem(new SpriteSetupSystem(renderer));
  scene->addRenderSystem(new SpriteRenderSystem());
  scene->addUpdateSystem(new SpriteUpdateSystem());
  
  scene->addEventSystem(new PlayerInputSystem());
  scene->addUpdateSystem(new MovementUpdateSystem());

  return scene;
}
