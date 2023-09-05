#pragma once
#include <string>
#include <functional>
struct PixelShader
{
    std::function<Uint32(Uint32)> func;
    std::string name;
};
