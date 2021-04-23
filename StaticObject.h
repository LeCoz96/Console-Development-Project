#pragma once
#include "GameObject.h"
class StaticObject :
    public GameObject
{
public:
    StaticObject(int x, int y, SDL_Renderer* renderer, LevelRenderer* level);
    ~StaticObject() = default;
};

