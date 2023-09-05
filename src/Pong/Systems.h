#pragma once
#include "./Components.h"
#include <iostream>
#include "../ECS/SystemTypes/SystemTypes.h"
#include "../Game/Graphics/TextureManager.h"

class HelloWorldSystem : public SetupSystem {
  public:
    HelloWorldSystem(int screen_width, int screen_height, int ballSpeed) 
    : screen_width(screen_width), screen_height(screen_height), ballSpeed(ballSpeed) {}

    ~HelloWorldSystem() {}

    void run() {
      scene->r.view<TransformComponent, TypeComponent, SpeedComponent>()
        .each(
          [&](const auto entity, auto& t, auto& ty, auto& s) {
            switch (ty.objType)
            {
              case BALL:
                t.position.x = screen_width/2;
                t.position.y = screen_height/2;
                s.x = ballSpeed;
                s.y = ballSpeed;
              break;
              default:
              break;
            }
          }
        );
    }
    private:
      int screen_width, screen_height, ballSpeed;
};

class RectRenderSystem : public RenderSystem {
  void run(SDL_Renderer* renderer) {
    scene->r.view<TransformComponent, SizeComponent, ColorComponent>()
      .each(
        [&](const auto entity, auto& t, auto& sz, auto& cr) {
          SDL_SetRenderDrawColor(renderer, cr.r, cr.g, cr.b, cr.c);

          int x = t.position.x;
          int y = t.position.y;
          int w = sz.w;
          int h = sz.h;

          SDL_Rect rect = { x, y, w, h };
          SDL_RenderFillRect(renderer, &rect);
        }
      );
  }
};

class MovementUpdateSystem : public UpdateSystem {
  public:
    MovementUpdateSystem(int screen_width, int screen_height, int* player_one_score, int* player_two_score) 
    : screen_width(screen_width), screen_height(screen_height), player_one_score(player_one_score), player_two_score(player_two_score) {}

    void run(float dT) {

    scene->r.view<TransformComponent, SpeedComponent, SizeComponent, TypeComponent>()
      .each(
        [&](const auto entity, auto& t, auto& s, auto& sz, auto& ty) {
          if (s.x == 0 && s.y == 0) {
            return;
          }

          const int nx = t.position.x + s.x * dT;
          const int ny = t.position.y + s.y * dT;

          switch (ty.objType)
          {
          case BALL:
            if (ny <= 0 || ny + sz.h > screen_height) {
              s.y *= -1.2;
            }
            if (nx <= 0) {
              scene->setup();
              (*player_one_score)++;
              break;
            }
            if (nx + sz.w >= screen_width) {
              scene->setup();
              (*player_two_score)++;
              break;
            }
            t.position.x = nx;
            t.position.y = ny;
            break;
          case PLAYER_1:
          case PLAYER_2:
            if (ny - sz.h <= -sz.h || ny + sz.h > screen_height) {
              break;
            }
            t.position.x = nx;
            t.position.y = ny;
            break;
          default:
            break;
          }

        }
      );
    }
  private:
    int screen_width,screen_height;
    int* player_one_score;
    int* player_two_score;
};

class PlayerInputSystem : public EventSystem {
  void run(SDL_Event event) {

    scene->r.view<SpeedComponent, PlayerComponent, TypeComponent>()
      .each(
        [&](const auto entity, auto& s, auto& p, auto& t) {
          if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
              case SDLK_UP:
                if (t.objType == PLAYER_1) {
                  s.y = -p.moveSpeed;
                }
                break;
              case SDLK_DOWN:
                if (t.objType == PLAYER_1) {
                  s.y = p.moveSpeed;
                }
                break;
              case SDLK_w:
                if (t.objType == PLAYER_2) {
                  s.y = -p.moveSpeed;
                }
                break;
              case SDLK_s:
                if (t.objType == PLAYER_2) {
                  s.y = p.moveSpeed;
                }
                break;
              default: break;
            }
          }
          if (event.type == SDL_KEYUP) {
            s.y = 0;
          }
        }
      );
    }
};

class CollisionDetectionUpdateSystem : public UpdateSystem {
  void run(float dT) {
    scene->r.view<TransformComponent, SizeComponent, ColliderComponent>()
      .each(
        [&](const auto entity,
            auto& transformComponent,
            auto& sizeComponent,
            auto& colliderComponent
          ) {
            // cada entidad que tiene collider
            // AABB
            scene->r.view<TransformComponent, SpeedComponent, SizeComponent>()
            .each(
              [&](const auto entity2,
                  auto& transformComponent2,
                  auto& speedComponent2,
                  auto& sizeComponent2
                ) {
                  if (entity == entity2) {
                    // skip self collision
                    return;
                  }

                  SDL_Rect boxCol1 = {
                    static_cast<int>(transformComponent.position.x),
                    static_cast<int>(transformComponent.position.y),
                    sizeComponent.w,
                    sizeComponent.h
                  };

                  SDL_Rect boxCol2 = {
                    static_cast<int>(transformComponent2.position.x),
                    static_cast<int>(transformComponent2.position.y),
                    sizeComponent2.w,
                    sizeComponent2.h
                  };

                  if (SDL_HasIntersection(&boxCol1, &boxCol2)) {
                    colliderComponent.triggered = true;
                    colliderComponent.transferSpeed = speedComponent2.x;
                  }

              }
            );
        }
      );
    }
};

class BounceUpdateSystem : public UpdateSystem {
  void run(float dT) {
    scene->r.view<TransformComponent, SpeedComponent, ColliderComponent>()
      .each(
        [&](const auto entity,
            auto& transformComponent,
            auto& speedComponent,
            auto& colliderComponent
          ) {
            if (colliderComponent.triggered) {
              speedComponent.x *= -1.5;
              speedComponent.y += colliderComponent.transferSpeed;

              colliderComponent.triggered = false;
            }
          }
      );
    }
};

class SimpleSpriteSetupSystem : public SetupSystem {
  public:
    SimpleSpriteSetupSystem(SDL_Renderer* renderer, SDL_Window* window) 
    : renderer(renderer), window(window) { }

    ~SimpleSpriteSetupSystem() {
      auto view = scene->r.view<SimpleSpriteComponent>();
      for (auto entity : view)
      {
        const auto spriteComponent = view.get<SimpleSpriteComponent>(entity);

        TextureManager::UnLoadTexture(spriteComponent.filename , spriteComponent.shader.name);

      }
    }

    void run () {
      auto view = scene->r.view<SimpleSpriteComponent>();


      for (auto entity : view)
      {
        const auto spriteComponent = view.get<SimpleSpriteComponent>(entity);

        TextureManager::LoadTexture(spriteComponent.filename, renderer, window, spriteComponent.shader);

      }
    }

  private:
    SDL_Renderer* renderer;
    SDL_Window* window;
};

class SimpleSpriteRenderSystem : public RenderSystem {
  public:
    void run (SDL_Renderer* renderer) {
      auto view = scene->r.view<TransformComponent, SimpleSpriteComponent>();

      for (auto entity : view)
      {
        const auto spriteComponent = view.get<SimpleSpriteComponent>(entity);
        const auto transformComponent = view.get<TransformComponent>(entity);


        Texture* texture = TextureManager::GetTexture(spriteComponent.filename, spriteComponent.shader.name);
        texture->render(transformComponent.position.x, transformComponent.position.y);
      }
    }
};