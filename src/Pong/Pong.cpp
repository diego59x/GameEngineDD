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

  Entity will = scene->createEntity("will", (screen_width/2), (screen_height/2));
  will.addComponent<SimpleSpriteComponent>("sprites/megaman/WillLittleCeasar.png");

  Entity willWhite = scene->createEntity("will2", 100, 100);
  willWhite.addComponent<SimpleSpriteComponent>("sprites/megaman/WillLittleCeasar.png"
  , [](Uint32 color) -> Uint32 { return 0xFF0000; }
  );


  scene->addSetupSystem(new SimpleSpriteSetupSystem(renderer, window));
  scene->addRenderSystem(new SimpleSpriteRenderSystem());


  return scene;
}
