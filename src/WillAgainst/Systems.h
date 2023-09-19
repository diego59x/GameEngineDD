#pragma once
#include "./Components.h"
#include <iostream>
#include "../ECS/SystemTypes/SystemTypes.h"
#include "../Game/Graphics/TextureManager.h"
#include "../Game/Graphics/Tile.h"

// class PlayerInputSystem : public EventSystem {
//   void run(SDL_Event event) {
//     auto& playerSpeed = scene->player->get<SpeedComponent>();
//     int speed = 200;

//     if (event.type == SDL_KEYDOWN) {
//       switch(event.key.keysym.sym) {
//         case SDLK_RIGHT:
//           playerSpeed.x = speed;
//           break;
//         case SDLK_LEFT:
//           playerSpeed.x = -speed;
//           break;
//         case SDLK_UP:
//           playerSpeed.y = -speed;
//           break;
//         case SDLK_DOWN:
//           playerSpeed.y = speed;
//           break;
//       }
//     }
//     if (event.type == SDL_KEYUP) {
//       switch(event.key.keysym.sym) {
//         case SDLK_RIGHT:
//           playerSpeed.x = 0;
//           break;
//         case SDLK_LEFT:
//           playerSpeed.x = 0;
//           break;
//         case SDLK_UP:
//           playerSpeed.y = 0;
//           break;
//         case SDLK_DOWN:
//           playerSpeed.y = 0;
//           break;
//       }
//     }
//   }
// };

class SpriteSetupSystem : public SetupSystem {
  public:
    SpriteSetupSystem(SDL_Renderer* renderer) 
    : renderer(renderer) { }

    ~SpriteSetupSystem() {
      auto view = scene->r.view<SpriteComponent>();
      for (auto entity : view)
      {
        const auto spriteComponent = view.get<SpriteComponent>(entity);

        TextureManager::UnLoadTexture(spriteComponent.filename, spriteComponent.shader.name);

      }
    }

    void run () {
      auto view = scene->r.view<SpriteComponent>();


      for (auto entity : view)
      {
        const auto spriteComponent = view.get<SpriteComponent>(entity);

        TextureManager::LoadTexture(spriteComponent.filename, renderer, spriteComponent.shader);

      }
    }

  private:
    SDL_Renderer* renderer;
};

class SpriteRenderSystem : public RenderSystem {
  public:
    void run (SDL_Renderer* renderer) {
      auto view = scene->r.view<TransformComponent, SpriteComponent>();

      for (auto entity : view)
      {
        const auto spriteComponent = view.get<SpriteComponent>(entity);
        const auto transformComponent = view.get<TransformComponent>(entity);


        Texture* texture = TextureManager::GetTexture(spriteComponent.filename, spriteComponent.shader.name);
        
        SDL_Rect clip = {
          spriteComponent.xIndex * spriteComponent.size,
          spriteComponent.yIndex * spriteComponent.size,
          spriteComponent.size,
          spriteComponent.size
        };
        
        texture->render(
          transformComponent.position.x,
          transformComponent.position.y,
          32,
          32,
          &clip
        );
      }
    }
};

class SpriteUpdateSystem : public UpdateSystem {
  public:
    void run(float dT) {
      auto view = scene->r.view<SpriteComponent>();

      Uint32 now = SDL_GetTicks();

      for(auto entity : view) {
        auto& spriteComponent = view.get<SpriteComponent>(entity);

        if (spriteComponent.animationFrames > 0) {
          float timeSinceLastUpdate = now - spriteComponent.lastUpdate;

          int framesToUpdate = static_cast<int>(
            timeSinceLastUpdate / 
            spriteComponent.animationDuration * spriteComponent.animationFrames
          );

          if (framesToUpdate > 0) {
            spriteComponent.xIndex += framesToUpdate;
            spriteComponent.xIndex %= spriteComponent.animationFrames;
            spriteComponent.lastUpdate = now;            
          }
        }
      }
    }
};

class WorldSetupSystem : public SetupSystem {
  public:
    void run() {
      int tilemapWidth = 50;
      int tilemapHeight = 38;
      int tilemapTileSize = 16;

      scene->world = new Entity(scene->r.create(), scene);
      scene->world->addComponent<TilemapComponent>(tilemapWidth, tilemapHeight, tilemapTileSize);
      scene->world->addComponent<WorldComponent>(tilemapWidth * tilemapTileSize, tilemapHeight*tilemapTileSize);
    }
};

class TilemapSetupSystem : public SetupSystem {
  public:
    TilemapSetupSystem(SDL_Renderer* renderer)
      : renderer(renderer) { }

    ~TilemapSetupSystem() {
    }

    void run() {
      const auto playerPosition = scene->player->get<TransformComponent>();
      Texture* surfaceTexture = TextureManager::LoadTexture("sprites/background/TileMoon.png", renderer);

      auto& tilemap = scene->world->get<TilemapComponent>();
      tilemap.map.resize(tilemap.width * tilemap.height);

      Terrain moonSurface{surfaceTexture};

      int centerX = playerPosition.position.x  / tilemap.tileSize;
      int centerY = playerPosition.position.y  / tilemap.tileSize;

      for (int y = 0; y < tilemap.height; y++) {
        for (int x = 0; x < tilemap.width; x++) {
          
          int index = y * tilemap.width + x;

          Tile& tile = tilemap.map[index];

          if ((std::abs(centerX - x) < 5 && std::abs(centerY - y) < 5)) {
            tile.up = moonSurface;
            // tile.down = water;
            tile.needsAutoTiling = true;
          } else {
            // tile.up = water;
            tile.needsAutoTiling = false;
            tile.isWalkable = false;
          }
        }
      }
   }

  private:
    SDL_Renderer* renderer;
};


class TilemapRenderSystem : public RenderSystem {
  public:
    void run(SDL_Renderer* renderer) {
      auto& tilemap = scene->world->get<TilemapComponent>();
      int size = tilemap.tileSize;

      // int startX = 
      // int endX = 
      // int startY = 
      // int endY = 

      for (int y = startY; y <= endY; y++) {
        for (int x = startX; x <= endX; x++) {
          Tile tile = tilemap.map[y * tilemap.width + x];

          int renderSize = tilemap.tileSize * z;

          if (tile.down.texture) {
            SDL_Rect downClip = {
              tile.down.x,
              tile.down.y,
              size,
              size
            };

            tile.down.texture->render(
              x * renderSize ,
              y * renderSize,
              renderSize,
              renderSize,
              &downClip
            );
          }
          SDL_Rect upClip = {
              tile.up.x,
              tile.up.y,
              size,
              size
          };
          tile.up.texture->render(
            x * renderSize,
            y * renderSize,
            renderSize,
            renderSize,
            &upClip
          );
        }
      }
    }
};



