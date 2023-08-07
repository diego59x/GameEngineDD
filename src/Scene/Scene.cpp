#include "Scene.h"
#include <iostream>

Scene::Scene(const std::string& name) 
    : name(name) {
        std::cout << "Scene created";
}

Scene::~Scene() {
        std::cout << "Scene Destroyed";
}