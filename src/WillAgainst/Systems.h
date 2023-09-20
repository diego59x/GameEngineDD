#pragma once
#include "./Components.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../ECS/SystemTypes/SystemTypes.h"
#include "../Game/Graphics/TextureManager.h"
#include "../Game/Graphics/Tile.h"
#include "../ECS/Entity.h"

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

class PlayerSetupSystem : public SetupSystem {
  public:
    void run() {
      const auto worldComponent = scene->world->get<WorldComponent>();
      int spriteSize = 32;
      int x = worldComponent.width / 2;
      int y = worldComponent.height / 2;
 
      scene->player = new Entity(scene->r.create(), scene);
      scene->player->addComponent<TransformComponent>(glm::vec2(x, y));
      auto& s = scene->player->addComponent<SpriteComponent>(
        "sprites/characterWill/WillLittleCeasarIdle.png",
        0, 0,
        spriteSize,
        4,
        1000
      );
      s.lastUpdate = SDL_GetTicks();
    }
};

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
      int tilemapWidth = 25;
      int tilemapHeight = 25;
      int tilemapTileSize = 32;

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

      // Read file
      std::ifstream mapFile;
      std::string line;
      std::vector<int> mapData;
      mapFile.open("assets/sprites/background/mapMoon.txt");
      if (mapFile.is_open()) {
          while ( getline (mapFile,line) )
          {
            std::istringstream iss(line); 
            int numberTile;
            while (iss >> numberTile) {
                mapData.push_back(numberTile);
            }
          }
          mapFile.close();
      } else std::cout << "Problem with opening file";

      for (int y = 0; y < tilemap.height; y++) {
        for (int x = 0; x < tilemap.width; x++) {
          
          int index = y * tilemap.width + x;
          Tile& tile = tilemap.map[index];
          tile.terrain = moonSurface;
          tile.terrain.id = mapData[index];
          if (index == 25) tile.isWalkable = false;
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
      int renderSize = tilemap.tileSize;

      for (int y = 0; y < tilemap.height; y++) {
        for (int x = 0; x < tilemap.width; x++) { 
          Tile tile = tilemap.map[y * tilemap.width + x];

          const int xIndex = tile.terrain.id % 5;
          const int yIndex = tile.terrain.id / 5;

          SDL_Rect terrainClip = {
            xIndex * renderSize,
            yIndex * renderSize,
            renderSize,
            renderSize
          };

          tile.terrain.texture->render(
            x * renderSize,
            y * renderSize,
            renderSize,
            renderSize,
            &terrainClip
          );
        }
      }
    }
};



