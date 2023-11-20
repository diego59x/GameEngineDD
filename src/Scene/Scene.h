#pragma once
#include <entt/entt.hpp>
#include <SDL2/SDL.h>
#include <string>

#include "../ECS/SystemTypes/SetupSystem.h"
#include "../ECS/SystemTypes/EventSystem.h"
#include "../ECS/SystemTypes/UpdateSystem.h"
#include "../ECS/SystemTypes/RenderSystem.h"

class Entity; // forward declaration

class Scene {
    public: 
        Scene(const std::string& name);
        ~Scene(); 

        Entity createEntity(const std::string& name = "NO NAME", int x = 0, int y = 0);

        void addSetupSystem(SetupSystem* system);
        void addEventSystem(EventSystem* system);
        void addUpdateSystem(UpdateSystem* system);
        void addRenderSystem(RenderSystem* system);

        void setup();
        void processEvents(SDL_Event event);
        void update(float dT);
        void render(SDL_Renderer* renderer);
        
        entt::registry r;

        Entity* lions;
        Entity* world;
        Entity* player;
    private: 
        std::string name;
        std::vector<SetupSystem*> setupSystems;
        std::vector<EventSystem*> eventSystems;
        std::vector<UpdateSystem*> updateSystems;
        std::vector<RenderSystem*> renderSystems;
};