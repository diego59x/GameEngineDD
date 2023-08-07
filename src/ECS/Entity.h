#pragma once
#include "../Scene/Scene.h"
#include <iostream>

class Entity {
    public:
        Entity(entt::entity e, Scene* s) {
            std::cout << "Entity created" << std::endl;
            handle = e;
            scene = s;
        }
        ~Entity() {}

        template<typename T, typename ...Args>
        T& addComponent(Args&&... args) {
            return scene->r.emplace<T>(handle, std::forward<Args>(args)...);
        }

        template<typename T>
        void removeComponent() {
            scene->r.remove<T>(handle);
        }
    private:
        entt::entity handle;
        Scene* scene;
};