#pragma once
#include "C:\Development\entt-master\src\entt\entt.hpp"
#include <string>

class Scene {
    public: 
        Scene(const std::string& name);
        ~Scene(); 
        entt::registry r;
    private: 
        std::string name;
};