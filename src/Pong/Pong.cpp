#include <iostream>
#include <SDL2/SDL.h>

#include "./Pong.h"
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

  Entity willOriginal = scene->createEntity("will", 200, 100);
  willOriginal.addComponent<SpriteComponent>(
    "sprites/characterWill/WillLittleCeasarIdle.png",
    0, 0,
    32,
    4,
    1000
  );

  Entity will = scene->createEntity("will2", 100, 100);
  will.addComponent<SpriteComponent>(
    "sprites/characterWill/WillLittleCeasarIdle.png",
    0, 0,
    32,
    4,
    1000
    , PixelShader {
       [](Uint32 color) -> Uint32 { if (color == 255) {
          return 0xFFFFFF;
        } else {
            return color;
        } 
        },
       "red"
    }
  );

  scene->addSetupSystem(new SpriteSetupSystem(renderer));
  scene->addRenderSystem(new SpriteRenderSystem());
  scene->addUpdateSystem(new SpriteUpdateSystem());

  return scene;
}
